#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//1480 Problem
vector<int> runningSum(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    result[0] = nums[0];

    for(size_t index = 1; index < nums.size(); ++index)
        result[index] += result[index - 1] + nums[index];

    return result;
}

//2574 Problem
vector<int> leftRightDifference(vector<int>& nums) {

    vector<int> result(nums.size(),0);
    vector<int> left_sum(nums.size(), 0);
    vector<int> right_sum(nums.size(), 0);

    for(size_t index = 1; index < nums.size(); ++index)
        left_sum[index] = left_sum[index-1] + nums[index - 1];

    for(int index = nums.size() - 2; index >= 0; --index)
        right_sum[index] = right_sum[index + 1] + nums[index + 1];

    for(int index = 0; index < left_sum.size(); ++index)
    {
        result[index] = abs(left_sum[index] - right_sum[index]);
    }

    return result;
}

//1732 Problem
int largestAltitude(vector<int>& gain)
{
    vector<int> res_vec(gain.size()+1, 0);
    for (size_t index = 1; index < res_vec.size(); ++index) {
        res_vec[index] = res_vec[index-1] + gain[index-1];
    }
    return *std::max_element(res_vec.begin(), res_vec.end());
}

//2848 Problem
int numberOfPoints(vector<vector<int>>& nums)
{
    vector<int> matrix(102, 0);

    //Set flags in matrix
    for (size_t index = 0; index < nums.size(); ++index) {
        matrix[nums[index][0]] += 1;
        matrix[nums[index][1] + 1] -= 1;
    }

    //Do prefix summ
    for (size_t index = 1; index < matrix.size(); ++index) {
        matrix[index] += matrix[index-1];
    }

    short counter = 0;

    for (size_t index = 0; index < matrix.size(); ++index) {
        if(matrix[index] > 0)
            ++counter;
    }
    return counter;
}

//1991 Problem
int findMiddleIndex(vector<int>& nums)
{
    vector<int> left_sum(nums.size(), 0);
    vector<int> right_sum(nums.size(), 0);

    int result = -1;

    for (int index = 1; index < left_sum.size(); ++index) {
        left_sum[index] = left_sum[index-1] + nums[index-1];
    }

    for(int index = nums.size() - 2; index >= 0; --index)
        right_sum[index] = right_sum[index + 1] + nums[index + 1];

    for (size_t index = 0; index < nums.size(); ++index) {
        if(left_sum[index] == right_sum[index]){
           result = index;
           break;
        }
    }

    return result;
}

//1893 Problem
bool isCovered(vector<vector<int>>& ranges, int left, int right)
{
    vector<int> matrix(52,0);
    bool result = false;

    for (size_t index = 0; index < ranges.size(); ++index) {
        matrix[ranges[index][0]] += 1;
        matrix[ranges[index][1] + 1] -= 1;
    }

    for (size_t index = 1; index < matrix.size(); ++index) {
        matrix[index] += matrix[index-1];
    }

    for (size_t index = left; index <= right; ++index) {
        if(matrix[index] == 0)
            return result;
    }
    result = true;
    return result;
}

int main()
{
    vector<vector<int>> nums {{1,10},{10,20}};
    cout << isCovered(nums, 1, 21);
    return 0;
}
