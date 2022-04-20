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

struct phieuThanhToan
{
  int codeBill;
  int Sum;
};

struct BILL
{
  phieuThanhToan PTT;
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

void inThanhTien1MonAn(GoiMon GM)
{
  cout<<"Mon ma so "<<GM.codeName<<": "<<GM.thanhTien<<endl;
}

void inThanhTienNhieuMonAn(order b)
{
  long long Sum = 0;
  cout<<"******************************\n";
  while(b != NULL)
  {
    inThanhTien1MonAn(b->GM);
    b=b->next;
  }
  cout<<"******************************\n";
}

void chinhSuaSoPhan(order &b, int pos)
{
  order tmp = b;
  while(tmp != NULL)
  {
    if(tmp->GM.codeName == pos)
    {
      cout<<"Xin moi ban chinh sua so phan an: \n";
      cin>>tmp->GM.soPhan;
    }
    tmp=tmp->next;
  }
}

void thanhTienOrder(menu a, order &b)
{
  order tmp1 = b;
  while(tmp1 != NULL)
  {
    menu tmp = a;
    while(tmp != NULL)
    {
    if(tmp->TD.codeName == tmp1->GM.codeName)
      tmp1->GM.thanhTien = tmp->TD.Cost * tmp1->GM.soPhan;
    tmp = tmp->next;
    }
    tmp1 = tmp1->next;
  }
}

bill themHoaDon()
{
  phieuThanhToan PTT;
  cout<<"Nhap ma phieu can luu: \n";
  cin>>PTT.codeBill;
  cout<<"Hoa don hien tai la: \n";
  cin>>PTT.Sum;

  bill tmp = new BILL();
  tmp->PTT = PTT;
  tmp->next = NULL;
  return tmp;
}

void taoBill(bill &c)
{
  bill tmp = themHoaDon();
  if(c == NULL)
    {
      c = tmp;
    }
  else
  {
    bill p = c;
    while(p->next != NULL)
    {
      p = p->next;
    }
    p->next = tmp;
  }
}

void inThongTin1Bill(phieuThanhToan PTT)
{
  cout<<"-----------------------------------\n";
  cout<<"Ma hoa don: "<<PTT.codeBill<<endl;
  cout<<"Tong tien cua hoa don: "<<PTT.Sum<<endl;
  cout<<"----------------------------------\n";
}

void inDanhSachBill(bill c)
{
  cout<<"-------------LIST-----------------\n";
  while(c != NULL)
  {
    inThongTin1Bill(c->PTT);
    c = c->next;
  }
  cout<<"-------------ENDLIST-----------------\n";
}

void thanhTienTrongBill(order b, bill &c)
{
  order tmp1 = b;
  bill tmp = c;
  while(tmp != NULL)
  {
    
    if(tmp->PTT.Sum == 0)
    {
      while(tmp1 != NULL)
      {
        tmp->PTT.Sum = tmp->PTT.Sum + tmp1->GM.thanhTien;
        tmp1 = tmp1->next;
      }
    }
    tmp = tmp->next;
  }
  cout<<"\nTinh toan thanh cong!!!\n";
}

void timKiemPhieuThanhToan(bill c, int pos)
{
  bill tmp = c;
  while(tmp != NULL)
  {
    if(tmp->PTT.codeBill == pos)
      inThongTin1Bill(tmp->PTT);
    tmp = tmp->next;
  }
}

void sapXepBill(bill &c)
{
  for(bill p = c; p->next != NULL; p = p->next)
  {
    bill min = p;
    for(bill q = p->next; q != NULL; q = q->next)
    {
      if(q->PTT.Sum < min->PTT.Sum)
      {  
        min = q;
    
      }
    }
    int tmp = min->PTT.codeBill;
    min->PTT.codeBill = p->PTT.codeBill;
    p->PTT.codeBill = tmp;

    int tmp1 = min->PTT.Sum;
    min->PTT.Sum = p->PTT.Sum;
    p->PTT.Sum = tmp1;
  }
}
int main()
{
  menu Head = NULL;
  order Head1 = NULL;
  bill Head2 = NULL;
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
          inDanhSachMonAn(Head);
          if(Head != NULL)
          {
          goiMonTrongDanhSach(Head1);
          inDanhSachOrder(Head1);
          }
          else
          {
            cout<<"Hien tai khong co mon nao trong thuc don"<<endl;
          }
        }
        if(selectOrder == 2)
        {
          if(Head != NULL && Head1 != NULL)
          {
            cout<<"Vi tri mon an ma ban muon xoa: \n";
            int pos;
            cin>>pos;
            xoaMonAnDaOrder(Head1, pos);
            inDanhSachOrder(Head1);
          }
          else
          {
            cout<<"Hien tai khong co mon nao trong thuc don va order de xoa!!"<<endl;
          }
        }
        if(selectOrder == 3)
        {
          if(Head != NULL && Head1 != NULL)
          {
            inDanhSachOrder(Head1);
            cout<<"Xin moi ban nhap ma mon can chinh sua: \n";
            int codeName;
            cin>>codeName;
            chinhSuaSoPhan(Head1, codeName);
            inDanhSachOrder(Head1);
            cout<<"Chinh sua thanh cong!!!\n";
          }
          else
          {
            cout<<"Khong co mon nao xuat hien trong order de chinh sua"<<endl;
          }
        }
        if(selectOrder == 4)
        {
          thanhTienOrder(Head, Head1);
          inThanhTienNhieuMonAn(Head1);
          taoBill(Head2);
          cout<<"Xin vui long cho trong giay lat....";
          thanhTienTrongBill(Head1, Head2);
          Head1 = NULL;
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
          inDanhSachBill(Head2);
        }
        if(selectBill == 2)
        {
          int codeBill;
          cout<<"Moi nhap ma phieu thanh toan: \n";
          cin>>codeBill;
          timKiemPhieuThanhToan(Head2, codeBill);
        }
        if(selectBill == 3)
        {
          sapXepBill(Head2);
          cout<<"Sap xep thanh cong\n";
        }
    }
  }
  return 0;
}
