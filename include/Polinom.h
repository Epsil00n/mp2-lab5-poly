#ifndef __TPOLINOM_H__
#define __TPOLINOM_H__

class TPolinom : public THeadRing {
  public:
    TPolinom ( int monoms[][2]=NULL, int km=0 ); // �����������
                     // �������� �� ������� ������������-������
    TPolinom ( const TPolinom &q);      // ����������� �����������
    PTMonom  GetMonom()  { return (PTMonom)GetDatValue(); }
    TPolinom & operator+( TPolinom &q); // �������� ���������
    TPolinom & operator=( TPolinom &q); // ������������
};

#endif // __TPOLINOM_H__
