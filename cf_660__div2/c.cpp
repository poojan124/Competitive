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

ll p[100005], h[100005], sp[100005], n, m;
vector<ll> g[100005];
bool ok;

ll dfs1(ll s, ll par){
    sp[s] = p[s];
    for(auto child : g[s]){
        if(child != par){
            sp[s] += dfs1(child, s);
        }
    }
    return sp[s];
}

void dfs2(ll s, ll par, ll happy, ll sad){

    if(!ok)
        return;
    ll check = h[s] + sp[s];
    ll actual_happy = (h[s] + sp[s]) / 2;
    ll actual_sad = sp[s] - actual_happy;

    if(actual_happy < 0 || actual_sad < 0 || check%2 == 1){
        // cout << "here" << h[s] << " " << s << " " << sp[s] << endl;
        // cout << " 1 " << endl; 
        ok = false;
        return;
    }
    if(actual_happy > happy){
        ok = false;
        // cout << " 2 " << endl; 
        return;
    }
    if(p[s] > actual_sad){
        actual_sad = 0;
        actual_happy = sp[s] - p[s];
    }
    else{
        actual_sad -= p[s];
    }
    for(auto child : g[s]){
        if(child != par){
            dfs2(child, s, actual_happy, actual_sad);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(p, 0, sizeof(p)); 
    memset(h, 0, sizeof(h));

    int t;
    cin >> t;
    while(t--){
        ok = true;       
        memset(sp, 0, sizeof(sp));
        cin >> n >> m;
        F0R(i,n+1) g[i].clear();
        ll x,y;
        F0R(i, n) cin >> p[i+1];
        F0R(i, n) cin >> h[i+1];
        F0R(i,n-1){
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        ll dump = dfs1(1, -1);
        dfs2(1, -1, m, 0);
        cout << (ok?"YES":"NO") << endl;
    }
    return 0;
}