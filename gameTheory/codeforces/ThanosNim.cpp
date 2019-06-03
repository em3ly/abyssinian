/*
    Date 05/22/2019
    Brenda E Ramirez.
*/

/*
  Statement:  https://codeforces.com/contest/1147/problem/C
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
  vector<int> v(n);

  int minVal = INT_MAX;
  int minCnt = 0;

  for(auto &it : v) {
    cin >> it;
    if(it == minVal) {
      minCnt++;
    } else if(it < minVal) {
      minVal = it;
      minCnt = 1;
    }
  }

  if(minCnt <= (n / 2)) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
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


