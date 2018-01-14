/**
 * Task class.
 * operates tasks
 */
#ifndef REVERSITESTS_TASK_H
#define REVERSITESTS_TASK_H


class Task {
public:
    /**
     * constructor.
     * @param func - void * obj
     * @param arg - void * arg
     */
    Task(void * (*func)(void *arg), void* arg) :
            func(func), arg(arg) {}
    /**
     * execute function.
     */
    void execute() {
        func(arg);
    }
    /**
     * destructor
     */
    virtual ~Task() {}
private:
    //members
    void * (*func)(void *arg);
    void *arg;
};


#endif //REVERSITESTS_TASK_H
