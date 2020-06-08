#include <bits/stdc++.h>

using namespace std;

bool matchP(string& a, string& b){
    for(int i=0;i<b.size();i++){
        if(b[i]!=a[i]) return false;
    }
    return true;
}

bool matchS(string& a, string& b){
    int j=a.size()-1;
    for(int i=b.size()-1;i>=0;i--){
        if(b[i]!=a[j--]) return false;
    }
    return true;
}

int main()
{
    int t,n;
    string p[50];
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<pair<pair<string,string>,string>> prs;
        bool flag =true;
        for(int i=0;i<n;i++) cin>>p[i];
        string longestP, longestS;
        for(int i=0;i<n;i++){
            string t;
            int start,end;
            for(int j=0;j<p[i].size();j++){
                if(p[i][j]=='*'){
                    start = j;
                    break;
                }
            }
            for(int j=p[i].size()-1;j>=0;j--){
                if(p[i][j]=='*'){
                    end = j;
                    break;
                }
            }
            string prefix = p[i].substr(0,start);
            string suffix = p[i].substr(end+1, p[i].size()-1-end);
            string s;
            for(int j=start+1;j<end;j++){
                if(p[i][j]!='*') s+=p[i][j];
            }
            string middle = s;
           
            prs.push_back({{prefix,suffix},middle});
            if(prefix.size()>longestP.size()) longestP = prefix;
            if(suffix.size()>longestS.size()) longestS = suffix;
        }
        if(longestP.size()){
            for(int i=0;i<n;i++){
                if( !matchP(longestP,prs[i].first.first)){
                    flag=false;break;
                }
            }
        }
       
        if(longestS.size()){
            for(int i=0;i<n;i++){
                if( !matchS(longestS,prs[i].first.second)){
                    flag=false;break;
                }
            }
        }
       
        if(!flag){
            cout<<"Case #"<<tc<<": *"<< endl;
            continue;
        }
        else{
            string res = longestP;
            for(int i=0;i<n;i++){
                res+=prs[i].second;
            }
            res+=longestS;
            cout<<"Case #"<<tc<<": "<<res<< endl;
        }
       
    }
    return 0;
}
