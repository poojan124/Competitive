#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long int a[3],b[3],c[3];
        scanf("%lld %lld %lld",&a[0],&a[1],&a[2]);
        scanf("%lld %lld %lld",&b[0],&b[1],&b[2]);
        scanf("%lld %lld %lld",&c[0],&c[1],&c[2]);
        long long int ans[6]={0};
        long long int j=0,max_ans=0;
        ans[0]=a[0]+a[1]+a[2];
        ans[1]=b[0]+b[1]+b[2];
        ans[2]=c[0]+c[1]+c[2];
        ans[3]=a[0]+b[0]+c[0];
        ans[4]=a[1]+b[1]+c[1];
        ans[5]=a[2]+b[2]+c[2];
        for(int i=0;i<6;i++)
        {
            max_ans=max(max_ans,ans[i]);
        }
        if(max_ans%2==0&&max_ans!=0)
            max_ans--;
        printf("%lld\n",max_ans);
    }
}
