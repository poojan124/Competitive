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

ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

ll solve(ll a, ll b){
    return a/gcd(a, b);  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k,a,b;
    cin >> n >> k;
    cin >> a >> b;
    vector<ll> burger;
    F0R(i,n)
        burger.pb(1ll + (ll)i*k);
    ll source = 1+a;
    set<ll> l;
    trav(burg, burger){
        if(burg==1){
            l.insert(n*k + 1 - b - source);
            l.insert(1 + b + n*k - source);
            continue;
        }
        ll tp = burg-b;
        ll ttp = burg+b;
        if(tp==source){
            l.insert(k*n);
        }
        else{
            l.insert(tp-source);
        }
        if(ttp == source){
            l.insert(k*n);
        }
        else{
            l.insert(ttp-source);
        }
    }
    ll a1=LONG_LONG_MIN, a2 = LONG_LONG_MAX;
    trav(L, l){
        ll xxx = solve(n*k,L);
        a1 = max(xxx, a1);
        a2 = min(xxx, a2);
    }
    cout << a2 << " " << a1; 
    return 0;
}
