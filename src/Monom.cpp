#include "Monom.h"

PTDatValue TMonom :: GetCopy() { // ���������� �����
  PTDatValue temp = new TMonom(Coeff,Index);
  return temp;
}