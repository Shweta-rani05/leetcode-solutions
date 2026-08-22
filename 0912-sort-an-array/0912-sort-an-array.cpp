class Solution {
public:
    void merge(vector<int>& nums, int s, int m, int e) {
        int n1 = m - s + 1;
        int n2 = e - m;
        
        // Create temporary arrays
        vector<int> arr1(n1);
        vector<int> arr2(n2);
        
        // Copy data to temporary arrays
        for(int i = 0; i < n1; i++) {
            arr1[i] = nums[s + i];
        }
        for(int i = 0; i < n2; i++) {
            arr2[i] = nums[m + 1 + i];  // Fixed: was arr[2] and mid+1+i
        }
        
        // Merge the two sorted arrays back
        int i = 0, j = 0, k = s;  // k starts at s, not 0
        
        while(i < n1 && j < n2) {  // Fixed: J to j (case-sensitive)
            if(arr1[i] <= arr2[j]) {
                nums[k++] = arr1[i++];  // Fixed: == to =, and increment k
            } else {
                nums[k++] = arr2[j++];  // Fixed: was arr2[j], j++, k++ separate
            }
        }
        
        // Copy remaining elements
        while(i < n1) {
            nums[k++] = arr1[i++];
        }
        while(j < n2) {
            nums[k++] = arr2[j++];
        }
    }
    
    void mergeSort(vector<int>& nums, int s, int e) {
        if(s < e) {
            int m = s + (e - s) / 2;
            mergeSort(nums, s, m);
            mergeSort(nums, m + 1, e);
            merge(nums, s, m, e);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);  // Fixed: size() with parentheses
        return nums;
    }
};