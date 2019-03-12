#ifndef __POLINOM_H__
#define __POLINOM_H__
#include "HeadRing.h"
#include "Monom.h"
#include <iostream>

using namespace std;

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = nullptr, int km = 0); // �����������
												  // �������� �� ������� ������������-������
	TPolinom(const TPolinom &q);      // ����������� �����������
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom operator+(TPolinom &q); // �������� ���������
	TPolinom & operator=(TPolinom &q); // ������������

	friend ostream& operator<<(ostream &out, TPolinom &p);
};

#endif
