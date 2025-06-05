class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        int longest =1,count=0;
        for(auto it : st)
        {
            if(st.find(it-1) == st.end())
            {
                count =1;
                int x=it;
                while(st.find(x+1) != st.end())
                {
                    x=x+1;
                    count+=1;
                }
                longest = max(count,longest);
            }
        }
        return longest;
    }
};
