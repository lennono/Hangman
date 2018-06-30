#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector>
#include <time.h>
#include <algorithm>
#include <stdio.h>
#include "hangman10.h"
using namespace std;

string getrandomword(vector<string> vec)
{
	string randomword;
	srand(time(NULL));
	randomword=vec[rand()%vec.size()+1];
	return randomword;
}

vector<string> getword(vector<string> allwords, int length)
{
	int count=0;
	vector<string> rightwords;
	while(count< allwords.size())
	{
		if(allwords[count].length()==length)
		{
			string helpw=allwords[count];
			rightwords.push_back(helpw);

		}
		count++;
	}
	return(rightwords);
}
vector<string> getvector(int length)
{
	string lol;
	vector<string> vec;
	ifstream input;
	input.open("directory.txt");
	while(input >> lol)
	{
		vec.push_back(lol);
	}
	vec=getword(vec, length);
	return(vec);
}

vector<string> difficultyMethod()
{
	string difficulty; vector<string> word;
	int length=0;
	while(length==0)
	{
	cout << "What mode would you like to play at, Easy, Medium or Hard? ";
	getline(cin, difficulty);
	
	if(difficulty=="Easy"||difficulty=="easy")
	{
		length=4;
		word=getvector(length);
	}
	else if(difficulty=="Medium"||difficulty=="medium")
	{
		length=6;
		word=getvector(length);
	}
	else if(difficulty=="Hard"||difficulty=="hard")
	{
		length=8;
		word=getvector(length);
	}
	else 
	{
		cout <<"Not vaild, Enter again\n";
	}
	}
return(word);
}


int main()
	{
		vector<string> word=difficultyMethod();
		//cout<< "got here";
		string gotword=getrandomword(word);
		cout<< gotword;
		//cout<< "got here";
		Hangman10 p(word);
		p.compare(gotword);
		//cout<< "\nThe word was " << gotword;
		return 0;
	}