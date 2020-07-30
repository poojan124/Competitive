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
vector<int> v[100005];
bool visi[100005];
int dp[100005];
int dfs(int s){
    if(visi[s])
        return dp[s];
    visi[s] = 1;
    int ini = 0;
    for(auto x : v[s]){
        ini = max(ini, dfs(x) + 1);
    }
    dp[s] = ini;
    return ini;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int x,y;
    F0R(i,m){
        cin >> x >> y;
        v[x].pb(y);
    }
    memset(visi, 0, sizeof(visi));
    memset(dp, 0, sizeof(dp)); 
    FOR(i, 1, n+1){
        if(!visi[i])
            int dump = dfs(i);
    }
    int ans = 0;
    FOR(i, 1, n+1){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}