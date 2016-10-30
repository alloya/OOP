#include "stdafx.h"

#include "../FindAndReplace/Utils.h"
#include <boost/test/output/compiler_log_formatter.hpp>
#include <boost/algorithm/string/replace.hpp>

BOOST_AUTO_TEST_SUITE(Test)

BOOST_AUTO_TEST_CASE(Find_And_Replace)
{
	{
		string subject = "123456789";
		auto newString = FindAndReplace(subject, "1", "0");
		const string correctString = "023456789";
		BOOST_CHECK(newString == correctString);
	}
	{
		string subject = "big paws, big black nose, stubby tail, and growl he goes";
		auto newString = FindAndReplace(subject, "big", "small");
		const string correctString = "small paws, small black nose, stubby tail, and growl he goes";
		BOOST_CHECK(newString == correctString);
	}
	{
		string subject = "big paws, big black nose, stubby tail, and growl he goes";
		auto newString = FindAndReplace(subject, "paws", "ears");
		const string correctString = "big ears, big black nose, stubby tail, and growl he goes";
		BOOST_CHECK(newString == correctString);
	}
	{
		string subject = "1223344455566667777888899999...";
		auto newString = FindAndReplace(subject, "0", "000");
		const string correctString = "1223344455566667777888899999...";
		BOOST_CHECK(newString == correctString);
	}
	{
		string subject = "1223344455566667777888899999...";
		auto newString = FindAndReplace(subject, "6", "0");
		const string correctString = "1223344455500007777888899999...";
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
