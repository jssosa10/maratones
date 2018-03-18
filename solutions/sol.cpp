#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
int n,a[M],b[M];
int main(){
	scanf("%d",&n);
	long long sum = 0;
	for(int  i =0; i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i = 0; i<n;i++){
		scanf("%d",&b[i]);
	}
	sort(b,b+n);
	long long bm = b[n-1]+b[n-2];
	if(sum<=bm)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}