#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using base = complex <ld>;

const ld pi = acos(-1);

string A, B, C;
vector <ll> X, Y, Z;
ll n, m, ans;

void fft(vector <base> &A, bool f)
{
	int k = A.size(), i, j, l, t;
	base w, x, y; ld th;

	for(i = 1, j = 0; i < k; i ++){
		for(l = k >> 1; j >= l; l >>= 1) j -= l;
		j += l; if(i < j) swap(A[i], A[j]);
	}

	for(i = 1; i < k; i <<= 1, t --){
		th = (f? -pi : pi) / i;
		w = base(cos(th), sin(th));
		for(j = 0; j < k; j += i + i){
			for(l = 0; l < i; l ++){
				if(l & 2047) x *= w;
				else x = l? base(cos(th * l), sin(th * l)) : 1;
				y = x * A[l | i | j];
				A[l | i | j] = A[l | j] - y;
				A[l | j] += y;
			}
		}
	}

	if(f) for(i = 0; i < k; i ++){
		A[i] /= k;
	}
}

vector <ll> mult(vector <ll> &X, vector <ll> &Y)
{
	ll s, i, j;

	for(s = 1; s < X.size() + Y.size(); s <<= 1);
	
	vector <base> P(s), Q(s);
	vector <ll> Z(X.size() + Y.size() - 1);

	for(i = 0; i < X.size(); i ++){
		P[i] = base(X[i] >> 12, X[i] & 4095);
	}
	for(i = 0; i < Y.size(); i ++){
		Q[i] = base(Y[i] >> 12, Y[i] & 4095);
	}
	fft(P, 0); fft(Q, 0);

	for(i = 0; i + i <= s; i ++){
		j = i? s - i : 0;
		base v1 = P[i] + conj(P[j]), v2 = conj(P[i]) - P[j];
		tie(P[i], Q[i], P[j], Q[j]) = make_tuple(
			v1 * Q[i], conj(v2) * conj(Q[j]),
			conj(v1) * Q[j], -v2 * conj(Q[i]));
	}
	fft(P, 1); fft(Q, 1);

	for(i = 0; i < Z.size(); i ++){
		Z[i] = (((ll)round(P[i].real()) << 23) + ((ll)round(Q[i].real()) >> 1)
			+ ((ll)round(P[i].imag() + Q[i].imag()) << 11));
	}

	return Z;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll i, j, s, t;

	for(i = 0; i < 2; i ++){
		cin >> A;

		if(A == "0"){
			cout << "0\n";
			return 0;
		}

		reverse(A.begin(), A.end());

		for(j = 0, s = 0, t = 1; j < A.size(); j ++){
			s += (A[j] - '0') * t;
			if(j % 7 == 6 || j + 1 == A.size()){
				X.push_back(s); s = 0; t = 1;
			}
			else t *= 10;
		}
		swap(A, B); swap(X, Y);
	}

	Z = mult(X, Y);

	for(i = 0; i + 1 < Z.size(); i ++){
		if(Z[i] >= 1e7){
			Z[i + 1] += Z[i] / (ll)1e7;
			Z[i] %= (ll)1e7;
		}
		for(j = 0; j < 7; j ++){
			C.push_back('0' + Z[i] % 10);
			Z[i] /= 10;
		}
	}

	for(; Z[i]; ){
		C.push_back('0' + Z[i] % 10);
		Z[i] /= 10;
	}

	reverse(C.begin(), C.end());

	cout << C << "\n";

	return 0;
}