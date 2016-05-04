#include <iostream>
#include <map>
#include <string>
#include "dictionary.h"
using namespace std;

void Dictionary::DisplayAll()
{
	map<string, string>::iterator it;
	for (it = dict.begin(); it != dict.end(); it++)
		cout << it->first << ":" << it->second << endl;
}

void Dictionary::DelItem(string word)
{
	dict.erase(word);
}

void Dictionary::AddItem(string word, string explanation)
{
	dict.insert(make_pair(word, explanation));
}

string Dictionary::Lookup(string word)
{
	if (dict.find(word) != dict.end())
		return dict[word];
	else
		return string("Ã»ÓÐ´ÊÌõ");
}
