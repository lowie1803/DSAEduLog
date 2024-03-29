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

const int STRING_LEN_LIMIT = 100'000;


int main(int argc, char* argv[])
{
  registerGen(argc, argv, 0);
  int numberOfTests = atoi(argv[1]);
  string letterUsed = argv[2];
  int totalChar = atoi(argv[3]);

  vector <string> tests;
  int strlen;
  string str;
  int remainingChar = totalChar;
  for (int i = numberOfTests; i > 0; i--) {
    strlen = (i == 1 ? remainingChar : (rnd.wnext(totalChar / numberOfTests / 2, totalChar / numberOfTests * 2, -4)));
    strlen = min(strlen, STRING_LEN_LIMIT);
    remainingChar -= strlen;
    str = "";
    for (int j = 0; j < strlen; j++) str += rnd.any(letterUsed);
    tests.push_back(str);
  }

  shuffle(tests.begin(), tests.end());
  cout << numberOfTests << "\n";
  for (string s: tests) cout << s << "\n";
}
