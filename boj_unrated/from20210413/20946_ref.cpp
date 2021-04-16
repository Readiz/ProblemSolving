// 구사과님 풀이..
// https://www.acmicpc.net/source/26846418
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<llf, llf>;
const int MAXN = 2505;
const int mod = 998244353;

/*
int n, k;
llf p[MAXN], dp[11][MAXN];
llf cost[MAXN][MAXN];

int main(){
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++){
		llf alive = 1, sum = 0;
		for(int j = i; j <= n; j++){
			alive *= 1 - p[j];
			sum += alive;
			cost[i][j] = sum;
		}
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			for(int l = 0; l < j; l++) dp[i][j] = max(dp[i][j], dp[i-1][l] + cost[l+1][j]);
		}
	}
	printf("%.10Lf\n", dp[k][n]);
}*/
namespace miller_rabin{
    lint mul(lint x, lint y, lint mod){ return (__int128) x * y % mod; }
	lint ipow(lint x, lint y, lint p){
		lint ret = 1, piv = x % p;
		while(y){
			if(y&1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(lint x, lint a){
		if(x % a == 0) return 0;
		lint d = x - 1;
		while(1){
			lint tmp = ipow(a, d, x);
			if(d&1) return (tmp != 1 && tmp != x-1);
			else if(tmp == x-1) return 0;
			d >>= 1;
		}
	}
	bool isprime(lint x){
		for(auto &i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
			if(x == i) return 1;
			if(x > 40 && miller_rabin(x, i)) return 0;
		}
		if(x <= 40) return 0;
		return 1;
	}
}

namespace pollard_rho{
	lint f(lint x, lint n, lint c){
		return (c + miller_rabin::mul(x, x, n)) % n;
	}
	void rec(lint n, vector<lint> &v){
		if(n == 1) return;
		if(n % 2 == 0){
			v.push_back(2);
			rec(n/2, v);
			return;
		}
		if(miller_rabin::isprime(n)){
			v.push_back(n);
			return;
		}
		lint a, b, c;
		while(1){
			a = rand() % (n-2) + 2;
			b = a;
			c = rand() % 20 + 1;
			do{
				a = f(a, n, c);
				b = f(f(b, n, c), n, c);
			}while(gcd(abs(a-b), n) == 1);
			if(a != b) break;
		}
		lint x = gcd(abs(a-b), n);
		rec(x, v);
		rec(n/x, v);
	}
	vector<lint> factorize(lint n){
		vector<lint> ret;
		rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
};



int main(){
	lint n;
	cin >> n;
	auto x = pollard_rho::factorize(n);
	if(sz(x) <= 1) cout << -1 << endl;
	else{
		if(sz(x) % 2){
			x[sz(x) - 2] *= x.back();
			x.pop_back();
		}
		for(int i = 0; i < sz(x); i += 2) printf("%lld ", x[i] * x[i+1]);
	}
}
