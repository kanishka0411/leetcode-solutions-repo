class Solution {
public:
    int mini;
    vector<int> ans;

    void solve(int n, int k, int st, vector<int>& curr) {
        if (k == 1) {
            if (n >= st) {
                curr.push_back(n);
                int mx = *max_element(curr.begin(), curr.end());
                int mn = *min_element(curr.begin(), curr.end());
                if (mx - mn < mini) {
                    mini = mx - mn;
                    ans = curr;
                }
                curr.pop_back();
            }
            return;
        }

        for (int i = st; i * i <= n; i++) {
            if (n % i == 0) {
                curr.push_back(i);
                solve(n / i, k - 1, i, curr); // non-decreasing factors
                curr.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        mini = INT_MAX;
        vector<int> curr;
        solve(n, k, 1, curr);
        return ans;
    }
};
