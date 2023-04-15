/*  Name : Sandesh Prakash Bhagwat
    Branch : AI&DS
    Div : A
    Roll No : 13
    PRN : 12110367

    ADS Assignment 1 : Insertion sort, Quick sort, Binary search.
*/


#include <iostream>
using namespace std;

/*int * takeInput(){
    int n, x;
    cout << "Size of an array: " << endl;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> x;
        arr[i]= x;
    }
    return arr;
}*/


void insertionSort(int arr[], int n){

    for(int i=1; i<n; i++){
        int j=i-1;
        int num = arr[i];
        while(j>=0 && arr[j]>num){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = num;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(){}

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int i = start;

    for(int j=start+1; j<=end; j++){
        if(arr[j]<=pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int tp = arr[i];
    arr[i] = arr[start];
    arr[start] = tp;
    return i;
}

void quickSort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int k = partition(arr, start, end);
    quickSort(arr, start, k-1);
    quickSort(arr, k+1, end);

}

void binarySearch(int arr[], int n){

    int k;
    cout << "Which number do you want?" << endl;
    cin >> k;

    int low=0, high=n-1, mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if(k<arr[mid]){
            high = mid-1;
        }
        else if(k>arr[mid]){
            low = mid+1;
        }
        else{
            cout << "Integer present at index: " << mid;
            cout << endl;
            return;
        }
    }
    cout << "Integer not found!!!\n";
    return;
}

void printArray(int arr[], int n){
    cout << "Sorted array: \n";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ops(){

    //Taking Input
    int n, x;
    cout << "\n\nSize of an array: " << endl;
    cin >> n;
    int arr[n];
    printf("Enter %d array elements:\n", n);
    for(int i=0; i<n; i++){
        cin >> x;
        arr[i]= x;
    }

    int operation;
    cout << "Select the operation: " << endl;
    cout << "1.Insertion Sort\n";
    //cout << "2.Merge Sort\n";
    cout << "2.Quick Sort\n";
    cout << "3.Binary Search\n";
    cout << "4.EXIT\n";
    cin >> operation;

    switch(operation){
        case 1:
            insertionSort(arr, n);
            printArray(arr, n);
            ops();
            break;

        case 2:
            quickSort(arr, 0, n-1);
            printArray(arr, n);
            ops();
            break;

        case 3:
            quickSort(arr, 0, n-1);
            printArray(arr, n);
            binarySearch(arr, n);
            ops();
            break;

        case 4:
            return;

        default:
            cout << "Invalid operation";
            ops();
    }
}

int main(){

    //Operations
    ops();
    return 0;
}