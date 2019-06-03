/*
    Date 05/24/2019
    Brenda E Ramirez.
*/

/*
  Statement:  https://codeforces.com/problemset/problem/1156/E
  rmq: https://mayanknatani.wordpress.com/2013/07/15/range-minimum-query/
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


class RMQ {
private:
  int n;
  int logn;
  int blockLen;
  vector<vector<int>> val, ind;

  void init(vector<int> & arr) {
    int n = arr.size();
    logn = getPowInd(n);
    val = vector<vector<int>> (logn + 1, vector<int>(n));
    ind = vector<vector<int>> (logn + 1, vector<int>(n, 0));

    val[0] = arr;
    iota(ind[0].begin(), ind[0].end(), 0);

    for(int p = 1, l = 1; p < n; p <<= 1, ++l) {
      for(auto s = 0; s < n; ++s) {
        val[l][s] = val[l - 1][s];
        ind[l][s] = ind[l - 1][s];

        if(s + p < n and val[l - 1][s] < val[l - 1][s + p]) {
          val[l][s] = val[l- 1][s + p];
          ind[l][s] = ind[l - 1][s + p];
        }
      }
    }
  }

  int getPowInd(int d) {
    int ind = 0;
    while((1 << ind) <= d) {
      ind ++;
    }
    return ind;
  }

public:
  RMQ(vector<int> & arr) {
    this->n = arr.size();
    blockLen = (int) sqrt(n + .0) + 1;

    init(arr);
  }

  pair<int, int> getMax(int l, int r) {
    r++;
    int d = r - l;
    int p = getPowInd(d / 2);

    if(l == r or val[p][l] > val[p][r - (1 << p)]) {
      return {val[p][l], ind[p][l]};
    } else {
      return {val[p][r - (1 << p)], ind[p][r - (1 << p)]};
    }
  }

};


int getSpecials(int l, int r, 
  RMQ & rmq, unordered_map<int, int> & inds, vector<int> & arr) {
  if(l >= r) return 0;

  auto m = rmq.getMax(l, r);
  auto maxv = m.first;
  auto maxInd = m.second;

  int cnt = 0;

  int start = maxInd + 1;
  int end = r;
  if(abs(l - maxInd) < abs(r - maxInd)) {
    start = l;
    end = maxInd - 1;
  }
  for(int i = start; i <= end; ++i) {
    int dif = maxv - arr[i];
    if(inds.count(dif)) {
      int limR = inds[dif];
      int limL = i;
      if(limR < limL ) swap(limR, limL);
      if(limL >= l and limL <= maxInd and 
        limR <= r and limR >= maxInd) {
          cnt++;
      }

    }
  } 

  cnt += getSpecials(l, maxInd - 1, rmq, inds, arr);
  cnt += getSpecials(maxInd + 1, r, rmq, inds, arr);
  return cnt;
}

void solve() {
  int n; cin >> n;
  vector<int> arr(n);
  unordered_map<int, int> inds;
  for(auto i = 0; i < n; ++i) {
    cin >> arr[i];
    inds[arr[i]] = i;
  } 

  RMQ rmq(arr);
  int ret = getSpecials(0, n - 1, rmq, inds, arr);
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


