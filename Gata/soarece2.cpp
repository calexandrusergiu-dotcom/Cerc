#include <bits/stdc++.h>
using namespace std;

ifstream fin("soarece2.in");
ofstream fout("soarece2.out");

stack<char> q;

int di[4]={-1, 1, 0, 0};
int dj[4]={0, 0, 1, -1};
char dp[4]={'N', 'S', 'E', 'V'};
char a[1005][1005];
int b[1005][1005];
char bp[1005][1005];
int n, m;
int is, js, ib, jb;
bool gasit=false, pas=1;

bool inmat(int is, int js){
    return is>=1 && is<=n && js>=1 && js<=m;
}

void Lee(int is, int js){
    queue<pair<int, int>> q;
    q.push(make_pair(is, js));
    b[is][js]=1;

    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();

        for(int k=0; k<4; k++){
            int iv=i+di[k];
            int jv=j+dj[k];

            if(inmat(iv, jv) && (a[iv][jv]=='_' || a[iv][jv]=='B') && b[iv][jv]==0){
                b[iv][jv]=b[i][j]+1;
                q.push(make_pair(iv, jv));
            }
        }
    }
}

void drum(int ib, int jb){

    int k;

    for(k=0; k<4; k++){
        int iv=ib+di[k];
        int jv=jb+dj[k];

        if(inmat(iv, jv)  && b[ib][jb]-1==b[iv][jv]) break;
    }
    
    //char dp[4]={'N', 'S', 'E', 'V'};

    if(b[ib][jb]>1){

        switch(k){
            case 0: q.push('S'); break;
            case 1: q.push('N'); break;
            case 2: q.push('V'); break;
            case 3: q.push('E'); break;
        }  

    
        drum(ib+di[k], jb+dj[k]);
    }
    


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

    Lee(is, js);

    drum(ib, jb);

    fout<<b[ib][jb]-1<<"\n";

    while(!q.empty()){
        fout<<q.top();
        q.pop();
    }

}
