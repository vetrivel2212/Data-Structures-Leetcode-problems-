vector<int> generateRow(int row)
{
    int res=1;
    vector<int> temp;
    temp.push_back(res);
    for(int i=1;i<row;i++)
    {
        res=res*(row-i);
        res=res/i;
        temp.push_back(res);
    }
    return temp;
}
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
