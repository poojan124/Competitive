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
    int n,m;
    cin>>n>>m;
    int a[n];
    F0R(i,n)cin>>a[i];
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        int min_ = INT_MAX;
        x--;
        FOR(i,x,y){
            FOR(j,i,y){
                int cur =0;
                FOR(xx,i,j+1){
                    if(a[xx]>(j-i+1))
                        cur += a[xx]*(j-i+1); 
                }
                if(cur>=z){
                    min_ = min(j-i+1,min_);
                    break; 
                }   
            }
        }
        cout<<min_<<endl;
    }
    return 0;
}