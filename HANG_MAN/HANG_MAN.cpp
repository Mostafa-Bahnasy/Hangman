// HANG_MAN GAME
#include <iostream>
#include<bits-stdc++.h>
#include<Windows.h>
#include<string>
#include<vector>
using namespace std;

//---------------------------------------------CATEGORIES----------------------------------------------------------
vector<string>comp = {"computer","monitor","mouse","keyboard","mobile","charger","wifi","windows","microsoft"};//9
vector<string>country = { "egypt","angola","jaban","brazil","canada","france","germany","india","iraq","china" };//10
vector<string>anim = { "naruto","ichigo","levi","sitama","nezuku","lite","luffy","jojo","hinata","dazai" };//10
vector<string>furn = { "chair","table","bed","sofa","bookshelf","clock","fan","mirror","remote" };//9
//-----------------------------------------------------------------------------------------------------------------

//-------------------------------FUNCTIONS---------------------------
bool COMPUTER_TEST(string temp);

bool ANIME_TEST(string temp);

bool FURNATURE_TEST(string temp);

bool COUNTRIES_TEST(string temp);

bool CLOSE_TEST(string temp);

void game(string win);

int randomi(int si);

string check_char(string win, string player, char ch);
//--------------------------------------------------------------------

int main()
{

    cout << "\t\tWELCOME TO HANGMAN GAME\n"; Sleep(750);

    cout << "\t       HOPE YOU ENJOY PLAYING IT\n"; Sleep(1000);

    while (true) {
        
        string tybe;
        
        cout << "\tPLEASE, CHOOSE ONE OF CATEGORIES WRITTEN BELOW:\n"; Sleep(750);
        
        cout << "( computer ) - ( furnature ) - ( anime ) - ( countries )\n"; Sleep(750);
        
        cout << "\t OR WRITE CLOSE TO END THE GAME\n\n";
        
        cin >> tybe; 
        transform(tybe.begin(), tybe.end(), tybe.begin(), ::tolower);
        if (COMPUTER_TEST(tybe)) {
            
            int index = randomi(9);
            
            cout << "\tYOU HAVE CHOSEN COMPUTER CATEGORY\n"; Sleep(1000);
        
            cout << "\t\tguess the next word\n\n";
            
            game(comp[index]);
        
        }
        
        else if (ANIME_TEST(tybe)) {
            int index = randomi(10);
            
            cout << "\tYOU HAVE CHOSEN ANIME CATEGORY\n"; Sleep(1000);
        
            cout << "\t\tguess the next word\n\n";
        
            game(anim[index]);
        
        }
        
        else if (COUNTRIES_TEST(tybe)) {
            
            int index = randomi(10);
            
            cout << "\tYOU HAVE CHOSEN COUNTRIES CATEGORY\n"; Sleep(1000);
            
            cout << "\t\tguess the next word\n\n";
            
            game(country[index]);
        
        }
        
        else if (FURNATURE_TEST(tybe)) {
            
            int index = randomi(9);

            cout << "\tYOU HAVE CHOSEN FURNATURE CATEGORY\n"; Sleep(1000);

            cout << "\t\tguess the next word\n\n";

            game(furn[index]);

        }
        
        else if (CLOSE_TEST(tybe)) {

            cout << "\n"; break;

        }
        
        else {

            cout << "\t IT SEEMS LIKE YOU CHOOSED VARFILESS WORD\n"; Sleep(1000);

            cout << "\t\t\tPLESE TRY AGAIN\n\n";

        }
    
    }
    
    cout << "\t\tTHANK YOU FOR USING OUR GAME!!\n";


}
bool COMPUTER_TEST(string temp) {
   
    string computer = "computer";
   
    if (computer != temp) {
        return 0;
    }

    else {
        return 1;
    } 

}
bool ANIME_TEST(string temp) {
    
    string anime = "anime";

    if (anime != temp) {
        return 0;
    }

    else {
        return 1;
    }


}

bool FURNATURE_TEST(string temp) {
   
    string furnature = "furnature";

    if (furnature != temp) {
        return 0;
    }

    else {
        return 1;
    }


}

bool COUNTRIES_TEST(string temp) {
    
    string countri = "countries";
    

    if (countri != temp) {
        return 0;
    }

    else {
        return 1;
    }


}

bool CLOSE_TEST(string temp) {
   
    string close = "close";

    if (close != temp) {
        return 0;
    }

    else {
        return 1;
    }


}

void game(string win) {

    string player; 
    char ch; 
    int cnt = 0;

    for (int i = 0; i < win.size(); i++) {
        player += "_";
    }

    while (player != win) {
    
        cnt++;

        cout << "YOUR WORD:   ( " << player<<" )\n";
        
        cout << "ENTER CHARACHTER:  "; cin >> ch; cout << "\n";
        
        player = check_char(win, player, ch);
        
    }
    
    cout << "\t\t\tCONGRATS!!\n"; Sleep(1000);

    cout << "\t    YOU WON THE GAME AFTER " << cnt << " TRIES!!\n"; Sleep(1000);
    
    cout << "\t  THE WINNING WORD WAS:  ( " << win << " )\n\n";

}

string check_char(string win, string player, char ch) {

    for (int i = 0; i < win.size(); i++) {

        if (ch == win[i] || win[i] == tolower(ch)) {
            player[i] = win[i];
        }

    }

    return player;

}
int randomi(int si) {
    srand(time(0));
    return rand() % si;
}