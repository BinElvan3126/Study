#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void selectionSort(int a[], int n) {
    int min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        if (a[min] < a[i]) swap(a[min], a[i]);
    }
}
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


int main() {
    int a[] = {1, 5, 7, 2, 8, 3, 9};
    int na = sizeof(a) / sizeof(a[0]);

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
i=0 key=
*/