#include<stdio.h>
#include<stdlib.h>
// -------------------------------------Khai bao cau truc 1 Danh sach lien ket don---------------------------------------
// Khai bao Cau truc 1 Node (data + con tro)
typedef struct Node NODE;
struct Node
{
	int giatri;
	struct Node *pNext;
};


// Khai bao Cau truc 1 List bao gom Node dau va Node cuoi
typedef struct List LIST;
struct List
{
	NODE *pHead;//tao 1 con tro dang NODE o dau de tro den 1 bien dang NODE
	NODE *pTail;//tuong tu
};
// ------------------------------------Khoi tao 1 Danh sach lien ket don------------------------------------------------------


// Khoi tao con tro Head va Tail khi Danh sach chua co gi
void createList(LIST &l) // Truyen tham chieu 1 bien kieu LIST, "Tham chieu" : 1 bien khac chung 1 kieu du lieu va dung chung bo nho	
{
	l.pHead = NULL; 
	l.pTail = NULL;
} // Cho 2 con tro Head va Tail chi den NULL vi khi moi tao, chung chua tro den dau ca


// Khoi tao 1 NODE moi de chuan bi nhet vao Single Linked List
//Khai bao Node *... la de tra ve 1 con tro tro toi NODE dang tao hien tai
// Truyen tham tri, khong can truyen tham chieu vi no da co dia chi (virtual address) di kem roi !
NODE *createNODE(int x)
{
	NODE *p; // Khai bao 1 con tro kieu NODE
	p = (NODE*)malloc(sizeof(NODE)); // Cap phat dong bo nho cho con tro, ep kieu (NODE*) vi o day con tro tro den 1 NODE
	if(p == NULL) // Kiem tra xem da cap phat thanh cong chua, xem bo nho con du de cap phat khong ?
	{
		printf("\nKhong du bo nho cap phat");
		return NULL;
	}
	(*p).giatri = x; // Neu cap phat dong thanh cong, thi NODE se nhan gia tri (o day la so INT) ma chung ta dua vao
	(*p).pNext = NULL; // Do chua dua vao LIST, nen con tro Next trong NODE se khong tro toi dau
	return p; // Tra lai con tro tro vao NODE vua khai bao
}
//----------------------------------------------------Cac ham them----------------------------------------------------------------------------------------
//Tao ham Them NODE vao dau danh sach neu muon
void Themvaodau(LIST &l, NODE *p)  // Truyen tham chieu gia tri cua 2 con tro pHead va pTail, cung voi do la con tro tro toi NODE do
{
	if(l.pHead == NULL) // Khi danh sach rong, thi chi co 1 NODE, vay NODE day se la diem dau va diem cuoi ma con tro pHead va pTail tro vao
		l.pHead = l.pTail = p;
	else	// Khi danh sach da 1 hoac nhieu NODE roi, muon dua NODE vua tao len dau thi phai cho con tro Next trong NODE tro toi NODE tiep theo
	{
		(*p).pNext = l.pHead;
		l.pHead = p; // Cung voi do la cap nhat lai con tro dau (pHead), cap nhat lai chinh la con tro kieu NODE chua dia chi cua NODE vua tao
	}
}

//Tao ham Them NODE vao cuoi danh sach neu muon
void Themvaocuoi(LIST &l, NODE *p) // Truyen tham chieu va truyen dia chi tuong tu nhu tren
{
	if(l.pHead == NULL) //tuong tu
		l.pHead = l.pTail = p;
	else
	{
		(*(l.pTail)).pNext = p;
/* Dieu khien con tro. Luc nay, l.pTail da nhan gia tri dia tri cua NODE truoc (co the  hieu l.pTail = pPrev). Vi vay, khi muon them, lien ket mot NODE sau, 
ta phai dieu khien sao cho con tro dang truoc (dang tro toi gia tri NULL) se tro vao NODE muon them vao. Bang cach su dung toan tu * (dieu khien gia tri ben
trong dia chi dang tro toi) cho l.pTail, ta can dieu khien pNext cua NODE truoc tro toi dang sau nen ta se goi (*(l.pTail)).pNext = p, cung co the hieu
don gian hon la : (*pPrev).pNext = p. Tuc la su dung con tro dang tro toi NODE truoc de dieu khien pNext cua no tro toi NODE vua tao ! */ 
		l.pTail = p; // Sau do, cap nhat lai con tro pTail xuong NODE cuoi vua tao, nhan dia chi cua no
	}
}

NODE *searchNODE(LIST l, int x)// Ham tra ve con tro tro toi NODE duoc tim boi gia tri int trong no
{
	NODE *tmp;
	for(tmp = l.pHead; tmp != NULL; tmp = (*tmp).pNext)
	{
		if((*tmp).giatri == x)
			return tmp; // Neu tim thay se tra ve con tro
	}
	return NULL; // Neu khong tim thay se tra ve NULL
}

void Themvaosau(LIST &l, NODE *q, NODE *p) // Ham them NODE p vao sau NODE q
{
	if(q != NULL) // Ta phai dua vao ham NODE *searchNODE() o tren de tim duoc address, neu NODE ton tai, con tro tro toi NODE q se tra ve address cua NODE q
	{
		(*p).pNext = (*q).pNext; //Ta se lien ket: cho con tro pNext cua NODE p tro toi address ma pNext cua Node q dang tro toi
		(*q).pNext = p;//Tiep theo, update con tro pNext cua NODE q se tro toi NODE p
		if(q == l.pTail)//Truong hop NODE q nam o cuoi danh sach thi ta phai update con tro Tail phai tro toi NODE p
			l.pTail = p;
	}
	else if (q == NULL)// Nguoc lai, neu gia tri tim khong co, tuc la NODE q khong ton tai, duyet tu trai sang phai khong co tuc la danh sach rong
						// thi ta phai dua NODE p len lam NODE dau tien ! 
		Themvaodau(l,p);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------Cac ham xoa-----------------------------------------------------------------------------------------
void Xoadau(LIST &l, int &x)// Truyen List va tham chieu x vao de luu lai gia tri NODE sau khi xoa
{
	NODE *tmp;
	if(l.pHead == NULL)
	{
		printf("\nKhong co gi de xoa");
	}
	else
	{
		tmp = l.pHead;// Luu address ma con tro pHead tro toi hien tai, de sau xoa
		x = (*tmp).giatri; // Luu lai gia tri NODE sap xoa (neu co can dung cho sau)
		l.pHead = (*(l.pHead)).pNext; // Gan address moi la tro toi NODE tiep theo
		printf("\nGia tri vua xoa la %d tai dia chi %p",x,tmp);
		free(tmp);// Giai phong address cu, tra lai bo nho cho may tinh
	}
	printf("\npHead gio dang tro toi : %p",l.pHead);
}

void Xoacuoi(LIST &l, int &x)// tuong tu
{
	if(l.pHead == NULL)
	{
		printf("\nKhong co gi de xoa");
	}
	else
	{
		for(NODE *tmp = l.pHead; tmp != NULL; tmp = (*tmp).pNext)//Duyet de tim pTail de xoa NODE cuoi
		{
			if((*tmp).pNext == l.pTail) // Dat dieu kien tim pTail
			{
				x = (*(l.pTail)).giatri; // Luu lai gia tri int cua NODE sap (neu lan sau can su dung)
				printf("\nGia tri vua xoa la %d tai dia chi %p",x,l.pTail);
				free(l.pTail);// Giai phong NODE cuoi, tra lai bo nho cho may tinh
				(*tmp).pNext = NULL;// Cap nhat lai con tro cua NODE truoc NODE vua xoa, tro toi NULL
				l.pTail = tmp;//Cap nhat lai con tro pTail, tro toi dia chi cua NODE cuoi moi
			}
		}
	}
}

void Xoachon(LIST &l, int x)
{
	if(l.pHead == NULL)
		printf("\nKhong co gi de xoa");
	if ((*(l.pHead)).giatri == x)
	{
		int y;
		Xoadau(l,y);
		return; // Day la 1 diem dung, tranh mat thoi gian ve sau
	}
	if ((*(l.pTail)).giatri == x)
	{
		int y;
		Xoacuoi(l,y);
		return;
	}
	NODE *g; // Khai bao g se la NODE truoc do
	for(NODE *tmp = l.pHead; tmp != NULL; tmp = (*tmp).pNext)
	{
		if((*tmp).giatri == x)
		{
			g->pNext = tmp->pNext; // Bo qua lien ket NODE ma tmp dang tro hien tai, lien ket voi NODE ma con tro pNext dang chi sau do
			printf("\nGia tri vua xoa la %d tai dia chi %p",x,tmp);
			free(tmp); // Giai phong bo nho NODE muon xoa, tra lai address cho may tinh
			return;
		}
		g = tmp; //Set up diem NODE truoc cung cho g
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
// NOTE: Nho Excute moi 1 lan sua doi de file duoc save lai thi moi chay duoc !
