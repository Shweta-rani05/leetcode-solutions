class Solution {
public:
    int singleNumber(vector<int>& num1) {
        int ans = 0 ;

        for(int val : num1){
            ans = ans^val ;
        }
        return ans;
    }
};