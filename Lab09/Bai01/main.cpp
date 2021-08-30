#include <iostream>
using namespace std;
#define M 11
#define NULLKEY 1
struct node
{
	int key;
};
node HASHTABLE[M];
int N;
int HF(int k)
{
	return k % 11;
}
int HF2(int k)
{
	return (M - 2 - k % (M - 2));
}
void KhoiTaoHASH()
{
	for (int i = 0; i < 11; i++)
		HASHTABLE[i].key = NULLKEY;
	N = 0;
}
bool Empty()
{
	return (N == 0 ? true : false);
}
bool Full()
{
	return((N == M - 1) ? true : false);
}
int ThemNode_TuyenTinh(int k)
{
	if (Full())
		cout << "BANG BAM DA DAY";
	else
	{
		int i = HF(k);
		while (HASHTABLE[i].key != NULLKEY)
		{
			i++;
			if (i >= M)
				i = i - M;
		}
		HASHTABLE[i].key = k;
		N = N + 1;
		return i;
	}
}
int ThemNode_DoBacHai(int k)
{
	if (Full())
		cout << "BANG BAM DA DAY";
	else
	{
		int i = HF(k);
		int d = 1;
		while (HASHTABLE[i].key != NULLKEY)
		{
			i = (i + d) % M;
			d = d + 2;
		}
		HASHTABLE[i].key = k;
		N = N + 1;
		return i;
	}
}
int ThemNode_BamKep(int k)
{
	if (Full())
		cout << "BANG BAM DA DAY";
	else
	{
		int i = HF(k);
		int j = HF2(k);
		while (HASHTABLE[i].key != NULLKEY)
		{
			i = (i + j) % M;
		}
		HASHTABLE[i].key = k;
		N = N + 1;
		return i;
	}
}
void Menu()
{
	while (true)
	{
		cout << "\n\t=========MENU=========";
		cout << "\n\t1.Bang bam chi duoc mo voi tham do tuyen tinh ";
		cout << "\n\t2.Bang bam chi duoc mo voi tham do binh phuong ";
		cout << "\n\t3.Bang bam day chuyen ";
		cout << "\n\t=========END=========";
		int lc;
		cout << "\nNhap lua chon : ";
		cin >> lc;
		if (lc == 1)
		{
			ThemNode_TuyenTinh(32);
			ThemNode_TuyenTinh(15);
			ThemNode_TuyenTinh(25);
			ThemNode_TuyenTinh(44);
			ThemNode_TuyenTinh(36);
			ThemNode_TuyenTinh(21);
			cout << "Ket qua \n";
		}
		if (lc == 2)
		{
			ThemNode_DoBacHai(32);
			ThemNode_DoBacHai(15);
			ThemNode_DoBacHai(25);
			ThemNode_DoBacHai(44);
			ThemNode_DoBacHai(36);
			ThemNode_DoBacHai(21);
			cout << "Ket qua \n";
		}
		if (lc == 3)
		{
			ThemNode_BamKep(32);
			ThemNode_BamKep(15);
			ThemNode_BamKep(25);
			ThemNode_BamKep(44);
			ThemNode_BamKep(36);
			ThemNode_BamKep(21);
		}
	}
}
void Duyet()
{
	for (int i = 0; i < M; i++)
	{
		cout << i << "\t";
		if (HASHTABLE[i].key == NULLKEY)
			cout << "NULLKEY" << endl;
		else
			cout << HASHTABLE[i].key << endl;
	}
}
int main()
{
	KhoiTaoHASH();
	cout << "Bam cac khoa lan luot : 32 15 25 44 36 21\n";
	while (true)
	{
		cout << "\n\t=========MENU=========";
		cout << "\n\t1.Bang bam chi duoc mo voi tham do tuyen tinh ";
		cout << "\n\t2.Bang bam chi duoc mo voi tham do binh phuong ";
		cout << "\n\t3.Bang bam day chuyen ";
		cout << "\n\t=========END=========";
		int lc;
		cout << "\nNhap lua chon : ";
		cin >> lc;
		if (lc == 1)
		{
			ThemNode_TuyenTinh(32);
			ThemNode_TuyenTinh(15);
			ThemNode_TuyenTinh(25);
			ThemNode_TuyenTinh(44);
			ThemNode_TuyenTinh(36);
			ThemNode_TuyenTinh(21);
			Duyet();
			break;
		}
		if (lc == 2)
		{
			ThemNode_DoBacHai(32);
			ThemNode_DoBacHai(15);
			ThemNode_DoBacHai(25);
			ThemNode_DoBacHai(44);
			ThemNode_DoBacHai(36);
			ThemNode_DoBacHai(21);
			Duyet();
			break;
		}
		if (lc == 3)
		{
			ThemNode_BamKep(32);
			ThemNode_BamKep(15);
			ThemNode_BamKep(25);
			ThemNode_BamKep(44);
			ThemNode_BamKep(36);
			ThemNode_BamKep(21);
			Duyet();
			break;
		}
	}

}
