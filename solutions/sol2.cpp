#include <bits/stdc++.h>
using namespace std;
const int M = 1000005;
int n,l[M];
int main(){
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		scanf("%d",&l[i]);
	}
	int res = 1;
	int  mmin;
	if((n-1-l[n-1])>0)
		mmin = n-1-l[n-1];
	else
		mmin = 0;
	for(int i = n-2; i>=0; i--){
		if(i<mmin)
			res++;
		int mm;
		if((i-l[i])>0)
			mm = i-l[i];
		else
			mm = 0;
		mmin= min(mmin,mm);

	}
	printf("%d\n",res);
	return 0;


}