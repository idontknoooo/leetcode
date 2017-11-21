class Solution {
public:
    // int shortestDistance(vector<string>& words, string word1, string word2) {
    //     int pos1 = -1, pos2 = -1, res = words.size();
    //     for (auto it = words.begin(); it != words.end(); ++it){
    //         if ((*it).compare(word1) == 0) pos1 = it - words.begin();
    //         else if ((*it).compare(word2) == 0) pos2 = it - words.begin();
    //         else continue;
    //         //if neither equals to word1 and 2, loop is continued and last step skipped
    //         if (pos1 >= 0 && pos2 >= 0 && abs(pos1 - pos2) < res) res = abs(pos1 - pos2); 
    //     }
    //     return res;
    // }
//     int shortestDistance(vector<string>& words, string word1, string word2) {
//     int id1 = -1, id2 = -1;
//     int minDist = INT_MAX;
//     for (int i = 0; i < words.size(); i++) {
//         if (words[i] == word1) {
//             id1 = i;
//             if (id2 != -1) {
//                 minDist = min(minDist, id1 - id2);
//             }
//         } else if (words[i] == word2) {
//             id2 = i;
//             if (id1 != -1) {
//                 minDist = min(minDist, id2 - id1);
//             }
//         }
//     }
//     return minDist;
// }
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int k = -1;
        int j = -1;
        int min_l = INT_MAX;
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                k = i;
                if (k >= 0 && j >= 0) {
                    min_l = min(min_l, k - j);
                }
            } else if (words[i] == word2) {
                j = i;
                if (k >= 0 && j >= 0) {
                    min_l = min(min_l, j - k);
                }
            }
        }
        return min_l;
    }
};