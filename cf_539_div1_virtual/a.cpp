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
ll solve(vector<ll> v){
    ll p[(int)v.size()];
    p[0] = v[0];
    FOR(i,1,v.size()) p[i] = p[i-1]^v[i];
    ll ans =0;
    map<ll,ll> m;
    F0R(i,(int)v.size()){
        ans += m[p[i]] + (p[i]==0);
        m[p[i]]++; 
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll a[n], ans=0;
    F0R(i,n) cin >> a[i];
    if(n==2){
        cout << ((a[0] ^ a[1]) == 0);
        return 0;
    }
    vector<ll> v1,v2;
    F0R(i,n/2) 
        v1.pb(a[2*i]^a[2*i+1]);
    FOR(i,1,(int)((n-1)/2)+1) 
        v2.pb(a[2*i]^a[2*i-1]);
    cout << solve(v1) + solve(v2);
    return 0;
}

