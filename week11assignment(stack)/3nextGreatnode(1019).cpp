//good question

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        int n=arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                int kids=st.top();
                st.pop();
                ans[kids]=arr[i];
            }
            st.push(i);

        }
        return ans;
        
    }
};