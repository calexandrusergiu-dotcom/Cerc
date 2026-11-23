#include <bits/stdc++.h>
using namespace std;

ifstream fin("croco.in");
ofstream fout("croco.out");

int a[1005][1005];
char b[1005][1005];

int main(){

    int n, m;
    fin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            fin>>a[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
           if(a[i][j]==0){
                b[i][j]='A';
                continue;
           }else if(i%2==j%2){
                b[i][j]='C';
           }else{
                b[i][j]='E';
           }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
           fout<<b[i][j]<<" ";
        }
        fout<<"\n";
    }
     
}