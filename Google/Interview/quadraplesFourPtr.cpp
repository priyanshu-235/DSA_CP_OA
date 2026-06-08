//sorted arr given-> find i,j,k,l such that a[i]+a[j]<k1 & a[k]+a[l]<k2 where i<j<k<l;
//follow up-> if a[i]+a[k]<k1 & a[j]+a[l]<k2 is asked? 

//For the first part-> we move j and find min i for which 1st condition satisfies. then we coun the right part with O(n)-> classic pair finding
//O(n) for left_count for particular j and O(n)for right count-> O(n*2n)-> O(2n^2).
// but we can have left count in O(logn) time and right count at O(1) time (suffix array).
// for left count we can find min i such that a[i]>k1-a[j]-> BS 
// for right count we can do the same for each n. we have to count it in nlogn time-> suffix array.now for each j , s[j]=suffix of the array. 
//first find how many valid pairs i.e for any j min i such that a[j]>k2-a[i]--> and s[j] suffix till j.-> because all of the previous pairs are 
//also valid. overall T.C for this approach-O(nlogn)+O(nlogn) S.C=O(n);
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL)
//O(2*n^2)
//function to find valid pairs in o(n)-> two pointer
// int countRightValidPairs(vector<int>& arr, int i, int j, int target){
//     int count=0;
//     while(i<j){
//         if(arr[i]+arr[j]>target){
//            count+=j-i;
//            j--;
//         }
//         else i++;
//     }
//     return count;
// }
//function to find the minimum number a[i]>k-a[j];-> BS-> O(logn)
int findValidIdx(vector<int>& arr, int start , int end, int target){
    int mid;
    int ans=end;
    while(start<=end){
     mid=start+(end-start)/2;
     if(arr[mid]>=target){
       end=mid-1;
       ans=mid;
     }
     else{
      start=mid+1;
     }

    }
    return ans;
}

//function to find valid pairs in right-> O(nlogn) and suffix array-> S.C-> O(n)
vector<int> getRightValidPairSuffix(vector<int>& arr,int k2){
    int count=0;
    vector<int>suffix(arr.size()+1,0);
    int n=arr.size();
    for(int i=n-2;i>=0;i--){
       int idx=findValidIdx(arr,i+1,n,k2-arr[i]);
       count+=n-idx;
       suffix[i]=count;
    }
    for(int i=0;i<suffix.size();i++){
        cout<<suffix[i]<<" \n"[i==suffix.size()-1];
    }
    return suffix;
}
//function to find left_count in O(n)
// int countLeftValidPairs(vector<int>& arr, int i, int j, int target){
//     int count=0;
//     while(i<j){
//         if(arr[i]+arr[j]>target){
//            count+=j-i;
//            break;
//         }
//         else i++;
//     }
//     return count;
// }

//function to find left_count in log(n)
int countLeftValidPairs(vector<int>& arr, int start,int end, int target){
    int count=0;
    int mid;
    int j=end;
    int ans=end;
    while(start<=end){
     mid=start+(end-start)/2;
     if(arr[mid]<=target){
       start=mid+1;
       ans=mid;
     }
     else{
      end=mid-1;
     }
    }
    cout<<"Ans: "<<ans<<" ";
    return j-ans;
}
//function to count total i,j,k,l 
int countQuadraples(vector<int>& arr,int k1, int k2){
    int n=arr.size();
    int total_count=0;
    vector<int>suffix=getRightValidPairSuffix(arr,k2);
    //running a loop of j from 0 to n-1-> blue stick method-> partitioning the array at each index.
    // int i=0;
    // int l=n-1;
    // for(int j=0;j<n;j++){
    //     total_count+=countLeftValidPairs(arr,i,j,k1)*countRightValidPairs(arr, j+1,l,k2); //O(2n^2)
    // }
    for(int j=0;j<n;j++){
        int left_cnt=countLeftValidPairs(arr,0,j,k1-arr[j]);
        cout<<"left_cnt: "<<left_cnt<<" ";
        int right_cnt=suffix[j+1];
        cout<<"Right_cnt: "<<right_cnt<<" ";
        cout<<"curr_count: "<<"left_cnt*right_cnt: "<<left_cnt*right_cnt<<" ";
        total_count+=left_cnt*right_cnt;
        cout<<"total_count: "<<total_count<<endl;
    }
    return total_count;
}
void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k1,k2;
    cin>>k1>>k2;
    cout<<"Total count for this array: "<<countQuadraples(arr,k1,k2)<<endl;
}

signed main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}