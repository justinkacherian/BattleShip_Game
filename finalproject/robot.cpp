#include "robot.h"

//constructor passing arguments to base class constructor
Robot::Robot(int x, int y, int s, string m, int l) : Enemy(x, y, s, m)
{
	num_of_lasers = l;
};

void Robot::move_position()
{
	cout << "Robot move to: ";

	if (get_status() > 0)
	{
		const int speed = 3;

		if ((get_movement() == "left" && get_x_position() - speed ) < 0) //make sure robot within coordinates
			set_movement("right");

		if ((get_movement() == "right" && get_x_position() + speed) > 800)
			set_movement("left");

		if (get_movement() == "left")
			set_x_position(get_x_position() - speed); //set new coordinates

		if (get_movement() == "right")
			set_x_position(get_x_position() + speed);

		cout << "(" << get_x_position() << "," << get_y_position() << ") ";
	}
	else
		cout << "Drone is dead...";

}

void Robot::fire_weapon()
{
	cout << "Robot fire weapon: ";

	if (get_status() && num_of_lasers > 0)
	{
		num_of_lasers -= 1;
		cout << "laser " << "(" << num_of_lasers << " left)";
	}

	if (get_status() == 0)
		cout << "No weapon fired, robot is dead";

	if (num_of_lasers == 0)
		cout << "No weapon fired, not enough ammo";
}

void Robot::update_status()
{
	cout << "Robot update status: ";

	if (get_status() > 0) {
		set_status(get_status() - 1);
		cout << "Robot has been hit. (Pew...) " << "status points " << get_status();
	}

	else
		cout << "Robot is dead...";
}