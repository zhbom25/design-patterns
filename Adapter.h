//
// Created by zhaobo on 2022/3/17.
//
// 适配器

#ifndef DESIGNPATTERN_ADAPTER_H
#define DESIGNPATTERN_ADAPTER_H

#include "Helper.h"

class MediaPlayer {
public:
    virtual void play(const string& audioType, const string fileName) {}
};

class AdvancedMediaPlayer {
public:
    virtual void playVlc(const string& fileName) {}
    virtual void playMp4(const string& fileName) {}
};

class VlcPlayer : public AdvancedMediaPlayer {
public:
    void playVlc(const string& fileName) {
        cout << "Playing vlc file. Name: " << fileName << endl;
    }
    void playMp4(const string& fileName) {
    }
};

class Mp4Player : public AdvancedMediaPlayer {
public:
    void playVlc(const string& fileName) {
    }
    void playMp4(const string& fileName) {
        cout << "Playing mp4 file. Name: " << fileName << endl;
    }
};

class MediaAdapter : public MediaPlayer {
private:
    AdvancedMediaPlayer* advancedMusicPlayer = nullptr;

public:
    MediaAdapter(const string& audioType) {
        if (audioType == "vlc") {
            advancedMusicPlayer = new VlcPlayer();
        } else if (audioType == "mp4") {
            advancedMusicPlayer = new Mp4Player();
        }
    }
    void play(const string& audioType, const string& fileName) {
        if(audioType == "vlc"){
            advancedMusicPlayer->playVlc(fileName);
        } else if (audioType == "mp4"){
            advancedMusicPlayer->playMp4(fileName);
        }
    }
};

class AudioPlayer : public MediaPlayer {
private:
    MediaAdapter* mediaAdapter = nullptr;
public:
    void play(const string& audioType, const string& fileName) {
        //播放 mp3 音乐文件的内置支持
        if (audioType == "mp3") {
            cout << "Playing mp3 file. Name: " << fileName << endl;
        }
            //mediaAdapter 提供了播放其他文件格式的支持
        else if (audioType == "vlc" || audioType == "mp4") {
            mediaAdapter = new MediaAdapter(audioType);
            mediaAdapter->play(audioType, fileName);
        } else {
            cout << "Invalid media. " << audioType << " format not supported" << endl;
        }
    }
};

#endif //DESIGNPATTERN_ADAPTER_H
