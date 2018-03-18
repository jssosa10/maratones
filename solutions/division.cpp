#include <bits/stdc++.h>
using namespace std;
int n, act, res;
int main(){
	while(scanf("%d",&n)==1&&n){
		res = 0;
		while(scanf("%d",&act)==1&& act){
			res = __gcd(res,act-n);
		}
		printf("%d\n",res);
	}
	return 0;
}