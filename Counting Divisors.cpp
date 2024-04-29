#include <bits/stdc++.h>
using namespace std;
int main(){
	int q; cin>>q;
	
	while (q--)
{		int n;
	cin>>n;
	int mid=sqrt(n);
	if (mid*mid!=n) mid++;
	int total=0;
	for (int i=1;i<mid;i++){
		if (n%i==0) total++;
	}
	total*=2;
	if (mid*mid==n) total++;
	cout<<total<<endl;
}
}
