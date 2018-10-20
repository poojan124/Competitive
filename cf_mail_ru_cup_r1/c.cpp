#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    int sum[n+1];
    memset(sum,0,sizeof(sum));
    int max_=-1;
    for(int i=0;i<n;i++){
        sum[i] = a[i]+b[i];
        max_ = max(sum[i],max_);
    }
    int flag = 1;
    for(int i=0;i<n;i++){
        int t1=0;
        for(int j=0;j<=i-1;j++){
            if(sum[j]<sum[i])
                t1++;
        }
        if(t1!=a[i])
            flag = 0;
        t1 = 0;
        for(int j=i+1;j<n;j++){
            if(sum[j]<sum[i])
                t1++;
        }
        if(t1!=b[i])
            flag = 0;
        // if(!flag)
        //     cout<<"--> "<<i<<endl;
        if(!flag)
            break;
    }
    if(flag){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            cout<<max_+1-sum[i]<<" ";
    }
    else
        cout<<"NO"<<endl;
    return 0;
}