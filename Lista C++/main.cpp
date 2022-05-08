#include <iostream>

#include <cstdlib>
#include <time.h>
#include  <ctime>

using namespace std;

struct element
{
    int value;
    element* prev;
    element* next;
};

bool isEmpty(element*& a)
{
	if(a==NULL)
        return true;
	else
        return false;
}

void addRight(int x, element*& a)
{
	element *nowy=new element;
	nowy->value=x;
	if(a==NULL)
	{
		nowy->prev=nowy;
		nowy->next=nowy;
		a=nowy;
	}
	else
	{
		nowy->prev=a;
		nowy->next=a->next;
		a->next=nowy;
		element *temp=a;
		while(temp->prev!=a) temp=temp->prev;
		temp->prev=nowy;
	}
}

void addLeft(int x, element*& a)
{
	element *nowy=new element;
	nowy->value=x;
	if(a==NULL)
	{
		nowy->prev=nowy;
		nowy->next=nowy;
		a=nowy;
	}
	else
	{
		nowy->next=a;
		nowy->prev=a->prev;
		a->prev=nowy;
		element *temp=a;
		while(temp->next!=a) temp=temp->next;
		temp->next=nowy;
	}
}

void addAny(int x, element*& a, int pos)
{
	if(a==NULL)
	{
		element *nowy=new element;
		nowy->value=x;
		nowy->prev=nowy;
		nowy->next=nowy;
		a=nowy;
	}
	else
	{
		element *temp=a;
		int i=1;
		if(a->next!=a)
		{
			while(i<pos-1)
			{
				temp=temp->next;
				i++;
			}
		}
		addRight(x, temp);
	}
}

void delLast(element*& a)
{
	element *temp=a;
	a=NULL;
	delete temp;
}

void delRight(element*& a)
{
	if(a->next==a)
        delLast(a);
	else
	{
		element *temp=a->next;
		a->next->next->prev=a->next->prev;
		a->next=a->next->next;
		delete temp;
	}
}

void delLeft(element*& a)
{
	if(a->next==a)
        delLast(a);
	else
	{
		element *temp=a->prev;
		a->prev->prev->next=a->prev->next;
		a->prev=a->prev->prev;
		delete temp;
	}
}

void delAny(element*& a, int pos)
{
	if(a->next==a)
        delLast(a);
	else
	{
		element *temp=a;
		int i=1;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		delRight(temp);
	}
}

void printList(element*& a)
{
	element *temp=a;
	do
	{
		cout<<temp->value<<" ";
		temp=temp->next;
	}while(temp!=a);
}

void printListRev(element*& a)
{
	element *temp=a;
	do
	{
		cout<<temp->value<<" ";
		temp=temp->prev;
	}while(temp!=a);
}

int main()
{
	srand(time(NULL));
	int wybor;
	element *biezacy=NULL;
	int x, pozycja;
	do
	{
		cout<<"1. Sprawdzenie czy lista jest pusta"<<endl;
		cout<<"2. Dodanie elementu na prawo od biezacego elementu"<<endl;
		cout<<"3. Dodanie elementu na lewo od biezacego elementu"<<endl;
		cout<<"4. Dodanie elementu na okreslona pozycje"<<endl;
		cout<<"5. Usuniêcie elementu znajdujacego sie po prawej od biezacego"<<endl;
		cout<<"6. Usuniecie elementu znajdujacego sie po lewej od biezacego"<<endl;
		cout<<"7. Usuniecie elementu znajdujacego sie na okreslonej pozycji"<<endl;
		cout<<"8. Wyswietlenie listy od poczatku do konca"<<endl;
		cout<<"9. Wyswietlenie listy od konca do poczatku"<<endl;
		cout<<"10. Wyjscie z programu"<<endl;
		cout<<"Wybor: ";
		cin>>wybor;
		switch(wybor)
		{
		case 1:
			if(isEmpty(biezacy))
                cout<<"Lista jest pusta"<<endl;
			else
                cout<<"Lista nie jest pusta"<<endl;
			break;
		case 2:
			x=rand()%50+1;
			addRight(x, biezacy);
			cout<<"Dodano element o wartoœci "<<x<<" na prawo od bie¿¹cego"<<endl;
			break;
		case 3:
			x=rand()%50+1;
			addLeft(x, biezacy);
			cout<<"Dodano element o wartoœci "<<x<<" na lewo od bie¿¹cego"<<endl;
			break;
		case 4:
			cout<<"Podaj numer pozycji: ";
			cin>>pozycja;
			x=rand()%50+1;
			addAny(x, biezacy, pozycja);
			cout<<"Dodano element o wartoœci "<<x<<" na pozycjê "<<pozycja<<endl;
			break;
		case 5:
			if(!isEmpty(biezacy))
			{
				delRight(biezacy);
				cout<<"Usuniêto element po prawej od bie¿¹cego"<<endl;
			}
			else
                cout<<"lista jest pusta"<<endl;
			break;
		case 6:
			if(!isEmpty(biezacy))
			{
				delLeft(biezacy);
				cout<<"Usuniêto element po lewej od bie¿¹cego"<<endl;
			}
			else
                cout<<"lista jest pusta"<<endl;
			break;
		case 7:
			if(!isEmpty(biezacy))
			{
				cout<<"Podaj numer pozycji: ";
				cin>>pozycja;
				delAny(biezacy, pozycja);
				cout<<"Usuniêto element numer "<<pozycja<<endl;
			}
			else
                cout<<"Lista jest pusta"<<endl;
			break;
		case 8:
			if(!isEmpty(biezacy))
			{
				cout<<"Zawartoœæ listy:"<<endl;
				printList(biezacy);
			}
			else
                cout<<"Lista jest pusta"<<endl;
			break;
		case 9:
			if(!isEmpty(biezacy))
			{
				cout<<"Zawartoœæ listy od koñca:"<<endl;
				printListRev(biezacy);
			}
			else
                cout<<"Lista jest pusta i nie ma nic do wyœwietlenia"<<endl;
			break;
		case 10:
			break;
		default:
			cout<<"Prosze wybrac poprawny numer zadania"<<endl;
		}
		cout<<endl;
	}
	while(wybor!=10);
	delete biezacy;
	return 0;
}
