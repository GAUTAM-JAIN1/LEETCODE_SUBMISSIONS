class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        int a = queries.size();
      sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
});
        vector<pair<int, int>> q;
        for (int i = 0; i < a; i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        vector<int> freq(n + 1, 0);
        vector<int> arr(a, 0);
        int i = 0, j = 0, cnt = 0;
        for (int k = 0; k < a; k++) {
            int y = q[k].first - x;
            int z = q[k].first;
            while (j < logs.size() && logs[j][1] <= z) {
                int id = logs[j][0];
                if (freq[id] == 0)
                    cnt++;
                freq[id]++;
                j++;
            }
            while (i < j && logs[i][1] < y) {
                int id = logs[i][0];
                freq[id]--;
                if (freq[id] == 0)
                    cnt--;
                i++;
            }
            arr[q[k].second] = n - cnt;
        }

        return arr;
    }
};