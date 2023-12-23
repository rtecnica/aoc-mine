#include <inttypes.h>

#define MAX_GAMES 20

typedef struct bag {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} bag_t;

typedef struct game {
  uint32_t id;
  uint8_t num;
  bag_t sets[MAX_GAMES];
} game_t;

game_t parseGame(char* line);
uint8_t isGamePosible(bag_t* b, game_t* g);
void freeGame(game_t* g);
