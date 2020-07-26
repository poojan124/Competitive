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
  int t;
  cin>>t;
  while(t--){
      int n, m;
      cin>>n>>m;
      int a[n][m];
      F0R(i, n){
        F0R(j, m){
            cin>>a[i][j];
        }
      }
    bool ok = true;
    if(a[0][0] > 2)
        ok = false;
    if(a[0][m-1] > 2)
        ok = false;
    if(a[n-1][0] > 2)
        ok = false;
    if(a[n-1][m-1] > 2)
        ok = false;
    FOR(i, 1, m-1)
        if(a[0][i] > 3) ok = false;
    FOR(i, 1, n-1)
        if(a[i][0] > 3) ok = false;
    FOR(i, 1, m-1)
        if(a[n-1][i] > 3) ok = false;
    FOR(i, 1, n-1)
        if(a[i][m-1] > 3) ok = false;
    FOR(i, 1, n-1)
        FOR(j, 1, m-1)
            if(a[i][j] > 4)
                ok = false;   
    if(!ok)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        F0R(i, n){
            int st=3;
            if(i==0 || i==n-1)
                st=2;
            F0R(j, m){
                if(j==0 || j==m-1)
                    cout<<st<<" ";
                else
                    cout<<st+1<<" ";
            }
            cout<<endl;
        }
    }
  }
  return 0;
}