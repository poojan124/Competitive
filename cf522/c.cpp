#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define EACH(x,v) for (auto &x : v)
ll gcd(ll a, ll b) {
      if (a == 0) return b;
      return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
ll modPos(ll a, ll mod=MOD){
    if (a >= 0) return a%mod;
    return (a%mod+mod)%mod;
}
ll modpow(ll a,ll b,ll m = MOD){
    ll res = 1;
    a = a%m;
    while(b>0){
        if(b%2)
            res = (res*a) % m;
        b = b>>1;
        a = (a*a)%m;
    }
    return res;
}
int dp[5][100000+5];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<5;i++)
        dp[i][0] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<5;j++){
            if(a[i]==a[i-1] && dp[j][i-1]){
                for(int c=0;c<5;c++)
                    if(c!=j)
                        dp[c][i] = 1;
            }
            if(a[i]>a[i-1] && dp[j][i-1]){
                for(int c=j+1;c<5;c++)
                    dp[c][i] = 1;
                break;
            }
            if(a[i]<a[i-1] && dp[j][i-1]){
                for(int c=j-1;c>=0;c--)
                    dp[c][i] = 1;
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int x=-1;    
    for(int i=0;i<5;i++)
        if(dp[i][n-1])x=i;
    vector<int> v;
    if(x!=-1){
        v.pb(x);
        for(int i=n-2;i>=0;i--){
            if(a[i]==a[i+1]){
                for(int j=0;j<5;j++){
                    if(dp[j][i] && j!=x){
                        x=j;
                        break;
                    }
                }
            }
            if(a[i]>a[i+1]){
                for(int j=x+1;j<5;j++){
                    if(dp[j][i]){
                        x=j;
                        break;
                    }
                }
            }
            if(a[i]<a[i+1]){
                for(int j=x-1;j>=0;j--){
                    if(dp[j][i]){
                        x=j;
                        break;
                    }
                }
            }
            v.pb(x);
        }
        reverse(all(v));
        for(auto i:v)
            cout<<i+1<<" ";
    }
    else
        cout<<"-1";
    return 0;
}