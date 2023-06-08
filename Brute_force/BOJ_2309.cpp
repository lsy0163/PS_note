#include <bits/stdc++.h>
using namespace std;
int arr[9];
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int sum = 0;
  int a, b;
  for(int i=0; i<9; i++){
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr, arr+9);
  for(int i=0; i<9; i++){
    for(int j=i+1; j<9; j++){
      if(sum-arr[i]-arr[j] == 100){
        a = i;
        b = j;
        break;
      }
    }
  }
  for(int i=0; i<9; i++){
    if(i == a || i == b) continue;
    cout << arr[i] << "\n";
  }
}