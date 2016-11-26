// TvSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TvSet.h"

using namespace std;

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

string CTvSet::GetChannelName(int number)const
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

bool IsNameCorrect(string & name)
{
	name = regex_replace(name, regex("^ +| +$|( ) +"), "$1");
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
		swap(m_currChannel, m_prevChannel);
		return true;
	}
	return false;
}

bool CTvSet::SetChannelName(int number, string name)
{
	if (m_isOn && IsNumberCorect(number) && IsNameCorrect(name))
	{
		//m_name = name;
		//mySecondMap.insert ( pair<char,int>(c,i) );
		channelName.insert(pair<string, size_t>(name, number));
		channelNumber.insert(pair<size_t, string>(number, name));
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

string CTvSet::GetChannelByName(string name) const
{
	return (channelName.find(name) != channelName.end()
		? to_string(channelName.find(name)->second) : ("not exist"));
}

bool CTvSet::DeleteChannelName(string name)
{
	map<string, size_t>::iterator itName = channelName.find(name);
	map<size_t, string>::iterator itNumber;
	//itNumber = channelName.find(name);
	if (itName != channelName.end())
	{
		int number = itName->second;
		channelName.erase(itName);
		//itNumber = channelNumber.find(number);
		channelNumber.erase(channelNumber.find(number));
		return true;
	}
	
	return false;
}
