#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ff first
#define sc second
#define INF 1e17
int main(){
	ll n; cin>>n;
	vector <pair<ll,pair<ll,ll>>> ranges(n);
	vector <pair<ll,ll>> resp(n);
	for (ll i=0;i<n;i++){
		ll a, b; cin>>a>>b; ranges[i]={a,{-b,i}};
	}
	sort(ranges.begin(), ranges.end());
	ll maxR=0, minR=INF; 
	for (ll i=n-1;i>=0;i--){
		if (-ranges[i].sc.ff<minR){
			minR=-ranges[i].sc.ff;
			resp[ranges[i].sc.sc].ff=0;
		}
		else resp[ranges[i].sc.sc].ff=1;
	}
	for (ll i=0;i<n;i++){
		if (-ranges[i].sc.ff>maxR){
			maxR=-ranges[i].sc.ff;
			resp[ranges[i].sc.sc].sc=0;
		}
		else resp[ranges[i].sc.sc].sc=1;
	}
	for (auto i:resp) cout<<i.ff<<" ";
	cout<<endl;
	for (auto i:resp) cout<<i.sc<<" ";
	return 0;
}
