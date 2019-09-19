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
#define SZ(a) (int)a.size()
#define pv(v) trav(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) trav(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) trav(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    map<ll,bool> m;
    F0R(i,n){
        cin >> a[i];
        m[a[i]] = true;
    }
    vector<vector<ll> > v(64);
    trav(x, a){
        FOR(i,0,63){
            ll p = pow(2, i);
            if( x % p == 0 && (x/p)%2==1){
                v[i].pb(x);
            }
        }
    }
    ll idx = 0;
    F0R(i,63)
        if(SZ(v[i]) > SZ(v[idx]))
            idx = i;
    cout << n - SZ(v[idx]) << endl;
    map<ll,bool> tp;
    trav(x, v[idx]) tp[x] = true;
    trav(x, m)
        if(!tp[x.F] && m[x.F])
            cout << x.F << endl;
    return 0;
}
