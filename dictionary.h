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
	void DisplayAll();				/*����Ӣ�ĵ��ʣ�������˼�ĸ�ʽ������д���*/
	void DelItem(string word);		/*ɾ��ĳ��Ӣ�ĵ��ʶ�Ӧ�Ĵ���*/
	void AddItem(string word, string explanation);		/*����һ������*/
	string Lookup(string);			/*����ĳ��Ӣ�ĵ��ʶ�Ӧ��������˼�����û�иõ��ʣ��򷵻ء�û�иô�����*/
private:
	map<string, string> dict;
};
#endif
