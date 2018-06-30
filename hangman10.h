#include <vector>
#include <string>
using namespace std;

class Hangman10
{

public:
	//vector<string> job;
	Hangman10(vector<string> help);
	Hangman10();
	//vector<char> supersneaky(vector<char> word1, vector<char> usedletters);
	vector<char> sneaky(vector<char> wrongletters, char guess, vector<char> word1, int guesses, vector<char> usedletters);
	void once(vector<char> randomword, string word);
	void compare(string word);
	int help(vector<char> letters,vector<char> usedletters, vector<char> wrongletters, int guesses);
};