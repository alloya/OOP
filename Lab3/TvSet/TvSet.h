#pragma once
#include "stdafx.h"

using namespace std;

class CTvSet
{
public:
	bool IsTurnedOn()const;
	void TurnOn();
	void TurnOff();
	string GetChannelName(size_t channel)const;
	size_t GetChannelByName(string channelName)const;
	string GetListOfNamedChannels();
	bool SelectChannel(int const &channel);
	bool SelectChannel(string const &name);
	bool SelectPreviousChannel();
	bool SetChannelName(int const &channelNumber, string channelName);
	size_t GetCurrChannel()const;
	bool DeleteChannelName(string const &name);
	
private:
	typedef map<string, size_t> MapName;
	typedef map<size_t, string> MapNumber;
	bool m_isOn = false;
	size_t m_currChannel = 1;
	size_t m_prevChannel = 1;

	MapName m_channelName;
	MapNumber m_channelNumber;
};

