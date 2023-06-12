#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int>& vec) {
  for (const auto& e : vec) {
    cout << e << " ";
  }
  cout << endl;
}

void permutation(vector<int>& vec, int k) {
  if (k == vec.size() - 1) {
    print_vector(vec);
    return;
  }

  for (int i = k; i < vec.size(); i++) {
    swap(vec[k], vec[i]);
    permutation(vec, k + 1);
    swap(vec[k], vec[i]);
  }
}

int main(void) {
  vector<int> vec{1, 2, 3, 4};
  permutation(vec, 0);
}
