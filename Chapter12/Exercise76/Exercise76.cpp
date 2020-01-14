#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Track
{
public:
    Track(float length, string name, int popularity) : m_trackLength(length), 
    m_trackName(name), m_popularityRating(popularity) {}
    float getLength() const { return m_trackLength; }
    string getName() const { return m_trackName; }
    int getPopularity() const { return m_popularityRating; }
 
private:
    float m_trackLength;
    string m_trackName;
    int m_popularityRating;
};

bool trackLengthCompare(const Track& t1, const Track& t2)
{
    return (t1.getLength() < t2.getLength());
}

int main()
{ 
    vector<Track> tracks;
    
    tracks.push_back(Track(199.0f, "God's Plan", 100));
    tracks.push_back(Track(227.0f, "Hold On, We're Going Home", 95));
    tracks.push_back(Track(182.0f, "The Motto", 80));
    sort(tracks.begin(), tracks.end(), trackLengthCompare);
 
    for (auto t : tracks)
    {
        cout << t.getName() << endl;
    }
    
    return 0;
}
