/*
    Date 05/11/2019
    Brenda E Ramirez.
*/

/*
Problem statement:
    https://community.topcoder.com/tc?module=ProblemDetail&rd=5009&pm=2402
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


/*
    recurrence : 
    state i : max donations up to i
    n : neighbors amount
    f[i] = max {
                    f[i - 1] : 1 <= i < n
                    f[i - 2] + donations[i]  : 2 <= i < n
                    donations[i] : 0 <= i < 2 
                }
    N -  1 state does not include donations[0] so, it could be 
    calculated in the same way than f.
*/

class BadNeighbors {
private:
    int maxDonationsV1(vector<int> & donations) {
        auto dp = vector<int> (donations.size(), 0);
        for(auto i = 1; i < (int)donations.size(); ++i) {
            int curDonation = donations[i - 1];
            dp[i] = dp[i - 1];
            int i2 = i - 2 >= 0 ? dp[i - 2] : 0;
            dp[i] = max(dp[i], i2 + curDonation);
        }

        int ret = dp[dp.size() - 1];

        dp = vector<int> (donations.size(), 0);

        for(auto i = 1; i < (int)donations.size(); ++i) {
            int curDonation = donations[i];
            dp[i] = dp[i - 1];
            int i2 = i - 2 >= 0 ? dp[i - 2] : 0;
            dp[i] = max(dp[i], i2 + curDonation);
        }        

        ret = max(ret, dp[dp.size() - 1]);
        return ret;
    }

    int maxDonationsV2(vector<int> & donations) {
        auto dp = vector<int>(3, 0);
        auto dpn = vector<int>(3, 0);

        for(auto i = 1; i < (int)donations.size(); ++i) {
            dp[i % 3] = dp[(i - 1 + 3) % 3];
            int curDonation = donations[i - 1];
            dp[i % 3] = max(dp[i % 3], dp[(i - 2 + 3) % 3] + curDonation);

            curDonation = donations[i];
            dpn[i % 3] = dpn[(i - 1 + 3) % 3];
            dpn[i % 3] = max(dpn[i % 3], dpn[(i - 2 + 3) % 3] + curDonation);
        }

        int lastInd = donations.size() - 1;
        return max(dp[lastInd % 3], dpn[(lastInd) % 3]);
    }

public:
    int maxDonations(vector<int> donations) {
        return maxDonationsV2(donations);
    }

};

void solve() {
    BadNeighbors bn;

    vector<int> data;
    //data = { 10, 3, 2, 5, 7, 8 };
    //data = {11, 15};
    //data = { 7, 7, 7, 7, 7, 7, 7 };
    //data = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    data = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };

    cout << bn.maxDonations(data);
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
