class Playlist 
{ 
 public:   
    void AddTrack(const Track* track) 
    { 
        if(!any_of(m_tracks.begin(), m_tracks.end(), [&track](const Track* t){ return t->getName() == track->getName(); })) 
        { 
            m_tracks.push_back(track); 
            return;
        } 
        cout << "Track: " << track->getName() << " Not added as already exists in playlist"; 
    } 
 
    void RemoveTrack(const string trackName) 
    { 
        m_tracks.erase(remove_if(m_tracks.begin(), m_tracks.end(), 
        [&trackName](const Track* t){ return t->getName() == trackName; })); 
    } 
 
    void PrintTracks() const 
    {
        for (auto & track : m_tracks) 
        {
            // round seconds 
            int seconds = static_cast<int>(track->getLength()); 
            std:: cout << track->getName() << " - " << seconds / 60 << ":" << seconds % 60 << endl; 
        } 
    } 
    void SortAlphabetically(bool reverse) 
    { 
        if(reverse) 
        {
            sort(m_tracks.begin(), m_tracks.end(), CompareTrackNamesReverse); 
        } 
        else 
        {
            sort(m_tracks.begin(), m_tracks.end(), CompareTrackNames); \
        } 
    } 
    void SortByLength(bool reverse) 
    { 
        if(reverse) 
        { 
            sort(m_tracks.begin(), m_tracks.end(), CompareTrackLengthsReverse); 
        } 
        else 
        { 
            sort(m_tracks.begin(), m_tracks.end(), CompareTrackLengths); 
        } 
    }    
 private: 
    static bool CompareTrackNamesReverse(const Track* t1, const Track* t2) 
    { 
        return (t1->getName() > t2->getName()); 
    } 
    static bool CompareTrackNames(const Track* t1, const Track* t2) 
    { 
        return (t1->getName() < t2->getName()); 
    } 
    static bool CompareTrackLengthsReverse(const Track* t1, const Track* t2) 
    { 
        return (t1->getLength() > t2->getLength()); 
    } 
    static bool CompareTrackLengths(const Track* t1, const Track* t2) 
    { 
        return (t1->getLength() < t2->getLength()); 
    } 

    vector<const Track*> m_tracks; 
};
