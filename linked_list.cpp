/*  Name : Sandesh Prakash Bhagwat
    Branch : AI&DS
    Div : A
    Roll No : 13
    PRN : 12110367

    ADS Assignment 4: Linked List
                        1.Implementation of Singly Linked List
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;

        if(this->next != NULL){
            this->next = NULL;
            delete next;
        }
        cout << "Node with data " << val << " is deleted.\n";
    }
};

void insertAtHead(Node* &head){
    cout << "\nEnter data/key for the node: ";
    int d;
    cin >> d;
    Node * new_node = new Node(d);
    if(head==NULL){
        head = new_node;
        return;
    }

    new_node -> next = head;
    head = new_node;
}

void insertAtTail(Node* &head){
    cout << "\nEnter data/key for the node: ";
    int d;
    cin >> d;
    Node * new_node = new Node(d);

    Node * temp = head;
    if(temp == NULL){
        head = new_node;
        return;
    }

    while(temp -> next  != NULL){
        temp = temp -> next;
    }

    temp -> next = new_node;
}

void insertAfterNode(Node * &head){


    Node * temp = head;

    if(temp == NULL){
        cout << "List is empty!!\n";
        return;
    }

    cout << "After which position?: \n";
    int n;
    cin >> n;

    cout << "\nEnter data/key for the node: ";
    int d;
    cin >> d;

    if(n == 0){
        insertAtHead(head);
        return;
    }

    while(n>1 && temp!= NULL){
        temp = temp -> next;
        n--;
    }

    if(temp == NULL){
        cout << "List underflows!\n";
        return;
    }

    Node * new_node = new Node(d);
    new_node -> next = temp -> next;
    temp -> next = new_node;
}

void insertNode(Node * &head){
    cout << "\nEnter location to insert node: \n";
    cout << "1.Head\n2.After node\n3.At tail\n4.Back to operations menu\n";
    int loc;
    cin >> loc;

    switch(loc){
        case 1:
            insertAtHead(head);
            insertNode(head);
            break;

        case 2:
            insertAfterNode(head);
            insertNode(head);
            break;

        case 3:
            insertAtTail(head);
            insertNode(head);
            break;
        
        case 4:
            return;

        default:
            cout << "Invalid choice!!!\n";
            insertNode(head);
            break;

    }

}

void deleteHead(Node * &head){
    Node * temp = head;
    if(temp == NULL){
        cout << "List is empty!!!\n";
        return;
    }

    head = temp -> next;
    delete temp;
}

void deleteTail(Node * &head){
    Node * temp = head;
    if(temp == NULL){
        cout << "List is empty!!!\n";
        return;
    }
    Node * prev = temp;
    while(temp ->next != NULL){
        prev = temp;
        temp = temp -> next;
    }

    prev -> next = NULL;
    delete temp;
}

void deleteKeyNode(Node * &head){
    cout << "\nEnter the key of node: ";
    int  key;
    cin >> key;

    Node * temp = head;
    if(temp == NULL){
        cout << "List is empty!!!\n";
        return;
    }
    if(temp -> data == key){
        deleteHead(head);
    }

    Node * prev = temp;
    while(temp -> data != key && temp != NULL){
        prev = temp;
        temp = temp -> next;
    }

    if(!temp){
        cout << "Key not found!\n";
        return;
    }
    
    prev -> next = temp -> next;
    delete temp;

}

void deleteNode(Node * &head){
    cout << "\nEnter location to delete node: \n";
    cout << "1.From Head\n2.Node with specific key\n3.From tail\n4.Back to operations menu\n";
    int loc;
    cin >> loc;

    switch(loc){
        case 1:
            deleteHead(head);
            deleteNode(head);
            break;

        case 2:
            deleteKeyNode(head);
            deleteNode(head);
            break;

        case 3:
            deleteTail(head);
            deleteNode(head);
            break;
        
        case 4:
            return;

        default:
            cout << "Invalid choice!!!\n";
            deleteNode(head);
            break;
    }

}

void display(Node * &head){
    Node * temp = head;
    if(temp == NULL){
        cout << "List is empty!\n";
        return;
    }

    cout << "Linked list elements: ";
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void ops(Node * &head){
    cout << "\nEnter your choice: \n";
    cout << "1.Insert node\n2.Delete node\n3.Display Linked List\n4.Exit\n";
    int choice;
    cin >> choice;
    
    switch(choice){
        case 1:
            insertNode(head);
            ops(head);
            break;

        case 2:
            deleteNode(head);
            ops(head);
            break;

        case 3:
            display(head);
            ops(head);
            break;
        
        case 4:
            return;

        default:
            cout << "Invalid choice!!!\n";
            ops(head);
            break;
    }
}

int main(){
    Node * head = NULL;
    ops(head);
    return 0;
}