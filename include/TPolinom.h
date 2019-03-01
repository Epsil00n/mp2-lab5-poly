#ifndef __TPOLINOM__
#define __TPOLINOM__
#include "THeadRing.h"
#include "TMonom.h"

class TPolinom : public THeadRing {
  public:
    TPolinom ( int monoms[][2]=NULL, int km=0 ); // �����������
                     // �������� �� ������� ������������-������
    TPolinom ( const TPolinom &q);      // ����������� �����������
    PTMonom  GetMonom()  { return (PTMonom)GetDatValue(); }
    TPolinom & operator+( TPolinom &q); // �������� ���������
    TPolinom & operator=( TPolinom &q); // ������������
};

#endif // __TPOLINOM__
