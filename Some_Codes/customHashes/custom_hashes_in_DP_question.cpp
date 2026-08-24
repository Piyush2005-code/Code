#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


/*
 * Now I am writing this code simply because of an error struck me today,
 * How can I use a hash map using unordered_map<some_container<some_class>, some_container<some_class>>, now if the containers are 
 * primtives supported by c++ or the definitions of unordered_map; then you can use it, like the primitives for int, string are defined in the
 * definitino of unordered_map, but if you pass a pair or a vector as a key in the hash function then it will not be able to hash them
 * the method to has them is to create a custome hash operator for pair and vector or other non-primitive classes which we might want to use 
 * as a key in the unordered_map.
 *
 */


/*
 * Instead of letting this code be a random small footprint of C++ knowledge I am making it a simple question for using hashmap
 *
 */


class Solution {
public:
    
    // Here comes the definition of the hash operator;
    struct pair_hash{                           // Note here you need to write "const" before the fuction definition as well
        size_t operator()(const pair<int, int>& pr) const {
            return hash<int>()(pr.first) ^ (hash<int>()(pr.second) << 1);
        }
    };


    int solve(vector<int>& nums, int target, int i, int sum, unordered_map<pair<int, int>, int, pair_hash>& mp){
        if(mp.find({i, sum}) != mp.end()){
            return mp[{i, sum}];
        }
        if(i == nums.size()) return target == sum;
        else return mp[{i, sum}] = solve(nums, target, i + 1, sum + nums[i], mp) + solve(nums, target, i + 1, sum - nums[i], mp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<pair<int, int>, int, pair_hash> mp;
        return solve(nums, target, 0, 0, mp);
    }
};


int main(){
    
    int n, target;

    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.findTargetSumWays(nums, target);

}

