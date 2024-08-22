#include<iostream>
using namespace std;
#include<string>
int maze(int cr,int cc , int er, int ec){
    int rightWay=0,downWay=0,totalWays;
    if(cr==er && cc == ec){
        return 1 ;
    }
    if(cr==er){
       downWay+=maze(cr,cc+1,er,ec);
    }
    if(cc==ec){
        rightWay+=maze(cr+1,cc,er,ec);
    }
    if(cr<er && cc<ec){
       downWay+=maze(cr,cc+1,er,ec);
        rightWay+=maze(cr+1,cc,er,ec);
    }
   totalWays=rightWay+downWay;
   return totalWays;
}
int main(){
    int n;
    cout<<"Enter the value of A ";
    cin>>n;
    int m;
    cout<<"Enter the value of B ";
    cin>>m;
    int ans = maze(1,1,n,m);
    cout<<ans;

}


// #include<iostream>
// using namespace std;

// int maze(int cr, int cc, int er, int ec) {
//     // Base case: If current position is the end position, return 1 (one valid path found)
//     if(cr == er && cc == ec) {
//         return 1;
//     }

//     // If the current position is out of bounds, return 0 (no valid path)
//     if(cr > er || cc > ec) {
//         return 0;
//     }

//     // Move right and down, and sum up the number of ways
//     int rightWay=0;
//     rightWay += maze(cr, cc + 1, er, ec);
//     int downWay=0;
//     downWay += maze(cr + 1, cc, er, ec);

//     return rightWay + downWay;
// }

// int main() {
//     int n, m;
//     cout << "Enter the value of A: ";
//     cin >> n;
//     cout << "Enter the value of B: ";
//     cin >> m;

//     // Call the maze function with start (1,1) and end (n,m)
//     int ans = maze(1, 1, n, m);
//     cout << "Number of ways: " << ans << endl;

//     return 0;
// }
