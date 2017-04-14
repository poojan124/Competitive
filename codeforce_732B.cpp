#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int ans=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-1;i++){
        if(a[i]+a[i+1]<k){
            ans+=(k-a[i]-a[i+1]);
            a[i+1]=k-a[i];
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
