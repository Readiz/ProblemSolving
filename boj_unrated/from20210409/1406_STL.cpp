#include <stdio.h>
#include <string>
#include <list>
 
using namespace std;
 
int main(){
    char initStr[100'001];
    scanf("%s", initStr);

    list<char> l;
    for (int p = 0; initStr[p] != 0; p++) {
        l.push_back(initStr[p]);
    }
    auto now = l.end();
    
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char cmd[2], c[2];
        scanf("%s", cmd);
        char tmp = cmd[0];
        
        if(tmp == 'L'){
            if(now != l.begin()){
                now--;
            }
        } 
        else if(tmp == 'D'){
            if(now != l.end()){
                now++;
            }
        }
        else if(tmp == 'B'){
            if(now != l.begin()){
                now = l.erase(--now);
            }
        }
        else if(tmp == 'P'){
            scanf("%s", c);
            l.insert(now, c[0]);
        }    
    }
    for (auto it = l.begin(); it != l.end(); it++) {
        printf("%c", *it);
    }
    return 0;
}
