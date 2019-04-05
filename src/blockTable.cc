//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Block Table Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./blockTable.h"

// Constructors
BlockTable::BlockTable()
{
  table.clear();
  blockLevel = 0;
}

// Public Methods
bool BlockTable::searchBlock(const int &index)
{
  for (unsigned int i = 0; i != table.back().size(); i++)
  {
    if (index == table.back()[i].getIndex())
    {
      return true;
    }
  }
  return false;
}

bool BlockTable::insert(const int &index, const int &arrSize, const int &constVal, const int &disp, const int &startLabel, const mKind &kind, const mType &type)
{
  bool canInsert = false;
  if (table.back().empty())
  {
    canInsert = true;
    TableEntry entry = TableEntry(index, arrSize, constVal, blockLevel, disp, startLabel, kind, type);
    table.back().push_back(entry);
  }

  else
  {
    canInsert = true;
    for (unsigned int i = 0; i != table.back().size(); i++)
    {
      if (index == table.back()[i].getIndex())
      {
        canInsert = false;
        break;
      }
    }
    if (canInsert)
    {
      TableEntry entry = TableEntry(index, arrSize, constVal, blockLevel, disp, startLabel, kind, type);
      table.back().push_back(entry);
    }
  }
  return canInsert;
}

TableEntry BlockTable::searchTable(const int &index)
{
  if (searchBlock(index) == true)
  {
    for (unsigned int i = 0; i != table.back().size(); i++)
    {
      if (index == table.back()[i].getIndex())
      {
        return table.back()[i];
      }
    }
  }
  else
  {
    for (unsigned int i = 0; i != table.size(); i++)
    {
      for (unsigned int j = 0; j != table[i].size(); j++)
      {
        if (index == table[i][j].getIndex())
        {
          return table[i][j];
        }
      }
    }
  }
  return TableEntry();
}

bool BlockTable::newBlock()
{
  if (table.size() >= MAXBLOCK)
  {
    return false;
  }
  else
  {
    blockLevel++;
    vector<TableEntry> vec;
    vec.clear();
    table.push_back(vec);
    return true;
  }
}

void BlockTable::endBlock()
{
  table.pop_back();
  blockLevel--;
}

int BlockTable::currentBlockLevel()
{
  return blockLevel;
}

void BlockTable::printBlock()
{
  for (unsigned int i = 0; i < table.back().size(); i++)
  {
    table.back()[i].printEntry();
  }
}

void BlockTable::printTable()
{
  cout << "---Table---" << endl;
  for (unsigned int i = 0; i < table.size(); i++)
  {
    cout << "--Block level " << i + 1 << ": --" << endl;
    for (unsigned int j = 0; j < table[i].size(); j++)
    {
      table[i][j].printEntry();
    }
  }
}

int BlockTable::tableSize()
{
  return table.size();
}

int BlockTable::blockSize()
{
  return table.back().size();
}
