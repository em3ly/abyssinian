/*
    Date 05/11/2019
    Brenda E Ramirez.
*/

/*
Problem statement:
 https://community.topcoder.com/tc?module=ProblemDetail&rd=4493&pm=1259 
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
    i state is the longest sequence that ends at i;
    fmax[i] = max   {
                        1,
                        fmin[j] + 1 : for all j < i a[j] < a[i]
                    } 
    fmin[i] = max   {
                        1,
                        fmax[j] + 1 : for all j < i a[j] > a[i]
                    }
*/

class ZigZag{
private:
public:
    int longestZigZag(vector<int> a) {
        int n = a.size();
        auto dpMax = vector<int> (n, 1);
        auto dpMin = vector<int> (n, 1);

        for(auto i = 0; i < n; ++i) {
            for(auto  j = 0; j < i; ++j) {
                if(a[i] == a[j]) continue;
                if(a[i] > a[j]){
                    dpMax[i] = max(dpMax[i], dpMin[j] + 1);    
                } else {
                    dpMin[i] = max(dpMin[i], dpMax[j] + 1);
                }
            }
        }
        return max(dpMax[n - 1], dpMin[n - 1]);
    }
};


// void solve() {

//     auto data = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
//     ZigZag zz;

//     cout << zz.longestZigZag(data) <<endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cout.precision(precision);
//     cout.setf(ios_base::fixed);
//     solve();
//     return 0;
// }
