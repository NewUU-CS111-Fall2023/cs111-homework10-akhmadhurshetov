/*
 * Author: Axmad Xurshetov
 * Date: 19.01.2024
 * Name:
 */
#include <iostream>
#include <vector>
#include <numeric>

class Problem8 {
public:
    static bool canPartition(std::vector<int>& numsProb8) {
        int sumProb8 = std::accumulate(numsProb8.begin(), numsProb8.end(), 0);
        if (sumProb8 % 2 != 0) return false;

        int targetProb8 = sumProb8 / 2;
        std::vector<bool> dpProb8(targetProb8 + 1, false);
        dpProb8[0] = true; 
        for (int num : numsProb8) {
            for (int j = targetProb8; j >= num; --j) {
                dpProb8[j] = dpProb8[j] || dpProb8[j - num];
            }
        }
        return dpProb8[targetProb8];
    }
};