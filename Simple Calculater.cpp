#include <iostream>
using namespace std;

int main()
{
	char operat;
	float num1, num2;
	
  cout<<"Enter the +,-,*,/ any one of this:";
	cin >> operat;
	cout<<"Enter the Number 1:";
	cin>>num1;
	cout<<"Enter the Number 2:";
	cin>>num2;
   

	switch (operat) {

	case '+':
		cout << num1 + num2;
		break;

	
	case '-':
		cout << num1 - num2;
		break;

	case '*':
		cout << num1 * num2;
		break;

	case '/':
		cout << num1 / num2;
		break;

	default:
		cout << "Error! operator is not correct";
	}

	return 0;
}

