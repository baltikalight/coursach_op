#ifndef MY_LAB_H
#define MY_LAB_H

#include <vector>

int calculateCost(const std::vector<std::vector<int>>& costMatrix, const std::vector<int>& assignment);
int greedyAlgorithm(const std::vector<std::vector<int>>& costMatrix, std::vector<int>& assignment);

#endif // MY_LAB_H
