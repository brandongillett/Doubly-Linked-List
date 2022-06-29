#include <iostream>
using namespace std;

class node{
    public:
	class node *next;
	class node *prev;
    string user;
};

class list{
    public:
    int count;
	class node *first;
	class node *last;
    list(){
        this->first = NULL;
	    this->count = 0;
    }
    void print();
    void add();
	void del();
	void exit(list *l);
};

void list::print(){

    node* nd = this->first;
	cout << "List : \n";
	while(nd != NULL){
		cout << nd->user << endl;
		nd = nd->next;
		count ++;
    }
	cout << endl;
}

void list::add(){
	string username;

	node *n = new node;

	cout << "Enter Username : ";
	cin >> username;
    n->user = username;

	if (this->first == NULL){
		n->prev = NULL;
		this->first = n;
		this->last = n;
	}
	else{
		n->prev = this->last;
		this->last->next = n;
		this->last = n;
	}
	n->next = NULL;
	cout << "Added " << username << endl;
    this->count ++;
}

void list::del(){
  string username;
  cout << "Username To Delete: ";
  cin >> username;

	node* nd = this->first;
	bool deleted = false;

	while (deleted == false && nd != NULL)
	{
		if (nd->user == username)
		{
			deleted = true;
			if (nd->prev == NULL && nd->next != NULL){
				nd->next->prev = NULL;
				this->first = nd->next;
				this->count -= 1;
				delete nd;
			}
			else if (nd->prev == NULL && nd->next == NULL){
				this->first = NULL;
				this->last = NULL;
				this->count -= 1;
				delete nd;
			}
			else if (nd->next == NULL){
				nd->prev->next = NULL;
				this->last = nd->prev;
				this->count -= 1;
				delete nd;
			}
			else{
				nd->prev->next = nd->next;
				nd->next->prev = nd->prev;
				this->count -= 1;
				delete nd;
			}

		}
		if (nd != NULL)
		{
			nd = nd->next;
		}
	}
  system("clear");
	if(deleted){
		cout << "Deleted node " << username << endl;
	}
	else if(!deleted){
		cout << "Could not delete node " << username << endl;
	}
}

void list::exit(list *l){
	node* nd = l->first;
	while (nd != NULL)
	{
		delete nd;
		nd = nd->next;
	}
	delete l;

}
