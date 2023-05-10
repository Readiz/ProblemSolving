#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>
using namespace std;
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define R register
typedef unsigned long long ull;
typedef long long ll;

vector<int> s[200001];
vector<ull> sumBack[200001];
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int n;
        scanf("%d", &n);
        int u[200001];
        int numStudents[200001] = {0, };
        ull sum[200001];
        unordered_set<int> univIdx;
        for (R int i = 1; i <= n; i++) {
            scanf("%d", &u[i]); // 소속팀
            numStudents[u[i]]++;
            sum[u[i]] = 0ULL;
            univIdx.insert(u[i]);
            s[u[i]].clear();
            sumBack[u[i]].clear();
        }
        for (R int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d", &tmp);
            sum[u[i]] += (ull)tmp;
            s[u[i]].push_back(tmp); // 소속팀 vector에 넣는다.
        }
        for (const auto& i: univIdx) {
            printd("University #%d has students... sorting...", i);
            sort(s[i].begin(), s[i].end(), greater<>());
            ull curSum = 0ULL;
            for (auto itr = s[i].rbegin(); itr < s[i].rend(); itr++) {
                curSum += *itr;
                sumBack[i].push_back(curSum);
            }
            if (isDebug) {
                printf("[DEBUG] skills: ");
                for (const auto& e: s[i]) {
                    printf("%d ", e);
                }
                printf("\n");
                printf("[DEBUG] sums: ");
                for (const auto& e: sumBack[i]) {
                    printf("%llu ", e);
                }
                printf("\n");
            }
        }
        bool skipFlag[200001] = {false, };
        bool overallSkipFlag = false;
        for (R int k = 1; k <= n; k++) {
            ull overallSum = 0ULL;
            printd("K: %d case...", k);

            if (!overallSkipFlag) {
                for (const auto& i: univIdx) {
                    if (skipFlag[i]) continue;
                    ull currentSum = sum[i]; // 전체 sum으로 시작
                    int curNumStudents = numStudents[i];
                    int deleteTailNum = curNumStudents % k;
                    if (deleteTailNum == curNumStudents) {
                        currentSum = 0ULL;
                    } else {
                        if (deleteTailNum >= 1) {
                            currentSum -= sumBack[i][deleteTailNum - 1];
                        }
                    }
                    printd("Sum for Unversity #%d: %llu (deleteTailNum: %d)", i, currentSum, deleteTailNum);
                    if (currentSum == 0ULL) skipFlag[i] = true;
                    overallSum += currentSum;
                }
                printd("overallSum: %llu", overallSum);
                if (overallSum == 0ULL) overallSkipFlag = true;
                printf("%llu ", overallSum);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
MAIN_END
