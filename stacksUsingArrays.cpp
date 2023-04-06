//
// Created by DELL on 4/5/2023.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX_SIZE = 100;

class Stack {
private:
    int top;
    int arr[MAX_SIZE];
public:
    Stack(){
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX_SIZE -1;
    }
    void push(int element) {
        if(isFull()) {
            cout << "Error: Stack is full" << endl;
        }else {
            top++;
            arr[top] = element;
        }
    }
    int pop() {
        if(isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return -1;
        } else {
            int poped_element = arr[top];
            top--;
            return poped_element;
        }
    }
    int stackTop() {
        if(isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return -1;
        } else{
            return arr[top];
        }
    }

    void display(){
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }

};

int main(){
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
