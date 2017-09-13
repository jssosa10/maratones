#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
	//FILE *f = fopen("file.txt", "w");
	while(scanf("%s",s)==1){
		if (s[0]=='0'&&strlen(s)==1)break;
		int l = strlen(s);
		int p,imp;
		p=imp=0;
		bool par=false;
		for (int i = l-1; i >= 0; i--){
			if(par)
				p+=(s[i]-'0');
			else
				imp+=(s[i]-'0');
			par = !par;
		}
		if((p-imp)==0 || ((p-imp)%11)==0){
			printf("%s is a multiple of 11.\n",s);
			//fprintf(f,"%s is a multiple of 11.\n",s);
		}
		else{
			printf("%s is not a multiple of 11.\n",s);
			//fprintf(f,"%s is not a multiple of 11.\n",s);
		}
	}
	//fclose(f);
	return 0;
}