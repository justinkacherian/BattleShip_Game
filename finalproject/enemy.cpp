#include "enemy.h"

//constructor
Enemy::Enemy(int x, int y, int s, string m) {
	x_position = x;
	y_position = y;
	status = s;
	movement = m;
}

//setters

void Enemy::set_x_position(int x) {
	x_position = x;
}

void Enemy::set_y_position(int y) {
	y_position = y;
}

void Enemy::set_width(int w) {
	width = w;
}

void Enemy::set_height(int h) {
	height = h;
}

void Enemy::set_status(int s) {
	status = s;
}

void Enemy::set_movement(string m) {
	movement = m;
}

//getters

int Enemy::get_x_position(){
	return x_position;
}

int Enemy::get_y_position() {
	return y_position;
}

int Enemy::get_width() {
	return width;
}

int Enemy::get_height() {
	return height;
}

int Enemy::get_status() {
	return status;
}

string Enemy::get_movement() {
	return movement;
}