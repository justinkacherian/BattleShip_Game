#include "enemy.h"
#include "tiger.h"
#include "drone.h"
#include "robot.h"
#include <stdlib.h>
#include <ctime>

int main()
{
	const int max_enemy = 3;
	Enemy* enemy_ptr[max_enemy];
	int num_enemy = 3;
	int num_of_games = 5; //number of rounds in the game

	Tiger t1(100, 500, 2, "left");
	Drone d1(300, 100, 7, "right", 7); //create objects with dummy variables
	Robot r1(400, 500, 4, "left", 10);

	Tiger* t = &t1;
	Drone* d = &d1; //create pointers
	Robot* r = &r1;

	enemy_ptr[0] = t;
	enemy_ptr[1] = d;
	enemy_ptr[2] = r;

	srand((unsigned)time(0));
	
	for (int i = 0; i < num_of_games; i++){

		cout << "ROUND " << i + 1 << '\n' << "----------- \n";

		for (int i = 0; i < num_enemy; i++)
			enemy_ptr[i]->move_position(); // every enemy object should move positions

		cout << endl;

		int random_num = rand() % num_enemy; // random number generator to determine which object attacks
		enemy_ptr[random_num]->fire_weapon();

		cout << endl;

		int random_num_2 = rand() % num_enemy; // random number generator to determine which object to update status
		while(random_num_2 == random_num)		
			random_num_2 = rand() % num_enemy; //make sure the enemy that fired its weapon is not the same one to get hit

		enemy_ptr[random_num_2]->update_status(); 

		cout << endl << endl;
	
	}	

	return 0;
}