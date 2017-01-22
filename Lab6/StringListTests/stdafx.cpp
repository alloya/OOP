// stdafx.cpp : source file that includes just the standard includes
// StringListTests.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: Установите ссылки на любые требующиеся дополнительные заголовки в файле STDAFX.H
// , а не в данном файле
// Сообщаем библиотеке boost test, что функция main будет предоставлена нами (для предварительного конфигурирования библиотеки), 
// а не сгенерирована boost-ом за нас
#define BOOST_TEST_NO_MAIN 
// подключаем реализацию boost test
#include <boost/test/included/unit_test.hpp>