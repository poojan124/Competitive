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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a[105];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    int max = 0;
    for(int i=0;i<105;i++){
        if(a[i]>max)
            max =a[i];
    }
    int ans = 0;
    if(max>k){
        if(max%k!=0)
            max += (k-max%k) ;
    }
    else{
        max = k;
    }
    for(int i=0;i<105;i++)
        if(a[i]>0)
            ans+=(max-a[i]);
    cout<<ans<<endl;
    return 0;
}