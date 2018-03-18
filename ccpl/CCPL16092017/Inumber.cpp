#include <bits/stdc++.h>
using namespace std;
int T, num, falta;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&num);
		int act = num;
		int suma = 0;
		while(act>=10){
			suma += act%10;
			act/=10;
		}
		suma += act

	}
	return 0;
}