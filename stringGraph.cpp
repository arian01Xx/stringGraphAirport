#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    void dfsTraversal(const string& current, unordered_map<string, multiset<string>>& flightMap, vector<string>& result){
        auto& destination=flightMap[current];
        
        while(!destination.empty()){
            auto nextDestination=*destination.begin();
            destination.erase(destination.begin());
            dfsTraversal(nextDestination, flightMap, result);
        }
        result.push_back(current);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets){
        unordered_map<string, multiset<string>> flightMap;
        vector<string> result;

        for(const auto& ticket: tickets){
            //practicamente otro tipo de vector<vector< >>
            flightMap[ticket[0]].insert(ticket[1]);
        }

        dfsTraversal("JFK", flightMap, result);
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    return 0;
}