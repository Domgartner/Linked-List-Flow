//  list.h
//  Lab8_exe_C
//  Created by Dominic Gartner on 2022-11-17.

#ifndef list_h
#define list_h

#include <stdio.h>

struct ListItem {
    int year;
    double flow;
};

struct Node {
    ListItem item;
    Node *next;
};

class FlowList{
public:
    FlowList();
    void remove(const int year);
    void insert(const ListItem& itemA);
    Node *gethead()const;
    
private:
    Node *headM;
};

#endif /* list_h */
