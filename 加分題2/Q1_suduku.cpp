class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10]={false};
        bool col[9][10]={false};
        bool box[9][10]{false};
        //遍歷board
        for (int r = 0;r<9;++r){
            for(int c = 0; c<9;++c){
                //跳過空白格
                if(board[r][c] == '.'){
                    continue;
                }
                //字元轉數字
                int num = board[r][c]-'0';
                //計算當前格子屬於哪個九宮格
                int box_index=(r/3)*3+(c/3);
                
                //判斷行、列或九宮格有沒有出現過
                if (row[r][num] || col[c][num] || box[box_index][num]){
                    return false;
                }
                //沒出現過就標記列[數字]存在，行[數字]存在,九宮格[數字存在]
                row[r][num] = true;
                col[c][num] = true;
                box[box_index][num] = true;
                }
            }
        return true;
    }
};