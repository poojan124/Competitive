#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
ll int gcd(ll int a,ll int b){
    if(!b)
        return a;
    else
        return gcd(b,a%b);
}
ll int lcm(ll int a,ll int b){
    return a*b/gcd(a,b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        ll int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<ll int> v;
        ll int ans1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j])
                    ans1=a[i];
                else if(a[i]%a[j]==0){
                    ans1=a[i];
                }
                else if(a[j]%a[i]==0){
                    ans1=a[j];
                }
                else{
                    ans1=lcm(a[i],a[j]);
                }
                v.pb(ans1);
            }
        }
        sort(v.begin(),v.end());
        cout<<v[0]<<endl;
    }
    return 0;
}
