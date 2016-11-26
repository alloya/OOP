#pragma once
#include "stdafx.h"

using namespace std;

class CTvSet
{
public:
	bool IsTurnedOn()const;
	void TurnOn();
	void TurnOff();
	string GetChannelName(int channel)const;
	string GetChannelByName(string channelName)const;
	string GetListOfNamedChannels();
	bool SelectChannel(int channel);
	bool SelectChannel(string name);
	bool SelectPreviousChannel();
	bool SetChannelName(int channelNumber, string channelName);
	int GetCurrChannel()const;
	//void Info();
	bool DeleteChannelName(string name);
	
private:
	typedef map<string, size_t> MapName;
	typedef map<size_t, string> MapNumber;
	bool m_isOn = false;
	int m_currChannel = 1;
	int m_prevChannel = 1;

	MapName channelName;
	MapNumber channelNumber;
};

