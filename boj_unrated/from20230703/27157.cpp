#include <bits/stdc++.h>
using namespace std;

#define _D(...) // printf(__VA_ARGS__)

char mywindow[51][51];
void debugprintall();

struct Node {
    string name;
    Node* parent;
    vector<Node*> children;
    
    pair<int,int> pos;
    pair<int,int> size;
    int color;
    pair<int,int> porigin;
    pair<int,int> anchor;
    int sensitive;
    int clip;
    pair<int,int> screenpos;

    // internal
    int sx, sy, ex, ey;

    void calculatePos() {
        // _D("[CALCULATE] %s\n", name.c_str());
        // pre-order: 자신 먼저 한다
        if (parent) {
            int x = porigin.first ? parent->ex : parent->sx;
            int y = porigin.second ? parent->ey : parent->sy;
            x += pos.first;
            y += pos.second;
            screenpos = {x, y}; // 관념적인 pos이고 draw에는 크게 도움이 안된다.

            // 아래가 실질적으로 도움되는 정보 (sx, sy) ~ (ex, ey)
            // _D("  anchor: %d, %d\n", anchor.first, anchor.second);
            sx = anchor.first ? screenpos.first - size.first : screenpos.first;
            ex = anchor.first ? screenpos.first : screenpos.first + size.first;
            sy = anchor.second ? screenpos.second - size.second : screenpos.second;
            ey = anchor.second ? screenpos.second : screenpos.second + size.second;
            // _D(" -> (%d, %d) ~ (%d, %d)\n", sx, sy, ex, ey);
        } else {
            // Window
            sx = 0;
            sy = 0;
            ex = size.first;
            ey = size.second;
        }
        // _D(" -> (%d, %d) (size: %d / %d)\n", screenpos.first, screenpos.second, size.first, size.second);
        // 자식 본다.
        for(auto& item: children) {
            item->calculatePos();
        }
    }
    // 이미 위치는 위에서 계산된 상태를 가정
    // (cx1, cy1) ~ (cx2, cy2) 가 실제로 보이는 영역, render도 여기에 집히는 녀석만.
    void draw(int cx1, int cy1, int cx2, int cy2) {
        _D("[DRAW][%s][COLOR: %d] %d, %d, %d, %d\n", name.c_str(), color, cx1, cy1, cx2, cy2);

        for(int j = max(cy1, sy); j < min(cy2, ey); ++j) {
            for(int i = max(cx1, sx); i < min(cx2, ex); ++i) {
                mywindow[j][i] = color;
            }
        }
        // debugprintall();
        if (clip) {
            cx1 = max(cx1, sx);
            cx2 = min(cx2, ex);
            cy1 = max(cy1, sy);
            cy2 = min(cy2, ey);
        }
        for(auto& item: children) {
            item->draw(cx1, cy1, cx2, cy2);
        }
    }
    
    Node* touch(int x, int y, int cx1, int cy1, int cx2, int cy2) {
        Node* res = 0;
        if (sensitive && x >= max(cx1, sx) && x < min(cx2, ex) && y >= max(cy1, sy) && y < min(cy2, ey)) {
            res = this;
        }

        if (clip) {
            cx1 = max(cx1, sx);
            cx2 = min(cx2, ex);
            cy1 = max(cy1, sy);
            cy2 = min(cy2, ey);
        }
        for(auto& item: children) {
            Node* tmp = item->touch(x, y, cx1, cy1, cx2, cy2);
            if (tmp != 0) res = tmp; // Pre-order로 덮어 쓴다.
        }
        return res;
    }
    void touchPrint(int x, int y, int cx1, int cy1, int cx2, int cy2) {
        if (sensitive) {
            for(int j = max(cy1, sy); j < min(cy2, ey); ++j) {
                for(int i = max(cx1, sx); i < min(cx2, ex); ++i) {
                    mywindow[j][i] = color;
                    // if (x == i && y == j) _D("TOUCHED!!! %s\n", name.c_str());
                }
            }
        }
        if (clip) {
            cx1 = max(cx1, sx);
            cx2 = min(cx2, ex);
            cy1 = max(cy1, sy);
            cy2 = min(cy2, ey);
        }
        for(auto& item: children) {
            item->touchPrint(x, y, cx1, cy1, cx2, cy2);
        }
    }
} n[5010]; // window max
int nid;

Node* newNode() {
    n[nid].color = 1;
    n[nid].sensitive = 1;
    return &n[nid++];
}
Node* window;

void debugprintall() {
    for(int i = 0; i < window->size.second; ++i) {
        for(int j = 0; j < window->size.first; ++j) {
            _D("%d", mywindow[i][j]);
        }
        _D("\n");
    }
}


void recalculatePos() {
    // Scene On 되지 않았을 시에는 0, 0으로 리턴
    for(int i = 0; i < nid; ++i) {
        n[i].screenpos = {0, 0};
    }
    window->calculatePos();
}

unordered_map<string, Node*> UM;

struct {
    string NEW = "New";
    string ADD = "Add";
    string REMOVE = "Remove";
    string UNPARENT = "Unparent";
    string SETPROPERTY = "SetProperty";
    string GETPROPERTY = "GetProperty";
    string TOUCH = "Touch";
    struct {
        string POSITION = "POSITION"; // -100'000 ~ 100'000
        string SIZE = "SIZE"; // 0 ~ 100'000
        string COLOR = "COLOR"; // 1 ~ 9
        string PARENT_ORIGIN = "PARENT_ORIGIN"; // 2d 0 or 1
        string ANCHOR_POINT = "ANCHOR_POINT"; // 2d 0 or 1
        string SENSITIVE = "SENSITIVE"; // 0 or 1
        string CLIP_CHILD = "CLIP_CHILD"; // 0 or 1
        string SCREEN_POSITION = "SCREEN_POSITION"; // read only
    } PROPERTY;
} CONSTANTS;

int main() {
    // freopen("input.txt", "r", stdin);

    int w, h; scanf("%d %d", &w, &h);
    window = newNode();
    window->size = {w, h};
    window->color = 0;
    window->anchor = {0, 0};
    window->sensitive = 1;
    window->name = "Window";
    UM["Window"] = &n[0];


    int QNUM; scanf("%d", &QNUM);

    char buf[20];
    for(int qnum = 0; qnum < QNUM; ++qnum) {
        scanf("%s", buf);
        string cmd = buf;
        if (cmd == CONSTANTS.NEW) {
            scanf("%s", buf);
            string name = buf;
            Node* n = newNode();
            n->name = name;
            UM[name] = n;
            _D("[NEW] %s\n", name.c_str());
        } else if (cmd == CONSTANTS.ADD) {
            scanf("%s", buf); string parent = buf;
            scanf("%s", buf); string child = buf;
            // 1. 기존 부모에서 삭제
            Node* c = UM[child];
            Node* oldp = c->parent;
            if (oldp != 0) {
                oldp->children.erase(find(oldp->children.begin(), oldp->children.end(), c));
            }
            // 2. 새로운 부모에 넣기
            Node* newp = UM[parent];
            newp->children.push_back(c);
            c->parent = newp;
            _D("[ADD] %s -> %s\n", c->name.c_str(), newp->name.c_str());
        } else if (cmd == CONSTANTS.REMOVE) {
            scanf("%s", buf); string parent = buf;
            scanf("%s", buf); string child = buf;
            // 1. 기존 부모에서 찾기
            Node* p = UM[parent];
            Node* c = UM[child];
            // 유효할때만 삭제한다. (요구사항)
            auto findres = find(p->children.begin(), p->children.end(), c);
            if (findres != p->children.end()) {
                // 있으므로 삭제
                p->children.erase(findres);
                c->parent = 0; // NULL!
                _D("[ERASE] %s is deleted from %s\n", child.c_str(), parent.c_str());
            } else {
                _D("[ERASE] no erase item!!\n");
            }
        } else if (cmd == CONSTANTS.UNPARENT) {
            scanf("%s", buf); string child = buf;
            Node* c = UM[child];
            if (c->parent != 0) {
                c->parent->children.erase(find(c->parent->children.begin(), c->parent->children.end(), c));
                c->parent = 0;
                _D("[UNPARENT] parent is deleted!\n");
            } else {
                _D("[UNPARENT] no parent!!! for %s!!\n", c->name.c_str());
            }
        } else if (cmd == CONSTANTS.SETPROPERTY) {
            scanf("%s", buf); string child = buf;
            scanf("%s", buf); string name = buf;
            Node* c = UM[child];
            _D("[SET] %s.%s = ", c->name.c_str(), name.c_str());
            if (name == CONSTANTS.PROPERTY.POSITION) {
                int x, y; scanf("%d %d", &x, &y);
                c->pos = {x, y};
                _D("%d, %d\n", x, y);
            } else if (name == CONSTANTS.PROPERTY.SIZE) {
                int x, y; scanf("%d %d", &x, &y);
                c->size = {x, y};
                _D("%d, %d\n", x, y);
            } else if (name == CONSTANTS.PROPERTY.COLOR) {
                int color; scanf("%d", &color);
                c->color = color;
                _D("%d\n", color);
            } else if (name == CONSTANTS.PROPERTY.PARENT_ORIGIN) {
                int x, y; scanf("%d %d", &x, &y);
                c->porigin = {x, y};
                _D("%d, %d\n", x, y);
            } else if (name == CONSTANTS.PROPERTY.ANCHOR_POINT) {
                int x, y; scanf("%d %d", &x, &y);
                c->anchor = {x, y};
                _D("%d, %d\n", x, y);
            } else if (name == CONSTANTS.PROPERTY.CLIP_CHILD) {
                int v; scanf("%d", &v);
                c->clip = v;
                _D("%d\n", v);
            } else if (name == CONSTANTS.PROPERTY.SENSITIVE) {
                int v; scanf("%d", &v);
                c->sensitive = v;
                _D("%d\n", v);
            } 
        } else if (cmd == CONSTANTS.GETPROPERTY) {
            scanf("%s", buf); string child = buf;
            scanf("%s", buf); string name = buf;
            Node* c = UM[child];
            _D("[GET] %s.%s = ", c->name.c_str(), name.c_str());
            if (name == CONSTANTS.PROPERTY.POSITION) {
                printf("%d %d\n", c->pos.first, c->pos.second);
            } else if (name == CONSTANTS.PROPERTY.SIZE) {
                printf("%d %d\n", c->size.first, c->size.second);
            } else if (name == CONSTANTS.PROPERTY.COLOR) {
                printf("%d\n", c->color);
            } else if (name == CONSTANTS.PROPERTY.PARENT_ORIGIN) {
                printf("%d %d\n", c->porigin.first, c->porigin.second);
            } else if (name == CONSTANTS.PROPERTY.ANCHOR_POINT) {
                printf("%d %d\n", c->anchor.first, c->anchor.second);
            } else if (name == CONSTANTS.PROPERTY.CLIP_CHILD) {
                printf("%d\n", c->clip);
            } else if (name == CONSTANTS.PROPERTY.SENSITIVE) {
                printf("%d\n", c->sensitive);
            } else if (name == CONSTANTS.PROPERTY.SCREEN_POSITION) {
                recalculatePos();
                printf("%d %d\n", c->screenpos.first, c->screenpos.second);
            } 
        } else if (cmd == CONSTANTS.TOUCH) {
            int x, y; scanf("%d %d", &x, &y);
            recalculatePos();
            _D("[TOUCH RESULT][%d, %d] ", x, y);
            printf("%s\n", window->touch(x, y, 0, 0, window->size.first, window->size.second)->name.c_str());
            // window->touchPrint(x, y, 0, 0, window->size.first, window->size.second);
            // for(int i = 0; i < window->size.second; ++i) {
            //     for(int j = 0; j < window->size.first; ++j) {
            //         _D("%d", mywindow[i][j]);
            //     }
            //     _D("\n");
            // }
        } else {
            _D("UNDEFINED CMD: %s!!!!!\n", cmd.c_str());
        }
    }

    recalculatePos();
    window->draw(0, 0, window->size.first, window->size.second); // 무조간 clip
    _D("-----------\n");
    for(int i = 0; i < window->size.second; ++i) {
        for(int j = 0; j < window->size.first; ++j) {
            printf("%d", mywindow[i][j]);
        }
        printf("\n");
    }
    return 0;
}