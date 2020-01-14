#include <iostream>
#include <string>

using namespace std;

class Track
{
    public:
    // m_ prefix added to member variables, to avoid naming conflicts with

    float m_lengthInSeconds;
    string m_trackName;
    Track(float lengthInSeconds, string trackName)
    {
        m_lengthInSeconds = lengthInSeconds;
        m_trackName = trackName;
    }
};

int main()
{
    Track track(200.0f, "Still Alive");
    cout << "Track Name = " << track.m_trackName << endl;
    cout << "Track Length = " << track.m_lengthInSeconds << endl;
    return 0;
}
