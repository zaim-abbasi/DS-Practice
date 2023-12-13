#include "Stack.h";

int main() {
	Stack<char> op;
	cout << op.postFixToAnswer("623+-382/+*") << endl;
	cout << op.infixToPostFix("a/b*c+d") << endl;


	/*Stack<string> History;
	string paragraph="";
	int choice;
	do {
		cout << paragraph << endl;
		cout << "1.. Add word\n"
			<< "2.. Undo\n"
			<< "3.. print stack\n"
			<< "4.. exit\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			History.push(paragraph);
			string word;
			cin >> word;
			paragraph += " " + word;
		}break;
		case 2: {
			paragraph = History.showTop();
			History.pop();
		}break;
		case 3: {
			cout << "stack\n";
			History.print();
		}break;
		default:exit(0);
		}
	
	} while (choice);*/

}