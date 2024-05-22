#include <iostream>
#include <string>
using namespace std;

class CDevice {
protected:
    string manufacturer;
    int year;

public:
    CDevice() : manufacturer("Unknown"), year(0) {}
    CDevice(const string& man, int y) : manufacturer(man), year(y) {}
    virtual ~CDevice() {}

    virtual void play() const {
        cout << "Playing from device" << endl;
    }

    void setManufacturer(const string& man) { manufacturer = man; }
    void setYear(int y) { year = y; }
    string getManufacturer() const { return manufacturer; }
    int getYear() const { return year; }

    CDevice& operator=(const CDevice& other) {
        if (this != &other) {
            manufacturer = other.manufacturer;
            year = other.year;
        }
        return *this;
    }
};

class CAudioPlayer : virtual public CDevice {
private:
    int bitRate;

public:
    CAudioPlayer() : CDevice(), bitRate(0) {}
    CAudioPlayer(const string& man, int y, int br) : CDevice(man, y), bitRate(br) {}

    void setBitRate(int br) { bitRate = br; }
    int getBitRate() const { return bitRate; }

    void play() const override {
        cout << "Playing audio from audio player" << endl;
    }

    void stop() const {
        cout << "Stopping audio from audio player" << endl;
    }

    void pause() const {
        cout << "Pausing audio from audio player" << endl;
    }

    void rewind() const {
        cout << "Rewinding audio from audio player" << endl;
    }
};

class CVideoPlayer : virtual public CDevice {
private:
    int resolution;

public:
    CVideoPlayer() : CDevice(), resolution(0) {}
    CVideoPlayer(const string& man, int y, int res) : CDevice(man, y), resolution(res) {}

    void setResolution(int res) { resolution = res; }
    int getResolution() const { return resolution; }

    void play() const override {
        cout << "Playing video from video player" << endl;
    }

    void stop() const {
        cout << "Stopping video from video player" << endl;
    }

    void pause() const {
        cout << "Pausing video from video player" << endl;
    }

    void forward() const {
        cout << "Forwarding video from video player" << endl;
    }
};

class CAudioVideoPlayer : public CAudioPlayer, public CVideoPlayer {
public:
    CAudioVideoPlayer() : CDevice(), CAudioPlayer(), CVideoPlayer() {}
    CAudioVideoPlayer(const string& man, int y, int br, int res) : CDevice(man, y), CAudioPlayer(man, y, br), CVideoPlayer(man, y, res) {}

    void play() const override {
        cout << "Playing audio and video from audio-video player" << endl;
    }

    void stop() const {
        cout << "Stopping audio and video from audio-video player" << endl;
    }

    void pause() const {
        cout << "Pausing audio and video from audio-video player" << endl;
    }

    void forward() const {
        cout << "Forwarding audio and video from audio-video player" << endl;
    }
};

int main() {
    CAudioVideoPlayer avPlayer("Sony", 2022, 320, 1080);
    avPlayer.play();  // Calls overridden method in CAudioVideoPlayer

    return 0;
}
