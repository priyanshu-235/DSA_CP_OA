// in this question we are given given a pile of boxes and we need to find the number of operations needed to equalize the boxes
//by reducing the size of bigger boxes to the next bigger box.

// simple logic we can sort and get prefix count-> when ever we get the the smaller value the operations= prev_big*(prev_number of boxes)
#include<bits/stdc++.h>
using namespace std;

//function to perform the count of operations

int countOperations( vector<int>& nums){
    sort(nums.begin(),nums.end(),greater<int>());

    int ops=0;
    int n=nums.size();
    for(int i=1;i<n;i++){
        ops+=(nums[i-1]-nums[i])*i;
    }
    return ops;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Total number of operations needed to equalized and minimize the boxes:"<<countOperations(nums)<<endl;
}