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
ll n,k,a,b;
ll ans = 0;
vector<ll> v;

ll na(ll l,ll r){
    return upper_bound(all(v),r)-lower_bound(all(v),l);
}
ll solver(ll l,ll r){
    if(l>r)
        return 0;
    ll NA = na(l,r);
    if(NA==0)
        return a;
    if((r-l+1)%2==1)
        return b*NA*(r-l+1);
    else{
        ll mid = (r+l-1)/2;
        return min(solver(l,mid)+solver(mid+1,r) , b*NA*(r-l+1));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>a>>b;
    ll cnt=0;
    ll x;
    F0R(i,k){
        cin>>x;
        v.push_back(x);
    }
    sort(all(v));
    cout<<solver(1,pow(2,n));
    return 0;
}