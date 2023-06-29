#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int data[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
      if (data[j] < data[j - 1]) {
        swap(data[j], data[j - 1]);
      }
    }
  }
}

int main(void) {
  int arr[4] = {3, 2, 4, 1};
  bubble_sort(arr, sizeof(arr) / sizeof(int));
  for (int i = 0; i < 4; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}