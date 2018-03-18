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
char lets[1000005],copie[1000005],emptys[1000005];
bool elimina[1000005];
int main(){
	scanf("%s",lets);
	int res = 0;
	while(true){
		for(int i=1;lets[i]; i++ ){
			if(lets[i-1]!=lets[i])
				elimina[i-1]=elimina[i]=true;
		}
		int j = 0;
		bool elem = true;
		for(int i = 0; lets[i]; i++){
			if(!elimina[i]){
				copie[j]=lets[i];
				j++;
			}
			elem = elem && !elimina[i];
			elimina[i] = false;
		}
		if(elem){
			break;
		}
		else{
			res++;
			strcpy(lets,copie);
			strcpy(copie,emptys);
		}
	}
	printf("%d\n",res);

	return 0;
}

