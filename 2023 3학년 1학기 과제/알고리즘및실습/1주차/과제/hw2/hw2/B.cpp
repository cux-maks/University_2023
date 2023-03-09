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

/*
합병정렬의 공간복잡도

line 4, line 23, line 40 참고

line 4를 보면, 함수의 매개변수로 int *arr을 받고있다. 이는 포인터로 변수의 주소값을 나타낸다.
여기에서는 정수 배열의 이름을 전달함으로써 배열의 주소값을 전달하는것으로 해석할 수 있다.
따라서 해당 함수에서는 추가적인 공간을 사용하지 않는다.

line 23을 보면, 함수의 매개변수로 int *arr을 받고있다. line 4와 마찬가지로 배열의 주소값을 전달하는것으로 해석할 수 있다.
따라서 해당 함수에서도 추가적인 공간을 사용하지 않는다.

line 40을 보면, int *nums = new int[N];을 통해 N개의 정수형 변수를 저장할 수 있는 배열을 동적할당 하고있다.
따라서 이 부분에서는 N개의 추가 공간을 사용하고 있다.

위의 내용을 종합해보았을 때, 이 코드의 공간 복잡도는 O(N)이라고 할 수 있다.
*/
