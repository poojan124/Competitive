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
int a[50][50], b[50][50], aa[50][50], bb[50][50];
bool check(int n, int m){
    F0R(i, n)
        F0R(j, m)
            if(j>0)
                if(aa[i][j] <= aa[i][j-1])
                    return false;
    F0R(i, m)
        F0R(j, n)
            if(j>0)
                if(aa[j][i] <= aa[j-1][i])
                    return false;
    F0R(i, n)
        F0R(j, m)
            if(j>0)
                if(bb[i][j] <= bb[i][j-1])
                    return false;
    F0R(i, m)
        F0R(j, n)
            if(j>0)
                if(bb[j][i] <= bb[j-1][i])
                    return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    
    F0R(i, n){
        F0R(j, m){
            cin >> a[i][j];
        }
    }
    F0R(i, n){
        F0R(j, m){
            cin >> b[i][j];
        }
    }
    F0R(i, n){
        F0R(j, m){
            if(a[i][j] < b[i][j]){
                aa[i][j] = a[i][j];
                bb[i][j] = b[i][j];
            }
            else{
                aa[i][j] = b[i][j];
                bb[i][j] = a[i][j];
            }
        }
    }
    cout<< ((check(n,m))?"Possible" : "Impossible" );
    return 0;
}

