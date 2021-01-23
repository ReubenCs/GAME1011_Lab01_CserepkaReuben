#pragma once
#include <string>
#include <iostream>
#include <array>

#include "Games.h"
#include "Platform.h"

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