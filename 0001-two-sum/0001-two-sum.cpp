class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered_map to store each number in nums and its index
        unordered_map<int, int> map;
        
        // Loop through each number in nums
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement of the current number with respect to the target
            int complement = target - nums[i];
            
            // If the complement is already in the map, we have found a pair that sums to target
            if (map.find(complement) != map.end()) {
                // Return a vector with the indices of the two numbers
                return { map[complement], i };
            }
            
            // Otherwise, add the current number and its index to the map
            map[nums[i]] = i;
        }
        
        // If no pair is found, return {-1, -1} to indicate failure
        return {-1, -1}; // or return {};
    }
};
