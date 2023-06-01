class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Sort the input array to make it easier to find pairs that sum to a given target
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Initialize a vector to store the output
        vector<vector<int>> output;
        
        // Loop through each pair of elements in the array
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                // Calculate the new target as the original target minus the sum of the two current elements
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                
                // Use two pointers to find pairs of elements that sum to the new target
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        // If we find a pair that sums to the new target, add it to the output
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        
                        // Move the pointers to the next distinct elements
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                
                // Skip over duplicates of the second element to avoid duplicates in the output
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            
            // Skip over duplicates of the first element to avoid duplicates in the output
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        
        // Return the output vector
        return output;
    }
};
