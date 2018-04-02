#ifndef WCPRO_H_
#define WCPRO_H_

#include <map>
#include <string>
#include <iostream>

using namespace std;

class WcPro
{
private:
    map<string, size_t> word_count;
    char *textBuf;
    int word_num;

public:
    WcPro(char *textBuf);
    ~WcPro();
    void processText();
    void print();
};
#endif // WCPRO_H_
