#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 商品結構
struct Product {
    string name;
    int expiry;     // 有效期限（天）
    int popularity; // 熱銷程度（1~10）

    // 自訂比較規則（小頂堆）
    bool operator<(const Product& other) const {
        if (expiry != other.expiry)
            return expiry < other.expiry; // 有效期限越小越優先
        return popularity > other.popularity; // 熱銷程度越高越優先
    }
};

void quickSort(vector<Product>& products, int left, int right)
{
    if (left >= right) {
        return;
    }

    Product pivot = products[left];
    int i = left;
    int j = right + 1;

    while (true) {
        do {
            ++i;
        } while (i <= right && products[i] < pivot);

        do {
            --j;
        } while (pivot < products[j]);

        if (i >= j) {
            break;
        }

        swap(products[i], products[j]);
    }

    swap(products[left], products[j]);
    quickSort(products, left, j - 1);
    quickSort(products, j + 1, right);

}


int main() {
    ifstream infile("input3.txt");
    if (!infile) {
        cerr << "無法打開檔案 products.txt" << endl;
        return 1;
    }

    int N;
    infile >> N;
    infile.ignore(); // 忽略換行符

    vector<Product> products;
    for (int i = 0; i < N; ++i) {
        string line;
        getline(infile, line);
        size_t lastSpace = line.rfind(' ');
        size_t secondLastSpace = line.rfind(' ', lastSpace - 1);

        string name = line.substr(0, secondLastSpace);
        int expiry = stoi(line.substr(secondLastSpace + 1, lastSpace - secondLastSpace - 1));
        int popularity = stoi(line.substr(lastSpace + 1));

        products.push_back({ name, expiry, popularity });
    }

    infile.close();

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