#ifndef _POLINOM_H_
#define _POLINOM_H_
#include <iostream>
#include "monom.h"
#include "datvalue.h"
#include "headring.h"

class TPolinom : public THeadRing {
public:
    TPolinom (int monoms[][2] = nullptr, int km = 0); // �����������
                     // �������� �� ������� ������������-������
    TPolinom (TPolinom &q);      // ����������� �����������
    PTMonom GetMonom() { return (PTMonom)GetDatValue(); }
    TPolinom &operator+=(TPolinom &q); // �������� ���������
    TPolinom &operator=(TPolinom &q); // ������������
    bool operator==(TPolinom &q);
    friend std::ostream& operator<<(std::ostream& os, TPolinom& q);
    friend std::istream& operator>>(std::istream& is, TPolinom& q);
};

#endif  // _POLINOM_H_
