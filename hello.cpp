#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3 + 5;
vector<vector<ll>> adj(N);
vector<bool> bl(N, false);

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);


    ll n;
    while(cin>>n){

    // Direct 1 print kora holo
    cout << 1;

    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            cout << " x " << i;
            n/=i;
        }
    }
    if(n>1){
        cout << " x " << n;
    }
    cout << endl;
  //  cout << endl;
}
}