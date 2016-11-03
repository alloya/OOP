#include "stdafx.h"

#include "../FindAndReplace/Utils.h"
#include <boost/test/output/compiler_log_formatter.hpp>
#include <boost/algorithm/string/replace.hpp>

BOOST_AUTO_TEST_SUITE(Test)

BOOST_AUTO_TEST_CASE(Replace_Word_In_String)
{
	{
		string subject = "A bad beginning makes a bad ending.";
		auto newString = FindAndReplace(subject, "bad", "good");
		const string correctString = "A good beginning makes a good ending.";
		BOOST_CHECK(newString == correctString);
	}

}

BOOST_AUTO_TEST_CASE(Replace_Unexisting_Word_In_String)
{
	{
		string subject = "A bad beginning makes a bad ending.";
		auto newString = FindAndReplace(subject, "happy", "wonderful");
		BOOST_CHECK(newString == subject);
	}

}

BOOST_AUTO_TEST_CASE(Replace_Single_Character_In_String)
{
	{
		string subject = "Hotel";
		auto newString = FindAndReplace(subject, "H", "M");
		const string correctString = "Motel";
		BOOST_CHECK(newString == correctString);
	}
}

BOOST_AUTO_TEST_CASE(Replace_Several_Digits_In_String)
{
	{
		string subject = "111222333444";
		auto newString = FindAndReplace(subject, "111", "000");
		const string correctString = "000222333444";
		BOOST_CHECK(newString == correctString);
	}
}

BOOST_AUTO_TEST_SUITE_END()

/*
Данный класс управляет формаитрованием журнала запуска тестов
Для того, чтобы увидеть результат, приложение должно быть запущено с ключём --log_level=test_suite (см. Post-build event в настройках проекта)
*/
class SpecLogFormatter :
	public boost::unit_test::output::compiler_log_formatter
{
	virtual void test_unit_start(std::ostream &os, boost::unit_test::test_unit const& tu) override
	{
		// перед запуском test unit-а выводим имя test unit-а, заменяя символ подчеркивания на пробел
		os << std::string(m_indent, ' ') << boost::replace_all_copy(tu.p_name.get(), "_", " ") << std::endl;
		// увеличиваем отступ для вывода имен последующих test unit-ов в виде дерева
		m_indent += 2;
	}

	virtual void test_unit_finish(std::ostream &/*os*/, boost::unit_test::test_unit const& /*tu*/, unsigned long /*elapsed*/) override
	{
		// по окончании test unit-а уменьшаем отступ
		m_indent -= 2;
	}

	int m_indent = 0;
};

boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
	// Заменили имя log formatter на пользовательский
	boost::unit_test::unit_test_log.set_formatter(new SpecLogFormatter);
	// Имя корневого набора тестов - All tests
	boost::unit_test::framework::master_test_suite().p_name.value = "All tests";
	return 0;
}


int main(int argc, char* argv[])
{
	// Запускаем тесты, передавая параметры командной строки и кастомную функцию инициализации тестов
	return boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
}
