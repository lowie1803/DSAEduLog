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

const int N_MAX = 100'000;

int main(int argc, char* argv[])
{
  registerGen(argc, argv, 0);
  int testCount = opt<int>("T");
  int cornerFreq = opt<int>("CFreq"); // corners will appear in testCount / argv[3] cases

  cout << testCount << "\n";
  for (int test = 1; test <= testCount; test++) {
    int n = N_MAX;

    int cornerCase = rnd.next(cornerFreq);
    vector <int> pieces;
    if (cornerCase == 0) {
      vector <pair <pair <int, int>, int> > cases = {{{1, 1}, 3}, {{1, n - 1}, 2}, {{n - 1, 1}, 1}, {{n - 1, n - 1}, 0}};
      pair <pair <int, int>, int> thisCase = rnd.any(cases);
      pieces = coordinateLPieces(thisCase.first.first, thisCase.first.second, thisCase.second);
    } else {
      int x = rnd.next(1, n - 1);
      int y = rnd.next(1, n - 1);
      int mode = rnd.next(0, 3);
      pieces = coordinateLPieces(x, y, mode);
    }

    int u = rnd.next(1, n), v = rnd.next(1, n);
    cout << n << "\n";
    for (int i = 0; i < pieces.size(); i++) {
      cout << pieces[i] << (i == pieces.size() - 1 ? "\n" : " ");
    }
    cout << u << " " << v << "\n";
  }
}
