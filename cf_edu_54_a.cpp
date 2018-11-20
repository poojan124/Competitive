#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll modpow(ll a,ll b,ll m){
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int idx = n-1;
    for(int i=0;i<n-1;i++){
        if(s[i+1]<s[i]){
            idx = i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=idx)
            cout<<s[i];
    }
    return 0;
}

