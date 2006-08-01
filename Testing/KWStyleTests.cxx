/*=========================================================================

  Program:   KWStyle - Kitware Style Checker
  Module:    KWStyleTests.cxx

  Copyright (c) Kitware, Inc.  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include <iostream>
#include "itkTestMain.h" 


void RegisterTests()
{
 REGISTER_TEST(kwsSemiColonSpaceTest);
 REGISTER_TEST(kwsStatementPerLineTest);
}
