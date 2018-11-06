#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define m (ll)998244353
ll pre[200000+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre[0] = 1;
    for(int i=1;i<=200000;i++)
        pre[i] = (pre[i-1]*2)%m;
    int a,b;
    cin>>a>>b;
    string s1,s2;
    cin>>s1>>s2;
    int sum[b+1];
    sum[0] = s2[0]-48;
    for(int i=1;i<b;i++)
        sum[i] = sum[i-1]+(s2[i]-48);
    ll ans=0;
    if(a>b){
        for(int i = (a-b);i<a;i++)
            if(s1[i]-48)ans = (ans + ((ll)sum[i-(a-b)]*pre[a-i-1])%m)%m;
    }
    else{
        for(int i=0;i<a;i++)
            if(s1[i]-48)ans = (ans + ((ll)sum[i+(b-a)]*pre[a-i-1])%m)%m;
    }
    cout<<ans%m<<endl;
    return 0;
}