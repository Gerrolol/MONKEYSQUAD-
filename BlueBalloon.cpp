#include "BlueBalloon.h"

BlueBalloon::BlueBalloon(float initialX, float initialY, int initialHealth, int initialreward)
    : Balloon(initialX, initialY, initialHealth, initialreward) {
    this->HasTurnedRed = false;
    this->BlueValue = initialreward*2;
}

void BlueBalloon::SetVelocityX(float newVelocityX){
    this->Blue_VelocityX = newVelocityX;
}

void BlueBalloon::SetVelocityY(float newVelocityY){
    this->Blue_VelocityY = newVelocityY;
}

void BlueBalloon::TakeDamage(int damage) {
    // Check if the balloon hasn't turned red and its health is dropping to zero
    if (!HasTurnedRed && (health - damage) <= 0) {
        // Create a RedBalloon object with the same attributes
        RedBalloon redBalloon(x, y, health);
        // Optionally, you can do something with the redBalloon object, like adding it to a collection.
        
        // Set the flag to indicate that this balloon has turned red
        HasTurnedRed = true;
    }

    // Call the base class TakeDamage method to update health
    Balloon::TakeDamage(damage);
}




