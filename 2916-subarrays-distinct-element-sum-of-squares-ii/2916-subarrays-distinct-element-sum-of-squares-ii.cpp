class Solution {
    static const int MOD = 1e9 + 7;

    class SegmentTree {
        int n;
        vector<long long> sum, sqSum, lazy;

        void push(int node, int l, int r) {
            if (lazy[node] == 0) return;

            long long val = lazy[node];
            long long len = r - l + 1;

            sqSum[node] = (sqSum[node]
                + 2 * val * sum[node] % MOD
                + val * val % MOD * len % MOD) % MOD;

            sum[node] = (sum[node] + val * len) % MOD;

            if (l != r) {
                lazy[node * 2] = (lazy[node * 2] + val) % MOD;
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] + val) % MOD;
            }

            lazy[node] = 0;
        }

        void update(int node, int l, int r, int ql, int qr) {
            push(node, l, r);

            if (r < ql || l > qr) return;

            if (ql <= l && r <= qr) {
                lazy[node] = 1;
                push(node, l, r);
                return;
            }

            int mid = l + (r - l) / 2;

            update(node * 2, l, mid, ql, qr);
            update(node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sqSum[node] =
                (sqSum[node * 2] + sqSum[node * 2 + 1]) % MOD;
        }

    public:
        SegmentTree(int size) : n(size) {
            sum.assign(4 * n, 0);
            sqSum.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void update(int l, int r) {
            if (l <= r) update(1, 0, n - 1, l, r);
        }

        long long getSquaredSum() {
            return sqSum[1];
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(n);

        unordered_map<int, int> lastSeen;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = lastSeen.count(nums[i])
                       ? lastSeen[nums[i]]
                       : -1;

            st.update(prev + 1, i);

            lastSeen[nums[i]] = i;

            ans = (ans + st.getSquaredSum()) % MOD;
        }

        return ans;
    }
};