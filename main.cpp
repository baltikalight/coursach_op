#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include "my_lab.h"
#include "time.h"
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Couldn`t open file input.txt!" << endl;
        return 1;
    }

    int n;
    inputFile >> n; 

    vector<vector<int>> costMatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> costMatrix[i][j];
        }
    }
    inputFile.close();

 
    int minCostBruteForce = INT_MAX;
    unsigned int start_time2 = clock();
    vector<int> bestAssignmentBruteForce(n);

    vector<int> assignment(n);
    for (int i = 0; i < n; ++i) {
        assignment[i] = i;
    }

    do {
        int currentCost = calculateCost(costMatrix, assignment);
        if (currentCost < minCostBruteForce) {
            minCostBruteForce = currentCost;
            bestAssignmentBruteForce = assignment;
        }
    } while (next_permutation(assignment.begin(), assignment.end()));
    cout << "runtime = " << (clock() - start_time2) / 1000.0 << endl; 

    vector<int> bestAssignmentGreedy(n);
    unsigned int start_time1 = clock(); 
    int minCostGreedy = greedyAlgorithm(costMatrix, bestAssignmentGreedy);
    cout << "runtime = " << (clock() - start_time1) / 1000.0 << endl; 


    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Couldn`t open file input.txt!" << endl;
        return 1;
    }


    outputFile << "The results of the iterative algorithm:" << endl;
    outputFile << "Min cost: " << minCostBruteForce << endl;
    outputFile << "Workers -> Jobs:" << endl;
    for (int i = 0; i < n; ++i) {
        outputFile << "Worker " << i + 1 << " -> Job " << bestAssignmentBruteForce[i] + 1 << endl;
    }

    outputFile << endl << "The results of the greedy algorithm:" << endl;
    outputFile << "Min cost: " << minCostGreedy << endl;
    outputFile << "Workers -> Jobs:" << endl;
    for (int i = 0; i < n; ++i) {
        outputFile << "Worker " << i + 1 << " -> Job " << bestAssignmentGreedy[i] + 1 << endl;
    }

    outputFile.close();

    cout << "The solution is written to a file output.txt" << endl;
 
    return 0;
}
