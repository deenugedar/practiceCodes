#include<vector>
#include<iostream>
using namespace std;
vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++){
        ans[i].resize(i+1);
        for(int j=0;j<=i;j++){
            if(j==0||j==i){
                ans[i][j]=1;
            }else{
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }
    }
    return ans;

}
int main(){
    int n;
    cin>>n;

    vector<vector<int>> pascal;

    pascal = pascalTriangle(n);
    for(int i=0;i<pascal.size();i++){
        for(int j=0;j<pascal[i].size();j++){
            cout<<pascal[i][j];
        }
        cout<<endl;
    }
}