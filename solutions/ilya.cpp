#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
int val[MAX];
bool paso[MAX];
set<int> gcds[MAX];
int beauty[MAX];
vector<int> G[MAX];
int n,x,y,a;
void DFS(int i, set<int> g, int gcdc){
    paso[i]=true;
    for(set<int>::iterator itt = g.begin();itt != g.end(); ++itt){
        gcds[i].insert(__gcd(val[i],*itt));
    }
    //es cero se agrega al gcdc completo :V
    gcds[i].insert(gcdc);
    //no es cero luego se agrega el gcdc = __gcd(gcdc,val[i]);
     gcdc = __gcd(gcdc,val[i]);
    gcds[i].insert(gcdc);
    //se itera sobre los hijos
    for(vector<int>::iterator it = G[i].begin();it!=G[i].end();++it){
        if(!paso[*it])
        DFS(*it,gcds[i],gcdc);
    }
    beauty[i]=*gcds[i].rbegin();
   
}
int main(){
    memset(beauty,-1,MAX);
    scanf("%d",&n);
    a = n-1;
    for (int i = 1; i <= n; i++) {
        int act;
        scanf("%d",&act);
        val[i]=act;
    }
    while(a--){
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    DFS(1,gcds[1],0);
    for (int i = 1; i < n; i++) {
        int act = beauty[i];
        printf("%d ",act);
    }
    int act = beauty[n];
    printf("%d\n", act );
    return 0;
}