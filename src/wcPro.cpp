#include "wcPro.h"
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define IS_WORD  1
#define NOT_WORD 0

#define SPACE           1
#define WORD            2

#define OUTPUT_SIZE  100


using namespace std;


typedef pair<string, size_t> PAIR;

/*
**function: compare two vectors, firstly consider value
**otherwise consider key
*/
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs)
{
    return (lhs.second != rhs.second) ? lhs.second > rhs.second : lhs.first < rhs.first;
}


/*
**constructed function
*/
WcPro::WcPro(char *textBuf)
{
    this->textBuf = textBuf;
    this->word_num = 0;
}


/*
**destructor
**free memory, prevent memory leak
*/
WcPro::~WcPro()
{
    delete textBuf;
}


/*
**function: process text and get statistical result
*/
void WcPro::processText()
{
    /*state val and initialize them*/
    char c;                     //visit all char and process it
    char *pText = textBuf;      //a copy from private member val
    int word_flag = NOT_WORD;   //mark current word state
    int state = SPACE;          //DFA state
    vector<char> tmp;           //temporary val to store a word
    string word;                //vector transfer string

    /*loop process each char*/
    while((c = *pText++) != '\0')
    {
        if(SPACE == state && isalpha(c))
        {
            state = WORD;
            tmp.push_back(c);
        }

        else if(WORD == state)
        {
            if( isalpha(c) || '-' == c )
                tmp.push_back(c);
            else
            {
                state = SPACE;
                word_flag = IS_WORD;
            }
        }


        /*if we can sure current state is IS_WORD then
        process this word*/
        if(IS_WORD == word_flag)
        {
            word_flag = NOT_WORD;       //word_flag set NOT_WORD, make sure next loop success
            while(tmp.back() == '-')    //process table----
                tmp.pop_back();
            word.assign(tmp.begin(), tmp.end());    //vector transfer string
            transform(word.begin(), word.end(), word.begin(), ::tolower);   //word transfer lower
            this->word_count[word] += 1;        //count word
            tmp.clear();                        //clear vector and goto next loop
            this->word_num += 1;
        }
    }
}


/*
**function: sort each vector and print them
*/
void WcPro::print()
{
    vector<PAIR> word_count_vector(word_count.begin(), word_count.end());
    sort(word_count_vector.begin(), word_count_vector.end(), cmp_by_value);

    cout << "There are " << word_num << " elements\n\n";
    //freopen("result.txt", "w", stdout);
    for(int i = 0; i != word_count_vector.size() /*&& i < OUTPUT_SIZE*/; ++i)
        cout << word_count_vector[i].first << " " << word_count_vector[i].second << endl;
}
