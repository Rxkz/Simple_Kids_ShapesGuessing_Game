#include <iostream>
#include <stack>// needed for stack list 
#include<cstdlib>// need this to used the rand or random fuction 


using namespace std;

void square(char x = '+')
{
	const int width = 4;
	const int height = 3;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << x;
		}
		cout << endl;
	}
}

void triangle(int n, char c = '+') {
	if (n < 0) {

		// flip to positive 

		n *= -1;

	}

	for (int k = 1; k <= n; k++)
	{

		for (int j = 1; j <= n - k; j++) {

			//cout << '-'; 

			cout << ' ';

		}
		for (int i = 1; i <= 2 * k - 1; i++) {

			cout << c;

		}
		cout << endl;
	}
}

void rectangle(int width, int height, char x = '+', char outline = '*')
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				cout << outline;
			}
			else
			{
				cout << x;
			}
		}
		cout << endl;
	}
}

int gameScore(int correctAns) 
{
	return correctAns * 10; // return answes multiply by 10
}

int main()
{
	stack<int>gameRCD;// made stack called gameRCD with int data type
	int score = 0;// set A score of 0 at starting 
	char playerinput;// player selection  choice 

	do // do this while it is true 
	{
		cout << " ::Main Menu::" << endl;
		cout << "1.Play" << endl;
		cout << "2.Final Score" << endl;
		cout << "3.Exit" << endl;
		cout << "Please Select a Option : ";
		cin >> playerinput; // get player input

		if (playerinput == '1') //if player inout is 1 then for 
		{
			for (int play = 0; play < 5; play++)// play  0 and make play turns less then 5 times 
			{
				gameRCD.push(play);// recors the play turn in my stack

			}

			while (!gameRCD.empty()) // run the stack while it reaches end 
			{
				int gshape = rand() % 3; // int game shapes random 3 times for 3 shapes 
				int size = rand() % 5 + 3;  // Random size between 3 and 7

				cout << " What Shape Is This ??" << endl; // ask about shape 

				switch (gshape)// switch case switch shapes 3 diffrent shapes 
				{
				case 0:
					square();// calling my shape function
					break;
				case 1:
					triangle(size);// giving it a size random display guide 
					break;
				case 2:
					rectangle(size,size+1);
					break;
				}

				cout << "1. Square\n2. Triangle\n3. Rectangle\n";
				cout << "Enter your guess (1-3): ";
				int guess;
				cin >> guess;// get user guess

				if (guess - 1 == gshape)// if user enter 1 or 2 or 3 subtract 1 from it as our range starts from 0 to 2 whuch has 3 elements thou
				{
					cout << " Correct!!" << endl;
					score += 10;
				}
				else
				{
					cout << "Wrong! The correct answer was " << gshape + 1 << ".\n";
				}

				gameRCD.pop();// remove the past guess that was entered last 

				cout << "Current score: " << score << endl;
				cout << "Enter 'q' to quit or any other key to continue: ";
				cin >> playerinput;
				if (playerinput == 'q' || playerinput == 'Q') {
					break;
				}

			}

		}
		else if (playerinput=='2')
		{
			cout << "Final Score: " << score << endl;
		}
		else if (playerinput=='3')
		{
			cout << "Thank you for playing!\n";
			return 0;
		}
		

	} while (true);

	return 0;
	
}

