#ifndef _CMsgQueue_H
#define _CMsgQueue_H
/**************************************************************************
* Copyright (c), 2016, xxx Co., Ltd.
* All rights reserved.
*
* @file   CMsgQueue.h
* @brief  message queue
*
* @author jakyhuang
* @version 1.0
* @date 2016/07/31
*
*
* TODO:
****************************************************************************/

#include <deque>
#include "Mutex.h"

template<typename T>
class CMegQueue
{
public:
    CMegQueue(const size_t maxSize = 100000);
    ~CMegQueue();
    //send message to buffer
    int sendMsg(const T& msg);
    //receive message from the buffer
    int recvMsg(T& msg);
private:
    //queue buffer
    std::deque<T> m_queue;
    //mutex
    Mutex m_mutex;
    //max buffer size
    size_t m_maxSize;
};


template<typename T>
CMegQueue<T>::CMegQueue(const size_t maxSize)
{
    //initial
    m_maxSize = maxSize;
}

template<typename T>
CMegQueue<T>::~CMegQueue()
{
    
}

template<typename T>
int CMegQueue<T>::sendMsg(const T& msg)
{
    {
        //lock c++ 11
        //std::lock_guard<std::mutex> lock(m_mutex);
        m_mutex.lock();
        if (m_queue.size() >= m_maxSize) 
        {
            m_mutex.unlock();
            return -1;
        }
        m_queue.push_back(msg);
        m_mutex.unlock();
    }
    return 0;
}

template<typename T>
int CMegQueue<T>::recvMsg(T& msg)
{
    {
        //lock c++ 11
        //std::lock_guard<std::mutex> lock(m_mutex);
        m_mutex.lock();
        if (m_queue.empty())
        {
            m_mutex.unlock();
            return -1;
        }           
        msg = m_queue.front();
        m_queue.pop_front();
        m_mutex.unlock();
    }
    return 0;
}



#endif