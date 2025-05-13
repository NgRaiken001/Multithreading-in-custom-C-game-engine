#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <functional>
#include <condition_variable>

class JobSystem {
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> jobs;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop = false;

public:
    JobSystem(size_t numThreads) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this]() {
                while (true) {
                    std::function<void()> job;
                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        condition.wait(lock, [this]() { return stop || !jobs.empty(); });
                        if (stop && jobs.empty()) return;
                        job = std::move(jobs.front());
                        jobs.pop();
                    }
                    job();
                }
            });
        }
    }

    void AddJob(std::function<void()> job) {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            jobs.push(std::move(job));
        }
        condition.notify_one();
    }

    ~JobSystem() {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for (auto& worker : workers) {
            worker.join();
        }
    }
};
