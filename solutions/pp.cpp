#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
	point(double xx=0,double yy=0):x(xx),y(yy){}
	double operator -(const point &p)const{
		return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
	}
};
double dis(point a, point b, point c){
	return fabs((c.y-a.y)*b.x+(a.x-c.x)*b.y+(c.x*a.y-a.x*c.y))/(a-c);
}
double calc(point a, point b, point c){
	double ret = dis(a,b,c)/2;
	ret=min(ret,(a-c)/2);
	return ret;
}
point pt[1005];
int n;
int main(){
	while(scanf("%d",&n)==1){
		for(int i = 0; i<n;i++)
			scanf("%lf%lf",&pt[i].x,&pt[i].y);
		double ans = calc(pt[0],pt[1],pt[2]);
		for(int i=1;i<n;i++)
			ans=min(ans,calc(pt[i],pt[(i+1)%n],pt[(i+2)%n]));
		printf("%.10f\n",ans );
	}
	return 0;
}