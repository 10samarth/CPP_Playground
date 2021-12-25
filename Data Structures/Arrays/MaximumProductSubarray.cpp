class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxOccured = nums[0];
        int minOccured = nums[0];
        
        int res = maxOccured;
        
        for(int i=1; i<nums.size(); i++){
            int curr = nums[i];
            int temp = max(maxOccured*curr, max(curr,minOccured*curr));
            minOccured = min(maxOccured*curr, min(curr,minOccured*curr));
            
            maxOccured = temp;
            res = max(maxOccured,res);
        }
        
        return res;
    }
};