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
    int n;
    cin>>n;
    int a[n+1];
    pi max_ =  mp(0,-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max_.F)
            max_ = mp(a[i],i);
    }
    assert(max_.S!=-1);
    int ans[n+1];
    bool flag= true;
    int x = 5;
    ans[max_.S]=5;
    for(int i=max_.S+1;i<n;i++){
        if(i==n-1){
            if(a[i]>a[i-1])
                x++;
            else if(a[i-1]==a[i-1])
                x = ((x==2)?3:2);
            else
                x--;
        }
        else{
            if(a[i-1]==a[i]){
                if(a[i]==a[i+1])
                    x = ((x==2)?3:2);
                else if(a[i+1]>a[i])
                    x = ((x==1)?2:1);
                else
                    x = ((x==5)?4:5);
            }
            else if(a[i]>a[i-1] && a[i]<=a[i+1])
                x++;
            else if(a[i]<a[i-1] && a[i]>=a[i+1])
                x--;
            else if(a[i]<a[i+1] && a[i]<a[i-1])
                x = min(1,--x);
            else if(a[i]>a[i+1] && a[i]>a[i-1])
                x = min(5,++x);
        }
        if(x>0 && x<=5)
            ans[i]=x;
        else{
            flag=false;
            break;
        }
    }
    x=5;
    for(int i=max_.S-1;i>=0;i--){
        if(i==0){
            if(a[i+1]>a[i])
                x--;
            else if(a[i+1]<a[i])
                x++;
            else
                x = ((x==2)?3:2);
        }
        else{
            if(a[i+1]==a[i]){
                if(a[i-1]==a[i])
                    x = ((x==2)?3:2);
                else if(a[i-1]>a[i])
                    x = ((x==1)?2:1);
                else
                    x = ((x==5)?4:5);
            }
            else if(a[i]>=a[i-1] && a[i]<a[i+1])
                x--;
            else if(a[i]<=a[i-1] && a[i]>a[i+1])
                x++;
            else if(a[i]<a[i+1] && a[i]<a[i-1]){
                x = min(1,--x);
            }
            else if(a[i]>a[i+1] && a[i]>a[i-1]){
                x = max(5,++x);
            }
                
        }
        if(x>0 && x<=5)
            ans[i]=x;
        else{
            flag=false;
            break;
        }
    }
    if(flag){
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
    }
    else{
        cout<<"-1"<<endl;
    }
    return 0;
}