//  hydro.h
//  Lab8_exe_C
//  Created by Dominic Gartner on 2022-11-17.

#ifndef hydro_h
#define hydro_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

double average(FlowList &x);
void saveData(FlowList& x);
void display(FlowList &x, int num);
void addData(FlowList &x);
void removeData(FlowList &x);
int readData(FlowList &x);
int menu();
void pressEnter(int called);
void displayHeader(int called);

#endif /* hydro_h */
