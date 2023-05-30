class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0]; 
        int fast = nums[nums[0]]; 
        
        while (slow != fast) {
            slow = nums[slow]; // Move the slow pointer one step at a time.
            fast = nums[nums[fast]]; // Move the fast pointer two steps at a time.
        }
        
        // Reset the slow pointer to the first element of the array, 
        // and move both pointers one step at a time until they meet again.
        slow = 0;
        while (slow != fast) {
            slow = nums[slow]; // Move the slow pointer one step at a time.
            fast = nums[fast]; // Move the fast pointer one step at a time.
        }
        
        // Return the value of the slow pointer, which is the duplicate number in the array.
        return slow;
    }
};
