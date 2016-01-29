#include "gamemath.h"

int main()
{
	cout << "Please help me! I'm trapped!" << endl;
	cout << "The only way to save me is to answer my questions correctly." << endl;
	cout << "They are math problems and the more you get right, the harder they get." << endl;
	cout << "To go back to the main menu press -999" << endl;
	mathGame().gameMenu();

	return 0;
}

mathGame::mathGame(){
	srand(time(NULL));
	x = 0;
	y = 0;
	score = 0;
}

int mathGame::addProblem(){
	x = rand() % 100 + 1;
	y = rand() % 100 + 1;

	cout << "What is " << x << '+' << y << ':' << endl;
	return x + y;
}

int mathGame::minusProblem(){
	x = rand() % 100 + 1;
	y = rand() % 100 + 1;
	
	cout << "What is " << x << '-' << y << ':' << endl;
	return x - y;
}

int mathGame::multiplyProblem(){
	x = rand() % 10 + 1;
	y = rand() % 100 + 1;

	cout << "What is " << x << '*' << y << ':' << endl;
	return x * y;
}

int mathGame::divideProblem(){
	x = rand() % 100 + 1;
	y = rand() % 10 + 1;

	cout << "What is " << x << '/' << y << ':' << endl;
	return x / y;
}

int mathGame::problemGenerator(){
	int randomProblem = 0, correctAnswer = 0, answer = 0;
	randomProblem = rand() % 4 + 1;
	switch (randomProblem)
	{
	case 1:
		 correctAnswer = minusProblem();
		 cin >> answer;
		 if (answer == correctAnswer)
		 {
			 cout << "Correct!" << endl;
			 addPoint();
		 }
		 else cout << "Incorrect!" << endl;
		 break;
	case 2:
		correctAnswer = addProblem();
		cin >> answer;
		if (answer == correctAnswer)
		{
			cout << "Correct!" << endl;
			addPoint();
		}
		else cout << "Incorrect!" << endl;
		break;
	case 3:
		correctAnswer = multiplyProblem();
		cin >> answer;
		if (answer == correctAnswer)
		{
			cout << "Correct!" << endl;
			addPoint();
		}
		else cout << "Incorrect!" << endl;
		break;
	case 4:
		correctAnswer = divideProblem();
		cin >> answer;
		if (answer == correctAnswer)
		{
			cout << "Correct!" << endl;
			addPoint();
		}
		else cout << "Incorrect!" << endl;
		break;
	default:
		cout << "error 111: number out of range" << endl;
		break;
	}
	return answer;

}
void mathGame::addPoint(){
	score++;
}
void mathGame::showScore(){
	cout << "Score: "<< score << endl;
}

void mathGame::gameMenu(){
	char start;
	cout << "[S]tart Game [H]igh Scores [Q]uit Game" << endl;
	cin >> start; cin.ignore(100, '\n');
	start = toupper(start);
	
	
		
		switch (start)
		{
		case 'S':
			while (stop(problemGenerator()))
			{
				showScore();
			}
			gameMenu();
			break;
		case 'H':
			setHighScore();
			gameMenu();
			break;
		case 'Q':
			break;
		default:
			cout << "Oops something happended!?" << endl;
			break;
		}
	



}
bool mathGame::stop(int problemGenerator){
	string highScoreName;
	int newHighScore;
	ofstream writefile;
	writefile.open("HighScores.txt", ios::app);
	if (problemGenerator == -999){
		cout << "Enter your name: ";
		cin >> highScoreName; cin.ignore(100, '\n');
		writefile << highScoreName  << "  " << score  << endl;
		return false;
	}
	else return true;

}

void mathGame::setHighScore(){
	int topScores[10], count = 0, count2 = 0, temp, maxLength;
	string topNames[10], nameTemp;

	ifstream readfile;
	readfile.open("HighScores.txt");
	while (!readfile.eof())
	{
		readfile >> topNames[count] >> topScores[count];
		count++;
	}
	
	for (int j = 0; j < count - 1; j++){
		for (int i = 0; i < count - 1; i++){
			if (topScores[i] < topScores[i + 1]){
				temp = topScores[i];
				nameTemp = topNames[i];
				topScores[i] = topScores[i + 1];
				topNames[i] = topNames[i + 1];
				topScores[i + 1] = temp;
				topNames[i + 1] = nameTemp;
			}
		}
	}
	readfile.close();

	ofstream writefile;
	writefile.open("HighScores.txt");
	while (count2 < count -1)
	{
		writefile << topNames[count2] << "  " << topScores[count2] << endl;
			count2++;
	}
	highScore();
}

void mathGame::highScore(){
	string name;
	int topScore = 0;
	ifstream readfile;
	readfile.open("HighScores.txt");
	cout << "-------------HIGH SCORES-------------" << endl;
	while (!readfile.eof())
	{
		readfile >> name >> topScore;
		cout << setw(16) << setfill(' ') << name << "   " << topScore << endl;
	}
	readfile.close();

}


bool mathGame::level(){

	return true;
}