Chapter 8 : Exercise 1.1 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Track
{
public:
   Track()
   {
      lengthInSeconds = 0.0f;
      trackName = "not set";
   }

   float lengthInSeconds;
   string trackName;
};


std::string TestCase() {
   
   Track track;

   out << "Track Name = " << track.trackName << endl;
   out << "Track Length = " << track.lengthInSeconds << endl;

   return out.str();
}

TEST(Chapter8, Exercise1.1) {

   EXPECT_EQ("Track Name = not set\nTrack Length = 0\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}







Chapter 8 : Exercise 1 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Track
{
public:

   Track(float lengthInSeconds, string trackName)
   {
      m_lengthInSeconds = lengthInSeconds;
      m_trackName = trackName;
   }

   float m_lengthInSeconds;
   string m_trackName;
};

std::string TestCase() {

   // create
   Track t(260.0f, "Still Alive");
   out << "My Favourite Song is: " << t.m_trackName << endl;
   // mess with it
   t.m_lengthInSeconds = 9405680394634.4895645f; // Song is now pretty much 300 millenia long!
   t.m_trackName = "S-Club Party"; // OH NO!!
   out << "My Favourite Song is: " << t.m_trackName;

   return out.str();
}

TEST(Chapter9, Exercise1) {

   EXPECT_EQ("My Favourite Song is: Still Alive\nMy Favourite Song is: S-Club Party", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}




Chapter 8 : Exercise 2 
#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
class Track
{
public:

   Track(float lengthInSeconds = 0.0f, string trackName = "not set")
   {
      m_lengthInSeconds = lengthInSeconds;
      m_trackName = trackName;
   }


   // m_ prefix added to member variables, to avoid naming conflicts with parameter names
   float m_lengthInSeconds;
   string m_trackName;
};

std::string TestCase() {
   Track track(200.0f, "Still Alive");

   Track track2 = track; // copy constructor is called

   out << "Track Name = " << track.m_trackName << endl;
   out << "Track Length = " << track.m_lengthInSeconds << endl;

   out << "Track Name = " << track2.m_trackName << endl;
   out << "Track Length = " << track2.m_lengthInSeconds << endl;

   return out.str();
}

TEST(Chapter8, Exercise2) {

   EXPECT_EQ("Track Name = Still Alive\nTrack Length = 200\nTrack Name = Still Alive\nTrack Length = 200\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 8 : Exercise 3
#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 

class Track
{
public:

   // added additional artist name constructor parameter
   Track(float lengthInSeconds = 0.0f, string trackName = "not set", string artistName = "not set", const char* data = NULL)
   {
      m_lengthInSeconds = lengthInSeconds;
      m_trackName = trackName;

      m_artistName = artistName;

      // create the sample clip from data
      m_dataSize = strlen(data);
      m_data = new char[m_dataSize + 1];
      strcpy(m_data, data);
   }

   Track(const Track& track)
   {
      // these can be shallow copied
      m_lengthInSeconds = track.m_lengthInSeconds;
      m_trackName = track.m_trackName;
      m_artistName = track.m_artistName;
      m_dataSize = track.m_dataSize;

      // allocate memory for the copied pointer
      m_data = new char[m_dataSize + 1];

      // copy the value from the old object
      strcpy(m_data, track.m_data);
   }

   ~Track()
   {
      delete[] m_data;
   }

   void SetData(float lengthInSeconds = 0.0f, string trackName = "not set", const char* newData = NULL)
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
   char* m_data;
};


std::string TestCase() {
   Track track(200.0f, "Still Alive", "GlaDos", "f651270d6011098375db09912b03e5e7");

   // copy the first track with the artist name
   Track track2 = track;

   // set the new needed data
   track2.SetData(300.0f, "Want You Gone", "db6fd7d74393b375344010a0c9cc4535");

   out << "Track 1" << endl;
   out << "Artist = " << track.m_artistName << endl;
   out << "Track Name = " << track.m_trackName << endl;
   out << "Track Length = " << track.m_lengthInSeconds << endl;
   out << "Track Data = " << track.m_data << endl;
   out << endl;
   out << "Track 2" << endl;
   out << "Artist = " << track2.m_artistName << endl;
   out << "Track Name = " << track2.m_trackName << endl;
   out << "Track Length = " << track2.m_lengthInSeconds << endl;
   out << "Track Data = " << track2.m_data << endl;

   return out.str();
}

TEST(Chapter8, Exercise3) {

   EXPECT_EQ("Track 1\nArtist = GlaDos\nTrack Name = Still Alive\nTrack Length = 200\nTrack Data = f651270d6011098375db09912b03e5e7\n\nTrack 2\nArtist = GlaDos\nTrack Name = Want You Gone\nTrack Length = 300\nTrack Data = db6fd7d74393b375344010a0c9cc4535\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 8 : Exercise 4

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <cstring>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 

class Track
{
public:
   // added additional artist name constructor parameter
   Track(float lengthInSeconds = 0.0f, string trackName = "not set", string artistName = "not set", const char* data = NULL)
   {
      m_lengthInSeconds = lengthInSeconds;
      m_trackName = trackName;

      m_artistName = artistName;

      // create the sample clip from data
      m_dataSize = strlen(data);
      m_data = new char[m_dataSize + 1];
      strcpy(m_data, data);
   }

   Track(const Track& track)
   {
      // these can be shallow copied
      m_lengthInSeconds = track.m_lengthInSeconds;
      m_trackName = track.m_trackName;
      m_artistName = track.m_artistName;
      m_dataSize = track.m_dataSize;

      // allocate memory for the copied pointer
      m_data = new char[m_dataSize + 1];

      // copy the value from the old object
      strcpy(m_data, track.m_data);
   }

   Track& operator=(const Track& track)
   {
      // check for self assignment
      if (this != &track)
      {
         // these can be shallow copied
         m_lengthInSeconds = track.m_lengthInSeconds;
         m_trackName = track.m_trackName;
         m_artistName = track.m_artistName;
         m_dataSize = track.m_dataSize;
         // allocate new memory and copy the existing data from the passed in object
         char* newData = new char[m_dataSize];
         strcpy(newData, track.m_data);
         // since this is an already existing object we must deallocate existing memory
         delete[] m_data;
         // assign the new data 
         m_data = newData;
      }

      return *this;
   }

   ~Track()
   {
      delete[] m_data;
   }

   void SetData(float lengthInSeconds = 0.0f, string trackName = "not set", const char* newData = NULL)
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
   char* m_data;
};


std::string TestCase() {
   Track track(200.0f, "Still Alive", "GlaDos", "f651270d6011098375db09912b03e5e7");

   // copy the first track with the artist name
   Track track2 = track;

   // set the new needed data
   track2.SetData(300.0f, "Want You Gone", "db6fd7d74393b375344010a0c9cc4535");

   track2 = track;

   out << "Track 1" << endl;
   out << "Artist = " << track.m_artistName << endl;
   out << "Track Name = " << track.m_trackName << endl;
   out << "Track Length = " << track.m_lengthInSeconds << endl;
   out << "Track Data = " << track.m_data << endl;
   out << endl;
   out << "Track 2" << endl;
   out << "Artist = " << track2.m_artistName << endl;
   out << "Track Name = " << track2.m_trackName << endl;
   out << "Track Length = " << track2.m_lengthInSeconds << endl;
   out << "Track Data = " << track2.m_data << endl;

   return out.str();
}

TEST(Chapter8, Exercise4) {

   EXPECT_EQ("Track 1\nArtist = GlaDos\nTrack Name = Still Alive\nTrack Length = 200\nTrack Data = f651270d6011098375db09912b03e5e7\n\nTrack 2\nArtist = GlaDos\nTrack Name = Want You Gone\nTrack Length = 300\nTrack Data = db6fd7d74393b375344010a0c9cc4535\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 8 : Activity 

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <cstring>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 


class VideoClip
{
public:

   VideoClip()
   {
      m_videoLength = 0;
      m_videoName = "NOT SET";
      m_dataLength = 0;
      m_data = 0;
   }

   VideoClip(float videoLength, string videoName, const char* data)
   {
      m_videoLength = videoLength;
      m_videoName = videoName;


      m_dataLength = strlen(data);
      m_data = new char[m_dataLength + 1];
      strcpy(m_data, data);
   }

   VideoClip(const VideoClip& vc)
   {
      m_videoLength = vc.m_videoLength;
      m_videoName = vc.m_videoName;
      m_dataLength = vc.m_dataLength;


      m_data = new char[m_dataLength + 1];
      strcpy(m_data, vc.m_data);
   }

   VideoClip& operator=(const VideoClip& rhs)
   {
      if (this != &rhs)
      {
         m_videoLength = rhs.m_videoLength;
         m_videoName = rhs.m_videoName;
         m_dataLength = rhs.m_dataLength;
         char* newData = new char[m_dataLength];
         strcpy(newData, rhs.m_data);

         delete[] m_data;
         m_data = newData;
      }
      return *this;
   }

   ~VideoClip()
   {
      delete[] m_data;
   }

   float m_videoLength;
   string m_videoName;

   int m_dataLength;
   char* m_data;

};

std::string TestCase() {
   VideoClip vc1(10.0f, "Halloween (2019)", "dfhdhfidghirhgkhrfkghfkg");
   VideoClip vc2(20.0f, "Halloween (1978)", "jkghdfjkhgjhgfjdfg");
   VideoClip vc3(50.0f, "The Shining", "kotriothgrngirgr");

   out << vc1.m_videoLength << " " << vc1.m_videoName << " " << vc1.m_data << endl;
   out << vc2.m_videoLength << " " << vc2.m_videoName << " " << vc2.m_data << endl;
   out << vc3.m_videoLength << " " << vc3.m_videoName << " " << vc3.m_data << endl;

   VideoClip vc4 = vc1;

   vc2 = vc4;

   out << vc1.m_videoLength << " " << vc1.m_videoName << " " << vc1.m_data << endl;
   out << vc2.m_videoLength << " " << vc2.m_videoName << " " << vc2.m_data << endl;
   out << vc3.m_videoLength << " " << vc3.m_videoName << " " << vc3.m_data << endl;
   out << vc4.m_videoLength << " " << vc4.m_videoName << " " << vc4.m_data << endl;

   return out.str();
}

TEST(Chapter8, Activity) {

   EXPECT_EQ("10 Halloween (2019) dfhdhfidghirhgkhrfkghfkg\n20 Halloween (1978) jkghdfjkhgjhgfjdfg\n50 The Shining kotriothgrngirgr\n10 Halloween (2019) dfhdhfidghirhgkhrfkghfkg\n10 Halloween (2019) dfhdhfidghirhgkhrfkghfkg\n50 The Shining kotriothgrngirgr\n10 Halloween (2019) dfhdhfidghirhgkhrfkghfkg", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
