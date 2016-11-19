#pragma once

class CTvSet
{
public:
	bool IsTurnedOn()const;
	void TurnOn();
	void TurnOff();
	std::string GetName()const;
	bool SelectChannel(int channel);
	bool SelectPreviousChannel();
	bool SetChannelName(int channelNumber, std::string channelName);
	int GetCurrChannel()const;
	void Info();

private:
	bool m_isOn = false;
	int m_currChannel = 1;
	int m_prevChannel = 1;
	std::string m_name = "";
};