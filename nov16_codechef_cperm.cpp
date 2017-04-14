#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod 1000000007
using namespace std;
int gcd(int a,int b){
    if(b==0)
        return 1;
    else
        return gcd(b,a%b);
}
ll int modulo(ll int a,ll int b,ll int n){
    ll int x=1,y=a;
    while(b > 0){
        if(b%2 == 1)
            x=(x*y)%n;
        y = (y*y)%n;
        b /= 2;
    }
    return x%n;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"0"<<endl;
            continue;
        }
        cout<<(modulo(2,n-1,mod)-2)%mod<<endl;
    }
    return 0;
}
