#include "headring.h"
#include "monom.h"
#include <iostream>

#ifndef __TPOLINOM_H__
#define __TPOLINOM_H__

#define PolinomWrongIndex -104

class TPolinom : public THeadRing {
  public:
    TPolinom ( int monoms[][2]=NULL, int km=0 ); // �����������
                     // �������� �� ������� ������������-������
    TPolinom (TPolinom &q);      // ����������� �����������
    TPolinom (const TPolinom &q);
    PTMonom  GetMonom()  { return (PTMonom)GetDatValue(); }
    TPolinom & operator+=( TPolinom &q); // �������� ���������
    TPolinom & operator=( TPolinom &q); // ������������
    bool operator==(TPolinom &q); //���������
    bool operator!=(TPolinom &q); //���������
    friend std::ostream& operator<<(std::ostream& out, TPolinom& p);
};

#endif // __TPOLINOM_H__
