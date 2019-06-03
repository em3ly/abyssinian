/*
    Date 05/22/2019
    Brenda E Ramirez.
*/

/*
  Statement:  https://www.hackerrank.com/challenges/misere-nim-1/problem
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
  while(t--) {
    int n; cin >> n;
    int retXor = 0;
    bool atLeastOne = false;
    bool allOnes = true;
    while(n--) {
      int tmp; cin >> tmp;
      retXor ^= tmp;
      if(tmp > 1) atLeastOne = true;
      if(tmp != 1) allOnes = false;
    }

    if(atLeastOne and !retXor) {
      cout << "Second" <<endl;
    } else if(allOnes and retXor) {
      cout << "Second" <<endl;
    } else {
      cout << "First" <<endl;
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


