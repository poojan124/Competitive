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
    int n;
    cin >> n;
    int a = n;
    int b = n+1;
    if(a%2) swap(a,b);
    a /= 2;
    if(a%2){
        cout << "NO";
    }
    else{
        cout << "YES\n";
        a /= 2;
        if(n == b){
            cout << 1 + 2*(a - 1) << endl;
            cout << b << " ";
            for(int i = 1; i <= a-1 ; i++){
                cout << i << " " << b - i << " ";
            }
            cout << "\n" << n - (1 + 2*(a-1)) << endl;
            for(int i = a; i <= n-a; i++){
                cout << i << " ";
            }
        }
        else{
            cout << 2*a << endl;
            for(int i = 1; i <= a ; i++){
                cout << i << " " << b - i << " ";
            }
            cout << "\n" << n - 2*a << endl;
            for(int i = a+1; i <= n-a; i++){
                cout << i << " ";
            }
        }
    }
    return 0;
}