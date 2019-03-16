#ifndef __TPOLINOM_H__
#define __TPOLINOM_H__

#include "HeadRing.h"
#include "Monom.h"


class TPolinom : public THeadRing {
  public:
    TPolinom ( int monoms[][2]=nullptr, int km=0 ); // �����������
                     // �������� �� ������� ������������-������
    TPolinom (TPolinom &q);      // ����������� �����������
    PTMonom  GetMonom() const { return (PTMonom) GetDatValue(); }
    TPolinom operator+( TPolinom &q); // �������� ���������
    TPolinom & operator=( TPolinom &q); // ������������
	bool operator==(TPolinom &q); 
    bool operator!=(TPolinom &q); 
	friend std::ostream& operator<< (std::ostream &os, TPolinom &q);
};

#endif //__TPOLINOM_H__
