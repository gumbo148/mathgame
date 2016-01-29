#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <array>
using namespace std;

class mathGame{
public:
	void gameMenu();
	int problemGenerator();
	int addProblem();
	int minusProblem();
	int divideProblem();
	int multiplyProblem();
	void setHighScore();
	void highScore();
	void addPoint();
	bool level();
	bool stop(int problemGenerator);
	void showScore();
	mathGame();
private:
	int x;
	int y;
	int percent;
	int score;





};