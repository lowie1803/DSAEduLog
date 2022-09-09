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
ll POW2[mn];
void preprocess()
{
  POW2[0] = 1;
  for (int i = 1; i < mn; i++) POW2[i] = POW2[i - 1] * 2 % mod;
}

// global variables:
ll POW(ll u, ll v) {
  if (v == 0) return 1;
  ll mid = POW(u, v / 2);
  mid = (mid * mid) % mod;
  return (v & 1) ? (mid * u % mod) : mid;
}

int n;

int last_ant_survive(string str) {
  str[0] = 'R';
  str[n - 1] = 'L';
  vector <int> wei(n, 1);
  vector <int> ind(n);
  for (int i = 0; i < n; i++) ind[i] = i + 1;
  while (str.size() > 1) {
    // cerr << str << "\n";
    for (int i = 0; i < str.size() - 1; i++) if (str[i] == 'R' && str[i + 1] == 'L') {
      if (wei[i] > wei[i+1]) {
        wei[i] += wei[i + 1];
        str.erase(str.begin() + i + 1);
        ind.erase(ind.begin() + i + 1);
        wei.erase(wei.begin() + i + 1);
      } else {
        wei[i+1] += wei[i];
        str.erase(str.begin() + i);
        ind.erase(ind.begin() + i);
        wei.erase(wei.begin() + i);
      }
    }

    str[0] = 'R';
    str[str.size() - 1] = 'L';
  }
  return ind[0];
}

string conv_int_to_binLR(int u) {
  string ans = "";
  for (int i = 0; i < n; i++) {
    ans += (u % 2 == 0 ? 'L' : 'R');
    u/=2; 
  }
  return ans;
}

// main solution goes here:
void execute(int test_number)
{
  cin >> n;
  vector <int> ans(n + 1);
  for (int i = 0; i < POW2[n]; i++) {
    int last_ant = last_ant_survive(conv_int_to_binLR(i));
    ans[last_ant] ++;
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] * POW(POW2[n], mod - 2) % mod << "\n";
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
