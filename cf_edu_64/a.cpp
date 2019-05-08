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
  vi ar(n);
  int te = 0;
  REP(i,n){
      cin>>ar[i];
      if(i>0)   if(ar[i]>1 && ar[i-1]>1)    te=1;
  }
  if(te)    cout<<"Infinite";
  else{
      int ans = 0;
      FOR(i,1,n){
          ans += (abs(ar[i]-ar[i-1]) == 1)?3:4;
      }
      cout<<"Finite"<<endl<<ans;
  }
  return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}