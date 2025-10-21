#include <iomanip>
#include <iostream>
using namespace std;

class listSach;
class listDg;

//====================cai dac hang doi ====================
struct NodeHD {
    int data;
    NodeHD* next;
};

class queue {
   public:
    NodeHD* head;
    int size;
    queue();
    NodeHD* createNode(int x);
    void enqueue(int x);
    void dequeue();
    void inHD();
    int front();
    bool empty();
};
//---------------------khai trien hang doi-----------------
queue::queue() {
    head = NULL;
    size = 0;
}
// tao node moi
NodeHD* queue::createNode(int x) {
    NodeHD* tmp = new NodeHD();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}
// lay phan tu dau nhung khong xoa
int queue::front() {
    if (head != NULL) return head->data;
    return -1;
}
// kiem tra rong
bool queue::empty() { return head == NULL; }
// them cuoi
void queue::enqueue(int x) {
    NodeHD* p = createNode(x);
    if (head == NULL) {
        head = p;
    } else {
        NodeHD* a = head;
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = p;
    }
}

// xoa dau
void queue::dequeue() {
    if (head == NULL) {
        return;
    } else {
        NodeHD* p = head;
        head = head->next;
        delete p;
    }
}
//=======================DANH SACH MUON===================================
struct NodeMuon {  // cau truc muon tra sach
    string maSach;
    NodeMuon* next;
};
class muon {
   public:
    NodeMuon* head;
    muon();
    NodeMuon* createNode(string ma);
    void themSach(string ma);
    void xoaSach(string ma);
    bool isEmpty();
    void inDs();
};
//---------------trien khai muom------------------------------------------
muon::muon() { head = NULL; };
NodeMuon* muon::createNode(string ma) {
    NodeMuon* p = new NodeMuon();
    p->maSach = ma;
    p->next = NULL;
    return p;
}
void muon::themSach(string ma) {  // tự thêm vào cuối
    NodeMuon* p = createNode(ma);
    if (head == NULL) {
        head = p;
    } else {
        NodeMuon* a = head;
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = p;
    }
}
void muon::xoaSach(string ma) {
    if (head == NULL) {
        return;
    }
    if (head->maSach == ma) {  // sach can xoa o dau linked list
        NodeMuon* p = head;
        head = head->next;
        delete p;
        return;
    }
    NodeMuon* p = head;
    // duyệt đến node trước node cần xóa
    while (p->next != NULL && p->next->maSach != ma) {
        p = p->next;
    }
    // nếu ko tìm tháy mã sách
    if (p->next == NULL) {
        return;
    }
    NodeMuon* tmp = p->next;
    p->next = tmp->next;
    delete tmp;
}
bool muon::isEmpty() { return head == NULL; }
void muon ::inDs() {
    if (head == NULL)
        cout << "Danh sach rong";
    else {
        NodeMuon* p = head;
        while (p != NULL) {
            cout << "- " << p->maSach << endl;
            p = p->next;
        }
    }
}
//===================CAU TRUC SACH VA LIST SACH==================
struct sach {  // cau truc quan li sach
    string masach;
    string tenSach;
    string tacGia;
    int soluong;
    queue hangdoimuonsach;
};
struct NodeSach {
    sach data;
    NodeSach* next;
};
class list;
class listSach {
   public:
    NodeSach* head;
    NodeSach* tail;
    listSach();
    NodeSach* createNode(sach x);
    void inDs();
    void insertLast(sach x);
    void insertFirst(sach x);
    void insertMid(sach x, int vitri);
    int soPhantu();
    void xoasachbangma(string masach);
    void xoasachbangten(string ten);
    NodeSach* timSachTheoMa(string ma);
    NodeSach* timSachTheoTen(string ten);
    void muonSach(string ma, int id, list& dg);
    void traSach(string ma, int id, list& dg);
    bool tonTaiSach(string& ma);
    bool tonTaiSachTheoTen(string ten);
    void inDanhSachHangDoi(list& dg);
    void themSoLuongSach(int x, string ma);
};
//=======================CAU TRUC DOC GIA VA LIST DOC GIA=========================
struct docgia {  // cau truc quan li doc gia
    string ten;
    string gioitinh;
    int tuoi;
    int id;
    muon sachdamuon;  // luu lai sach ma doc gia muon
};
struct NodeDg {
    docgia data;
    NodeDg* next;
};
//------------------------khai trien class doc gia--------------------------
class list {
   private:
    NodeDg* head;
    NodeDg* tail;

   public:
    list();
    NodeDg* createNode(docgia x);
    void inDs();
    void insertLast(docgia x);
    void insertFirst(docgia x);
    void insertMid(docgia x, int vitri);
    int soPhantu();
    void xoaDocGiaTheoID(int id, listSach& ds);
    void xoaDocGiaTheoTen(string ten, listSach& ds);
    NodeDg* timDocGiaTheoID(int id);
    void xemSachDangMuon(int id);
    bool tonTaiDocGia(int id);
    void inTatCaSachDaMuon(listSach& dsSach);
};
list::list() {
    head = NULL;
    tail = NULL;
}
bool list::tonTaiDocGia(int id) {
    NodeDg* p = head;
    while (p != NULL) {
        if (p->data.id == id) return true;
        p = p->next;
    }
    return false;
}
NodeDg* list::createNode(docgia x) {
    NodeDg* p = new NodeDg();
    p->data = x;
    p->next = NULL;
    return p;
}
void list::insertLast(docgia x) {
    NodeDg* p = createNode(x);
    if (head == NULL) {
        head = tail = p;
        return;
    } else {
        tail->next = p;
        tail = p;
    }
}
int list::soPhantu() {
    NodeDg* p = head;
    int size = 0;
    while (p != NULL) {
        size++;
        p = p->next;
    }
    return size;
}
void list::inDs() {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    cout << "\n===============================================\n";
    cout << "| " << left << setw(6) << "ID";
    cout << "| " << left << setw(17) << "HO VA TEN";
    cout << "| " << left << setw(4) << "TUOI";
    cout << "| " << left << setw(10) << "GIOI TINH" << setw(3) << " |";
    cout << "\n-----------------------------------------------\n";
    for (NodeDg* p = head; p != NULL; p = p->next) {
        cout << "| " << left << setw(6) << p->data.id;
        cout << "| " << left << setw(17) << p->data.ten;
        cout << "| " << left << setw(4) << p->data.tuoi;
        cout << "| " << left << setw(10) << p->data.gioitinh << setw(3) << " |";
        cout << endl;
    }
    cout << "===============================================\n";
}
NodeDg* list::timDocGiaTheoID(int id) {
    NodeDg* p = head;
    while (p != NULL) {
        if (p->data.id == id) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
void list::insertFirst(docgia x) {
    NodeDg* p = createNode(x);
    if (head == NULL) {
        head = tail = p;
    } else {
        p->next = head;
        head = p;
    }
}
void list::insertMid(docgia x, int vitri) {
    if (vitri == 1) {
        insertFirst(x);
        return;
    } else if (vitri == soPhantu() + 1) {
        insertLast(x);
        return;
    }
    if (vitri <= 0 || vitri > soPhantu() + 1) {
        cout << "Vi tri khong hop le.";
        return;
    }
    NodeDg* p = createNode(x);
    NodeDg* tmp = head;
    for (int i = 1; i < vitri - 1; i++) {
        tmp = tmp->next;
    }
    p->next = tmp->next;
    tmp->next = p;
}
// xem sach doc gia dang muon
void list::xemSachDangMuon(int id) {
    NodeDg* p = timDocGiaTheoID(id);
    if (p == NULL) {
        cout << "Khong tim thay doc gia co ID " << id << endl;
        return;
    }
    cout << "Doc gia ten : " << p->data.ten << " (ID " << p->data.id << " )" << "dang muon :\n";
    if (p->data.sachdamuon.isEmpty()) {
        cout << "khong co sach ";
    } else {
        p->data.sachdamuon.inDs();
    }
}
void list::inTatCaSachDaMuon(listSach& dsSach) {
    if (head == NULL) {
        cout << "Danh sach doc gia rong.\n";
        return;
    }
    NodeDg* p = head;
    cout << "\n========== Danh sach da muon  ==========\n";
    while (p != NULL) {
        cout << "Độc giả: " << p->data.ten << " (ID: " << p->data.id << ")\n";
        if (p->data.sachdamuon.isEmpty()) {
            cout << "   - Không có sách nào đang mượn.\n";
        } else {
            NodeMuon* muon = p->data.sachdamuon.head;
            while (muon != NULL) {
                NodeSach* sachDocGiaDaMuon = dsSach.timSachTheoMa(muon->maSach);
                if (sachDocGiaDaMuon != NULL) {
                    cout << " -Ma : " << muon->maSach << endl;
                    cout << " -Ten sach : " << sachDocGiaDaMuon->data.tenSach;
                }
                muon = muon->next;
            }
        }
        p = p->next;
    }
}
// xoa doc gia theo id và tra lai sach
void list::xoaDocGiaTheoID(int id, listSach& ds) {
    if (head == NULL) {
        cout << "Danh sach rong, khong the xoa.\n";
        return;
    }
    NodeDg* truoc = NULL;
    NodeDg* sau = head;
    // tìm độc giả cần xóa
    while (sau != NULL && sau->data.id != id) {
        truoc = sau;
        sau = sau->next;
    }
    if (sau == NULL) {
        cout << "Khong tim thay doc gia co ID " << id << ".\n";
        return;
    }
    // Duyệt toàn bộ danh sách sách đã mượn, trả từng quyển
    NodeMuon* p = sau->data.sachdamuon.head;
    while (p != NULL) {
        NodeMuon* next = p->next;  // lưu lại node kế tiếp trước khi gọi traSach
        ds.traSach(p->maSach, id, *this);
        p = next;
    }
    // Xóa node độc giả khỏi danh sách
    if (truoc == NULL)
        head = head->next;
    else
        truoc->next = sau->next;
    delete sau;
    cout << "Da xoa doc gia co ID " << id << " va tra lai toan bo sach.\n";
}
void list::xoaDocGiaTheoTen(string ten, listSach& ds) {
    if (head == NULL) {
        cout << "Danh sach rong, khong the xoa.\n";
        return;
    }
    NodeDg* truoc = NULL;
    NodeDg* sau = head;
    // tìm độc giả cần xóa
    while (sau != NULL && sau->data.ten != ten) {
        truoc = sau;
        sau = sau->next;
    }
    if (sau == NULL) {
        cout << "Khong tim thay doc gia co ten: " << ten << ".\n";
        return;
    }
    int id = sau->data.id;
    // Duyệt toàn bộ danh sách sách đã mượn, trả từng quyển
    NodeMuon* p = sau->data.sachdamuon.head;
    while (p != NULL) {
        NodeMuon* next = p->next;  // lưu lại node kế tiếp trước khi gọi traSach
        ds.traSach(p->maSach, id, *this);
        p = next;
    }
    // Xóa node độc giả khỏi danh sách
    if (truoc == NULL)
        head = head->next;
    else
        truoc->next = sau->next;
    delete sau;
    cout << "Da xoa doc gia co ten " << ten << " va tra lai toan bo sach.\n";
}
//-----------------------khai trien class Sach-----------------------
listSach::listSach() {
    head = NULL;
    tail = NULL;
}
NodeSach* listSach::createNode(sach x) {
    NodeSach* p = new NodeSach();
    p->data = x;
    p->next = NULL;
    return p;
}
void listSach::insertLast(sach x) {
    NodeSach* p = createNode(x);
    if (head == NULL) {
        head = tail = p;
        return;
    } else {
        tail->next = p;
        tail = p;
    }
}
int listSach::soPhantu() {
    NodeSach* p = head;
    int size = 0;
    while (p != NULL) {
        size++;
        p = p->next;
    }
    return size;
}
void listSach::inDs() {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    cout << "\n=========================================================================\n";
    cout << "| " << left << setw(10) << "Ma Sach";
    cout << "| " << left << setw(25) << "TEN SACH";
    cout << "| " << left << setw(20) << "TAC GIA";
    cout << "| " << left << setw(7) << "SO LUONG" << setw(3) << " |";
    cout << "\n-------------------------------------------------------------------------\n";
    for (NodeSach* p = head; p != NULL; p = p->next) {
        cout << "| " << left << setw(10) << p->data.masach;
        cout << "| " << left << setw(25) << p->data.tenSach;
        cout << "| " << left << setw(20) << p->data.tacGia;
        cout << "| " << left << setw(7) << p->data.soluong << setw(3) << "  |";
        cout << endl;
    }
    cout << "=========================================================================\n";
}
void listSach::insertFirst(sach x) {
    NodeSach* p = createNode(x);
    if (head == NULL) {
        head = tail = p;
    } else {
        p->next = head;
        head = p;
    }
}
void listSach::insertMid(sach x, int vitri) {
    if (vitri == 1) {
        insertFirst(x);
        return;
    } else if (vitri == soPhantu() + 1) {
        insertLast(x);
        return;
    }
    if (vitri <= 0 || vitri > soPhantu() + 1) {
        cout << "Vi tri khong hop le.";
        return;
    }
    NodeSach* p = createNode(x);
    NodeSach* tmp = head;
    for (int i = 1; i < vitri - 1; i++) {
        tmp = tmp->next;
    }
    p->next = tmp->next;
    tmp->next = p;
}
void listSach::xoasachbangma(string masach) {
    if (head == NULL) {
        cout << "Danh sach rong, khong the xoa.\n";
        return;
    } else if (head->data.masach == masach) {
        NodeSach* c = head;
        head = head->next;
        delete c;
        cout << "Da xoa sach co ma " << masach << ".\n";
        return;
    }
    NodeSach* p = head;
    while (p->next != NULL && p->next->data.masach != masach) {
        p = p->next;
    }
    if (p->next == NULL) {
        cout << "Khong tim thay sach co ma " << masach << ".\n";
        return;
    }
    NodeSach* c = p->next;
    p->next = c->next;
    delete c;
    cout << "Da xoa ma sach " << masach << ".\n";
}
void listSach::xoasachbangten(string tenSach) {
    if (head == NULL) {
        cout << "Danh sach rong, khong the xoa.\n";
        return;
    } else if (head->data.tenSach == tenSach) {
        NodeSach* c = head;
        head = head->next;
        delete c;
        cout << "Da xoa sach co ten " << tenSach << ".\n";
        return;
    }
    NodeSach* p = head;
    while (p->next != NULL && p->next->data.tenSach != tenSach) {
        p = p->next;
    }
    if (p->next == NULL) {
        cout << "Khong tim thay sach co ten " << tenSach << ".\n";
        return;
    }
    NodeSach* c = p->next;
    p->next = c->next;
    delete c;
    cout << "Da xoa ma sach " << tenSach << ".\n";
}
NodeSach* listSach::timSachTheoMa(string ma) {
    NodeSach* p = head;
    while (p != NULL) {
        if (p->data.masach == ma) return p;
        p = p->next;
    }
    return NULL;
}
NodeSach* listSach::timSachTheoTen(string ten) {
    NodeSach* p = head;
    while (p != NULL) {
        if (p->data.tenSach == ten) return p;
        p = p->next;
    }
    return NULL;
}
bool listSach::tonTaiSach(string& ma) {  // ton tai sach theo ma
    NodeSach* p = head;
    while (p != NULL) {
        if (p->data.masach == ma) return true;
        p = p->next;
    }
    return false;
}
bool listSach::tonTaiSachTheoTen(string ten) {
    NodeSach* p = head;
    while (p != NULL) {
        if (p->data.tenSach == ten) return true;
        p = p->next;
    }
    return false;
}
// muon sach
void listSach::muonSach(string ma, int id, list& dg) {
    NodeSach* p = timSachTheoMa(ma);
    if (p == NULL) {
        cout << "Khong tim thay sach";
        return;
    }
    if (p->data.soluong > 0) {
        p->data.soluong--;
        NodeDg* a = dg.timDocGiaTheoID(id);
        if (a) {
            a->data.sachdamuon.themSach(ma);
            cout << "Doc gia (ID: " << id << ")" << " ten " << a->data.ten << " da muon sach "
                 << p->data.masach << ":" << p->data.tenSach << "." << endl;
        }
    } else {
        p->data.hangdoimuonsach.enqueue(id);
        // them id nguoi muon sach vao hang doi neu het sach
        cout << "Da het sach . Doc gia " << id << " duoc dua vao hang doi.\n";
    }
}
void listSach::traSach(string ma, int id, list& dg) {
    NodeSach* p = timSachTheoMa(ma);
    if (p == NULL) {
        cout << "Khong tim thay sach .";
        return;
    }
    // xoa sach khoi danh sach muon
    NodeDg* a = dg.timDocGiaTheoID(id);
    if (a) {  // neu ton tai doc gia
        if (a->data.sachdamuon.isEmpty()) {
            cout << "Danh sach rong";
            return;
        } else {
            a->data.sachdamuon.xoaSach(ma);
            cout << "Tra sach thanh cong.";
        }
    }
    if (!p->data.hangdoimuonsach.empty()) {  // kiem tra neu co doc gia trong hang doi
        int idTiepTheo = p->data.hangdoimuonsach.front();
        p->data.hangdoimuonsach.dequeue();  // xoa khoi hang doi
        NodeDg* dg2 = dg.timDocGiaTheoID(idTiepTheo);
        if (dg2) {
            dg2->data.sachdamuon.themSach(ma);  // them sach da muon vao doc gia co IdTieptheo
            cout << "Doc gia " << idTiepTheo << " da duoc muon sach (" << p->data.tenSach << ").\n";
        }
    } else {
        // neu hang doi trong
        p->data.soluong++;  // tra lai so luon sach khi tra
    }
}
void listSach::themSoLuongSach(int x, string ma) {
    if (head == NULL) {
        cout << "Danh sach rong\n";
        return;
    }
    NodeSach* p = head;
    while (p != NULL && p->data.masach != ma) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Khong tim thay sach co ma: " << ma << endl;
    } else {
        p->data.soluong = p->data.soluong + x;
        cout << "Da them " << x << " sach " << p->data.tenSach;
    }
}
//=======================nhap thong tin doc gia=================
void nhapDocGia(docgia& a) {
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
void nhapSach(sach& a) {
    cout << "Nhap ma sach :";
    getline(cin, a.masach);
    cout << "Nhap ten sach :";
    getline(cin, a.tenSach);
    cout << "Nhap tac gia :";
    getline(cin, a.tacGia);
    cout << "Nhap so luong :";
    cin >> a.soluong;
}

// in danh sach trong hang doi
void listSach::inDanhSachHangDoi(list& dsDocGia) {
    bool coDuLieu = false;
    cout << "\n===== DANH SÁCH HÀNG ĐỢI CỦA CÁC SÁCH =====\n";
    cout << left << setw(25) << "Ten Doc Gia" << " | " << "Sach Dang Doi Muon\n";
    cout << "----------------------------------------------------------\n";

    NodeSach* pSach = head;
    while (pSach != NULL) {
        NodeHD* pQueue = pSach->data.hangdoimuonsach.head;
        while (pQueue != NULL) {
            int idDocGia = pQueue->data;
            NodeDg* doc = dsDocGia.timDocGiaTheoID(idDocGia);

            if (doc != NULL) {
                cout << left << setw(25) << doc->data.ten << " | " << pSach->data.tenSach << endl;
                coDuLieu = true;
            }
            pQueue = pQueue->next;
        }
        pSach = pSach->next;
    }
    if (!coDuLieu) {
        cout << "Khong co doc gia nao trong hang doi!\n";
    }
}

int main() {
    list Dsdocgia;
    listSach DSsach;
    while (true) {
        cout << "\n\n========================MENU=========================\n";
        cout << "|                                                   |\n";
        cout << "|          0. THOAT CHUONG TRINH                    |\n";
        cout << "|                                                   |\n";
        cout << "|          1. THEM DU LIEU. ( Doc gia / Sach )      |\n";
        cout << "|                                                   |\n";
        cout << "|          2. XOA SACH ( Ma / Ten )                 |\n";
        cout << "|                                                   |\n";
        cout << "|          3. XOA DOC GIA ( ID / Ten)               |\n";
        cout << "|                                                   |\n";
        cout << "|          4. TIM SACH ( Ma / Ten )                 |\n";
        cout << "|                                                   |\n";
        cout << "|          5. THEM SO LUONG SACH                    |\n";
        cout << "|                                                   |\n";
        cout << "|          6. MUON / TRA SACH                       |\n";
        cout << "|                                                   |\n";
        cout << "|          7. HIEN THI DU LIEU                      |\n";
        cout << "|                                                   |\n";
        cout << "=====================================================\n";
        cout << "[[?]] Moi nhap lua chon :";
        int lc;
        cin >> lc;

        if (lc == 0) {
            cout << "Da thoat chuong trinh \n";
            break;
        }

        if (lc == 1) {  // them thong tin
            cout << " 1.Them Doc Gia.\n";
            cout << " 2.Them Sach.\n";
            cout << "[?] Moi nhap lua chon :";
            int lc1;
            cin >> lc1;
            if (lc1 == 1) {  // them docgia
                cout << "---------------------------------------------\n";
                cout << " 1.Them vao dau danh sach\n";
                cout << " 2.Them vao cuoi danh sach\n";
                cout << " 3.Them vao giua danh sach\n";
                cout << "[?] Moi nhap lua chon :";
                int lcthem;
                cin >> lcthem;
                docgia dg;
                nhapDocGia(dg);
                if (lcthem == 1) {
                    Dsdocgia.insertFirst(dg);
                } else if (lcthem == 2) {
                    Dsdocgia.insertLast(dg);
                } else if (lcthem == 3) {
                    int vitri;
                    cout << "Nhap vi tri can chen :";
                    cin >> vitri;
                    Dsdocgia.insertMid(dg, vitri);
                }
                cout << "Them doc gia thanh cong.";
                cout << "\n---------------------------------------------\n";
            } else if (lc1 == 2) {  // them sach
                cout << "---------------------------------------------\n";
                cout << " 1.Them vao dau danh sach\n";
                cout << " 2.Them vao cuoi danh sach\n";
                cout << " 3.Them vao giua danh sach\n";
                cout << "[?] Moi nhap lua chon :";
                int lcThem;
                cin >> lcThem;
                sach a;
                cin.ignore();
                nhapSach(a);
                if (lcThem == 1) {
                    DSsach.insertFirst(a);
                } else if (lcThem == 2) {
                    DSsach.insertLast(a);
                } else if (lcThem == 3) {
                    int vitri;
                    cout << "Nhap vi tri can chen :";
                    cin >> vitri;
                    DSsach.insertMid(a, vitri);
                }
                cout << "Them sach thanh cong.";
                cout << "\n---------------------------------------------\n";
            }
        }

        if (lc == 2) {  // xoa sach
            int lcXoa;
            cout << " 1. Xoa theo ma.\n";
            cout << " 2. Xoa theo ten.\n";
            cout << "[?] Moi nhap lua chon :";
            cin >> lcXoa;
            if (lcXoa == 1) {  // xoa sach theo ma
                string ma;
                cout << "Nhap ma sach can xoa: ";
                cin.ignore();
                getline(cin, ma);
                if (!DSsach.tonTaiSach(ma)) {
                    cout << "Khong ton tai sach co ma \"" << ma << "\"\n";
                } else {
                    DSsach.xoasachbangma(ma);
                }
                cout << "\n---------------------------------------------\n";
            } else if (lcXoa == 2) {  // xoa sach theo ten
                string ten;
                cout << "Nhap ten sach can xoa: ";
                cin.ignore();
                getline(cin, ten);
                if (!DSsach.tonTaiSachTheoTen(ten)) {
                    cout << "Khong ton tai sach co ten \"" << ten << "\"\n";
                } else {
                    DSsach.xoasachbangten(ten);
                }
                cout << "\n---------------------------------------------\n";
            }
        }

        if (lc == 3) {  // xoa doc gia
            int lcXoaDG;
            cout << " 1. Xoa theo ID.\n";
            cout << " 2. Xoa theo Ten.\n";
            cout << "[?] Moi nhap lua chon :";
            cin >> lcXoaDG;
            if (lcXoaDG == 1) {  // xoa theo id
                int id;
                cout << "Nhap ID doc gia can xoa: ";
                cin >> id;
                Dsdocgia.xoaDocGiaTheoID(id, DSsach);
                cout << "\n---------------------------------------------\n";
            } else if (lcXoaDG == 2) {  // xoa theo ten
                string tendg;
                cout << "Nhap Ten doc gia can xoa :";
                cin.ignore();
                getline(cin, tendg);
                Dsdocgia.xoaDocGiaTheoTen(tendg, DSsach);
                cout << "\n---------------------------------------------\n";
            }
        }

        if (lc == 4) {  // tim sach
            int lcTim;
            cout << " 1.Tim theo Ma.\n";
            cout << " 2.Tim theo Ten.\n";
            cout << "[?] Nhap lua chon : ";
            cin >> lcTim;
            if (lcTim == 1) {  // tim theo ma
                string ma;
                cout << "Nhap ma sach can tim: ";
                cin.ignore();
                getline(cin, ma);
                NodeSach* p = DSsach.timSachTheoMa(ma);
                if (p != NULL) {
                    cout << "Tim thay sach: " << p->data.masach << " | Tac gia: " << p->data.tacGia
                         << " | SL: " << p->data.soluong << endl;
                } else {
                    cout << "Khong tim thay sach.";
                }
                cout << "\n---------------------------------------------\n";
            } else if (lcTim == 2) {  // tim theo ten
                string tenSach;
                cout << "Nhap ten sach can tim: ";
                cin.ignore();
                getline(cin, tenSach);
                NodeSach* p = DSsach.timSachTheoTen(tenSach);
                if (p != NULL) {
                    cout << "Tim thay sach: " << p->data.tenSach << " | Tac gia: " << p->data.tacGia
                         << " | SL: " << p->data.soluong << endl;
                } else {
                    cout << "Khong tim thay sach.";
                }
                cout << "\n---------------------------------------------\n";
            }
        }
        if (lc == 5) {
            int sL;
            string ma;
            cout << "Nhap ma sach muon them :";
            cin.ignore();
            getline(cin, ma);
            cout << "Nhap so luong :";
            cin >> sL;
            DSsach.themSoLuongSach(sL, ma);
        }
        if (lc == 6) {  // tra/muon sach
            int lc2;
            cout << " 1.Muon sach.\n";
            cout << " 2.Tra sach.\n";
            cout << "[?] Nhap lua chon : ";
            cin >> lc2;
            if (lc2 == 1) {  // muon sach
                string ma;
                int id;
                cout << "Nhap ma sach: ";
                cin.ignore();
                getline(cin, ma);
                if (!DSsach.tonTaiSach(ma)) {
                    cout << "Khong ton tai sach co ma \"" << ma << "\"\n";
                    continue;
                }
                cout << "Nhap id doc gia: ";
                cin >> id;
                if (!Dsdocgia.tonTaiDocGia(id)) {
                    cout << "Khong ton tai doc gia co ID " << id << endl;
                } else {
                    DSsach.muonSach(ma, id, Dsdocgia);
                }
                cout << "\n---------------------------------------------\n";
            } else if (lc2 == 2) {  // tra sach
                string ma;
                int id;
                cout << "Nhap ma sach: ";
                cin.ignore();
                getline(cin, ma);
                cout << "Nhap id doc gia: ";
                cin >> id;
                if (!Dsdocgia.tonTaiDocGia(id)) {
                    cout << "Khong ton tai doc gia co ID " << id << endl;
                } else if (!DSsach.tonTaiSach(ma)) {
                    cout << "Khong ton tai sach co ma \"" << ma << "\"\n";
                } else {
                    DSsach.traSach(ma, id, Dsdocgia);
                }
                cout << "\n---------------------------------------------\n";
            }
        }
        if (lc == 7) {  // hien thi du lieu
            int lc4;
            cout << " 1. Hien thi danh sach doc gia.\n";
            cout << " 2. Hien thi danh sach sach.\n";
            cout << " 3. Hien thi tat ca sach da muon.\n";
            cout << " 4. Hien thi danh sach doc gia trong hang doi.\n";
            cout << "[?] Moi nhap lua chon :";
            cin >> lc4;
            if (lc4 == 1) {
                Dsdocgia.inDs();
            } else if (lc4 == 2) {
                DSsach.inDs();
            } else if (lc4 == 3) {
                Dsdocgia.inTatCaSachDaMuon(DSsach);
            } else if (lc4 == 4) {
                queue HangDoiSach;
                DSsach.inDanhSachHangDoi(Dsdocgia);
            }
            cout << "\n---------------------------------------------\n";
        }
    }
}
