#ifndef MUTEX_H_
#define MUTEX_H_

#include <pthread.h>

class Mutex
{
private:
    pthread_mutex_t _mutex;
    Mutex & operator=(const Mutex & obj);
    Mutex(const Mutex & obj);

public:
    Mutex();
    virtual ~Mutex();
    void lock();
    void unlock();
};


#endif