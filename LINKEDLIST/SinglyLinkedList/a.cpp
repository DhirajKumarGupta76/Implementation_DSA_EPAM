# include <iostream>
using namespace std;

// The members of a struct are public by default, while the members of a class are private by default.
struct listnode{
    //declaration
    int val;
    listnode* next;
    //construction
    listnode(int x){
        val=x;
        next=NULL;

    }

};


class solution{
    public:
    listnode* solve(listnode* head ){
        // logic
    }

};

int main(){
    listnode* head=new listnode(2);
    head->next=new listnode(4);
    head->next->next=new listnode(7);

    solution obj;
    head=obj.solve(head);
    while(head){
        cout<<head->val;
        head=head->next;
    }



    return 0;
}