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
vector<vector<int> > v(6005);
int d ,maxd,ans=0,n;
int dp[6005], w[6005];
void dfs(int u,int p){
    int pos = lower_bound(dp,dp+n,w[u])-dp;
    int pval = dp[pos];
    ans = max(ans,pos);
    dp[pos] = w[u];
    trav(x,v[u]){
        if(x==p)continue;
        dfs(x,u);
    }
    dp[pos] = pval;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,y;
    cin>>n;
    FOR(i,0,n)
        cin>>w[i];
    F0R(i,n-1){
        cin>>x>>y;
        x--;y--;
        v[x].pb(y);
        v[y].pb(x);
    }
    FOR(i,0,n){
        if(v[i].size()!=1)continue;
        F0R(i,n)
            dp[i] = INT_MAX;
        dfs(i,-1);
    }
    cout<<ans+1;
    return 0;
}
/*
Each minute spend on reading and solving problem on paper
will save you 10 minute of debugging time.
*/