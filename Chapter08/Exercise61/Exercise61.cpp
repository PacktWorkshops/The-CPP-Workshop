#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Track
{
public:
    // added additional artist name constructor parameter 
    Track(float lengthInSeconds = 0.0f, string trackName = "not set", string artistName = "not set", const char * data = NULL)
    {
    m_lengthInSeconds = lengthInSeconds;
    m_trackName = trackName;
    m_artistName = artistName;
      
    // create the sample clip from data 
    m_dataSize = strlen(data);
    m_data = new char[m_dataSize + 1];
    strcpy(m_data, data);
  }
  
  ~Track()
  {
    delete[] m_data;
  }
  Track & operator = (const Track & track) 
  {
      // check for self assignment
      if (this != & track) 
      {
          // these can be shallow copied
          m_lengthInSeconds = track.m_lengthInSeconds;
          m_trackName = track.m_trackName;
          m_artistName = track.m_artistName;
          m_dataSize = track.m_dataSize;
          
          // allocate new memory and copy the existing data from the passed in object
          char * newData = new char[m_dataSize];
          strcpy(newData, track.m_data);
          
          // since this is an already existing object we must deallocate existing memory
          delete[] m_data;
          
          // assign the new data
          m_data = newData;
      }
      return *this;
  }
  
  void SetData(float lengthInSeconds = 0.0f, string trackName = "not set", const char * newData = NULL)
  {
       m_lengthInSeconds = lengthInSeconds;
       m_trackName = trackName;
       
       // delete the array so it can be recreated 
       delete[] m_data;
    
       // create the sample clip from data 
       m_dataSize = strlen(newData);
       m_data = new char[m_dataSize + 1];
       strcpy(m_data, newData);
  }

  // m_ prefix added to member variables, to avoid naming conflicts with parameter names 
  float m_lengthInSeconds;
  string m_trackName;

  // additional artist name string member variable 
  string m_artistName;

  // sample clip data 
  int m_dataSize;
  char * m_data;
    
};

void PrintTrackName(Track track) 
{
    cout << "Track Name = " << track.m_trackName << endl;
}

int main() 
{
    Track track(200.0f, "Still Alive", "GlaDos","f651270d6011098375db09912b03e5e7");
    PrintTrackName(track);
    
    // construct another track with new values
    Track track2(300.0f, "Want You Gone", "GlaDos", "db6fd7d74393b375344010a0c9cc4535");
    
    // here the assignment operator is called
    track2 = track;

    // set the new needed data
    track2.SetData(300.0f, "Want You Gone", "db6fd7d74393b375344010a0c9cc4535");
    cout << "Track 1" << endl;
    cout << "Artist = " << track.m_artistName << endl;
    cout << "Track Name = " << track.m_trackName << endl;
    cout << "Track Length = " << track.m_lengthInSeconds << endl;
    cout << "Track Data = " << track.m_data << endl;
    cout << endl;
    cout << "Track 2" << endl;
    cout << "Artist = " << track2.m_artistName << endl;
    cout << "Track Name = " << track2.m_trackName << endl;
    cout << "Track Length = " << track2.m_lengthInSeconds << endl;
    cout << "Track Data = " << track2.m_data << endl;
  
    return 0;
}
