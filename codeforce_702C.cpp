#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n+1],b[m+1];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    int t,r=INT_MIN,j=0,temp=-1;
    for(int i=0;i<n;i++){
        if(i!=0)
            if(a[i]==a[i-1])
                continue;
        t=INT_MAX;
        if(j!=m-1){
            while(b[j]<a[i]){
                if(abs(b[j]-a[i])<t){
                    temp=j;
                    t=abs(b[j]-a[i]);
                }
                j++;
                if(j==m-1)
                    break;
            }
        }
        if(abs(b[j]-a[i])<t){
            temp=j;
            t=abs(b[j]-a[i]);
        }
        r=max(r,t);
        j=temp;
        //cout<<j<<" bug1"<<t<<" "<<r<<endl;
    }
    cout<<r<<endl;
}
