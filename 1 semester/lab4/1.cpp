#include <iostream>
#include <string>
#define N 7

using namespace std;

struct EditingHistory{
	string text;
	int numb;
};

template <typename T>
struct stack{
	EditingHistory array[N];
	int head = -1;
	
	bool empty(){
		return (head == -1);
	}
	
	int size(){
		return (head + 1);
	}
	
	EditingHistory& push(EditingHistory x){
		if(size() == N){
			cout << "ÏÎÌÈËÊÀ!!! ÑÒÅÊ ÏÅÐÅÏÎÂÍÅÍÈÉ!!!"<< endl;	
		}
		
		else{
			head++;
			array[head] = x;	
		}	
	}
	
	EditingHistory& pop(){
		if(size() != 0){
			return array[head--];
		}
		else{
			cout << "\nÏÎÌÈËÊÀ!!! ÑÒÅÊ ÏÎÐÎÆÍIÉ!!!\n";
		}
	}
	
	EditingHistory& top(){
		return array[head];
	}

};



int main(){  
	setlocale(LC_ALL,"rus");
	stack <EditingHistory> MyStack;
	EditingHistory temp;
	
	cout << "Äîäàòè ïîäiþ(1)\n";
	cout << "Âiäìiíèòè(UNDO) ïîäiþ(2)\n";
	cout << "Çàâåðøèòè(3)\n";
	cout << "_______________________\n";
	int inp;
	do{
		cout << "\nÂâåäiòü ÷èñëî 1,2 àáî 3\n";
		cin >> inp;
		if(inp == 1){
			cout << "\nÑêiëüêè ðàçiâ, áóäåòå ïîâòîðþâàòè öþ äiþ:\n";
			int ID;
			cin >> ID;
			while(ID){
				
				cout << "\nÒåêñò: ";
				string Text;
				cin >> Text;
				temp.text = Text;
				
				cout << "Íîìåð ðÿäêà:";
				int Numb;
				cin >> Numb;
				temp.numb = Numb;
				
				MyStack.push(temp);
				
				cout << "ÐÎÇÌIÐ ÄÎÊÓÌÅÍÒÓ: " << MyStack.size() << endl; 
				ID--;
			}
		}
		
		if(inp == 2){
			cout << "\nÑêiëüêè ðàçiâ, áóäåòå ïîâòîðþâàòè öþ äiþ:\n";
			int ID;
			cin >> ID;
			while(ID){
				if(!MyStack.empty()){
					EditingHistory last = MyStack.pop();
        			cout << "Ñêàñîâàíèé " << last.text << " " << last.numb << endl;
				}
				else{
					MyStack.pop();
				}
				ID--;
			}
	
			cout << "ÐÎÇÌIÐ ÄÎÊÓÌÅÍÒÓ: " << MyStack.size() << endl; 
		}
		  
	}while(inp != 3);
	
	cout << "ÐÎÇÌIÐ ÄÎÊÓÌÅÍÒÓ: " << MyStack.size() << endl; 
	return 0;
}
