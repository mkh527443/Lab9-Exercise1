#include<iostream>

using namespace std;

class Queue
{
private:
	int SIZE = 5;
	int* queue = new int[SIZE];
	int rear = -1;
	int front = -1;
	int value;

public:
	bool is_empty()
	{
		if (rear == -1 && front == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool is_full()
	{
		if (rear == SIZE - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void get_front()
	{
		cout << "The front is on: " << queue[front];
	}

	void enqueue()
	{
		cout << "Enter the value: ";
		cin >> value;

		if (rear == SIZE - 1)
		{
			cout << "Overflow!!";
		}
		else
		{
			if (front == -1)
			{
				front = rear = 0;
			}
			else
			{
				rear++;
			}
			queue[rear] = value;
			cout << "Item Inserted!";
		}
	}

	void dequeue()
	{
		if (front == -1)
		{
			cout << "Underflow!!";
		}
		else
		{
			value = queue[front];
			if (front == rear)
			{
				front = rear = -1;
			}
			else
			{
				front++;
			}
			cout << "Item Deleted";
		}
	}

	void display()
	{

		if (front == -1)
		{
			cout << "Queue is empty";
		}
		else
		{
			for (int i = front; i <= rear; i++)
			{
				cout << queue[i] << " ";
			}
		}
	}
};

int main()
{
	Queue q;
	int choice;

	cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Show Front\n5.Exit\n";
	while (1)
	{
		cout << endl << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{

		case 1:
			q.enqueue();
			break;

		case 2:
			q.dequeue();
			break;

		case 3:
			q.display();
			break;

		case 4:
			q.get_front();
			break;

		case 5:
			return 0;

		}

	}
}