#include<bits/stdc++.h>
using namespace std;
string flip(string s){
    for(int i=0;i<s.length();i++)
        s[i] = (1-(s[i]-48))+48;
    return s;
}
int count(string s){
    int cntr = 0;
    for(int i=0;i<s.length();i++)
        if(s[i]-48)
            cntr++;
    return cntr;
}
int main(){ 
    string s;
    cin>>s;
    int len = s.length();
    stack<string> st;
    for(int i=len-1;i>=0;i--){
        string t1,t2;
        if(s[i] == '+'){
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
        }
        else if(s[i] == '-'){
            t1 = st.top();
            st.pop();
            t2 = flip(st.top());
            st.pop();
        } 
        else
            t1 = "1";
        st.push(t1+t2);
    }
    string eq= st.top();
    int pos = count(eq);
    int neg = eq.length() - pos;
    int fac,extra, flag;
    if(pos>neg){
        fac = (pos-1)/neg;
        extra = pos - (fac*neg);
        flag = 0;
    }
    else{
        fac = neg/pos;
        extra = neg - (fac*pos);
        flag = 1;
    }
    for(int i=0;i<eq.length();i++){
        if((eq[i]-48)^flag)
            printf("1\n");
        else{
            if(extra){
                printf("%d\n",fac+1);
                extra--;
            }
            else     
                printf("%d\n",fac);
        }
    }
    return 0;
}
