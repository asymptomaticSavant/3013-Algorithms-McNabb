#pragma once
#include <iostream>
using namespace std;

class ArrayStack {
private:
    int* A;   
    int size; 
    int top;  
    double threshHold;
 

public:
    int touchySize;
    int maxSize;     
    int resizeTimes;          
    double fullThreshold;   
    double shrinkThreshold; 
    double growRatio;    
    double shrinkRatio; 

    ArrayStack();
    ArrayStack(int s);
    bool Empty();
    bool Full();
    int Peek();
    int Pop();
    void Print();
    bool Push(int x);
    void ContainerGrow();
    void checkResize();
    void ContainerShrink();
    int main();

};