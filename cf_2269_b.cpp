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

int digi_sum(int x){
    int sum = 0;
    while(x>0){
        int digi = x%10;
        sum += digi*digi;
        digi /= 10;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>> t;
    F0R(i, t){
        int n;
        cin >> n;
        vector<int> v;
        unordered_map<int, vector<int>> mv;
        F0R(j, n){
            int ele;
            cin >> ele;
            v.pb(ele);
            unordered_map<int, bool> seen;
            int day = 1;
            while(seen.count(ele) < 1){
                seen[ele] = true;
                mv[day].push_back(ele);
                ele = digi_sum(ele);
                day += 1;
            }
        }

    }
    return 0;
}