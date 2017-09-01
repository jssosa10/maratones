#include <bits/stdc++.h>
using namespace std;
int vals[105];
int n,val,ct;
int main(){
    scanf("%d",&n);
    if(n%2 == 0){
        printf("No\n");
    }
    else{
        for(int i = 1; i<=n;i++){
            scanf("%d",&val);
            vals[i]=val;
        }
        if(vals[1]%2==0||vals[n]%2==0)printf("No\n");
        else{
          for (int i = 1; i < n; i = i+2) {
              if(vals[i]%2!=0 && vals[i+1]%2!=0){
                  ct++;
                  i--;
              }
          }
          ct++;
          if(ct%2==0){
              printf("No\n");
          }
          else printf("Yes\n");
        }
    }
    return 0;
}
