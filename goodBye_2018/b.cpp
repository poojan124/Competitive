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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x,y;
    cin>>n;
    vector<pl> v,ans;
    F0R(i,n){
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    F0R(i,n){
        cin>>x>>y;
        trav(xx,v){
            ll tx = xx.F + x;
            ll ty = xx.S + y;
            ans.pb(mp(tx,ty));
        }
    }
    sort(all(ans));
    int cnt = 1;
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i].F==ans[i+1].F && ans[i].S==ans[i+1].S){
            cnt++;
        }
        else{
            if(cnt==n){
                cout<<ans[i-1].F<<" "<<ans[i-1].S;
                return 0;
            }
            cnt = 1;
        }
    }
    cout<<ans[n-1].F<<" "<<ans[n-1].S;
    return 0;
}