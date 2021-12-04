#include "PriorityQueue.h"
using namespace std;

int main()
{
	PriorityQueue <char> JohndeLancie(6);

	JohndeLancie.push('G', 4);
	JohndeLancie.push('J', 1);
	JohndeLancie.push('D', 3);
	JohndeLancie.push('W', 2);
	JohndeLancie.push('W', 5);

	int loopCount = JohndeLancie.GetSize();

	for (int i = 0; i < loopCount; i++)
	{
		cout << "Item #" << i + 1 << endl;
		cout << "Data: " << JohndeLancie.Front()->getData() << endl;
		cout << "Priority: " << JohndeLancie.Front()->m_priority << endl << endl;
		JohndeLancie.Pop();
	}

	cout << "Data: " << JohndeLancie.Front()->getData() << endl;

	/*cout << JohndeLancie.Front()->getData() << endl;
	cout << JohndeLancie.Front()->m_priority << endl;
	cout << JohndeLancie.Front()->m_next->getData() << endl;
	cout << JohndeLancie.Front()->m_next->m_priority << endl;
	cout << JohndeLancie.Front()->m_next->m_next->getData() << endl;
	cout << JohndeLancie.Front()->m_next->m_next->m_priority << endl;
	cout << JohndeLancie.Front()->m_next->m_next->m_next->getData() << endl;
	cout << JohndeLancie.Front()->m_next->m_next->m_next->m_priority << endl;
	cout << JohndeLancie.Front()->m_next->m_next->m_next->m_next->getData() << endl;
	cout << JohndeLancie.Front()->m_next->m_next->m_next->m_next->m_priority << endl;*/

	return 0;
};