// The question says that an array is given and 2 players are playing first turn p1-> it picks the first element adds to his score and remove the 
//element from the array.next p2 plays. if any one of the player picks even number then reverse the array.

// 1 3 4 6 3 7  -> 1 3 4 6 3 7 -> 1 3 4 6 3 7 -> 1 3 4 6 3 7 -> 1 3 4 6 3 7-> 1 3 4 6 3 7
// S         E       S       E        S     E          S   E          S E          S=E
// so the algo is if take a start and end pointer and if even then start taking from the other pointers.
#include <bits/stdc++.h>
using namespace std;

//function to get scores
int gameScoreDiff(vector<int>& arr){
     int s=0,e=arr.size()-1;
     int p1=0,p2=0;
     bool turn = true;
     int rev=0;
     int last=0;
     while(s!=e){
      cout<<arr[s];
      if(turn){
        p1+=arr[s];
        cout<<"p1"<<p1<<endl;
      }
      else{
        p2+=arr[s];
        cout<<"p2"<<p2<<endl;
      }
      last=s;
      if(rev%2==0){
        s++;
      }
      else{
        s--;
      }
      if(arr[last]%2==0){
        swap(s,e);
        cout<<"swapped";
        rev++;
      }

      turn=!turn;
     }
     if(turn){
        p1+=arr[s];
     }
     else{
        p2+=arr[s];
     }
     return abs(p1-p2);
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