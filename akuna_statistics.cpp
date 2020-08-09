#include<bits/stdc++.h>
using namespace std;


vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

string max_(map<string, int> &m){
    pair<string, int> p = {"temp", 0};
    for(auto x : m){
        if(p.second < x.second || (p.second == x.second && p.first > x.first)){
            p = x;
        }
    }
    return p.first;
}

int main(){
    string s;
    cin >> s;
    map<string, int> pass;
    map<string, int> city;
    int total = 0;
    while(s != "q"){
        vector<string> v = split(s, ":");
        int dis = stoi(v[3]);
        total += dis;
        pass[v[0]] += dis;
        city[v[1]]++;
        city[v[2]]++;
        cout << total << ":" << max_(pass) << ":" << max_(city) << endl;
        cin >> s;
    }

}