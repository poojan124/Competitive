#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dist(int x, int y){
    return ((ll)x*(ll)x) + ((ll)y*(ll)y);
}

bool comp(pair<char, ll> a, pair<char, ll> b){
    return a.second < b.second;
}

int solution(string &S, vector<int> &X, vector<int> &Y) {
    vector<pair<char, ll> > v;
    for(int i = 0 ; i < S.size() ; i++){
        v.push_back({S[i], dist(X[i], Y[i])});
    }
    sort(v.begin(), v.end(), comp);
    int ans = 0;
    map<char, bool> m;
    pair<char, ll> prev = {'#',-1};
    for(int i=0;i<v.size();i++){
        if(prev.first == v[i].first && prev.second == v[i].second){
            ans--;
            break;
        }
        if(m[v[i].first] == true){
            // cout << "here " << v[i].first << " " << v[i].second << endl;
            break;
        }
        m[v[i].first] = true;
        ans++;
        prev = v[i];
    }
    return ans;
}

int main(){
    string s = "ABDCA";
    vector<int> a = {2,-1,-4,-3,3};
    vector<int> b = {2,-2,4,1,-3};
    cout << solution(s, a, b) << endl;

}