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
    cin>>n;
    int a[n];
    F0R(i,n)
        cin>>a[i];
    int s1 = 0,s2 = 0;
    vector<int> v1;
    int xx = 1;
    F0R(i,n){
        v1.pb(xx);
        xx = xx<<1;
    }
    vector<int> v2;
    F0R(i,1<<n)
        v2.pb(i);
    trav(x,v2){
        s1 = 0;
        s2 = 0;
        F0R(i,v1.size()){
            if(x&v1[i])
                s1 += a[i];
            else
                s2 += a[i];
        }
        if(abs(s1-s2) == 0 || abs(s1-s2)%360==0){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}