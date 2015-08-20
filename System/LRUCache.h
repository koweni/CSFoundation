//
//  LRUCache.h
//  CSFoundation
//
//  Created by Vincent WenShuo on 19/08/2015.
//  Copyright (c) 2015 vin. All rights reserved.
//

#ifndef CSFoundation_LRUCache_h
#define CSFoundation_LRUCache_h

using namespace std;

template <typename T>
struct CacheQueueNode {
    CacheQueueNode *pre, *next;
    unsigned pageNum;
    T *data;
};

template <typename T>
struct CacheQueue {
    CacheQueueNode<T> *head, *tail;
    unsigned sizeLimit;
    unsigned count;
};

template <typename T>
struct CacheHash {
    unsigned sizeLimit;
    CacheQueueNode<T> *nodeArray;
};

template <typename T>
class LRUCacheManager {
private:
    CacheQueue<T>* queue;
    CacheHash<T>* hash;
    unsigned sizeLimit;
    unsigned count;

public:
    LRUCacheManager(unsigned sizeLimit);
    ~LRUCacheManager();
    
    CacheQueueNode<T>* newCacheNode(unsigned pageNum, T *data);
    void deleteTail();
    void insert(unsigned pageNum, T *data);
    T* fetchPage(unsigned pageNum);
    void printQueue();
};

void CacheManagerTests();

#endif
