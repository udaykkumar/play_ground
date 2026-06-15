class MovingAverage {
    std::list< int >  window_;
	int 			  max_size_;
	double 			  sum_;

    std::list< int > &window() { return window_ ; }
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        max_size_ = size;
        sum_ = 0;
    }
    
    double next(int v) {
        
        // There is no room
		if ( window().size() == max_size_ )
		{
			// remove the last one 
			sum_ -= window().back();

			// make room
			window().pop_back();
		}

        window().push_front(v);
		sum_  +=  v; // new element

		return window().size() ? (sum_ / window().size()) : 0;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */