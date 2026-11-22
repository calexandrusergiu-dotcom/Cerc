#include <bits/stdc++.h>
using namespace std;

long long invers(long long n){
    long long in=0;

    if(n%10==0) return 11;
    while(n!=0){
        in=in*10+n%10;
        n=n/10;
    }
    return in;
}

int main(){
    long long a, b, nr=0;
    cin>>a>>b;
  
    long long nri=1;
    while(nri*nri<a) nri++;
    
    for(; nri*nri<=b; nri++){

        long long ggg=nri*nri;

        if(ggg%10==0) continue;

        long long g=invers(ggg);
        long long gg=round(sqrt(g));

        if(gg*gg==g) nr++;
    }

    cout<<nr;

}
// is.int(is)