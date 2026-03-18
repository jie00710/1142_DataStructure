class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> counts;
        int max_lucky = -1;//若找不到則max_lucky預設-1

        for (int num : arr) {
            counts[num]++; //計算出現次數
        }

        for (auto const& [num, freq] : counts) {
            if (num == freq) { //判斷是否是 lucky number
                if(num>max_lucky){ //判斷是否比目前的num_lucky大
                    max_lucky = num ;
                }
                
            }
        }

        return max_lucky;//回傳max_lucky
    }
};
