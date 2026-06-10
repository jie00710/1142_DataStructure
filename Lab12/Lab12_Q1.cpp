#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// 商品結構
struct Product {
    string name;
    int expiry;     // 有效期限（天）
    int popularity; // 熱銷程度（1~10）

    // 自訂比較規則
    bool operator<(const Product& other) const {
        if (expiry != other.expiry)
            return expiry < other.expiry; // 有效期限越小越優先
        return popularity > other.popularity; // 熱銷程度越高越優先
    }
};

void quickSort(vector<Product>& products, int left, int right)
{
    if (left >= right) { // 基本情況：子陣列長度為0或1
        return;
    }

    Product pivot = products[left];// 選擇第一個元素作為基準
    int i = left;// i從左邊開始
    int j = right + 1;// j從右邊開始
    // 分割
    while (true) {
        // 找到第一個大於或等於pivot的元素
        do {
            ++i;
        } while (i <= right && products[i] < pivot);
        // 找到第一個小於或等於pivot的元素
        do {
            --j;
        } while (pivot < products[j]);
        // 如果i和j相遇或交錯，分割完成
        if (i >= j) {
            break;
        }
        // 交換i和j位置的元素
        swap(products[i], products[j]);
    }
    // 將pivot放到正確的位置
    swap(products[left], products[j]);
    quickSort(products, left, j - 1);
    quickSort(products, j + 1, right);

}


int main() {
    ifstream infile("input1.txt");
    if (!infile) {
        cerr << "無法打開檔案" << endl;
        return 1;
    }

    int N;
    infile >> N;
    infile.ignore(); // 忽略換行
    // 讀取商品資料(名稱、有效期限、熱銷程度)
    vector<Product> products;
    for (int i = 0; i < N; ++i) {
        string line;
        getline(infile, line);
        
        // 從後往前提取最後兩個數字
        istringstream iss(line);
        string word;
        vector<string> tokens;
        
        while (iss >> word) {
            tokens.push_back(word);
        }
        
        if (tokens.size() < 3) continue;
        
        int popularity = stoi(tokens[tokens.size() - 1]);
        int expiry = stoi(tokens[tokens.size() - 2]);
        
        // 其餘部分是商品名稱
        string name = "";
        for (size_t j = 0; j < tokens.size() - 2; ++j) {
            if (j > 0) name += " ";
            name += tokens[j];
        }

        products.push_back({ name, expiry, popularity });
    }
    
    infile.close();
    // 排序
    if (!products.empty()) {
        quickSort(products, 0, static_cast<int>(products.size()) - 1);
    }

    // 輸出
    cout << "商品排序:" << endl;
    for (const Product& product : products) {
        cout << product.name << endl;
    }

    return 0;
}