class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        for(int i=0;i<num.size();i++){
            for(int j= i+1;j<num.size();j++){
                if(num[j]== target - num[i]){
                    return {i,j};
                }
            }
        }
        return {};

    }

};