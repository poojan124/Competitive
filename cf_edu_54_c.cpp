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
    int t;
    cin>>t;
    while(t--){
        double d;
        cin>>d;
        if(pow(d,2)-4*d>=0){
            double root1 = (d-sqrt(pow(d,2)-4*d))/2;
            double root2 = (d+sqrt(pow(d,2)-4*d))/2;
            cout<<setprecision(12)<<"Y "<<root2<<" "<<root1<<endl;
        }
        else{
            cout<<"N"<<endl;
        }
    }
    return 0;
}
