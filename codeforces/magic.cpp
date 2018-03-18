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
int n;
int main(){
	scanf("%d",&n);
	set<pair<pair<int,int>,int> >s;
	for(int i = 1;i<=n; i++){
		for(int j = i; j<=n; j++){
			int c = i^j;
			if(i+j>c&&c>=j&&c<=n)
				s.insert({{i,j},c});

		}

	}
	printf("%d\n",s.size());
	return 0;
}

