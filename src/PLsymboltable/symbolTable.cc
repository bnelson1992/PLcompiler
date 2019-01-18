//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Implementation File
// Written By: Eric Den Haan and Blake Nelson
// Inspired By: https://gist.github.com/ducngtuan/4332979
//************************************************************************************

#include "./symbolTable.h"

using namespace std;

// Constructors
SymbolTable::SymbolTable()
{
  table = vector<Token>(TABLE_SIZE);
  occupiedCells = 0;
}

// Destructor
SymbolTable::~SymbolTable()
{
}

// init Method
// Initialize the Symbol Table with all reserved words
// Fill remaining space with NONAME Empty Token
void SymbolTable::init()
{
}

// search Method
// Given a lexeme, return the position in the table
// Or, if not found, return -1
int SymbolTable::search(const string &lexeme)
{
}

// insert Method
// Given a lexeme, create the appropriate Token and insert into Symbol Table
// If the lexeme already exists, return the position in the table
int SymbolTable::insert(const string &lexeme)
{
  int location = search(lexeme);
  if (location != -1)
  {
    return location;
  }

  occupiedCells++;
}

// isFull Method
// return true if Symbol Table is full, else false
bool SymbolTable::isFull()
{
  return occupiedCells == TABLE_SIZE;
}

// getOccupiedCells Method
int SymbolTable::getOccupiedCells()
{
  return occupiedCells;
}

// hash Method
// The hash function for the Symbol Table
int SymbolTable::hash(const string &lexeme)
{
  int value = 0;
  for (int i = 0; i < lexeme.length(); i++)
  {
    value = 37 * value + lexeme[i];
  }
  return value;
}

// findIndex Method
// Use the hash function to find the index of the new table entry
int SymbolTable::findIndex(const string &lexeme)
{
  int h = hash(lexeme) % TABLE_SIZE, offset = 0, index;

  while (offset < TABLE_SIZE)
  {
    index = (h + offset) % TABLE_SIZE;

    if (table[index].getSname() == NONAME)
    {
      return index;
    }

    offset++;
  }
  return -1;
}