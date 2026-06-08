// The question says that an array is given and 2 players are playing first turn p1-> it picks the first element adds to his score and remove the 
//element from the array.next p2 plays. if any one of the player picks even number then reverse the array.

// 1 3 4 6 3 7  -> 1 3 4 6 3 7 -> 1 3 4 6 3 7 -> 1 3 4 6 3 7 -> 1 3 4 6 3 7-> 1 3 4 6 3 7
// S         E       S       E        S     E          S   E          S E          S=E
// so the algo is if take a start and end pointer and if even then start taking from the other pointers.
#include <bits/stdc++.h>
using namespace std;

//function to get scores
int gameScoreDiff(vector<int>& arr){
    int start=0,end=arr.size()-1;
    bool turn=true;
    int rev=0;
    bool isrev=true;
    int p1=0,p2=0;
    while(start!=end){
     if(turn){
        p1+=arr[start];
     }
     else{
        p2+=arr[start];
     }
     turn=!turn;
     if(arr[start]%2==0){rev++;isrev=true;}
     else{isrev=false;}
     if(isrev && rev%2==1){
      start++;
      swap(start,end);
     }
     else if(isrev && rev%2==0){
       start--;
       swap(start,end);
     }
     else{
        if(rev%2==0){
            start++;
        }
        else start--;
     }
    }
    if(turn)p1+=arr[start];
    else p2+=arr[start];
    return abs(p2-p1);
}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Difference between score of p1 and p2 is:"<<gameScoreDiff(arr)<<endl;
}