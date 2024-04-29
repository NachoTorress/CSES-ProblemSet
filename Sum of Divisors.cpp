#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long getTotal(int n)
{
	long long total=0;
	for (int i=1;i<=n;i++){
		if (n%i==0) {
			total=(total+i)%MOD;
		}
	}
	return total;
}int main(){
	int n; cin>>n;
	long long total=0;
	for (int i=1;i<=n;i++) total+=getTotal(i);
	cout<<total;
}
