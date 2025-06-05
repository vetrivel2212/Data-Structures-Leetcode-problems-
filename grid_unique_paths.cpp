class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = min(m - 1, n - 1); // binomial symmetry
        long double ans = 1.0;

        for (int i = 1; i <= r; i++) {
            ans = ans * (N - r + i) / i;
        }

        return (int)(ans + 0.5); // rounding to handle floating point error
    }
};
