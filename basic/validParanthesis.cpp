#include <iostream>
#include<stack>
using namespace std;

bool validPar(string str){
    stack<char> stack;
for(int i=0;i<str.size();i++){
        if(str[i] == '{' ||  str[i] == '[' ||  str[i]== '('){
             stack.push(str[i]);
             continue;
        }
        if(stack.empty()) return false;
            switch(str[i]){
                case '}': if(stack.top()=='{') stack.pop();
                            else return false;
                            break;
                case ']':if(stack.top()=='[') stack.pop();
                            else return false;
                            break;
                case ')':if(stack.top()=='(') stack.pop();
                            else return false;
                            break;
            }
        
    }
    return stack.empty();
}
int main(){
    
    string str="{}(())";
    cout << validPar(str);

}