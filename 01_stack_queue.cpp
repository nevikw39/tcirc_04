#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	queue<int> q;

	for (int i = 0; i < 10; i++)
	{
		s.push(i);
		q.push(i);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "Stack: " << s.top() << ' ';
		s.pop();
		cout << "Queue: " << q.front() << '\n';
		q.pop();
	}
	if (q.empty())
		cout << "Queue is empty.\n";
	return 0;
}
