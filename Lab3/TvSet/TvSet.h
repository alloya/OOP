#pragma once

class CTvSet
{
public:
	bool IsTurnedOn()const;
	void TurnOn();
	void TurnOff();
	bool SelectChannel(int channel);
	bool SelectPreviousChannel();
	int GetCurrChannel()const;
	void Info();

private:
	bool m_isOn = false;
	int m_currChannel = 1;
	int m_prevChannel = 1;
};