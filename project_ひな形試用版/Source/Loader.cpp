#include "Loader.h"
#include "Notes.h"
#include "Player.h"
#include "Common.h"
#include "Screen.h"

Loader::Loader()
{
	new Player();
	Common c;
	Common::SongData& s = SceneManager::selectedMusic;
	startTime = GetNowCount();

	/*char filename[60];
	sprintf_s<60>(filename, "songs/stage/Target/Stage_%d.csv", id);
	const char* path = "songs/chart.csv";*/

	const char* csvPath = s.csvPath.c_str();//"songs/test_01/chart.csv";
	const char* bgmPath = s.bgmPath.c_str();//"songs/test_01/song.mp3";

	if (Load(csvPath)) {
		for (int i = 0; i < noteCount; i++)
		{
			Common::NoteData& data = notes[i];
			Notes* n = new Notes(data.lane, data.timing);
		}
		c.HitScore[c.Excellent] = c.maxScore / (float)noteCount;
		c.HitScore[c.Good] = c.HitScore[c.Excellent] * 0.8;
		c.HitScore[c.Hit] = c.HitScore[c.Excellent] * 0.5;

		music = LoadSoundMem(bgmPath);
		ChangeVolumeSoundMem(g.musicVolume, music);
	}
}

Loader::~Loader()
{
	InitSoundMem();
}

void Loader::Update()
{
	Common c;
	if (GetNowCount() - startTime >= c.startDiray * 1000 && !isPlayed) {
		PlaySoundMem(music, DX_PLAYTYPE_BACK);
		isPlayed = true;
	}

	musicTime = (float)(GetSoundCurrentTime(music)) / 1000.0f;

	//printfDx(
	//   "music = %d \n",
	//	CheckSoundMem(music)
	//);
	//printfDx(
	//	"GetSoundCurrentTime = %.2lf \n",
	//	(float)(GetSoundCurrentTime(music)) / 1000.0f
	//);

	if (isPlayed) {
		if (beforeDebugMode != g.debugMode)
		{
			if (g.debugMode) ChangeMusicStatus("pause");
			else ChangeMusicStatus("resume");
		}

		beforeDebugMode = g.debugMode;
	}
}

bool Loader::Load(const char* path)
{
	ifstream file(path);
	if (!file.is_open()) return false;

	string line;
	while (getline(file, line))	//getline(元データ、格納先、区切る文字)
	{
		if (line.empty() || line[0] == '#') continue; //空白行はスキップ

		istringstream ss(line); //行にあるやつ全部格納
		string token;
		string tokens[5];
		int count = 0;

		while (getline(ss, token, ',') && count <= 4)
		{
			tokens[count++] = token;
		}

		if (tokens[0] == "BPM")
		{
			bpm = stof(tokens[1]);
			continue;
		}
		if (tokens[0] == "BEAT")
		{
			beatNum = stof(tokens[1]);
			beatDen = stof(tokens[2]);
			continue;
		}

		Common::NoteData n;
		n.measure = stoi(tokens[0]);
		n.beat = stoi(tokens[1]);
		n.sub = stoi(tokens[2]);
		n.lane = stoi(tokens[3]) - 1;

		float secBeat = Screen::FRAME_RATE / bpm;
		float subFrac = (float)n.sub / 4.0;
		float tgSec = ((n.measure - 1) * beatNum + (n.beat - 1) + subFrac) * secBeat;

		n.timing = tgSec;

		notes[noteCount++] = n;
	}
	return true;
}

void Loader::ChangeMusicStatus(const char* mode)
{
	if (mode == "pause")  StopSoundMem(music);
	if (mode == "resume") PlaySoundMem(music, DX_PLAYTYPE_BACK, FALSE);
}

float Loader::GetMusicTime() const
{
	Common c;
	if (!isPlayed) {
		return (GetNowCount() - startTime) / 1000.0f - c.startDiray;
	}
	return musicTime;
}
