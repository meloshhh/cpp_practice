#pragma once

struct Player {
public:
	int id;
	std::string username;
	int points;

	// This allows passing an existing string
	Player(int id, const std::string& username, int points);
	// This allows username to be created inline
	Player(int id, std::string&& username, int points);

	friend std::ostream& operator<<(std::ostream& os, const Player& user) {
		os << "{";
		os << "id: " << user.id;
		os << ", username: " << user.username;
		os << ", points: " << user.points;
		os << "}";
		return os;
	}
};