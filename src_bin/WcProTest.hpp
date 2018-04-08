#ifndef WCPROTEST_H_
#define WCPROTEST_H_

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "wcPro.h"

#define FORMAT make_pair<string,int>


#define DECLARE_VAL  char *textBuf;\
                     vector<PAIR> vecTest, vecAc;


#define PROCESS     WcPro wcpro(textBuf);\
                    wcpro.processText();\
                    wcpro.getVal(vecTest);


TEST(WcProTest, mainPath)
{
    DECLARE_VAL;

    textBuf = "hello ";
    vecAc.push_back(FORMAT("hello", 1));
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath1)
{
    DECLARE_VAL;

    textBuf = "-wc ";
    vecAc.push_back(FORMAT("wc", 1));
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath2)
{
    DECLARE_VAL;

    textBuf = "content-based\n\n ";
    vecAc.push_back(FORMAT("content-based", 1));
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath3)
{
    DECLARE_VAL;

    textBuf = "hello---- ";
    vecAc.push_back(FORMAT("hello", 1));
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}



TEST(WcProTest, ifPath4)
{
    DECLARE_VAL;

    textBuf = "let's ";
    vecAc.push_back(FORMAT("let", 1));
    vecAc.push_back(FORMAT("s", 1));
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}



TEST(WcProTest, ifPath5)
{
    DECLARE_VAL;

    textBuf = "TABLE1_2 ";
    vecAc.push_back(FORMAT("table", 1));
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath6)
{
    DECLARE_VAL;

    textBuf = "(see Box 3 - 2).8885d_c01_016 ";
    vecAc.push_back(FORMAT("box", 1));
    vecAc.push_back(FORMAT("c", 1));
    vecAc.push_back(FORMAT("d", 1));
    vecAc.push_back(FORMAT("see", 1));
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath7)
{
    DECLARE_VAL;

    textBuf = "f\n\t\n\n ";
    vecAc.push_back(FORMAT("f", 1));
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}



TEST(WcProTest, ifPath8)
{
    DECLARE_VAL;

    textBuf = "aa=+23%^ ";
    vecAc.push_back(FORMAT("aa", 1));
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath9)
{
    DECLARE_VAL;

    textBuf = "a a a ";
    vecAc.push_back(FORMAT("a", 3));
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}



TEST(WcProTest, ifPath10)
{
    DECLARE_VAL;

    textBuf = "a a a b b ";
    vecAc.push_back(FORMAT("a", 3));
    vecAc.push_back(FORMAT("b", 2));

    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath11)
{
    DECLARE_VAL;

    textBuf = "d f s a ";
    vecAc.push_back(FORMAT("a", 1));
    vecAc.push_back(FORMAT("d", 1));
    vecAc.push_back(FORMAT("f", 1));
    vecAc.push_back(FORMAT("s", 1));

    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath12)
{
    DECLARE_VAL;

    textBuf = "hello, world\n ";
    vecAc.push_back(FORMAT("hello", 1));
    vecAc.push_back(FORMAT("world", 1));

    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}



TEST(WcProTest, ifPath13)
{
    DECLARE_VAL;

    textBuf = "fuck, fuck, fuck!!!hello, hello, hi ";
    vecAc.push_back(FORMAT("fuck", 3));
    vecAc.push_back(FORMAT("hello", 2));
    vecAc.push_back(FORMAT("hi", 1));

    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}

TEST(WcProTest, ifPath14)
{
    DECLARE_VAL;

    textBuf = "a + b = c\n b_c- ";
    vecAc.push_back(FORMAT("b", 2));
    vecAc.push_back(FORMAT("c", 2));
    vecAc.push_back(FORMAT("a", 1));

    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}

TEST(WcProTest, ifPath15)
{
    DECLARE_VAL;

    textBuf = "\n\n\n ";

    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath16)
{
    DECLARE_VAL;

    textBuf = "-a--- ";
    vecAc.push_back(FORMAT("a", 1));

    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath17)
{
    DECLARE_VAL;

    textBuf = "c\n\nf-a ";
    vecAc.push_back(FORMAT("c", 1));
    vecAc.push_back(FORMAT("f-a", 1));

    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}



TEST(WcProTest, ifPath18)
{
    DECLARE_VAL;

    textBuf = "\t\r#$%^&&**((";

    PROCESS;
    EXPECT_EQ(vecTest, vecAc);

}


TEST(WcProTest, ifPath19)
{
    DECLARE_VAL;

    textBuf = "1234546767 9809 ";
    PROCESS;

    EXPECT_EQ(vecTest, vecAc);

}
/*

*/

#endif // WCPROTEST_H_
