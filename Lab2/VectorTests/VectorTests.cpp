#include "stdafx.h"

#include "../vector/utils.h"
#include <boost/test/output/compiler_log_formatter.hpp>
#include <boost/algorithm/string/replace.hpp>

BOOST_AUTO_TEST_SUITE(Test)

BOOST_AUTO_TEST_CASE(Getting_numbers_to_vector)
{
	{
		std::stringstream str("2.5 4 3 -4.5 18.37 22");
		auto numbers = GetNumbers(str);
		const std::vector<double> correctVec = {
			2.5, 4, 3, -4.5, 18.37, 22
		};
		BOOST_CHECK(numbers == correctVec);
	}

	{
		std::stringstream str("");
		auto numbers = GetNumbers(str);
		const std::vector<double> correctVec = {};
		BOOST_CHECK(numbers == correctVec);
	}
}

BOOST_AUTO_TEST_CASE(Vector_processing_when_minimal_is_positive)
{
	{
		std::vector<double> numbers = {
			10, 6, 2, 100, 26
		};
		ModifyVector(numbers);
		const std::vector<double> correctVec = {
			20, 12, 4, 200, 52
		};
		BOOST_CHECK(numbers == correctVec);
	}
}

BOOST_AUTO_TEST_CASE(Vector_processing_when_minimal_is_negative)
{

	{
		std::vector<double> numbers = {
			10, 6, -2, 100, 26
		};
		ModifyVector(numbers);
		const std::vector<double> correctVec = {
			-20.000, -12.000, 4.000, -200.000, -52.000
		};
		BOOST_CHECK(numbers == correctVec);
	}
}

BOOST_AUTO_TEST_CASE(Vector_processing_when_minimal_is_zero)
{
	{
		std::vector<double> numbers = {
			10, 6, 0, 100, 26
		};
		ModifyVector(numbers);
		const std::vector<double> correctVec = {
			0, 0, 0, 0, 0
		};
		BOOST_CHECK(numbers == correctVec);
	}

}
BOOST_AUTO_TEST_CASE(Vector_processing_when_vector_is_empty)
{
	{
		std::vector<double> numbers = {
		};
		ModifyVector(numbers);
		const std::vector<double> correctVec = {
		};
		BOOST_CHECK(numbers == correctVec);
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
