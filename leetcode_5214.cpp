#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        map<int, bool> v;
        map<int, vector<int> > m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
            v[arr[i]] = 0;
        }
        int ans = 0;
        for(auto i: arr){
            if(v[i])
                continue;
            int cnt = 1;
            int cur = i;
            v[cur] = 1;
            int idx = m[i][0];
            while((v.find(cur + d) != v.end())){
                cout << cur << " " << cnt << endl;
                vector<int> x = m[cur+d];
                int I = 0;
                while(I<x.size() && idx >= x[I])
                    I++;
                cout << I << endl;
                if(I == x.size())
                    break;
                else
                    idx = x[I];
                cur += d;
                cnt++;
                v[cur] = 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main(){
    vector<int> v = {1,1,1,1};
    Solution sol = Solution();
    cout << sol.longestSubsequence(v, 0);

}
