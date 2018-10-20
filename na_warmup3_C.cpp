#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int x;
        string name1;
        string name2;
        cin>>x>>name1;
        if(name1=="Alice")
        name2 = "Bob";
        else name2 = "Alice";
        int cntr = 0;
        int f = 1-(x%2);
        vector<pair<int,int> > v;
        while(x%2==0){
            cntr++;
            x/=2;
        }
        if(cntr>0)
            v.push_back(make_pair(2,cntr));
        for(int i=3;i<=ceil(sqrt(x));i+=2){
            if(x%i == 0){
                cntr=0;
                while(x%i==0){
                    cntr++;
                    x/=i;
                }
                v.push_back(make_pair(i,cntr));
                f++;
                if(f>2 || x == 1)
                    break;
            }
        }
        if(x!=1){
            v.push_back(make_pair(x,1));
            f++;
        }
        if(f>2)
            cout<<"tie"<<endl;
        else{
            assert(v.size()<=2);
            if(v.size()==1)
                cout<<(v[0].second%2 ? name1:name2)<<endl;
            else{
                if(abs(v[0].second-v[1].second)<=1)
                    cout<<((v[0].second+v[1].second)%2 ? name1:name2)<<endl;
                else
                    cout<<"tie"<<endl;
            }
        }
    }
    return 0;
}