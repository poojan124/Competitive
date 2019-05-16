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
int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int arr[] = {4,8,15,16,23,42};
    map<int,int> m;
    F0R(i,6){
        m[arr[i]] = 0;
    }
    
    int a,b,c,d;
    int ans[6];
    cout << "? 1 2" << endl;
    fflush(stdout);
    cin >> a;
    cout << "? 1 3" << endl;
    fflush(stdout);
    cin >> b;
    cout << "? 1 4" << endl;
    fflush(stdout);
    cin >> c;
    cout << "? 1 5" << endl;
    fflush(stdout);
    cin >> d;
    cout << a << " " << b << " " << c << " " << d << endl;
    int a1 = gcd(a,b);
    int a2 = gcd(a,c);
    int a3 = gcd(a,d);
    cout << a1 << " " << a2 << " " << a3 << endl;  
    ans[0] = gcd(a1 , gcd(a2,a3));
    cout << ans[0] << endl;
    ans[1] = a/ans[0];
    ans[2] = b/ans[0];
    ans[3] = c/ans[0];
    ans[4] = d/ans[0];
    F0R(i,5){
        m[ans[i]] = 1;
    }
    F0R(i,6){
        if(m[arr[i]] == 0){
            ans[5] = arr[i];
        }
    }
    cout << "! "; 
    pv(ans);
    return 0;
}
