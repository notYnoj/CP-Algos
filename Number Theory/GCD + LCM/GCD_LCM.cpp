/*Euclidean GCD algorithm
It can be used to solve Linear Diophantine equations
as ax+by+cz... = T only has an integer solution if
GCD(a,b,c...) | (divides)T
TC - O(log(min(a,b)))
SC - O(1)
*/
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
/*clever LCM implementation using above GCD def
*/
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

/* Ex usage: 1700 rated - Beauty of the Mountains
//Linear Diophine -> x + Ax  = Y - Ay (where x is k*k - pref)
// rearrange u get y-x = Ax+Ay+Bz+By... Linear Diophantine use the above solution.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        vector<vector<ll>> grid(n, vector<ll>(m));
        vector<vector<ll>> needed(n, vector<ll>(m));
        ll mon1 = 0, mon2 = 0;
        for(ll i = 0;i<n; i++){
            for(ll j = 0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        for(ll i = 0 ;i<n; i++){
            string s;
            cin>>s;
            for(ll j = 0; j<m; j++) {
                if (s[j] == '1') {
                    mon1 += grid[i][j];
                    needed[i][j] = 1;
                } else {
                    mon2 += grid[i][j];
                    needed[i][j] = 0;
                }
            }
        }
 
        if(k == 1 || mon1 == mon2) cout<<"YES\n";
        else{
            //kxk -check, check will be for wihtout them, with them will be kxk-check
            set<ll> st;
            vector<vector<ll>> pref(n, vector<ll>(m, 0));
            for(ll i = 0; i<n; i++){
                for(ll j = 0; j<m; j++){
                    pref[i][j] = needed[i][j];
                    if(i>0){
                        pref[i][j]+=pref[i-1][j];
                    }
                    if(j>0){
                        pref[i][j]+=pref[i][j-1];
                    }
                    if(i>0 && j>0){
                        pref[i][j] -= pref[i-1][j-1];
                    }
                }
            }
            for(ll i = 0; i<=n-k; i++){
                for(ll j = 0; j<=m-k; j++){
                    ll cur = pref[i+k-1][j+k-1];
                    if(i>0) cur-= pref[i-1][j+k-1];
                    if(j>0) cur-=pref[i+k-1][j-1];
                    if(i>0 && j>0) cur+=pref[i-1][j-1];
                    st.insert(cur);
                }
            }
            vector<bool> used((k*k+1), false);
            ll totz = k*k;
            bool can = false;
            ll gcd = LLONG_MAX;
            ll df = max(mon1,mon2)-min(mon1,mon2);
            for(ll i: st){
                if(used[totz-i] || used[totz]) continue;
                else{
                    ll ax = totz-i;
                    ll bx = i;
                    ll newx = max(ax,bx)-min(ax,bx);
                    if(!newx) continue;
                    if (gcd == LLONG_MAX) gcd = newx;
                    else gcd = gcd(gcd, newx);
                    if((df%newx) == 0){
                        cout<<"YES\n";
                        can = true;
                        break;
                    }
                    if(df%gcd == 0){
                        cout<<"YES\n";
                        can = true;
                        break;
                    }
                }
            }
            if(can) continue;
            else{
                if(df % gcd == 0){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }
 
        }
    }
}
*/
