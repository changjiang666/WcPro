#ifndef WCPRO_H_
#define WCPRO_H_

#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<string, size_t> PAIR;

class WcPro
{
private:
    vector<PAIR> word_count_vec;
    map<string, size_t> word_count;
    char *textBuf;

public:
    WcPro(char *textBuf);
    ~WcPro();
    void processText();
    void print();
    void getVal(vector<PAIR> &vec);
};
#endif // WCPRO_H_
