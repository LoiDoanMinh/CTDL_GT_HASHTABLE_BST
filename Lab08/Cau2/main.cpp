#include <iostream>
#include <string>
using namespace std;
struct SV
{
	int MSSV;
	string Ho;
	string Ten;
	float DTB;
};
struct NODE
{
	SV data;
	NODE* pLeft;
	NODE* pRight;
};
typedef NODE* TREE;
void KhoiTaoTree(TREE& t)
{
	t = NULL;
}
void NhapInf(SV& x)
{
	cout << "\nNhap MSSV : ";
	cin >> x.MSSV;
	cin.ignore();
	cout << "Nhap ho : ";
	getline(cin, x.Ho);
	cout << "Nhap ten : ";
	getline(cin, x.Ten);
	cout << "Nhap DTB : ";
	cin >> x.DTB;
	cin.ignore();
}
void XuatSV(SV A)
{
	cout << "MSSV : " << A.MSSV << endl;
	cout << "Ho Ten : " << A.Ho << " " << A.Ten << endl;
	cout << "DTB : " << A.DTB << endl;
}
void ThemNode(TREE &t, SV x)
{
	if (t == NULL)
	{
		NODE* p = new NODE;
		p->data = x;
		p->pLeft = p->pRight = NULL;
		t = p;
	}
	else
	{
		if ((t->data).MSSV > x.MSSV)
			ThemNode(t->pLeft, x);
		else
			ThemNode(t->pRight, x);
	}
}
void NLR(TREE t)
{
	if (t != NULL)
	{
		XuatSV(t->data);
		cout << endl;
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}
void LRN(TREE t)
{
	if (t != NULL)
	{
		LRN(t->pLeft);
		LRN(t->pRight);
		XuatSV(t->data);
		cout << endl;
	}
}
void TimNodeTheMang(TREE &p,TREE &pTM)
{
	if (pTM->pRight != NULL)
		TimNodeTheMang(p, pTM->pRight);
	else
	{
		(p->data)= (pTM->data);
		p = pTM;
		pTM = pTM->pLeft;
	}
}
void XoaNode(TREE& t,SV x)
{
	if (t == NULL)
		return ;
	else
	{
		if (x.MSSV < (t->data).MSSV)
			XoaNode(t->pLeft, x);
		else if (x.MSSV > (t->data).MSSV)
			XoaNode(t->pRight, x);
		else
		{
			NODE* p = t;
			if (t->pLeft == NULL)
				t = t->pRight;
			if (t->pRight == NULL)
				t = t->pLeft;
			else
				TimNodeTheMang(p, t->pLeft);
			delete p;
		}
	}
}
void XoaSVDuoi5(TREE& t)
{
	if (t == NULL)
		return;
	else
	{
		if ((t->data).DTB < 5)
			XoaNode(t, t->data);
		XoaSVDuoi5(t->pLeft);
		XoaSVDuoi5(t->pRight);
	}
}
void menu(TREE &t)
{
	while (true)
	{
		cout << "\n\t==========MENU==========";
		cout << "\n\t1.Nhap danh sach n sinh vien";
		cout << "\n\t2.Xuat Danh Sach theo cach duyet truoc(NLR) ";
		cout << "\n\t3.Xoa SV co DTB duoi 5 ra khoi DS va xuat theo cach duyet sau(LRN)";
		cout << "\n\t0.Thoat";
		cout << "\n\t==========END==========";
		int lc;
		cout << "\nNhap lua chon : ";
		cin >> lc;
		if (lc == 1)
		{
			int n;
			cout << "Nhap so luong sinh vien : ";
			cin >> n;
			cin.ignore();
			for (int i = 0; i < n; i++)
			{
				SV A;
				cout << "\nNhap SV thu : " << i + 1 ;
				NhapInf(A);
				ThemNode(t, A);
			}
		}
		if (lc == 2)
		{
			cout << "Danh sach SV !" << endl;
			NLR(t);
		}
		if (lc == 3)
		{
			XoaSVDuoi5(t);
			cout << "Danh sach SV co DTB lon hon 5 va duyet theo LRN!" << endl;
			LRN(t);
		}
		if (lc == 0)
			break;
	}
}

int main()
{
	TREE t;
	KhoiTaoTree(t);
	menu(t);
}