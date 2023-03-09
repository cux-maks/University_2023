#### 1주차 과제
## A번 문제
```c++
// set자료구조 미사용

#include <iostream>
 
using namespace std;
 
int main() {
 
    int T = 0;
    cin >> T;
 
    for (int i = 0; i < T; i++) {
        int cnt = 0;
        string S;
        cin >> S;
        for (int j = 3; j < S.length() + 1; j++) {
            if (S[j - 3] != S[j - 2] && S[j - 2] != S[j - 1] && S[j - 3] != S[j - 1]) {
                cnt += 1;
            }
        }
        cout << cnt << endl;
    }
 
    return 0;
}
```
```c++
// set자료구조 사용
#include <iostream>
#include <set>
 
using namespace std;
 
int main() {
 
    int T = 0;
    cin >> T;
 
    for (int i = 0; i < T; i++) {
        int cnt = 0;
        string S;
        cin >> S;
        for (int j = 3; j < S.length() + 1; j++) {
            set<char> s;
            s.insert(S[j - 3]);
            s.insert(S[j - 2]);
            s.insert(S[j - 1]);
            if (s.size() == 3) cnt++;
        }
        cout << cnt << endl;
    }
 
    return 0;
}
```

## B번 문제
```c++
// 합병정렬
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
```
```c++
// 팀정렬
#include <iostream>
using namespace std;
const int RUN = 32;
 
void insertionSort(int *arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
 
void merge(int *arr, int l, int m, int r)
{
    int len1 = m - l + 1;
    int len2 = r - m;
    int* left = new int[len1];
    int* right = new int[len2];
    for (int i = 0; i < len1; i++) left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}
 
void timSort(int *arr, int n)
{
 
    for (int i = 0; i < n; i += RUN) insertionSort(arr, i, min((i + RUN - 1), (n - 1)));
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
 
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right) merge(arr, left, mid, right);
        }
    }
}
 
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        int* nums = new int[N];
        for (int j = 0; j < N; j++) cin >> nums[j];
        timSort(nums, N);
        for (int j = 0; j < N; j++) cout << nums[j] << " ";
        cout << "\n";
    }
    return 0;
}
```
