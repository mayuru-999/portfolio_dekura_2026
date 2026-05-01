#include "pre_game.h"
#include "Player.h"
#include "Notes.h"

pre_game::pre_game()
{
	count = 0;
	new Player();
	new Notes(423, 0, 1);
	new Notes(423, -100, 1);
	new Notes(423, -200, 1);
	new Notes(423, -300, 1);
	new Notes(423, -400, 1);
}

pre_game::pre_game(int level)
{
	new Player();
}

pre_game::~pre_game()
{
}

void pre_game::Update()
{
	count--;
	if (count <= -100) {
		new Notes(423, -100, 1);
		count = 0;
	}
}

void pre_game::Draw()
{
}
