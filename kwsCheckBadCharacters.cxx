/*=========================================================================

  Program:   KWStyle - Kitware Style Checker
  Module:    kwsCheckBadCharacters.cxx

  Copyright (c) Kitware, Inc.  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "kwsParser.h"

namespace kws {

/** Check if the current file as bad characters like ����*/
bool Parser::CheckBadCharacters(bool checkComments)
{
  m_TestsDone[BADCHARACTERS] = true;
  m_TestsDescription[BADCHARACTERS] = "Checking for bad characters";

  std::string buffer = m_BufferNoComment;
  if(checkComments)
    {
    buffer = m_Buffer;
    }
  
  bool hasErrors = false;
  
  unsigned long pos = 0;
  std::string::const_iterator it = buffer.begin();
  while(it!= buffer.end())
    {
    if(((*it)<0) ||((*it)>127))
      {
      Error error;
      error.line = this->GetLineNumber(pos,!checkComments);
      error.line2 = error.line;
      error.number = BADCHARACTERS;
      error.description = "Bad character";
      m_ErrorList.push_back(error);
      hasErrors = true;
      }
    pos++;
    it++;
    }

  
  return !hasErrors;
}

} // end namespace kws
