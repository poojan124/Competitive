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

    ifstream infile("b.inp1.txt");
    ofstream opfile("b.op1.txt");
    int t;
    infile >> t;
    FOR(T,1,t+1){
        int n;
        infile >> n;
        int c1 = 0, c2 = 0;
        char x;
        F0R(i,n){
            infile >> x;
            (x=='A'?c1:c2)++;
        }
        opfile << "Case #" << T << ": "; 
        if(abs(c1-c2) > 1){
            opfile << "N" << endl;
        }
        else{
            opfile <<"Y" << endl;
        }
    }
    return 0;
}
