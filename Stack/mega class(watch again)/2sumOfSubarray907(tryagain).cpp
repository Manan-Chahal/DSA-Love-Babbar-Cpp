// this question was done in mega class for you to understand this question 
//watch megaclass again and watch class3 video again for the concept of this question 
// my doubt is in line 16 and 31 
//why v[st.top()] > v[i]) in line 16 and v[st.top()] >= v[i] in line 31
class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> &v)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(v.size(), -1);

        for (int i = v.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() != -1 && v[st.top()] > v[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &v)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(v.size(), -1);

        for (int i = 0; i < v.size(); i++)
        {
            while (!st.empty() && st.top() != -1 && v[st.top()] >= v[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        auto next = nextSmallerElement(arr);
        auto prev = prevSmallerElement(arr);
        long long sum = 0;       // sum of all sub array's minimum elements
        const int mod = 1e9 + 7; // const, good practice

        for (int i = 0; i < arr.size(); i++)
        {
            // for each index element, need to find
            // how many times it is contributing to the "sum"
            int nexti = next[i] == -1 ? arr.size() : next[i];
            int previ = prev[i];
            int left = i - previ;
            int right = nexti - i;
            long long no_of_times = (left % mod * right % mod) % mod;
            long long total = (no_of_times * arr[i]) % mod;
            sum = (sum + total) % mod;
        }
        return sum;
    }
};