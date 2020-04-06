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
vector<ll> gcds(100001, 0);
vector<vector<int> > v(100001);
vector<ll> val(100001, 0);
void dfs(ll s, ll par,ll gcd){
    gcds[s] = __gcd(val[s], gcd);
    trav(child, v[s]){
        if(child != par)
            dfs(child, s, gcds[s]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x,y;
    cin >> n;
    F0R(i, n){
        cin >> val[i+1];
    }
    F0R(i, n-1){
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1, -1, 0);
    ll s = -val[0];
    F0R(i, n){
        cout << i << " " << gcds[i+1] << endl;
    }
    trav(x, gcds){
        s += x;
        if(s>MOD)
            s -= MOD;
    }
    trav(x, val){
        s += x;
        if(s>MOD)
            s -= MOD;
    }
    cout << s;
    return 0;
}
