#include <bits/stdc++.h>
using namespace std;
const double pi = 4*atan(1);
double angle(double x1, double y1, double x2, double y2){
	double dot = x1*x2+y1*y2;
	double dist = sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2);
	return acos(dot/dist);
} 
int T,k;
int main(){
	scanf("%d",&T);
	while(T--){
		double ax,ay,bx,by,cx,cy;
		scanf("%d %lf %lf %lf %lf %lf %lf",&k,&ax,&ay,&bx,&by,&cx,&cy);
		double ta = angle(bx-ax,by-ay,cx-ax,cy-ay);
		double tb = angle(cx-bx,cy-by,ax-bx,ay-by);
		double tc = angle(ax-cx,ay-cy,bx-cx,by-cy);
		double om = sin(ta)*sin(tb)*sin(tc);
		om = om/(1+cos(ta)*cos(tb)*cos(tc));
		om = atan(om);
		double abx = cos(om)*(bx-ax)-sin(om)*(by-ay);
		double aby = sin(om)*(bx-ax)+cos(om)*(by-ay);
		double bcx = cos(om)*(cx-bx)-sin(om)*(cy-by);
		double bcy = sin(om)*(cx-bx)+cos(om)*(cy-by);
		double px = ((ay-ax*aby/abx)-(by-bx*bcy/bcx));
		px = px/(bcy/bcx-aby/abx);
		double py = aby*(px-ax)/abx+ay;
		printf("%d %.5f %.5f\n",k,px,py);

	}
	return 0;
}