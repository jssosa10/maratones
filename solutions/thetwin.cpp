#include <bits/stdc++.h>
using namespace std;
int a[23] = {679,3879,6670,8547,8552,6663,
			7423, 4872,9740,5808,9447,560,
			4199,267,5135,2584,3344,1455,
			1460,3337,6128,9328,1};
int num[5013] = {1,229,7728,2069,4990,1182,
				8338,3409,2588,4676,5205,8420,
				6749,6107,1784,4701,3574,6252,
				4989,1032,8473,8155,2806};
int main(){
	for(int j =23; j<5013;j++){
		for (int i = 0; i < 23; i++){
			num[j]=(num[j]+num[j-1-i]*a[i])%10007;
		}
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int a;
		scanf("%d",&a);
		if(a%2 == 1)
			printf("0\n");
		else
			printf("%d\n",num[a/2]);
	}
	return 0;
}