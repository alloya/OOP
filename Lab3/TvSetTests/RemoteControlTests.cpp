#include "stdafx.h"
#include "../TvSet/RemoteControl.h"
#include "../TvSet/TVSet.h"
#include <sstream>
#include <boost/optional.hpp>

using namespace std;
using boost::optional;
using boost::none;

// Зависимости RemoteControl-а вынесены в родительскую структуру,
// чтобы гарантировать их создание до конструирования самого remote-контрола
struct RemoteControlDependencies
{
	CTvSet tv;
	stringstream input;
	stringstream output;
};

struct RemoteControlFixture : RemoteControlDependencies
{
	CRemoteControl remoteControl;

	RemoteControlFixture()
		: remoteControl(tv, input, output)
	{
	}

	// Вспомогательная функция для проверки работы команды command
	// Она принимает ожидаемый номер канала expectedChannel и expectedOutput
	void VerifyCommandHandling(const string& command, const optional<int> & expectedChannel, const string& expectedOutput)
	{
		// Предварительно очищаем содержимое выходного потока
		output = stringstream();
		input = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK_EQUAL(tv.IsTurnedOn(), expectedChannel.is_initialized());
		BOOST_CHECK_EQUAL(tv.GetCurrChannel(), expectedChannel.get_value_or(0));
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Remote_Control, RemoteControlFixture)

	BOOST_AUTO_TEST_CASE(can_handle_TurnOn_command)
	{
		VerifyCommandHandling("TurnOn", 1, "TV is turned on.\n");
	}

	BOOST_AUTO_TEST_CASE(can_print_tv_info)
	{
		// Ожидаемое поведение команды Info, вызванной у выключенного телевизора
		VerifyCommandHandling("Info", none, "TV is turned off.\n");

		// Проверяем поведение команды Info у включенного телевизора
		tv.TurnOn();
		tv.SelectChannel(42);
		tv.SetChannelName(42, "Netflix");
		VerifyCommandHandling("Info", 42, "TV is turned on.\nChannel is: 42 Netflix\n");
	}

	BOOST_AUTO_TEST_CASE(cant_select_channel_when_tv_is_turned_off)
	{
		VerifyCommandHandling("SelectChannel 42", none, "Can't select channel because TV is turned off.\n");
		VerifyCommandHandling("SelectChannel 100", none, "Can't select channel because TV is turned off.\n");
	}

	BOOST_AUTO_TEST_CASE(cant_set_channel_name_when_tv_is_turned_off)
	{
		VerifyCommandHandling("SetChannelName 42, ORT ", none, "Can't set channel name because TV is turned off.\n");
	}

	BOOST_AUTO_TEST_CASE(cant_get_channel_name_when_tv_is_turned_off)
	{
		VerifyCommandHandling("GetChannelName 42, ORT ", none, "Can't get channel name because TV is turned off.\n");
	}

	BOOST_AUTO_TEST_CASE(cant_get_channel_by_name_when_tv_is_turned_off)
	{
		VerifyCommandHandling("GetChannelByName OPT", none, "Can't get channel number because TV is turned off.\n");
	}

	struct when_turned_on_ : RemoteControlFixture
	{
		when_turned_on_()
		{
			tv.TurnOn();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(when_turned_on, when_turned_on_)

		BOOST_AUTO_TEST_CASE(cant_select_previous_channel_right_after)
		{
			VerifyCommandHandling("SelectPreviousChannel", 1, "Channel switched to 1.\n");
		}
		
		BOOST_AUTO_TEST_CASE(can_be_turned_off)
		{
			VerifyCommandHandling("TurnOff", none, "TV is turned off.\n");
		}

		BOOST_AUTO_TEST_CASE(can_select_a_valid_channel)
		{
			VerifyCommandHandling("SelectChannel 42", 42, "Channel switched to 42.\n");
		}
	
		BOOST_AUTO_TEST_CASE(cant_select_an_invalid_channel)
		{
			tv.SelectChannel(42);
			VerifyCommandHandling("SelectChannel 100", 42, "Incorrect channel. Enter number from 1 to 99.\n");
			VerifyCommandHandling("SelectChannel 0", 42, "Incorrect channel. Enter number from 1 to 99.\n");
		}

		BOOST_AUTO_TEST_CASE(remembers_previous_channel)
		{
			tv.SelectChannel(42);
			VerifyCommandHandling("SelectPreviousChannel", 1, "Channel switched to 1.\n");
			VerifyCommandHandling("SelectPreviousChannel", 42, "Channel switched to 42.\n");
		}

		BOOST_AUTO_TEST_CASE(doesnt_have_channel_name_by_default)
		{
			VerifyCommandHandling("GetChannelName 1", 1, "Channel 1 name is empty.\n");
		}

		BOOST_AUTO_TEST_CASE(can_set_channel_name)
		{
			VerifyCommandHandling("SetChannelName 1 Netflix", 1, "Channel 1 name is set to Netflix.\n");
			VerifyCommandHandling("SetChannelName 100 Netflix", 1, "Channel number must be from 1 to 99. Name must not be empty or contain only whitespaces.\n");
		}

		BOOST_AUTO_TEST_CASE(can_get_channel_name)
		{
			VerifyCommandHandling("GetChannelName 1", 1, "Channel 1 name is empty.\n");
			tv.SetChannelName(1, "OPT");
			VerifyCommandHandling("GetChannelName 1", 1, "Channel 1 name is OPT.\n");
		}

		BOOST_AUTO_TEST_CASE(can_get_channel_by_name)
		{
			VerifyCommandHandling("GetChannelByName OPT", 1, "Channel OPT is not exist.\n");
			tv.SetChannelName(1, "OPT");
			VerifyCommandHandling("GetChannelByName OPT", 1, "Channel OPT is 1.\n");
		}

		/*BOOST_AUTO_TEST_CASE(can_rename_channel)
		{
			VerifyCommandHandling("SetChannelName 1 Netflix", 1, "Channel name is set to Netflix.\n");
			VerifyCommandHandling("SetChannelName 100 Netflix", 1, "Channel number must be from 1 to 99. Name must not be empty or contain only whitespaces.\n");
		}*/
	}

BOOST_AUTO_TEST_SUITE_END()