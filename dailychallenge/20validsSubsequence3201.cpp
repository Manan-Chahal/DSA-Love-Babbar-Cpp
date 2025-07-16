class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int oddlength=0;
        int evenlength=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                evenlength++;
            }
        }
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2!=0){
                oddlength++;
            }
        }
        int parity=nums[0]%2;
        int alternating=1;
        for(int k=1;k<nums.size();k++){
             int currParity=nums[k]%2;
            if(currParity!=parity){
                alternating++;
                parity=currParity;

            }
        }
        return max({evenlength,alternating,oddlength});
    }
};