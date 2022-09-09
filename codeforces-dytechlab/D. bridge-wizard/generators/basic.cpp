#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

/*
*  rnd.next(4) - Random int bw 0-3
*  rnd.next(4, 100) - Random int bw 4-100
*  rnd.next(10.0) - Random real [0;10)
*  rnd.next("one|two|three") Random word out of 'one', 'two' and 'three'
*  rnd.next("[1-9][0-9]{99}") Random REGEX (100-digit number as a string)
*  rnd.wnext(4,t) wnext is a method of obtaining an uneven distribution (with a biased expectation)
*  rnd.any(container) A random element of the container container (with random access via an iterator), for example, it works for std::vector and std::string
*  shuffle
*/

/** Extend testlib.h here **/
/**/

void writeTest(int test, int n, int m, int wLimit) {
    // startTest(test);

    vector<int> p(n);
    for (int i = 1; i < n; i++)
        p[i] = rnd.wnext(i, 2);

    vector<int> perm = rnd.perm(n);

    vector<pair<pair<int, int>, int>> edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back({make_pair(perm[i], perm[p[i]]), rnd.next(1, wLimit)});
        else
            edges.push_back({make_pair(perm[p[i]], perm[i]), rnd.next(1, wLimit)});

    for (int i = n; i <= m; i++) {
      int u = rnd.wnext(n-1, -1);
      int v = rnd.next(u+1, n - 1);
      edges.push_back({make_pair(perm[u], perm[v]), rnd.next(1, wLimit)});
    }

    shuffle(edges.begin(), edges.end());

    println(n, m);
    for (auto edge: edges)
        println(edge.first.first + 1, edge.first.second + 1, edge.second);
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int testCount = opt<int>(1);
    int nTotal = opt<int>(2);
    int mTotal = opt<int>(3);
    int wLimit = opt<int>(4);

    int extraEdges = mTotal - nTotal + testCount;

    cout << testCount << "\n";

    for (int i = 1; i <= testCount; i++) {
      int n = (i == testCount ? nTotal : rnd.wnext(2, nTotal - (testCount - i) * 2, -2));
      int m = (i == testCount ? extraEdges : rnd.wnext(extraEdges + 1, -1)) + (n - 1);
      nTotal -= n;
      extraEdges -= (m - n + 1);
      writeTest(i, n, m, wLimit);
    }
}
