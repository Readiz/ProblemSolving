#include <bits/stdc++.h>
using namespace std;

struct Info {
    int score;
    int id;
    bool operator<(const Info& t) const {
        if (score != t.score) return score > t.score;
        return id < t.id;
    }
} info[100];

int basescore[100];
char buf[2];
int main() {
    int N, M; scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i) {
        scanf("%d",&basescore[i]);
    }
    for(int i=0;i<M;++i) {
        scanf("%d",&info[i].id);
        for(int j=0;j<N;++j) {
            scanf("%s", buf);
            if (buf[0]=='O') {
                info[i].score+=basescore[j];
            }
        }
    }
    sort(info, info+M);
    printf("%d %d\n",info[0].id,info[0].score);

    return 0;
}