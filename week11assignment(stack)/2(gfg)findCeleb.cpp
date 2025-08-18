// explanation given in notebook 


class Solution {
public:
    int celebrity(vector<vector<int>>& mat) 
    {
        stack<int> st;
        int n = mat.size();
        
        // Push all people into the stack
        for(int i = 0; i < n; i++){
            st.push(i);
        }

        // Eliminate non-celebrities
        while(st.size() != 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            // CORRECTED: if a knows b, a cannot be celebrity → push b
            // if a does NOT know b, b cannot be celebrity → push a
            if(mat[a][b] == 1){
                st.push(b);  // a knows b → a cannot be celebrity
            }
            else{
                st.push(a);  // a does NOT know b → b cannot be celebrity
            }
        }

        // The single person left might be the celebrity
        int mightBeCeleb = st.top();

        // Check if everyone knows the candidate (skip self)
        for(int j = 0; j < n; j++){
            if(j != mightBeCeleb && mat[j][mightBeCeleb] == 0){
                return -1;
            }
        }

        // Check if candidate does not know anyone else
        for(int k = 0; k < n; k++){
            if(k != mightBeCeleb && mat[mightBeCeleb][k] == 1){
                return -1;
            }
        }

        return mightBeCeleb;
    }
};
