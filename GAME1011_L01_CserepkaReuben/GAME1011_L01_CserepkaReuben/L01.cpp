#include <string>
#include <iostream>
#include <array>

using namespace std;

class Achievement
{
public:
	string m_title;
	string m_description;
	int m_score = 0;

	Achievement()
	{

	}

	Achievement(string title, string description, int score = 0)
	{
		this->m_title = title;
		this->m_description = description;
		this->m_score = score;
	}

	string Title()
	{
		return m_title;
	}

	string Description()
	{
		return m_description;
	}

	int Score()
	{
		return m_score;
	}
};

class Game
{
public:
	string m_name;
	string m_publisher;
	string m_developer;
	Achievement* m_achievements[12];

	Game()
	{

	}

	Game(string name, string publisher, string developer)
	{
		this->m_name = name;
		this->m_publisher = publisher;
		this->m_developer = developer;
		for (int i = 0; i < 12; i++)
		{
			m_achievements[i] = nullptr;
		}
	}

	string Name()
	{
		return m_name;
	}

	string Publisher()
	{
		return m_publisher;
	}

	string Developer()
	{
		return m_developer;
	}
};

class Platform
{
public:
	string m_platName;
	string m_manufacturer;
	Game* m_games[12];

	Platform()
	{

	}

	Platform(string platName, string manufacturer)
	{
		this->m_platName = platName;
		this->m_manufacturer = manufacturer;
		for (int i = 0; i < 12; i++)
		{
			m_games[i] = nullptr;
		}
	}

	string PlatName()
	{
		return m_platName;
	}

	string Manufacturer()
	{
		return m_manufacturer;
	}

};

int main()
{
	string title, description,
		   name, publisher, developer,
		   platName, manufacturer,
		   aChoice, gChoice, pChoice;

	int aCount = 0, gCount = 0, pCount = 0, score;
	
	Platform* m_pPlatform[12];
	
	for (int i = 0; i < 12; i++)
	{
		m_pPlatform[i] = nullptr;
	}

	do 
	{
		cout << "Y - New Platform, N - Exit: ";
		cin >> pChoice;

		system("CLS");

		if (pChoice == "N")
			break;

		cout << "Platforms name: ";
		cin >> platName;

		cout << "Manufacturers name: ";
		cin >> manufacturer;

		m_pPlatform[pCount] = new Platform(platName, manufacturer);

		do
		{
			cout << "Y - New Game, N - Exit: ";
			cin >> gChoice;

			system("CLS");

			if (gChoice == "N")
				break;

			cout << "Whats the name of the game: ";
			cin >> name;

			cout << "Name of the publisher: ";
			cin >> publisher;

			cout << "Name of the developer: ";
			cin >> developer;

			m_pPlatform[pCount]->m_games[gCount] = new Game(name, publisher, developer);

			do
			{
				cout << "Y - New Achievement, N - Exit: ";
				cin >> aChoice;

				system("CLS");

				if (aChoice == "N")
					break;

				cout << "Whats The achievements title: ";
				cin >> title;

				cout << "Whats The achievements description: ";
				cin >> description;

				cout << "Whats The achievements score: ";
				cin >> score;

				m_pPlatform[pCount]->m_games[gCount]->m_achievements[aCount] = new Achievement(title, description, score);

				aCount++;
			} while (aChoice == "Y");

			gCount++;
		} while (gChoice == "Y");

		pCount++;
	} while (pChoice == "Y");

	system("CLS");

	// Display Platforms, Games and Achievements
	for (int i = 0; i < 12; i++)
	{
		if (m_pPlatform[i] != nullptr)
		{
			cout << "PLATFORM\n------------" << endl
				<< "Platform Name: " << m_pPlatform[i]->m_platName << endl
				<< "Platform Manufacturer: " << m_pPlatform[i]->m_manufacturer << endl << endl;

			for (int j = 0; j < 12; j++)
			{
				if (m_pPlatform[i]->m_games[j] != nullptr)
				{
					cout << "GAMES\n-----" << endl
						<< "Name: " << m_pPlatform[i]->m_games[j]->m_name << endl
						<< "Publisher: " << m_pPlatform[i]->m_games[j]->m_publisher << endl
						<< "Developer: " << m_pPlatform[i]->m_games[j]->m_developer << endl << endl;

					for (int k = 0; k < 12; k++)
					{
						if (m_pPlatform[i]->m_games[j]->m_achievements[k] != nullptr)
						{
							cout << "ACHIEVEMENTS\n--------" << endl
								<< "Title: " << m_pPlatform[i]->m_games[j]->m_achievements[k]->m_title << endl
								<< "Description: " << m_pPlatform[i]->m_games[j]->m_achievements[k]->m_description << endl
								<< "Score: " << m_pPlatform[i]->m_games[j]->m_achievements[k]->m_score << endl << endl;
						}
					}
				}
			}
		}
	}
}