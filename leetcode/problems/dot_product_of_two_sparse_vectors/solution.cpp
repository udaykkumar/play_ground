class SparseVector {
    std::vector< int > v;
public:
    
    SparseVector(vector<int> &nums) {
        for ( auto n : nums )
            v.emplace_back(n);
    }
    
    std::vector< int > &get()
    {
        return v;
    }
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int s = 0;
        for( int i = 0 ; i < vec.get().size() ; ++i )
            s += ( get()[i] * vec.get()[i]);
        return s;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);