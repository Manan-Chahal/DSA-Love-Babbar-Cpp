// leetcode 300. Longest Increasing Subsequence
// ->other approach done in live class

// optimised solution : BINARY SEARCH
// TC: O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i = 1; i<nums.size();i++){ // O(N)
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                // find the index of just >= the ith element(lowerbound->gives iterator not index) 
                auto it = lower_bound(ans.begin(),ans.end(),nums[i]); //O(logn)
                int index = it - ans.begin(); //get index from iterator
                ans[index] = nums[i];
            }
        }
        
        /*
        ================================================================================
                            DETAILED EXPLANATION OF LOWER_BOUND AND ITERATOR ARITHMETIC
        ================================================================================
        
        Example walkthrough:
        Let's say ans vector (sorted) contains:
        
        Index : 0   1   2   3
        Value : 2   5   8  12
        
        Now we call: lower_bound(ans.begin(), ans.end(), 7)
        
        STEP 1: Binary Search Process
        --------------------------
        lower_bound searches for the first value ≥ 7 (target).
        
        Binary search process:
        - Check middle elements using binary search
        - 2 < 7 (continue searching right)
        - 5 < 7 (continue searching right)  
        - 8 ≥ 7 (found! This is our answer)
        
        Result: lower_bound returns iterator pointing to value 8 (at index 2)
        
        STEP 2: Iterator Values
        ----------------------
        it        → points to ans[2] (value 8) → memory address &ans[2]
        ans.begin() → points to ans[0] (value 2) → memory address &ans[0]
        
        STEP 3: Iterator Arithmetic 
        ---------------------------
        it - ans.begin() calculates the offset between two iterators:
        
        it        → &ans[2]  (memory address of index 2)
        ans.begin() → &ans[0]  (memory address of index 0)
        
        Difference: &ans[2] - &ans[0] = 2 (number of elements between them)
        
        Therefore: index = 2
        
        STEP 4: Final Operation
        ----------------------
        ans[index] = nums[i]  →  ans[2] = 7
        
        Updated ans vector:
        Index : 0   1   2   3
        Value : 2   5   7  12  (8 was replaced by 7)
        
        WHY THIS WORKS:
        --------------
        - We maintain ans[] as a sorted array
        - When nums[i] is not greater than ans.back(), we find the smallest element 
          in ans[] that is ≥ nums[i] and replace it
        - This replacement maintains the sorted order
        - The length of ans[] gives us the length of LIS
        - Note: ans[] doesn't store the actual LIS, just maintains optimal state for length calculation
        
        ALGORITHM INTUITION:
        -------------------
        - If current element can extend the sequence → add it to end
        - If current element is smaller → replace the first element that's ≥ current element
        - This replacement keeps better (smaller) options for future extensions
        - Binary search makes finding replacement position efficient: O(log n)
        
        Example trace for nums = [10, 22, 9, 33, 21, 50, 41, 60]:
        
        i=0: ans=[10]
        i=1: 22>10 → ans=[10,22]  
        i=2: 9<22 → replace ans[0]=10 with 9 → ans=[9,22]
        i=3: 33>22 → ans=[9,22,33]
        i=4: 21<33 → replace ans[1]=22 with 21 → ans=[9,21,33]  
        i=5: 50>33 → ans=[9,21,33,50]
        i=6: 41<50 → replace ans[3]=50 with 41 → ans=[9,21,33,41]
        i=7: 60>41 → ans=[9,21,33,41,60]
        
        Final answer: ans.size() = 5
        ================================================================================
        */
        
        return ans.size();
    }
};