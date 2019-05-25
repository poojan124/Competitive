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
    int n, ans = 1,x;
    cin >> n;
    vector<int> dig;
    while(n>0){
        x = n%10;
        dig.pb(x);
        n/=10;
        ans *= x;
    }
    
    for(int i=0;i<dig.size()-1;){
        int tans = 1;
        //cout << "i = "<< dig[i] << endl; 
        if(dig[i]==9){
            FOR(I,0,((int)dig.size())){
                if(I==((int)dig.size())-1 && dig[I]==0){
                    continue;
                }
                tans *= dig[I];
            }
            ans = max(ans, tans);
            i++;
            continue;
        }
        dig[i] = 9;
        bool carry = true;
        int j = i+1;
        while(carry &&  j<((int)dig.size())){
            if(dig[j]!=0){
                dig[j]--;
                carry = false;
                break;
            }
            else{
                dig[j]=9;
            }
            j++;
        }
        FOR(I,0,((int)dig.size())){
            if(I==((int)dig.size())-1 && dig[I]==0){
                continue;
            }
            tans *= dig[I];
        }
        ans = max(ans, tans);
        i = j;
        //dig[j]++;
    }
    cout << ans;
    return 0;
}
/*
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dig;
    while(n>0){
        int x;
        x = n%10;
        dig.pb(x);
        n/=10;
    }
    bool cary = false;
    int ans=1;
    F0R(i,(int)dig.size()){
        if(dig[i]==0){
            cary = true;
            ans *= 9;
        }
        else{
            if(i==(int)dig.size()-1 && dig[i]!=1){
                if(carry)
                    ans *= (dig[i]-1);
                else
                    ans *= (dig[i]);
            }
            else{
                if(carry){
                    if(dig[i]==1)
                }
                else{
                    ans *= dig[i];
                }
            }
        }
    }
    return 0;
}
*/
