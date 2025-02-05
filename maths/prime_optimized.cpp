#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n <= 1){
        return false;
    }
    if(n==2){
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for(int i = 3; i <= n; i+=2){
        if(n%i == 0){
            return false;
        }
    return true;
    }   
}

int main(){
    int n;
    cin >> n;
    cout<<"Enter a number to check prime or not";
    if(isPrime(n)){
        cout<<n<<" It is a prime number";
    }
    else{
        cout<<n<<" It not a prime number";
    }
}