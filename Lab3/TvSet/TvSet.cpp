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

bool CTvSet::SelectChannel(int channel)
{
	if ((m_isOn) && (channel <100) && (channel > 0))
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

int CTvSet::GetCurrChannel() const
{
	return m_isOn ? m_currChannel : 0;
}

void CTvSet::Info()
{
	if (m_isOn)
	{
		std::cout << "TV is ON. Current channel is " << m_currChannel << std::endl;
	}
	else
	{
		std::cout << "TV is OFF." << std::endl;
	}
}

