
#include <iostream>
#include <string>
using namespace std;
struct Item
{
	string word;
	string meaning;
};
struct NODE
{
	Item data;
	NODE* pLeft;
	NODE* pRight;
};
typedef NODE* TREE;
void KhoiTaoTree(TREE& t)
{
	t = NULL;
}
void NhapInf(Item& x)
{
	cin.ignore();
	cout << "Word : ";
	getline(cin, x.word);
	cout << "Meaning : ";
	getline(cin, x.meaning);
}
void ThemNode(TREE& t, Item x)
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
		if (((t->data).word).compare(x.word) > 0)
			ThemNode(t->pLeft, x);
		else
			ThemNode(t->pRight, x);
	}
}
NODE* TimKiemWORD(TREE& t, string x)
{
	if (t != NULL)
	{
		if ((t->data).word.compare(x) == 0)
			return t;
		if ((t->data).word.compare(x) > 0)
			return TimKiemWORD(t->pLeft, x);
		else
			return TimKiemWORD(t->pRight, x);
	}
	return NULL;
}
void TimNodeTheMang(TREE& p, TREE& pTM)
{
	if (pTM->pLeft != NULL)
		TimNodeTheMang(p, pTM->pLeft);
	else
	{
		p->data = pTM->data;
		p = pTM;
		pTM = pTM->pRight;
	}
}
int XoaNode(TREE &t, string W)
{
	if (t == NULL)
		return 0;
	else
	{
		if ((t->data).word.compare(W) > 0)
			return XoaNode(t->pLeft, W);
		if ((t->data).word.compare(W) < 0)
			return XoaNode(t->pRight, W);
		else
		{
			NODE* p = new NODE;
			p = t;
			if (t->pRight == NULL)
				t = t->pLeft;
			else if (t->pLeft == NULL)
				t = t->pRight;
			else
			{
				TimNodeTheMang(p, t->pRight);
			}
			delete p;
			return 1;
		}
	}
}
/*void XoaWORD(TREE& t, string W)
{
	if (t == NULL)
		return;
	else
	{
		if (t->data.word.compare(W) == 0)
		{
			XoaNode(t, t->data);
		}
		XoaWORD(t->pLeft, W);
		XoaWORD(t->pRight, W);
	}
}*/
void LNR(TREE t)
{
	if (t != NULL)
	{
		LNR(t->pLeft);
		cout << t->data.word << " : " << t->data.meaning << endl;
		LNR(t->pRight);
	}
}
void Menu(TREE& t)
{
	while (true)
	{
		cout << "\n\t==========MENU==========";
		cout << "\n\t1.Them 1 Item vao tu dien";
		cout << "\n\t2.Tim kiem nghia cua mot tu";
		cout << "\n\t3.Xoa Khoi tu dien tu co word ";
		cout << "\n\t4.In tat ca meaning theo thu tu word tang dan ";
		cout << "\n\t0.Thoat";
		cout << "\n\t==========END==========";
		int lc;
		cout << "\nNhap lua chon : ";
		cin >> lc;
		if (lc == 1)
		{
			Item A;
			NhapInf(A);
			ThemNode(t, A);
		}
		if (lc == 2)
		{
			cin.ignore();
			string W;
			cout << "Nhap word can tim : ";
			getline(cin, W);
			NODE* p = new NODE;
			p = TimKiemWORD(t, W);
			if (p != NULL)
				cout << "Nghia cua WORD : " << W << " : " << p->data.meaning;
			else
				cout << "Khong tim thay !";
		}
		if (lc == 3)
		{
			cin.ignore();
			string W;
			cout << "Nhap word can xoa : ";
			getline(cin, W);
			int kq=XoaNode(t, W);
			if (kq == 1)
				cout << "Xoa thanh cong !";
			else
				cout << "Xoa khong thanh cong !";
		}
		if (lc == 4)
		{
			cout << "tat ca meaning theo thu tu word tang dan\n";
			LNR(t);
		}
		if (lc == 0)
			break;
	}
}
int main()
{
	TREE t;
	KhoiTaoTree(t);
	Menu(t);
}
