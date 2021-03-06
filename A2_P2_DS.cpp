// Data Structures Assignment Two Problem 2
// Authors: 
// Shereen Hassan	ID-20170130
// Salma Essam		ID-20170115

#include <iostream>
#include <map>
#include <string>
#include <iterator> 


using namespace std;

	multimap <string, int> map1;
	multimap <string, int>::iterator itr1;
	multimap <string, int>::iterator match;
	
	map<string, int> map2;
	map <string, int>::iterator itr2;

void print();
void remove_duplicates();
void modify();
int main()
{
	string word = "";
	int count = 0;

	
	cout << "\nEnter word & enter done to exit: \n>>";
	cin >> word;

	for (int i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}



	while (word != "done")
	{
		map1.insert(pair<string, int>(word, 0));

		cout << "\nEnter word & enter done to exit: \n>>";
		cin >> word;

		for (int i = 0; i < word.length(); i++)
		{
			word[i] = tolower(word[i]);
		}

	}

	cout << "\nFirst print: \n";
	remove_duplicates();
	print();
	cout << endl;
	
	cout << "\nAfter modification: \n";
	modify();
	print();
	

    return 0;
}

void remove_duplicates()
{
	for (itr1 = map1.begin(); itr1 != map1.end(); ++itr1)
	{
		map2.insert(pair<string, int>(itr1->first, itr1->second));
	}
}

void print()
{
	for (itr2 = map2.begin(); itr2 != map2.end(); ++itr2)
	{
		cout << "Word: " << itr2->first << ", ";
		itr2->second = map1.count(itr2->first);
		cout << "Count: " << itr2->second << endl;
	}
}

void modify()
{
	itr2 = map2.begin();
	while (itr2 != map2.end())
	{
		if (itr2->first[0] == 'a')
		{
			map2.erase(itr2);
			itr2 = map2.begin();
		}
		else
		{
			++itr2;
		}
	}

}