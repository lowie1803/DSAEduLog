#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;

const int MAXT = 50'000;
const int MAXN = 200'000;
const int MAXSUMN = 1'000'000;
const int MAXA = 1'000'000'000;

// todo: copy doc from: https://codeforces.com/blog/entry/18426 thanks RR
vector <int> root;
int getroot(int u) {
  if (u == root[u]) return u;
  return root[u] = getroot(root[u]);
}
void mergeroot(int u, int v) {
  if (getroot(u) == getroot(v)) return;
  root[getroot(u)] = getroot(v);
}

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int testCount = inf.readInt(1, MAXT, "testCount");
  inf.readEoln();
  int totalN = 0, totalM = 0;
  for (int test = 1; test <= testCount; test++) {
    setTestCase(test);
    int n = inf.readInt(2, 200'000, "n");
    inf.readSpace();
    totalN += n;
    ensuref(totalN < MAXSUMN, "total of N in all testcases surpass max value");
    int m = inf.readInt(n - 1, 200'000, "m");
    totalM += m;
    ensuref(totalM < MAXSUMN, "total of M in all testcases surpass max value");
    inf.readEoln();

    root.assign(n+1, 0);
    for (int i=1; i<=n; i++) root[i] = i;

    for (int i = 0; i < m; i++) {
        int a = inf.readInt(1, n, "a_i");
        inf.readSpace();
        int b = inf.readInt(1, n, "b_i");
        inf.readSpace();
        int w = inf.readInt(1, 1e9, "w_i");
        inf.readEoln();

        ensuref(a != b, "Graph can't contain loops");

        mergeroot(a, b);
    }

    for (int i=2; i<=n; i++) ensuref(getroot(i) == getroot(1), "Graph is not connected, %d and %d in different part", 1, i);
  }
  inf.readEof();
}
