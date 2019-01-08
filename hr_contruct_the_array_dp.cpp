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

const int MOD = 1e9+7;
ll modpow(ll a,ll b,ll m = MOD){
    ll res = 1;
    a = a%m;
    while(b>0){
        if(b%2)res = (res*a) % m;
        b = b>>1;
        a = (a*a)%m;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x,k;
    cin>>n>>k>>x;
    int dp[n][2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    FOR(i,1,n-2){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = ((dp[i-1][0] + dp[i-1][1] )*(k-1) - dp[i][0]) % MOD;
    }
    if(x==1)
        cout<<(dp[n-3][0]*(k-1) % MOD + dp[n-3][1]*(k-2) % MOD) % MOD;
    else{
        ll fac = dp[n-3][1]*modpow(k-1,MOD-2);
        cout<< ((dp[n-3][0] + fac*(k-2)%MOD)*(k-2) %MOD + fac*(k-1) %MOD) % MOD;
    }
    return 0;
}
