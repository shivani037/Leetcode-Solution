class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int cand1, vote1 = 0, cand2, vote2 = 0, lmt = nums.size() / 3;

        // looking for the 2 most frequent items
        for (int n: nums) {
            if (n == cand1) vote1++;     // if the current number matches candidate 1, increment its vote
            else if (n == cand2) vote2++; // if the current number matches candidate 2, increment its vote
            else if (!vote1) {           // if candidate 1 has no votes yet, assign it to the current number
                cand1 = n;
                vote1++;
            }
            else if (!vote2) {           // if candidate 2 has no votes yet, assign it to the current number
                cand2 = n;
                vote2++;
            }
            else {                       // if the current number does not match any candidate, decrement both votes
                vote1--;
                vote2--;
            }
        }
        // checking the actual frequency of the 2 most common items
        vote1 = 0;
        vote2 = 0;
        for (int n: nums) {
            if (n == cand1) vote1++;    // count the occurrences of candidate 1
            if (n == cand2) vote2++;    // count the occurrences of candidate 2
        }
        // making sure cand1 has more votes
        if (vote1 < vote2) {            // swap candidates if candidate 2 has more votes
            swap(cand1, cand2);
            swap(vote1, vote2);
        }
        // return the candidates that appear more than ⌊n/3⌋ times
        return vote1 <= lmt ? vector<int>{} : vote2 <= lmt ? vector<int>{cand1} : vector<int>{cand1, cand2};
    }
};
