#include<bits/stdc++.h>
using namespace std;
int h,m;
int main(){
 while(scanf("%d :%d",&h,&m)==2&&h+m){
  double res =0;int hs=(30*h+m*6)%360,mins=m*6;
  printf("%.3f\n",(double)360-abs(hs-mins));

}
return 0;
}