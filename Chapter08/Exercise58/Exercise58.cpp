#include <iostream>
#include <string>

using namespace std;

class Track
{
  public:
    float lengthInSeconds;
    string trackName;
    Track ()
    {
        lengthInSeconds = 0.0f; 
        trackName = "not set"; 
    }
};

int main()
{
    Track track;
    cout << "Track Name = " << track.trackName << endl;
    cout << "Track Length = " << track.lengthInSeconds << endl;
    return 0;
}

