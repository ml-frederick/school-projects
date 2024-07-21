/*
 * Name: Madeline Frederick     netID: mlf417
 * Date: 4/14/2022              Due Date: 4/17/2022
 *
 * Description: This program takes a playlist of songs and allows the user to sort by song,
 * shuffle, search by song, sort by artist, or search by artist.
 */

/***************************
    Binary search: used the lecture slides as a reference
    Selection sort: used the lecture slides as a reference
    Shuffle and swap: used geeksforgeeks.org to figure out how to generate random numbers
        and swap them.
 ***************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

#include "song.h"

using namespace std;

//given to you
void processFile(vector<Song> &playlist);

//you should create
void displayPlaylist(vector<Song> &playlist);
void shuffle(vector<Song> &playlist);
void swap(int *x, int *y);
int binarySearch(vector<Song> &playlist, string songTitle);
int binarySearchArtist(vector<Song> &playlist, string songTitle);

//add your own sort function
void selectionSort(vector<Song> &playlist);
void selectionSortArtist(vector<Song> &playlist);

int main()
{
    //declare variables
    vector<Song> playlist;
    string songTitle;
    int index;

    // sets up playlist
    processFile(playlist);

    cout << "\nInitial playlist: " << endl;
    displayPlaylist(playlist);

    cout << "Welcome to the playlist display manager." << endl << endl;

    //menuing
    while(1)
    {
        string option;

        //displays menu
        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Sort playlist by song" << endl;
        cout << "2. Shuffle playlist" << endl;
        cout << "3. Search playlist by song" << endl;
        cout << "4. Sort playlist by artist" << endl;
        cout << "5. Search playlist by artist" << endl;
        cout << "What would you like to do? ";
        cin >> option;

        //include cin.ignore() so you can start using getline
        cin.ignore();
        cout << endl;

        //menu handling
        //option 0 - exit
        if(option == "0")
        {
            cout << "Goodbye!" << endl;
            break;
        }

        //option 1 - sort playlist by song
        else if(option == "1")
        {
            selectionSort(playlist);
            displayPlaylist(playlist);
        }

        //option 2 - shuffle playlist
        else if(option == "2")
        {
            shuffle(playlist);
            displayPlaylist(playlist);
        }

        //option 3 - search playlist by song
        else if(option == "3")
        {
            //display warning to user
            cout << "WARNING: playlist must be sorted to give proper output." << endl;

            //get input from user
            cout << "Which song are you searching for?" << endl;
            getline(cin, songTitle);
            cout << endl;

            //use binary search to determine whether the song is in the vector
            index = binarySearch(playlist, songTitle);

            //song is NOT in vector
            if(index == -1)
            {
                cout << "Your song was not found." << endl;
            }

            //song IS in vector, tell user where
            else
            {
                cout << "Your song was found at index " << index << "." << endl;
            }
        }

        //option 4 - sort by artist
        else if(option == "4")
        {
            selectionSortArtist(playlist);
            displayPlaylist(playlist);
        }

        //option 5 - search by artist
        else if(option == "5")
        {
            //display warning to user
            cout << "WARNING: playlist must be sorted to give proper output." << endl;

            //get input from user
            cout << "Which artist are you searching for?" << endl;
            getline(cin, songTitle);
            cout << endl;

            //use binary search to determine whether the artist is in the vector
            index = binarySearchArtist(playlist, songTitle);

            //artist is NOT in vector
            if(index == -1)
            {
                cout << "Your artist was not found." << endl;
            }

            //song IS in vector, tell user where
            else
            {
                cout << "Your artist was found at index " << index << "." << endl;
            }
        }

        //incorrect menu option
        else
        {
            cout << "Invalid menu option. Please try again." << endl << endl;
        }
    }

    return 0;
}

void processFile(vector<Song> &playlist)
{
    ifstream infile;
    string line;

    infile.open("songs.txt");

    if(infile.is_open())
    {
        cout << "Successful songs opening." << endl;
    }

    else
    {
        cout << "Couldn't locate file. Program closing." << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(infile, line))
    {
        // first line --> song
        // second line --> artist

        if(line != "")
        {
            string song, artist;

            song = line;

            getline(infile, artist);

            Song temp(song, artist);

            playlist.push_back(temp);
        }
    }

    return;
}

void displayPlaylist(vector<Song> &playlist)
{
    //display the songs and artists in playlist
    for(int i = 0; i < playlist.size(); i++)
    {
        cout << playlist[i].getTitle() << " - " << playlist[i].getArtist() << endl;
    }
    cout << endl;
}

void shuffle(vector<Song> &playlist)
{
    //generate random number using srand()
    srand(time(NULL));
    //swap elements one by one starting with last element
    for(int i = playlist.size() - 1; i > 0; i--)
    {
        int randomNum = rand() % (playlist.size());
        //swap playlist[i] with a random index in playlist[randomNum]
        //use swap function
        swap(playlist[i], playlist[randomNum]);
    }
    return;
}

void swap(int *x, int *y)
{
    //swaps integers, goes with shuffle function
    int temp = *x;
    *x = *y;
    *y = temp;
}

int binarySearch(vector<Song> &playlist, string songTitle)
{
    int low = 0, high = playlist.size() - 1, mid;

    while(high >= low)
    {
        mid = (high + low) / 2;

        //if item being searched is greater than mid
        if(playlist[mid].getTitle() < songTitle)
        {
            //sets new low to mid + 1
            low = mid + 1;
        }

        //if item being searched is less than mid
        else if(playlist[mid].getTitle() > songTitle)
        {
            //sets new high to mid - 1
            high = mid - 1;
        }

        //found
        else
        {
            return mid;
        }
    }
    //not found
    return -1;
}

int binarySearchArtist(vector<Song> &playlist, string songTitle)
{
    int low = 0, high = playlist.size() - 1, mid;

    while(high >= low)
    {
        mid = (high + low) / 2;

        //if item being searched is greater than mid
        if(playlist[mid].getArtist() < songTitle)
        {
            //sets new low to mid + 1
            low = mid + 1;
        }

        //if item being searched is less than mid
        else if(playlist[mid].getArtist() > songTitle)
        {
            //sets new high to mid - 1
            high = mid - 1;
        }

        //found
        else
        {
            return mid;
        }
    }
    //not found
    return -1;
}

void selectionSort(vector<Song> &playlist)
{
    for(int i = 0; i < (playlist.size() - 1); i++)
    {
        int smallIndex = i;

        for(int j = i + 1; j < playlist.size(); j++)
        {
            if(playlist[j].getTitle() < playlist[smallIndex].getTitle())
            {
                smallIndex = j;
            }
        }

        //swap small number with current number
        Song temp = playlist[i];
        playlist[i] = playlist[smallIndex];
        playlist[smallIndex] = temp;
    }
}

void selectionSortArtist(vector<Song> &playlist)
{
    for(int i = 0; i < (playlist.size() - 1); i++)
    {
        int smallIndex = i;

        for(int j = i + 1; j < playlist.size(); j++)
        {
            if(playlist[j].getArtist() < playlist[smallIndex].getArtist())
            {
                smallIndex = j;
            }
        }

        //swap small number with current number
        Song temp = playlist[i];
        playlist[i] = playlist[smallIndex];
        playlist[smallIndex] = temp;
    }
}
