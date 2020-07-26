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

char goo(char c1, char c2){
    if(c1 == 'Y' && c1 == c2)
        return 'Y';
    return 'N';
}

int main(){

    ifstream in("a.inp1.txt");
    ofstream out("a.op1.txt");
    int t;
    in >> t;
    FOR(T,1,t+1){
        out << "Case #" << T << ": " << endl; 
        int n;
        in >> n;
        string s1,s2;
        in >> s1 >> s2;
        char ans[n][n];
        F0R(i,n)
            ans[i][i] = 'Y';
        
        FOR(i,1,n){
            ans[i][i-1] = goo(s1[i-1], s2[i]);
        }
        FOR(i,0,n-1){
            ans[i][i+1] = goo(s1[i+1], s2[i]);
        }
        for(int i=2;i<n;i++){
            for(int j=0;j<n-i;j++){
                ans[i+j][j] = goo(ans[i+j-1][j], ans[i+j][j+1]);
            }
            for(int j=i;j<n;j++){
                ans[j-i][j] = goo(ans[j-i+1][j], ans[j-i][j-1]);
            }
        }
        F0R(i,n){
           F0R(j,n){
                out << ans[i][j];
            }
            out << "\n";
        }
    }
   
    return 0;
}
