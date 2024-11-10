#pragma once

#include <iostream>

class LifecycleDebug {
public:
	int x;

	LifecycleDebug();
	LifecycleDebug(const LifecycleDebug& other);
	~LifecycleDebug();
};

class User {
public:
	std::string username;
	int age;

	User();
	User(std::string username, int age);

	friend std::ostream& operator<<(std::ostream& os, const User& user);
};

class State {
public:
	State();
	int open_contact_id;
};
