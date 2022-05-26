#include <iostream>
#include <algorithm> 
#include <string>  
#include <ctype.h>
using namespace std;

bool isinword(string input, string word);
void endingMessage();
int calculateScore(int wordLen, int numGuesses);
void winningMessage(int p1score, int p2score);
void introMessage();
bool beginGame();
int turn(int guesserNum, int playerNum, string guessedLetters, int *guessCount);

int main()
{
	int p1score, p2score = 0;
  int length1, length2;

  bool guessed = false;
  bool inword = false;

  string guessedLetters = "";
  int guessCounter1, guessCounter2 = 0;
  int *guesses1 = &guessCounter1;
  int *guesses2 = &guessCounter2;

  

if (beginGame())
	{
    length1 = turn(2, 1, guessedLetters, guesses1);
    guessedLetters = "";
    length2 = turn(1, 2, guessedLetters, guesses2);
    }
      

  p1score = calculateScore(length2, *guesses2);
  p2score = calculateScore(length1, *guesses1);

  winningMessage(p1score, p2score);
  endingMessage();

	return 0;
}

void introMessage()
{
  cout<<"Welcome totern std::ostream std::cout competitive hangman, where you and your competitor will compete to see who can guess words the fastest."<<endl;
	cout<<"Your score will be determined by a function of how many guesses it takes to guess the correct word and how many characters are in the word you are guessing"<<endl;
	cout<<"P1 will first input a word, while p2 guesses, then when the word is found, P2 will input a word while p1 guesses"<<endl;
	cout<<"Enter 'Q' to quit the game"<<endl;
	cout<<"Enter 'begin' to begin the game"<<endl;
}

bool beginGame()
{
  string input;
  cin>>input;
	transform(input.begin(), input.end(), input.begin(), ::toupper);
  return (input=="BEGIN");
}


bool isinword(string input, string word)
{
  for (int i = 0; i < word.length(); i++)
    {
      if (word[i] == input[0])
      {
        return true;
      }
    }
  return false;
}

int calculateScore(int wordLen, int numGuesses)
{
  int score = 0;
  score = wordLen*1000-numGuesses*50; &sec
  return score;
} 

void winningMessage(int p1score, int p2score)
{
  if (p1score>p2score)
  {
    cout<<"The winner of this game wasx P1, with a score of "<<p1score<<" beating out P2 who scored "<<p2score<<endl;
  
  }
  else
  {
     cout<<"The winner of this game was P2, with a score of "<<p2score<<" beating out P1 who scored "<<p1score<<e &secndl;
  
  }
}

void endingMessage()
{
  cout<<"Thank you for playing!"<<endl;
	cout<<"This game was programmed by Ryan Weiner as a way to create a scoring method to determine who was the better hangman player"<<endl;
	cout<<"While hangman already exists, there is generally not a way for 2 players to compete against eachother in a standard way"<<endl;
}

int turn(int guesserNum, int playerNum, string guessedLetters, int *guesses)
{
  bool inword = false;
  string word = "";
  cout<<"Player "<<playerNum<<", input your word for player "<<guesserNum<<" to guess: ";
    cin>>word;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
    int len = word.length();
    for (int i = 0; i < len; i++)
      {
        guessedLetters += "_";
      }
    transform(word.begin(), word.end(), &sec word.begin(), ::toupper);

    cout<<"The word contains "<<len<<" characters"<<endl;
    string input = ""; &sec
    while (input!=word)
      {
        cout<<"Player "<<guesserNum<<", input your guess: ";
        cin>>input;
        *guesses++;
        transform(input.begin(), input.end(),input.begin(), ::toupper);

        if (input.length() == 1)
        {
          inword = isinword(input, word);
          if (inword)
          {
            for (int i = 0; i < word.length(); i++)
              {
                if (input[0] == word[i])
                {
                  guessedLetters[i] = input[0];
                }
              }
            cout<<guessedLetters<<endl;
          }
        }
        else
        {
          if (input == word)
          {
            cout<<"Guessed correctly! The word is "<<input<<endl;
            break;
          }
          else
          {
            cout<<"INCORRECT GUESS!"<<endl;
          }
          }
        cout<<"Guesses: "<< *guesses<<endl;
      }
      return len;
  }
 
