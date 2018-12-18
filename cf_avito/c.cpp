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
const ll md = 998244353;

ll modpow(ll a,ll b,ll m){
    if(a==0)
        return 1;
    ll res = 1;
    a = a%m;
    while(b>0){
        if(b%2)
            res = (res*a) % m;
        b = b>>1;
        a = (a*a)%m;
    }
    return res%m;
}
ll ncr(ll n, ll r, ll p) { 
    if (r==0) 
        return 1; 
    ll fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p;
    return (((fac[n]* modpow(fac[r], p-2, p)) % p) * ((modpow(fac[n-r], p-2, p)) % p)) % p; 
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    if(m==1 && k>0){
        cout<<0;
        return 0;
    }
    ll nseg = ncr(n-1,k,md);
    cout<<(modpow(m-1,k,md)*m %md)*nseg % md<<endl;
    return 0;
}