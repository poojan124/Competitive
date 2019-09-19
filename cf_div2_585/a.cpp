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
    int a1,a2,k1,k2,n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int mn = a1*(k1-1) + a2*(k2-1);
    cout << (n-mn>0?(n-mn):0) << " ";
    int mx1 = 0;
    int a11 = a1, a22=a2, k11=k1, k22=k2, nn=n;
    while(a1>0 && n-k1>=0){
        n-=k1;
        mx1++;
        a1--;
    }
    while(a2>0 && n-k2>=0){
        n-=k2;
        mx1++;
        a2--;
    }
    int mx2 = 0;
    while(a22>0 && nn-k22>=0){
        nn-=k22;
        mx2++;
        a22--;
    }
    while(a11>0 && nn-k11>=0){
        nn-=k11;
        mx2++;
        a11--;
    }
    cout << max(mx1, mx2);
    return 0;
}
