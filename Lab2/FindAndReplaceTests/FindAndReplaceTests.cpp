#include "stdafx.h"

#include "../FindAndReplace/Utils.h"
#include <boost/test/output/compiler_log_formatter.hpp>
#include <boost/algorithm/string/replace.hpp>

BOOST_AUTO_TEST_SUITE(Function_FindAndReplace)

BOOST_AUTO_TEST_CASE(Replaces_word_in_string)
{
	{
		string subject = "A bad beginning makes a bad ending.";
		auto newString = FindAndReplace(subject, "bad", "good");
		const string correctString = "A good beginning makes a good ending.";
		BOOST_CHECK(newString == correctString);
	}

}

BOOST_AUTO_TEST_CASE(Not_changing_input_string_if_searching_string_is_empty)
{
	{
		BOOST_CHECK_EQUAL(FindAndReplace("subj", "", "hello"), "subj");
	}

}

BOOST_AUTO_TEST_CASE(Not_changing_already_changed_text)
{
	{
		string subject = "ma mamos";
		auto newString = FindAndReplace(subject, "ma", "mama");
		const string correctString = "mama mamamos";
		BOOST_CHECK(newString == correctString);
	}
}

BOOST_AUTO_TEST_SUITE_END()

/*
������ ����� ��������� ��������������� ������� ������� ������
��� ����, ����� ������� ���������, ���������� ������ ���� �������� � ������ --log_level=test_suite (��. Post-build event � ���������� �������)
*/
class SpecLogFormatter :
	public boost::unit_test::output::compiler_log_formatter
{
	virtual void test_unit_start(std::ostream &os, boost::unit_test::test_unit const& tu) override
	{
		// ����� �������� test unit-� ������� ��� test unit-�, ������� ������ ������������� �� ������
		os << std::string(m_indent, ' ') << boost::replace_all_copy(tu.p_name.get(), "_", " ") << std::endl;
		// ����������� ������ ��� ������ ���� ����������� test unit-�� � ���� ������
		m_indent += 2;
	}

	virtual void test_unit_finish(std::ostream &/*os*/, boost::unit_test::test_unit const& /*tu*/, unsigned long /*elapsed*/) override
	{
		// �� ��������� test unit-� ��������� ������
		m_indent -= 2;
	}

	int m_indent = 0;
};

boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
	// �������� ��� log formatter �� ����������������
	boost::unit_test::unit_test_log.set_formatter(new SpecLogFormatter);
	// ��� ��������� ������ ������ - All tests
	boost::unit_test::framework::master_test_suite().p_name.value = "All tests";
	return 0;
}


int main(int argc, char* argv[])
{
	// ��������� �����, ��������� ��������� ��������� ������ � ��������� ������� ������������� ������
	return boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
}
