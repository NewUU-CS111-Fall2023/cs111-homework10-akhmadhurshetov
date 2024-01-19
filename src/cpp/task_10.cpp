/*
 * Author: Axmad Xurshetov
 * Date: 19.01.2024
 * Name:
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Problem10 {
public:
    static std::string generate3SATFormula(int numVariables, int numClauses) {
        std::string formula;
        std::srand(std::time(nullptr));

        for (int i = 0; i < numClauses; ++i) {
            std::string clause = "(";
            for (int j = 0; j < 3; ++j) {
                int var = std::rand() % numVariables + 1;
                bool negation = std::rand() % 2;
                clause += (negation ? "~" : "") + std::string(1, 'A' + var - 1);
                if (j < 2) clause += " | ";
            }
            clause += ")";
            if (i < numClauses - 1) clause += " & ";
            formula += clause;
        }

        return formula;
    }
};