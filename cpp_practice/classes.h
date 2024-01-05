#pragma once

class User {
public:
	std::string username;
	int age;

	User();
	User(std::string username, int age);

	friend std::ostream& operator<<(std::ostream& os, const User& user) {
		os << "{username: " << user.username << ", age: " << user.age << "}";
		return os;
	}
};

class LifecycleDebug {
public:
	int x;

	LifecycleDebug();
	LifecycleDebug(const LifecycleDebug& other);
	~LifecycleDebug();
};
