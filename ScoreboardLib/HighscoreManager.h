#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

struct Score {
	char name[100];
	unsigned int points;
};

class HighscoreManager {
private:
	std::vector<Score> scores;

public:
	HighscoreManager();
	virtual ~HighscoreManager();
	void read_score_file(std::string file_name = "scores.dat");
	void add_score(std::string new_name, unsigned int new_points);
	void write_score_file(std::string file_name = "scores.dat");
	void order_score();
	void show_score();
};