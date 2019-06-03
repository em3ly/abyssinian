/*
    Date 05/22/2019
    Brenda E Ramirez.
*/

/*
  Statement:  https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/a-game-of-stones
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


void solve() {
  int t; cin >> t;
  vector<int> stones = {2, 3, 5};

  vector<bool> dp(101, 0);

  for(auto i = 1; i < (int)dp.size(); ++i) {
    for(auto s : stones) {
      if(i - s >= 0 and dp[i - s] == 0) {
        dp[i] = 1;
        break;
      }
    }
  }

  while(t--) {
    int n; cin >> n;
    if(dp[n]) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
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

