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
int x[3], y[3];
int u, v;

pii centralSquare() {
  int a = (x[0] == x[1]) ? x[0] : x[2];
  int b = (y[0] == y[1]) ? y[0] : y[2];
  return {a, b};
}
// main solution goes here:
void execute(int test_number)
{
  cin>>n;
  for (int i=0; i<3; i++) cin>>x[i]>>y[i];
  cin>>u>>v;

  int cx = centralSquare().first, cy = centralSquare().second;

  if ((cx == 1 || cx == n) && (cy == 1 || cy == n)) { // "corner" case, literally
    // the crickets can only reach coordinates within the edges that already contains at least 2 crickets,
    // which contains the centralSquare of the L
    cout << ((u == cx || v == cy) ? "YES\n" : "NO\n");
  } else {
    if ((cx + cy) % 2 == (u + v) % 2) {
      cout << (cx % 2 == u % 2 ? "YES\n" : "NO\n"); 
    } else { // can be prove to always reach, since we have ways to align 2 crickets in the same diagonal as target
      cout << "YES\n"; 
    }
  }
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
