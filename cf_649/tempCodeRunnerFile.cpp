#include<bits/stdc++.h>
using namespace std;
int v[1000001];

int main(){
    // cout << " asdf";
    int n;
    cin >> n;
    int a[n], b[n];
    set<int> s;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    deque<int> q;
    for(int i=0;i<=2*n;i++){
        if(s.find(i) == s.end()){
            q.push_back(i); 
        }
    }
    int prev = a[0];
    for(int i=0;i<n;i++){
        if(a[i] != prev){
            q.push_front(prev);
            prev = a[i];
        }
        int x = q.front();
        q.pop_front();
        b[i] = x;
        
    }
    for(auto x : b)
        cout << x << " ";
    return 0;
}