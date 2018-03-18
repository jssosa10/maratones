/*
 * I won't be broken
 * I won't be tortured
 * I won't be beaten down
 * I have the answer
 * I can take the pressure
 * I will turn it all around
 * Lift me up above this
 * The flames and the ashes
 * Lift me up and help me to fly away
*/
#include <bits/stdc++.h>
using namespace std;
int n,c,d,s,a[1000],t[1000]={0};
int main(){
	scanf("%d",&n);
	for(int i  =0; i<n; i++)
		scanf("%d",a+i);
	scanf("%d%d%d",&c,&d,&s);
	int tt = d/s;
	t[0]=a[0];
	for(int i = 1; i<n; i++){
		t[i]=t[i-1]+a[i]+tt;	
	}
	//printf("%d\n",t[2]);
	int f = t[n-1];
	for(int i = 1; i<c; i++){
		t[0]+=a[0];
		for(int j = 1; j<n; j++){
			int te = t[j-1]+tt;
			if(te<t[j])
				t[j]+=a[j];
			else
				t[j]=te+a[j];
		}
		//printf("%d\n",t[1]);
	}
	int l = t[n-1];
	printf("%d\n",l-f);
	return 0;
}

