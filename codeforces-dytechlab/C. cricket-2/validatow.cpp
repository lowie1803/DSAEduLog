#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAXT = 50'000;
const int MAXN = 100'000;
const int MAXA = 1'000'000'000;

// todo: copy doc from: https://codeforces.com/blog/entry/18426 thanks RR

bool isInLShape(vector <int> v) {
  if (v.size() != 6) return false;
  // check 3 square are different
  for (int i = 0; i < 6; i += 2) {
    for (int j = i + 2; j < 6; j+=2) {
      if (v[i] == v[j] && v[i+1] == v[j+1]) return false;
    }
  }

  // check 3 square in the same 2x2 grid (thanks, magnified)
  for (int i = 0; i < 6; i += 2) {
    for (int j = i + 2; j < 6; j+=2) {
      if (abs(v[i] - v[j]) > 1 || abs(v[i+1] - v[j+1]) > 1) return false;
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int testCount = inf.readInt(1, MAXT, "testCount");
  inf.readEoln();
  for (int test = 1; test <= testCount; test++) {
    setTestCase(test);
    int n = inf.readInt(4, MAXN, "n");
    inf.readEoln();
    vector <int> v(6, 0);
    for (int i = 0; i < 6; i++) {
      v[i] = inf.readInt(1, n, "v[i]");
      if (i < 5) inf.readSpace();
      else inf.readEoln();
    }

    ensuref(isInLShape(v), "the pieces are not standing in a correct shape");

    inf.readInt(1, n, "x");
    inf.readSpace();
    inf.readInt(1, n, "y");
    inf.readEoln();
  }
  inf.readEof();
}
