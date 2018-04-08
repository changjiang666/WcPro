#include <iostream>
#include <gtest/gtest.h>
#include "file.h"
#include "wcPro.h"
#include "WcProTest.hpp"

#define DEBUG 0
using namespace std;


int
main(int argc, char **argv)
{
    #if DEBUG
    int filesize;
    char *textBuf = readfile(argv[1]);
    //cout << textBuf;
    WcPro wcpro(textBuf);
    wcpro.processText();
    wcpro.print();
    return 0;

    #else
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;

    #endif // DEBUG

}

