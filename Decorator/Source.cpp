#include <iostream>
#include <thread>
#include <chrono>
#include "Message.h"

using namespace std;
int main()
{
	Notifier* notifier = new SMS;
	notifier->send("Nu zdarova");

	Notifier* notifier1 = new Facebook(new SMS);
	notifier1->send("Paka");

	Notifier* not2 = new Facebook(notifier);
	not2->send("Vam povistka");
}