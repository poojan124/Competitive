#include<bits/stdc++.h>

using namespace std;
int solution(vector<int> &A) {
    priority_queue<int, vector<int>, greater<int> > p(A.begin(), A.end());
    int ans = 0;
    while(p.size() > 1){
        int a = p.top();
        p.pop();
        int b = p.top();
        p.pop();
        p.push(a + b);
        ans += (a + b);
    }
    return ans;
}

int main(){
    vector<int> v = {10,20,30,40,50};
    cout << solution(v);
    return 0;

}