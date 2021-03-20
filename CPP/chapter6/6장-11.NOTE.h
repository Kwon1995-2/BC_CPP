// 6¿Â-11.NOTE.H

class Note{
    class NoteImpl * ni;
public:
    Note (int pitch, int duration);
    ~Note ();
    void Sound ();
    void Increase (int delta);
    void Modulate (int cicles);
} ;