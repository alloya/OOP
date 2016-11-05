// WordFrequensyTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../WordFrequency/Utils.h"
#include <boost/test/output/compiler_log_formatter.hpp>
#include <boost/algorithm/string/replace.hpp>

BOOST_AUTO_TEST_SUITE(Function_GetWordFrequency)

	BOOST_AUTO_TEST_CASE(Counts_words_in_input_string)
	{
		{
			WordFerequency result = { { "day", 4 }, { "������", 3 } };
			istringstream test("������ day\n������ daY\t������ day day");
			BOOST_CHECK(result == CountWords(test));
		}
	}

	BOOST_AUTO_TEST_CASE(Does_not_count_words_when_input_string_is_empty)
	{
		WordFerequency result = {};
		istringstream test("");
		BOOST_CHECK(result == CountWords(test));
	}

BOOST_AUTO_TEST_SUITE_END()

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

