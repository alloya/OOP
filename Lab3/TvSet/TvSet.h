#pragma once
#include "stdafx.h"


class CTvSet
{
public:
	bool IsTurnedOn()const;
	void TurnOn();
	void TurnOff();
	std::string GetChannelName(int channel)const;
	std::string GetChannelByName(std::string channelName)const;
	bool SelectChannel(int channel);
	bool SelectPreviousChannel();
	bool SetChannelName(int channelNumber, std::string channelName);
	int GetCurrChannel()const;
	//void Info();
	
private:
	typedef std::map<std::string, size_t> MapName;
	typedef std::map<size_t, std::string> MapNumber;
	bool m_isOn = false;
	int m_currChannel = 1;
	int m_prevChannel = 1;

	MapName channelName;
	MapNumber channelNumber;
	//std::string m_name = "";
};

