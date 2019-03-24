//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Block Table Entry Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./tableEntry.h"

// Constructors
TableEntry::TableEntry()
{
  index = -1;
  arrSize = 0;
  constVal = 0;
  depth = 0;
  kind = VARKIND;
  type = UNIV;
}

TableEntry::TableEntry(const int &i, const int &a, const int &c, const int &d, const mKind &k, const mType &t)
{
  index = i;
  arrSize = a;
  constVal = c;
  depth = d;
  kind = k;
  type = t;
}

TableEntry::TableEntry(const int &i, const int &d, const mKind &k, const mType &t)
{
  index = i;
  depth = d;
  kind = k;
  type = t;
}

// Public Methods
int TableEntry::getIndex()
{
  return index;
}

int TableEntry::getArrSize()
{
  return arrSize;
}

int TableEntry::getConstVal()
{
  return constVal;
}

int TableEntry::getDepth()
{
  return depth;
}

mKind TableEntry::getKind()
{
  return kind;
}

mType TableEntry::getType()
{
  return type;
}

void TableEntry::printEntry()
{
  cout << "Index: " << index << endl
       << "Array Size: " << arrSize << endl
       << "Constant Value: " << constVal << endl
       << "Block level: " << depth << endl
       << "Kind: " << kind << endl
       << "Type: " << type << endl
       << endl;
}