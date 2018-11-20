#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    if(a+b==0){
        cout<<0<<"\n"<<0<<"\n";
        return 0;
    }
    ll n = floor((sqrt(1+4*2*(a+b))-1)/2);
    bool v[n+5];
    //cout<<n<<endl;
    memset(v,0,sizeof(v));
    vector<ll> aa;
    vector<ll> bb;
    for(int i=n;i>=1;i--){
        if(a==0)
            break;
        if(a<=i){
            aa.push_back(a);
            v[a] = 1;
            a-=a;
        }
        else{
            aa.push_back(i);
            v[i] = 1;
            a-=i;
        }
    }
    for(int i=1;i<=n;i++)
        if(!v[i])bb.push_back(i);
    cout<<aa.size()<<endl;
    for(auto i:aa)
        cout<<i<<" ";
    cout<<endl;
    cout<<bb.size()<<endl;
    for(auto i:bb)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
