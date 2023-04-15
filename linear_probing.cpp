/*  Name : Sandesh Prakash Bhagwat
    Branch : AI&DS
    Div : A
    Roll No : 13
    PRN : 12110367

    ADS Assignment 6B: Hashing - Linear Probing
*/

#include<bits/stdc++.h>
using namespace std;

int hashKey(int n){
    return n%10;
}

void insert(int n, int arr[10][2]){
    int ind = hashKey(n);
    int count = 0;
    bool done = 0;
    for(int i=ind; i<10+ind-1; i++){
        if(arr[i%10][count&1]==-1){
            arr[i%10][count&1] = n;
            cout << "Successfully inserted!!\n";
            done = 1;
            return;
        }
        count++;
        if(arr[i%10][count&1]==-1){
            arr[i%10][count&1] = n;
            cout << "Successfully inserted!!\n";
            done = 1;
            return;
        }
        count++;
    }
    if(!done)cout << "Failed to insert!!\n";
}

void printHashSet(int arr[10][2]){
    cout << "HashTable: \n";
    for(int i=0; i<10; i++){
        for(int j=0; j<2; j++){
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
}

void hashSet(){
    cout << "\nEnter the size of input: ";
    int size;
    cin >> size;
    int arr[10][2];
    for(int i=0; i<10; i++){
        for(int j=0; j<2; j++){
            arr[i][j]=-1; 
        }
    }

    for(int i=0; i<size; i++){
        cout << "\nEnter the element: ";
        int n;
        cin >> n;
        insert(n, arr);
        printHashSet(arr);
    }
    cout << "Input limit reached!\n";
    printHashSet(arr);
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    hashSet();
    return 0;
}