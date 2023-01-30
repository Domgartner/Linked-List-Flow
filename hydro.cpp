//  hydro.cpp
//  Lab8_exe_C
//  Created by Dominic Gartner on 2022-11-17.

#include "hydro.h"
#include "list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    FlowList x;
    int called = 0;
    displayHeader(called);
    called++;
    int NumRecords = readData(x);
    
    while(1){
        int quit = 0;
        switch(menu()){
            case 1:
                display(x, NumRecords);
                pressEnter(called);
                break;
            case 2:
                addData(x);
                pressEnter(called);
                break;
            case 3:
                saveData(x);
                pressEnter(called);
                break;
            case 4:
                removeData(x);
                pressEnter(called);
                break;
            case 5:
                cout<<"\nProgram Terminated Successfully.\n"<<endl;
                quit = 1;
                break;
            default:
                cout<<"\nEntry is not an option.";
                pressEnter(called);
        }
        if(quit == 1)
            break;
    }
    
    return 0;
}

void displayHeader(int called){
    cout<<"Program: Flow Studies, Fall 2022\nVersion 1.0\nLab Section: B01\nProduced by: Dominic Gartner\n";
    pressEnter(called);
    return;
}

void pressEnter(int called){
    cout<<"\n\n<<< Press Enter To Continue >>>\n";
    cin.get();
    if(called != 0)
        cin.get();
}

int menu(){
    cout<<"Please Select One Of The Following Operations:\n";
    cout<<"1. Display Flow List, And The Average\n";
    cout<<"2. Add Data\n";
    cout<<"3. Save Data Into The File\n";
    cout<<"4. Remove Data\n";
    cout<<"5. Quit\n";
    int n;
    cout<<"\nEnter Your Choice (1, 2, 3, 4, or 5): ";
    cin>>n;
    return n;
}

int readData(FlowList &x){
    int data_read = 0;
    ListItem a;
    ifstream inObj;
    inObj.open("/Users/dominicgartner/Downloads/flow.txt", ios::in);
    if(!inObj){
        cout<<"Error Opening File.\n";
        exit(1); }
    while(!inObj.eof()){
        inObj >> a.year >> a.flow;
        x.insert(a);
        data_read+=1;
    }
    inObj.close();
    return data_read;
}

void addData(FlowList &x){
    ListItem add_data;
    Node *add = x.gethead();
    cout<<"Please Enter A Year: ";
    cin>>add_data.year;
    while(add != 0){
        if(add->item.year == add_data.year){
            cout<<"\nError: Duplicate Data.";
            return;
        }
        add = add->next;
    }
    cout<<"Please Enter The Flow: ";
    cin>>add_data.flow;
    x.insert(add_data);
    cout<<"\nNew Record Inserted Successfully.";
    return;
}

void removeData(FlowList& x){
    int year;
    cout<<"Please Enter The Year You Want To Remove: ";
    cin>>year;
    Node* remove = x.gethead();
    while(remove != 0){
        if(remove->item.year == year){
            x.remove(year);
            cout<<"\nRecord Was Successfully Removed.";
            return;
        }
        remove = remove->next;
    }
    cout<<"\nError: No Such Data.";
    return;
    }
    
double average(FlowList &x){
    double average = 0;
    Node *curr = x.gethead();
    while(curr != 0){
        average += curr->item.flow;
        curr = curr->next;
    }
    return average;
}

void saveData(FlowList &x){
    ofstream outObj;
    outObj.open("/Users/dominicgartner/Downloads/flow.txt", ios::out);

    if(!outObj){
        cout<<"\nError Opening File.\n";
        exit(1);
    }
    Node *curr = x.gethead();
    while(curr != 0){
        outObj << curr->item.year << "\t" << curr->item.flow << endl;
        curr = curr->next;
    }
    outObj.close();
    cout<<"\nFile Successfully Saved.";
}

void display(FlowList &x, int num){
    Node *current = x.gethead();
    cout<<"Year"<<"\t"<<"Flow (In Billions Of Cubic Meters)"<<endl;
    while(current){
        cout<<current->item.year<<"\t"<<current->item.flow<<endl;
        current = current->next;
    }
    double av = (average(x) / num);
    cout<<"\nThe Annual Average Of The Flow Is: " << av <<" Billions Of Cubic Meter.";
    return;
}
