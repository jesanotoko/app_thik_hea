#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10000005;
int spf[MAXN];

// Precompute Smallest Prime Factor up to 1e7

void sieve(){
    for(int i=1;i<MAXN;i++){
        spf[i] = i;
    }
    for(int i=2;i*i<MAXN;i++){
        if(spf[i]==i){
            for(int j=i*i;j<MAXN;j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }
    }
}

int main(){
// Fast I/O is mandatory for 10^7 operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int n;
    while(cin>>n){
        cout << 1 ;
        while(n>1){
            cout << " x " << spf[n];
            n/=spf[n];
        }
        cout << "\n";
    }
}