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
    ll n,k,m;
    cin>>n>>k>>m;
    vector<ll> a(n);
    F0R(i,n){
        cin>>a[i];
    }
    sort(all(a));
    ll sum = 0;
    if(m>n){
        sum += (m-n);
        m=n;
    }
    trav(x,a)
        sum+=x;
    double best = 0.0;
    while(m){
        best = max(best, ( sum+min((ll)k * (ll)a.size(),m) )/ (double)a.size() );
        m--;
        sum -= a[0];
        a.erase(a.begin());
    }
    cout<<setprecision(15);
    cout<<best;
    return 0;
}