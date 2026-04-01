#include <iostream>
#include <string>
using namespace std;


struct Student {//建立一個名為Student的結構型態,裡面包含int、string等不同類型的資料型態
int id;
string name;
int chinese;
int english;
int math;
int social;
int science;
};
Student * ps;
void updateMath(Student s) {

}
void printStudent(Student * s) {
cout << "學生編號: " << s->id << endl;
cout << "姓名: " << s->name << endl;
cout << "數學成績: " << s->math << endl;
}
int main() {
    Student one; //宣告一個Student型態的變數one
    one.id = 1; //對新宣告的結構變數one中的元素賦值
    one.name = "張小美";
    one.chinese = 77;
    one.english = 83;
    one.math = 86;
    one.social = 68;
    one.science = 91;
    updateMath(one);
    printStudent(&one);
    
return 0;
}