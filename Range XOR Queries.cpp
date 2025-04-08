#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n, q; cin>>n>>q;
	vector <ll> px (n+2);
	for (int i=1;i<=n;i++){
		cin>>px[i];
		px[i]^=px[i-1];
	}
	ll a,b; 
	while (q--){
		cin>>a>>b;
		cout<<(px[b]^px[a-1])<<endl;
	}
}
