#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
bool isDebug = false;
#else
bool isDebug = true;
#endif

typedef long long ll;
typedef unsigned long long ull;


struct Division {
    int idx[100];
    int cnt;
    int chkCnt;
} d[25];

unsigned int seed = 5;
int prand() {
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

int gans[100];
char buf[10];
int gq;
int N, D, Q;
void printCurrent() {
    int ans[100] = {0};
    // memset(ans, 0xFF, sizeof(int) * 100);
    for(int div = 0; div < D; ++div) {
        for(int i = 0; i < d[div].cnt; ++i) {
            ans[d[div].idx[i]] = div;
        }
    }
    for(int i = 0; i < N; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}
void printDebug() {
    ll sum[25] = {0, };
    for(int div = 0; div < D; ++div) {
        for(int i = 0; i < d[div].cnt; ++i) {
            sum[div] += gans[d[div].idx[i]];
        }
    }
    printf("#");
    for(int i = 0; i < D; ++i) {
        printf("%lld(div: %d) ", sum[i], i);
    }
    printf("\n");
}
void printEnding() {
    printf("#");
    ll sum[25] = {0, };
    ll sumAll = 0;
    for(int div = 0; div < D; ++div) {
        for(int i = 0; i < d[div].cnt; ++i) {
            sum[div] += gans[d[div].idx[i]];
            sumAll += gans[d[div].idx[i]];
        }
    }
    double mean = (double)sumAll / D;
    double std = 0;
    for(int div = 0; div < D; ++div) {
        std += ((double)sum[div] - mean) * ((double)sum[div] - mean);
    }
    std /= D;

    printf("%lld\n", 1+(ll)round(100 * sqrt(std)));
}
// 1: <, -1: >, 0: =
int query(int cnta, int cntb, int a[], int b[]) {
    ++gq;
    if (isDebug) {
        printf("#c ");
        printCurrent();
        printDebug();
    }

    int ma[100], mb[100];
    memcpy(ma, a, sizeof(int) * cnta);
    memcpy(mb, b, sizeof(int) * cntb);
    sort(ma, ma + cnta);
    sort(mb, mb + cntb);
    printf("%d %d ", cnta, cntb);
    for(int i = 0; i < cnta; ++i) printf("%d ", ma[i]);
    for(int i = 0; i < cntb; ++i) printf("%d ", mb[i]);
    printf("\n");
    fflush(stdout);
    if (isDebug == false) {
        scanf("%s", buf);
        if (buf[0] == '=') return 0;
        else if (buf[0] == '<') return 1;
        return -1;
    } else {
        ll suma = 0, sumb = 0;
        for(int i = 0; i < cnta; ++i) {
            suma += gans[a[i]];
        }
        for(int i = 0; i < cntb; ++i) {
            sumb += gans[b[i]];
        }
        if (suma == sumb) return 0;
        else if (suma < sumb) return 1;
        return -1;
    }

}
int query(Division& a, Division& b) {
    a.chkCnt++;
    b.chkCnt++;
    return query(a.cnt, b.cnt, a.idx, b.idx);
}

int getMinChk() {
    int minchk = 987654321;
    int ret = -1;
    for(int i = 0; i < D; ++i) {
        if (d[i].chkCnt < minchk) {
            minchk = d[i].chkCnt;
            ret = i;
        }
    }
    return ret;
}

int main() {
    scanf("%d %d %d", &N, &D, &Q);
    fflush(stdout);

    if (isDebug) {
        for(int i = 0; i < N; ++i) {
            scanf("%d", &gans[i]);
        }
    }

    // 1. 대강 큰거를 모아둔다.
    int isSpecialNode[100] = {0, };
    vector<int> specialNodes;

    if (Q >= 6 * N) { // 쿼리 개수가 충분히 많다.
        // 쿼리 소모 예상: xxx
        int smallNodesCnt = D * 2;
        for(int k = 0; k < smallNodesCnt; ++k) { // 가능한 최대값을 찾는다. 최대 4번 돌아봄.
            int lastidx = -1;
            int cidx = prand() % N;
            while(isSpecialNode[cidx] == 1) cidx = prand() % N;

            for(int l = 0; l < 4; ++l) { // 세번정도 바꿔가며..
                int nidx = prand() % N;
                while(cidx == nidx || isSpecialNode[nidx] == 1) nidx = prand() % N;

                if (cidx > nidx) swap(cidx, nidx);
                int left[1] = {cidx};
                int right[1] = {nidx};
                int ret = query(1, 1, left, right);
                if (ret == 1) {
                    lastidx = cidx;
                    cidx = nidx; // 더 큰애를 찾았으니 바꿔준다.
                }
            }
            isSpecialNode[cidx] = 1;
            specialNodes.push_back(cidx);
            if (lastidx != -1 && k + 1 < smallNodesCnt) {
                isSpecialNode[lastidx] = 1;
                specialNodes.push_back(lastidx);
                ++k;
            }
        }

        if (isDebug) printf("# specialNodes Cnt: %d\n", (int)specialNodes.size());

        // 큰 녀석들을 뿌린다. 분산하는 느낌
        // for(int i = 0; specialNodes.size(); ++i) {
        //     int div2 = i % D;
        //     d[div2].idx[d[div2].cnt++] = specialNodes.back();
        //     specialNodes.pop_back();
        // }
        for(int i = 0; i < D; ++i) {
            int div2 = i % D;
            d[div2].idx[d[div2].cnt++] = specialNodes.back();
            specialNodes.pop_back();
        }
        for(int i = D - 1; i >= 0; --i) {
            int div2 = i % D;
            d[div2].idx[d[div2].cnt++] = specialNodes.back();
            specialNodes.pop_back();
        }
    }

    // if (isDebug) {
    //     // printf("#c "); printCurrent();
    //     int ta[1] = {0};
    //     int tb[1] = {1};
    //     query(1, 1, ta, tb);
    // }

    for (int i = 0, j = 0; i < N; ++i) {
        int div = j % D;
        if (isSpecialNode[i]) {
            // 넣지 않는다.
        } else {
            d[div].idx[d[div].cnt++] = i;
            ++j;
        }
    }


    for(; gq < Q;) {
        int div1 = getMinChk();
        while(d[div1].cnt == 0) div1 = prand() % D;
        int div2 = prand() % D;
        while(d[div2].cnt == 0 || div1 == div2) div2 = prand() % D;

        int ret = query(d[div1], d[div2]);
        if (ret == 0) {
            // do nothing
            continue;
        } else if (ret == 1) {
            swap(div1, div2);
            // swap 후 size 순서: div1 > div2
        }

        int selected[25] = {0, };
        selected[div1] = 1;
        selected[div2] = 1;

        if (D >= 4) { 
            // 여유가 많으면 div를 더 많이 찾아보자
            int blockSelCnt = (int)(((double)D / 4)*2.0);
            for(int k = 0; gq < Q && k < blockSelCnt; ++k) { // D == 20 -> 5번까지 찾음
                int div3 = prand() % D;
                while (d[div3].cnt == 0 || selected[div3] == 1) div3 = prand() % D;
                selected[div3] = 1;
                
                int ret = query(d[div2], d[div3]);
                if (ret == -1) { // 순서: div1 > div2 > div3
                    // 새로 찾은게 제일 작다.
                    swap(div2, div3);
                } else if (ret == 1 && gq < Q) {
                    // div1 > div2  //  div3 > div2 인 상황
                    // 새로 찾은거랑 div1 이랑 다시 비교해본다.
                    ret = query(d[div1], d[div3]);
                    if (ret == -1) {
                        // do nothing
                    } else if (ret == 1) {
                        swap(div1, div3); // div3가 제일 큰 상황 -> div3를 div1에 넣어줌
                    }
                }
            }
        }


        double progress = (double)gq / Q * 100;
        if (false && progress >= 90.0) {
            // humm... maybe we can do final jobs
            // div2: 제일 작은 바구니
            // 여기에 speicalNode를 넣어준다.
            // d[div2].idx[d[div2].cnt++] = specialNodes.back();
            // specialNodes.pop_back();
        } else {
            // 원소 교환 start -> div1, 2의 대소가 바뀔 때까지 반복한다.
            for(int internalLoopCnt = 0; gq < Q; ++internalLoopCnt) {
                double progress = (double)gq / Q * 100;
                if (d[div1].cnt == 1) break;
                if (progress >= 80.0 && d[div1].cnt <= 3) break; // 미세조정을 해야할 때

                int idx1 = prand() % d[div1].cnt;

                int numVisited[100] = {0, };
                numVisited[idx1] = 1;

                // if (D < 4 && d[div1].cnt > 1) {
                int loopcnt;
                if (progress <= 90.0) loopcnt = min(3, d[div1].cnt - 1); // -1: 이미 하나 선택했음
                else loopcnt = min(10, d[div1].cnt - 1); // -1: 이미 하나 선택했음
                for(int k = 0; gq < Q && k < loopcnt; ++k) { // 가능한 최소값을 찾는다. 최대 4번 돌아봄.
                    int nidx = prand() % d[div1].cnt;
                    // printf("c: %d\n", nidx);
                    while(numVisited[nidx] == 1) {
                        nidx = prand() % d[div1].cnt;
                        // printf("nc: %d\n", nidx);
                    }
                    numVisited[nidx] = 1;

                    if (d[div1].idx[nidx] < d[div1].idx[idx1]) swap(idx1, nidx);
                    assert(d[div1].idx[idx1] < d[div1].idx[nidx]);
                    int left[1] = {d[div1].idx[idx1]};
                    int right[1] = {d[div1].idx[nidx]};
                    int ret = query(1, 1, left, right);
                    if (ret == -1) idx1 = nidx; // 더 작은애를 찾았으니 바꿔준다.
                }
                // }

                int idx2 = prand() % d[div2].cnt;
                int v1 = d[div1].idx[idx1];
                int v2 = d[div2].idx[idx2];
                d[div1].idx[idx1] = d[div1].idx[d[div1].cnt - 1];
                d[div1].cnt--;
                d[div2].idx[idx2] = v1;
                d[div2].idx[d[div2].cnt] = v2;
                d[div2].cnt++;

                if (internalLoopCnt >= 1) break;

                // div check
                if (D >= 4 && gq + 10 < Q && d[div1].cnt && d[div2].cnt) {
                    int ret = query(d[div1], d[div2]);
                    if (ret == -1) {
                        // do nothing
                        // 아직 안바뀌었으므로 계속 하면 된다
                    } else { // 바뀌었으면 그만
                        break;
                    }
                } else {
                    break;
                }
            }
        }
    }


    int chkcnt = 0;
    for(int div = 0; div < D; ++div) {
        for(int i = 0; i < d[div].cnt; ++i) {
            ++chkcnt;
        }
    }
    assert(N == chkcnt);
    assert(gq == Q);
    printCurrent();
    if (isDebug) printEnding();
    

    return 0;
}








/*
#!/bin/bash
ans=0
for num in $(seq -w 0000 1000); do
    ../A_Balancing_by_Balance < ../input/$num.txt > ../output/$num.txt
    line=$(tail -n 1 ../output/$num.txt) > /dev/null
    line="${line:1}"
    ans=$(($ans+$line))
    echo "$num: $line"
done
echo "Overall Score: $ans"
*/