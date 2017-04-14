#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n+1],b[m+1];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    sort(a,a+n,cmp);
    sort(b,b+m,cmp);
    int cmp_cnt=0,adpt_cnt=0;
    int v[m+1];
    int adt[m+1];
    int soc[n+1];
    memset(v,0,sizeof(v));
    memset(v,0,sizeof(adt));
    memset(v,0,sizeof(soc));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[j]<a[i]){
                cout<<"break Here"<<endl;
                break;
            }
            if(!v[j]){
                if(b[j]==a[i]){
                    cmp_cnt++;
                    soc[i]=j+1;
                    v[j]=1;
                    break;
                }
                else{
                    cmp_cnt++;
                    adpt_cnt++;
                    int temp=b[j],f=0,i_cntr=0;
                    while(temp>a[i]){
                        temp/=2;
                        if(temp%2==1)
                            temp++;
                        i_cntr++;
                        if(temp==a[i]){
                            f=1;
                            break;
                        }
                    }
                    if(f==1){
                        cout<<i_cntr<<endl;
                        adt[j]=i_cntr;
                        soc[i]=j+1;
                        v[j]=1;
                        break;
                    }
                }
            }
        }
    }
    printf("%d %d\n",cmp_cnt,adpt_cnt);
    for(int i=0;i<m;i++)
        printf("%d ",adt[i]);
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%d ",soc[i]);
    printf("\n");
    return 0;
}
