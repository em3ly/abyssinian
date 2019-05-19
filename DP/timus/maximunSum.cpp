/*
    Date 05/13/2019
    Brenda E Ramirez.
*/

/*
  Statement:  http://acm.timus.ru/problem.aspx?space=1&num=1146
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


vector<int> kadanes1D(vector<int> & data) {
  int l = 0, r = 0;
  int curSum = data[0];
  int gMax = curSum;
  int gL = 0, gR = 0;
  for(auto i = 1; i < (int)data.size(); ++i) {
    auto v = data[i];
    if((curSum + v) >= v) {
      curSum += v;
      r++;
    } else {
      curSum = v;
      l = r = i;
    }

    if(curSum > gMax) {
      gMax = curSum;
      gL = l;
      gR = r;
    }
  }

  return {gMax, gL, gR};
}


void solve() {
  int n; cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  if(n == 0) {
    cout << 0;
    return;
  }

  for(auto &it : matrix) {
    for(auto &v : it) {
      cin >> v;
    }
  }

  vector<int> kadaneRows(n);
  int maxSum = matrix[0][0];
  int tx, ty, bx, by;

  for(auto l = 0; l < n; ++l) {
    fill(kadaneRows.begin(), kadaneRows.end(), 0);
    for(auto r = l; r < n; ++r) {

      for(auto k = 0; k < n; ++k) {
        kadaneRows[k] += matrix[r][k];
      }

      auto k1d = kadanes1D(kadaneRows);
      auto curSum = k1d[0];
      auto top = k1d[1];
      auto bottom = k1d[2];

      if(curSum > maxSum) {
        maxSum = curSum;
        tx = l;
        ty = top;
        bx = r;
        by = bottom;
      }
    }
  }
   // cout << imie(tx) << imie(ty) << imie(bx) << imie(by)<<endl;
  cout << maxSum;
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


