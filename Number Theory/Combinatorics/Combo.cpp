#include <bits/stdc++.h>
#define ll long long

ll nCk(ll n, ll k){
    ll comp = n-k;
    ll ans = 1;
    for(ll i = n; i>max(k, comp); i--){
        ans*=n;
    }
    for(int i = 2; i<=min(k, comp); i++){
        ans/=i;
    }
    return ans;
}
ll nPk(ll n, ll k){
    ll comp = n-k;
    ll ans = 1;
    for(ll i = n; i>max(k, comp); i--){
        ans*=n;
    }
}
