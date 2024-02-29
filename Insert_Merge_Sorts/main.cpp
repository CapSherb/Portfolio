/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

int randomInt(int min, int max);

void insertionSort(int arr[], int arrSize);

void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r);

void printArray(int arr[], int arrSize);

int main()
{
    //get size of array from user
    int sizeOfArray;
    cout<<"Please enter the size of the array to be sorted:";
    cin >> sizeOfArray;
    cout << "" << endl;
    
    //initialize arrays with user assigned size
    int arrIns[sizeOfArray];
    int arrMrg[sizeOfArray];
    
    //fill the arrays with the same set of random numbers between -500 and 500
    //same random numbers to more accurately compare execution time of sorts
    for (int i = 0; i < sizeOfArray; i++) {
        int ran = randomInt(-500, 500);
        arrIns[i] = ran;
        arrMrg[i] = ran;
    }
    
///////////////////////|insertion sort|///////////////////////////////////
    //print unsorted array
    cout<<"Unsorted Array:"<<endl;
    printArray(arrIns, sizeOfArray);
    
    //begin timing for insertion sort, run it, then end timing
    auto start_timeIns = chrono::high_resolution_clock::now();
    insertionSort(arrIns, sizeOfArray);
    auto end_timeIns = chrono::high_resolution_clock::now();
    
    //print sorted array    
    cout<<"Insertion Sorted Array:"<<endl;
    printArray(arrIns, sizeOfArray);
    
    //store time for insertion sort in microseconds
    auto durationIns = chrono::duration_cast<chrono::microseconds>(end_timeIns - start_timeIns);

/////////////////////////|merge sort|///////////////////////////////

    auto start_timeMrg = chrono::high_resolution_clock::now();
    mergeSort(arrMrg, 0, sizeOfArray - 1);
    auto end_timeMrg = chrono::high_resolution_clock::now();

    cout<<"Merge Sorted Array:"<<endl;
    printArray(arrMrg, sizeOfArray);
    
     //store time for merge sort in microseconds
    auto durationMrg = chrono::duration_cast<chrono::microseconds>(end_timeMrg - start_timeMrg);
    
//////////////////////|execution times|///////////////////////////////
    // Print the execution time
    cout << "Insertion Sort Execution Time: " << durationIns.count() << " microseconds" << endl;
    cout << "\n" << endl;
    // Print the execution time
    cout << "Merge Sort Execution Time: " << durationMrg.count() << " microseconds" << endl;
    
    return 0;
}

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void insertionSort(int arr[], int arrSize) {
    for (int i = 1; i < arrSize; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int subArr1, int mid, int subArr2) {
    int n1 = mid - subArr1 + 1;
    int n2 = subArr2 - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[subArr1 + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = subArr1; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort on an array
void mergeSort(int arr[], int arrStart, int arrEnd) {
    if (arrStart < arrEnd) {
        // Calculate the middle point of the array
        int mid = arrStart + (arrEnd - arrStart) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, arrStart, mid);
        mergeSort(arr, mid + 1, arrEnd);

        // Merge the sorted halves
        merge(arr, arrStart, mid, arrEnd);
    }
}


void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << "\n" << endl;
}

































