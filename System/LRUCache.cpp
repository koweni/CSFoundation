//
//  LRUCache.cpp
//  CSFoundation
//
//  Created by Vincent WenShuo on 19/08/2015.
//  Copyright (c) 2015 vin. All rights reserved.
//

#include <stdio.h>
#include "LRUCache.h"

template <typename T>
LRUCacheManager<T>::LRUCacheManager(unsigned sizeLimit){
    this->sizeLimit = sizeLimit;
    this->count = 0;
    
    queue = new CacheQueue<T>;
    queue->head = NULL;
    queue->tail = NULL;
    queue->sizeLimit = sizeLimit;
    queue->count = 0;
    
    hash = new CacheHash<T>;
    hash->sizeLimit = sizeLimit;
    hash->nodeArray = new CacheQueueNode<T>[sizeLimit];
}

template <typename T>
LRUCacheManager<T>::~LRUCacheManager() {
    if(hash && hash->nodeArray) {
        delete[] hash->nodeArray;
        
        delete hash;
        hash = NULL;
    }
    if(queue) {
        delete queue;
        queue = NULL;
    }
}

template <typename T>
CacheQueueNode<T>* LRUCacheManager<T>::newCacheNode(unsigned pageNum, T *data) {
    CacheQueueNode<T> *newNode = new  CacheQueueNode<T>;
    newNode->data = data;
    newNode->pre = NULL;
    newNode->next = NULL;
    newNode->pageNum = pageNum;
    
    return newNode;
}

template <typename T>
void LRUCacheManager<T>::deleteTail() {
    if(queue->count == 0) {
        return;
    }
    if(queue->count == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    }
    
    if(queue->tail) {
        CacheQueueNode<T> *tempNode = queue->tail;
        if(queue->tail->pre) {
            queue->tail->pre->next = NULL;
        }
        delete tempNode;
    }
    queue->count--;
}

template <typename T>
void LRUCacheManager<T>::insert(unsigned pageNum, T *data){
    CacheQueueNode<T> *newNode = this->newCacheNode(pageNum, data);
    //if the queue is full, delete the tail and add new node to head
    if( queue->count == queue->sizeLimit ) {
        //hash->nodeArray[ queue->tail->pageNum ] = NULL;
        deleteTail();
    }

    if (queue->head == NULL && queue->tail == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else{
        CacheQueueNode<T> *tempNode = queue->head;
        tempNode->pre = newNode;
        newNode->next = tempNode;
        queue->head = newNode;
        
        hash->nodeArray[pageNum] = *newNode;
    }

    queue->count++;
}

template <typename T>
void LRUCacheManager<T>::printQueue() {
    printf("Print queue:\n");
    CacheQueueNode<T> *tempNode = queue->head;
    while(tempNode != NULL){
        printf("%d\n", *tempNode->data);
        tempNode = tempNode->next;
    }
}

void CacheManagerTests() {
    printf("CacheManagerTests start!\n");
    LRUCacheManager<int> *intLRUCacheManager = new LRUCacheManager<int>(5);
    
    int* data0 = new int;
    *data0 = 0;
    intLRUCacheManager->insert(0, data0);
    
    int* data1 = new int;
    *data1 = 1;
    intLRUCacheManager->insert(1, data1);

    intLRUCacheManager->printQueue();
    
    *data0 = 3;
    
    intLRUCacheManager->printQueue();
    
    delete intLRUCacheManager;
    printf("CacheManagerTests end!\n");
}

