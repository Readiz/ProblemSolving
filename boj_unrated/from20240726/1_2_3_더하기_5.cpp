#include <stdio.h>
#include <memory.h>

const long long MOD = 1'000'000'009;
long long dp[100'010][3]; // 마지막 숫자 1, 2, 3일때 k가 되는 경우의 수

void doSolve() {
    int N=100'000;
    for(int i=0;i<=N;++i) dp[i][0]=dp[i][1]=dp[i][2]=0;
    dp[1][0]=1;
    dp[2][1]=1;dp[2][0]=0;
    dp[3][0]=1;dp[3][1]=1;dp[3][2]=1;
    for(int i=4;i<=N;++i) {
        for(int j=0;j<3;++j) {
            int c=j+1, a=(j+1)%3+1, b=(j+2)%3+1;
            if(i-c>=0){
                dp[i][j]+=dp[i-c][a-1];
                dp[i][j]+=dp[i-c][b-1];
            }
            dp[i][j]%=MOD;
        }
    }
}

int main() {
    int TC; scanf("%d", &TC);
    doSolve();
    while(TC--) {
        int N; scanf("%d", &N);
        printf("%lld\n",(dp[N][1]+dp[N][2]+dp[N][0])%MOD);
    }
    return 0;
}