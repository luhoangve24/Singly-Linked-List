#include"LinkedList2.h"
//------------------------------------------------------Prototypes -------------------------------------------------------------
void Menu(LIST &l);
//------------------------------------------------------------------------------------------------------------------------------

int main()
{
	LIST l;
	createList(l); //Khoi tao danh sach lien ket don
	Menu(l); //Dung ham Menu da tao ben thu vien LinkedList2.h de lua chon cac tinh nang cua SLL(Singly Linked List)
	return 0;
}

//------------------------------------------Refer----------------------------------
/*
- https://www.youtube.com/channel/UCSSMahX759Ppn7diWOpo7Yw (Thien Tam Nguyen)
- https://codelearn.io/learning/data-structure-and-algorithms/805177
- https://topdev.vn/blog/danh-sach-lien-ket-don-trong-c/#xoa-o-sau-node-bat-ky
- https://khiemle.dev/con-tro-va-cap-phat-dong-trong-cpp
- https://nguyenvanhieu.vn/tham-chieu-va-tham-tri-trong-c/
- Sach Cau truc du lieu va Giai thuat - Le Minh Hoang
- Apprenez à programmer en C (Da duoc bien dich)
- https://cpp.daynhauhoc.com/8/0-con-tr/
- https://stackoverflow.com/questions/641715-8/c-how-to-free-nodes-in-the-linked-list
- Slide 05_LinkedLists - Co Giang Huyen
*/
//---------------------------------------------------------------------------------
