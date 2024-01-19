/*
 * Author: Axmad Xurshetov
 * Date: 19.01.2024
 * Name:
 */

#include <iostream>
#include <vector>
#include <cmath>

class Problem11 {
public:
    static bool isSatisfiable(const std::vector<std::vector<int>>& cnf_formula) {
        int numVariables = 0;
        for (const auto& clause : cnf_formula) {
            for (int var : clause) {
                numVariables = std::max(numVariables, std::abs(var));
            }
        }

        int totalCombinations = std::pow(2, numVariables);
        for (int i = 0; i < totalCombinations; ++i) {
            if (satisfiesAllClauses(cnf_formula, i, numVariables)) {
                return true;
            }
        }
        return false;
    }

private:
    static bool satisfiesAllClauses(const std::vector<std::vector<int>>& cnf_formula, int combination, int numVariables) {
        for (const auto& clause : cnf_formula) {
            bool clauseSatisfied = false;
            for (int var : clause) {
                bool varValue = combination & (1 << (std::abs(var) - 1));
                if (var < 0) varValue = !varValue;
                clauseSatisfied |= varValue;
                if (clauseSatisfied) break;
            }
            if (!clauseSatisfied) return false;
        }
        return true;
    }
};