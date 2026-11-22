#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;

ifstream fin("paranteze2.in");
ofstream fout("paranteze2.out");

int main()
{

    string s;
    fin>>s;

    stack<char> st;
    int n=0, max=0;
    
    for(int i=0; i<s.length(); i++){
        char c=s[i];

        if(c=='('){
            st.push(c);
            n++;
            if(n>max) max=n;
        }
        else if(c==')'){
            st.pop();
            n--;
        }
    }

    fout<<max;
    



}