#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > v(10000+5);
bool V[10000+5];
int sub[10000+5];
int par[10000+5];
void dfs1(int s){
    V[s] = 1;
    for(auto i:v[s]){
        if(!V[i]){
            dfs1(i);
            sub[s] += sub[i];
        }
    }
}
int main(){
    cin>>n;
    memset(V,0,sizeof(V));
    fill(sub,sub+10000+5,1);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(0);
    int cost = 0;
    int ans = 0;
    // int exp_junctions = (n-1)*(n)/2;
    //cout<<exp_junctions<<endl;
    for(int i=0;i<=n;i++){
        int sum_ = 0,m1 = -1,m2 = -1;
        vector<int> t;
        for(auto e:v[i]){
            if(sub[e] > sub[i]){
                int temp = n-sub[i]+1;
                sum_ += temp;
                t.push_back(temp);
                int flag1 = 0; 
                if(temp>m1){
                    m2 = m1;
                    m1 = temp;
                    flag1 = 1;
                }
                else if(temp > m2  and !flag1)
                    m2 = temp;
                continue;
            }
            sum_ += sub[e];
            int flag1 = 0 ;
            if(sub[e]>m1){
                m2 = m1;
                m1 = sub[e];
                flag1 = 1;
            }
            else if(sub[e] > m2 && !flag1)
                m2 = sub[e]; 
            t.push_back(sub[e]);
        }
        int tcost = 0;
        for(int I=0;I<t.size()-1;I++){
            sum_ = sum_-t[I];
            tcost += t[I]*sum_;
        }
        if(tcost > cost){
            cost = tcost;
            if(m1!=-1 && m2!= -1)
                ans = cost - m1*m2;
        }
        //cout<<"cost for "<<i<<" "<<tcost<<" "<<m1<<" "<<m2<<endl;
    } 
    cout<<cost<<" "<<ans<<endl;
    return 0;
}