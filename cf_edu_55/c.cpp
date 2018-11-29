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
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<vector<ll>> v(100005);
    F0R(i,n){
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
    }
    FOR(i,1,k+1){
        if(v[i].size()>1)
            sort(all(v[i]),cmp);
    }
    vector<vector<ll>> smax(k+1);
    int max_size = 0;
    FOR(i,1,k+1){
        int nn = v[i].size();
        max_size = max(max_size,nn);
        if(nn==0)
            continue;
        if(v[i][0]<0)
            continue;
        smax[i].pb(v[i][0]);
        if(nn>1){
            FOR(j,1,nn){
                if(smax[i][j-1]+v[i][j]<0)
                    break;
                smax[i].pb(smax[i][j-1]+v[i][j]);
            }
        }
    }
    if(smax.empty()){
        cout<<0<<endl;
        return 0;
    }
    ll best = 0;
    F0R(i,max_size){
        ll ans = 0;
        trav(x,smax){
            if(x.size()>i)
                ans+=x[i];
        }
        best=max(best,ans);
    }
    cout<<best<<endl;
    return 0;
}