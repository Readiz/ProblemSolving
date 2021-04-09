print(int(input()) % 20000303)

# 아래처럼 decimal을 쓰면 빨라짐
# from decimal import Decimal, getcontext
# getcontext().prec = 1_000_007
# m = Decimal(input()) % Decimal(20000303)
# print(m)


# cpp 버전
# #include <cstdio>
# using namespace std;
# const int MOD = 20000303;

# int main(){
# 	int result = 0;
# 	while(1){
# 		char c = getchar();
# 		if(c < 0 || c == '\n') break;
# 		result = (result*10%MOD + c-'0') % MOD;
# 	}
# 	printf("%d\n", result);
# }