class DisjointUnion {
    
    vector<int> id;
    vector<int> sz;

    public:

    DisjointUnion() {
        for(int i = 0; i<MAX; i++) {
            id.push_back(i);
            sz.push_back(1);
        }
    }
    
    int getParent(int i) {
        if(id[i] != i) id[i] = getParent(id[i]);
        return id[i];
    }
    
    void unionJoin(int x, int y) {
        x = getParent(x);
        y = getParent(y);
        if( x == y ) return;
        if(sz[x] > sz[y]) { id[y] = x; sz[x] += sz[y]; }
        else { id[x] = y; sz[y] += sz[x]; }
    }
};
