#pragma once
#include <iostream>
#include <string>
using namespace std;
__interface Notifier
{
	void send(const string& message);
};

class SMS : public Notifier // CORE CLASS
{
public:
	void send(const string& message) override
	{
		cout << "SMS : " << message << endl;
	}

};
// abstr
class BaseDecorator abstract: public Notifier
{
	Notifier* notifier;
public:
	BaseDecorator(Notifier* notifier)
		: notifier(notifier)
	{}
	void send(const string& message) override
	{
		notifier->send(message);
	}
};
class Facebook : public BaseDecorator
{
public:
	Facebook(Notifier* notifier)
		: BaseDecorator(notifier)
	{}
	void send(const string& message) override
	{
		BaseDecorator::send(message);
		cout << "Facebook : " << message << endl;
	}

};

class Telegram : public BaseDecorator
{
public:
	Telegram(Notifier* notifier)
		: BaseDecorator(notifier)
	{}
	void send(const string& message) override
	{
		BaseDecorator::send(message);
		cout << "Telegram : " << message << endl;
	}
};