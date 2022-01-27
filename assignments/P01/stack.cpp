///////////////////////////////////////////////////////////////////////////////
//
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Label:            L01
// Title:            Lecture 01 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - See class below
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack {
private:
    int* A;   // pointer to array of int's
    int size; // current max stack size
    int top;  // top of stack
    double threshHold = .85;

    int maxSize = 0;              //max size the stack ever reached
    int resizeTimes = 0;          //how many times the stack was resized(grown or reduced)
    double fullThreshold = .85;   // ratio you go over to grow the stack(e.g. .85)
    double shrinkThreshold = .15; //to shrink  ratio to go under to shrink the stack(e.g. .15) but not below size 10!
    double growRatio = 2.0;       // how much to grow the stack(e.g. 2.0 = double the size)
    double shrinkRatio = 0.5;     // how much to shrink the stack(e.g. .5 = half its size)

    // top = number of items in the stack + 1
    // size = array size

    // size = 100
    // (top + 1) / size

public:
    /**
  * ArrayStack
  *
  * Description:
  *      Constructor no params
  *
  * Params:
  *     - None
  *
  * Returns:
  *     - NULL
  */
    ArrayStack() {
        size = 10;
        A = new int[size];
        top = -1;
    }

    /**
  * ArrayStack
  *
  * Description:
  *      Constructor size param
  *
  * Params:
  *     - int size
  *
  * Returns:
  *     - NULL
  */
    ArrayStack(int s) {
        size = s;
        A = new int[s];
        top = -1;
    }

    /**
  * Public bool: Empty
  *
  * Description:
  *      Stack empty?
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [bool] true = empty
  */
    bool Empty() {
        return (top <= -1);
    }

    /**
  * Public bool: Full
  *
  * Description:
  *      Stack full?
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [bool] true = full
  */
    bool Full() {
        return (top >= size - 1);
    }

    /**
  * Public int: Peek
  *
  * Description:
  *      Returns top value without altering the stack
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [int] top value if any
  */
    int Peek() {
        if (!Empty()) {
            return A[top];
        }

        return -99; // some sentinel value
                    // not a good solution
    }

    /**
  * Public int: Pop
  *
  * Description:
  *      Returns top value and removes it from stack
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [int] top value if any
  */
    int Pop() {
        if (!Empty()) {
            return A[top--];
        }

        checkResize();

        return -99; // some sentinel value
                    // not a good solution
    }

    /**
  * Public void: Print
  *
  * Description:
  *      Prints stack to standard out
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      NULL
  */
    void Print() {
        for (int i = 0; i <= top; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    /**
  * Public bool: Push
  *
  * Description:
  *      Adds an item to top of stack
  *
  * Params:
  *      [int] : item to be added
  *
  * Returns:
  *      [bool] ; success = true
  */
    bool Push(int x) {
        if (Full()) {
            ContainerGrow();
        }
        if (!Full()) {
            A[++top] = x;

            checkResize();
            return true;
        }

        return false;
    }

    /**
  * Public void: ContainerGrow
  *
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      NULL
  */
    void ContainerGrow() {
        int newSize = size * growRatio;   
        int* B = new int[newSize]; // allocate new memory

        for (int i = 0; i < top; i++) { // copy values to new array
            B[i] = A[i];
        }

        delete[] A; // delete old array

        size = newSize; // save new size

        A = B; // reset array pointer
        resizeTimes++;

        //check to update maxSize
        maxSize = size > maxSize ? size: maxSize;
    }

    /**
 * Public void: checkResize
 *
 * Description:
 *      Checks grow/shrink ratio and resizes array appropriately
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      NULL
 */
    void checkResize() {
        if (??>= fullThreshold) {
            ContainerGrow();
        }
        else if (? ? <= shrinkThreshold) {
            ContainerShrink();
        }
    }

/**
  * Public void: ContainerShrink
  *
  * Description:
  *      Resizes the container for the stack by halving
  *      its capacity
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      NULL
  */
    void ContainerShrink() {
        if (size / shrinkRatio >= 10)
        {
            int newSize = size / shrinkRatio;
            int* B = new int[newSize]; // allocate new memory

            for (int i = 0; i < top; i++) { // copy values to new array
                B[i] = A[i];
            }

            delete[] A; // delete old array

            size = newSize; // save new size

            A = B; // reset array pointer
            resizeTimes++;
        }
    }
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
    ArrayStack stack;
    int r = 0;

    for (int i = 0; i < 20; i++) {
        r = rand() % 100;
        r = i + 1;
        if (!stack.Push(r)) {
            cout << "Push failed" << endl;
        }
    }

    for (int i = 0; i < 7; i++) {
        stack.Pop();
    }

    stack.Print();
}