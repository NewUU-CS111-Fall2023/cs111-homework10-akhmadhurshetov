/*
 * Author: Axmad Xurshetov
 * Date: 19.01.2024
 * Name:
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Problem9 {
public:
    static bool isSatisfied(const std::vector<std::vector<int>>& clauses, const std::unordered_map<char, bool>& assignment) {
        for (const auto& clause : clauses) {
            bool clauseResult = false;
            for (int var : clause) {
                char varName = std::abs(var) + 'A' - 1;
                bool varValue = var > 0 ? assignment.at(varName) : !assignment.at(varName);
                clauseResult |= varValue;
                if (clauseResult) break;
            }
            if (!clauseResult) return false;
        }
        return true;
    }
};