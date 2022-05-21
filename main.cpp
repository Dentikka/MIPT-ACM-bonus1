#include "StringFunctions.h"
#include "Solver.h"

int main() {
    int n;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    Solver solver(strings);
    string superstring = solver.Solve();
    cout << superstring;
}


