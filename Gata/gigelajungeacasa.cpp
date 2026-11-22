#include <bits/stdc++.h>
using namespace std;

ifstream fin("gigelajungeacasa.in");
ofstream fout("gigelajungeacasa.out");

short int di[16]={-1, -1, 0, 1, 1, 1, 0, -1};
short int dj[16]={0, 1, 1, 1, 0, -1, -1, -1};

int a[1005][1005], b[1005][1005], n, m, k, d;
int x1, yl, x2, y2, xy, yy, xb, yb, x, y;

bool inmat(int i, int j){
    return i>=1 && i<=n && j>=1 && j<=m;
}

void Lee(int is, int js) {
    queue<pair<int, int>> q;
    q.push(make_pair(is, js));
    b[is][js] = 1;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int d = 0; d < 8; d++) {
            int iv = i + di[d];
            int jv = j + dj[d];

            if (inmat(iv, jv) && a[iv][jv] == 0 && b[iv][jv] == 0) {
                b[iv][jv] = b[i][j] + 1;
                q.push(make_pair(iv, jv));
            }
        }
    }
}

int main(){

    fin>>n>>m>>k;  //Marimea tabloului, k=numarul varcolacilor
    fin>>x1>>yl; //coordonatele casei
    fin>>x2>>y2; //coordonatele popasului
    fin>>xy>>yy; //yeti
    fin>>xb>>yb; //bicfut
    for(int i=0; i<k; i++){
        fin>>x>>y;
        a[x][y]=-1;
    }

    a[xy][yy]=-1;
    a[xb][yb]=-1;

    Lee(x2, y2);

    fout<<b[x1][yl]-1;






}