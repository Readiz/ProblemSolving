#include "main.cpp"

struct Node
{
    int index;
    int val;
    Node *next;
    Node *pre;
};
Node wall[100000];
int pos;
Node *head;
Node *tail;
int result[500];
int count_result;
int temp_arr[5];
int _id;
struct Hash
{
    int index;
    int val;
    Hash *next;
};
#define SIZE 100007
 
Hash *table[SIZE];
Hash POOL[100000];
int pool;
 
int hashFuntion(int arr[]){
    int max = arr[0];
    for(int i = 0; i < 5; i++){
        if(arr[i] > max) max = arr[i];
    }
    int t = 0;
    for(int i = 0; i < 5; i++){
        t = (t << 4) + (max - arr[i]);
    }
    return t;
}
void addHash(int id, int arr[]){
    int key = hashFuntion(arr);
    Hash *node = &POOL[pool++];
    node->index = id;
    node->next = nullptr;
    node->val = key;
    key %= SIZE;
    if(table[key] == nullptr){
        table[key] = node;
    }else{
        node->next = table[key];
        table[key] = node;
    }
}
 
void init(){
    count_result = 0;
    pos = 0;
    pool = 0;
    head = nullptr;
    tail = nullptr;
    for(int i = 0; i < SIZE; i++){
        table[i] = nullptr;
    }
}
 
void makeWall(int arr[]){
 
    for(int i = 0; i < 5; i++){
        Node *node = &wall[pos];
        node->index = pos;
        node->val = arr[i];
        node->next = nullptr;
        node->pre = nullptr;
        if(head == nullptr){
            head = node;
            tail = node;
        }else{
            tail->next = node;
            node->pre = tail;
            tail = node;
        }
        pos++;
    }
    addHash(pos-5, arr);
    int c = 0;
    Node *temp = &wall[pos-5];
    if(temp->pre == nullptr){
        return;
    }
 
    for(int i = 0; i < 4; i++){
        temp = temp->pre;
    }
    _id = 0;
    Node *temp2;
    for(int i = 0; i < 4; i++){
        _id = 0;
        temp2 = temp;
        for(int j = 0; j < 5; j++){
            temp_arr[_id++] = temp2->val;
            temp2 = temp2->next;
        }
        addHash(temp->index, temp_arr);
        temp = temp->next;
    }
}
 
void delHash(int index){
    //xoa trong hash
    Node *block1 = &wall[index];
    int c = 0;
    for(int i = 0; i < 4 && block1->pre != nullptr; i++){
        block1 = block1->pre;
        c++;
    }
    _id = 0;
    Node *node;
    for(int i = 0; i < (c + 5); i++){
        _id = 0;
        node = block1;
        for(int j = 0; j < 5 && node != nullptr; j++){
            temp_arr[_id++] = node->val;
            node = node->next;
        }
        if(_id == 5){
            int key = hashFuntion(temp_arr);
            key %=SIZE;
            Hash *temp = table[key];
            Hash *cur = nullptr;
            while (temp)
            {
                if(temp->index == block1->index){
                    if(cur == nullptr){
                        table[key] = temp->next;
                    }else{
                        cur->next = temp->next;
                    }
                    break;
                }
                cur = temp;
                temp = temp->next;
            }
        }else{
            break;
        }
        block1 = block1->next;
    }
}
 
void handleAddHash(Node *node){
    int c = 0;
    Node *temp = node;
    for(int i = 0; i < 4 && temp->pre != nullptr; i++){
        temp = temp->pre;
        c++;
    }
    Node *temp2;
    _id = 0;
    for(int i = 0; i < c; i++){
        temp2 = temp;
        _id = 0;
        for(int j = 0; j < 5 && temp2 != nullptr; j++){
            temp_arr[_id++] = temp2->val;
            temp2 = temp2->next;
        }
        if(_id == 5){
            addHash(temp->index, temp_arr);
        }else{
            break;
        }
        temp = temp->next;
    }
}
int matchPiece(int arr[]){
    int index = -1;
    int min = arr[0];
    int key = 0;
    for(int i = 0; i < 5; i++){
        if(arr[i] < min) min = arr[i];
    }
    for(int i = 4; i >= 0; i--){
        key = (key << 4) + (arr[i] - min);
    }
     
    if(table[key%SIZE] == nullptr) return index;
    //Tim index
    Hash *temp = table[key%SIZE];
    while (temp)
    {
        if(temp->val == key && temp->index > index){
            index = temp -> index;
        }
        temp = temp->next;
    }
    if(index == -1) return index;
    delHash(index);
    //xoa link list
    Node *block1 = &wall[index];
    Node *block5 = block1->next->next->next->next;
 
    if(block1->pre == nullptr){
        head = block5->next;
    }
    if(block1->pre) block1->pre->next = block5->next;
    if(block5->next) block5->next->pre = block1->pre;
 
    if(block5->next == nullptr) tail = block1->pre;
     
 
    //add hash
 
    handleAddHash(block1);
    int count = 0;
    for(int i = 0; i < count_result; i++){
        if(result[i] < index) count++;
    }
    result[count_result++] = index;
    return index - 5*count+1;
}