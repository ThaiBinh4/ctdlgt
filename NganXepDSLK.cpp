#include <iostream>
#include<math.h>
using namespace std;
// cấp phát động Node trong danh sách liên kết đơn
//tạo 1 node mới;
struct node{
    int  data;
    node *next;//link 
};
//typedef struct node node;
node* makeNode(int x){
    //C node *newNode=(node*) malloc(sizeof(node));
    //C++
    node *newNode = new node();
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
//thêm node vào đầu danh sách liên kết "C++" truyền tham chiếu
void push(node *&head, int x){
    node *newnode=makeNode(x);
    //b1: cho phần next của newnode trỏ vào phần head hiện tại
    newnode->next=head;
    // b2: cập nhật node head=> newnode
    head=newnode;
}
//xóa node đầu khỏi danh sách liên kết
void pop(node *&head){
    if (head==NULL) return;
    node *tam=head;
    //head=tam->next ;
    head=head->next;
    delete tam;
}
// lấy phần tử trong ngăn xếp
int top(node *&head){
    if (head!=NULL)
        return head->data;
}
//đếm số lượng phần tử trong ngăn xếp
int size(node *&head){
    int n=0;
    node *a=head;
    while(a!=NULL){
        ++n;
        a=a->next;
    }
    return n;
}
int main(){
    node *head=NULL;
    while (1)
    {
        cout<<"1. them\n";
        cout<<"2. xoa\n";
        cout<<"3. lay\n";
        cout<<"4. so luong \n";
        cout<<"=========================\n";
        int k,z;cin>>k;
        if (k==1) {cout<<"nhap x:";cin>>z;push(head,z);}
            else if (k==2) pop(head);
                    else if(k==3) cout<<top(head)<<endl;
                            else if(k==4) cout<<size(head)<<endl;
                                else break;
    }
    
}