#ifndef WCPROTEST_H_
#define WCPROTEST_H_
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "wcPro.h"
#define TEST_NUM 20


#define FORMAT make_pair<string,int>

#define DECLAREVAL  int i;\
                    char *textBuf;\
                    vector<PAIR> vecTest, vecAc;

#define PROCESS     WcPro wcpro(textBuf);\
                    wcpro.processText();\
                    wcpro.getVal(vecTest);\
                    EXPECT_EQ(vecTest, vecAc);


TEST(WcProTest, mainPath)
{
    DECLAREVAL;
    textBuf = readfile("test0.txt");
    vecAc.push_back(FORMAT("hello", 1));
    PROCESS;
}


#endif // WCPROTEST_H_
