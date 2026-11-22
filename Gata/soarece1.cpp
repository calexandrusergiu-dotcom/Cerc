
#include <bits/stdc++.h>
using namespace std;

ifstream fin("soarece1.in");
ofstream fout("soarece1.out");

int n, m;
int is, js, ib, jb;
char a[1005][1005];
int b[1005][1005];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
bool gasit=false;

bool inmat(int i, int j){
    return i>=1 && i<=n && j>=1 && j<=m;
}

void back(int is, int js, int pas){
    if(!inmat(is, js)) return;
    if(a[is][js]=='#') return;
    if(b[is][js]!=0) return;
    if(gasit) return;

    b[is][js]=pas;

    if(a[is][js]=='B'){
        gasit=true;
        return;
    }

    for(int k=0; k<4; k++){
        back(is+di[k], js+dj[k], pas+1);

        if(gasit) return;
    }

    b[is][js]=0;
}

int main(){

    fin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            fin>>a[i][j];

            if(a[i][j]=='S'){
                is=i;
                js=j;
            }

            if(a[i][j]=='B'){
                ib=i;
                jb=j;
            }
        }
    }

    back(is, js, 1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            fout<<setw(2)<<b[i][j]<<" ";
        }
        fout<<"\n";
    }
}
