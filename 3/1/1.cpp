// Program that calculates a sum of integers from 0 to 39.
//
// Author: Unknown

#include <iostream>

using namespace std;

const int N = 40; // Number of integers

// Calculate the sum of integers
inline void sum(int& p, int n, vector<int> d) {
  p = 0;
  for (int i = 0; i < n; ++i) {
    p = p + d[i];
  }
}

int main() {
  vector<int> data(N);

  // Fill a vector with integers from 0 to N - 1
  for (int i = 0; i < N; ++i) {
    data[i] = i;
  }

  int accum = 0;
  sum(accum, N, data);

  // Print output
  cout << "sum is " << accum << endl;

  return 0;
}
