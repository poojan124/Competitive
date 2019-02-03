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
void insertionSort(vector<ll> & arr) { 
    int i = arr.size()-1;
    int key, j; 
    key = arr[i]; 
    j = i-1; 
    while (j >= 0 && arr[j] < key) { 
        arr[j+1] = arr[j]; 
        j = j-1; 
    } 
    arr[j+1] = key;
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    ll a[n];
    string s;
    F0R(i,n)
        cin>>a[i];
    cin>>s;
    vector<ll> cur;
    char prev = '!';
    ll ans = 0;
    F0R(i,n){
        if(s[i] != prev){
            sort(all(cur),[](ll a,ll b){return a>b;});
            F0R(j,min(k,(int)cur.size())){
                ans += cur[j];
            }
            cur.clear();
            cur.pb(a[i]);
            prev = s[i];
        }
        else{
            cur.pb(a[i]);
        }
    }
    sort(all(cur),[](ll a,ll b){return a>b;});
    F0R(j,min(k,(int)cur.size())){
        ans += cur[j];
    }
    cout<<ans;
    return 0;   
}