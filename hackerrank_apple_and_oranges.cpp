#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,t,a,b,d,m,n,cnt=0;
    cin>>s>>t;
    cin>>a>>b;
    cin>>n>>m;
    d=t-s;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp<0)
            continue;
        else{
            temp=temp+a;
            if(temp>=s &&temp<=t)
                cnt++;
        }
    }
    cout<<cnt<<endl;
    cnt=0;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        if(temp>0)
            continue;
        else{
            temp=temp+b;
            if(temp>=s&&temp<=t)
                cnt++;
        }
    }
    cout<<cnt;
}
