#include "PriorityQueue.h"
using namespace std;

int main()
{
	PriorityQueue <char> JohndeLancie(5);

	JohndeLancie.push('L', 4);
	JohndeLancie.push('P', 1);
	JohndeLancie.push('D', 3);
	JohndeLancie.push('R', 2);
	JohndeLancie.push('W', 5);

	int loopCount = JohndeLancie.GetSize();

	for (int i = 0; i < loopCount; i++)
	{
		cout << "Current item at front of queue:" << endl;
		cout << "Data: " << JohndeLancie.Front()->getData() << endl;
		cout << "Priority: " << JohndeLancie.Front()->m_priority << endl;
		JohndeLancie.Pop();
		cout << "Removing item at front of queue..." << endl << endl;
	}

	return 0;
};