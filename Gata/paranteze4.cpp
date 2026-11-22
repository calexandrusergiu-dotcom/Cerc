#include <bits/stdc++.h>
using namespace std;

int main(){

    char s[254];
    cin>>s;
    stack<int> st;
    int p=0;
    for(int i=0; i<strlen(s); i++){
        char c=s[i];
        if(c=='('){
            p++;
            st.push(p);
        }
        if(c==')'){
            cout<<st.top()<<" ";
            st.pop();
        }

    }

}