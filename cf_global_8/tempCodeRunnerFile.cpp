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
    ll n; 
    cin >> n;
    ll p1=0,p2=0,x1,x2,min_=INT_MAX;
    for(ll x=1;x<=39;x++){
        ll tx1 = x;
        ll tx2 = x+1;
        for(ll i=0;i<=10;i++){
            for(ll j=10-i;j>=0;j--){
                int tot = (tx1 - 1)*i + (tx2 - 1)*j;
                if((pow(tx1, i) * pow(tx2, j) >= n) && min_ > tot){
                    min_ = tot;
                    p1 = i;
                    p2 = j;
                    x1 = tx1;
                    x2 = tx2;
                }
            }
        }
    }
    // cout << p1 << " " << p2 << " " << x1 << " " << x2 << endl;
    string s = "codeforces";
    string ans = "";
    for(auto c : s){
        if(p1){
            p1--;
            for(int i=0;i<x1;i++) ans += c;
        }
        else if(p2){
            p2--;
            for(int i=0;i<x2;i++) ans += c;
        }
        else{
            ans += c;
        }
    }
    cout << ans;
    return 0;
}