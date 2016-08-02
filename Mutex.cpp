#include "Mutex.h"
#include <exception>

Mutex::Mutex()
{
    if ( pthread_mutex_init(&_mutex, NULL) )
    {
        throw "Error: Initializing _mutex";
    }
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&_mutex);
}

Mutex::Mutex(const Mutex & obj)
{
	_mutex = obj._mutex;
}

Mutex & Mutex::operator=(const Mutex & obj)
{
	_mutex = obj._mutex;
	return *this;
}

void Mutex::lock ()
{
    pthread_mutex_lock( &_mutex );
}

void Mutex::unlock ()
{
    pthread_mutex_unlock( &_mutex );
}
