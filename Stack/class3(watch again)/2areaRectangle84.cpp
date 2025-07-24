/*
Explanation of the code:

This code solves the "Largest Rectangle in Histogram" problem (LeetCode 84).
Given an array of heights representing histogram bars, the goal is to find the area of the largest rectangle that can be formed.

Key Functions:

1. nextSmallerElement:
   - For each bar, finds the index of the next smaller bar to the right.
   - Uses a stack to keep track of indices.
   - If there is no smaller bar to the right, stores -1.

2. prevSmallerElement:
   - For each bar, finds the index of the previous smaller bar to the left.
   - Uses a stack to keep track of indices.
   - If there is no smaller bar to the left, stores -1.

3. largestRectangleArea:
   - Calls nextSmallerElement and prevSmallerElement to get the boundaries for each bar.
   - For each bar, calculates the width as (nextSmallerIndex - prevSmallerIndex - 1).
   - The area for each bar is width * height.
   - Returns the maximum area found.

How it works:
-------------
- For each bar, the code finds how far it can extend to the left and right without hitting a shorter bar.
- The stack-based approach ensures O(N) time complexity for finding next/previous smaller elements.
- The main loop computes the area for each bar using these boundaries and keeps track of the maximum.

This approach is efficient and commonly used for histogram rectangle problems.
*/

class Solution {
public:
    void nextSmallerElement(vector<int>& arr, vector<int>& nextAns) {
        stack<int> st;
        st.push(-1);
        int n = arr.size();

        for(int i=n-1; i>=0; i--) {

            int element = arr[i];

            int index = st.top();
            while(index != -1 && arr[index] >= element) {
                st.pop();
            } 
            //agar yaha tk pohocha hu, iska mtlb
            //k ya toh koi choota number stack top pr h 
            //ya fer -1 stack top pr h 
            nextAns.push_back(st.top());
            //current number ko toh stack me push krna hi h 
            st.push(i);
        }
    }

    void prevSmallerElement(vector<int>& arr, vector<int>& prevAns) {
        stack<int> st;
        st.push(-1);
        int n = arr.size();

        for(int i=0; i<n; i++) {
            int element = arr[i];
            
            int stackTopIndex = st.top();
            
            while(stackTopIndex != -1 && arr[stackTopIndex] >= element) {
                st.pop();
            } 
            //agar yaha tk pohocha hu, iska mtlb
            //k ya toh koi choota number stack top pr h 
            //ya fer -1 stack top pr h 
            prevAns.push_back(st.top());
            //current number ko toh stack me push krna hi h 
            st.push(i);
        }
    }



    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextAns;
        vector<int> prevAns;
        nextSmallerElement(heights,nextAns);
        reverse(nextAns.begin(), nextAns.end());
        //yahi maoin bhul jata hu
        for(int i=0 ;i<nextAns.size(); i++) {
            if(nextAns[i] == -1) {
                nextAns[i] = nextAns.size(); 
            }
        }
        ///corner case -> = wala main bhul jata

        prevSmallerElement(heights, prevAns);

        int maxArea = INT_MIN;
        for(int i=0; i<nextAns.size(); i++) {
            int width = nextAns[i]-prevAns[i]-1;
            int height = heights[i];
            int currArea = width * height;
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
};