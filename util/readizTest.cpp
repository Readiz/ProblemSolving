#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#define INF 0x7FFFFFFF
using namespace std;
 
 
class Student{
public:
    string name;
    int age;
    Student(string name, int age):name(name),age(age){}
    
};
 
 
void Print(vector<Student> &v){
    cout << "Student : " ;
    for(int i=0; i<5; i++){
        cout << "[" << v[i].name << ", " << v[i].age << "]";
    }
    cout << endl;
}
 
bool compare(Student a, Student b){
    if(a.name == b.name){   //이름이 같으면, 나이가 적은순
        return a.age < b.age;
    }else{                  //이름 다르면, 이름 사전순
        return a.name < b.name;
    }
    
}
int main(void){
    int a = INF;
    int b = INF + 1;
    int c = INF - 1;
    printf("%d %d %d\n", a, b, c);
    vector<Student> v;
    
    v.push_back(Student("cc", 10));
    v.push_back(Student("ba", 24));
    v.push_back(Student("aa", 11));
    v.push_back(Student("cc", 8));  //cc는 이름이 같으니 나이 기준 오름차순 예시
    v.push_back(Student("bb", 21));
    
    Print(v); //정렬 전 출력
    sort(v.begin(), v.end(), compare); //[begin, end) compare 함수 기준 정렬
    Print(v); //정렬 후 출력
    
    return 0;
}
 
