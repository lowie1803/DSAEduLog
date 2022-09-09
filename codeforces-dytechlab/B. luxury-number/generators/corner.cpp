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
  ll maxLimit = opt<long long>("MAXLR");
  int wnextIndicator = opt<int>("WNEXT");
  cout << testCount << "\n";
  for (int i = 0; i < testCount; i++) {
    ll sqrtMax = sqrt(maxLimit);
    ll sqrtlr = rnd.wnext(1ll, sqrtMax, wnextIndicator);
    ll l = rnd.next(sqrtlr * sqrtlr, (sqrtlr + 1) * (sqrtlr + 1) - 1);
    ll r = rnd.next(l, (sqrtlr + 1) * (sqrtlr + 1) - 1);
    cout << l << " " << r << "\n";
  }
}
