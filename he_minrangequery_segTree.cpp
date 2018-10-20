#include<bits/stdc++.h>
using namespace std;
#define maxN 100010
#define intMax 1e9
int a[maxN];
int tree[10*maxN];

inline int min(int x,int y){
    return tree[x]<tree[y]?tree[x]:tree[y]; 
}

void build(int s,int lc,int rc){
    if(lc == rc)
        tree[s] = a[lc];
    else{
        int mid = (lc+rc)/2;
        build(2*s,lc,mid);
        build(2*s+1,mid+1,rc);
        tree[s] = min(2*s,2*s+1);
    }
}

void update(int s,int lc,int rc,int idx,int val){
    if(lc == rc){
        tree[s] = val;
        a[idx] = val;
    }
    else{
        int mid = (lc+rc)/2;
        if(lc <= idx && idx <= mid)
            update(2*s,lc,mid,idx,val);
        else   
            update(2*s+1,mid+1,rc,idx,val);
        tree[s] = min(2*s,2*s+1);
    }
}

int query(int s,int lc,int rc,int l,int r){
    // cout<<"Query for"<<s<<" "<<lc<<" "<<rc<<" "<<l<<" "<<r<<endl;
    if(r < lc  || l > rc)
        return tree[0];
    if(l<=lc &&  rc<=r)
        return tree[s];
    int mid = (lc+rc)/2;
    // cout<<"Split "<<l<<" "<<mid<<" "<<r<<endl;
    int lv = query(2*s,lc,mid,l,r);
    int rv = query(2*s+1,mid+1,rc,l,r);
    return lv<rv?lv:rv;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    tree[0] = intMax;
    for(int i=1;i<=q;i++){
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c == 'q')
            cout<<query(1,1,n,x,y)<<endl;
        else
            update(1,1,n,x,y);
    }
    return 0;
}