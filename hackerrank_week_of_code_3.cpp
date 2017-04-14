#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll int gcd(ll int a,ll int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
        ll int a,b,k,ans1=0,ans2=0;
        scanf("%lld %lld %lld",&a,&b,&k);
        ll int t1=max(a,b);
        ll int t2=min(a,b);
        if(k==0){
            printf("0\n");
            continue;
        }
        if(k<t2){
            printf("2\n");
            continue;
        }
        if(k%t1==0){
            printf("%lld\n",k/t1);
            continue;
        }
        //cout<<t2<<" "<<t1<<endl;
        //cout<<gcd(t2,t1)<<endl;
        if(k%gcd(t2,t1)==0){
            ll int j=0,i;
            while(1){

                i=(k-(t2*j))/t1;
                //cout<<"j : "<<j<<"i : "<<i<<endl;
                if(i*t1==(k-(t2*j))){
                    ans1=i+j;
                    break;
                }
                j++;
            }
        }
        ll int s=k/t1;
        ans2=s+2;
        //printf("%lld %lld\n",ans1,ans2);
        printf("%lld\n",min(ans1,ans2));
    }
}
