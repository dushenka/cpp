#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <Windows.h>

using namespace std;
short temporalCrystal = 0, mainMenuChoise, settingsMenuChoise, numberQuestions = 3, numberLives = 2, numberFiftyFifty = 1, tempFifty, beenAsked[15], userAnswer, correctAnswersCount = 0, isAnswerCorrect, mistakes = 0;
string question, answers[4], correctAnswer, fifty[2];

void clear()
{
	system("cls");
}

void randomizer()
{
	srand(time(NULL));
}

void shuffleAnswers(string* a, size_t n)
{
	for (size_t i = n; i > 0; i--)
	{
		swap(a[i-1], a[rand()%i]);
	}
}

void getQuestion(short val)
{
	switch (val)
	{
	case 1:
		if (beenAsked[val] != 1)
		{
			question = "What sort of animal is Walt Disney`s Dumbo?";
			answers[0] = "Deer";
			answers[1] = "Rabbit";
			answers[2] = "Elephant";
			answers[3] = "Donkey";
			correctAnswer = "Elephant";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 2:
		if (beenAsked[val] != 1)
		{
			question = "The Norwegian explorer Roald Amundsen reached the South Pole on 14 December of which year?";
			answers[0] = "1891";
			answers[1] = "1901";
			answers[2] = "1911";
			answers[3] = "1921";
			correctAnswer = "1911";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 3:
		if (beenAsked[val] != 1)
		{
			question = "When attacked by predators, which of these animals will often activate a large gland known as an ink sac?";
			answers[0] = "Cheetah";
			answers[1] = "Squid";
			answers[2] = "Owl";
			answers[3] = "Paris Hilton";
			correctAnswer = "Squid";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 4:
		if (beenAsked[val] != 1)
		{
			question = "Snapping selfies in kitchens you can`t afford and taking \"a meatball break\" are two things BuzzFeed says every twentysomething does on their first trip where?";
			answers[0] = "To Paris";
			answers[1] = "To London";
			answers[2] = "To Rome";
			answers[3] = "To Ikea";
			correctAnswer = "To Ikea";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 5:
		if (beenAsked[val] != 1)
		{
			question = "Who lives in a pineapple under the sea?";
			answers[0] = "Sponge Bob";
			answers[1] = "Patrick The Star";
			answers[2] = "Squidward";
			answers[3] = "Mr Crabs";
			correctAnswer = "Sponge Bob";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 6:
		if (beenAsked[val] != 1)
		{
			question = "What car did Elon Musk launch on the rocket \"Falcon Heavy\" to space as a joke?";
			answers[0] = "Porsche 911";
			answers[1] = "Lamborghini Huracan";
			answers[2] = "Tesla Model S";
			answers[3] = "Tesla Roadster";
			correctAnswer = "Tesla Roadster";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 7:
		if (beenAsked[val] != 1)
		{
			question = "What is the cause of death of Cleopatra?";
			answers[0] = "Suicide";
			answers[1] = "Age";
			answers[2] = "Murderer";
			answers[3] = "Heat";
			correctAnswer = "Suicide";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 8:
		if (beenAsked[val] != 1)
		{
			question = "How many countries borders with Russia?";
			answers[0] = "8";
			answers[1] = "14";
			answers[2] = "9";
			answers[3] = "12";
			correctAnswer = "14";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 9:
		if (beenAsked[val] != 1)
		{
			question = "Which country has the most population? (Based of July 1, 2021)";
			answers[0] = "India";
			answers[1] = "China";
			answers[2] = "USA";
			answers[3] = "Japan";
			correctAnswer = "China";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 10:
		if (beenAsked[val] != 1)
		{
			question = "What is the name of personal Apple voice assistant?";
			answers[0] = "Alexa";
			answers[1] = "Alice";
			answers[2] = "Siri";
			answers[3] = "Cortana";
			correctAnswer = "Siri";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 11:
		if (beenAsked[val] != 1)
		{
			question = "Who was the manufacturer of the first Google Pixel phone?";
			answers[0] = "HTC";
			answers[1] = "Huawei";
			answers[2] = "LG";
			answers[3] = "Samsung";
			correctAnswer = "HTC";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 12:
		if (beenAsked[val] != 1)
		{
			question = "How many moons Mars have?";
			answers[0] = "1";
			answers[1] = "2";
			answers[2] = "3";
			answers[3] = "4";
			correctAnswer = "2";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 13:
		if (beenAsked[val] != 1)
		{
			question = "Who is the most rich person by NET WORTH? (Based of November 1, 2021)";
			answers[0] = "Elon Musk";
			answers[1] = "Jeff Bezos";
			answers[2] = "Bill Gates";
			answers[3] = "Mark Zuckerberg";
			correctAnswer = "Elon Musk";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 14:
		if (beenAsked[val] != 1)
		{
			question = "What was the year of the Chernobyl disaster?";
			answers[0] = "1986";
			answers[1] = "1987";
			answers[2] = "1978";
			answers[3] = "1968";
			correctAnswer = "1986";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	case 15:
		if (beenAsked[val] != 1)
		{
			question = "What volume of \"Dead Souls\" did Nikolay Gogol burn?";
			answers[0] = "1";
			answers[1] = "2";
			answers[2] = "3";
			answers[3] = "He didn`t burn any";
			correctAnswer = "2";
			beenAsked[val] = 1;
		}
		else
		{
			temporalCrystal = 1 + rand() % 15;
			getQuestion(temporalCrystal);
			temporalCrystal = 0;
		}
		break;
	}
}

void askQuestion()
{
	clear();
	randomizer();
	temporalCrystal = 1 + rand() % 15;
	getQuestion(temporalCrystal);
	temporalCrystal = 0;
	cout << " [?] " << question << "\n\n";
	shuffleAnswers(answers,4);
	for (short i = 0; i < 4; i++)
	{
		cout << " [" << i+1 << "] - " << answers[i] << "\n";
	}
	if (numberFiftyFifty == 1)
	{
		cout << "\n [5] - 50/50\n";
	}
}

void getFiftyFifty()
{
	short hasCorrectAnswer = 0;
	for (short i = 0; i < 2; i++)
	{
		temporalCrystal = rand() % 4;
		if (hasCorrectAnswer == 0 && answers[temporalCrystal] == correctAnswer)
		{
			fifty[i] = answers[temporalCrystal];
			hasCorrectAnswer++;
		}
		else if (hasCorrectAnswer == 1 && answers[temporalCrystal] != correctAnswer)
		{
			fifty[i] = answers[temporalCrystal];
		}
	}
	temporalCrystal = 0;
	if (hasCorrectAnswer == 0)
	{
		getFiftyFifty();
	}
	else if (hasCorrectAnswer == 1)
	{
		cout << "\n\n [!] Here`s a 50/50 chance\n";
		for (short i = 0; i < 2; i++)
		{
			cout << " [" << i + 1 << "] - " << fifty[i] << "\n";
		}
		cout << "\n [!] Your answer is (choose button 1-2): ";
	}
}

void checkAnswerFiftyFifty()
{
	if (fifty[userAnswer - 1] == correctAnswer)
	{
		isAnswerCorrect = 1;
		correctAnswersCount++;
	}
	else
	{
		isAnswerCorrect = 0;
	}
}

void checkAnswer()
{
	if (answers[userAnswer-1] == correctAnswer)
	{
		isAnswerCorrect = 1;
		correctAnswersCount++;
	}
	else
	{
		isAnswerCorrect = 0;
	}
}

void answerQuestion()
{
	cout << "\n [!] Your answer is (choose button 1-4): ";
	cin >> userAnswer;
	if (numberFiftyFifty == 1)
	{
		while (userAnswer < 1 || userAnswer > 5)
		{
			cout << "\n\n [!] Error! No such button, try again: ";
			cin >> userAnswer;
		}
		if (userAnswer < 5)
		{
			checkAnswer();
		}
		if (userAnswer == 5)
		{
			getFiftyFifty();
			cin >> userAnswer;
			while (userAnswer < 1 || userAnswer > 2)
			{
				cout << "\n\n [!] Error! No such button, try again: ";
				cin >> userAnswer;
			}
			checkAnswerFiftyFifty();
			if (isAnswerCorrect == 1)
			{
				tempFifty = numberFiftyFifty;
				numberFiftyFifty = 2;
				return;
			}
		}
	}
	if (numberFiftyFifty == 2)
	{
		while (userAnswer < 1 || userAnswer > 4)
		{
			cout << "\n\n [!] Error! No such button, try again: ";
			cin >> userAnswer;
		}
		checkAnswer();
	}
	cout << "\n";
}

void clearBeenAsked()
{
	for (short i = 0; i < 15; i++)
	{
		beenAsked[i] = 0;
	}
}

void gameLogic()
{
	short size, lives;
	clock_t time;
	time = clock();
	switch (numberQuestions)
	{
	case 1:
		size = 5;
		break;
	case 2:
		size = 10;
		break;
	case 3:
		size = 15;
		break;
	}
	switch (numberLives)
	{
	case 1:
		lives = 10;
		break;
	case 2:
		lives = 5;
		break;
	case 3:
		lives = 1;
		break;
	}

	for (short i = 0; i < size; i++)
	{
		clear();
		askQuestion();
		answerQuestion();
		while (isAnswerCorrect != 1 && lives > 0)
		{
			cout << "\n [!] Incorrect answer, you have " << lives-1 << " more live(s), try again. \n\n";
			mistakes++;
			lives--;
			answerQuestion();
		}
		if (lives <= 0)
		{
			clear();
			time = clock() - time;
			cout << " [!] You`ve lost all your lives, good luck next time!\n [a] Correct answers: " << correctAnswersCount <<"\n [t] Time: " << time/1000 << "s\n [!] You`ll be redirected to main menu.\n\n";
			system("pause");
			return;
		}
		cout << "\n [!] That was correct answer, great job!\n\n";
		system("pause");
	}
	clear();
	time = clock() - time;
	cout << " [w] YOU WON THE QUIZ! WELL DONE!\n\n";
	cout << " [!] Your stats:\n";
	cout << " [m] - Mistakes: \033[33m" << mistakes << "\033[0m\n";
	cout << " [l] - Lives left: \033[33m" << lives << "\033[0m\n";
	cout << " [t] - Time of completition: \033[33m"<< time/1000 << "s\033[0m\n";
	cout << "\n\n";
	clearBeenAsked();
	if (tempFifty == 1)
	{
		numberFiftyFifty = tempFifty;
	}
	system("pause");
	return;
}

void howToPlay()
{
	clear();
	cout << " [h] How to play\n\n";
	cout << " - You`ll have a choosen count of \033[32mquestion\033[0m to be answered.\n - You have choosen count of \033[32m\"lives\"\033[0m (How many mistakes you can make)\n - You can choose to have a \033[32m50/50 help\033[0m\n\n";
	cout << " [d] Default settings are: \033[32m15 questions\033[0m, \033[32m5 lives\033[0m and \033[32m50/50 enabled\033[0m\n";
	cout << "\n\n";
	system("pause");
}

void questionsMenu()
{
	clear();
	cout << " [q] Questions count\n\n";
	cout << " [1] - \033[32m5 questions\033[0m\n [2] - \033[32m10 questions\033[0m\n [3] - \033[32m15 questions\033[0m\n [4] - Back\n\n";
	cout << " [?] Choose what button you want (default value is \033[33m15 questions\033[0m): ";
	temporalCrystal = numberQuestions;
	cin >> numberQuestions;
	while (numberQuestions < 1 || numberQuestions > 4)
	{
		cout << "\n\n [!] Error! No such button, try again: ";
		cin >> numberQuestions;
	}
	if (numberQuestions == 4) { numberQuestions = temporalCrystal; temporalCrystal = 0;  };
}

void livesMenu()
{
	clear();
	cout << " [l] Lives count\n\n";
	cout << " [1] - Baby \033[32m(10 lives)\033[0m\n [2] - Normal \033[32m(5 lives)\033[0m\n [3] - \033[31mHARDCORE\033[0m \033[32m(1 life)\033[0m\n [4] - Back\n\n";
	cout << " [?] Choose what button you want (default value is \033[33mNormal\033[0m): ";
	temporalCrystal = numberLives;
	cin >> numberLives;
	while (numberLives < 1 || numberLives > 4)
	{
		cout << "\n\n [!] Error! No such button, try again: ";
		cin >> numberLives;
	}
	if (numberLives == 4) { numberLives = temporalCrystal; temporalCrystal = 0; };
}

void fiftyFiftyMenu()
{
	clear();
	cout << " [f] Choose whether you`ll have 50/50\n\n";
	cout << " [1] - \033[32mYes\033[0m\n [2] - \033[32mNo\033[0m\n [3] - Back\n\n";
	cout << " [?] Choose what button you want (default value is \033[33mYes\033[0m): ";
	temporalCrystal = numberFiftyFifty;
	cin >> numberFiftyFifty;
	while (numberFiftyFifty < 1 || numberFiftyFifty > 3)
	{
		cout << "\n\n [!] Error! No such button, try again: ";
		cin >> numberFiftyFifty;
	}
	if (numberFiftyFifty == 3) { numberFiftyFifty = temporalCrystal; temporalCrystal = 0; };
}

void settingsMenu()
{
	clear();
	cout << " [s] Settings\n\n";
	cout << " [1] - Questions\n [2] - Lives \n [3] - 50/50\n [4] - Back to main menu\n\n";
	cout << " [?] Choose what button you want: ";
	cin >> settingsMenuChoise;
	cout << "\n\n";
	switch (settingsMenuChoise)
	{
	case 1:
		questionsMenu();
		settingsMenu();
		break;
	case 2:
		livesMenu();
		settingsMenu();
		break;
	case 3:
		fiftyFiftyMenu();
		settingsMenu();
		break;
	case 4:
		return;
	default:
		settingsMenu();
	}
}

void mainMenu()
{
	clear();
	cout << " [!] Quiz\n\n";
	cout << " [1] - Start game\n [2] - Settings \n [3] - How to play\n [4] - Quit game\n\n";
	cout << " [?] Choose what button you want: ";
	cin >> mainMenuChoise;
	cout << "\n\n";
	switch (mainMenuChoise)
	{
	case 1:
		gameLogic();
		mainMenu();
	case 2:
		settingsMenu();
		mainMenu();
	case 3:
		howToPlay();
		mainMenu();
	case 4:
		clear();
		cout << " [T_T] - It was my honor to serve you, sir! Bye!\n\n";
		system("pause");
		break;
	default:
		mainMenu();
	}
}

int main()
{
	setlocale(0, "");
	mainMenu();
	return 777;
}