#pragma once
#include <string>
#include <iostream>
#include <array>

#include "Achievements.h"
#include "Platform.h"

using namespace std;

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
