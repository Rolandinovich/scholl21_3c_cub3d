#include "game/game.h"

int main(int argc, char **argv) {
    t_data data;

    argc++;
	make_map(argv[1], &data);
    return 0;
}
