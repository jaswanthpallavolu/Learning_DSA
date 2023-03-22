#include <iostream>
#include <map>
#include <unordered_map>
#include<vector>
#include<string>
using namespace std;

bool isValid(string s)
{
    std::map<char, int> m = {
        {'(', 1},
        {')', 2},
        {'[', 3},
        {']', 4},
        {'{', 5},
        {'}', 6}};
    int N = s.length();
    if (N % 2 != 0)
        return false;
    for (int i = 0; i + 1 < N; i++)
    {

        if (m[s[i]] % 2 != 0)
        {
            if (m[s[i]] + 1 == m[s[i + 1]])
            {
                i++;
                continue;
            }
            if (m[s[i]] + 1 == m[s[N - 1 - i]])
                continue;
            else
                return false;
        }
    }
    return true;
}

bool validAnagram(string s, string t){
    if(s.length() != t.length()) return false;
    std::unordered_map<char, int> m;
    
    for(auto i=s.begin();i!=s.end();i++)
        m[*i] += 1;

    for(auto j=t.begin();j!=t.end();j++){
        if(m[*j]){
            m[*j] -= 1;
            if(m[*j] == 0) m.erase(*j);
        }else return false;
    }
    if(m.empty()) return true;
    return false;

}

void groupAnagrams(vector<string> strs){
    vector<vector<string>> arr;
    vector<string> t; 
    std::unordered_map<int, int> used;
    std::unordered_map<char, int> m;
    int N = strs.size();
//  && (used[strs[i]]==0)
    for(int i=0; (i <N) ; i++){
        if (used[i]==0){
        // cout <<"l1 " << strs[i] << endl;
        used[i] = 1;
        t.push_back(strs[i]);
 

        for(int j=i+1; (j<N); j++){
            if(used[j]==0){
            // cout <<"l2 " << strs[j] << endl;
            bool isValid = false;
            if(strs[i].length() == strs[j].length()){
           
            for(auto x=strs[i].begin();x!=strs[i].end();x++)
                m[*x] += 1;

            for(auto y=strs[j].begin();y!=strs[j].end();y++){
                // cout << "l3" <<endl;
                if(m[*y]){
                    m[*y] -= 1;
                    if(m[*y] == 0) m.erase(*y);
                    // continue;
                }
                else break;
            }
            if(m.empty()) isValid=true;
            }

            if(isValid){
                used[j] = 1;
                t.push_back(strs[j]);
            }
            m.clear();
            }
        }
        // int s = arr.size();
        arr.push_back(t);
        t.clear();
        // continue;
        }
    }
 
 
    for(int i=0;i<arr.size();i++){
        cout << i << "->  ";
        for(int j=0;j<arr[i].size();j++){
            cout << arr[i][j] << ", ";
        }
        cout << endl;
    }

}

int main()
{

    // cout << isValid("([])");
    
    // string s = "anagram";
    // string t = "nagaram";
    // cout <<"is validAnagram: "<< validAnagram(s,t);

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    // vector<string> strs = {"anagram","nagaram"};

    groupAnagrams(strs);
    
    return 0;
}