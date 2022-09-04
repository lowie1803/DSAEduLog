#include "testlib.h"

const int MAXT = 50'000;
const int MAXN = 1'000'000;
const int MAXA = 1'000'000'000;

// todo: copy doc from: https://codeforces.com/blog/entry/18426 thanks RR

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  inf.readInt(1, MAXN, "n");
  inf.readEoln();
  inf.readEof();
}
