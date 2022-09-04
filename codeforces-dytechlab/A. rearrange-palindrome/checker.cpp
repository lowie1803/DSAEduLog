#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

bool isPalindromic(const char* str, int l, int r) {
  for (int i = 0; i < (r - l + 1) / 2; i++) {
    if (str[l + i] != str[r - i]) return false;
  }
  return true;
}

bool hasEqualCharset(string a, string b) {
  string s = a, t = b;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return s == t;
}

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);

  int testCount = inf.readInt();
  for (int testNumber = 1; testNumber <= testCount; testNumber++) {
    setTestCase(testNumber);
    // for each test case, we will bruteforce to find longest palindromic substring, but knowing that the answer
    // will be at least |str| - 25. Hashing with n * log(n) is also possible, but takes time to implement
    string inputStr = inf.readToken();
    int n = inputStr.size();
    string patternCheck = "[a-z]{" + toString(n) + "}";

    string participantAns = ouf.readToken(patternCheck, "pAns");
    string juryAns = ans.readToken(patternCheck, "jAns");

    quitif(!hasEqualCharset(juryAns, inputStr), _fail, "Test %d jury answer is not permuting input.", testNumber);
    quitif(!hasEqualCharset(participantAns, inputStr), _wa, "Test %d output is not permuting input.", testNumber);

    int juryPalindromeLen = -1;
    for (int len = n; len > max(n - 30, 0); len--) {
      for (int leftInd = 0; leftInd + len <= n; leftInd++) {
        int rightInd = leftInd + len - 1;
        if (isPalindromic(juryAns.data(), leftInd, rightInd)) {
          juryPalindromeLen = len;
          break;
        }
      }
      if (juryPalindromeLen > 0) break;
    }

    if (juryPalindromeLen == -1) {
      quitf(_fail, "Test %d jury answer can be proved to be incorrect.", testNumber);
    }

    int participantPalindromeLen = -1;
    for (int len = n; len >= juryPalindromeLen; len--) {
      for (int leftInd = 0; leftInd + len <= n; leftInd++) {
        int rightInd = leftInd + len - 1;
        if (isPalindromic(participantAns.data(), leftInd, rightInd)) {
          participantPalindromeLen = len;
          break;
        }
      }
      if (participantPalindromeLen > 0) {
        if (participantPalindromeLen > juryPalindromeLen) {
          quitf(_fail, "Test %d jury answer is less optimal than participant. Jury %d, participant %d.", testNumber, juryPalindromeLen, len);
        } else {
          break;
        }
      }
    }
    if (participantPalindromeLen == -1) {
      quitf(_wa, "Test %d participant answer is not optimal. Jury %d, participant < %d.", testNumber, juryPalindromeLen, juryPalindromeLen);
    }
  }
  quitf(_ok, "Ok %d tests.", testCount);
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