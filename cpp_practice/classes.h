#pragma once


class User {
public:
	std::string username;
	int age;

	User();
	User(std::string username, int age);

	friend std::ostream& operator<<(std::ostream& os, const User& user)
	{
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


struct UserStruct {
public:
	int id;
	std::string username;
	int age;

	// This allows username to be an existing string
	UserStruct(int id, std::string& username, int age);
	// This allows username to be created inline
	UserStruct(int id, std::string&& username, int age);

	friend std::ostream& operator<<(std::ostream& os, const UserStruct& user)
	{
		os << "{";
		os << "id: " << user.id;
		os << ", username: " << user.username;
		os << ", age: " << user.age;
		os << "}";
		return os;
	}
};
