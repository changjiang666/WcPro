#include <iostream>
#include <string>
#include "file.h"
#include "wcPro.h"
using namespace std;

int
main(/*int argc, char **argv*/)
{
    char *textBuf = readfile("test.txt");
    WcPro wcpro(textBuf);
    wcpro.processText();
    wcpro.print();
    return 0;
}
