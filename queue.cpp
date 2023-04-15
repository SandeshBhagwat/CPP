/*  Name : Sandesh Prakash Bhagwat
    Branch : AI&DS
    Div : A
    Roll No : 13
    PRN : 12110367

    ADS Assignment 3: Queue
                        1.Implementation of Circular Queue 
                        2.Reversing Stack using Queue
*/

#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 2
int front=0, reare = -1;
int Queue[MAX_SIZE];

void enQueue(int num){
    if(reare - front == (MAX_SIZE-1)){
        cout << "Queue is full!!!\n";
    }
    else{
        Queue[++reare%MAX_SIZE] = num;
    }
}

void deQueue(){
    if(front==reare){
        cout << "Queue is empty!!!\n";
    }
    else{
        cout << "Deleted element: " << Queue[front%MAX_SIZE] << endl;
        front++;
    }
}

void display(){
    cout << "Queue element: ";
    if(front==reare){
        cout << "Queue is empty!\n";
    }
    else{
        for(int i=front; i<=reare; i++){
            cout << Queue[i%MAX_SIZE] << " ";
        }
    }
}

void circularQueue(){
    cout << "\nEnter your choice: \n";
    cout << "1. Enque\n2. Deque\n3. Display\n4. Back\n\n";
    int choice;
    cin >> choice;

    switch(choice){
        case 1:
            int num;
            cout << "Enter number to EnQueue: ";
            cin >> num;
            enQueue(num);
            circularQueue();
            break;
        
        case 2:
            deQueue();
            circularQueue();
            break;

        case 3:
            display();
            circularQueue();
            break;

        case 4:
            return;

        default:
            cout << "Invalid choice\n";
            circularQueue();
    }
}

void pushStack(int &top, int stack[], int n, int ele){
    if(top==n-1){
        cout << "Stack is full!";
    }
    else{
        stack[++top] = ele;
    }
}

void printStack(int &top, int stack[]){
    int temp = top;
    if(temp==-1){
        cout << "Stack is empty!";
    }
    while(temp!=-1){
        cout << stack[temp--] << " ";
    }
}

bool stackIsEmpty(int &top){
    if(top==-1) return true;
    return false;
}

bool queueIsEmpty(int front, int n){
    if(front == n) return true;
    return false;
}

// void enQue(int &front, int &back, int Que[], int ele, int n){
//     Que[++reare] = ele;
// }

void reverseStack(){
    cout << "Enter the size of stack: \n";
    int n, top=-1;
    cin >> n;
    int stack[n];
    cout << "Enter elements of stack: \n";
    for(int i=0; i<n; i++){
        int ele;
        cin >> ele;
        pushStack(top, stack, n, ele);
    }
    cout << "Entered stack is: ";
    printStack(top, stack);

    int Que[n];
    int front = 0, reare=-1;
    while(!stackIsEmpty(top)){
        // enQue(front, back, Que, stack[top--], n);
        Que[++reare] = stack[top--];
    }

    while(!queueIsEmpty(front, n)){
        stack[++top] = Que[front++];
    }

    cout << "\nReversed stack is: ";
    printStack(top, stack);
}

void ops(){
    cout << "\nEnter the choice: \n" << endl;
    cout << "1. Circular queue operations.\n2. Reverse stack using queue.\n3. Exit\n\n";
    int choice;
    cin >> choice;

    switch(choice){
        case 1:
            circularQueue();
            ops();
            break;

        case 2:
            reverseStack();
            ops();
            break;

        case 3:
            return;

        default:
            cout << "Invalid choice!!!\n";
            ops();
    }
}


int main(){

    ops();
    return 0;
}