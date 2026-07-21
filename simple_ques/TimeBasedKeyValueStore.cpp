#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


class TimeMap {
private:
    // The key is stored as the actual key and the vector<pair<int, int>> is the pair of timestamp and value;
    unordered_map<string, vector<pair<int, string>>> mp;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }

        auto& temp = mp[key];
        int l = 0, r = temp.size() - 1;
        int mid;
        string ans = "";
        // I need to learn this kind of lesser than or equal to binary search, which can be used for storing an answer which contains the answer for the (lesser than or equal to conditions).
        while(l <= r){
            mid = l + (r - l) / 2;
            if(temp[mid].first <= timestamp){
                ans = temp[mid].second;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
