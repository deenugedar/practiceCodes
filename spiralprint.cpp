#include<iostream>
#include<vector>
using namespace std;
void spiralPrint(vector<vector<int> > &vec){
    int left=0;
    int right=vec[0].size()-1;
    int top=0;
    int bottom=vec.size()-1;
    int direction=0;
    while(top<=bottom&&left<=right){
        direction=direction%4;
        if(direction==0){
            for(int col=left;col<=right;col++){
                cout<<vec[top][col]<<" ";
            }
            top++;
        }
        else if(direction==1){
            for(int row=top;row<=bottom;row++){
                cout<<vec[row][right]<<" ";
            }
            right--;
        }else if(direction==2){
            for(int col=right;col>=left;col--){
                cout<<vec[bottom][col]<<" ";
            }
            bottom--;
        }else{
            for(int row=bottom;row>=top;row--){
                cout<<vec[row][left]<<" ";
            }
            left++;
        }
        direction++;
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int> > vect(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>vect[i][j];
        }
    }
    spiralPrint(vect);
}