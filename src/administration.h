//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Administration Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "./scanner.h"

#define MAX_ERRORS 10

enum ErrorTypes
{
  ScanError,
  ParseError,
  ScopeError,
  TypeError
};

using namespace std;

class Administration
{
public:
  // Constructors
  Administration(ifstream &, ofstream &, Scanner &);

  // Destructor
  ~Administration();

  // Public Methods
  void error(const string &, const Token &);
  int scan();

private:
  // Data Members
  ifstream *inputFilePtr;
  ofstream *outputFilePtr;
  Scanner &scanner;
  int currentLine;
  bool correctLine;
  int errorCount;
};

#endif
