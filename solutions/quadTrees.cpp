#include <bits/stdc++.h>
using namespace std;
const int M = 2000;
char tree1[M], tree2[M];
int T,pos1,pos2;
int value(int tree,int pixels){
	if(tree==1){
		pos1++;
		if(tree1[pos1]=='p')
			return value(1,pixels/4)+value(1,pixels/4)+value(1,pixels/4)+value(1,pixels/4);
		else if(tree1[pos1]=='f')
			return pixels;
		else
			return 0;
	}
	else{
		pos2++;
		if(tree2[pos2]=='p')
			return value(1,pixels/4)+value(1,pixels/4)+value(1,pixels/4)+value(1,pixels/4);
		else if(tree2[pos2]=='f')
			return pixels;
		else
			return 0;
	}
}
int calc(int val){
	if(tree1[pos1]=='f' || tree2[pos2]=='f'){
		pos1++;
		pos2++;
		return val;
	}
	if (tree1[pos1]=='p' && tree2[pos2]=='e'){
		pos2++;
		return value(1,val/4)+value(1,val/4)+value(1,val/4)+value(1,val/4);
	}
	if (tree1[pos1]=='e' && tree2[pos2]=='p'){
		pos1++;
		return value(2,val/4)+value(2,val/4)+value(2,val/4)+value(2,val/4);
	}
	if (tree1[pos1]=='p' && tree2[pos2]=='p'){
		pos1++;
		pos2++;
		return calc(val/4)+calc(val/4)+calc(val/4)+calc(val/4);
	}
	if(tree1[pos1]=='e' && tree2[pos2]=='e'){
		pos1++;
		pos2++;
		return 0;
	}
} 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s", tree1);
		scanf("%s", tree2);
		pos1 = 0;
		pos2 = 0;
		 printf("There are %d black pixels.\n",calc(1024));
	}
	return 0;
}