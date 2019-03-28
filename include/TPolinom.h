#ifndef  __POLINOM_H
#define  __POLINOM_H
#include "TMonom.h"
#include "THeadRing.h"

class Polinom:public THeadRing
{
public:
	Polinom(int monoms[][2] = NULL , int km =0 );
	Polinom( Polinom&);
	PTMonom GetMonom() { return (PTMonom)GetDatValue(); }
	Polinom operator+(Polinom&);//�������� ���������
	Polinom& operator+=(Polinom&); // �������� ��������� � �������������
	bool operator==(Polinom&) ; //��������� ���������
	double get(double x, double y, double z); //������ �������� ��������
	Polinom& operator= (Polinom&); // ������������
	friend ostream& operator<<(ostream& os, Polinom&);
	friend istream& operator>>(istream& os, Polinom&);
};
#endif // ! __POLINOM_H
