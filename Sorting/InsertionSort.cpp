#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int data[], int n) {
  for (int i = 1; i < n; i++) {
    int key = data[i];
    int j = i - 1;
    while (j >= 0 && data[j] > key) {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = key;
  }
}

int main(void) {
  int arr[4] = {3, 2, 4, 1};
  insertion_sort(arr, sizeof(arr) / sizeof(int));
  for (int i = 0; i < 4; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}