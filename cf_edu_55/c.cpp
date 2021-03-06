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
    vector<ll> smax(100005);
    int max_size = 0;
    trav(x,v){
        int i=0;
        ll csum = 0 ;
        trav(xx,x){
            csum+=xx;
            if(csum>0)
                smax[i] += csum;
            else
                break;
            i++;
        }
    }
    if(smax.empty()){
        cout<<0<<endl;
        return 0;
    }
    ll best = 0;
    cout<<*max_element(all(smax))<<endl;
    return 0;
}