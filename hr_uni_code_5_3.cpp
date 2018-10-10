#include<bits/stdc++.h>
using namespace std;
bool V[300000+5];
vector< vector< long long > > v(300000+5);
vector<long long> neigh;
void dfs(long long i){
    V[i] = 1;
    neigh.push_back(v[i].size());
    for(vector<long long>::iterator it = v[i].begin(); it != v[i].end(); it++){
        if(!V[*it])
            dfs(*it);
    }
    return;
}
int main(){
    long long n,m,a,b;
    cin>>n>>m>>a>>b;
    for(long long i=0;i<m;i++){
        long long x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(V,0,sizeof(V));
    long long cntr = 0;
    for(long long i=1;i<=n;i++){
        if(!V[i]){
            neigh.clear();
            dfs(i);
            //for(long long i=0;i<neigh.size();i++)
              //  cout<<neigh[i]<<" ";
            //cout<<endl;
            long long min_ = a*(*min_element(neigh.begin(),neigh.end()));
            long long max_ = b*(*max_element(neigh.begin(),neigh.end()));
            //cout<<min_<<" "<<max_<<endl;
            for(vector<long long> :: iterator it=neigh.begin();it!=neigh.end();it++){
                if(*it>min_  && *it<max_)
                    cntr++;
            }
        }
    }
    cout<<cntr<<endl;
}
