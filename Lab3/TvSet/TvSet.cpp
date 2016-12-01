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

string CTvSet::GetChannelName(size_t number)const
{
	return (channelNumber.find(number) != channelNumber.end()
		? channelNumber.find(number)->second : (""));
}

bool IsNumberCorect(int const number)
{
	return ((number < 100) && (number > 0));
}

string CTvSet::GetListOfNamedChannels()
{
	string list = "";
	map<size_t, string>::iterator it;
	if (m_isOn)
	{
		for (it = channelNumber.begin(); it != channelNumber.end(); ++it)
		{
			list = list + (to_string(it->first)) + " - " + it->second + '\n';
		}
	}
	
	return list;
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

bool CTvSet::SelectChannel(string name)
{
	map<string, size_t>::iterator it = channelName.find(name);
	if ((m_isOn) && (it != channelName.end()))
	{
		m_prevChannel = m_currChannel;
		m_currChannel = it -> second;
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
		if (channelName.find(name) != channelName.end())
		{
			DeleteChannelName(name);
		}
		else if (channelNumber.find(number) != channelNumber.end())
		{
			DeleteChannelName(channelNumber.find(number)->second);
		}
		
		channelName.insert(pair<string, size_t>(name, number));
		channelNumber.insert(pair<size_t, string>(number, name));
		return true;
	}
	return false;
}

size_t CTvSet::GetCurrChannel() const
{
	return m_isOn ? m_currChannel : 0;
}

string CTvSet::GetChannelByName(string name) const
{
	return (channelName.find(name) != channelName.end()
		? to_string(channelName.find(name)->second) : ("not exist"));
}

bool CTvSet::DeleteChannelName(string name)
{
	map<string, size_t>::iterator itName = channelName.find(name);
	if (m_isOn && itName != channelName.end())
	{
		size_t number = itName->second;
		channelName.erase(itName);
		channelNumber.erase(number);
		return true;
	}
	
	return false;
}
