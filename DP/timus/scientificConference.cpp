/*
    Date 05/13/2019
    Brenda E Ramirez.
*/

/*
  Statement:  http://acm.timus.ru/problem.aspx?space=1&num=1203
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
  int n; cin >> n;

  vector<vector<int>> intervals(n, vector<int>(2, 0));
  int maxTime = 0;
  for(auto &it : intervals) {
    cin >> it[1] >> it[0]; // [end, begin]
    maxTime = max(maxTime, it[0]);
  }

  sort(intervals.begin(), intervals.end());

  vector<int> dp(maxTime + 2, 0);
  int maxConferences = 0;
  int t = 1;
  for(auto & it : intervals) {

    int start = it[1];
    int end = it[0]; 
    while(t <= end) {
      dp[t] = dp[t - 1];
      t++;
    }

    dp[end] = max(dp[end], dp[start - 1] + 1);
    maxConferences = max(maxConferences, dp[end]);
  }
  cout << maxConferences;
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