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
#define iceil(n, x) (((n) + (x) - 1) / (x))
#define pv(v) trav(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) trav(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) trav(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if((c-1)%d!=0 && (a-c)%d!=0 && abs(c-b)%d!=0)cout<<"-1"<<endl;
        else{
            if(abs(c-b)%d==0){
                cout<<abs(c-b)/d<<endl;
                continue;
            }
            ll x = ((c-1)%d==0?((ll)(iceil(b-1,d))):1000000000000);
            ll y = ((a-c)%d==0?((ll)(iceil(a-b,d))):1000000000000);
            // cout<<x<<" "<<y;
            cout<<min(x + (ll)((c-1)/d), y+(ll)((a-c)/d))<<endl;
        }
    }
    return 0;
}