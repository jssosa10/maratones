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
int h,a[100005];
bool isperfect(){
	int ant=1;
	for(int i = 1; i<=h; i++){
		if(ant>1&&a[i]>1)
			return false;
		ant = a[i];
	}
	return true;
}

int main(){
	scanf("%d",&h);
	int sum = 0;
	for(int i = 0; i<=h; i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	bool p = isperfect();
	if(p)printf("perfect\n");
	else{

		printf("ambiguous\n");
		printf("0");
		int index = 1;
		for(int i =1; i<=h; i++ ){
			for(int j = 0; j<a[i]; j++){
				printf(" %d",index);
			}
			index+=a[i];
		}

		printf("\n");
		printf("0");
		index = 1;
		bool diff = false;
		for(int i = 1; i<=h; i++){
			if(a[i-1]==1||a[i]==1||diff){
				for(int j = 0; j<a[i];j++){
					printf(" %d",index);
				}
			}
			else{
				printf(" %d",index-1);
				for(int j = 0; j<a[i]-1;j++){
					printf(" %d",index);
				}
			}
			index+=a[i];
		}

		printf("\n");

	}
	return 0;
}

