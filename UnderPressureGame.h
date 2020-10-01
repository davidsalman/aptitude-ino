/*
 * UnderPressureGame class is a Arduno game inheriting its properties from the Game super class.
 * Goal of this game is to maintain a consitent grip pressure on the potentiometer for a period of time.
 */

#ifndef _UnderPressureGame_h
#define _UnderPressureGame_h

#include "Game.h"
#include "SevenSegmentDisplay.h"

class UnderPressureGame : public Game 
{
  private:
    byte analog_input;
    float avg_val;
    float update_weight;
    float prev_weight;
    SevenSegmentDisplay *ssd_display_ptr;
    int get_smooth_pressure_read();
  public:
    UnderPressureGame() : Game() { 
      avg_val = 1023; 
      update_weight = 0.001; 
      prev_weight = 1.0 - update_weight;
    };
    void init(byte analog_input_pin, SevenSegmentDisplay *ssd_ptr);
    void execute();
};

extern UnderPressureGame;

#endif
