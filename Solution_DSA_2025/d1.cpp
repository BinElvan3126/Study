#include <iostream>
#include <vector>

using namespace std;
// Bai 1 - a
void merge(vector<char> &a, int left, int mid, int right) 
{
    int i,j,k;
    i=left, j=mid+1, k=0;
    int temp[right - left + 1];
    while (i <= mid && j <= right) {
        if((int)a[i] >= (int)a[j]) {
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
    for (int i = 0; i < k; i++) {
        a[left + i] = temp[i];
    }
}
void mergeSort(vector<char> &a, int left, int right) 
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
// Bai 1 - b

int minCandyDiff(vector<int>& a, int k) {
    const int MAX_VAL = 999;
    vector<int> count(MAX_VAL + 1, 0);

    // Đếm số lượng từng giá trị
    for (int val : a) {
        count[val]++;
    }

    // Tạo mảng đã sắp xếp từ count (Counting Sort)
    vector<int> sorted;
    for (int val = 1; val <= MAX_VAL; val++) {
        while (count[val]--) {
            sorted.push_back(val);
        }
    }

    // Tìm đoạn con k phần tử có hiệu nhỏ nhất
    int minDiff = INT_MAX;
    for (int i = 0; i + k - 1 < sorted.size(); i++) {
        int diff = sorted[i + k - 1] - sorted[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}


int main() {
    vector<char> a = {'F','I','T','A','N','N','I','V',
                      'E','R','S','A','R','Y','3','0'};
    mergeSort(a, 0, a.size() - 1);
    for (char c : a) {
        cout << c << " ";
    }     
    cout << endl;            
    return 0;
}