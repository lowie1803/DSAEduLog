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

vector <int> coordinateLPieces(int x, int y, int mode) {
  vector <pair <int, int> > squares = {};
  for (int i = x; i < x + 2; i++) {
    for (int j = y; j < y + 2; j++) {
      squares.push_back({i, j});
    }
  }

  vector <pair <int, int> > squaresUsed = {};
  for (int i = 0; i < 4; i++) if (i != mode) squaresUsed.push_back(squares[i]);
  shuffle(squaresUsed.begin(), squaresUsed.end());

  vector <int> res = {};
  for (auto p: squaresUsed) {
    res.push_back(p.first);
    res.push_back(p.second);
  }
  return res;
}

const int N_MIN = 4;

int main(int argc, char* argv[])
{
  registerGen(argc, argv, 0);
  int testCount = opt<int>("T");
  int n = opt<int>("N");

  vector <vector <int> > cases;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
          for (int mode = 0; mode < 4; mode++) {
            if (cases.size() >= testCount) continue;

            vector <int> cas = coordinateLPieces(i, j, mode);
            cas.push_back(u);
            cas.push_back(v);
            cases.push_back(cas);
          }
        }
      }
    }
  }
  shuffle(cases.begin(), cases.end());

  cout << cases.size() << "\n";
  for (auto cas: cases) {
    cout << n << "\n";
    for (int i = 0; i < 6; i++) {
      cout << cas[i] << (i == 5 ? "\n" : " ");
    }
    cout << cas[6] << " " << cas[7] << "\n";
  }
}
