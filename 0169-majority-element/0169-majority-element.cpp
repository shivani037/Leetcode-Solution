class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maxElement;
        int count=0;
        
        // Iterate through the array
        for(int i=0;i<nums.size();i++){
            
            // If count is 0, set the current element as the new candidate
            if(count==0) maxElement=nums[i];
            
            // If the current element is the same as the candidate, increment the count
            if(nums[i]== maxElement) count++;
            
            // Otherwise, decrement the count
            else count--;
        }
        
        return maxElement;
    }
};
