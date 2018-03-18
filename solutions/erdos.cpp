#include<bits/stdc++.h>
using namespace std;
//por mejorar
const int MAX = 200005;
vector<int> G[MAX];
int er[MAX];
int N,A,D,M,S,C,val,a;
void BFS(int ini){
    queue<int> q;
    q.push(ini);
    er[ini]=0;
    while(q.size()>0){
        val = q.front();
        q.pop();
        a = er[val];
        for(vector<int>::iterator it= G[val].begin(); it!=G[val].end(); ++it){
             if(er[*it]==-1){
                 int act = *it;
                 if(act <= N){
                     er[act]=a+1;
                     q.push(act);
                     S += a+1;
                     D++;
                     M = max(M,a+1);
                 }
                 else{
                     er[act] = a;
                     q.push(*it);
                 }
                 
             }
        }
       
        
    }
    
}
int main(){
    D = 1;
    M = 0;
    S = 0;
    memset(er,-1,MAX-1);
    scanf("%d %d",&A,&N);
    while(A--){
        scanf("%d",&C);
        for (int i = 0; i < C; i++) {
            scanf("%d",&val);
             G[A+N+1].push_back(val);
             G[val].push_back(A+N+1);
        }
               
        
    }
    BFS(1);
    if(G[1].size()==0){
        D = 0;
    }
    printf("%d %d %d\n",D,M,S);
    return 0;
}