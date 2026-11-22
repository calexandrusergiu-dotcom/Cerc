#include <bits/stdc++.h>
using namespace std;

int n, k;
long long dp[100005];
int main(){
    cin>>n>>k;
    dp[1]=1;
    long long suma=1;
    for(int i=2; i<=n; i++){
        dp[i]=suma;
        suma=(suma+dp[i])%9001;

        if(i-k>=1){
            suma=(suma-dp[i-k]+9001)%9001;
        }
    
    }
    cout<<dp[n];
    return 0;


}