#include<bits/stdc++.h>
using namespace std;
int min(int x,int y){
    if(x==-1)
        return y;
    else
        return x>y?y:x;
}
int deter(int x,int y,int a,int b){
    if(a>x && b>y)return 0;
    if(a>x && b<y)return 1;
    if(a<x && b<y)return 2;
    else return 3;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int x,y;
    scanf("%d %d",&x,&y);
    vector< pair<int ,int> > obs;
    int cross[4],top=-1,bottom=-1,right=-1,left=-1;
    memset(cross,-1,sizeof(cross));
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(abs(x-a)==abs(y-b)){
            cross[deter(x,y,a,b)] = min(cross[deter(x,y,a,b)] , abs(x-a)-1);
        }
        if(x==a){
            if(b>y)
                right = min(right,abs(b-y)-1);
            else
                left = min(left,abs(b-y)-1);
        }
        if(y==b){
            if(a>x)
                top = min(top,abs(x-a)-1);
            else
                bottom = min(bottom,abs(x-a)-1);
        }
        //obs.push_back(make_pair(a,b));
    }
    int ans=0;
    int c = 0;
    if(top!=-1)
        ans+=top;
    else
        ans+=abs(x-n);

    if(left!=-1)
        ans+=left;
    else
        ans+=abs(y-1);

    if(right!=-1)
        ans+=right;
    else
        ans+=abs(y-n);

    if(bottom!=-1)
        ans+=bottom;
    else
        ans+=abs(x-1);

    for(int i=0;i<4;i++){
        if(cross[i]!=-1)
            ans+=cross[i];
        else{
            if(i==0)
                ans+=min(abs(x-n),abs(y-n));
            if(i==1)
                ans+=min(abs(x-n),abs(y-1));
            if(i==2)
                ans+=min(abs(x-1),abs(y-1));
            if(i==3)
                ans+=min(abs(x-1),abs(y-n));
        }
    }
    printf("%d\n",ans);
    return 0;
}
