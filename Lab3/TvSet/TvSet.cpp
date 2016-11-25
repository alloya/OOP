// TvSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TvSet.h"


bool CTvSet::IsTurnedOn() const
{
	return m_isOn;
}

void CTvSet::TurnOn()
{
	m_isOn = true;
}

void CTvSet::TurnOff()
{
	m_isOn = false;
}

std::string CTvSet::GetName()const
{
	return m_name;
}

bool IsNumberCorect(int const number)
{
	return ((number < 100) && (number > 0));
}

bool IsNameCorrect(std::string & name)
{
	name = std::regex_replace(name, std::regex("^ +| +$|( ) +"), "$1");
	if (!name.empty())
	{
		return true;
	}
	return false;
}

bool CTvSet::SelectChannel(int channel)
{
	if ((m_isOn) && IsNumberCorect(channel))
	{
		m_prevChannel = m_currChannel;
		m_currChannel = channel;
		return true;
	}
	return false;
}

bool CTvSet::SelectPreviousChannel()
{
	if (m_isOn)
	{
		std::swap(m_currChannel, m_prevChannel);
		return true;
	}
	return false;
}

bool CTvSet::SetChannelName(int number, std::string name)
{
	if (m_isOn && IsNumberCorect(number) && IsNameCorrect(name))
	{
		m_name = name;
		return true;
	}
	return false;
}

int CTvSet::GetCurrChannel() const
{
	return m_isOn ? m_currChannel : 0;
}

void CTvSet::Info()
{
	if (m_isOn)
	{
		std::cout << "TV is ON. Current channel is " << m_currChannel << 
			" - " << m_name << std::endl;
	}
	else
	{
		std::cout << "TV is OFF." << std::endl;
	}
}

