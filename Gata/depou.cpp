#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    stack<int> a,b,c;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push(x);
    }

    int min=1,m=0;
    bool corect=true;
    string rand[2005];

    while(min<=n){
        if(!a.empty() && a.top()==min){
            a.pop();
            c.push(min);
            rand[m]="A C";
            m++;
            min++;
        }
        else if(!b.empty() && b.top()==min){
            b.pop();
            c.push(min);
            rand[m]="B C";
            m++;
            min++;
        }
        else if(!a.empty()){
            int x=a.top();

            if(!b.empty() && x>b.top()){
                corect=false;
                break;
            }

            a.pop();
            b.push(x);
            rand[m]="A B";
            m++;
        }
        else{
            corect=false;
            break;
        }
    }

    if(corect){
        cout<<m<<"\n";
        for(int i=0;i<m;i++){
            cout<<rand[i]<<"\n";
        }
    }else{
        cout<<0;
    }
}