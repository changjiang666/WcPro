// testWcfile.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "file.h"   //������󣬰����ļ���ȡ
#include<gtest/gtest.h>


//���ò�������
/*class ReadfileTest :public::testing::TestWithParam <const char* >
{

};*/

//����
TEST(ReadfileTest, fileread)
{
	printf("test0\n");
	EXPECT_THROW(readfile(" "),char*);	
};
TEST(ReadfileTest1, fileread)
{
	printf("test1\n");
	EXPECT_TRUE(readfile(".\\TestCase\\test1.txt")[0] == 'h');
};

TEST(ReadfileTest2, fileread)
{
	printf("test2\n");
	EXPECT_THROW(readfile("H:\\abc"), char*);
};

TEST(ReadfileTest3, fileread)
{
	printf("test3\n");
	EXPECT_THROW(readfile(".\\*"), char*);
};

TEST(ReadfileTest4, fileread)
{
	printf("test4\n");
	EXPECT_STREQ(readfile(".\\TestCase\\test2.txt"), "abc ");
};

TEST(ReadfileTest5, fileread)
{
	printf("test5\n");
	EXPECT_STREQ(readfile(".\\TestCase\\test3.txt"), "hello- ");
};


TEST(ReadfileTest6, fileread)
{
	printf("test6\n");
	EXPECT_STREQ(readfile(".\\TestCase\\test4.txt"), "let's ");
};


TEST(ReadfileTest7, fileread)
{
	printf("test7\n");
	EXPECT_STREQ(readfile(".\\TestCase\\test5.txt"), "a-b ");
};

TEST(ReadfileTest8, fileread)
{
	printf("test8\n");
	EXPECT_STREQ(readfile(".\\TestCase\\test6.txt"), "1_3 ");
};


TEST(ReadfileTest9, fileread)
{
	printf("test9\n");
	EXPECT_STREQ(readfile(".\\TestCase\\test7.txt"), "my you ");
};
//������Χ
//INSTANTIATE_TEST_CASE_P(fileread, ReadfileTest, testing::Values("",".\\TestCase\\test.txt","H:\\asdasd",".\\*"));
//INSTANTIATE_TEST_CASE_P(fileread, ReadfileTest, testing::Values(".\\TestCase\\test.txt"));

int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
	getchar();
	return 0;
}

