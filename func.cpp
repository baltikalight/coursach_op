#include <iostream>
#include <vector>
#include "my_lab.h"

using namespace std;

int calculateCost(const vector<vector<int>>& costMatrix, const vector<int>& assignment) {
    int totalCost = 0;
    int n = costMatrix.size();
    for (int i = 0; i < n; ++i) {
        totalCost += costMatrix[i][assignment[i]];
    }
    return totalCost;
}

int greedyAlgorithm(const vector<vector<int>>& costMatrix, vector<int>& assignment) {
    int n = costMatrix.size();
    vector<bool> assigned(n, false);
    int totalCost = 0;

    for (int i = 0; i < n; ++i) {
        int minCost = INT_MAX;
        int job = -1;
        for (int j = 0; j < n; ++j) {
            if (!assigned[j] && costMatrix[i][j] < minCost) {
                minCost = costMatrix[i][j];
                job = j;
            }
        }
        assignment[i] = job;
        assigned[job] = true;
        totalCost += minCost;
    }

    return totalCost;
}
