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
const int M = 1e6+1;
ll isp(ll a,ll b){
    int x = sqrt(a);
    int y = sqrt(b);
    FOR(i,2,x+1){
        if(a%i==0)return 0;
    }
    FOR(i,2,y+1){
        if(b%i==0)return 0;
    }
    return 1;
}
ll mn,mc,nn,c1,c2;
unordered_map<ll,ll> dp1,dp2;
vector<ll> fac(ll n){
    vector<ll> v;
    ll bkpn = n;
    int ed = (int)sqrt(n)+1;
    if(n%2==0 && n>2){
        while(n%2==0)n/=2;
        v.pb(2);
    }
    FOR(i,3,ed){
        if(n%i==0){
            v.pb(i);
            while(n%i==0)n/=i;
        }
        i++;
    }
    if(n>1 && n!=bkpn)
        v.pb(n);
    return v;
}
void solve(ll n){
    if(n==1 || dp1.find(n)!=dp1.end()){
        return;
    }
    //cout<<"Call for "<<n<<endl;
    vector<ll> v = fac(n);
    dp1[n] = c1 + (n-1)*c2;
    dp2[n] = 1;
    //cout<<"----------------------------\n";
    //pv(v);
    //cout<<"----------------------------\n";
    bool f = 0;
    trav(x,v){
        //if(n==nn || 1)
        cout<<x<<" -------------------------------------- "<<n<<endl;
        ll ax  = x,ay = n/x;
        solve(ax);
        solve(ay);
        ll t = dp1[ax] + dp1[ay];
        ll tc = dp2[ax]*dp2[ay];
        if(dp1[n] == t){
        //    cout<<"here "<<n<<" "<<tc<<" "<<ax<<" "<<ay<<" "<<"\n";
            f = 1;
            dp2[n] += tc;
            //if(isp(ax,ay) && ax!=ay){
            //    dp2[n] += tc;
            //}
        }
        if(dp1[n]>t){
          //  cout<<"NEVERRRRRR "<<n<<" "<<tc<<" "<<ax<<" "<<ay<<" "<<"\n";
            dp1[n] = t;
            dp2[n] = tc;
            //if(isp(ax,ay) && ax!=ay){
            //    dp2[n] += tc;
            //}
        }
    }
    cout<<"For n : "<<n<<" "<<dp1[n]<<" "<<dp2[n]<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>nn>>c1>>c2;
    dp1[1] = 0;
    dp2[1] = 1;
    pv(fac(nn));
    solve(nn);
    cout<<dp1[nn]<<" "<<dp2[nn];
    return 0;
}
