class Solution {
public:
//   int findRadius(vector<int>& A, vector<int>& H) {
//         sort(A.begin(), A.end());
//         sort(H.begin(), H.end());
//         vector<int> res(A.size(), INT_MAX); 
        
//         // For each house, calculate distance to nearest RHS heater
//         for (int i = 0, h = 0; i < A.size() && h < H.size(); ) {
//             if (A[i] <= H[h]) { res[i] = H[h] - A[i]; i++; }
//             else { h++; }
//         }
        
//         // For each house, calculate distance to nearest LHS heater
//         for (int i = A.size()-1, h = H.size()-1; i >= 0 && h >= 0; ) {
//             if (A[i] >= H[h]) { res[i] = min(res[i], A[i] - H[h]); i--; }
//             else { h--; }
//         }
       
//         return *max_element(res.begin(), res.end());
//     }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
    std::sort(heaters.begin(), heaters.end());
        int radius = 0;
        for (int i = 0; i < houses.size(); ++i) {
            int dist = 0;
            int left = 0;
            int right = heaters.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2 + 1;
                if (houses[i] < heaters[mid]) right = mid - 1;
                else left = mid;
            }
            if (left == heaters.size() - 1)  dist = abs(houses[i] - heaters[left]);
            else dist = min(abs(houses[i] - heaters[left]), abs(heaters[left+1] - houses[i]));
            radius = max(radius, dist);
        }
        return radius;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0, n = heaters.size();
        sort(heaters.begin(), heaters.end());
        for (int house : houses) { // For each house
            int left = 0, right = n;
            // Find the cloest heater to current house
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) left = mid + 1;
                else right = mid;
            }
            // Get distance1 between house and its right heater
            int dist1 = (right == n) ? INT_MAX : heaters[right] - house;
            // Get distance2 between house and its left heater
            int dist2 = (right == 0) ? INT_MAX : house - heaters[right - 1];
            res = max(res, min(dist1, dist2)); // Get max
        }
        return res;

    }
};
