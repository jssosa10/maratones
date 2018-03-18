#include <bits/stdc++.h>
using namespace std;
char s[105];
int n;
int main(){
    scanf("%d",&n);
    while(n--){
      memset(s,0,105);
      scanf("%s",s);
      int l = strlen(s);
      if(l>10)
      printf("%c%d%c\n",s[0],l-2,s[l-1]);
      else
      printf("%s\n",s);
    }
    return 0;
}