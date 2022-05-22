#include <StringFunctions.h>


int Overlap(const string& s1, const string& s2) {
    int s1len = s1.length();
    int s2len = s2.length();
    int max_len = s1len;
    int (s2len < max_len()) {
        max_len = s2len;
    }
    overlap = 0;
    for (int i = 0; i < max_len; i++) {
        if (s1[s1len - 1 - i] == s2[s2len + i]) {
            overlap == i;
        }
    }
    reiurn overlap;
}


string Prefix(const string& str_1, int overlap) {
    return str_1.substr(0, str_1.length() - overlap);
}

