#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;

	for (int i = 0; i < 10; ++i)
		s.push(i);
	for (int i = s.size(); i > 0; --i)
	{
		cout << s.top() << '\n';
		s.pop();
	}
	if (s.empty())
		cout << "Stack is empty.\n";
	return 0;
}
