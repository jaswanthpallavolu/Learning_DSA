// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

#include <iostream>
#include<vector>
#include <map>
#include<bits/stdc++.h>
using namespace std;


int main(){
    
    vector<int> tops={1,2,1,1,1,2,2,2};
    vector<int> bottoms={2,1,2,2,2,2,2,2};
    int N= tops.size();
    map<int ,int> tmap;
    map<int ,int> bmap;
    // cout << tmap[2];

    for(int i=0;i<tops.size();i++){
        tmap[tops[i]]++;
        bmap[bottoms[i]]++;
    }
    // cout << tmap.size() << bmap.size() <<endl;
    // cout << tmap.at(0) ;
    // cout << tmap.begin()->first;
    // map<int,int>::iterator curr;
    auto topHighest=tmap.begin(),bottomHighest=bmap.begin();
    
    // sort(tmap.begin(),tmap.end());

    //finding key with max value 
    for ( auto curr=tmap.begin();curr!=tmap.end();curr++){
        // cout << '('<<curr->first<<","<<curr->second<<')' << " ";
        if(topHighest->second < curr->second) topHighest = curr;
    }
    // cout << endl;
    for (auto curr=bmap.begin();curr!=bmap.end();curr++){
        // cout << '('<<curr->first<<","<<curr->second<<')' << " ";
         if(bottomHighest->second < curr->second) bottomHighest = curr;
    }

    cout << endl;
    cout << "keys with max value " << topHighest->first <<',' << bottomHighest->first <<endl;
    int count=0;
    if(topHighest->second < bottomHighest->second) {
        tops.swap(bottoms);
        topHighest=bottomHighest;
    }

    for(int i=0;i<N;i++){
            if(tops[i] != topHighest->first && bottoms[i] == topHighest->first){
                ++count; 
            }else if(tops[i] != topHighest->first && bottoms[i] != topHighest->first){
                count = -1;
                break;
            }
        }

    cout << "possible rotations: " << count;
    return 0;
}