#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // P truck
        int pickP = 0;
        int travelP = 0;
        int lastHouseP = 0;

        // M Truck
        int pickM = 0;
        int travelM = 0;
        int lastHouseM = 0;

        // G Truck
        int pickG = 0;
        int travelG = 0;
        int lastHouseG = 0;

        // Traverse each house
        for (int i = 0; i < garbage.size(); i++) {
            string currHouse = garbage[i];
            // Check garbage in each house
            for (int j = 0; j < currHouse.length(); j++) {
                char garbageType = currHouse[j];
                if (garbageType == 'P') {
                    pickP++;
                    lastHouseP = i;
                }
                if (garbageType == 'M') {
                    pickM++;
                    lastHouseM = i;
                }
                if (garbageType == 'G') {
                    pickG++;
                    lastHouseG = i;
                }
            }
        }

        // Calculate travel time for P truck
        for (int i = 0; i < lastHouseP; i++) {
            travelP += travel[i];
        }

        // Calculate travel time for G truck
        for (int i = 0; i < lastHouseG; i++) {
            travelG += travel[i];
        }

        // Calculate travel time for M truck
        for (int i = 0; i < lastHouseM; i++) {
            travelM += travel[i];
        }

        int totalPickingTime = pickP + pickM + pickG;
        int totalTravelTime = travelP + travelG + travelM;

        int totalTime = totalPickingTime + totalTravelTime;
        return totalTime;
    }
};

int main() {
    Solution solution;

    // Sample input
    vector<string> garbage = {"G", "P", "GP", "GG"};
    vector<int> travel = {2, 4, 3};

    // Function call
    int result = solution.garbageCollection(garbage, travel);

    // Output the result
    cout << "Total time required: " << result << endl;

    return 0;
}
