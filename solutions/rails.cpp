#include <bits/stdc++.h>
using namespace std;
const int MAX = 1002;
int N;
//UVA 514
stack<int> st;
int vals[MAX];
int val;
int main(){
    while(scanf("%d",&N) == 1 && N!=0){
        //cout<<'\n';
        st = stack<int>();
       
        while( scanf("%d",&val)==1&&val!=0){
            //printf("%d\n",val);
            vals[0]=val;
            for (int i = 1; i < N; i++) {
                 //printf("%d\n",val);
                scanf("%d",&val);
                vals[i]=val;
            }
            int pos = 0;
            for (int i = 1; i <= N; i++) {
               // printf("%d %d\n", i, vals[pos]);
                st.push(i);
                while(st.size()!=0&&st.top()==vals[pos]){
                    pos++;
                    int k = st.top();
                    st.pop();
                    //printf("%d\n",k);
                   // printf("%d\n",st.size());
                }
            }
            if(st.size()==0 || pos == N){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
            //scanf("%d",&val);
        }
        cout<<"\n";
       
     
    }
    return 0;
}