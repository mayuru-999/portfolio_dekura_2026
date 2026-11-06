#include "Loader.h"
#include "Notes.h"
#include "Player.h"
#include "Common.h"
#include "Screen.h"
#include "UiElements.h"

Loader::Loader()
{
	ClearDrawScreen();
	new Player();
	Common c;
	Common::SongData& s = SceneManager::selectedMusic;

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

		isLoaded = true;
		startTime = GetNowCount();
	}
}

Loader::~Loader()
{
	InitSoundMem();
}

void Loader::Update()
{
	if (!isLoaded) return;
	if (gameEnded) {
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			SceneManager::ChangeScene("TITLE");
		}
		return;
	}

	Common c;

	// 曲の再生開始ディレイ
	if (GetNowCount() - startTime >= c.startDiray * 1000 && !isPlayed) {
		PlaySoundMem(music, DX_PLAYTYPE_BACK);
		isPlayed = true;
	}

	// 曲の再生時間を取得
	musicTime = (float)(GetSoundCurrentTime(music)) / 1000.0f;

	// 曲終了時処理
	float songTime = GetMusicTime();
	if (songTime >= gameEnd && !gameEnded)
	{
		volume = max(volume - 5, 0);
		ChangeVolumeSoundMem(volume, music);

		if (volume <= 0)
		{
			printfDx("Loader: 曲終了\n");

			StopSoundMem(music);
			gameEnded = true;

			new UiResult(100, 100, 400, 600, 0x000000, 2);
		}
	}

	// デバッグモードの切り替えによる音楽の一時停止・再開
	if (isPlayed && !gameEnded) {
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
	int lineNumber = 0;
	while (getline(file, line))	//getline(元データ、格納先、区切る文字)
	{
		lineNumber++;

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

		try
		{
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
		catch (const std::invalid_argument& e)
		{
			printfDx("ChartLoader: 失敗 LINE/%d [%s]\n", lineNumber, ss.str());
		}
	}

	gameEnd = notes[noteCount-1].timing;
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
