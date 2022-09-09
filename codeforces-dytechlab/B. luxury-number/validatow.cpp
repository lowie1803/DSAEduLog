#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXT = 100'000;
const int MAXN = 100'000;
const long long MAXA = 1'000'000'000'000'000'000;

// todo: copy doc from: https://codeforces.com/blog/entry/18426 thanks RR

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int testCount = inf.readInt(1, MAXT, "testCount");
  inf.readEoln();
  for (int i = 0; i < testCount; i++) {
    setTestCase(i);
    long long l = inf.readLong(1, MAXA, "l");
    inf.readSpace();
    inf.readLong(l, MAXA, "r");
    inf.readEoln();
  }
  // inf.readEoln();
  inf.readEof();
}
