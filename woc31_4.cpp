#include<bits/stdc++.h>
using namespace std;
/**Structure Defined**/
struct edge{
    pair<float , float> w;
    int x;
    int y;
};
struct dis{
    int p;
    int d;
}dis[100005];

/**Sort comparator defined**/
bool cmp(edge e1,edge e2){
    if(float(e1.w.first/e1.w.second)>float(e2.w.first/e2.w.second))
        return true;
    else if(float(e1.w.first/e1.w.second)<float(e2.w.first/e2.w.second)){
        return false;
    }
    else if(float(e1.w.first/e1.w.second)==float(e2.w.first/e2.w.second)){
        if(float(e1.w.first/e1.w.second)>=1.0){
            if(e1.w.first>e2.w.first)
                return true;
            else
                return false;
        }
        else{
            if(e1.w.first>e2.w.first)
                return false;
            else
                return true;
        }
    }
}
int find_set(int x){
    if(dis[x].p!=x)
        dis[x].p=find_set(dis[x].p);
    return dis[x].p;
}

int union_(int x,int y){
    int xR = find_set(x);
    int yR = find_set(y);
    if(dis[xR].d>dis[yR].d)
        dis[yR].p=xR;
    else if(dis[xR].d<dis[yR].d)
        dis[xR].p=yR;
    else{
        dis[yR].p=xR;
        dis[xR].d++;
    }
}

int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    edge e;
    vector<edge> v;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,x,y;
        cin>>x>>y>>a>>b;
        if(x!=y){
            e.w=make_pair(a,b);
            e.x=x;
            e.y=y;
            v.push_back(e);
        }
    }
    sort(v.begin(),v.end(),cmp);
    /**for(vector<edge>::iterator it=v.begin();it!=v.end();it++){
        cout<<(*it).w.first<<" "<<(*it).w.second<<"fraction :"<<float((*it).w.first/(*it).w.second)<<endl;
        cout<<(*it).x<<" "<<(*it).y<<endl;
    }**/
    //vector<edge> ans;
    int a_=0,b_=0;
    for(int i=0;i<=n;i++){
        dis[i].p=i;
        dis[i].d=0;
    }
    for(vector<edge>::iterator it=v.begin();it!=v.end();it++){
        if(find_set((*it).x)!=find_set((*it).y)){
            //ans.push_back(*it);
            union_((*it).x,(*it).y);
            a_+=(*it).w.first;
            b_+=(*it).w.second;
        }
    }
    /*for(vector<edge>::iterator it=ans.begin();it!=ans.end();it++){
        cout<<(*it).w.first<<" "<<(*it).w.second<<"fraction :"<<float((*it).w.first/(*it).w.second)<<endl;
        cout<<(*it).x<<" "<<(*it).y<<endl;
    }*/
    int t=gcd(a_,b_);
    a_/=t;
    b_/=t;
    printf("%d/%d \n",a_,b_);
    return 0;
}
