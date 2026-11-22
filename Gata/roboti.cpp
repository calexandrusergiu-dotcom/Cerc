#include <bits/stdc++.h>
using namespace std;

ifstream fin("roboti.in");
ofstream fout("roboti.out");

int di[4]={-1, 1, 0, 0};
int dj[4]={0, 0, -1, 1};
int a[1005][1005];
int b[1005][1005]={0};
int lin, col;
int is, js;
int ist, jst;

int inMat(int i, int j){
    return i>=1 && i<=lin && j>=1 && j<=col;
}

void Lee(int is, int js) {
    queue<pair<int, int>> q;
    q.push(make_pair(is, js));
    b[is][js] = 1;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int iv = i + di[d];
            int jv = j + dj[d];

            if (inMat(iv, jv) && a[iv][jv] == 0 && b[iv][jv] == 0) {
                b[iv][jv] = b[i][j] + 1;
                q.push(make_pair(iv, jv));
            }
        }
    }
}



int main(){

    fin>>lin;
    fin>>col;
    for(int i=1; i<=lin; i++){
        for(int j=1; j<=col; j++){
            fin>>a[i][j];
        }
    }

    fin>>is;
    fin>>js;

    Lee(is, js);

    fin>>ist;
    fin>>jst;

    fout<<b[ist][jst]-1;
   
    

}




