#include<bits/stdc++.h>

using namespace std; 
#define trav(x,v) for (auto &x : v)
#define pv(v) trav(x, v) cout << x << " "; cout << endl;
int main() 
{ 
    int x;
    vector<int> v;
    int max_ = 0;
	while(cin>>x){
        v.push_back(x);
        max_ = max(max_,x);
    }
	int visi[max_+5];
    memset(visi,0,sizeof(visi));
    for(int i=0;i<v.size();i++){
        if(visi[v[i]]){
            for(int j=visi[v[i]]-1;j<i;j++)
                cout<<v[j]<<" ";
            cout<<endl;
            break;
        }
        visi[v[i]] = i+1;
    }
    // pv(visi);
	return 0; 
} 
