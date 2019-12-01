#include <string>
using namespace std;

/*
    Convert s into a nonnegative int that depends on all characters of s.
    */
unsigned int StringToInt(string s)
{
    int length = (int)s.length(); // number of characters in s
    unsigned int answer = 0;
    
    if (length % 2 == 1) {
        // length is odd
        answer = s.at(length - 1);
        length--;
    }

    // length is now even
    for (int i = 0; i < length; i += 2) {
        // do two characters at a time
        answer += s.at(i);
        answer += ((int) s.at(i+1)) << 8;
    }
    return answer;
}
