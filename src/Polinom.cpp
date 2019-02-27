#include "Polinom.h"


TPolinom :: TPolinom ( int monoms[][2], int km ) { // ����������� �������� �� ������� ������������-������
	PTMonom pMonom = new TMonom (0, -1);
	pHead = (PTDatLink)pMonom;
	for (int i = 0; i < km; i++) {
		pMonom = new TMonom(monoms[i][0],monoms[i][1]);
		InsLast(pMonom);
	}
}
TPolinom :: TPolinom (TPolinom &q) {    // ����������� �����������
	PTMonom pMonom = new TMonom (0, -1);
	pHead = (PTDatLink)pMonom;
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
		pMonom = q.GetMonom();
		InsLast(pMonom -> GetCopy());
	}
	delete pMonom;
}

TPolinom TPolinom :: operator+( TPolinom &q) { // �������� ���������
	PTMonom pm, qm, rm;
	Reset();
	q.Reset();
	while (1) {
		pm = GetMonom();
		qm = q.GetMonom();

		if (pm->Index < qm->Index) { //����� pm ������ ������ qm, ����� ��������� qm � p
			rm = new TMonom(qm->Coeff, qm->Index);
			InsCurrent(rm);
			q.GoNext();
		}
		else if (pm->Index > qm->Index) GoNext();
		else { //������� �����
			if (pm->Index == -1) //��������, �� ������ ��?
				break;
			pm->Coeff += qm->Coeff;
			if (pm->Coeff != 0) {
				GoNext();
				q.GoNext();
			}
			else {
				DelCurrent();
				q.GoNext();
			}
		}
		if (IsListEnded()) {
			for (;!q.IsListEnded(); q.GoNext()) {
				rm = new TMonom(qm->Coeff, qm->Index);
				InsLast(rm);
			}
			break;
		}
	}
	return *this;

	}

TPolinom & TPolinom :: operator=( TPolinom &q) { // ������������
	PTMonom pMonom = new TMonom (0, -1);
	pHead -> SetDatValue (pMonom);
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
		pMonom = q.GetMonom();
		InsLast(pMonom -> GetCopy());
	}
	delete pMonom;
	return *this;
}

std::ostream& operator<< (std::ostream &os, TPolinom &q) {
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
		os<<*q.GetMonom()<<std::endl;
	}
	return os;
}