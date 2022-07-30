#pragma once

#include <HighscoreManager.h>

int main() {

	HighscoreManager highscore_manager;
	bool finished = false;
	unsigned int option;

	while (!finished) {

		std::cout << "Que desea hacer: 1 Ver Score / 2 Agregar Jugador / 3 Terminar" << std::endl;
		std::cin >> option;

		if (option < 1 || option > 3)
			option = 3;

		if (option == 1 || option == 2)
			highscore_manager.read_score_file("scores.dat");

		switch (option)
		{
		case 1:	// Ver score
			highscore_manager.show_score();
			break;

		case 2:	// Agregar jugador
		{
			std::string player_name;
			unsigned int player_points{};

			std::cout << "Indique el nombre y el puntaje: ";
			std::cin >> player_name >> player_points;
			std::cout << std::endl;

			highscore_manager.add_score(player_name, player_points);

			highscore_manager.order_score();

			highscore_manager.write_score_file("scores.dat");
		}
		break;

		case 3:	// Terminar

			finished = true;
			break;

		default:
			break;
		}

	}

	return 0;

}