class TimeMap {
private:
    unordered_map<string, std::set<int>> key_time;
    unordered_map<int, string> time_value;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key_time[key].insert(timestamp);
        time_value[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if ( key_time.find(key) == key_time.end() ) return "";
        auto it = key_time[key].lower_bound(timestamp);
        if ( *it == timestamp ) return time_value[*it];
        if ( it != key_time[key].begin() ) {
            it--;
            return time_value[*it];
        }
        return "";
    }
};
