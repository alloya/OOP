#include "stdafx.h"
#include "RemoteControl.h"
#include "TvSet.h"

using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(CTvSet & tv, std::istream & input, std::ostream & output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "TurnOn", bind(&CRemoteControl::TurnOn, this, _1) } ,
		{ "TurnOff", bind(&CRemoteControl::TurnOff, this, _1) },
		{ "Info", bind(&CRemoteControl::Info, this, _1) },
		{ "SelectChannel", bind(&CRemoteControl::SelectChannel, this, _1) },
		{ "SelectPreviousChannel", bind(&CRemoteControl::SelectPreviousChannel, this, _1) },
		{ "SetChannelName", bind(&CRemoteControl::SetChannelName, this, _1) },
		{ "GetChannelName", bind(&CRemoteControl::GetChannelName, this, _1) }
	})
{
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	return false;
}

bool CRemoteControl::TurnOn(std::istream & /*args*/)
{
	m_tv.TurnOn();
	m_output << "TV is turned on." << endl;
	return true;
}

bool CRemoteControl::TurnOff(std::istream & /*args*/)
{
	m_tv.TurnOff();
	m_output << "TV is turned off." << endl;
	return true;
}

bool CRemoteControl::Info(std::istream & /*args*/)
{
	string info = (m_tv.IsTurnedOn())
		? ("TV is turned on.\nChannel is: " + to_string(m_tv.GetCurrChannel()) + " " 
			+ (m_tv.GetChannelName(m_tv.GetCurrChannel())) + "\n") : "TV is turned off.\n";
	
	string listOfChannels = "";

	m_output << info << listOfChannels;

	return true;
}

bool CRemoteControl::SelectChannel(std::istream & args)
{
	int channel;
	string info;
	args >> channel;

	if (m_tv.IsTurnedOn())
	{
		info = (m_tv.SelectChannel(channel)) ? ("Channel switched to " + to_string(m_tv.GetCurrChannel()) + ".\n")
			: "Incorrect channel. Enter number from 1 to 99.\n";
	}
	else
	{
		info = "Can't select channel because TV is turned off.\n";
	}

	m_output << info;

	return true;
}

bool CRemoteControl::SelectPreviousChannel(std::istream & args)
{
	string info = (m_tv.SelectPreviousChannel()) ? ("Channel switched to " + to_string(m_tv.GetCurrChannel()) + ".\n")
		: "Can't select channel because TV is turned off.\n";
	
	m_output << info;

	return true;
}

bool CRemoteControl::SetChannelName(std::istream & args)
{
	int channel;
	string info;
	string name;
	args >> channel;
	args >> name;

	if (m_tv.IsTurnedOn())
	{
		info = (m_tv.SetChannelName(channel, name)) ? ("Channel " + to_string(channel) + " name is set to " + name + ".\n")
			: "Channel number must be from 1 to 99. Name must not be empty or contain only whitespaces.\n";
	}
	else
	{
		info = "Can't set channel name because TV is turned off.\n";
	}

	m_output << info;

	return true;
}

bool CRemoteControl::GetChannelName(std::istream & args)
{
	int channel;
	string info;
	args >> channel;

	if (m_tv.IsTurnedOn())
	{
		info = ("Channel " + to_string(channel) + " name is " + m_tv.GetChannelName(channel) + ".\n");
	}
	else
	{
		info = "Can't get channel name because TV is turned off.\n";
	}

	m_output << info;

	return true;
}
