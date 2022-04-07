#prag\
ma GCC optimize("O3")

#define ROOM_SIZE 777777
#define NOTE_SIZE 100000
#define ROOM_TYPES 3
 
 
// 2, 3, 5 = 10
 
#define ROOM2_MAX (77778)
#define ROOM3_MAX (77777)
#define ROOM5_MAX (77778)
#define ROOM2_PTR 0
#define ROOM3_PTR (ROOM2_MAX * 2)
#define ROOM5_PTR (ROOM3_PTR + ROOM3_MAX * 3)
#define ROOM 0
#define ROOM2_CNT 2
#define ROOM3_CNT 3
#define ROOM5_CNT 4
#define ROOM2_TOP 5
#define ROOM3_TOP 6
#define ROOM5_TOP 7
 
#define ROOM2_STACK 8
#define ROOM3_STACK (ROOM2_STACK + 8000)
#define ROOM5_STACK (ROOM3_STACK + 8000)
 
void init_note(char note[NOTE_SIZE], char rooms[ROOM_SIZE])
{
    int* NOTE = (int*)note;
    long long& mem_ptr = *(long long *)(&NOTE[ROOM]);
    mem_ptr = (long long)rooms;
    NOTE[ROOM2_CNT] = NOTE[ROOM3_CNT] = NOTE[ROOM5_CNT] = 0;
    NOTE[ROOM2_TOP] = NOTE[ROOM3_TOP] = NOTE[ROOM5_TOP] = 0;
}
 
char* sell_room(char note[NOTE_SIZE], int size) {
 
    long long& note_ptr = *((long long*)&note);
    int* NOTE = (int*)note_ptr;
    long long& mem_ptr = *((long long*)&NOTE[ROOM]);
    char* rooms = (char*)mem_ptr;
 
    int* STACK;
    int* TOP;
    int* CNT;
    int PTR;
 
    if (size == 2)
    {
        STACK = (int*)&NOTE[ROOM2_STACK];
        TOP = (int*)&NOTE[ROOM2_TOP];
        CNT = (int*)&NOTE[ROOM2_CNT];
        PTR = ROOM2_PTR;
 
        if (*TOP == 0 && *CNT >= ROOM2_MAX) return 0;
    }
    else if (size == 3)
    {
        STACK = (int*)&NOTE[ROOM3_STACK];
        TOP = (int*)&NOTE[ROOM3_TOP];
        CNT = (int*)&NOTE[ROOM3_CNT];
        PTR = ROOM3_PTR;
        if (*TOP == 0 && *CNT >= ROOM3_MAX) return 0;
    }
    else
    {
        STACK = (int*)&NOTE[ROOM5_STACK];
        TOP = (int*)&NOTE[ROOM5_TOP];
        CNT = (int*)&NOTE[ROOM5_CNT];
        PTR = ROOM5_PTR;
        if (*TOP == 0 && *CNT >= ROOM5_MAX) return 0;
    }
 
    if (*TOP) return (char*)STACK[(*TOP)--];
    return &rooms[PTR + (size * (*CNT)++)];
}
void return_room(char note[NOTE_SIZE], char* position) {
    long long& note_ptr = *((long long*)&note);
    int* NOTE = (int*)note_ptr;
    long long& mem_ptr = *((long long*)&NOTE[ROOM]);
    char* rooms = (char*)mem_ptr;
     
    long long room3_ptr = (long long)&rooms[ROOM3_PTR];
    long long room5_ptr = (long long)&rooms[ROOM5_PTR];
 
    long long pos_ptr = (long long)position;
    int size;
    if (pos_ptr < room3_ptr) size = 2;
    else if (pos_ptr < room5_ptr) size = 3;
    else size = 5;
 
    int* STACK;
    int* TOP;
 
    if (size == 2)
    {
        STACK = (int*)&NOTE[ROOM2_STACK];
        TOP = (int*)&NOTE[ROOM2_TOP];
    }
    else if (size == 3)
    {
        STACK = (int*)&NOTE[ROOM3_STACK];
        TOP = (int*)&NOTE[ROOM3_TOP];
    }
    else
    {
        STACK = (int*)&NOTE[ROOM5_STACK];
        TOP = (int*)&NOTE[ROOM5_TOP];
    }
 
    STACK[++(*TOP)] = (long long)position;
}