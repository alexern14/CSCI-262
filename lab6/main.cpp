#include <iostream>

using namespace std;

void Sieve_of_Eratosthenes (int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p*p <= n; p++){
        if (prime[p] == true){
            for (int i = p*p; i <= n; i += p){
                prime[i] = false;
            }
        }
    }
    for (int p = 2;p <= n; p++){
        if (prime[p]){
            cout << p << " ";

        }
    }
}

int main(){
    int n;
    cout << "Input a maximum number: " ;
    cin >> n ;
    Sieve_of_Eratosthenes(n);
    return 0;
}