class ProductOfNumbers {
public:
    vector<int> arr;

    ProductOfNumbers() {

    }

    void add(int num) {
        arr.push_back(num);
    }

    int getProduct(int k) {
        int i = 0;
        int ans = 1;

        while(k > 0) {
            ans *= arr[arr.size()-1-i];
            k--;
            i++;
        }

        return ans;
    }
};