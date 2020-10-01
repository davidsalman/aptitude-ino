// Under Pressure Game - Analog Pullup Input
#define UPG_GAME_INPUT_1 A5

// Under Pressure Game - Seven Segment Display Segment Pins
#define UPG_GAME_OUTPUT_SSD_P 3
#define UPG_GAME_OUTPUT_SSD_A 4
#define UPG_GAME_OUTPUT_SSD_B 6
#define UPG_GAME_OUTPUT_SSD_C 8
#define UPG_GAME_OUTPUT_SSD_D 10
#define UPG_GAME_OUTPUT_SSD_E 9
#define UPG_GAME_OUTPUT_SSD_F 5
#define UPG_GAME_OUTPUT_SSD_G 7

// Under Pressure Game - Seven Segment Display Digit Pins
#define UPG_GAME_OUTPUT_SSD_D1 2
#define UPG_GAME_OUTPUT_SSD_D2 11
#define UPG_GAME_OUTPUT_SSD_D3 12
#define UPG_GAME_OUTPUT_SSD_D4 13

// Under Pressure Game Class Usage:
#include "UnderPressureGame.h"
UnderPressureGame under_pressure_game = UnderPressureGame();
SevenSegmentDisplay *upg_ssd_display_ptr = new SevenSegmentDisplay();
byte upg_game_input = UPG_GAME_INPUT_1;
byte upg_game_ssd_output[12] = { UPG_GAME_OUTPUT_SSD_P, UPG_GAME_OUTPUT_SSD_A, UPG_GAME_OUTPUT_SSD_B, UPG_GAME_OUTPUT_SSD_C, UPG_GAME_OUTPUT_SSD_D, UPG_GAME_OUTPUT_SSD_E, UPG_GAME_OUTPUT_SSD_F, UPG_GAME_OUTPUT_SSD_G, UPG_GAME_OUTPUT_SSD_D1, UPG_GAME_OUTPUT_SSD_D2, UPG_GAME_OUTPUT_SSD_D3, UPG_GAME_OUTPUT_SSD_D4 };
  
// Under Pressure Game Initialization:
void setup()
{
  Serial.begin(57600);
  upg_ssd_display_ptr->init(upg_game_ssd_output);
  under_pressure_game.init(upg_game_input, upg_ssd_display_ptr);  
}

// Under Pressure Game Runtime:
void loop()
{
  under_pressure_game.execute();
}
