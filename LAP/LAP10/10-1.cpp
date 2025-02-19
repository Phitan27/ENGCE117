#include <stdio.h>

void SetArray(int **Arr, int *n);
void PrintArray(int Arr[], int n, char comment[20]);
int BinarySearch(int Arr[], int n, int find);
void MergeSort(int t[], int k);
void Merge(int *u, int m, int *v, int n, int *t);

int main() {
    int n = 0, pos = -1, find = -1, *data;
    SetArray(&data, &n);
    PrintArray(data, n, "Origin");
    MergeSort(data, n);
    PrintArray(data, n, "Sort");
    printf("Search (value) : ");
    scanf("%d", &find);
    pos = BinarySearch(data, n, find);
    printf("FOUND %d in POSITION = Arr[%d]\n", data[pos], pos);
    return 0;
}

void PrintArray(int *Arr, int n, char comment[20]) { //TODO: comment คือข้อความที่อยากแสดงตรงส่วนหัวของชุดข้อความ
    printf("%s : ", comment);
    for (int i = 0; i < n; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void SetArray(int **Arr, int *n) {
    printf("Enter Arr size : ");
    scanf("%d", n);
    static int data[100]; // เปลี่ยนให้ใช้ static array ขนาดใหญ่พอที่จะเก็บข้อมูลได้
    *Arr = data;
    for (int i = 0; i < *n; i++) {
        printf("Arr[%d] : ", i);
        scanf("%d", (*Arr) + i);
    }
}

int BinarySearch(int arr[], int n, int find) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == find)
            return mid;
        if (arr[mid] < find)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void MergeSort(int t[], int k) {
    if (k < 2) return;
    int mid = k / 2;
    static int left[100], right[100]; // เปลี่ยนให้ใช้ static array ขนาดใหญ่พอที่จะเก็บข้อมูลได้
    for (int i = 0; i < mid; i++) {
        left[i] = t[i];
    }
    for (int i = mid; i < k; i++) {
        right[i - mid] = t[i];
    }
    MergeSort(left, mid);
    MergeSort(right, k - mid);
    Merge(left, mid, right, k - mid, t);
}

void Merge(int *u, int m, int *v, int n, int *t) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (u[i] <= v[j])
            t[k++] = u[i++];
        else
            t[k++] = v[j++];
    }
    while (i < m) {
        t[k++] = u[i++];
    }
    while (j < n) {
        t[k++] = v[j++];
    }
}
