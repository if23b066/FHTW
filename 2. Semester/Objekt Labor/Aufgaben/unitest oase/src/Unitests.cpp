#include "catch_amalgamated.hpp"
#include "Unitests.hpp"
#include "Player.h"
#include "World.h"
#include "Enemy.h"

TEST_CASE("Player movement within bounds", "[player]") {
    Player player(2, 2);

    player.move('w'); // Move up
    REQUIRE(player.y == 1);
    REQUIRE(player.x == 2);

    player.move('a'); // Move left
    REQUIRE(player.y == 1);
    REQUIRE(player.x == 1);

    player.move('s'); // Move down
    REQUIRE(player.y == 2);
    REQUIRE(player.x == 1);

    player.move('d'); // Move right
    REQUIRE(player.y == 2);
    REQUIRE(player.x == 2);

    player.move('w'); // Move up
    player.move('w'); // Move up
    REQUIRE(player.y == 0);

    player.move('a'); // Move left
    player.move('a'); // Move left
    REQUIRE(player.x == 0);
}

TEST_CASE("World generation contains at least one relic", "[world]") {
    World world;
    world.generateWorld();

    int relicsCount = 0;
    int emptyCount = 0;
    int dangerCount = 0;
    int healingCount = 0;

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            switch(world.world[y][x]) {
                case 'R': relicsCount++; break;
                case '_': emptyCount++; break;
                case 'G': dangerCount++; break;
                case 'B': healingCount++; break;
            }
        }
    }

    REQUIRE(relicsCount > 0);
    REQUIRE(emptyCount + dangerCount + healingCount + relicsCount == 25);
}

TEST_CASE("Player interaction with world elements", "[player][world]") {
    World world;
    world.generateWorld();
    Player player(0, 0);
    Enemy enemy;

    world.world[1][0] = 'G';
    world.world[2][0] = 'B';
    world.world[3][0] = 'R';

    player.move('s'); // Move to danger field
    player.activeField(&world, &enemy);
    REQUIRE(player.hp <= 5);

    int hpAfterDanger = player.hp;
    player.move('s'); // Move to healing field
    player.activeField(&world, &enemy);
    REQUIRE(player.hp == hpAfterDanger);

    player.move('s'); // Move to relic field
    player.activeField(&world, &enemy);
    REQUIRE(player.colRelics == 1);
    REQUIRE(world.relics == 1);
}

TEST_CASE("Player reset to initial position and stats", "[player]") {
    Player player(3, 3);

    player.move('w');
    player.hp = 5;
    player.resetPlayer();

    REQUIRE(player.x == 0);
    REQUIRE(player.y == 0);
    REQUIRE(player.hp == 5);
}
