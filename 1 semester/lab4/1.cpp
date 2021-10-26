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
			cout << "�������!!! ���� ������������!!!"<< endl;	
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
			cout << "\n�������!!! ���� ������I�!!!\n";
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
	
	cout << "������ ���i�(1)\n";
	cout << "�i��i����(UNDO) ���i�(2)\n";
	cout << "���������(3)\n";
	cout << "_______________________\n";
	int inp;
	do{
		cout << "\n����i�� ����� 1,2 ��� 3\n";
		cin >> inp;
		if(inp == 1){
			cout << "\n��i���� ���i�, ������ ����������� �� �i�:\n";
			int ID;
			cin >> ID;
			while(ID){
				
				cout << "\n�����: ";
				string Text;
				cin >> Text;
				temp.text = Text;
				
				cout << "����� �����:";
				int Numb;
				cin >> Numb;
				temp.numb = Numb;
				
				MyStack.push(temp);
				
				cout << "����I� ���������: " << MyStack.size() << endl; 
				ID--;
			}
		}
		
		if(inp == 2){
			cout << "\n��i���� ���i�, ������ ����������� �� �i�:\n";
			int ID;
			cin >> ID;
			while(ID){
				if(!MyStack.empty()){
					EditingHistory last = MyStack.pop();
        			cout << "���������� " << last.text << " " << last.numb << endl;
				}
				else{
					MyStack.pop();
				}
				ID--;
			}
	
			cout << "����I� ���������: " << MyStack.size() << endl; 
		}
		  
	}while(inp != 3);
	
	cout << "����I� ���������: " << MyStack.size() << endl; 
	return 0;
}
