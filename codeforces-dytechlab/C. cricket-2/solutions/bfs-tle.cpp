#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define ll long long
#define pii pair <ll, ll>
#define ld long double
#define XX first
#define YY second
#define mattype ll
#define matrix vector <vector <mattype> >

// constants:
const int mn = 200005;
const int mod = 1000000007;
const long long inf = 4444444444444444444;
const int sminf = 1111111111;
const bool is_multitest = 1;
const bool is_interactive = 0;

// i/o methods:
const bool input_from_file = 0;
const bool output_to_file = 0;
#define filename ""
#define in_extension "inp"
#define out_extension "out"

// debug functions
void debug_vector(string name, vector <ll> v) {
  cerr << name << " @size=" << v.size() << ": [";
  for (int x: v) cerr << x << " ";
  cerr << "]\n";
}

void debug_2d_vector(string name, vector <vector<ll> > v) {

  cerr << name << " @size=" << v.size() << ": {\n";
  for (int i = 0; i < v.size(); i++) {
    cerr << "\t";
    debug_vector(name + "[" + to_string(i) + "]", v[i]);
  }
  cerr << "}\n";
}

// data preprocessing: (e.g.: divisor generating, prime sieve)
void preprocess()
{
  
}

// global variables:
int n;
int passed[15][15][15][15][15][15];
bool is_positions_passed(vector <pii> pts, int test_number) {
  return passed[pts[0].XX][pts[0].YY][pts[1].XX][pts[1].YY][pts[2].XX][pts[2].YY] == test_number;
}

void pass_positions(vector <pii> pts, int test_number) {
  passed[pts[0].XX][pts[0].YY][pts[1].XX][pts[1].YY][pts[2].XX][pts[2].YY] = test_number;
}

bool in_range(pii p) {
  return (p.XX > 0 && p.XX <= n && p.YY > 0 && p.YY <= n);
}

bool shared_pt(pii u, pii v) {
  return u != v && abs(u.XX - v.XX) <= 1 && abs(u.YY - v.YY) <= 1;
}

pii skipCell(pii u, pii v) {
  return {2 * v.XX - u.XX, 2 * v.YY - u.YY};
}

// main solution goes here:
void execute(int test_number)
{
  cin >> n;
  vector <pii> pts(3, {0, 0});
  for (int i = 0; i < 3; i++) cin >> pts[i].XX >> pts[i].YY;
  pii target;
  cin >> target.XX >> target.YY;
  deque <vector <pii> > q = {pts};
  while (!q.empty()) {
    vector <pii> positions = q.front();
    q.pop_front();

    for (int i = 0; i < 3; i++) if (target == positions[i]) {
      cout << "YES\n";
      return;
    }

    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 3; j++) {
        if (!shared_pt(positions[i], positions[j])) continue;

        pii temp = positions[i];
        positions[i] = skipCell(positions[i], positions[j]);
        if (in_range(positions[i]) && !is_positions_passed(positions, test_number)) {
          pass_positions(positions, test_number);
          q.push_back(positions);
        }
        positions[i] = temp;

        temp = positions[j];
        positions[j] = skipCell(positions[j], positions[i]);
        if (in_range(positions[j]) && !is_positions_passed(positions, test_number)) {
          pass_positions(positions, test_number);
          q.push_back(positions);
        }
        positions[j] = temp;
      }
    }
  }
  cout << "NO\n";
}
// REMEMBER TO CHOOSE TEST METHODS
// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Solution by low_



















signed main()
{
#ifdef lowie
    if (!is_interactive)
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
#else
    if (input_from_file) freopen(filename"."in_extension, "r", stdin);
    if (output_to_file) freopen(filename"."out_extension, "w", stdout);
#endif
    if (!is_interactive)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    preprocess();
    int ntest;
    if (is_multitest) cin >> ntest;
    else ntest = 1;

    for (int testno = 1; testno <= ntest; testno++)
    // use for instead of while to serve facebook hacker cup test format
    {
        execute(testno); // only start coding in this function, not in main
    }
}
// Template by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/
