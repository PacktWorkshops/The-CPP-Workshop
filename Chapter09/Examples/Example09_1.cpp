#include <iostream>
#include <string>

using namespace std;

class Track 
{
public:
    // declare a constant value for maximum track length 
    const float MAX_TRACK_LENGTH = 600.0 f;

    Track(float lengthInSeconds, string trackName) 
    {
        m_lengthInSeconds = lengthInSeconds;
        m_trackName = trackName;
    }

    float getLength() 
    {
        return m_lengthInSeconds;
    }

    string getName() 
    {
        return m_trackName;
    }

    void setName(string newTrackName) 
    {
        // if S-Club is not found set the track name - otherwise do nothing 
        if (newTrackName.find("S-Club") == string::npos) 
        {
            m_trackName = newTrackName;
         }
    }

    void setLength(float newTrackLength) 
    {
        if (newTrackLength < MAX_TRACK_LENGTH && newTrackLength > 0) 
        // no prog metal for us! 
        {
            m_lengthInSeconds = newTrackLength;
        }
    }

private:
    float m_lengthInSeconds;
    string m_trackName;
};

int main() {
    // create 
    Track t(260.0 f, "Still Alive");

    cout << "My Favourite Song is: " << t.getName() << endl;
    cout << "It is :" << t.getLength() / 60.0 f << " minutes long" << endl;

    t.setName("S-Club Party"); // this again! 
    t.setLength(315576000000.0 f); // 10 milennia 

    cout << "My Favourite Song is: " << t.getName() << endl;
    cout << "It is :" << t.getLength() / 60.0 f << " minutes long";

    return 0;
}
