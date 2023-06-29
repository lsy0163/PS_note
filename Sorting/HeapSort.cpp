#include <bits/stdc++.h>
using namespace std;

int number = 9;
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};
int main(void) {
  // 힙 구성
  for (int i = 1; i < number; i++) {
    int child = i;
    do {
      int root = (child - 1) / 2;
      if (heap[root] < heap[child]) {
        swap(heap[root], heap[child]);
      }
      child = root;
    } while (child != 0);
  }

  // 힙 크기 줄여가면서 반복적으로 힙 구성
  for (int i = number - 1; i >= 0; i--) {
    swap(heap[0], heap[i]);
    int root = 0;
    int child = 1;
    do {
      child = 2 * root + 1;
      // 자식 노드 중 더 큰 값
      if (child < i - 1 && heap[child] < heap[child + 1]) {
        child++;
      }
      // 루트 보다 자식이 더 크면 swap
      if (child < i && heap[root] < heap[child]) {
        swap(heap[root], heap[child]);
      }
      root = child;
    } while (child < i);
  }

  for (int i = 0; i < number; i++) {
    printf("%d ", heap[i]);
  }
  printf("\n");
}