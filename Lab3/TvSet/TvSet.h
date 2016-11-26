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
	bool SelectChannel(int channel);
	bool SelectPreviousChannel();
	bool SetChannelName(int channelNumber, string channelName);
	int GetCurrChannel()const;
	//void Info();
	bool DeleteChannelName(string name);
	
private:
	typedef map<string, size_t> MapName;
	typedef map<string, size_t>::iterator ItName;
	typedef map<size_t, string> MapNumber;
	typedef map<size_t, string>::iterator ItNumber;
	bool m_isOn = false;
	int m_currChannel = 1;
	int m_prevChannel = 1;

	MapName channelName;
	ItName itName;
	MapNumber channelNumber;
	ItNumber itNumber;
};

