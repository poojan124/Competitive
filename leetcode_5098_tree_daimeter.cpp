#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int,int> bfs(vector<vector<int> > v, int s){
        queue<int> q; 
        int dis[10000+5];
        for(int i=0;i<10000+2;i++)dis[i]=-1;
        q.push(s);
        dis[s] = 0;
        while(!q.empty()){
            int S = q.front();
            q.pop();
            for(auto x:v[S]){
                if(dis[x]==-1){
                    q.push(x);
                    dis[x] = dis[S] + 1;
                }
            }
        }
        pair<int,int> p = make_pair(0,0);
        for(int i=0;i<10000+2;i++){
            if(dis[i]>p.second)
                p = make_pair(i, dis[i]);
        }
        return p;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        vector<vector<int> > v(10000+5);
        for(auto e:edges){
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }
        auto node1 = bfs(v, 0);
        auto node2 = bfs(v, node1.first);
        return node2.second;
    }
};

int main(){
    vector<vector<int> > v(2);
    v[0].push_back(0);
    v[0].push_back(1);

    v[1].push_back(0);
    v[1].push_back(2);
    cout << v.size() << endl;
    for(auto x : v){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    auto sol = Solution();
    cout << sol.treeDiameter(v);
}