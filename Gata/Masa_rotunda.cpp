#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n, k;
    cin>>n>>k;
    if(n%2==1)
    cout<<min(n, k+1);
    else{
        if(k+1>n/2) cout<<n/2;
        else cout<<k+1;
    }
    

}