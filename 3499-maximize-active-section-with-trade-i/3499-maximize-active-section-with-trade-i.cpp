class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        string aug = "1" + s + "1";
        vector<pair<char, int>> seg;
        int i = 0;
        while (i < aug.size()) {
            char ch = aug[i];
            int j = i;
           while (j < aug.size() && aug[j] == ch) {
                j++;
            }
            seg.push_back({ch, j - i});
            i = j;
        }
        int maxzeros = 0;
        int m = seg.size();
        for (int i = 1; i < m - 1; i++) {
            if (seg[i].first == '1' && seg[i - 1].first == '0' &&
                seg[i + 1].first == '0') {
                int a = seg[i - 1].second + seg[i + 1].second;
                maxzeros = max(maxzeros, a);
            }
        }

        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                ones++;
        }

        return ones + maxzeros;
    }
};