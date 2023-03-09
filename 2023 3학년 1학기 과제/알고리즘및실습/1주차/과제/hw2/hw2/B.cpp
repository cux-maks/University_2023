#include <iostream>
using namespace std;

void merge(int* arr, int left, int mid, int right) {
    int* nums_sorted = new int[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) nums_sorted[k++] = arr[i++];
        else nums_sorted[k++] = arr[j++];
    }
    if (i > mid) {
        while (j <= right) nums_sorted[k++] = arr[j++];
    }
    else {
        while (i <= mid) nums_sorted[k++] = arr[i++];
    }
    for (i = left, k = 0; i <= right; i++, k++) arr[i] = nums_sorted[k];
    delete[] nums_sorted;
}

void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {

    int T = 0;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        int *nums = new int[N];
        for (int j = 0; j < N; j++) cin >> nums[j];
        mergeSort(nums, 0, N - 1);
        for (int j = 0; j < N; j++) cout << nums[j] << " ";
        cout << "\n";
    }

    return 0;
}