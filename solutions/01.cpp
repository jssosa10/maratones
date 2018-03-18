#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	int cnt = 0;
	for (int i = 0; i <str.length(); i++)
		if(str[i]=='0')
			cnt++;
	int i = 0,j=str.length()-1;
	double ans = 0;
	while(j>i){
		while(str[i]=='0'&&j>i)
			i++;
		while(str[j]=='1'&&j>i)j--;
		ans+=sqrt((double(j-i)));
		i++,j--;
	}
	printf("%.12f\n", ans);
	return 0;
}