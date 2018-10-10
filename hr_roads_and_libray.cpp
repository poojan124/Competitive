#include<bits/stdc++.h>
using namespace std;
struct dis{
    int p;
    int d;
}ar[100005];
int find_(int x){
    if(ar[x].p!=x)
        ar[x].p=find_(ar[x].p);
    return ar[x].p;
}
void uni(int x,int y){
    int xR = find_(x);
    int yR = find_(y);
    if(ar[xR].d>ar[yR].d){
        ar[yR].p=xR;
    }
    else if(ar[xR].d<ar[yR].d){
        ar[xR].p=yR;
    }
    else{
        ar[yR].p=xR;
        ar[xR].d++;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        long long c_l,c_r;
        cin>>n>>m>>c_l>>c_r;
        int v[n+1]={0};
        for(int i=0;i<=n;i++){
            ar[i].p=i;
            ar[i].d=0;
        }
        if(c_l<c_r){
            for(int i=0;i<m;i++){
                long long x,y;
                cin>>x>>y;
            }
            cout<<c_l*n<<endl;
            continue;
        }
        else{
            long long int cost=0;
            for(int i=0;i<m;i++){
                long long x,y;
                cin>>x>>y;
                if(find_(x)!=find_(y))
                    uni(x,y);
            }
            for(int i=1;i<=n;i++){
                long long c=find_(i);
                if(v[c]==0 && v[i]==0){
                    cost+=c_l;
                    if(i!=c)
                        cost+=c_r;
                    v[c]=1;
                    v[i]=1;
                    //cout<<"here"<<c<<" "<<i<<endl;
                }
                else if(v[i]==0){
                    cost+=c_r;
                    v[i]=1;
                }
            }
            cout<<cost<<endl;
        }
    }
    return 0;
}
