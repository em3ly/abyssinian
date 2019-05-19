/*
    Date 05/17/2019
    Brenda E Ramirez.
*/

/*
  Statement:  http://acm.timus.ru/problem.aspx?space=1&num=1009
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

/*
  rec: 
  f(d, i) = [
              sum{(di = 0, di = n), f(di, i - 1)} if(d != 0)
              sum{(di = 1, di = n), f(di, i - 1)} if(d = 0)
            ]
*/

void solve(){
  int n, base;
  cin >> n >> base;

  vector<vector<ll>> dp(n + 1, vector<ll>(base, 0));

  for(auto i = 0; i < base; ++i) {
    dp[1][i] = 1;
  }

  for(auto r = 2; r <= n; ++r) {
    for(auto c = 0; c < base; ++c) {
      dp[r][c] =  accumulate(dp[r - 1].begin(), dp[r - 1].end(), 0ll);
      if(c == 0) {
        dp[r][c] -= dp[r - 1][0];
      }
    }
  }

  auto ret = accumulate(dp[n].begin() + 1, dp[n].end(), 0ll);
  cout << ret;
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


