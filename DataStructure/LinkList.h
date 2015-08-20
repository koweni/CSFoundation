//
//  LinkList.h
//  CSFoundation
//
//  Created by Vincent WenShuo on 01/07/2015.
//  Copyright (c) 2015 vin. All rights reserved.
//

#ifndef __CSFoundation__LinkList__
#define __CSFoundation__LinkList__

#include <stdio.h>

using namespace std;

struct LinkListNode {
    int value;
    LinkListNode* next;
    
    LinkListNode(int value){
        this->value = value;
        this->next = NULL;
    }
};

class LinkList {
public:
    LinkListNode* head;
    
    LinkList();
    ~LinkList();
    
    void addNode(int value);
    void addNode(LinkListNode* node);
    void removeNode(int value);
    void printList();
};

LinkList* combineLinkList(LinkList *list1, LinkList *list2);
void LinkListTest();

#endif /* defined(__CSFoundation__LinkList__) */
