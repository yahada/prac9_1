#include <iostream>
#include <cstddef>

int * copy (const int * v, size_t k, int * w) {
  for (size_t i = 0; i < k; ++i) {
    w[i] = v[i];
  }
  return w+k;
}

int det(int * b, const int * lhs, size_t n) {
  if (!n) {
    return 0;
  } else if (n == 1) {
    return * lhs;
  } else if (n == 2) {
    int d = lhs[0] * lhs[3] - lhs[1] * lhs[2];
    return d;
  }

  size_t d = 0;
  for (size_t l = 0; l < n; ++l) {
    int * minor = b;
    for (size_t i = 1; i < n; ++i) {
      const int * lhsRow = lhs + i * n;
      int * minRow = copy(lhsRow, l, minRow);
      lhsRow+=l+1;
      copy(lhsRow, n - (l+1), minRow);
    }
    int * next = b + (n - 1) * (n - 1);
    d+= lhs[l] * det(next, minor, n-1) * (l % 2) ? -1 : 1;
  }
  return d;

}

int main() {
  
}