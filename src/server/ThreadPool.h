/**
 * ThreadPool class.
 * manages our pool
 */

#ifndef REVERSITESTS_THREADPOOL_H
#define REVERSITESTS_THREADPOOL_H

#define THREADS_NUM 5

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;
class ThreadPool {
public:
    /**
     * ThreadPool constructor
     * @param threadsNum - number of threads for pool
     */
    ThreadPool(int threadsNum);
    /**
     * addTask func.
     * @param task - Task obj
     */
    void addTask(Task *task);
    /**
     * terminate func.
     */
    void terminate();
    /**
     * destructor
     */
    virtual ~ThreadPool();
private:
    //members
    queue<Task *> tasksQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;
    static void *execute(void *arg);
};


#endif //REVERSITESTS_THREADPOOL_H
