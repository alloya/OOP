#pragma once

#include "stdafx.h"

using namespace std;

bool CheckArgumentCount(const int argumentCount);

bool CheckReplacingString(const string & str);

string FindAndReplace(string const & subject, string const & search, string  const & replace);
