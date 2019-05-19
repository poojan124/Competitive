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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        F0R(i,n){
            cin >> a[i];
        }
        int d1 = a[1]-a[0];
        int d2 = a[2]-a[1];
        int d3 = a[3]-a[2];
        int d;
        if(d1 !=d2 && d2 !=d3 && d1 != d3){
            d = (a[3]-a[0])/3;
        }
        else{
            if(d1 == d2 || d1 == d3)
                d = d1;
            else
                d = d2;
        }
        int td;
        FOR(i,1,n){
            td = a[i]-a[i-1];
            if(td!=d){
                if(i==n-1){
                    a[n-1] = a[n-2]+d;
                }
                else{
                    if(a[i+1]-a[i] == d){
                        a[i-1] = a[i] - d;
                    }
                    else{
                        a[i] = a[i-1] + d;
                    }
                }
                break;
            }
        }
        pv(a);
    }
    
    return 0;
}
