#include<iostream>
#include<string>
using namespace std;

struct ThucDon
{
  int codeName;
  string Name;
  int Cost;
};

struct MENU
{
  ThucDon TD;
  MENU *next;
};

struct GoiMon
{
  int codeName;
  int soPhan;
  int thanhTien;
};

struct ORDER
{
  GoiMon GM;
  ORDER *next;
};

struct PhieuThanhToan
{
  int codeBill;
  int Sum;
};

struct BILL
{
  PhieuThanhToan PTT;
  BILL *next;
};

typedef struct BILL* bill;
typedef struct ORDER* order;
typedef struct MENU* menu;

menu themMonAn() //them mon an vao MENU
{
  ThucDon TD;
  cout<<"---Nhap thong tin mon an---\n";
  cout<<"Nhap ma mon an: \n";
  cin>>TD.codeName;
  cout<<"Nhap ten mon an: \n";
  cin.ignore();
  getline(cin, TD.Name);
  cout<<"Nhap gia tien cua mon an: \n";
  cin>>TD.Cost;

  menu tmp = new MENU();
  tmp->TD = TD;
  tmp->next = NULL;
  return tmp;
}

order goiMonAn() //goi mon an tu MENU
{
  GoiMon GM;
  cout<<"Nhap ma mon an can goi: \n";
  cin>>GM.codeName;
  cout<<"Nhap so phan can goi: \n";
  cin>>GM.soPhan;

  order tmp = new ORDER();
  tmp->GM = GM;
  tmp->next = NULL;
  return tmp;
}

bool empty(menu a) //Check rong
{
  return a == NULL;
}

void themMonAnVaoDanhSach(menu &a) //Them mon an vao list
{
  menu tmp = themMonAn();
  if(a == NULL)
  {
    a = tmp;
  }
  else
  {
    menu p = a;
    while(p->next != NULL)
    {
      p = p->next;
    }
    p->next = tmp;
  }
}

void goiMonTrongDanhSach(order &b) //Goi mon trong list cua Menu
{
  order tmp = goiMonAn();
  if(b == NULL)
    {
      b = tmp;
    }
  else
  {
    order p = b;
    while(p->next != NULL)
    {
      p = p->next;
    }
    p->next = tmp;
  }
}

void xoaMonAn(menu &a, int pos)
{
  if(pos <= 0)
  {
    cout<<"Khong hop le!!!\n";
    return;
  }
  menu before = NULL, after = a;
  for(int i = 1; i<pos; i++)
  {
    before = after;
    after = after->next;
  }

  if(before == NULL)
  {
    a = a->next;
  }
  else
  {
    before->next = after->next;
  }
}

void xoaMonAnDaOrder(order &b, int pos)
{
  order tmp = b;
  if(pos < 0)
  {
    cout<<"Khong hop le\n";
    return;
  }
  order before = NULL, after = b;
  for(int i = 1; i<pos; i++)
  {
    before = after;
    after = after->next;                                                                                                           
  }
  if(before == NULL)
  {
    b = b->next;
  }
  else
  {   
    before->next = after->next;
  }
} 


void inThongTinMonAn(ThucDon TD)
{
  cout<<"-------------------------------\n";
  cout<<"Ma mon an: "<<TD.codeName<<endl;
  cout<<"Ten mon an: "<<TD.Name<<endl;
  cout<<"Gia tien: "<<TD.Cost<<endl;
  cout<<"-------------------------------\n";
}

void inDanhSachMonAn(menu a)
{
  cout<<"-------------LIST--------------------\n";
  while(a != NULL)
  {
    inThongTinMonAn(a->TD);
    a = a->next;
  }
  cout<<"-----------ENDLIST--------------------\n";
}

void inThongTin1MonAnTrongOrder(GoiMon GM)
{
  cout<<"---------------------\n";
  cout<<"| Ma mon an: "<<GM.codeName<<"      |\n";
  cout<<"| So phan: " <<GM.soPhan<<"        |\n";
  cout<<"---------------------\n";
}

void inDanhSachOrder(order b)
{
  cout<<"--------------Ordered------------------\n";
  while(b != NULL)
  {
    inThongTin1MonAnTrongOrder(b->GM);
    b = b->next;
  }
  cout<<"--------------ENDLIST------------------\n";
}

void timKiemThongTin(menu a, int pos)
{
  menu tmp = a;
  while(tmp != NULL)
  {
    if(tmp->TD.codeName == pos)
      inThongTinMonAn(tmp->TD);
    tmp = tmp->next;
  }
}

void chinhSuaThongTinMonAn(menu &a, int pos)
{
  menu tmp = a;
  while(tmp != NULL)
  {
    if(tmp->TD.codeName == pos)
    {
      cout<<"Ban muon chinh sua gi: \n";
      cout<<"1. Chinh sua ten mon an\n";
      cout<<"2. Chinh sua gia mon an\n";
      int select;
      cin>>select;
      if(select == 1)
      {
      cout<<"Nhap ten mon an: \n";
      cin.ignore();getline(cin,tmp->TD.Name);
      }
      else
      {
      cout<<"Nhap gia tien cua mon an: \n";
      cin>>tmp->TD.Cost;
      }
    }
    tmp=tmp->next;
  }
}

void sapXepMonAn(menu &a)
{
  for(menu p = a; p->next != NULL; p = p->next)
  {
    menu min = p;
    for(menu q = p->next; q != NULL; q = q->next)
    {
      if(q->TD.Cost < min->TD.Cost)
      {  
        min = q;
    
      }
    }
    int tmp = min->TD.codeName;
    min->TD.codeName = p->TD.codeName;
    p->TD.codeName = tmp;

    string tmp1 = min->TD.Name;
    min->TD.Name = p->TD.Name;
    p->TD.Name = tmp1;

    int tmp2 = min->TD.Cost;
    min->TD.Cost = p->TD.Cost;
    p->TD.Cost = tmp2;
  }
}

void goiMonAn(menu a, order &b)
{
}

int main()
{
  menu Head = NULL;
  order Head1 = NULL;
  while(1)
  {
    cout<<"------------------QUAN LY QUAN CAFE-----------------------\n";
    cout<<"1. Quan ly thuc don\n";
    cout<<"2. Quan ly goi mon\n";
    cout<<"3. Quan ly thanh toan\n";
    cout<<"----------------------------------------------------------\n";
    int select;
    cout<<"Moi ban lua chon chuc nang: \n";
    cin>>select;
    if(select == 1)
    {
        cout<<"------------------------MENU----------------------------\n";
        cout<<"1. Xem thuc don\n";
        cout<<"2. Them mon an\n";
        cout<<"3. Xoa mon an\n";
        cout<<"4. Tim kiem theo ma mon an\n";
        cout<<"5. Chinh sua thong tin mon an\n";
        cout<<"6. Sap xep theo gia tien\n";
        cout<<"--------------------------------------------------------\n";
        cout<<"Moi ban lua chon chuc nang muon su dung: \n";
        int selectMenu;
        cin>>selectMenu;
        if(selectMenu == 1)
        {
          inDanhSachMonAn(Head);
        }
        if(selectMenu == 2)
        {
          themMonAnVaoDanhSach(Head);
        }
        if(selectMenu == 3)
        {
          int pos;
          cout<<"Nhap vi tri mon an can xoa: \n";
          cin>>pos;
          xoaMonAn(Head, pos);
        }
        if(selectMenu == 4)
        {
          int pos;
          cout<<"Nhap ma mon an can tim kiem: \n";
          cin>>pos;
          timKiemThongTin(Head,pos);
        }
        if(selectMenu == 5)
        {
          int pos;
          cout<<"Nhap ma mon can sua doi: \n";
          cin>>pos;
          chinhSuaThongTinMonAn(Head, pos);
        }
        if(selectMenu == 6)
        {
          sapXepMonAn(Head);
        }
    }
    else if(select == 2)
    {
        cout<<"----------------------------ORDER-----------------------\n";
        cout<<"1. Goi mon + so phan\n";
        cout<<"2. Xoa mon da goi\n";
        cout<<"3. Chinh sua so phan\n";
        cout<<"4. Tinh thanh tien\n";
        cout<<"--------------------------------------------------------\n";
        cout<<"Moi ban lua chon chuc nang muon su dung: \n";
        int selectOrder;                                                     
        cin>>selectOrder;
        if(selectOrder == 1)
        {
          goiMonTrongDanhSach(Head1);
          inDanhSachOrder(Head1);
        }
        if(selectOrder == 2)
        {
          cout<<"Vi tri mon an ma ban muon xoa: \n";
          int pos;
          cin>>pos;
          xoaMonAnDaOrder(Head1, pos);
          inDanhSachOrder(Head1);
        }
        if(selectOrder == 3)
        {
          return 0;
        }
        if(selectOrder == 4)
        {
          return 0;
        }
    }
    else
    {
        cout<<"--------------------------BILL--------------------------\n";
        cout<<"1. Xem danh sach cac phieu thanh toan\n";
        cout<<"2. Tim kiem theo ma phieu\n";
        cout<<"3. Sap xep bill theo tong tien\n";
        cout<<"--------------------------------------------------------\n";
        cout<<"Moi ban nhap chuc nang muon su dung: \n";
        int selectBill;
        cin>>selectBill;
        if(selectBill == 1)
        {
          return 0;
        }
        if(selectBill == 2)
        {
          return 0;
        }
        if(selectBill == 3)
        {
          return 0;
        }
    }
  }
  return 0;
}
