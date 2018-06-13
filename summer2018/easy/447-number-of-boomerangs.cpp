// O(n^2) but bead 99%
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0, n = points.size();
        int dis[n];
        for(int i=0;i<n;i++) {
            // Calculate distance for j given i
            for(int j=0;j<n;j++){ 
                int x = points[i].first - points[j].first;
                int y = points[i].second - points[j].second;
                dis[j] = x*x + y*y;
            }
            //reverse(dis, dis+n);
            sort(dis, dis+n);
            // Count number of boomerangs
            // if there are 3 points with distance 1 | a,b,c
            // there will have j,a,c | j,a,b | j,b,c | * 2 | == k*(k-1)
            int k=1;
            for(int j=1;j<n;j++){
                if(dis[j]==dis[j-1]) k++;
                else {
                    result += k*(k-1);
                    k = 1;
                }
            }
            result += k*(k-1);
        }
        return result;
    }
};
