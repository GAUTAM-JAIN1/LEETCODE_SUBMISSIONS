class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long normal = 1LL*cost1*need1 + 1LL*cost2*need2;

        long long k = min(need1, need2);

        long long other = 1LL*k*costBoth
                        + 1LL*(need1-k)*cost1
                        + 1LL*(need2-k)*cost2;

        long long alpha = 1LL*max(need1,need2)*costBoth;

        return min(normal, min(other, alpha));
    }
};
