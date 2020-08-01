#include<bits/stdc++.h>
using namespace std;    
typedef long long ll;
typedef long double ld;
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

/**
 When there is nothing there is lonliness.
 **/

ll solve(ll n, ll W, vector<ll> &w, vector<ll> &v){
    ll dp[2][1000*n + 1];
    F0R(i,1000*n + 1){
        dp[0][i] = W+1;
        dp[1][i] = W+1;
    }
    dp[0][0] = 0;
    dp[1][0] = 0;
    for(int j=0;j<n;j++){
        for(int i=0;i<=1000*n;i++){
            if(v[j] <= i){
                dp[j%2][i] = min(dp[(j+1)%2][i], dp[(j+1)%2][i - v[j]] + w[j]);
            }
            else{
                dp[j%2][i] = dp[(j+1)%2][i];
            }
        }
    }
    ll ret=0;
    for(int i=0;i<=1000*n;i++){
        if(dp[(n-1)%2][i] <= W)
            ret = i;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,W;
    cin >> n >> W;
    vector<ll> w(n);
    vector<ll> v(n);
    F0R(i, n) cin >> w[i] >> v[i];
    cout << solve(n,W,w,v);
    return 0;
}