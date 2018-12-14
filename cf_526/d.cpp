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
vector<vector<pl> > v(100005);
ll gaso[100005];
bool visi[100005];
ll opti_gaso[100005];
void dfs(ll s,ll cur){
    if(visi[s])
        return;
    cur+=gaso[s];
    visi[s] = 1;
    if(cur>opti_gaso[s]){
        opti_gaso[s] = cur;
    }
    else{
        cur = opti_gaso[s];
    }
    trav(x,v[s]){
        dfs(x.F,cur-x.S);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll s=-1;
    memset(visi,0,sizeof(visi));
    F0R(i,n)cin>>gaso[i+1];
    F0R(i,n)opti_gaso[i+1]=gaso[i+1];
    F0R(i,n-1){
        ll a,b,c;
        cin>>a>>b>>c;
        if(s==-1)
            s=a;
        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
    }
    dfs(1,0);
    cout<<*max_element(opti_gaso+1,opti_gaso+n+1);
    return 0;
}