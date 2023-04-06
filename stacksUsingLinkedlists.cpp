//
// Created by DELL on 4/5/2023.
//
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;
class Node
{
public:
    int data; //store elements of a stack
    Node *next; //pointer to next node
};

class Stack
{
private:
    Node *top;
public:
    Stack(){top=NULL;}

    void push(int x)
    {
        Node *t=new Node;
        /* if New node fails to create i.e NULL*/
        if(t==NULL)
            cout<<"Stack is Full\n";
        else
        {   //enter the new data and update top pointer
            t->data=x;
            t->next=top;
            top=t;
        }
    }

    bool isEmpty(){
        // If top is NULL it means that
        // there are no elements are in stack
        return top == NULL;
    }

    /*bool isFull(){
        return top = ;
    }*/

    int pop()
    {
        int x=-1;
        //if top pointer is empty
        if(top==NULL)
            cout<<"Stack is Empty\n";
        else
        {   //data stored at top
            x=top->data;
            Node *t=top;
            //top points to next pointer
            top=top->next;
            //delete previous node
            delete t;
        }
        return x;
    }

    void display()
    {
        Node *p=top;
        //iterate till the end i.e NULL
        while(p!=NULL)
        {   //print data at each pointer
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }

    int stackTop()
    {
        // If stack is not empty , return the top element
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

};

int main()
{
    auto start = high_resolution_clock::now();
    srand(time(NULL));

    Stack myStack;
    myStack.push(8);
    myStack.push(10);
    myStack.push(5);
    myStack.push(11);
    myStack.push(15);
    myStack.push(23);
    myStack.push(6);
    myStack.push(18);
    myStack.push(20);
    myStack.push(17);

    myStack.display();

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();

    myStack.display();

    myStack.push(4);
    myStack.push(30);
    myStack.push(3);
    myStack.push(1);

    myStack.display();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double time = duration.count() / 1000000.0;
    cout << "time taken is: " << time << " seconds" << endl;

    return 0;
}