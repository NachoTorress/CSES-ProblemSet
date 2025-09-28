#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e16
int main() {
	ll n, a,b; cin>>n>>a>>b;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<ll> pfx(n+1,0);
    for (int i=1;i<=n;i++) pfx[i]=pfx[i - 1]+nums[i - 1];
    multiset<ll> op;
    ll maxi=-INF;
    for (int i = a; i <= n; i++) {
        op.insert(pfx[i-a]);
        if (i-b-1>=0) {
            auto it = op.find(pfx[i-b-1]);
            if (it!=op.end()) op.erase(it); // borramos solo una ocurrencia
        }
        if (!op.empty()) maxi = max(maxi, pfx[i] - *op.begin());
    }

    cout <<maxi;
    return 0;
}

