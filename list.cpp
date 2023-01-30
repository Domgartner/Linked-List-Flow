//  list.cpp
//  Lab8_exe_C
//  Created by Dominic Gartner on 2022-11-17.
#include "list.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


FlowList::FlowList(): headM(0)
{
}

Node *FlowList::gethead()const{
    return headM;
}


void FlowList::remove(const int year)
{
    // if list is empty, do nothing
    if (headM == 0)
        return;
    if(headM->item.year == year){
        Node* doomed = headM;
        headM = headM->next;
        delete doomed;
    }
    
    Node *doomed_node = 0;
    
    if (year == headM->item.year) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && year != maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if(maybe_doomed != 0 && year == maybe_doomed->item.year){
            doomed_node = maybe_doomed;
            before->next = maybe_doomed->next;
        }
    }
    delete doomed_node;
}

void FlowList::insert(const ListItem& itemA){
    Node *new_node = new Node;
    new_node->item = itemA;

    if (headM == 0 || itemA.year < headM->item.year ) {
        new_node->next = headM;
        headM = new_node;
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA.year > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}
