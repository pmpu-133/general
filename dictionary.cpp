#include "pch.h"
#include <iostream>
#include <string>
#include "Vector.h"
#include "Section.h"
#include "list.h"
#include "arr.h"
#include "Hasht.h"
#include "AVL.h"
#include <fstream>
#include "hashstring.h"

using namespace std;

int main()
{
	avl<string, string> dictionary;
	fstream in("en_ru.txt", ios_base::in);
	string s;
	
	while (in)
	{
		bool t = false;
		string en = "", ru = "";
		getline(in, s);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '\t')
			{
				t = true;
			}
			else
				if (!t)
					en += s[i];
				else
					ru += s[i];
		}
		dictionary.push(en, ru);
	//	cout << en << endl;
	//	cout << en << "----" << ru << endl;
	}
	in.close();
	while (cin)
	{
		getline(cin, s);
		cout << dictionary[s] << endl;
	}
}
