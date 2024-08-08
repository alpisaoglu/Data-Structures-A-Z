#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node (int value) : data(value) , next(nullptr) {} 
    // Her arry 2 parçaya böldük. İlk kısma verimizi ekledik, ikinci kısmı ise Node işaretledik. 
    // Node* yapısını girdik. Node yapısı int değer girilir. verimiz değer tutar, işaretcimizin içide boştur.
};

Node* head = nullptr; // Global bir head pointer

void ft_ListAppend(int value) //void fonksiyonu kullanmamızın nedeni herhangi bir şey döndürmeceğimizden ve pointerla işlem yapıcağımızdan dolayı.
{   
    Node* newNode = new Node(value); 
    // Yeni bir node oluşturuyoruz, bir int değeri taşıcak struct yapısında olduğundan dolayı next boş olucak.
    if(head == nullptr)
        head = newNode;
    //Ekleyeceğimizden dolayı sona kadar döngüyle birlikte listeye geliyoruz.Bunun için bir node yapıcağız. mantık i++ artırmak gibi düşünebilirsiniz. 
    else{
    Node* i = head; // Boş bir global header vardı bunu direk eşitledik. 
    while(i->next != nullptr) // i değeri diğer arry boş gösterene kadar ilerlesin.
    {
        i = i->next; // i değerini next gösterdi. Next ise diğer arry'deki veriyi tuttuyor. 
    }
    i->next = newNode; // i değer boş olduğunda 5|# --> NEW|#
   }
}
void ft_ListInsert(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return; // head boş ise, fonksiyondan çıkıyoruz.
    }
    newNode->next = head;
    head = newNode;
}
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) return; // Liste boşsa, hiçbir şey yapma

    Node* temp = head; // Silinecek düğümü işaret eden geçici pointer
    head = head->next; // head'i bir sonraki düğüme kaydır
    delete temp;       // Eski baş düğümü sil
}

void printList()
{
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    // Başa ekleme
    ft_ListInsert(10);  // Liste: 10
    ft_ListInsert(20);  // Liste: 20 -> 10
    ft_ListInsert(30);  // Liste: 30 -> 20 -> 10
    cout << "Başa ekleme sonrası liste: ";
    printList();

    // Sona ekleme
    ft_ListAppend(40);  // Liste: 30 -> 20 -> 10 -> 40
    ft_ListAppend(50);  // Liste: 30 -> 20 -> 10 -> 40 -> 50
    cout << "Sona ekleme sonrası liste: ";
    printList();

    // Baştan silme
    deleteAtBeginning(head);  // Liste: 20 -> 10 -> 40 -> 50
    cout << "Baştan silme sonrası liste: ";
    printList();

    return 0;
}