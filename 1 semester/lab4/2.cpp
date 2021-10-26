#include <iostream>
#include <string.h>
#define N 9

using namespace std;

struct Message{
	string text;
	int id;
	int NumbOfEmoticons;
};

struct queue{
	int head = -1;
	int tail = -1;
	Message arr[N];
};

bool empty(queue* Q){
	return Q->head == -1;
}

int size(queue* Q){
	if(empty(Q)){
		cout << "Î÷åðåäü ïóñòàÿ\n";
		return 0;
	}
	
	else if(Q->head == Q->tail){
		return 1;
	}
	
	else if(Q->tail < Q->head){
		return (N - Q->head + Q->tail + 1);
	}
	
	else return (Q->tail - Q->head + 1);
}

void push(queue* Q,Message x){
	if(empty(Q)){
		Q->head = 0;
		Q->tail = 0;
		Q->arr[(Q->tail)] = x;
	}
	else if((Q->tail + 1) % N == Q->head){
		cout << "Î÷åðåäü ïîëíàÿ\n";
	}
	else{
		Q->tail = (Q->tail + 1) % N; 
		Q->arr[(Q->tail)] = x;
	}
}

Message pop(queue* Q){
	if(empty(Q)){
		cout << "Î÷åðåäü ïóñòàÿ\n";
		return { "null", 0, 0 };
	}
	else if(Q->head == Q->tail){
		Message temp = Q->arr[(Q->head)];
		Q->tail = -1;
		Q->head = -1;
		return temp;
	}
	else{
		Message temp = Q->arr[(Q->head)];
		Q->head = (Q->head + 1) % N;
		return temp; 
	}
}

Message front(queue* Q){
	if(Q->head != -1){
		return Q->arr[(Q->head)];
	}
	cout << "Î÷åðåäü ïóñòàÿ\n";
	return { "null", 0, 0 };
}

void print(queue* Q){
	if(empty(Q)){
		cout << "Î÷åðåäü ïóñòàÿ\n";
	}
	
	else{
		queue TempQ = *Q;
		while(!empty(&TempQ)){
			Message M = front(&TempQ);
			cout << M.id << " " << M.NumbOfEmoticons << " " << M.text << endl;
			pop(&TempQ);
		}
	}
}

int main(){
	setlocale(LC_ALL,"rus");
	queue MyQueue;
	Message temp;
	
	cout << "Äîáàâèòü 7 ñîîáùåíèé:\n";
	int IND = 7;
	while(IND--){
		cout << "òåêñò: ";
		string TEXT;
		cin >> TEXT;
		temp.text = TEXT;
		
		cout << "id: ";
		int ID;
		cin >> ID;
		temp.id = ID;
		
		cout << "êîë-âî ñìàéëîâ: ";
		int NUMB;
		cin >> NUMB;
		temp.NumbOfEmoticons = NUMB;
		
		push(&MyQueue,temp); 
	}
	
	cout << endl << "ÐÀÇÌÅÐ " << size(&MyQueue) << endl << "ÄÎÊÓÌÅÍÒ:" << endl;
	print(&MyQueue);
	
	cout << "\nÄîáàâèòü 4 ñîîáùåíèé:\n";
	IND = 4;
	while(IND--){
		cout << "\nòåêñò: ";
		string TEXT;
		cin >> TEXT;
		temp.text = TEXT;
		
		cout << "id: ";
		int ID;
		cin >> ID;
		temp.id = ID;
		
		cout << "êîë-âî ñìàéëîâ: ";
		int NUMB;
		cin >> NUMB;
		temp.NumbOfEmoticons = NUMB;
		
		push(&MyQueue,temp);
	}
	
	cout << endl << "ÐÀÇÌÅÐ " << size(&MyQueue) << endl << "ÄÎÊÓÌÅÍÒ:" << endl;
	print(&MyQueue);
	
	cout << "\nÇàáðàòü 6 ñîîáùåíèé:\n";
	IND = 6;
	while(IND--){
		pop(&MyQueue);
	}
	
	cout << endl << "ÐÀÇÌÅÐ " << size(&MyQueue) << endl << "ÄÎÊÓÌÅÍÒ:" << endl;
	print(&MyQueue);
	
	cout << "\nÐåäàêòèðîâàòü 2 ñîîáùåíèÿ:\n";
	IND = 2;
	while(IND--){
		temp = pop(&MyQueue);
		temp.NumbOfEmoticons = 0;
		push(&MyQueue,temp);
	}
	
	cout << endl << "ÐÀÇÌÅÐ " << size(&MyQueue) << endl << "ÄÎÊÓÌÅÍÒ:" << endl;
	print(&MyQueue);
	
	cout << "\nÇàáðàòü 6 ñîîáùåíèé:\n";
	IND = 6;
	while(IND--){
		pop(&MyQueue);
	}
	
	cout << endl << "ÐÀÇÌÅÐ " << size(&MyQueue) << endl << "ÄÎÊÓÌÅÍÒ:" << endl;
	print(&MyQueue);
	

	return 0;
}
