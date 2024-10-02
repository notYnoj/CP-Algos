#include <bits/stdc++.h>
#define ll long long

ll nCk(ll n, ll k) {
    if (k > n - k)
        k = n - k;

    ll result = 1;
    for (ll i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}
ll nPk(ll n, ll k){
    ll comp = n-k;
    ll ans = 1;
    for(ll i = n; i>max(k, comp); i--){
        ans*=n;
    }
}
