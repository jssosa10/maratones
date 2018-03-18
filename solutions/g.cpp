#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	char mat[n][7];
	for(int i = 0; i<n; i++){
		scanf("%s",mat[i]);
	}
	int maxx = 0;
	for(int i = 0; i<7; i++){
		int res =0;
		for(int j = 0; j<n; j++){
			res += (mat[j][i]-'0');
		}
		maxx = max(res,maxx);
	}
	printf("%d\n",maxx);
	return 0;
}