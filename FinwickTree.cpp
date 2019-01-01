class FinwickTree {
    vector<int> ft;
    int sz;
    
    public:
    FinwickTree(int n) {
        ft.assign(n+1, 0);
        sz = n;
    }

    int lastOne(int x) {
        int temp = x ^ (x-1);
        return temp & x;
    }

    long long int query(int i ) {
        long long int sum = 0;
        while(i>0) {
            sum += ft[i];
            i -= lastOne(i);
        }
        return sum;
    }

    void update(int pos, int value) {
        int i = pos;
        while(i<=sz) {
            ft[i] += value;
            i += lastOne(i);
        }
    }
};