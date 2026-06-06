#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {

        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        
        int heater_ptr = 0;
        int max_radius = 0;
        
        for (int house_ptr = 0; house_ptr < houses.size(); ++house_ptr) {

            while (heater_ptr + 1 < heaters.size() && 
                   std::abs(heaters[heater_ptr + 1] - houses[house_ptr]) <= std::abs(heaters[heater_ptr] - houses[house_ptr])) {
                heater_ptr++;
            }

            int current_dist = std::abs(heaters[heater_ptr] - houses[house_ptr]);

            max_radius = std::max(max_radius, current_dist);
        }
        
        return max_radius;
    }
};
