#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll int gcd(ll int a,ll int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll int lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
int main()
{
    int n,m;
    cin>>n>>m;
    ll a[n+1],b[m+1];
    ll lc,gc;
    scanf("%lld",&a[0]);
    lc=a[0];
    for(int i=1;i<n;i++){
        scanf("%lld",&a[i]);
        lc=lcm(lc,a[i]);
    }
    scanf("%lld",&b[0]);
    gc=b[0];
    for(int i=1;i<m;i++){
        scanf("%lld",&b[i]);
        gc=gcd(gc,b[i]);
    }
    ll t=gc/lc;
    ll cnt=0,j=1,tlc=lc;
    if(t==0){
        cout<<"0"<<endl;
        return 0;
    }

    else{
        while(tlc<=gc){
            if(gc%tlc==0)
                cnt++;
            j++;
            tlc=lc*j;
        }
    }
    cout<<cnt<<endl;
}
