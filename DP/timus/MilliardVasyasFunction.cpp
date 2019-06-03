/*
    Date 05/17/2019
    Brenda E Ramirez.
*/

/*
  Statement:  http://acm.timus.ru/problem.aspx?space=1&num=1353
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


map<vector<int>, int> memo;


ll getSum(int ind, int curS, string accLimit, bool isSmaller, int n) {
  if(memo.count({ind, curS, isSmaller})) return memo[{ind, curS, isSmaller}];

  if(ind > n) {
    if(curS == 0) {
      memo[{ind, curS, isSmaller}] = 1;
      return 1;
    }
    return 0;
  }

  ll acc = 0;

  int digit = 9;
  int accDigit = accLimit[ind] - '0';

  if (!isSmaller) {
    digit = accDigit;
  }

  for(auto i = 0; i <= digit; ++i) {
    if(curS - i < 0) break;
    bool curIsSmaller = isSmaller ? true : i < accDigit; 
    acc += getSum(ind + 1, curS - i, accLimit, curIsSmaller, n);
  }
  memo[{ind, curS, isSmaller}] = acc;
  return acc;
}

void solve() {
  int s; cin >> s;

  string accLimit = "1000000000";
  int n = 10;

  int acc = getSum(0, s, accLimit, false, n - 1);

  cout << acc ;
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


