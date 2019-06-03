/*
    Date 05/17/2019
    Brenda E Ramirez.
*/

/*
  Statement:  http://acm.timus.ru/problem.aspx?space=1&num=2018
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
    state: how many ways finishing on d(1 or 2) that has length k
    f(k, d) = [
                sum(i = k - a, k - 1, f(i, 2) if d == 1    k - a >= 0
                sum(i = k - b, k - 1, f(i, 1) if d == 2    k - b >= 0
              ]
*/

void solve(){
  int n, a, b; cin >> n >> a >> b;

  auto dp = vector<vector<ll>>(3, vector<ll>(n + 1));

  dp[1][0] = 1;
  dp[2][0] = 1;

  for(auto i = 1; i <= n; ++i) {
    for(int j = i - 1; j >= i - a and j >= 0; --j) {
      dp[1][i] += dp[2][j];
      dp[1][i] %= lmodulo;
    }

    for(int j = i - 1;j >= i - b and j >= 0; --j) {
      dp[2][i] += dp[1][j];
      dp[2][i] %= lmodulo;
    }
  }

  ll ret = dp[1][n] + dp[2][n];
  ret %= lmodulo;
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


