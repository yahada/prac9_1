#include <cstddef>
#include <iostream>


int * copy (const int * v, size_t k, int * w) {
  for (size_t i = 0; i < k; ++i) {
    w[i] = v[i];
  }
  return w+k;
}


int det(const int * a, size_t n) {
  if (!n) {
    return 0;
  } else if (n == 1) {
    return * a;
  } else if (n == 2) {
    int d = a[0] * a[3] - a[1] * a[2];
    return d;
  }

  int res = 0;
  int d = 0;

  for (size_t l = 0; l < n; ++l) {
    int pivot = a[l];
    int * minor = new int[(n-1)*(n-1)];
    for (size_t i = 0; i < n; ++i) {
      const int * lhsRow = a + (i*n);
      int * minorRow = minor + (i-1) * (n-1);
      copy(lhsRow, l, minorRow);
      lhsRow+=(l+1);
      copy(lhsRow, n - l + 1, minorRow);
      
    }
    try {
      d+=(pivot * det(minor, n-1)) * (l%2) ? -1: 1;
      delete[] minor;
    }
    catch(...) {
      delete[] minor;
      throw;
    }

    
    
  }
  return d;
}

int main() {

}