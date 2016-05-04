#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Dictionary
{
public:
	void DisplayAll();				/*按照英文单词：中文意思的格式输出所有词条*/
	void DelItem(string word);		/*删除某个英文单词对应的词条*/
	void AddItem(string word, string explanation);		/*增加一个词条*/
	string Lookup(string);			/*查找某个英文单词对应的中文意思，如果没有该单词，则返回“没有该词条”*/
private:
	map<string, string> dict;
};
#endif
