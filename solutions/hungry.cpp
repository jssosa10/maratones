#include <bits/stdc++.h>
using namespace std;
int n,x;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		bool t = false;
		bool t2 = false;
		for (int i = 0; i < 35&&!t&&!t2; ++i) {
			if((x-3*i)%7==0)
				t=true;
			if(3*i>x)
				t2=true;
		}
		if(t)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

