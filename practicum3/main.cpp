#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>

using namespace std;

//declare genre array as a global 
char genre[148][32] = {"Blues", "Classic Rock", "Country", "Dance",
"Disco", "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal",
"New Age", "Oldies", "Other", "Pop", "R&B", "Rap", "Reggae", "Rock",
"Techno", "Industrial", "Alternative", "Ska", "Death Metal",
"Pranks", "Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop",
"Vocal", "Jazz+Funk", "Fusion", "Trance", "Classical",
"Instrumental", "Acid", "House", "Game", "Sound Clip", "Gospel",
"Noise", "Alternative Rock", "Bass", "Soul", "Punk", "Space",
"Meditative", "Instrumental Pop", "Instrumental Rock", "Ethnic",
"Gothic", "Darkwave", "Techno-Industrial", "Electronic", "Pop-Folk",
"Eurodance", "Dream", "Southern Rock", "Comedy", "Cult", "Gangsta",
"Top 40", "Christian Rap", "Pop/Funk", "Jungle", "Native American",
"Cabaret", "New Wave", "Psychadelic", "Rave", "Showtunes",
"Trailer", "Lo-Fi", "Tribal", "Acid Punk", "Acid Jazz", "Polka",
"Retro", "Musical", "Rock & Roll", "Hard Rock", "Folk", "Folk-Rock",
"National Folk", "Swing", "Fast Fusion", "Bebob", "Latin",
"Revival", "Celtic", "Bluegrass", "Avantgarde", "Gothic Rock",
"Progressive Rock", "Psychedelic Rock", "Symphonic Rock",
"Slow Rock", "Big Band", "Chorus", "Easy Listening", "Acoustic",
"Humour", "Speech", "Chanson", "Opera", "Chamber Music", "Sonata",
"Symphony", "Booty Bass", "Primus", "Porn Groove", "Satire",
"Slow Jam", "Club", "Tango", "Samba", "Folklore", "Ballad",
"Power Ballad", "Rhythmic Soul", "Freestyle", "Duet", "Punk Rock",
"Drum Solo", "Acapella", "Euro-House", "Dance Hall", "Goa",
"Drum & Bass", "Club-House", "Hardcore", "Terror", "Indie",
"BritPop", "Negerpunk", "Polsk Pumk", "Beat",
"Christian Gangsta Rap", "Heavy Metal", "Black Metal", "Crossover",
"Contemporary Christian", "Christian Rock", "Merengue", "Salsa",
"Thrash Metal", "Anime", "JPop", "Synthpop"};

struct mp3
{
    char header[3];
    char songTitle[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[29];
    char track;
    char genre;
};

void printTag(mp3 &);

int main(){

    char fname[128], comment[29], ch;
    fstream fs;
    mp3 tag;

    //redirrecting cerr stream to an error log file:
    fstream file1;
    file1.open("errorLog.txt", ios::out);
    string line;
 
    //streambuffer of cerr
    streambuf* stream_buffer_cerr = cerr.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file1 = file1.rdbuf();
    cerr.rdbuf(stream_buffer_file1);
 
    try{
    cout << "Enter an MP3 file: ";
    cin.getline(fname, 128, '\n');
    if(strcmp(&fname[strlen(fname)-4], ".mp3") != 0)
    {
        throw logic_error("File has to be an .mp3 file.");
    }
    fs.open(fname, ios::in | ios::out | ios::binary);
    if (!fs.is_open())
    {
        throw logic_error("Unable to open file.");
    }
    else
    {
        fs.seekg(-128, ios::end); //moving position 128 bytes from end
        
        fs.read(reinterpret_cast<char*>(&tag), 128);

        if(strncmp("TAG", tag.header, 3) != 0)
        {
            throw logic_error("Unknown tag.");
        }
        cerr << "File is OK with valid ID3v1.1 tag" << endl << endl;
        
        
        printTag(tag);
        
        char temp;
        cout << endl << "Do you wish to update the comment field (Y/N)? ";
        cin >> temp;

        if(toupper(temp) == 'Y'){
            cout << "Comment: ";
            cin.ignore();
            cin.getline(comment, 29, '\n'); //taking in the 29 characters in the comment

            fs.seekp(-31, ios::end);

            fs.write(comment, 29);

            cerr << "Comment updated" << endl << endl;

            fs.seekg(-31, ios::end);
            fs.read(reinterpret_cast<char*>(&tag.comment), 29);
        }
        printTag(tag);

    fs.close();
    }
    }
    catch(exception & ex)
    {
        cerr << ex.what() << endl;
    }

    //redirecting cerr back to the console
    cerr.rdbuf(stream_buffer_cerr);
 
    //closing cerr stream
    file1.close();

    return 0; 
}

void printTag(mp3 & tag)
{
    cout << "Title: ";
    for(int i = 0; i < 30; i++)
        cout << tag.songTitle[i];
    cout << endl;

    cout << "Artist: ";
    for(int i = 0; i < 30; i++)
        cout << tag.artist[i];
    cout << endl;

    cout << "Album: ";
    for(int i = 0; i < 30; i++)
        cout << tag.album[i];
    cout << endl;


    cout << "Year: ";
    for(int i = 0; i < 4; i++)
        cout << tag.year[i];
    cout << endl;

    cout << "Comment: ";
    for(int i = 0; i < 29; i++)
        cout << tag.comment[i];
    cout << endl;

    cout << "Track Number: " << int(tag.track) << endl;
    cout << "Genre: " << genre[int(tag.genre)] << endl;
}