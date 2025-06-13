class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefixmax(height.size());
        vector<int> suffixmax(height.size());

        prefixmax[0] = height[0];
        for(int i=1;i<height.size();i++)
        {
            prefixmax[i] = max(height[i],prefixmax[i-1]);
        }
        suffixmax[height.size()-1] = height[height.size()-1];
        for(int i= height.size()-2;i>=0;i--)
        {
            suffixmax[i]=max(height[i],suffixmax[i+1]);
        }

        int total = 0;
        for(int i=0;i<height.size();i++)
        {
            int leftmax = prefixmax[i],rightmax = suffixmax[i];
            if(leftmax>height[i] && rightmax >height[i])
            {
                total+=min(leftmax,rightmax)-height[i];
            }
        }
        return total;
    }
};
