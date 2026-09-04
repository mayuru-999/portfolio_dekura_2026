#pragma once
#include <string>
#include <windows.h>
#include <DxLib.h>
#include "Common.h"
using namespace std;

class SongLoader
{
public:
    Common::SongData songs[256];
    int songCount = 0;

    void Load() {
        songCount = 0;

        string base = "songs";
        string searchPath = base + "/*"; // 検索パスを作成 例: "data/songs/*.csv"

        WIN32_FIND_DATA findData;
        HANDLE hFind = FindFirstFile(searchPath.c_str(), &findData);
        if (hFind == INVALID_HANDLE_VALUE) return;

        do {
            // ディレクトリのみ取得
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) continue;

            // . と .. を除外
            string name = findData.cFileName;
            if (name == "." || name == "..") continue;

            Common::SongData s;
            s.name = name;
            s.csvPath = base + "/" + name + "/chart.csv";
            s.bgmPath = findBgm(base + "/" + name);
            s.songImage = findImage(base + "/" + name);

            songs[songCount++] = s;

        } while (FindNextFile(hFind, &findData) && songCount < 256);

        FindClose(hFind);
    }

    string findBgm(const string& folderPath) 
    {
        string path = folderPath + "/song.mp3";
        DWORD attr = GetFileAttributes(path.c_str());
        if (attr != INVALID_FILE_ATTRIBUTES)
            return path;

        return ""; // 見つからない場合
    }

    int findImage(const string& folderPath)
    {
        string path = folderPath + "/image.jpg";
        DWORD attr = GetFileAttributes(path.c_str());
        if (attr != INVALID_FILE_ATTRIBUTES)
            return LoadGraph(path.c_str());

        return -1; // 見つからない場合
    }
};