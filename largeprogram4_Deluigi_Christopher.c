//Christopher Deluigi
//Dr. Steinberg
//COP3223C Section 1
//Large Program 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Main_choices(); //sets up function


typedef struct Game {
    char title[100], genre[100], studio[100], console[100]; //delcares varibles for struct for characteristics the game will contain
    double price;
}Game;

void Main_choices() //prints welcome statement, and asks for user input to choose an option
{
    printf("Welcome to the Sony Exclusive Video Game Catalog!\n");
    printf("*************************************************************\n");
    printf("What would you like to do?\n");
    printf("1: Add A Game\n");
    printf("2: Remove A Game\n");
    printf("3: Display All Games\n");
    printf("4: Lookup A Game\n");
    printf("5: Exit Prgram\n");
    printf("Enter here: ");
}

Game New_Game(char title[], char genre[], char studio[], char console[], double price) //passes the varibles to a function that allows a new game to be added to the array
{
    Game newGame;
    strcpy(newGame.title, title);
    strcpy(newGame.genre, genre);
    strcpy(newGame.studio, studio);
    strcpy(newGame.console, console);
    newGame.price = price;

    return newGame;
}

void New_Game_input(Game Games[], int *gameSize)  //sets limit on the amount of games allowed
{
    if(*gameSize == 30) {
        printf("Theres No More Space, Delete Some Games And Try Again.\n");
        return;
    }
    
    char title[100], genre[100], studio[100], console[20];
    double price;

    printf("++++++++++++++++++++++++++++++++++++++++\n");   //sets print statement and scanf statement to take in user inport when adding a new game.
    printf("Add game Menu\n");
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    printf("Please Enter Game Title: ");
    scanf(" %[^\n]s", title);
    printf("Please Enter Game genre: ");
    scanf(" %[^\n]s", genre);
    printf("Please Enter Game studio: ");
    scanf(" %[^\n]s", studio);
    printf("Please Enter Game Console: ");
    scanf(" %[^\n]s", console);
    printf("Please Enter Game Price: ");
    scanf("%lf", &price);

    Games[(*gameSize)++] = New_Game(title, genre, studio, console, price); //saves data to function new_game, placing it in the array
}

void Game_infomation(Game Game)  //prints games information details when displaying
{
    printf("Title: %s\n", Game.title);
    printf("Genre: %s\n", Game.genre);
    printf("Studio: %s\n", Game.studio);
    printf("Console: %s\n", Game.console);
    printf("Price: $%.2lf\n", Game.price);
    printf("++++++++++++++++++++++++++++++++++++++++\n");
}

void Search_Game(Game Games[], int gameSize, char searchText[], int user_select)  //allows users to search in the array
{
    printf("\n++++++++++++++++++++++++++++++++++++++++\n");
    printf("Search Game Result:\n");
    printf("++++++++++++++++++++++++++++++++++++++++\n");

    for(int i = 0; i < gameSize; ++i) 
    {  
        if((user_select == 1 && strcmp(Games[i].title, searchText) == 0)) //if user searches by name and game is found condition passes
        {
            printf("Game Found. Here are the Game Details: \n"); //statement checks to make sure game user is searching for is in the array and if it is, it calls game_information which then prints it out
            
            Game_infomation(Games[i]);
            
            return;
        }
    }
    printf("Game Not Found Within Console.\n"); //if nothing matches prints fail statement to user saying it was not located.
}

void Search_Input(Game Games[], int gameSize)  //checks to make sure theres at least 1 game saved. if there are 0 then it auto prints no games.
{
    if(gameSize == 0) 
    {
        printf("No Games Found.\n");
        return;
    }
    
    int user_response;
    printf("\n++++++++++++++++++++++++++++++++++++++++\n");
    printf("Search Game Menu\n");
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    printf("Press 1: Search Game With Title\n");
    scanf("%d", &user_response); //allows user to search within via the game name. 

    char searchText[100];
    if(user_response == 1) {
        printf("Please Enter Game Title: "); //takes in user search input
        scanf(" %[^\n]s", searchText); //makes sure user searches with game title, and if user tries to search with anything else, fail statement will print.
    } 
    else 
    {
        printf("Wrong Input. Please Try Again\n");
        return;
    }
    
    Search_Game(Games, gameSize, searchText, user_response); //information of game is then passed out to the function search game where it will confirm its there and if it is it will print all its details, and if not a fail statement will print.
}

void Show_All_Current_Games(Game Games[], int gameSize) 
{
    if(gameSize == 0)  //checks to make sure theres at least 1 game saved. if there are 0 then it auto prints no games.
    { 
        printf("No Games Found!\n");
        return;
    }
    
    printf("*************************************************************\n");
    printf("Displaying All Games In The Sony Exclusive Video Game Catalog.\n"); //displays all games saved at that moment in game information
    for(int i = 0; i < gameSize; ++i) {
        Game_infomation(Games[i]);
    }
}

void Remove_Game(Game Games[], int *gameSize, char searchText[], int user_select) 
{
    for(int i = 0; i < *gameSize; ++i) {
        if( (user_select == 1 && strcmp(Games[i].title, searchText) == 0))  //for user to remove game, it makes sure user is searching for a game with the tiitle, if passes, then game will be searched
        {
            printf("Game Found! Removing the Game from the Console!\n"); //if found game is remvoed, and array is game_information are updated.
            Games[i] = Games[(*gameSize)-1];
            (*gameSize)--;
            return;
        }
    }
    printf("Game Not Found.\n"); //if nothing matches then fail statement prints
}

void Remove_Game_Input(Game Games[], int *gameSize) 
{
    int user_response;
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    printf("Remove Game Menu\n");
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    printf("Press 1: Remove Game With Title\n");
    scanf("%d", &user_response); //takes input for user to select and search for game to remove.
    
    char searchText[100];
    if(user_response == 1) 
    {
        printf("Please Enter Game Title: ");
        scanf(" %[^\n]s", searchText); //confirms user is searching by title, if not fail statement prints.
    } 
    else 
    {
        printf("Incorrect Input! Please Try Again.\n");
        return;
    }
    Remove_Game(Games, gameSize, searchText, user_response); //if user is searching by title, then the function remove_games is called and starts to run to find game that user inputed.
    
}

void Game_Data_save(Game Games[], int *gameSize)  //holds all game data such as name, year, console it was initally realeased on
{
    int amount = 6; //declares the amount of games in the console, with all accompanying information
    char titles[][100] = {"Ghost of Tsushima", "The Last of Us", "Spider-Man", "Until Dawn", "Horizon Forbidden West", "God of War"};
    char genres[][100] = {"Historical", "Survival", "Superhero", "Horror", "Science Fiction", "Action-Adventure"};
    char studios[][100] = {"Sucker Punch Productions", " Naughty Dog", "Insomniac Games", "Supermassive Games", "Guerrilla Games", "Santa Monica Studio"};
    char consoles[][100] = {"PS4", "PS3", "PS4", "PS4", "PS5", "PS5"};
    double prices[] = {19.79, 69.99, 39.99, 19.99, 54.00, 69.99};
    
    for(int i = 0; i < amount; ++i)
        Games[(*gameSize)++] = New_Game(titles[i], genres[i], studios[i], consoles[i], prices[i]); //if new game is added game_data_save is then updated with users inputed information for the new game.
    
}

int main() 
{
    int gameSize = 0; //creates varible and sets it to 0
    Game gamescount[30]; //sets limit for the amount of games.
    
    Game_Data_save(gamescount, &gameSize); 
    
    int user_response = 0;
    while(user_response != 5) //while loops runs until user chooses option 5 which exits the program. 
    { 
        Main_choices();
        scanf("%d", &user_response); //user input is saved to user_response

        if(user_response > 5 || user_response <= 0) {
            printf("Enter a number between 1-5 To Move Forward.\n");// if user fails to input right value to move forward fail statement prints
            continue;
        }
        if(user_response == 1) New_Game_input (gamescount, &gameSize); //depending on which option chosen then a different action will take place, add, search, display remvoe, or exit.
        else if(user_response == 4) Search_Input(gamescount, gameSize);
        else if(user_response == 3) Show_All_Current_Games(gamescount, gameSize);
        else if(user_response == 2) Remove_Game_Input(gamescount, &gameSize);
        else break;
    }
    
    printf("*************************************************************\n");
    printf("Exiting the system and saving records to a text file called Records.txt.\n");
    return 0;
}