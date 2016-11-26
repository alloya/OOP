#pragma once
#include <boost\noncopyable.hpp>

class CTvSet;

class CRemoteControl : boost::noncopyable
{
public:
	CRemoteControl(CTvSet & tv, std::istream & input, std::ostream & output);
	bool HandleCommand();

private:
	bool TurnOn(std::istream & args);
	bool TurnOff(std::istream & args);
	bool Info(std::istream & args);
	bool SelectChannel(std::istream & args);
	bool SelectPreviousChannel(std::istream & args);
	bool SetChannelName(std::istream & args);
	bool GetChannelName(std::istream & args);
	bool GetChannelByName(std::istream & args);
private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

	CTvSet & m_tv;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};