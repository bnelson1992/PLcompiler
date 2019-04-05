//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Administration Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./administration.h"

// Constructors
Administration::Administration(ifstream &inputFile, ofstream &outputFile, Scanner &s) : scanner(s)
{
  inputFilePtr = &inputFile;
  outputFilePtr = &outputFile;
  currentLine = 1;
  errorCount = 0;
}

// Public Methods
Scanner Administration::getScanner()
{
  return scanner;
}

ifstream *Administration::getInputFilePtr()
{
  return inputFilePtr;
}

ofstream *Administration::getOutputFilePtr()
{
  return outputFilePtr;
}

int Administration::getCurrentLine()
{
  return currentLine;
}

int Administration::getErrorCount()
{
  return errorCount;
}

void Administration::incrementCurrentLine()
{
  currentLine++;
}

void Administration::error(const ErrorTypes &eType, const string &s, Token t)
{
  string errorType(s);
  Token temp(t);
  if (eType == ErrorTypes::ScanError)
  {
    cout << endl
         << "Scanner encountered an error at line " << currentLine << ": " << s << ": " << temp.getSval().getLexeme() << endl
         << endl;
  }

  else if (eType == ErrorTypes::ParseError)
  {
    cout << endl
         << "Syntax error from parser at line " << currentLine << endl
         << endl;
  }
  else if (eType == ErrorTypes::ScopeError)
  {
    cout << endl
         << "Scope error at line " << currentLine << ": " + s + " " << endl
         << endl;
  }
  else if (eType == ErrorTypes::TypeError)
  {
    cout << endl
         << "Type error at line " << currentLine << ": " + s + " " << endl
         << endl;
  }

  errorCount++;
}

void Administration::fatal(const string &s)
{
  cout << s << endl;
  exit(1);
}

void Administration::emit1(const string &opcode)
{
  if (errorCount == 0)
  {
    // cout << opcode << endl;
    *outputFilePtr << opcode << endl;
  }
}

void Administration::emit2(const string &opcode, const int &arg1)
{
  if (errorCount == 0)
  {
    // cout << opcode << endl
    //      << arg1 << endl;
    *outputFilePtr << opcode << endl
                   << arg1 << endl;
  }
}

void Administration::emit3(const string &opcode, const int &arg1, const int &arg2)
{
  if (errorCount == 0)
  {
    // cout << opcode << endl
    //      << arg1 << endl
    //      << arg2 << endl;
    *outputFilePtr << opcode << endl
                   << arg1 << endl
                   << arg2 << endl;
  }
}
