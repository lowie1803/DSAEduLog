#include "testlib.h"

const int MAXT = 1'000;
const int MAXN = 1'000'000;
const int MAXA = 1'000'000'000;

// todo: copy doc from: https://codeforces.com/blog/entry/18426 thanks RR

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int tests = inf.readInt(1, MAXT, "T");
  inf.readEoln();
  int sumN = 0;
  for (int test = 1; test <= tests; test++) {
    setTestCase(test);
    int n = inf.readInt(1, MAXN, "n");
    sumN += n;
    ensuref(sumN <= MAXN, "sum of n exceeded %d", MAXN);
    inf.readEoln();
  }
  inf.readEof();
}
