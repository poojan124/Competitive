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
bool div(int n){
    for(int i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            if( ( (i&1) && (i != 1) ) || (n/i)&1 )return true;
        }
    }
    return false;
}
bool check_odd_div(int n){
    int cnt = 0;
    while(n%2 == 0){
        n/=2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2){  
        while (n % i == 0)  {  
            cnt++; 
            n = n/i;  
        }  
    }  
    if(n>1)
        cnt++;
    return cnt>1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string p1 = "Ashishgup", p2 = "FastestFinger";
        if(n==1){
            cout << p2 << endl;
        }
        else if(n == 2){
            cout << p1 << endl;
        }
        else if((n%2 == 0) && ((n/2)%2 == 1)){
            cout << (check_odd_div(n)?p1:p2) << endl;
        }
        else{
            cout << (div(n)?p1:p2) << endl;
        }
    }
    return 0;
}