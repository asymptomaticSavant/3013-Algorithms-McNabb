/*****************************************************************************
*                    
*  Author:           Terry Griffin, Katherine C. McNabb
*  Email:            terry.griffin@msutexas.edu, katherine.claire.mcnabb@gmail.com
*  Label:            A04
*  Title:            Linked List Class
*  Course:           CMPS 3013
*  Semester:         Spring 2020
* 
*  Description:
*        This program implements a class that allows a linked list to be used just like 
*        an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
*        array elements, but really it traverses the list to find the specified node using
*        an index value. It also overloads the "+" signs allowing a user to "add"
*        or "push" items onto the end of the list. 
*        This class is not meant to replace the STL vector library, its simply a project
*        to introduce the beginnings of creating complex / abstract data types. 
*        
*  Usage: 
*       - $ ./main filename
*       - This will read in a file containing whatever values to be read into our list/array. 
*       
*  Files:            
*       main.cpp    : driver program 
*****************************************************************************/
#include <iostream>

using namespace std;

int A[100];


/**
 * Node
 * 
 * Description:
 *      Creates a node, which stores a int value, and is linked to another node.
 * 
 * Public Methods:
 *      - Node()
 *      - Node(int)
 * Usage: 
 * 
 *      - Node()    //default constructor
 *      - Node(int) //constructor; given value is stored in Node
 *      
 */
struct Node {
    int x;
    Node *next;

    /**
     * Public : Node
     * 
     * Description:
     *      Intializes int x to -1 and next to null.
     */
    Node() {
        x = -1;
        next = NULL;
    }

    /**
     * Public : LoadList
     * 
     * Description:
     *      Intializes x to given value, and next to null.
     * 
     * Params:
     *      [int]   :  x value
     */
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      Creates a list based on nodes, where int values can be stored and removed.
 * 
 * Public Methods:
 *      - List()
 *      - void Push(int)
 *      - void insert(int)
 *      - void PrintTail()
 *      - string Print()
 *      - int Pop()
 *      - List operator+(const List &Rhs)
 *      - int operator[](int)
 *      - int main(int argc, char **argv)
 * 
 * Usage: 
 * 
 *      - List()                          //default constructor
 *      - void Push(int)                  //pushes given value to the list
 *      - void insert(int)                //inserts value into the list
 *      - void PrintTail()                //prints the tail of the list
 *      - string Print()                  //returns a string of list values.
 *      - int Pop()                       //not implemented
 *      - List operator+(const List &Rhs) //overloads the + operator to work with
 *                                        //lists
 *      - int operator[](int) //overloads the [] operator to work with
 *                                        //lists
 *      - int main(int argc, char **argv) //tests lists; prints var. values
 *      
 */
class List {
private:
    Node *Head;
    Node *Tail;
    int Size;

public:
     /**
     * Public : List
     * 
     * Description:
     *      Intialized Head and Tail to null, and Size to 0.
     */
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

     /**
     * Public : Push
     * 
     * Description:
     *      Adds a given value to the list.
     * 
     * Params:
     *      [int]    :  value to be added to the list
     */
    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

     /**
     * Public : Insert
     * 
     * Description:
     *       Adds a given value to the list.
     * 
     * Params:
     *      [int]    :  value to be added
     */
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

  /**
     * Public : PrintTail
     * 
     * Description:
     *      Prints the x-value of the tail node of the list.
     */
    void PrintTail() {
        cout << Tail->x << endl;
    }

    /**
     * Public : Print
     * 
     * Description:
     *      Returns a string of list values.
     * Returns:
     *      [string] list   : string of list values
     */
    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    /**
     * Public : Pop
     * 
     * Description:
     *      Alters the size value by -1; Not currently fully implemented.
     * 
     * Params:
     *      [int]    :  not implemented
     */
    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

     /**
     * Public : operator+
     * 
     * Description:
     *      Overloads the + operator.
     * 
     * Params:
     *      [const List &Rhs]    :  class input
     * 
     * Returns:
     *      [List] NewList   : new list
     */
    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

     /**
     * Public : operator[]
     * 
     * Description:
     *      Overloads the [] operator. This function returns an
    // int value as if the list were an array.
     * 
     * Params:
     *      [int]    :  index
     * 
     * Returns:
     *      [int] List*   : value of the selected node.
     */
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

/**
* Public : main
* 
* Description:
*      Tests list; prints various values.
* 
* Params:
*      [int argc, char **argv]  :  main hyjinks
* 
* Returns:
*
*      [int] : 0.
*/
int main(int argc, char **argv) {
    List L1;
    List L2;

    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}