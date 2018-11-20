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
ll primeFactors(ll n)
{
    if(n%2 == 0)
		return 2;
	for (ll i = 3; i <= sqrt(n); i = i+2)
		if(n%i==0)
            return i;
    return n;
}
int main(){
    ll n;
    cin>>n;
    ll p = primeFactors(n);
    if(n==p)
        cout<<1;
    else{
        ll ans = 0;
        if(p!=2){
            ans++;
            n = n-p;
        }
        cout<<ans+(n/2);
    }

    return 0;
}

