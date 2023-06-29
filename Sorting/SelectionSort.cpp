#include <bits/stdc++.h>
using namespace std;

void selection_sort(int data[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int idx = i;
    for (int j = i + 1; j < n; j++) {
      if (data[j] < data[idx]) {
        idx = j;
      }
    }
    swap(data[i], data[idx]);
  }
}

int main(void) {
  int arr[4] = {3, 2, 4, 1};
  selection_sort(arr, sizeof(arr) / sizeof(int));
  for (int i = 0; i < 4; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}