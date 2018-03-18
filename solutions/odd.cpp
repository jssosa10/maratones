#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int M = 10005;
int uf[M];
int tam[M];
vector<int> g[M];
int find(int u) {
	return (u == uf[u]) ? u : find(uf[u]);
}
void unionf(int u, int v) {
	int fu = find(u), fv = find(v); 
	if (tam[fu] < tam[fv]) 
		swap(fu, fv); 
	tam[fu] += tam[fv]; 
	uf[fv] = fu;
}
// functions used to comunicate with the interactor (the other program)
// use this to get the position of the other player.
// after using it you must do your own move
// TL;DR GetEdge() GetEdge() is invalid
pair<int, int> GetEdge() {
    int a, b; 
    cin >> a >> b;
    return {a, b};
}

// use this to set your answer
void SetAnswer(int s) {
    cout << s << endl;
    if (s == 0) {
        exit(0);
    }
}
int especial(pair<int,int> p){
    if(find(p.first)!= find(p.second)){
		unionf(p.first,p.second);
		g[p.first].push_back(p.second);
		g[p.second].push_back(p.first);
		return 1;
    }
    else{
        unionf(p.first,p.second);
		g[p.first].push_back(p.second);
		g[p.second].push_back(p.first);
		queue<int>q;q.push(p.first);
		int color[M];
		memset(color,-1,sizeof(color));
		color[p.first]=0;
		bool isBi = true;
		while(!q.empty()&&isBi){
		    int u = q.front(); q.pop();
		    for(vector<int>::iterator it = g[u].begin(); it!=g[u].end();++it){
		        int act = *it;
		        if(color[act]==-1){
		            color[act]=1-color[u];
		            q.push(act);
		        }
		        else if(color[act]==color[u]){
		            isBi=false;
		            break;
		        }
		    }
		}
		if(isBi)return 1;
		else return 0;
    }
}


int main() {
    // use this to pass the first example
    int n; 
    cin >> n;
    int res = especial(GetEdge());
    while(res==1){
        SetAnswer(1);
        res = especial(GetEdge());
    }
    SetAnswer(0);
    return 0;
}