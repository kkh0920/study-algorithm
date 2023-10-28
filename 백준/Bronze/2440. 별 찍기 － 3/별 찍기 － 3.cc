#include <iostream>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    for(int i=1; i<=N ; i++){
        
        for(int a=i; a<=N ; a++){
            cout<<"*";
        }
        
        cout<<"\n";
    } 
    return 0;
}