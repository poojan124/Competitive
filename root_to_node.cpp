#include<bits/stdc++.h>
using namespace std;
vector<int>  st;
bool V[1000000+5];
vector<vector<int> > v(1000000+5);
void dfs(int s,int p,int q){
    st.push_back(s);
    V[s]=1;
    if(s==p or s==q){
        cout<<"Path to node "<<s<<":"<<endl;
        for(int i=0;i<st.size();i++)
            cout<<st[i]<<" ";
        cout<<endl;
    }
    for(vector<int>::iterator it=v[s].begin();it!=v[s].end();it++)
        if(!V[*it])
            dfs(*it,p,q);
    st.pop_back();
}
int main(){
    int n,root;
    cin>>n>>root;
    memset( V , 0 , sizeof(V));
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int p,q;
    cin>>p>>q;
    dfs(root,p,q);
    return 0;
}