#pragma once
#include <string>
#include <iostream>
#include <array>

#include "Achievements.h"
#include "Games.h"

using namespace std;

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