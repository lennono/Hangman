#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector>
#include <time.h>
#include <algorithm>
#include <stdio.h>
#include "hangman10.h"
#include <algorithm>
using namespace std;
vector<string> job;
int count2;
Hangman10::Hangman10(vector<string> help)
{
	job=help;
}

Hangman10::Hangman10()
{}

/*vector<char> Hangman10::supersneaky(vector<char> word1, vector<char> usedletters)
{
	int count=0;
	string word;
	for(int d=0; d<word.size();d++)
	{
		for(int o=0; o<word1.size();o++)
		{
			word=job[d];
			vector<char> word3(word.begin(), word.end());
			if(word3[o]==word1[o])
			{
				count++;
			}
			else if(count==word1.size()-1)
			{
				if(d+1!=job.size())
				{
					word=job[d+1];
					break;
				}
			}
			if(count==word1.size())
			{
			vector<char> word3(word.begin(), word.end());
			return word3;
			}
			else count=0;
		}
		
	}
	
	//vector<char> word3(word.begin(), word.end());
	return word1;
}
*/
vector<char> Hangman10::sneaky(vector<char> wrongletters, char guess, vector<char> word1, int guesses, vector<char> usedletters)
{
	string word;
	string word2;
	int count=0;
	vector<char> cantuse;
	for(int d=0; d<wrongletters.size();d++)
		{
			for(int p=0; p<usedletters.size();p++)
			{
				if(wrongletters[d]==usedletters[p])
				{
					char ok=(wrongletters[d]);
					cantuse.push_back(ok);
					break;
				}
			}
		}
		
		
	for(int i=0; i<job.size();i++)
	{
		cout<< job[i]<< "\n";
	}
	cout<<"\n";
	
	for(int i=0; i<job.size();i++)
	{
		word=job[i];
		vector<char> letters(word.begin(), word.end());
		for(int j=0; j<letters.size();j++)
		{
			for(int d=0; d<cantuse.size();d++)
			{
				for(int p=0; p<wrongletters.size();p++)
				{
					if(letters[j]==wrongletters[p] && (job.size()!=1) && wrongletters[p]!=cantuse[d])
					{
					}
				}
			}
		}
	}
	
	
	
	for(int i=0; i<job.size();i++)
	{
		word=job[i];
		vector<char> letters(word.begin(), word.end());
		for(int d=0; d<letters.size();d++)
		{
			for(int p=0; p<cantuse.size();p++)
			{
					if(letters[d]==cantuse[p] && (job.size()!=1) && usedletters[d]!=cantuse[p])
					{	
						cout << job[i] << "\n";
						job.erase(job.begin() +i);
						break;
					}
			}
		}
	}
	int countcheck=0;
	for(int j=0;j <word1.size();j++)
	{
		word=job[j];
		vector<char> letters(word.begin(), word.end());
		for(int k=0;k <word1.size();k++)
		{
			if(usedletters[k]!='-' && job.size()!=1 && usedletters[k]!=letters[k])
			{
				job.erase(job.begin() +j);
				break;
			}
		}
	}
	for(int j=0;j <word1.size();j++)
	{
		if(guess==word1[j])
		{
			countcheck++;
		}
	}
	for(int j=0;j <job.size();j++)
	
	{
		word=job[j];
		vector<char> letters(word.begin(), word.end());
		for(int y=0; y<letters.size();y++)
		{
			if(count>=(job.size()/2)&& countcheck<=1)
			{
				return(word1);
			}
			else if(letters[y]==guess)
			{
				count++;
			}
			else if(j+1==job.size())
			{
				vector<char> letters(word2.begin(), word2.end());
				cout<<word2;
				return (letters);
			}
			
			else
			{
				word2=job[j];
			}
		}
	}
}

void Hangman10::once(vector<char> randomword, string word)
{
	string word1;
	int count1=0;
	count2=0;
	vector<int> counts(10, 0);
	vector<char> ugh(word.begin(), word.end());
	cout<< "got here";
	for(int s=0; s<job.size(); s++)
	{
		word1=job[s];
		vector<char> letters(word1.begin(), word1.end());
		for(int p=0; p<ugh.size(); p++)
		{
			if(letters[p]==ugh[p])
			{	
				counts[p]=counts[p]+1;
			}
		}
	}
	for(int o=0;o<randomword.size();o++)
	{
		if(counts[o]<count1)
		{
			count1=counts[o];
			count2=o;
		}
	}
	for(int q=0; q<job.size();q++)
	{
		word1=job[q];
		vector<char> letters(word1.begin(), word1.end());
		for(int w=0; w<job.size();w++)
		{
			if(letters[count2]!=randomword[count2])
			{
				job.erase(job.begin() +q);
			}
		}
	}
	return;
}

void Hangman10::compare(string word)
{
	int guesses=10;
	vector<char> letters(word.begin(), word.end());
	vector<char> wrongletters(10, ' ');
	vector<char> usedletters(letters.size(),char('-'));
	once(letters, word);
	help(letters, usedletters, wrongletters, guesses);
	return;
}

int Hangman10::help(vector<char> letters,vector<char> usedletters, vector<char> wrongletters, int guesses)
{
	char guess;
	int count1=0;
	int bye=0;
	int messing=0;
	for(int l=0; l<letters.size();l++)
	{
		if(letters[l]==usedletters[l]) 
		{
			count1++;
		}			
	}
	if(count1==letters.size())
	{
		cout << "\nYou win well done!";
		return 1;
	}
	if(guesses==0)// 
	{
		cout << "\nYou lose";
		return 0;
	}
		if (guesses==1)
		{
			cout << "\nYou have "<< guesses <<" guess left";
		}
		else
		{
			cout << "\nYou have "<< guesses <<" guesses left";
		}
		cout << "\nUsed letters:";
		if(guesses<= 9)
		{
			for(int j=0;j<wrongletters.size();j++)
			{
				cout<< " " << wrongletters[j];
			}
		}
		cout << "\nWord: ";
	for(int i=0;i<usedletters.size();i++)
	{
		cout<< usedletters[i];
	}
	cout << "\nEnter guess: ";
	cin >> guess;
	//while()
	//{
		for(int o=0;o<wrongletters.size();o++)// only dodgey part  
		{
			if (guess==wrongletters[o])
			{
				cout<< "Already entered, enter a new guess: ";
				cin >> guess;
			}
		}
	//}
	if(job.size()>1)
	{
		letters=sneaky(wrongletters, guess, letters, guesses, usedletters);
		cout<<letters[0];
		cout<<letters[1];
		cout<<letters[2];
		cout<<letters[3];
	}
	//if (guesses<=6)
	//{
		//letters=supersneaky(letters, usedletters);
	//}
	for(int p=0;p<letters.size();p++)
	{
		if(guess==letters[p])
		{
			if (bye==0)
			{
				cout<< "Yes, there is a copy of: "<< guess << "\n";
				usedletters[p]=guess;
				wrongletters[10-guesses]=(guess);
				bye++;
			}
			else
			{
				cout<< "There are multiple uses of "<< guess <<", goodjob.\n"; 
				usedletters[p]=guess;
				wrongletters[10-guesses]=(guess);
				bye++;
			}
		}
	else if(p+1==letters.size())
	{
		if(bye<1) 
			{
				cout << "Sorry there is no copy of:" << guess <<"\n";
				wrongletters[10-guesses]=(guess);
			}
		}
	}
	guesses--;
	return(help(letters,usedletters,wrongletters,guesses));
}
