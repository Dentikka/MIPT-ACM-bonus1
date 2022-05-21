#include <StringFunctions.h>

int Overlap(const string& s1, const string& s2) {
    int s1last = s1.length() - 1;
    int s2len = s2.length();
    int overlap = 0;
    for (int i = s1last, j = 0; (i >= 0) && (j < s2len);
         --i, ++j) {
        string suff = s1.substr(i, s1last+1-i);
        string pref = s2.substr(0, j+1);
        if (suff == pref) {
            overlap = j;
        }
    }
    return overlap+1;
}


string Prefix(const string& str_1, int overlap) {
    return str_1.substr(0, str_1.length() - overlap);
}

