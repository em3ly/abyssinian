/*
    Date 05/12/2019
    Brenda E Ramirez.
*/

/*
    Statement:
    http://acm.timus.ru/problem.aspx?space=1&num=1225
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
    int n; cin >> n;

    vector<vector<ll>> dp(3, vector<ll>(n + 1));
    dp[0][0] = 0; // blue
    dp[1][0] = 1; //red
    dp[2][0] = 1; // white

    for(auto i = 1; i <= n; ++i) {
        dp[0][i] = dp[1][i - 1] + dp[2][i - 1];
        dp[1][i] = dp[2][i - 1] + dp[0][i - 1] / 2;
        dp[2][i] = dp[1][i - 1] + dp[0][i - 1] / 2;
    }

    cout << dp[0][n];
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
