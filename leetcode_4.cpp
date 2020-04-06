#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<char, int> m;
    int ans = 1;
    void check(int gap){
        bool f = true;
        for(auto i:m) f &= (i.second <=1);
        ans = max(ans, (f?gap:0));
    }

    int lengthOfLongestSubstring(string s) {
        int n = (int)s.length();
        for(int gap=1;gap<=min(26,n);gap++){
            m.clear();
            for(int i=0;i<gap;i++)m[s[i]]++;
            check(gap);
            for(int i=gap; i<n ; i++){
                m[s[i-gap]]--;
                m[s[i]]++;
                check(gap);
            }
        }
        return ans;
    }
};

int main(){
    Solution s = Solution();
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;

}
