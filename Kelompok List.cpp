#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


struct Node{
    char nama[100];
    char NIM[50];
    Node *next;
};

typedef Node *List;
List head = NULL, node = NULL, mainly = NULL, masukan,posisi;
void tambahawal(int kode);
void tampil();
int tambahhead();
int tambahafter();
int tambahbefore();
int tambahtail();
void hapusheadtail();
void hapustertentu();
void hapusall();


/*class Simpul{
private:
    List head,node,main;

public:
    int tambah.awal(int kode);
    /*int tambah.head(char *nama, char *NIM);
    int tambah.tail(char *nama, char *NIM);
};*/

int main()
{
    int p,x;
    cout<<"Daftar Mahasiswa : ";cin>>p;
    tambahawal(p);
    system("cls");
    tampil();
    getch();
    system("cls");
    cout<<"Penambahan pada head : "<<endl;
    tambahhead();
    system("cls");
    tampil();
    getch();
    system("cls");
    cout<<"Penambahan pada setelah node tertrntu : "<<endl;
    tambahafter();
    system("cls");
    tampil();
    getch();
    system("cls");
    cout<<"Penambahan pada tail : "<<endl;
    tambahtail();
    system("cls");
    tampil();
    getch();
    system("cls");
    cout<<"Penambahan pada sebelum node tertentu: "<<endl;
    tambahbefore();
    system("cls");
    tampil();
    getch();
    while(true){
    cout<<"Anda mau delete? (Pilih 1 untuk simpul pertama dan terakhir, 2 untuk snode tertentu, 3 untuk hapus semua node, 4. Tidak) : ";cin>>x;
    if(x==1)
    {
        system("cls");
        hapusheadtail();
        tampil();
        getch();
        continue;
    }
    else if(x==2){
        system("cls");
        hapustertentu();
        tampil();
        getch();
        continue;
    }
    else if(x==3){
        system("cls");
        hapusall();
        tampil();
        cout<<"Tadaa udah kehapus semua wkwk"<<endl;
        break;
    }
    else if(x==4){
        break;
    }
    else
    {
        system("cls");
        cout<<"Ulangi lagi!"<<endl;
        continue;
    }

  }

  cout<<"Selesai"<<endl;


    getch();
    return 0;
}



void tambahawal(int kode)
{

    for(int i=0;i<kode;i++)
     {
        node = new Node();
        cout<<"Masukkan nama : ";cin>>node->nama;
        cout<<"Masukkan nim : ";cin>>node->NIM;
        if(head==NULL)
        {
            head = node;
            mainly = node;
        }
        else{
            mainly->next=node;
            mainly=node;
        }
    }
    mainly->next = NULL;
}

void tampil(){
    mainly = head;
    while(mainly!=NULL)
    {
        cout<<"Nama : "<<mainly->nama<<endl;
        cout<<"nim : "<<mainly->NIM<<endl;
        mainly=mainly->next;
    }
}

int tambahhead()
{

    masukan = new Node();
    cout<<"Masukkan Nama : ";cin>>masukan->nama;
    cout<<"Masukkan NIM : ";cin>>masukan->NIM;
    masukan->next=head;
    head = masukan;
    return 1;
}

int tambahafter()
{
    List after;
    char calonNIM[50];
    masukan = new Node();
    cout<<"Masukkan NIM data, yang setelahnya ingin dimasukkan : ";cin>>calonNIM;
    after=head;
    do
    {
        after=after->next;
    }while(stricmp(after->NIM,calonNIM)!=0);

    int banding = stricmp(after->NIM,calonNIM);

        cout<<"Masukkan Nama : ";cin>>masukan->nama;
        cout<<"Masukkan NIM : ";cin>>masukan->NIM;
        masukan->next=after->next;
        after->next=masukan;
}

int tambahbefore()
{
    List /*before*/previous;
    char calonNIM[50];
    cout<<"Masukkan NIM yang sebelumnya ingin dimasukkkan data baru : ";cin>>calonNIM;
    int banding = stricmp(head->NIM,calonNIM);
    if (banding==0)
    {
        tambahhead();
    }
    else{
        mainly = head;
        do{
           previous=mainly;
           mainly=mainly->next;
        }while(stricmp(mainly->NIM,calonNIM)!=0);
            masukan = new Node();
            cout<<"Masukkan Nama : ";cin>>masukan->nama;
            cout<<"Masukkan NIM : ";cin>>masukan->NIM;
            masukan->next=mainly;
            previous->next=masukan;
    }

}

int tambahtail()
{
  List tail;
  tail=head;
  do{
    tail=tail->next;
  }while(tail->next!=NULL);

  masukan=new Node();
  cout<<"Masukkan Nama baru : ";cin>>masukan->nama;
  cout<<"Masukkan NIM baru : ";cin>>masukan->NIM;
  masukan->next=NULL;
  tail->next=masukan;
  tail=tail->next;
  return 0;
}

void hapusheadtail(){
    List tail,before;
    posisi = head;
    head = head->next;
    delete posisi;
    tail=head;
    do{
        before=tail;
        tail=tail->next;
    }while(tail->next!=NULL);
    posisi=tail;
    tail=before;
    tail->next=NULL;

    delete posisi;

}

void hapustertentu()
{
    List before,prev;
    tampil();
    char NIMhapus[50];
    cout<<"Masukkan NIM Data yang ingin dihapus : ";cin>>NIMhapus;
    mainly = head;
    if(stricmp(head->NIM,NIMhapus)==0)
    {
        posisi = head;
        head = head->next;
        delete posisi;
    }
    else{
        before = head;
        do{
            prev=before;
            before=before->next;
        }while(stricmp(before->NIM,NIMhapus)!=0);
        posisi=before;
        prev->next=before->next;
        delete posisi;
    }
}

void hapusall()
{
    mainly=head;
    while(mainly!=NULL)
    {
        posisi = mainly;
        mainly=mainly->next;
        delete posisi;
    }
}
