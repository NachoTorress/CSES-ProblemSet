#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n, x; cin>>x>>n;
	multiset <ll> longs;
	set <ll> lights;
	lights.insert(0), lights.insert(x);
	longs.insert(x);
	while (n--){
		ll a; cin>>a;
		lights.insert(a);
		auto iter=lights.find(a);
		ll nex=*next(iter); ll pre=*prev(iter);
		longs.erase(longs.find(nex-pre));
		longs.insert(nex-a); longs.insert(a-pre);
		cout<<*longs.rbegin()<<" ";
		
		
	}
	return 0;
}
