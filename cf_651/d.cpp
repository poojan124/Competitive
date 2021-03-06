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
int max_m(map<int,int> m, int k){
    int cnt = 0;
    for(auto x : m){
        cnt += x.S;
        if(cnt >= k)
            return x.F;
    }
    return -1;
}

// vector<pair<int,int> > foo(vector<int> v){
//     for(int i=1;i<=n-1;i++){
//         for()
//     }
// }

bool check(int *a, int n, int k, int x, bool what){
    int ans = 0;
    for(int i=0;i<n;i++){
        if(what){
            ans++;
            what = 1 - what;
        }
        else{
            if(a[i] <= x){
                ans++;
                what = 1 - what;
            }
        }
    }
    return ans >= k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n, k;
    cin >> n >> k;
    int a[n];
    F0R(i,n) cin >> a[i];
    int l = 1, r=1e9;
    while(l<r){
        int mid = (r + l)/2;
        if(check(a,n,k,mid,false) || check(a,n,k,mid,true)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}