#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
	while(scanf("%d",&N)==1&&N!=0){
		int res = 1;
		int nn = 2;
		while(nn!=1){
			if(nn<=N/2){
				nn*=2;
			}
			else{
				nn=(nn-(N/2)-1)*2+1;
			}
			res++;
		}
		printf("%d\n",res);
	}
}