#include <iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int m=3;
    int arr[m][m]={1,2,3,4,5,6,7,8,9};

    for(int i=0;i<m;i++){
        int x=i,y=0;
      
        if(x==m-1){
            for(int j=0;j<m;j++){
                x=i;
                y=j;
                while((x>=0) && (y<m)){
                    cout << arr[x--][y++] << " ";
                }
                cout << endl;
            }
        }else{
          
            while((x>=0) && (y<m)){
                cout << arr[x--][y++] << " ";
            }
            cout << endl;
        }

        
    }

    return 0;
}