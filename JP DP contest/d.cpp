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

ll dp[2][100005];

ll solve(ll n, ll W, ll *w, ll *v){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=W;j++){
            if(w[i] > j)
                dp[i%2][j] = dp[(i+1)%2][j];
            else
                dp[i%2][j] = max(dp[(i+1)%2][j - w[i]] + v[i], dp[(i+1)%2][j]);
        }
    }
    return dp[(n-1)%2][W];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,W;
    cin >> n >> W;
    ll v[n],w[n];
    memset(dp,0,sizeof(dp));
    F0R(i, n)
        cin >> w[i] >> v[i];  
    cout << solve(n, W, w, v);
    return 0;
}