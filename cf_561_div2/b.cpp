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
    cin >> n;
    int row = -1;
    FOR(i, 5, (n/2)+1){
        if(n%i == 0 && (n/i)>=5){
            row = i;
            break;
        }
    }
    if(row==-1)
        cout << -1;
    else{
        int col = n/row;
        string s1 = "aeiou";
        string ans = "";
        map<int, char> m = {{0, 'a'}, {1, 'e'}, {2, 'i'}, {3, 'o'},{4,'u'}};
        F0R(i,5){
            ans += s1;
            rotate(s1.begin(), s1.begin()+1, s1.end());
            F0R(j,col-5){
                ans += m[i%5];
            }
        }
        FOR(i,5,row){
            ans += s1;
            F0R(j,col-5){
                ans += m[i%5];
            }
        }
        cout << ans;
    }
    
    
    return 0;
}
