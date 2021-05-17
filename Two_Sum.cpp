
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include <numeric>
using namespace std;

void print(vector<int>&& vec)
{
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

vector<int> twoSum(vector<int> nums, int target) {
    vector<int> index(2);
    int n = nums.size();
    for(int i = 0; i < n ; i++) {
        index[0] = i+1;
        for(int j = i+1 ; j < n ; j++) {
            if(nums[i] + nums[j] == target){
                index[1] = j+1;
                return index;
            }
        }
    }
    return index;
}

int main(){

    vector<int>vec(10);
    iota(vec.begin(), vec.end(),0);
    
    for(auto elm:vec){ cout << elm;}
    cout<< endl;
    print(twoSum(vec,19));
    return 0;
}