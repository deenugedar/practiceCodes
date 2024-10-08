#include<iostream>
#include<vector>
using namespace std;
  
void spiralMaker(vector<vector<int> > &vec){
    int left=0;
    int right=vec[0].size()-1;
    int top=0;
    int bottom=vec.size()-1;
    int direction=0;
    int value=1;
    while(top<=bottom&&left<=right){
        if(direction==0){
            for(int col=left;col<=right;col++){
                vec[top][col]=value++;
            }
            top++;
        }
        else if(direction==1){
            for(int row=top;row<=bottom;row++){
                vec[row][right]=value++;
            }
            right--;
        }else if(direction==2){
            for(int col=right;col>=left;col--){
                vec[bottom][col]=value++;
            }
            bottom--;
        }else{
            for(int row=bottom;row>=top;row--){
                vec[row][left]=value++;
            }
            left++;
        }
        direction=(direction+1)%4;
    }
}

int main(){
    int m;
    cin>>m;
    vector<vector<int> > vect(m,vector<int>(m));
    
    spiralMaker(vect);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }
}