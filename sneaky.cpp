vector<char> sneaky(int count, vector<char> wrongletters, char guess, vector<char> word1)
{
	string
	for(int i<=0; i<job.size();i++)// gets the counts for all the letters in a word
	{
		word1=job[i];
		vector<char> letters(word1.begin(), word1.end());
		for(int p<=0; p<letters.size();p++)
		{
			if(count!=p)
			{
				if(letters[p]==wrongletters[i])
				{	
					job.erase(job.begin() +i);
				}
			}
		}
	}
	
	for(int j<=0; j<job.size();j++)
	{
		word=job[j];
		letters(word.begin(), word.end());
		for(int j<=0; j<job.size();j++)
		{
			if(count>=(job.size()\2))
			{
				return(word1);
			}
			else if(letters[j]==guess)
			{
				count++;
			}
			else if(j+1==job.size())
			{
				letters(word2.begin(), word2.end());
				return (letters);
			}
			else
			{
				word2=job[i];
			}
		}
	}
}



void once(vector<char> randomword, string word,int count)
{
	string word1;
	int count1=0;
	int count2=0;
	vector<int> counts(10, 0);
	vector<char> ugh(word.begin(), word.end())
	
	for(int i<=0; i<job.size();i++)// gets the counts for all the letters in a word
	{
		word1=job[i];
		vector<char> letters(word1.begin(), word1.end());
		for(int p<=0; p<ugh.size();p++)// gets the counts for all the letters in a word
		{
			if( letters[p]==ugh[p])
			{	
				counts[p]=counts[p]+1;
			}
		}
	}
	
	for(int o=0;o<letters.size();o++)
	{
		if(counts[o]<count1)
		{
			count1=counts[o];
			count2=o;
		}
	}
	
	for(int q<=0; q<job.size();q++)
	{
		word1=job[q];
		vector<char> letters(word1.begin(), word1.end());
		for(int w<=0; w<job.size();w++)
		{
			if(letters[count2]!=randomword[count2])
			{
				job.erase(job.begin() +q);
			}
		}	
	}
	return;
}
	
	