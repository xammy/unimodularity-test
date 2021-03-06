#include "common.h"

#include <assert.h>
#include <stdlib.h>

#include <stdio.h>

TU_ERROR  stringToDoubleMatrix(TU* tu, TU_DBLMAT** matrix, const char* string)
{
  assert(tu);
  char* end;
  int numRows, numColumns;

  /* Read size of matrix. */
  numRows = strtol(string, &end, 10);
  assert(end > string);
  string = end;
  numColumns = strtol(string, &end, 10);
  assert(end > string);
  string = end;

  TUdblmatCreate(tu, matrix, numRows, numColumns, numRows * numColumns);

  (*matrix)->numNonzeros = 0;
  for (int row = 0; row < (*matrix)->numRows; ++row)
  {
    (*matrix)->rowStarts[row] = (*matrix)->numNonzeros;
    for (int column = 0; column < (*matrix)->numColumns; ++column)
    {
      double x = strtod(string, &end);
      assert(end > string);
      string = end;

      if (x != 0.0)
      {
        (*matrix)->entryColumns[(*matrix)->numNonzeros] = column;
        (*matrix)->entryValues[(*matrix)->numNonzeros] = x;
        (*matrix)->numNonzeros++;
      }
    }
  }

  return TU_OKAY;
}

TU_ERROR stringToIntMatrix(TU* tu, TU_INTMAT** matrix, const char* string)
{
  assert(tu);
  char* end;
  int numRows, numColumns;

  /* Read size of matrix. */
  numRows = strtol(string, &end, 10);
  assert(end > string);
  string = end;
  numColumns = strtol(string, &end, 10);
  assert(end > string);
  string = end;

  TUintmatCreate(tu, matrix, numRows, numColumns, numRows * numColumns);

  (*matrix)->numNonzeros = 0;
  for (int row = 0; row < (*matrix)->numRows; ++row)
  {
    (*matrix)->rowStarts[row] = (*matrix)->numNonzeros;
    for (int column = 0; column < (*matrix)->numColumns; ++column)
    {
      int x = strtol(string, &end, 10);
      assert(end > string);
      string = end;

      if (x != 0)
      {
        (*matrix)->entryColumns[(*matrix)->numNonzeros] = column;
        (*matrix)->entryValues[(*matrix)->numNonzeros] = x;
        (*matrix)->numNonzeros++;
      }
    }
  }

  return TU_OKAY;
}

TU_ERROR stringToCharMatrix(TU* tu, TU_CHRMAT** matrix, const char* string)
{
  assert(tu);
  char* end;
  int numRows, numColumns;

  /* Read size of matrix. */
  numRows = strtol(string, &end, 10);
  assert(end > string);
  string = end;
  numColumns = strtol(string, &end, 10);
  assert(end > string);
  string = end;

  TU_CALL( TUchrmatCreate(tu, matrix, numRows, numColumns, numRows * numColumns) );

  (*matrix)->numNonzeros = 0;
  for (int row = 0; row < (*matrix)->numRows; ++row)
  {
    (*matrix)->rowStarts[row] = (*matrix)->numNonzeros;
    for (int column = 0; column < (*matrix)->numColumns; ++column)
    {
      int x = strtol(string, &end, 10);
      if (end == string)
        return TU_ERROR_INPUT;
      string = end;

      if (x != 0)
      {
        (*matrix)->entryColumns[(*matrix)->numNonzeros] = column;
        (*matrix)->entryValues[(*matrix)->numNonzeros] = x;
        (*matrix)->numNonzeros++;
      }
    }
  }

  return TU_OKAY;
}
