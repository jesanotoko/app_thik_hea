#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t;
    cin >> t;
    vector<ll>a(1e6+10,0);

    while(t--){
        ll n;
        cin >> n;
        if(n==1){
            cout << "deficient\n";
            continue;
        }
        if(a[n]){
            if(a[n]==1)cout << "abundant\n";
            else if(a[n]==2)cout << "deficient\n";
            else cout << "perfect\n";
            continue;
        }
        ll ans = 1, to = 1, val = 1;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                val+=i;
                if((n/i)!=i)val+=(n/i);
            }
        }
        if(val>n)a[n]=1;
        else if(val<n)a[n]=2;
        else a[n]=3;

        if(a[n]==1)cout << "abundant\n";
        else if(a[n]==2)cout << "deficient\n";
        else cout << "perfect\n";
    }
}