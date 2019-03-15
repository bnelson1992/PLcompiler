#include "./blockTable.h"

BlockTable::BlockTable()
{
    table.clear();
    blockLevel = 0;
}

bool BlockTable::search(const int &index)
{
    for(auto i = table[blockLevel].begin(); i != table[blockLevel].end(); i++)
    {
      if(index == i->getIndex())
      {
        return true;
      }
    }
    return false;
}

bool BlockTable::insert(const int &index, const int &arrSize, const int &constVal, const mKind &kind, const mType &type)
{
  if(table.back().empty())
  {
    cout << "empty block" << endl;
    TableEntry entry = TableEntry(index, arrSize, constVal, blockLevel, kind, type);
    table.back().push_back(entry);
    return true;
  }

  else
  {
    for(unsigned int i = 0; i != table.back().size(); i++)
    {
      if(index == table.back()[i].getIndex())
      {
        cout << "Previously defined ID" << endl; //already have this entry
        return false;
      }

      else
      {
        cout << "valid entry" << endl;
        TableEntry entry = TableEntry(index, arrSize, constVal, blockLevel, kind, type);
        table.back().push_back(entry);
        return true;
      }
    }
  }
}

bool BlockTable::find(const int &index, const bool &error)
{
  for(unsigned int i = 0; i != table.size(); i++)
  {
    for(unsigned int j = 0; j != table[i].size(); j++)
    {
      if(index == table[i][j].getIndex())
      {
        //return *j;
        return true;
      }
    }
  }
  return false;
}

bool BlockTable::newBlock()
{
  if(table.size() >= MAXBLOCK)
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
  for(unsigned int i = 0; i < table[blockLevel].size(); i++)
  {
    table[blockLevel][i].printEntry();
  }
}

void BlockTable::printTable()
{
  for(unsigned int i = 0; i < table.size(); i++)
  {
    for(unsigned int j = 0; j < table[i].size(); j++)
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
