#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    
    for(int i=1 ; i<=N ; i++){
        for(int a=1; a<i ; a++){
            cout<<' ';
        }
        
        for(int j=i; j<=N ; j++){
            cout<<"*";
        }
        cout<<'\n';
    }
}