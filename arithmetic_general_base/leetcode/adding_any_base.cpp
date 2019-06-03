/*
    Date 06/02/2019
    Brenda E Ramirez.
*/

/*
Statement (not from any judge)
Add two b-base numbers. (nega_base or positive_base)
Input:  b
        n
        m
        n digits consisting the first number(most significant first)
        m digits consisting the first number(most significant first)

Output 
      v digits consisting the result(most significant first)
*/

/*
Property to consider:
  c = q * b + r if r > 0
  c = b(q + 1) + (r - b) r < 0  (adding +- b)
*/

#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>  
#include <numeric>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define endl '\n'
using ll = long long;

const int precision = 3;
const int modulo =  1000000007; // 10^9 + 7
const ll lmodulo =  1000000007; // 10^9 + 7

const double EPS = 1e-9;

vector<int> add(vector<int> & a, vector<int> & b, int base) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  vector<int> ret;
  int carry = 0;
  int len = max(a.size(), b.size());

  for(int i = 0; i < len or carry; ++i) {
    int acc = carry;
    if(i < (int)a.size()) acc += a[i];
    if(i < (int)b.size()) acc += b[i];

    int q = acc / base;
    int r = acc % base;

    if(r < 0) {
      r -= base;
      q++;
    }

    ret.push_back(r);
    carry = q;
  }

  while(ret.size() > 1 and ret[ret.size() - 1] == 0) ret.pop_back();
  reverse(ret.begin(), ret.end());
  return ret;
}

void solve() {
  int base; cin >> base;
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);

  for(auto & it : a) cin >> it;
  for(auto & it : b) cin >> it;

  vector<int> ret = add(a, b, base);
  
  for(auto & it: ret) {
    cout << it << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(precision);
  cout.setf(ios_base::fixed);
  solve();
  return 0;
}

