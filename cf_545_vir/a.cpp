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
    cin >> n >> m;
    int a[n][m];
    F0R(i,n)
        F0R(j,m)
            cin >> a[i][j];
    int lr[n][m], tb[n][m], lrm[n], tbm[m];
    F0R(i,n){
        map<int,int> M;
        F0R(j,m) M[a[i][j]] = 1;
        int index = 1;
        trav(ele, M) M[ele.F] = index++; // map element to index
        F0R(j,m) lr[i][j] = M[a[i][j]];
        lrm[i] = (int)M.size();
    }
    F0R(i,m){
        map<int,int> M;
        F0R(j,n) M[a[j][i]] = 1;
        int index = 1;
        trav(ele, M) M[ele.F] = index++; // map element to index
        F0R(j,n) tb[j][i] = M[a[j][i]];
        tbm[i] = (int)M.size();
    }
    /*
    F0R(i,n){
        F0R(j,m){
            cout << lr[i][j] << " ";
        }
        cout << "\n";
    }
    F0R(i,n){
        F0R(j,m){
            cout << tb[i][j] << " ";
        }
        cout << "\n";
    }*/
    F0R(i,n){
        F0R(j,m){
            if(lr[i][j] > tb[i][j]){
                int shift = lr[i][j] - tb[i][j];
                int LR = lrm[i];
                int TB = tbm[j]+shift;
                cout << max(LR, TB) << " ";
            }
            else{
                int shift = tb[i][j] - lr[i][j];
                int LR = lrm[i]+shift;
                int TB = tbm[j];
                cout << max(LR, TB) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
