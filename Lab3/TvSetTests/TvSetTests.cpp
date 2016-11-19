#include "stdafx.h"
#include "../TvSet/TvSet.h"

struct TvSetFixture
{
	CTvSet tv;
};

BOOST_FIXTURE_TEST_SUITE(TvSet, TvSetFixture)

	BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
	{
		BOOST_CHECK(!tv.IsTurnedOn());
	}

	BOOST_AUTO_TEST_CASE(cant_set_channel_name_when_tv_is_off)
	{
		BOOST_CHECK(!tv.SetChannelName(1, "OPT"));
	}

	BOOST_AUTO_TEST_CASE(channel_number_when_tv_is_off_is_0)
	{
		BOOST_CHECK_EQUAL(tv.GetCurrChannel(), 0);
	}

	BOOST_AUTO_TEST_CASE(cant_change_channel_if_turned_off)
	{
		BOOST_CHECK(!tv.IsTurnedOn());
		tv.SelectChannel(33);
		BOOST_CHECK_EQUAL(tv.GetCurrChannel(), 0);
	}

	BOOST_AUTO_TEST_CASE(cant_select_previous_channel_if_turned_off)
	{
		BOOST_CHECK(!tv.IsTurnedOn());
		BOOST_CHECK(!tv.SelectPreviousChannel());
	}

	BOOST_AUTO_TEST_CASE(can_be_turned_on)
	{
		tv.TurnOn();
		BOOST_CHECK(tv.IsTurnedOn());
	}

	struct when_turned_on_ : TvSetFixture
	{
		when_turned_on_()
		{
			tv.TurnOn();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(when_turned_on, when_turned_on_)
		
		BOOST_AUTO_TEST_CASE(channel_at_start_is_1)
		{
			BOOST_CHECK_EQUAL(tv.GetCurrChannel(), 1);
		}

		BOOST_AUTO_TEST_CASE(cant_select_previous_channel_right_after_turning_on)
		{
			tv.SelectPreviousChannel();
			BOOST_CHECK_EQUAL(tv.GetCurrChannel(), 1);
		}

		BOOST_AUTO_TEST_CASE(can_change_channel_if_turned_on)
		{
			tv.SelectChannel(33);
			BOOST_CHECK_EQUAL(tv.GetCurrChannel(), 33);
		}

		BOOST_AUTO_TEST_CASE(channel_can_be_selected_in_range_from_1_to_99)
		{
			tv.SelectChannel(131);
			BOOST_CHECK_EQUAL(tv.GetCurrChannel(), 1);
			tv.SelectChannel(-1);
			BOOST_CHECK_EQUAL(tv.GetCurrChannel(), 1);
		}
		
		BOOST_AUTO_TEST_CASE(remembers_previous_channels)
		{
			tv.SelectChannel(33);
			tv.SelectChannel(34);
			tv.TurnOff();
			tv.TurnOn();
			BOOST_CHECK_EQUAL(tv.GetCurrChannel(), 34);
			tv.SelectPreviousChannel();
			BOOST_CHECK_EQUAL(tv.GetCurrChannel(), 33);
		}

			BOOST_AUTO_TEST_CASE(can_switch_to_previous_channel)
		{
			tv.SelectChannel(33);
			tv.SelectPreviousChannel();
			BOOST_CHECK_EQUAL(tv.GetCurrChannel(), 1);
		}

		BOOST_AUTO_TEST_CASE(can_set_channel_name)
		{
			tv.SetChannelName(1, "   First   and only   ");
			BOOST_CHECK_EQUAL(tv.GetName(), "First and only");
		}

		BOOST_AUTO_TEST_CASE(can_be_turned_off)
		{
			tv.TurnOff();
			BOOST_CHECK(!tv.IsTurnedOn());
		}
	}

BOOST_AUTO_TEST_SUITE_END()

