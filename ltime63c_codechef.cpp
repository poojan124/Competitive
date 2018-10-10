#include<bits/stdc++.h>
using namespace std;
int* insert_(int *a,int n){
    int temp = a[n-1];
    int i = n-2;
    while(i>0 && a[i]>temp){
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = temp;
    return a;
}
int main(){
    int n,m,x;
    cin>>n>>m>>x;
    int a[n+1],b[m+1];
    int maxa,maxb,mina,minb;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+m);
    int pdiff = a[n-1]+b[m-1]-a[0]-b[0];
    int cdiff = a[n-1]+b[m-1]-a[0]-b[0];
    int flag=0;
    //cout<<a[n-1]<<" "<<b[m-1]<<" "<<a[0]<<" "<<b[0]<<endl;
    while(1){
        a[n-1]-=x;
        b[m-1]-=x;

        int temp = a[n-1];
        int i = n-2;
        while(i>=0 && a[i]>temp){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = temp;

        temp = b[m-1];
        i = m-2;
        while(i>=0 && b[i]>temp){
            b[i+1] = b[i];
            i--;
        }
        b[i+1] = temp;

        //cout<<a[n-1]<<" "<<b[m-1]<<" "<<a[0]<<" "<<b[0]<<endl;
        //cout<<pdiff<<" "<<cdiff<<endl;
        cdiff = a[n-1]+b[m-1]-a[0]-b[0];
        if(cdiff==0){
            cout<<cdiff<<endl;
            break;
        }
        //cout<<"dis"<<a[n-1]+b[m-1]-a[0]-b[0]-x*2<<endl;
        //if(a[n-1]+b[m-1]-a[0]-b[0]-x*2 == 0){
          //  cout<<cdiff<<endl;
            //break;
        //}
        if(cdiff > pdiff ){
            cout<<pdiff<<endl;
            break;
        }
        else
            pdiff=cdiff;
        if(cdiff == pdiff )
        flag++;
        if(flag>1000){
            cout<<cdiff<<endl;
            break;
        }
    }
    return 0;
}
