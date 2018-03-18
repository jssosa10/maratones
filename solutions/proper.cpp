#include <bits/stdc++.h>
using namespace std;
long long n,a,b;
long long gcd(long long a,long long  b,long long &x, long long &y){
	if(a==0)
	{
		x=0;y=1;
		return b;
	}
	long long x1,y1;
	long long d = gcd(b%a,a,x1,y1);
	x= y1 -(b/a)*x1;
	y= x1;
	return d;
}
bool findsol(long long a , long long b, long long c, long long &x0,long long &y0,long long &g){
	g = gcd (a , b , x0, y0 ) ;
	if ( c % g != 0 )
		return false ;
	x0 *= c / g ;
	y0 *= c / g ;
	return true ;
}
int main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	long long x0,y0,g;
	if(findsol(a,b,n,x0,y0,g)){
		if(x0>=0&&y0>=0)
			printf("YES\n%lld %lld\n",x0,y0 );
		else{
			//printf("YES\n%d %d\n",x0,y0 );
		//	printf("%d %d\n",x0,y0);

			if(x0<0&&y0>0){
				while(y0>=0){
					y0-=(a/g);
					x0+=(b/g);

					if(x0>=0&&y0>=0){
							
						printf("YES\n%lld %lld\n",x0,y0 );
						break;
					}
					//k++;

				}	
				if(y0<0)
					printf("NO\n");
			}
			else if(x0>0&&y0<0){
				while(x0>=0){
					y0+=(a/g);
					x0-=(b/g);
					if(x0>=0&&y0>=0){
							
						printf("YES\n%lld %lld\n",x0,y0 );
						break;
					}
					//k++;

				}	
				if(x0<0)
					printf("NO\n");
			
			}
			else if(x0<0&&y0<0)
				printf("YES\n%lld %lld\n",-x0,-y0 );
				
		}
	}
	else
		printf("NO\n");
	return 0;
}

