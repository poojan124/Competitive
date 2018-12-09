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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll a[n],c[n];
    F0R(i,n)
        cin>>a[i];
    F0R(i,n)
        cin>>c[i];
    ll dp[n][3];
    F0R(i,n){
        dp[i][0] = c[i];
        dp[i][1] = dp[i][2] = -1;
    }
    if(a[1]>a[0])
        dp[1][1] = dp[0][0]+c[1];
    FOR(i,2,n){
        FOR(x,1,3){
            ll min_ = -1;
            FOR(j,0,i){
                if(dp[j][x-1]==-1 || a[j]>=a[i])
                    continue;
                if(min_==-1)
                    min_ = dp[j][x-1];
                min_ = min(dp[j][x-1],min_);
            }
            if(min_!=-1)
                dp[i][x] = min_+c[i];
        }
    }
    ll ans = -1;
    F0R(i,n){
        if(dp[i][2]==-1)
            continue;
        if(ans==-1)
            ans = dp[i][2];
        ans = min(ans,dp[i][2]);
    }
    cout<<ans;
    return 0;
}