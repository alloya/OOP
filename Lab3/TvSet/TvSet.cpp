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

std::string CTvSet::GetChannelName(int number)const
{
	/*if (channelNumber.find(GetCurrChannel()) != channelNumber.end())
	{
		return channelNumber.find(GetCurrChannel())->second;
	}
	return ("This channel name is empty.");
	*/
	return (channelNumber.find(number) != channelNumber.end()
		? channelNumber.find(number)->second : ("empty"));
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
		//m_name = name;
		//mySecondMap.insert ( pair<char,int>(c,i) );
		channelName.insert(std::pair<std::string, size_t>(name, number));
		channelNumber.insert(std::pair<size_t, std::string>(number, name));
		return true;
	}
	return false;
}

int CTvSet::GetCurrChannel() const
{
	return m_isOn ? m_currChannel : 0;
}

//void CTvSet::Info()
//{
	//if (m_isOn)
	//{
	//	//std::cout << "TV is ON. Current channel is " << m_currChannel << 
	//	//	" - " << m_name << std::endl;
	//	std::cout << ("TV is turned on.\nChannel is: " + std::to_string(m_currChannel)
	//		+ " " + (GetChannelName(m_currChannel) + "\n"));
	//}
	//else
	//{
	//	std::cout << "TV is turned off." << std::endl;
	//}
//}

std::string CTvSet::GetChannelByName(std::string name) const
{
	return (channelName.find(name) != channelName.end()
		? std::to_string(channelName.find(name)->second) : ("No such channel name."));
}

