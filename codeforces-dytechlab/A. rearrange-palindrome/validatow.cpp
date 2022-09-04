#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXT = 10'000;
const int MAXN = 100'000;
const int MAX_TOTAL = 200'000;
const int MAXA = 1'000'000'000;

// todo: copy doc from: https://codeforces.com/blog/entry/18426 thanks RR

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int testCount = inf.readInt(1, MAXT, "testCount");
  inf.readEoln();
  string pattern = "[a-z]{1," + toString(MAXN) + "}";
  
  int totalLen = 0;
  for (int testCase = 1; testCase <= testCount; testCase++) {
    setTestCase(testCase);
    string str = inf.readToken(pattern, "str");
    inf.readEoln();

    totalLen += str.length();
    ensuref(totalLen <= MAX_TOTAL, "test %d, totalLen too long, total %d", testCase, totalLen);
  }
  inf.readEof();
}
