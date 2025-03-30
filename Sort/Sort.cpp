#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void print(int a[], int n) 
{
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
// Selection Sort
void selectionSort(int a[], int n) 
{
    int min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        if (a[min] < a[i]) swap(a[min], a[i]);
    }
}
// Insertion Sort
void insertionSort(int a[], int n)  
{  
 
    for (int i = 1; i < n; i++) 
    {  
        int key = a[i];  
        int j = i - 1;  
        while (j >= 0 && a[j] > key) 
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = key;  
    }  
}  
// Merge Sort
void merge(int a[], int left, int mid, int right) 
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[right - left + 1]; // temp arr to store merged elements

    while (i <= mid && j <= right) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        }else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= right) {
        temp[k++] = a[j++];
    }
    // copy merged elements back to origin arr
    for (int idx = 0; idx < k; idx++) {
        a[left + idx] = temp[idx];
    }
}
void mergeSort(int a[], int left, int right) 
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
// Heap Sort
void heapify(int a[], int n, int i) 
{
    int largest = i; // assume root is the largest
    int left = 2 * i + 1; // idx left child
    int right = 2 * i + 2; // idx right child

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]); // swap root with the larest child
        heapify(a, n, largest); // heapify the affected subtree
    }
}
void heapSort(int a[], int n) 
{
    // build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    // extract elements 1 by 1 from the heap 
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]); // move the largest elements to the end
        heapify(a, i, 0); // heapify the reduced heap
    }
}
// Quick Sort
int partition(std::vector<int>& a, int low, int high)
{
    int pivot = a[high]; // pivot = last element
    int i = low - 1; // idx for smaller elements

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]); // swap smaller element to the left
        }
    }
    swap(a[i + 1], a[high]); // place pivot to correct pos
    return i + 1; // return pivot idx
}
void quickSort(std::vector<int>& a, int low, int high)
{   
    if (low < high) {
        int privotIndex = partition(a, low, high);
        quickSort(a, low, privotIndex - 1); // sort left part
        quickSort(a, privotIndex + 1, high); // sort right part     
    }
}
// Radix Sort
void countingSort()
{

}
void radixSort(std::vector<int>& a)
{
    int maxNum = *std::max_element(a.begin(), a.end());
    
}

int main() {
    int a[] = {1, 5, 7, 2, 8, 3, 5, 9};
    int na = sizeof(a) / sizeof(a[0]);

    // selectionSort(a, na);
    // print(a, na);

    // insertionSort(a, na);
    // print(a, na);

    // heapSort(a, na);
    // print(a, na);

    // mergeSort(a, 0, na - 1);
    // print(a, na);
    
    // std::vector<int> b = {1, 5, 7, 2, 8, 3, 5, 9};
    // quickSort(b, 0, b.size() - 1);
    // for (int i = 0; i < b.size(); i++) {
    //     std::cout << b[i] << " ";
    // }

    return 0;
}

/* 
Selection sort
1 5 7 2 8 3 9
i=0 min=0: [1] 5 7 2 8 3 9
i=1 min=3: 1 | [5] 7 (2) 8 3 9 -> 1 2 | 7 5 8 3 9
i=2 min=5: 1 2 | [7] 5 8 (3) 9 -> 1 2 3 | 5 8 7 9
i=3 min=3: 1 2 3 | ([5]) 8 7 9 -> 1 2 3 5 | 8 7 9
i=4 min=5: 1 2 3 5 | [8] (7) 9 -> 1 2 3 5 7 | 8 9
i=5 min=5: 1 2 3 5 7 | ([8]) 9 -> 1 2 3 5 7 8 | 9
i=6 min=6: 1 2 3 5 7 8 | ([9]) -> 1 2 3 5 7 8 9 |
i=7 END.

Insertion sort
1 5 7 2 8 3 9
i=0 (1) 5 7 2 8 3 9
i=1 1 (5) 7 2 8 3 9
i=2 1 5 (7) 2 8 3 9
i=3 1 5 7 (2) 8 3 9
    1 2 5 7 8 3 9
i=4 1 2 5 7 (8) 3 9
i=5 1 2 5 7 8 (3) 9
    1 2 3 5 7 8 9
i=6 1 2 3 5 7 8 (9)
i=7 END.


*/