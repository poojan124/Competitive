#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > v(1002);
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        bool visited[1002];
        memset(visited,0,sizeof(visited));
        
        int k1;
        cin>>k1;
        int vk1[k1];
        bool isin1[1002];
        memset(isin1,0,sizeof(isin1));
        for(int i=0;i<k1;i++){
            cin>>vk1[i];
            isin1[vk1[i]] = 1;
        }
        
        int k2;
        cin>>k2;
        int vk2[k2];
        bool isin2[1002];
        memset(isin2,0,sizeof(isin2));
        for(int i=0;i<k2;i++){
            cin>>vk2[i];
            isin2[vk2[i]] = 1;
        }
        //query 1
        cout<<"B "<<vk2[0]<<endl;
        fflush(stdout);
        int ans1;
        cin>>ans1;
        //check query 1
        if(isin1[ans1])
            cout<<"C "<<ans1<<endl;
        else{
            queue<int> q;
            q.push(ans1);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                visited[node] = 1;
                //query 2
                if(isin1[node]){
                    cout<<"A "<<node<<endl;
                    fflush(stdout);
                    cin>>ans1;
                    if(isin2[ans1])
                        cout<<"C "<<node<<endl;
                    else
                        cout<<"C -1"<<endl;
                    break;
                }
                for(auto adj:v[node]){
                    if(!visited[adj]){
                        q.push(adj);
                    }           
                }
            }
        }
    }
}