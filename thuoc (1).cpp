#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct SANPHAM
{
	char maSP[10];
	char tenSP[10];
	float donGia;
	int soLuong;
	float thanhTien;
};
struct Node
{
	SANPHAM data;
	Node *link;
};
struct List
{
	Node *first,*last;
};
void Init(List &l);
Node *GetNode(SANPHAM sp);
void AddLast(List &l,Node *new_ele);
void InsertLast(List &l,SANPHAM sp);
void NhapSP(SANPHAM &sp);
void CreateList(List &l);
void XuatSP(SANPHAM sp);
void PrintList(List l);
void TinhTong(List l);
void timKiem(List l,SANPHAM sp);
void sapXep(List l);
int main()
{
	SANPHAM sp;
	List l;
	Init(l);
	CreateList(l);
	PrintList(l);
	return 0;
}
void Init(List &l)
{
	l.first=l.last=NULL;
}
Node *GetNode(SANPHAM sp)
{
	Node *p;
	p=new Node;
	if(p==NULL)
	{
		printf("Danh sach rong\n");
		return NULL;
	}
	p->data=sp;
	p->link=NULL;
	return p;
}
void AddLast(List &l,Node *new_ele)
{
	if(l.last==NULL)
	{
		l.first=l.last=new_ele;
	}
	else
	{
		l.last->link=new_ele;
		l.last=new_ele;
	}
}
void InsertLast(List &l,SANPHAM sp)
{
	Node *new_ele=GetNode(sp);
	if(new_ele==NULL)
	{
		return;
	}
	AddLast(l,new_ele);
}
void NhapSP(SANPHAM &sp)
{
	printf("Ma san pham:");fflush(stdin);
	gets(sp.maSP);
	printf("Ten san pham:");fflush(stdin);
	gets(sp.tenSP);
	do
	{
		printf("Don Gia:");
		scanf("%d",&sp.donGia);
		printf("So Luong:");
		scanf("%d",&sp.soLuong);
	}while(sp.donGia<=0||sp.soLuong<=0);
	sp.thanhTien=sp.donGia*sp.soLuong;
	if(strcmp(sp.maSP,sp.tenSP)==0)
	{
		printf("Ten san pham hoac ma san pham khong trung nhau\n");
	}
	else
	{
		printf("DONE\n");
	}
}
void CreateList(List &l)
{
	Node *p;
	SANPHAM sp;
	int n;
	do
	{
		NhapSP(p->data);	
		printf("n=0 de ket thuc:");
		scanf("%d",&n);
		InsertLast(l,sp);
		if(n==0)
		 break;
	}while(n!=0);
}
void XuatSP(SANPHAM sp)
{
	printf("Ma san pham:%s\n",sp.maSP);
	printf("Ten san pham:%s\n",sp.tenSP);
	printf("Don Gia:%f\n",sp.donGia);
	printf("So Luong:%d\n",sp.soLuong);
	printf("Thanh tien:%f\n",sp.thanhTien);
}
void PrintList(List l)
{
	Node *p;
	p=l.first;
	while(p!=NULL)
	{
		XuatSP(p->data);
		p=p->link;
	}
}
void TinhTong(List l)
{
	float s=0;
	Node *p;
	p=l.first;
	while(p!=NULL)
	{
		s+=p->data.thanhTien;
		p=p->link;
	}
	printf("Tong thanh tien:%f",s);
}
void timKiem(List l,SANPHAM sp)
{
	Node *p;
	p=l.first;
	while(p!=NULL)
	{
		if(p->data.soLuong>100)
		{
			printf("Da tim thay\n");
		}
		p=p->link;
	}
	printf("Ko tim thay\n");
}
void Swap(float &a,float &b)
{
	float temp=a;
	a=b;
	b=temp;
}
void sapXep(List l)
{
	for(Node *p=l.first;p!=l.last;p=p->link)
	{
		for(Node *q=p->link;q!=NULL;q=q->link)
		{
			if(p->data.donGia>q->data.donGia)
			{
				Swap(p->data.donGia,q->data.donGia);
			}
		}
	}
}
void ghiFile(FILE *f,List &l)
{	
	f=fopen("a.txt","w");
	Node *p;
	p=l.first;
	if(f==NULL)
	{
		printf("ko mo duoc\n");
	}
	while(p!=NULL)
	{
		fprintf("ten:%s ma:%s",p->data.tenSP,p->data.maSP);
		p=p->link;
	}
}

	