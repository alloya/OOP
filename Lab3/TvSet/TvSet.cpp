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
	return (m_channelNumber.find(number) != m_channelNumber.end()
		? m_channelNumber.find(number)->second : (""));
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
		for (it = m_channelNumber.begin(); it != m_channelNumber.end(); ++it)
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
	map<string, size_t>::iterator it = m_channelName.find(name);
	if ((m_isOn) && (it != m_channelName.end()))
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
		if (m_channelName.find(name) != m_channelName.end())
		{
			DeleteChannelName(name);
		}
		else if (m_channelNumber.find(number) != m_channelNumber.end())
		{
			DeleteChannelName(m_channelNumber.find(number)->second);
		}
		
		m_channelName.emplace(name, number);
		m_channelNumber.emplace(number, name);
		return true;
	}
	return false;
}

size_t CTvSet::GetCurrChannel() const
{
	return m_isOn ? m_currChannel : 0;
}

size_t CTvSet::GetChannelByName(string name) const
{
	return (m_channelName.find(name) != m_channelName.end()
		? (m_channelName.find(name)->second) : 0);
}

bool CTvSet::DeleteChannelName(string name)
{
	map<string, size_t>::iterator itName = m_channelName.find(name);
	if (m_isOn && itName != m_channelName.end())
	{
		size_t number = itName->second;
		m_channelName.erase(itName);
		m_channelNumber.erase(number);
		return true;
	}
	
	return false;
}
