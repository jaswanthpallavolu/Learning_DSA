//(x1, y1) (x2,y2)

#include<bits/stdc++.h>
using namespace std;

void distance(int x1,int y1,int x2, int y2){
    cout <<"distance: " << sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int main(){
    int x1 = 2,y1=3,x2=4,y2=8;
    //distance(x1,y1,x2,y2);

    // x1,x2=x2,x1;

    int arr[] = {3,4,1,9,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int min;
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i+1;j<n;j++)
            if(arr[min]>arr[j]) min=j;
        swap(arr[i],arr[min]);
    }

    for(auto x:arr)
        cout << x <<", ";

    return 0;
}