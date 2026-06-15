class Logger {
     private:
    	std::unordered_map< std::string, int > stamperlookup;

    	int allowed_time(std::string m)
    	{
    		auto kvp = stamperlookup.find(m);
    		if ( kvp != stamperlookup.end()) 
    			return kvp->second;
    		return -1;
    	}

    	void update_allowed_time( std::string m, int ts )
    	{
            auto kvp = stamperlookup.find(m);
            if ( kvp != stamperlookup.end() )
    		    stamperlookup[m] = ts + 10;
            else
                stamperlookup.insert(std::pair<std::string, int>(m, ts+10));
    	}

    
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int ts, string msg) {
        int allowed_ts = allowed_time(msg);
		if( ts < allowed_ts )
			return false;
        update_allowed_time(msg, ts );
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */