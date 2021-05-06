#include<bits/stdc++.h>
using namespace std;
#define endl	'\n'

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	const int MX=5e6;
	bitset<MX> P,Q;
	P.set(0),P.set(1);
	for(int i=2;i*i<MX;++i)if(!P[i])
		for(int j=i*i;j<MX;j+=i)P.set(j);
	int n;long long S[2]={};cin>>n;
	vector<int> T[2];
	while(n--){
		for(int i=0,a;i<2;++i){
			cin>>a;
			if(P[a]){
				if(T[!i].size()==3)S[!i]+=T[!i][2];
				else S[!i]+=1000;
			}else if(Q[a])S[i]-=1000;
			else{
				Q[a]=1;
				int k=0;
				auto&t=T[i];
				while(k<t.size()&&a<t[k])++k;
				if(k<3){
					t.insert(t.begin()+k,a);
					if(t.size()>3)t.pop_back();
				}
			}
		}
	}
	if(S[0]>S[1])puts("소수의 신 갓대웅");
	else if(S[0]<S[1])puts("소수 마스터 갓규성");
	else puts("우열을 가릴 수 없음");
	
	return 0;
}