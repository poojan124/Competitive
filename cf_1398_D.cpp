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

/*
    i am so dumb missed this fking simple case:
    1 1 2
    4
    4
    3 3

    Answer is fking 4*3 + 4*3. So greedy wont work you dumb fuck.
*/


bool cmp(int a, int b){
    return a > b;
}

int dp[201][201][201];
vector<int> R(201), G(201), B(201);
int r,g,b;
int foo(int i, int j, int k){
    if(dp[i][j][k] != -1){
        return dp[i][j][k];    
    }
    int check = (i>=r) + (j>=g) + (k>=b);
    if(check >= 2){
        dp[i][j][k] = 0;
    }
    else{
        if(check == 1){
            if(i >= r) dp[i][j][k] = (G[j] * B[k]) + foo(i, j+1, k+1);
            if(j >= g) dp[i][j][k] = (R[i] * B[k]) + foo(i+1, j, k+1);
            if(k >= b) dp[i][j][k] = (R[i] * G[j]) + foo(i+1, j+1, k);
        }
        else{
            int p=0, q=0, r=0;
            p = (G[j] * B[k]) + foo(i, j+1, k+1);
            q = (R[i] * B[k]) + foo(i+1, j, k+1);
            r = (R[i] * G[j]) + foo(i+1, j+1, k);
            dp[i][j][k] = max(p, max(q, r));
        }        
    }
    return dp[i][j][k];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> g >> b;
    F0R(i, r) cin >> R[i];
    F0R(i, g) cin >> G[i];
    F0R(i, b) cin >> B[i];
    sort(R.begin(), R.end(), cmp);
    sort(G.begin(), G.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    F0R(i, r+1)
        F0R(j, g+1)
            F0R(k, b+1)
                dp[i][j][k] = -1;
    cout << foo(0,0,0);
    return 0;
}