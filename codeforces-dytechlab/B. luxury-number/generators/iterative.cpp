#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

int main(int argc, char* argv[])
{
  registerGen(argc, argv, 0);
  int testCount = opt<long long>("T");
  ll leftMin = opt<long long>("MINL");
  ll rightMin = opt<long long>("MINR");
  ll leftMax = opt<long long>("MAXL");
  ll rightMax = opt<long long>("MAXR");
  vector <pair <ll, ll> > tests;
  ll curL = leftMin, curR = rightMin;
  while (tests.size() < testCount && curL <= leftMax) {
    tests.push_back({curL, curR});
    curR++;
    if (curR > rightMax) {
      curL++;
      curR = max(rightMin, curL);
    }
  }

  shuffle(tests.begin(), tests.end());
  cout << tests.size() << "\n";
  for (auto test: tests) cout << test.first << " " << test.second << "\n";
}
