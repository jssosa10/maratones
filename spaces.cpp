#include <bits/stdc++.h>
using namespace std;
string line;
int T,N;
int main(){
	cin>>T;
	for (int t = 1; t <=T; t++){
		if(t>1)cout<<endl;
		cin>>N;
		getchar();
		string s[N+2];
		for(int i= 0; i<N; i++){
			getline(cin,line);
			s[i].push_back(line[0]);
			for(int j = 1; j<line.size();j++){
				if(line[j-1]==' '&&line[j]==' ')
					continue;
				else
					s[i].push_back(line[j]);
			}
		}
		cout<<"Case "<<t<<":"<<endl;
		for(int i=0; i<N; i++){
			cout<<s[i]<<endl;
		}
	}
	return 0;

}