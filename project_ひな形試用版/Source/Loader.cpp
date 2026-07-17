#include "Loader.h"
#include "Notes.h"
#include "Player.h"

Loader::Loader()
{
	new Player();

	if (Load("data/chart.csv")) {
		for (int i = 0; i < noteCount; i++)
		{
			Common::NoteData& data = notes[i];
			Notes* n = new Notes(data.frame, data.lane);
		}
	}
}

Loader::~Loader()
{
}

void Loader::Update()
{
	DrawFormatString(0, 30, GetColor(255, 255, 255), "%d", noteCount);
}
