#include <iostream>
#include <string>
using namespace std;

struct Student { //建立包含學生資訊的結構
    int id;
    string name;
    int chinese;
    int english;
    int math;
    int social;
    int science;
};

// 修改為 Call by Address：接收 Student 型態的指標
void updateMath(Student *s) {
    // 用箭頭存取指標所指向的屬性，將math改為100
    s->math = 100; 
}


void printStudent(const Student *s) { //改為使用指標輸出
    cout << "學生編號: " << s->id << endl;
    cout << "姓名: " << s->name << endl;
    cout << "數學成績: " << s->math << endl;
}

int main() {
    Student one; //宣告物件維持不變
    
    one.id = 1;
    one.name = "張小美";
    one.chinese = 77;
    one.english = 83;
    one.math = 86;
    one.social = 68;
    one.science = 91;

    
    updateMath(&one);  //把one的地址傳入函式，而不是傳入整個物件，函式能直接修改原本的物件
    
    // 輸出結果，此時 math 會成功變為 100
    printStudent(&one);

    return 0; //返回0表示程式正常結束
}