#include <iostream>
#include <cstring>
#include <stack>
#include <fstream>
using namespace std;

int main(){

    ifstream fin("paranteze1.in");
    ofstream fout("paranteze1.out");

    int n;
    fin >> n;

    for(int i = 0; i < n; i++){
        string s;
        fin >> s;

        stack<char> st;
        bool corect = true;

        for(int i = 0; i < s.length(); i++){
            char c = s[i];

            if(c == '('){
                st.push(c);
            }
            else if(c == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    corect = false;
                }
            }
        }

        if(st.empty() && corect == true)
            fout << "1" << endl;
        else
            fout << "0" << endl;
    }

    return 0;
}