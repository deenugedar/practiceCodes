#include <iostream>
#include <vector>
using namespace std;
// int calculateSum(vector<vector<int>> &v,int l1,int r1,int l2, int r2)
// {
//     int sum=0;
    
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 1; j < v[i].size(); j++)
//         {
//             v[i][j]=v[i][j]+v[i][j-1];
//         }
//     }

//     for (int i = l1; i <=l2; i++)
//     {
//         for(int j = r2; j<=r2;j++){
//            if(r1!=0){
//             sum+=v[i][r2]-v[i][r1-1];
//            }
//            else{
//             sum+=v[i][r2];
//            }
//         }
         
//     }
//     return sum;
// }
int calculateSum(vector<vector<int> > &vec,int l1,int r1,int l2,int r2){
    int n = vec.size();
    int m = vec[0].size();
    int sum;
    //prefix sum raw-wise;
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            vec[i][j]+=vec[i][j-1];
        }
    }
    //prefix sum column wise;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            vec[i][j]+=vec[i-1][j];
        }
    }
    if(r1>0&&l1>0){
         sum=vec[l2][r2]-vec[l1-1][r2]-vec[l2][r1-1]+vec[l1-1][r1-1];
    }else if(l1>0){
         sum = vec[l2][r2]-vec[l1-1][r2];
    }else if(r1>0){
         sum = vec[l2][r2]-vec[l2][r1-1];
    }else if(l1==0&&r1==0){
         sum = vec[l2][r2];
    }
     return sum;
}

int main()
{
    int n,m;
    cin >> n>>m;
    vector<vector<int>> vect(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vect[i][j];
        }
    }
    cout << endl;
    int l1,r1,l2,r2;
    cout<<"enter the value of l1 and r1 ";
    cin>>l1>>r1;
    cout<<"enter the value of l2 and r2 ";
    cin>>l2>>r2;
    cout<<"Array before prefix"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
    int ans=calculateSum(vect,l1,r1,l2,r2);
    cout<<"Array after prefix "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"calculated sum is "<<ans;
}