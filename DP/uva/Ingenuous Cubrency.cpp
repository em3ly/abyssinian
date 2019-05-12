/*
    Date 05/12/2019
    Brenda E Ramirez.
*/

/*
    Statement:
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=2078
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

const int precision = 16;
const int modulo =  1000000007; // 10^9 + 7
const ll lmodulo =  1000000007; // 10^9 + 7

const double EPS = 1e-9;

void solve() {
    
    int n = 22;
    int m = 10000;

    auto cube = [](int number)->int {
        return number * number * number;
    };

    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    dp[0][0] = 1;

    for(auto i = 1; i < n; ++i) {
        for(auto j = 0;  j < m; ++j) {
            dp[i][j] = dp[i - 1][j];
            auto c = cube(i);
            if(j >= c) {
                dp[i][j] += dp[i][j - c];
            }
        }
    }

    int amount;
    while(cin >> amount) {
        cout << dp[n - 1][amount]<<endl;
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
