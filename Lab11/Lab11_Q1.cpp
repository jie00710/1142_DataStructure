#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
const int EMPTY = 0; // 用 0 代表沒有節點
class TreeNode {
public:
    int value;// 節點值
    TreeNode* left;// 左子節點
    TreeNode* right;// 右子節點

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}//初始化節點
};

class BinaryTree {
public:
    TreeNode* root;// 樹根節點

    BinaryTree() : root(nullptr) {}

    TreeNode* buildTree(const vector<int>& arr) {// 建立樹
        if (arr.empty() || arr[0] == EMPTY) return nullptr;

        queue<TreeNode**> q;//建立queue儲存待處理的節點指標
        root = new TreeNode(arr[0]);// 建立根節點 (陣列第一個元素)
        q.push(&root);// 將根節點的指標加入queue

        size_t i = 1;// 陣列索引
        while (!q.empty() && i < arr.size()) {
            TreeNode** nodePtr = q.front();// 取出queue的第一個節點指標
            q.pop();// 將該節點從queue中刪除

            // 左子節點
            if (i < arr.size()) {
                if (arr[i] != EMPTY) {
                    (*nodePtr)->left = new TreeNode(arr[i]);// 添加左子節點
                    q.push(&((*nodePtr)->left));// 將左子節點的指標加入queue
                }
                i++;
            }
            // 右子節點
            if (i < arr.size()) {
                if (arr[i] != EMPTY) {
                    (*nodePtr)->right = new TreeNode(arr[i]);// 添加右子節點
                    q.push(&((*nodePtr)->right));// 將右子節點的指標加入queue
                }
                i++;
            }
        }
        return root;
    }

    void Depth_first_search(TreeNode* node) {//深度優先搜尋
        if (node == nullptr) return;
        cout << node->value << " ";// 訪問當前節點的值
        Depth_first_search(node->left);// 遞迴遍歷左子樹
        Depth_first_search(node->right);// 遞迴遍歷右子樹
    }

    void Breadth_first_search(TreeNode* root) {
        if (root == nullptr) return;
        queue<TreeNode*> q;//建立queue儲存待處理的節點指標
        q.push(root); // 將根節點的指標加入queue

        while (!q.empty()) {
            TreeNode* current = q.front();// 取出queue的第一個節點指標
            q.pop();// 將該節點從queue中刪除
            cout << current->value << " ";
            if (current->left) q.push(current->left);  // 將左子節點的指標加入queue
            if (current->right) q.push(current->right);// 將右子節點的指標加入queue
        }
    }
    int getHeight(TreeNode* root) { // 計算樹高
        if (root == nullptr) return 0; // 空樹高度為 0
        int leftHeight = getHeight(root->left);// 左子樹高度
        int rightHeight = getHeight(root->right);// 右子樹高度
        return max(leftHeight, rightHeight) + 1;// 返回較大高度 + 1（包含當前節點）
    }
    int sumAtLayer(TreeNode* root, int layer) {
        if (layer <= 0) {
            return 0; // 保護：無效層號直接返回 0
        }
        if (root == nullptr) return 0; // 空樹返回 0
        if(layer > getHeight(root)) { // 超過樹高顯示訊息並返回 0
        cout <<"The layer exceeds the tree height." << endl;
        return 0;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int sum = 0;

        while (!q.empty()) {
            TreeNode* node;
            int level;
            tie(node, level) = q.front();
            q.pop();

            if (level == layer) { // 當前節點在目標層
                sum += node->value; // 累加節點值
            }
            if (level < layer) { // 只有當前層小於目標層才繼續添加子節點
                if (node->left) q.push({node->left, level + 1}); // 將左子節點和層號加入queue
                if (node->right) q.push({node->right, level + 1}); // 將右子節點和層號加入queue
            }
        }
        cout << "Sum at layer " << layer-1 << ": " << sum << endl;
        return sum;
    }

};

int main() {
    BinaryTree tree;
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, EMPTY, EMPTY, 10, 11, EMPTY, EMPTY };
    tree.buildTree(arr);

    cout << "DFS Result: ";
    tree.Depth_first_search(tree.root);
    cout << endl;

    cout << "BFS Result: ";
    tree.Breadth_first_search(tree.root);
    cout << endl;

    int layer;
    cout << "Enter layer number to query: ";
    cin >> layer;
    tree.sumAtLayer(tree.root, layer+1);
    


    system("pause");
    return 0;
}