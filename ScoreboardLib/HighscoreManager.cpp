#include "HighscoreManager.h"

HighscoreManager::HighscoreManager() {}

HighscoreManager::~HighscoreManager() {}

void HighscoreManager::read_score_file(std::string file_name) {

	scores.clear();

	std::ifstream input;
	input.open(file_name, std::ios::in | std::ios::binary);

	if (input.is_open()) {

		Score new_score;
		input.seekg(std::ios::beg);

		while (true) {
			input.read((char*)&new_score, sizeof(new_score));
			if (input.eof())
				break;
			scores.push_back(new_score);
		}

		input.close();
	}

}

void HighscoreManager::add_score(std::string new_name, unsigned int new_points) {

	Score new_score;
	strcpy_s(new_score.name, new_name.c_str());
	new_score.points = new_points;
	scores.push_back(new_score);

}

void HighscoreManager::write_score_file(std::string file_name) {

	std::ofstream output;
	output.open(file_name, std::ios::out | std::ios::binary);

	if (output.is_open()) {

		for (const Score& score : scores) {
			output.write((char*)&score, sizeof(score));
		}

		output.close();
	}

	scores.clear();

}

void HighscoreManager::order_score() {

	Score temp_score_1;
	Score temp_score_2;

	for (auto i = 0; i < scores.size(); i++) {
		if (i >= 100) break;
		for (auto j = 0; j + i < scores.size() - 1; j++) {
			temp_score_1 = scores.at(j);
			if (temp_score_1.points < scores.at(j + 1).points) {
				temp_score_2 = scores.at(j + 1);
				scores.at(j + 1) = temp_score_1;
				scores.at(j) = temp_score_2;
			}
		}
	}

	if (scores.size() > 100) scores.resize(100);

}

void HighscoreManager::show_score() {

	unsigned int counter = 1;

	for (const Score& score : scores) {
		std::cout << counter << "  " << std::setw(11) << std::left << score.name << "  " << score.points << std::endl;
		counter++;
		if (counter > 100)
			break;
	}

}

