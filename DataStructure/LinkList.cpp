//
//  LinkList.cpp
//  CSFoundation
//
//  Created by Vincent WenShuo on 01/07/2015.
//  Copyright (c) 2015 vin. All rights reserved.
//

#include "LinkList.h"
#include <map>

LinkList::LinkList() {
    head = NULL;
}

LinkList::~LinkList() {
    while(head != NULL){
        LinkListNode *temp = head;
        head= head->next;
        delete temp;
    }
}

void LinkList::addNode(int value) {
    if(head == NULL) {
        head = new LinkListNode(value);
    }
    else{
        LinkListNode *newNode = new LinkListNode(value);
        newNode->next = head;
        head = newNode;
    }
}

void LinkList::addNode(LinkListNode *node) {
    if(head == NULL) {
        head = node;
    }
    else{
        node->next = head;
        head = node;
    }
}

void LinkList::removeNode(int value) {
    if(head == NULL){
        return;
    }
    LinkListNode *del = NULL;

    LinkListNode *pre = head;
    LinkListNode *cur = head->next;
    while(cur != NULL){
        if(cur->value == value){
            del = cur;
            pre->next = cur->next;
            cur = cur->next;
            delete  del;
        }
        else{
            pre = cur;
            cur = cur->next;
        }
    }
    
    if(head->value == value){
        del = head;
        head = head->next;
        delete del;
    }
}

void LinkList::printList() {
    LinkListNode *temp = head;
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

LinkList* combineLinkList(LinkList *list1, LinkList *list2) {
    if(list1 == NULL || list2 == NULL){
        return NULL;
    }
    
    LinkList *comList = new LinkList();
    map<int, bool> valueMap;
    LinkListNode *head1 = list1->head;
    
    while(head1 != NULL){
        //printf("%d ", head1->value);
        if(valueMap.find(head1->value) == valueMap.end()) {
            valueMap[head1->value] = true;
            comList->addNode(head1->value);
        }
        head1 = head1->next;
    }
    
    LinkListNode *head2 = list2->head;
    while(head2 != NULL){
        if(valueMap.find(head2->value) == valueMap.end()) {
            valueMap[head2->value] = true;
            comList->addNode(head2->value);
        }
        head2 = head2->next;
    }
    
    return comList;
}

void LinkListTest(){
    printf("LinkListTest start!\n");
    LinkList *list = new LinkList();
    list->addNode(5);
    list->addNode(4);
    list->addNode(2);
    list->addNode(2);
    list->addNode(2);
    list->printList();
    
    list->removeNode(2);
    list->printList();
    
    list->removeNode(1);
    list->printList();
    
    list->removeNode(5);
    list->printList();
    
    list->removeNode(4);
    list->printList();
    
    LinkList *list1 = new LinkList();
    list1->addNode(5);
    list1->addNode(4);
    list1->addNode(3);
    list1->addNode(2);
    list1->printList();
    
    LinkList *list2 = new LinkList();
    list2->addNode(4);
    list2->addNode(5);
    list2->addNode(6);
    list2->addNode(7);
    list2->addNode(8);
    list2->printList();
    
    LinkList *list3 = combineLinkList(list1, list2);
    list3->printList();
    
    delete list;
    printf("LinkListTest end!\n");
}





