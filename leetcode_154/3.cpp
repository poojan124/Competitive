#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
#define PI 3.1415926535897932384626433832795
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define trav(x,v) for (auto &x : v)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define pv(v) trav(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) trav(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) trav(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

const int MOD = 1000000007;

class Solution {
public:
    ll maxSubArraySum(vector<int> a, int s) {
       ll max_so_far = 0, max_ending_here = 0;
       for (int i = 0; i < s; i++) {
           max_ending_here = max_ending_here + a[i];
           if (max_ending_here < 0) max_ending_here = 0;
           else if (max_so_far < max_ending_here) max_so_far = max_ending_here;
       }
       return max_so_far;
    }
    int kConcatenationMaxSum(vector<int>& a, int k) {
        ll sum = accumulate(a.begin(), a.end(), 0);
        if(sum <= 0){
            if(k>1){
                a.insert(a.end(), a.begin(), a.end());
                return maxSubArraySum(a, (int)a.size()) % MOD;
            }
            return maxSubArraySum(a, (int)a.size()) % MOD;
        }
        else{
            if(k>1){
                ll ans = ((k-1) * sum ) % MOD;
                ans += maxSubArraySum(a, (int)a.size()) % MOD;
                return ans;
            }
            return ((ll)k * sum ) % MOD;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s = Solution();
    vector<int> v = {-5,-2,0,0,3,9,-2,-5,4};
    cout << s.kConcatenationMaxSum(v, 5);
    return 0;
}
