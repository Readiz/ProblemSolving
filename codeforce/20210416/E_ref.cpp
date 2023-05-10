#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
 
// Function to calculate nth permutation of string
void lex_permutation(ull k, ull n)
{
    // Creating an empty stack
    stack<int> s;
    string result;

    // Loop to generate the factroid
    // of the sequence
    for (int i = 1; i < str.size() + 1; i++) {
        s.push(n % i);
        n = n / i;
    }
 
    // Loop to generate nth permutation
    for (int i = 0; i < str.size(); i++) {
        int a = s.top();
        result += str[a];
        int j;
 
        // Remove 1-element in each cycle
        for (j = a; j < str.length(); j++)
            str[j] = str[j + 1];
        str[j + 1] = '\0';
        s.pop();
    }
 
    // Final answer
    cout << result << endl;
}
 
// Driver code
int main()
{
    string str = "abcde";
    long long int n = 11;
 
    lex_permutation(n, str);
    return 0;
}
