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
    map<int,int> ma;
    bool isf[1000005];
    bool isb[1000005];
    memset(isf,0,sizeof(isf));
    memset(isb,0,sizeof(isb));
    F0R(i,n){
        int x,y;
        cin>>x>>y;
        ma[x] = y;
        isf[x] = isb[y] = 1;
    }
    int fr;
    F0R(i,1000003){
        if(isf[i] && !isb[i]){
            fr = i;
            break;
        }
    }
    int ar[n];
    ar[1] = ma[0];
    int i = 1;
    int start = 0;
    while(i<n){
        ar[i] = ma[start];
        start = ma[start];
        i+=2;
    }
    ar[0] = fr;
    start = fr;
    i = 2;
    while(i<n){
        ar[i] = ma[start];
        start = ma[start];
        i+=2;
    }
    pv(ar);
    return 0;
}