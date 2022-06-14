#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
class Tree {
  struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
      data = x;
      left = right = NULL;
    }
    Node(int x, Node *ll, Node *rr) {
      data = x;
      left = ll;
      right = rr;
    }
  };
  Node *root;

public:
  void taoCayBST() {
        Node *a = new Node(10, new Node(😎, new Node(12));
        Node *b = new Node(20, new Node(16), new Node(25));
        root = new Node(15, a, b);
  }

  Node *qL(Node *&T) {
    Node *x = T;
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    T = y;
    return T;
  }

  Node *qLR(Node *&T) {
    Node *x = T;
    Node *y = x->left;
    Node *z = y->right;
    x->left = z->right;
    y->right = z->left;
    z->left = y;
    z->right = x;
    T = z;
    return T;
  }

  Node *qR(Node *&T) {
    Node *x = T;
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    T = y;
    return T;
  }

  Node *qRL(Node *&T) {
    Node *x = T;
    Node *y = x->right;
    Node *z = y->left;
    x->right = z->left;
    y->left = z->right;
    z->left = x;
    z->right = y;
    T = z;
    return T;
  }

  int cao(Node *T) {
    if (T == NULL)
      return 0;
    else
      return 1 + max(cao(T->left), cao(T->right));
  }

  Node *chenx(Node *&T, int x) {
    if (T == NULL)
      T = new Node(x);
    else if (T->data == x)
      cout << "\nGia tri " << x << " da co trong cay";
    else {
      if (x < T->data)
        T->left = chenx(T->left, x);
      else
        T->right = chenx(T->right, x);
      int h1 = cao(T->left);
      int h2 = cao(T->right);
      if (h1 > h2 + 1) {
        int h11 = cao(T->left->left);
        int h12 = cao(T->left->right);
        if (h11 > h12)
          T = qL(T);
        else
          T = qLR(T);
      } else if (h2 > h1 + 1) {
        int h21 = cao(T->right->left);
        int h22 = cao(T->right->right);
        if (h22 > h21)
          T = qR(T);
        else
          T = qRL(T);
      }
    }
    return T;
  }

  void nhapCayAVL() {
    root = NULL;
    while (1) {
      int x;
      cout << "\nNhap x (<>0) de them vao cay: ";
      cin >> x;
      if (x == 0)
        break;
      root = chenx(root, x);
    }
    cout << "\nDa nhap cay xong!!";
  }

  void duyetTrungTu(Node *T) {
    if (T != NULL) {
      duyetTrungTu(T->left);
      cout << T->data << "  ";
      duyetTrungTu(T->right);
    }
  }

  void inTrungTu() { duyetTrungTu(root); }

  void docFile() {
    ifstream fi("input.txt");
    int n;
    fi >> n;
    for (int i = 0; i < n; i++) {
      int x;
      fi >> x;
      root = chenx(root, x);
    }
    cout << "\nDa doc xong file!";
  }

  void ghiFile() {
    ofstream fo("output.txt");
    fo << "1. dsadasd";
    fo.close();
    cout << "\nDa ghi xong file!";
  }

  int tongNodeLa(Node *T) {
    int s = 0;
    if (T == NULL)
      return 0;
    else {
      if (T->left == NULL && T->right == NULL)
        s = T->data;
      else
        s = s + tongNodeLa(T->left) + tongNodeLa(T->right);
    }
    return s;
  }

  int inTongNodeLa() { tongNodeLa(root); }

  // Đếm số nốt lá
  int demNodeLa(Node *T) {
    int dem = 0;
    if (T == NULL)
      return 0;
    else {
      if (T->left == NULL && T->right == NULL)
        dem = 1;
      else
        dem = dem + demNodeLa(T->left) + demNodeLa(T->right);
    }
    return dem;
  }

  int inDemNodeLa() { demNodeLa(root); }
  // Tính tổng nốt lẻ

  int tongNodeLe(Node *T) {
    int s = 0;
    if (T == NULL)
      return 0;
    else {
      if (T->data % 2 != 0)
        s = T->data;
      else
        s = s + tongNodeLe(T->left) + tongNodeLe(T->right);
    }
    return s;
  }

  int inTongNodeLe() { tongNodeLe(root); }
  // Đếm các nốt chỉ có 1 con
  int demNodeChiCoMotCon(Node *T) {
    int dem = 0;
    if (T == NULL)
      return 0;
    else {
      if ((T->left == NULL && T->right != NULL) ||
          (T->left != NULL && T->right == NULL))
        dem = 1;
      else
        dem = dem + demNodeChiCoMotCon(T->left) + demNodeChiCoMotCon(T->right);
    }
    return dem;
  }

  int inDemNodeChiCoMotCon() { demNodeChiCoMotCon(root); }
  // Kiểm tra cây có nốt giá trị bằng x không

  bool kiemTraX(Node *T, int x) {
    bool KT = false;
    if (T == NULL)
      return false;
    else {
      if (T->data == x)
        KT = true;
      else {
        KT = kiemTraX(T->left, x) + kiemTraX(T->right, x);
      }
    }
    return KT;
  }

  void inKiemTraX(int x) {
    if (kiemTraX(root, x) == true)
      cout << "Co";
    else
      cout << "Khong";
  }

  // Duyệt cây theo chiều rộng (theo mức)
  void duyetTheoRong(Node *T) {
    if (root == NULL)
      return;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty()) {
      Node *p = Q.front();
      Q.pop();
      cout << p->data << "  ";
      if (p->left != NULL)
        Q.push(p->left);
      if (p->right != NULL)
        Q.push(p->right);
    }
  }
  void inDuyetCayTheoRong() { duyetTheoRong(root); }
};
main() {
  Tree T;
  // T.nhapCayAVL();
  T.docFile();
  // T.ghiFile();
  cout << "1. " << T.inTongNodeLa();
  cout << "\n2. " << T.inDemNodeLa();
  cout << "\n3. " << T.inTongNodeLe();
  cout << "\n4. " << T.inDemNodeChiCoMotCon();
  cout << "\n5. ";
  T.inKiemTraX(100);
  cout << "\n6. ";
  T.inDuyetCayTheoRong();
}
