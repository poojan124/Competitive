#include<bits/stdc++.h>

using namespace std;

int solution(string &s, int K) {
    vector<pair<int, char> > v;
    char prev = s[0];
    int cnt = 1;
    int total = 0;
    for(int i=1;i<s.size();i++){
        if(s[i] != prev){
            v.push_back({cnt, prev});
            if(cnt!=1)
                total += to_string(cnt).size();
            total++;
            cnt = 1;
            prev = s[i];
        }
        else
            cnt++;
    }
    v.push_back({cnt, prev});
    total += to_string(cnt).size();
    total++;
    if(K == 0){
        return total;
    }
    int i = 0, j;
    int ans = total;
    int n = v.size();
    while(i < n){
        j = i;
        int cur = 0, char_cnt = 0;
        while(j < n && cur < K){
            cout << j << " " << v[j].first << " " << v[j].second << " " << cur << endl;
            if(v[j].first + cur > K){
                cur = K;
                if((v[j].first - (K - cur)) == 1){
                    char_cnt += to_string(v[j].first).size();
                }
                else{
                    char_cnt += to_string(v[j].first).size() - to_string(v[j].first - (K - cur)).size();
                }
                j++;
                continue;
            }
            cur += v[j].first;
            if(v[j].first != 1)
                char_cnt += to_string(v[j].first).size();
            char_cnt++;
            j++;
        }
        cout << i << " " << j << endl;
        if(j<n && i>0 && (v[j].second == v[i-1].second)){
            cout << " here " << endl;
            int x = v[j].first + v[i-1].first;
            char_cnt += to_string(v[j].first).size() + to_string(v[i-1].first).size() - to_string(x).size();
        }
        ans = min(ans, total - char_cnt);
        i = j;
    }
    return ans;

}

int main(){
    string s = "AAAAAAAAAAABXXAAAAAAAAAA";
    int k = 3;
    cout << solution(s, k);
    return 0;
}