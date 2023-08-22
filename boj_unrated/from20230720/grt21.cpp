#include <bits/stdc++.h>
using namespace std;
int main() {
	int N; scanf("%d", &N);
	char buf[110]; scanf("%s", buf);
	string full = buf;
    set<string> mlist;
    for(int i = 1; i < N - 1; ++i) {
        for(int j = i + 1; j < N; ++j) {
            string a = full.substr(0, i);
            string b = full.substr(i, j - i);
            string c = full.substr(j);
            mlist.insert(a);
            mlist.insert(b);
            mlist.insert(c);
        }
    }
    
    int maxidx = 0;
    for(int i = 1; i < N - 1; ++i) {
        for(int j = i + 1; j < N; ++j) {
            string a = full.substr(0, i);
            string b = full.substr(i, j - i);
            string c = full.substr(j);
            int aidx = distance(mlist.begin(), mlist.find(a)) + 1;
            int bidx = distance(mlist.begin(), mlist.find(b)) + 1;
            int cidx = distance(mlist.begin(), mlist.find(c)) + 1;
            if (aidx + bidx + cidx > maxidx) maxidx = aidx + bidx + cidx;
        }
    }
	
    printf("%d\n", maxidx);
    
	return 0;
}