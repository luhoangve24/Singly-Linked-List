#include"LinkedList.h"
#include<time.h>
//----------------------------------------------Prototypes----------------------------------------------------------------
void createList(LIST &l);
void freeList(LIST &l);
void timMax(LIST l);
void Xuat(LIST l);
void takeNODE(LIST &l);
void takeNODEbyINFO(LIST l, int x);
void InterchangeSort_DATA(LIST l);
//-------------------------------------------------------------------------------------------------------------------------
void takeNODE(LIST &l)
{
	int q,count= 0,q1 = 0;
	for(NODE *k = l.pHead; k != NULL; k = (*k).pNext) // Chay vong lap, bat dau tu dia chi ma Head dang tro toi, chinh la dia chi cua NODE dau tien
	{
		count++;
	}
	printf("\n > Danh sach nay co %d NODE",count);
	if(count != 0)
	{
		printf("\n > Nhap thu tu NODE muon lay thong tin:");
		scanf("%d",&q);
	}
	else
		printf("\n > Empty List, can't search");
	for(NODE *k = l.pHead; k != NULL; k = (*k).pNext)
	{
		printf("\t\t|%d	| ",(*k).giatri);
		printf("Dia chi tro toi: %p|", (*k).pNext);
		if(q1+1 == q)
			printf("-> Day la NODE ban muon tim");
		printf("\n");
		q1++;
		if(q1 == q)
			break;
	}
}
void freeList(LIST &l)
{
	NODE *tmp;
	while(l.pHead != NULL)
	{
		tmp = l.pHead;
		l.pHead = (*(l.pHead)).pNext;
		free(tmp);
	}
	l.pTail = NULL;
}

/*void takeNODEbyINFO(LIST l, int x)
{
	NODE *tmp;
	NODE *d;
	int c = 0, coun;
	for(tmp = l.pHead; tmp != NULL; tmp = (*tmp).pNext)
	{
		if((*tmp).giatri == x)
		{
			d = tmp;
			coun = c + 1;
			break;
		}
		c++;
	}
	if(tmp != NULL)
	{
		printf("\nTim thay !");
		printf("\n - Gia tri %d thuoc NODE thu %d \n - NODE duoc tro boi con tro co dia chi %p \n - Con tro trong NODE tro toi dia chi %p",x,coun,d,(*d).pNext);
	}
	else
		printf("\nKhong tim thay :(");
}*/ // Ham nay con tra ve them chi so INDEX o moi NODE nhung khong dap ung nhu cau thuat toan de bai 
void takeNODEbyINFO(LIST l, int x)
{
	NODE *tmp = searchNODE(l,x);
	if(tmp == NULL)
		printf("\nKhong tim thay");
	else
	{
		printf("\nTim thay !");
		printf("\n - Gia tri %d \n - NODE duoc tro boi con tro tro toi dia chi %p \n - Con tro trong NODE tro toi dia chi %p",x,tmp,(*tmp).pNext);
	}
}

void InterchangeSort_DATA(LIST l)
{
	NODE *p, *q;
	p = l.pHead;
	int min;
	while(p != l.pTail)
	{
		min = (*p).giatri;
		q = (*p).pNext;
		while(q != NULL)
		{
			if(min > (*q).giatri)
			{
				min = (*q).giatri;
				(*q).giatri = (*p).giatri;
				(*p).giatri = min;
			}
			q = (*q).pNext;
		}
		p = (*p).pNext;
	}
}
void Xuat(LIST l)
{
	int q,count= 0,q1 = 0;
	for(NODE *k = l.pHead; k != NULL; k = (*k).pNext)
	{
		printf("\t\t|%d| ",(*k).giatri);
		printf("Dia chi tro toi: %p| ", (*k).pNext);
		printf("\n");
		count++;
	}
	printf("\n > Danh sach nay co %d NODE",count);
	printf("\n-Dia chi cua Head : %p, Dia chi Head dang tro : %p\n-Dia chi cua Tail : %p, Dia chi Tail dang tro : %p ",&(l.pHead),l.pHead,&(l.pTail),l.pTail);
}

void timMax(LIST l)
{
	NODE *ptr;
	NODE *tmp = l.pHead;// Ta se gan gia tri int cua NODE dau tien la max, roi sau do chay vong lap de so sanh
	for(ptr = l.pHead; ptr != NULL; ptr = (*ptr	).pNext)
	{
		if((*tmp).giatri < (*ptr).giatri)
			tmp = ptr;
	}
	printf("\nGia tri lon nhat la %d",(*tmp).giatri);
}

void Menu(LIST &l)
{
	while (true)
	{
		char n;
		printf("\n");
		printf("\n\t<=========================MENU===============================>");
		printf("\n\t|	----------Chon 1 trong cac tinh nang o duoi :----------");
		printf("\n\t|	Bam 0 de them 1 NODE o truoc");
		printf("\n\t|	Bam 1 de them 1 NODE o cuoi ");
		printf("\n\t|	Bam 2 de in Danh sach lien ket don");
		printf("\n\t|	Bam 3 de dung chuong trinh");
		printf("\n\t|	Bam 4 de tim ra so lon nhat trong danh sach");
		printf("\n\t|	Bam 5 de giai phong bo nho toan danh sach (Xoa danh sach)");
		printf("\n\t|	Bam 6 de lay thong tin 1 NODE bang cach duyet danh sach theo chi so");
		printf("\n\t|	Bam 7 de them 1 NODE dang sau 1 NODE co san");
		printf("\n\t|	Bam 8 de xoa NODE dau (HEAD) danh sach");
		printf("\n\t|	Bam 9 de xoa NODE cuoi (TAIL) danh sach");
		printf("\n\t|	Bam a de xoa 1 NODE bang tim kiem DATA");
		printf("\n\t|	Bam b de lay thong tin 1 NODE bang DATA cua no");
		printf("\n\t|	Bam c de tao 1 Danh sach lien ket don bang sinh so ngau nhien (RANDOM) ");
		printf("\n\t|	Bam d de sap xep 1 NODE bang thuat toan : InterchangeSort, doi cho DATA cho cac NODE");
		printf("\n\t<=============================================================>");
		printf("\n- Input: ");
		fflush(stdin);
		scanf("%c",&n);
		printf("\n- Output:\n");
		while ((n > '9' || n < '0') && (n < 'a' || n > 'd'))
		{
			printf("\nWrong input, please check !\n");
			printf("Do it again, human ! Your input :");
			fflush(stdin);
			scanf("%c",&n);
		}
		switch (n)
		{
			case '0':
				{
					int x;
					printf("\nYour number you want to add ? :");
					scanf("%d",&x);
					NODE *p = createNODE(x);
					Themvaodau(l,p);
					system("cls");
				}
				break;
			case '1':
				{
					int x;
					printf("\n > Your number you want to add ? :");
					scanf("%d",&x);
					NODE *p = createNODE(x);
					Themvaocuoi(l,p);
					system("cls");
				}
				break;
			case '2':
				{
					printf("\n > Your Singly Linked List\n");
					Xuat(l);
				}
				break;
			case '4':
				{
					if(l.pHead == NULL)
						printf("\n\t\tYour list is empty man !");
					else
						timMax(l);
				}
				break;
			case '5':
				{
					freeList(l);
				}
				break;
			case '6':
				{
					takeNODE(l);
				}
				break;
			case '7':
				{
					int x;
					printf("\nInput the number of the NODE you want to add a NOTE behind it: ");
					scanf("%d",&x);
					int x1;
					printf("\nInput the number of the NODE you want to create: ");
					scanf("%d",&x1);
					NODE *p = createNODE(x1);
					Themvaosau(l, searchNODE(l,x), p);
				}
				break;
			case '8':
				{
					int x;
					Xoadau(l,x);
					printf("\nGia tri vua xoa la %d",x);
				}
				break;
			case '9':
				{
					int x;
					Xoacuoi(l,x);
					printf("\nGia tri vua xoa la %d",x);
				}
				break;
			case 'a':
				{
					int x;
					printf("\nNhap so ma ban muon xoa NODE cua no:");
					scanf("%d",&x);
					Xoachon(l,x);
				}
				break;
			case 'b':
				{
					int x;
					printf("\nNhap so ma ban muon kiem tra thong tin NODE do:");
					scanf("%d",&x);
					takeNODEbyINFO(l,x);
				}
				break;
			case 'c':
				{
					if(l.pHead != NULL)
					printf("\nDanh sach nay khong rong nen khong the tao !");
					else
					{
						int z;
						printf("\nNhap so luong NODE ban muon tao:");
						scanf("%d",&z);
						srand((int)time(0));
						for(int i = 1; i <= z; i++)
						{
							NODE *p = createNODE(rand()%100);
							Themvaodau(l,p);
						}		
					}
				}
				break;
			case 'd':
				{
					InterchangeSort_DATA(l);
				}
				break;
			
			default:
			{
				printf("Exit . . . See ya !");
				exit(0);
			}
			break;
		}
	}
}
/*		if(n == '0')
		{
			int x;
			printf("\nYour number you want to add ? :");
			scanf("%d",&x);
			NODE *p = createNODE(x);
			Themvaodau(l,p);
			system("cls");
		}
		else if (n == '1')
		{
			int x;
			printf("\n > Your number you want to add ? :");
			scanf("%d",&x);
			NODE *p = createNODE(x);
			Themvaocuoi(l,p);
			system("cls");
		}
		else if (n == '2')
		{
			printf("\n > Your Singly Linked List\n");
			Xuat(l);
		}
		else if (n == '3')
		{
			printf("\n > Exit . . ., see ya !");
			break;
		}
		else if (n == '4')
		{
			if(l.pHead == NULL)
				printf("\n\t\tYour list is empty man !");
			else
			timMax(l);
		}
		else if (n == '5')
			freeList(l);
		else if (n == '6')
			takeNODE(l);
		else if (n == '7')
		{
			int x;
			printf("\nInput the number of the NODE you want to add a NOTE behind it: ");
			scanf("%d",&x);
			int x1;
			printf("\nInput the number of the NODE you want to create: ");
			scanf("%d",&x1);
			NODE *p = createNODE(x1);
			Themvaosau(l, searchNODE(l,x), p);
		}
		else if (n == '8')
		{
			int x;
			Xoadau(l,x);
			printf("\nGia tri vua xoa la %d",x);
		}
		else if (n == '9')
		{
			int x;
			Xoacuoi(l,x);
			printf("\nGia tri vua xoa la %d",x);
		}
		else if (n == 'a')
		{
			int x;
			printf("\nNhap so ma ban muon xoa NODE cua no:");
			scanf("%d",&x);
			Xoachon(l,x);
		}
		else if (n == 'b')
		{
			int x;
			printf("\nNhap so ma ban muon kiem tra thong tin NODE do:");
			scanf("%d",&x);
			takeNODEbyINFO(l,x);
		}
		else if (n == 'c')
		{
			if(l.pHead != NULL)
				printf("\nDanh sach nay khong rong nen khong the tao !");
			else
			{
				int z;
				printf("\nNhap so luong NODE ban muon tao:");
				scanf("%d",&z);
				srand((int)time(0));
				for(int i = 1; i <= z; i++)
				{
					NODE *p = createNODE(rand()%100);
					Themvaodau(l,p);
				}		
			}
		}
		else if (n == 'd')
		{
			InterchangeSort_DATA(l);
		}
	}
}*/
// NOTE: Nho Excute moi 1 lan sua doi de file duoc save lai thi moi chay duoc !
