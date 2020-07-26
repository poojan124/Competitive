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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    F0R(i, n)
        cin >> a[i];
    ll ans = 0 ;
    int bc[22];
    memset(bc, 0, sizeof(bc));
    for(auto x : a){
        ll tmp = x;
        int i = 0;
        while(tmp){
            bc[i] += tmp&1;
            tmp >>= 1;
            i++;
        }
    }
    while(1){
        ll n = 0;
        for(int i=0;i<22;i++){
            if(bc[i] > 0){
                bc[i]--;
                n |= (1 << i);
            }
        }
        if(n==0){
            break;
        }
        ans += (n*n);
    }
    cout << ans;
    return 0;
}