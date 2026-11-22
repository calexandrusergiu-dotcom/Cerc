#include <bits/stdc++.h>
using namespace std;

ifstream fin("soarece.in");
ofstream fout("soarece.out");

int di[4]={-1, 1, 0, 0};
int dj[4]={0, 0, -1, 1};


int is, js, ib, jb;
int n, m, nr=0;
int a[1005][1005];

void back(int is, int js){

    if(is<1 || is>n || js<1 || js>m) return;
    if(a[is][js]==1) return;
    if(a[is][js]==2) return;

    a[is][js]=2;

    if(is==ib && js==jb){
        nr++;
        a[is][js]=0;
        return;
    }

    for(int k=0; k<4; k++){
        back(is+di[k], js+dj[k]);
    }
    a[is][js]=0;


}



int main(){
   fin>>n;
   fin>>m;
   for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        fin>>a[i][j];
    }
   }
   fin>>is>>js;
   fin>>ib>>jb;

   back(is, js);
   fout<<nr;
}