#include "Balloon.h"

// Constructor to initialize the balloon's attributes
Balloon::Balloon(float initialX, float initialY, int initialHealth, int initialReward)
    : x(initialX),
      y(initialY),
      health(initialHealth),
      reward(initialReward){
      }

// Getters
float Balloon::GetX() const {
    return x;
}

float Balloon::GetY() const {
    return y;
}

float Balloon::GetVelocityX() const {
    return velocity_x;
}

float Balloon::GetVelocityY() const {
    return velocity_y;
}

int Balloon::GetHealth() const {
    return health;
}

// Setters
void Balloon::SetX(float newX) {
    x = newX;
}

void Balloon::SetY(float newY) {
    y = newY;
}

void Balloon::SetVelocityX(float newVelocityX) {
    velocity_x = newVelocityX;
}

void Balloon::SetVelocityY(float newVelocityY) {
    velocity_y = newVelocityY;
}

void Balloon::SetHealth(int newHealth) {
    health = newHealth;
}

// Function to apply damage to the balloon
void Balloon::TakeDamage(int damage) {
    health -= damage;
}

// Function to check if the balloon is popped (health <= 0)
bool Balloon::IsPopped() {
    return health <= 0;
}
