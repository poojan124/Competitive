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
    int x[] = {6,10,14,15,21,22,26,33,34};
    int N = 9;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n<31){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            bool ok = false;
            for(int i=0;i<N-2;i++){
                for(int j=i+1;j<N-1;j++){
                    for(int k=j+1;k<N;k++){
                        int xx = n - x[i] - x[j] - x[k];
                        if(xx != x[i] && xx != x[j] && xx != x[k]){
                            cout << x[i] << " " << x[j] << " " << x[k] << " " << xx << endl;
                            ok = true;
                            break;
                        }
                    }
                    if(ok) break;
                }
                if(ok) break;
            }
        }
    }
    return 0;
}