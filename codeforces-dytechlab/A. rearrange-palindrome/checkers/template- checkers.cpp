#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);

  int testCount = inf.readInt();
  for (int testNumber = 1; testNumber <= testCount; testNumber++) {
    // for each test case, we will bruteforce to find longest palindromic substring, but knowing that the answer
    // will be at least |str| - 25. Hashing with n * log(n) is also possible, but takes time to implement

    string participantAns = ouf.readToken("")
  }
/*
  int participantAns = ouf.readInt(-2000, 2000, "sum of numbers");
  int juryAns = ans.readInt();

  if (participantAns == juryAns) {
    quitf(_ok, "Correct");
  } else {
    quitf(_wa, "Expected = %d, found = %d", jans, pans);
  }
*/
}

/* 
  Streams:
    inf: input file
    out: participant output file
    ans: jury output file

  Verdicts:
    _ok: Accepted
    _wa: Incorrect output
    _pe: Presentation error
    _pc(score): give partial scoring
    _fail: critical error (jury/problemsetter fault)
  
  Methods:
    readXXX: read + type (Int, Long, Double, Token)
    quitf(verdict, message_with_format): quit checker with formatted msg
    quitif(condition, verdict, message_with_format): quit checker with formatter message
    ensuref(condition, message_with_format): assert
*/