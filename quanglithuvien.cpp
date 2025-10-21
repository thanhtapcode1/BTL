#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

//====================cai dac hang doi ====================
struct NodeHD
{
    int data;
    NodeHD *next;
};

class queue
{
public:
    NodeHD *head;
    int size;
    queue();
    NodeHD *createNode(int x);
    void enqueue(int x);
    void dequeue();
    void inHD();
};
queue::queue()
{
    head = NULL;
    size = 0;
}
// tao node moi
NodeHD *queue::createNode(int x)
{
    NodeHD *tmp = new NodeHD();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// them cuoi
void queue::enqueue(int x)
{
    NodeHD *p = createNode(x);
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        NodeHD *a = head;
        while (a->next != NULL)
        {
            a = a->next;
        }
        a->next = p;
    }
}

// xoa dau
void queue::dequeue()
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        NodeHD *p = head;
        head = head->next;
        delete p;
    }
}
// in
void queue::inQueue()
{
    NodeHD *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
//==========================cau truc========================
struct docgia
{
    string ten;
    string gioitinh;
    int tuoi;
    int id;
    vector<string> sachdamuon; // luu lai sach ma doc gia muon
};

struct sach
{
    string masach;
    string tenSach;
    string tacGia;
    int soluong;
};
//=======================Quan li danh sach doc gia=================
struct Node
{
    docgia data;
    Node *next;
};

class list
{
private:
    Node *head;
    Node *tail;

public:
    list();
    Node *createNode(docgia x);
    void inDs();
    void insertLast(docgia x);
    void insertFirst(docgia x);
    void insertMid(docgia x, int vitri);
    int soPhantu();
    void xoaDocGiaTheoID(int id);
};
list::list()
{
    head = NULL;
    tail = NULL;
}
Node *list::createNode(docgia x)
{
    Node *p = new Node();
    p->data = x;
    p->next = NULL;
    return p;
}
void list::insertLast(docgia x)
{
    Node *p = createNode(x);
    if (head == NULL)
    {
        head = tail = p;
        return;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}
int list::soPhantu()
{
    Node *p = head;
    int size = 0;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}
void list::inDs()
{
    if (head == NULL)
    {
        printf("Danh sach rong!\n");
        return;
    }
    cout << "| " << left << setw(6) << "ID";
    cout << "| " << left << setw(17) << "HO VA TEN";
    cout << "| " << left << setw(4) << "TUOI";
    cout << "| " << left << setw(10) << "GIOI TINH" << setw(3) << " |";
    cout << "\n-----------------------------------------------\n";
    for (Node *p = head; p != NULL; p = p->next)
    {
        cout << "| " << left << setw(6) << p->data.id;
        cout << "| " << left << setw(17) << p->data.ten;
        cout << "| " << left << setw(4) << p->data.tuoi;
        cout << "| " << left << setw(10) << p->data.gioitinh << setw(3) << " |";
        cout << endl;
    }
}
void list::insertFirst(docgia x)
{
    Node *p = createNode(x);
    if (head == NULL)
    {
        head = tail = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}
void list::insertMid(docgia x, int vitri)
{
    if (vitri == 1)
    {
        insertFirst(x);
        return;
    }
    else if (vitri == soPhantu() + 1)
    {
        insertLast(x);
        return;
    }
    if (vitri <= 0 || vitri > soPhantu() + 1)
    {
        cout << "Vi tri khong hop le.";
        return;
    }
    Node *p = createNode(x);
    Node *tmp = head;
    for (int i = 1; i < vitri - 1; i++)
    {
        tmp = tmp->next;
    }
    p->next = tmp->next;
    tmp->next = p;
}
void list::xoaDocGiaTheoID(int id)
{
    if (head == NULL)
    {
        cout << "Danh sach rong, khong the xoa.\n";
        return;
    }
    else if (head->data.id == id)
    {
        Node *c = head;
        head = head->next;
        delete c;
        cout << "Da xoa doc gia co ID " << id << ".\n";
        return;
    }
    Node *p = head;
    while (p->next != NULL && p->next->data.id != id)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {

        cout << "Khong tim thay doc gia co ID " << id << ".\n";
        return;
    }
    Node *c = p->next;
    p->next = c->next;
    delete c;
    cout << "Da xoa doc gia co ID " << id << ".\n";
}

//========================Quan li  sach============================
struct NodeSach
{
    sach data;
    NodeSach *next;
};

class listSach
{
private:
    NodeSach *head;
    NodeSach *tail;

public:
    listSach();
    NodeSach *createNode(sach x);
    void inDs();
    void insertLast(sach x);
    void insertFirst(sach x);
    void insertMid(sach x, int vitri);
    int soPhantu();
    void xoasachbangma(string masach);
    void xoasachbangten(string ten);
};
listSach::listSach()
{
    head = NULL;
    tail = NULL;
}
NodeSach *listSach::createNode(sach x)
{
    NodeSach *p = new NodeSach();
    p->data = x;
    p->next = NULL;
    return p;
}
void listSach::insertLast(sach x)
{
    NodeSach *p = createNode(x);
    if (head == NULL)
    {
        head = tail = p;
        return;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}
int listSach::soPhantu()
{
    NodeSach *p = head;
    int size = 0;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}
void listSach::inDs()
{
    if (head == NULL)
    {
        printf("Danh sach rong!\n");
        return;
    }
    cout << "| " << left << setw(10) << "Ma Sach";
    cout << "| " << left << setw(25) << "TEN SACH";
    cout << "| " << left << setw(20) << "TAC GIA";
    cout << "| " << left << setw(7) << "SO LUONG" << setw(3) << " |";
    cout << "\n-------------------------------------------------------------------------\n";
    for (NodeSach *p = head; p != NULL; p = p->next)
    {
        cout << "| " << left << setw(10) << p->data.masach;
        cout << "| " << left << setw(25) << p->data.tenSach;
        cout << "| " << left << setw(20) << p->data.tacGia;
        cout << "| " << left << setw(7) << p->data.soluong << setw(3) << "  |";
        cout << endl;
    }
}
void listSach::insertFirst(sach x)
{
    NodeSach *p = createNode(x);
    if (head == NULL)
    {
        head = tail = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}
void listSach::insertMid(sach x, int vitri)
{
    if (vitri == 1)
    {
        insertFirst(x);
        return;
    }
    else if (vitri == soPhantu() + 1)
    {
        insertLast(x);
        return;
    }
    if (vitri <= 0 || vitri > soPhantu() + 1)
    {
        cout << "Vi tri khong hop le.";
        return;
    }
    NodeSach *p = createNode(x);
    NodeSach *tmp = head;
    for (int i = 1; i < vitri - 1; i++)
    {
        tmp = tmp->next;
    }
    p->next = tmp->next;
    tmp->next = p;
}
void listSach::xoasachbangma(string masach)
{
    if (head == NULL)
    {
        cout << "Danh sach rong, khong the xoa.\n";
        return;
    }
    else if (head->data.masach == masach)
    {
        NodeSach *c = head;
        head = head->next;
        delete c;
        cout << "Da xoa sach co ma " << masach << ".\n";
        return;
    }
    NodeSach *p = head;
    while (p->next != NULL && p->next->data.masach != masach)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {

        cout << "Khong tim thay sach co ma " << masach << ".\n";
        return;
    }
    NodeSach *c = p->next;
    p->next = c->next;
    delete c;
    cout << "Da xoa doc gia ma sach " << masach << ".\n";
}
void listSach::xoasachbangten(string tenSach)
{
    if (head == NULL)
    {
        cout << "Danh sach rong, khong the xoa.\n";
        return;
    }
    else if (head->data.tenSach == tenSach)
    {
        NodeSach *c = head;
        head = head->next;
        delete c;
        cout << "Da xoa sach co ten " << tenSach << ".\n";
        return;
    }
    NodeSach *p = head;
    while (p->next != NULL && p->next->data.tenSach != tenSach)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {

        cout << "Khong tim thay sach co ten " << tenSach << ".\n";
        return;
    }
    NodeSach *c = p->next;
    p->next = c->next;
    delete c;
    cout << "Da xoa doc gia ma ten " << tenSach << ".\n";
}

//=======================nhap thong tin doc gia=================
void nhapDocGia(docgia &a)
{
    cout << "Nhap ID:";
    cin >> a.id;
    cout << "Nhap ten doc gia :";
    cin.ignore();
    getline(cin, a.ten);
    cout << "Nhap tuoi:";
    cin >> a.tuoi;
    cout << "Nhap gioi tinh :";
    cin.ignore();
    getline(cin, a.gioitinh);
}

// ================nhap thong tin Sach================
void nhapSach(sach &a)
{
    cout << "Nhap ma sach :";
    cin.ignore();
    getline(cin, a.masach);
    cout << "Nhap ten sach :";
    getline(cin, a.tenSach);
    cout << "Nhap tac gia :";
    getline(cin, a.tacGia);
    cout << "Nhap so luong :";
    cin >> a.soluong;
}
int main()
{
    list Dsdocgia;
    listSach DSsach;
    while (true)
    {
        cout << "\n\n===================MENU====================\n";
        cout << "|     0. Thoat khoi chuong trinh          |\n";
        cout << "|     1. Them doc gia                     |\n";
        cout << "|     2. Them sach                        |\n";
        cout << "|     3. Xoa sach theo ma                 |\n";
        cout << "|     4. Xoa doc gia theo id              |\n";
        cout << "|     5. Xoa sach theo ten                |\n";
        cout << "|     6. In danh sach doc gia             |\n";
        cout << "|     7. In danh sach Sach                |\n";
        cout << "===========================================\n\n";
        cout << "-moi nhap lua chon :";
        int lc;
        cin >> lc;
        if (lc == 0)
        {
            cout << "Da thoat chuong trinh \n";
            break;
        }
        if (lc == 1)
        {
            cout << "1. them vao dau danh sach\n";
            cout << "2. them vao cuoi danh sach\n";
            cout << "3. them vao giua danh sach\n";
            cout << "-moi nhap lua chon :";
            int lc1;
            cin >> lc1;
            docgia dg;
            nhapDocGia(dg);
            if (lc1 == 1)
            {
                Dsdocgia.insertFirst(dg);
            }
            else if (lc1 == 2)
            {
                Dsdocgia.insertLast(dg);
            }
            else if (lc1 == 3)
            {
                int vitri;
                cout << "Nhap vi tri can chen :";
                cin >> vitri;
                Dsdocgia.insertMid(dg, vitri);
            }
        }
        if (lc == 2)
        {
            cout << "1. them vao dau danh sach\n";
            cout << "2. them vao cuoi danh sach\n";
            cout << "3. them vao giua danh sach\n";
            cout << "-moi nhap lua chon :";
            int lc1;
            cin >> lc1;
            sach a;
            nhapSach(a);
            if (lc1 == 1)
            {
                DSsach.insertFirst(a);
            }
            else if (lc1 == 2)
            {
                DSsach.insertLast(a);
            }
            else if (lc1 == 3)
            {
                int vitri;
                cout << "Nhap vi tri can chen :";
                cin >> vitri;
                DSsach.insertMid(a, vitri);
            }
        }
        if (lc == 6)
        {
            Dsdocgia.inDs();
        }
        if (lc == 7)
        {
            DSsach.inDs();
        }
        if (lc == 4)
        {
            int id;
            cout << "Nhap ID doc gia can xoa: ";
            cin >> id;
            Dsdocgia.xoaDocGiaTheoID(id);
        }
        if (lc == 3)
        {
            string ma;
            cout << "Nhap ma sach can xoa: ";
            cin.ignore();
            getline(cin, ma);
            DSsach.xoasachbangma(ma);
        }
        if (lc == 5)
        {
            string ten;
            cout << "Nhap ten sach can xoa: ";
            cin.ignore();
            getline(cin, ten);
            DSsach.xoasachbangten(ten);
        }
    }
}
