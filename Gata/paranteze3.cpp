#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("paranteze3.in");
    ofstream fout("paranteze3.out");

    int n;
    fin>>n;

    for(int i=0; i<n; i++){
        string s;
        fin>>s;
        bool corect=true;

        stack<char> st;

        for(int i=0; i<s.length(); i++){
            char c=s[i];
            if(c=='(' || c=='['){
                st.push(c);
            }
            else if(c==')'){
                if(c==')' && !st.empty() && st.top()!='['){
                    st.pop();
                }else{
                    corect=false;
                }
            }
            else if(c==']'){
                if(c==']' && !st.empty() && st.top()!='('){
                    st.pop();
                }else{
                    corect=false;
                }
            }
        }

            if(corect && st.empty()){
                fout<<"1\n";
            }else{
                fout<<"0\n";
            }
    }


}