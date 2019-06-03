/*
    Date 05/22/2019
    Brenda E Ramirez.
*/

/*
  Statement:  https://www.hackerrank.com/challenges/nim-game-1/problem
  See from editorial: http://www.suhendry.net/blog/?p=1586
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
  int g; cin >> g;
  while(g--) {
    int n; cin >> n;
    int retXor = 0;
    while(n--) {
      int tmp; cin >> tmp;
      retXor ^= tmp;
    }

    if(!retXor) {
      cout << "Second" << endl;
    } else {
      cout << "First" << endl;
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


