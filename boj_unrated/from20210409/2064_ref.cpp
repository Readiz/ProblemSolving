// from https://www.acmicpc.net/source/71522
#include<cstdio>
#define B(X) ((X)&(0xFF))
typedef unsigned u;
int main(){
	u N,Lb=(1LL<<32)-1,Ub=0,Mask;
	scanf("%u",&N);
	for(int i=0;i<N;i++){
		u a,b,c,d,now;
		scanf("%u.%u.%u.%u",&a,&b,&c,&d);
		now=(a<<24)|(b<<16)|(c<<8)|d;
		Ub=now>Ub?now:Ub;
		Lb=now<Lb?now:Lb;
	}for(u i=0;i<=32;i++){
		Mask=((1LL<<32)-1)^((1LL<<i)-1);
		if((Mask&Ub)==(Mask&Lb))break;
	}Lb&=Mask;
	printf("%u.%u.%u.%u\n%u.%u.%u.%u",B(Lb>>24),B(Lb>>16),B(Lb>>8),B(Lb),B(Mask>>24),B(Mask>>16),B(Mask>>8),B(Mask));
	return 0;
}