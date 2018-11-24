#include<bits/stdc++.h>
using namespace std;
vector< vector< int > > v(200000+5);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    queue<int> q;
    q.push(1);
    int flag = 1;
    int i=0;
    bool V[n+5];
    memset(V,0,sizeof(V));
    int j=1;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        V[ele] = 1;
        if(ele!=a[i]){
            flag = 0;
            //cout<<"break1 at : "<<i<<endl;
            break;
        }
        i++;
        //cout<<"size for ele: "<<ele<<" is : "<<v[ele].size()<<endl;
        for(int c=0; c<v[ele].size() ;c++){
           // cout<<"this is fk: "<<v[ele][c]<<" and "<<V[v[ele][c]]<<endl;
            if(!V[v[ele][c]]){
                if(find(v[ele].begin(),v[ele].end(),a[j])==v[ele].end()){
                    flag=0;
                    //cout<<"break at : "<<j<<"and value is"<<a[j]<<endl;
                    //cout<<v[ele][0]<<" "<<v[ele][1]<<endl;
                    break;
                }
                else{
                    q.push(a[j]);
                }
                j++;
            }
            if(!flag){
                //cout<<"break2 at : "<<i<<endl;
                break;
            }
        }
        if(!flag){
            //cout<<"break3 at : "<<i<<endl;
            break;
        }
    }
    string ans= flag?"Yes":"No" ;
    cout<<ans<<endl;
    return 0;
}