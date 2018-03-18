/*
 * I won't be broken
 * I won't be tortured
 * I won't be beaten down
 * I have the answer
 * I can take the pressure
 * I will turn it all around
 * Lift me up above this
 * The flames and the ashes
 * Lift me up and help me to fly away
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007 
int T;
double d,l,t;
long long gcd(long  a, long long  b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}
long long mod(long long x){
 return (MOD+(x%MOD))%MOD;
}
long long powmod(long long a, long long p){
	if(p==1LL){
		return mod(a);
	}
	else{
		if(p%2==0){
			long long x = mod(powmod(a,p/2));
			return mod(x*x);
		}
		else{
			long long x = mod(powmod(a,p-1));
			return mod(x*mod(a));
		}
	}
}
long long inversemod(long long a,long long m){
	long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        long long q = a / m;
        long long t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
    return x;
}
long long deno, nume;
double inte;
void toFrac(double input)
{
    inte = floor(input);
    double frac = input - inte;
   // printf("%.3f %.3f\n",inte,frac);
    long long prec = 10000000000;
    long long  gcd_ = gcd((frac*prec), prec);
    printf("%lld\n",gcd_);
    deno = prec / gcd_;
    printf("%lld\n",deno);
    nume = round(frac * prec) / gcd_;

}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf",&l,&d,&t);
		double ang = acos(d/l);
		double css = cos(t*ang)*l;
		//printf("%.3f\n",css);
		toFrac(css);
		inte = inte*deno+nume;
		long long u = (long long)inte;
		long long de = (long long) deno;
		printf("%lld/%lld\n",u,de);
		long long inv = inversemod(de,MOD);
		printf("%lld %lld\n",inv,u);
		//printf("%lld\n",mod(inv)*mod(u));
		long long r = mod(mod(inv)*mod(u));
		printf("%lld\n",r);
	}

	return 0;
}
