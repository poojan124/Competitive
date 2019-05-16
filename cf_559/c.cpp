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
    vector<int> a(n);
    vector<int> b(m);
    map<int,int> m1,m2;
    ll sum = 0;
    int minb = 0, ming  = INT_MAX;
    F0R(i,n){
        cin >> a[i];
        m1[a[i]] += m;
        minb = max(a[i], minb);
    }
    int mm = 0;
    F0R(i,m){
        cin >> b[i];
        ming = min(ming, b[i]);
        if(m1[b[i]] > 0){
            sum += b[i];
            m1[b[i]]--;
        }
        else{
            sum += b[i];
            mm++;
        }
    }
    
    if(minb>ming){
        cout << -1;
        return 0;
    }
    //cout << "asdf "<< sum;
    trav(x,m1){
        if( x.S%m == 0 && x.S>0){
            sum += x.F*(x.S/m);
            m1[x.F] -= (x.S/m);
        }
    }
    //pm(m1);
    
    //cout << sum <<" saf" <<endl;
    sort(a.begin(), a.end(), [](int a,int b){return a>b;});
    int i = 0;
    //pv(a);
    while(mm > 0 && i<n){
        if(m1[a[i]] <= 0){
            i++;
            continue;
        }
        if(mm > m1[a[i]]){
            mm -= m1[a[i]];
            m1[a[i]] = 0;
        }
        else{
            m1[a[i]] -= mm;
            break;
        }
        i++;
    }
    trav(x,m1){
        sum += x.F*x.S;
    }
    cout << sum;
    return 0;
}
