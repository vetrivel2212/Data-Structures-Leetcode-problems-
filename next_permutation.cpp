class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // std::next_permutation(nums.begin(), nums.end());  // Use std:: to avoid name clash
        // for (auto i : nums) {
        //     cout << i << " ";
        // }
        // cout << endl;
        int n = nums.size();
        int ind = -1;

        // Step 1: Find the breakpoint
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: If no breakpoint, reverse the array
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            // Step 3: Find the next greater element from the right
            for (int i = n - 1; i > ind; i--) {
                if (nums[i] > nums[ind]) {
                    swap(nums[i], nums[ind]);
                    break;  //
                }
            }

            // Step 4: Reverse the tail
            reverse(nums.begin() + ind + 1, nums.end());
        }

        // Optional: Print for verification
        for (auto i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }
};
