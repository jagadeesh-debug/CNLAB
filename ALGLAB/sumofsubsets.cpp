#include <iostream>
#include <vector>
using namespace std;
void subsetSum(vector<int> &nums, vector<int> &subset, int index, int sum, int target)
{
    if (sum == target)
    {
        cout << "Subset: ";
        for (int x : subset)
            cout << x << " ";
        cout << endl;
        return;
    }
    if (index >= nums.size() || sum > target)
        return;
    subset.push_back(nums[index]);
    subsetSum(nums, subset, index + 1, sum + nums[index], target);
    subset.pop_back();
    subsetSum(nums, subset, index + 1, sum, target);
}
int main()
{
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;
    vector<int> subset;
    cout << "Subsets with sum " << target << ":" << endl;
    subsetSum(nums, subset, 0, 0, target);
    return 0;
}