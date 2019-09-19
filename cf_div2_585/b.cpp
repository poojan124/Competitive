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
    int n;
    cin >> n;
    int a[n];
    F0R(i,n) cin >> a[i];
    vector<int> neg,diff;
    F0R(i,n) if(a[i]<0) neg.pb(i);
    ll odd = 0, even = 0;
    neg.pb(n);
    F0R(i,(int)neg.size()-1){
        diff.pb(neg[i+1] - neg[i]);
        if(i%2) even += diff.back();
        else odd += diff.back();
    }
    int ismod2 = 1;
    ll a1 = 0;
    int frnt = 0;
    F0R(i, n){
        a1 += (ismod2?odd:even);
        //cout << (ismod2?"odd ":"even ") << a1 << endl;
        if(a[i]<0){
            (ismod2?odd:even) -= diff[frnt++];
            ismod2 = 1 - ismod2;
        }
    }
    cout << a1 << " " << (((ll)n * (ll)(n+1)) /2) - a1 << endl;
    return 0;
}
