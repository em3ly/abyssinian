/*
    Date 05/16/2019
    Brenda E Ramirez.
*/

/*
  Statement: http://acm.timus.ru/problem.aspx?space=1&num=1119
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
  int n, m; cin >> n >> m;
  int k; cin >> k;

  set<pair<int, int>> diag;
  while(k--) {
    int a, b;
    cin >> a >> b;
    diag.insert({a, b});
  }


  vector<vector<double>> dp(m + 1, vector<double>(n + 1, INT_MAX));

  dp[0][0] = 0;

  for(int r = 0; r <= m; ++r) {
    for(auto c = 0; c <= n; ++c) {

      if((r - 1) >= 0) {
        dp[r][c] = dp[r - 1][c] + 100.0;
      }

      if((c - 1) >= 0) {
        dp[r][c] = min(dp[r][c], dp[r][c - 1] + 100.0);
      }

      if((r - 1) >= 0 and (c - 1) >= 0 and diag.count({c, r})) {
        dp[r][c] = min(dp[r][c], dp[r - 1][c - 1] + 141.421356237);
      }

    }
  }

  int ret = round(dp[m][n]);

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


