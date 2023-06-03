#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <Windows.h>
#include <QtGui>
#include <QDebug>


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    //fixing the window size
    this->setFixedSize(size());

    //disabing some elements at the start
    ui->GuessTxtBox->setEnabled(false);
    ui->StartOverBtn->setEnabled(false);
    ui->SubmitBtn->setEnabled(false);





}

MainWindow::~MainWindow()
{

    delete ui;

}

//validating the users guess
bool isguessValid(string guess, int length){

    if(!(guess.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ ") == std::string::npos))
    {
        QMessageBox::critical(0,"Error","Incorrect Input! Use only the alphabet characters");
        return false;
    }
    if(guess.size()==0)
    {
        QMessageBox::critical(0,"Error","Input can't be empty.");
        return false;
    }
    if(guess.size()!=length)
    {
        QMessageBox::critical(0,"Error","Incorrect Input! Pay attention to the length.");
        return false;
    }

    else{
        return true;

    }



}

//Uppercase Function
void toUpperCase(std::string &input)
{
    std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c)
                   { return std::toupper(c); });
}

//Checking whether if the user has guessed the chosen word correctly
bool isAllMatch(std::string target, std::string guess)
{
    for (int i = 0; i < guess.length(); i++)
    {
        if (guess[i] != target[i])
            return false;
    }
    return true;
}


//------------------------------------------------------------------------------
//declaring the arrays of the categories
string animals[100] = {  "ant", "bat", "bear", "bee", "bird", "camel", "cat", "cheetah", "chicken", "cow",            "crocodile", "deer", "dog", "dolphin", "duck", "eagle", "elephant", "fish", "fox", "frog",            "giraffe", "goat", "goldfish", "hamster", "hippopotamus", "horse", "kangaroo", "kitten", "lion", "lobster",            "monkey", "octopus", "owl", "panda", "parrot", "penguin", "pig", "puppy", "rabbit", "rat",            "scorpion", "seal", "shark", "sheep", "snail", "snake", "spider", "squirrel", "tiger", "turtle",            "wolf", "zebra", "alpaca", "antelope", "armadillo", "bald eagle", "bat", "beaver", "buffalo", "butterfly",            "camel", "caterpillar", "chimpanzee", "coyote", "crab", "dinosaur", "dragon", "eagle", "elephant seal", "ferret",            "flamingo", "gazelle", "gecko", "gerbil", "gopher", "grizzly bear", "hamster", "hedgehog", "iguana", "jaguar",            "jellyfish", "koala", "lemur", "leopard", "llama", "lynx", "manatee", "meerkat", "mole", "mongoose", "moose", "mosquito", "narwhal", "opossum", "otter", "pangolin", "pelican", "platypus", "porcupine", "quokka",            };
string jobs[100] = {"trader","accountant", "actor", "architect", "artist", "astronomer", "athlete", "attorney", "author", "baker", "banker",            "bartender", "biologist", "builder", "busdriver", "butcher", "carpenter", "chef", "chemist", "cleaner", "clerk",            "coach", "composer", "computerprogrammer", "consultant", "contractor", "cook", "counselor", "dentist", "designer", "detective",            "doctor", "economist", "electrician", "engineer", "entrepreneur", "factoryworker", "farmer", "firefighter", "fisherman", "flightattendant",            "florist", "freelancer", "gardener", "graphicdesigner", "hairdresser", "healthcareworker", "hotelmanager", "housekeeper", "insuranceagent", "interpreter",            "journalist", "judge", "lawyer", "lecturer", "librarian", "lifeguard", "maintenanceworker", "manager", "marketingspecialist", "mechanic",            "musician", "nutritionist", "officeassistant", "painter", "paramedic", "pharmacist", "photographer", "physician", "physicist",            "pilot", "plumber", "policeofficer", "politician", "postalworker", "professor", "psychologist", "realestateagent", "receptionist", "salesperson",            "scientist", "secretary", "securityguard", "softwaredeveloper", "socialworker", "soldier", "sportscoach", "teacher", "technician", "therapist",            "translator", "travelagent", "truckdriver", "veterinarian", "videogamedesigner", "waiter", "webdeveloper", "writer", "yogainstructor", "youtuber"    };
string food[100] = {"apple", "apricot", "avocado", "bacon", "bagel", "banana", "bean", "beef", "beer", "biscuit",            "blueberry", "bread", "broccoli", "butter", "cake", "carrot", "cheese", "cherry", "chicken", "chips",            "chocolate", "coffee", "cookie", "corn", "crab", "croissant", "cucumber", "curry", "doughnut", "egg",            "fajita", "fig", "fish", "fries", "garlic", "grape", "grapefruit", "hamburger", "ham", "honey",            "hotdog", "icecream", "jelly", "ketchup", "kiwi", "lobster", "lollipop", "macaroni", "mango", "mayonnaise",            "meatball", "milk", "muffin", "mushroom", "mustard", "noodle", "oatmeal", "olive", "onion", "orange",            "pancake", "pasta", "peach", "peanutbutter", "pear", "pepper", "pickle", "pineapple", "pizza", "popcorn",            "potato", "pretzel", "pudding", "pumpkin", "quiche", "radish", "raspberry", "rice", "salad", "salmon",            "sandwich", "sausage", "shrimp", "soup", "spaghetti", "spinach", "steak", "strawberry", "sushi", "sweetpotato",            "taco", "toast", "toffee", "tomato", "turkey", "vanilla", "veal", "watermelon", "waffle", "wine" };
string cities[100] = {"tehran", "mashhad", "isfahan", "shiraz", "tabriz", "yazd", "kerman", "rasht", "qom", "ahvaz", "dubai", "istanbul", "beirut", "cairo", "london", "paris", "berlin", "rome", "madrid", "lisbon", "budapest", "vienna", "prague", "warsaw", "moscow", "bangkok", "tokyo", "beijing", "seoul", "delhi", "mumbai", "jakarta", "manila", "hanoi", "sydney", "melbourne", "toronto", "vancouver", "newyork", "losangeles", "chicago", "houston", "boston", "philadelphia", "atlanta", "miami", "mexico", "brazilia", "buenosaires", "lima", "santiago", "bogota", "caracas", "montreal", "ottawa", "quebec", "calgary", "edmonton", "halifax", "havana", "kingston", "porto", "barcelona", "madrid", "valencia", "seville", "malaga", "rome", "florence", "milan", "naples", "berlin", "frankfurt", "munich", "hamburg", "vienna", "salzburg", "innsbruck", "brussels", "antwerp", "ghent", "bruges", "amsterdam", "rotterdam", "thehague", "utrecht", "oslo", "bergen", "trondheim", "copenhagen", "aarhus", "stockholm", "gothenburg", "malmo", "helsinki", "tampere", "turku", "reykjavik", "dublin"};
string items[100] = {"alarm", "bag", "ball", "balloon", "bat", "battery", "bed", "belt", "bike", "blanket",        "book", "bottle", "bow", "broom", "brush", "bucket", "camera", "candle", "car", "chair",        "clock", "coat", "comb", "computer", "cup", "curtain", "desk", "door", "dress", "drum",        "dumbbell", "earring", "fan", "flag", "flashlight", "flower", "food", "fork", "fridge", "glasses",        "glove", "hairbrush", "hammer", "hat", "headphones", "helmet", "keyboard", "knife", "lamp", "lighter",        "map", "mirror", "mouse", "nail", "needle", "oven", "paint", "paper", "pen", "pencil",        "phone", "picture", "pillow", "plate", "pot", "radio", "remote", "ring", "rope", "rug","scissors", "shampoo", "shoe", "shovel", "soap", "socks", "spoon", "sunglasses", "table", "tape",        "teapot", "telephone", "television", "thermometer", "tissue", "toilet", "towel", "trash", "umbrella", "vase",        "wallet", "watch", "water", "wheel", "window", "wine", "zipper", "brush", "cushion", "guitar"  };


string SelectedWord;
int SelectedCategory;
int NumberOfTries;
int wordlength;


void MainWindow::on_StartBtn_clicked()
{
    //generate random number
    srand((unsigned) time(NULL));
    int randomnumber = rand() % 99;
    //
    int ComboIndex;
    ComboIndex= ui->CatComboBox->currentIndex();
    SelectedCategory = ComboIndex;


    //choosing a random word from the selected category
    switch(SelectedCategory){

    case 0:
        SelectedWord = animals[randomnumber];

        break;

    case 1:
        SelectedWord = jobs[randomnumber];
        break;

    case 2:
        SelectedWord = food[randomnumber];
        break;

    case 3:
        SelectedWord = cities[randomnumber];
        break;


    case 4:
        SelectedWord = items[randomnumber];
        break;

    }

    toUpperCase(SelectedWord);

    wordlength=SelectedWord.size();

    NumberOfTries=wordlength;

    //displaying the length and the guesses left
    QString tmpforlable3 = QString::number(wordlength);
    ui->label_3->setText("Length: "+tmpforlable3);
    QString tmpforlable4 = QString::number(NumberOfTries);
    ui->label_4->setText("Guesses Left: "+tmpforlable4);



    //--------------
    ui->StartBtn->setEnabled(false);
    ui->CatComboBox->setEnabled(false);

    //--------
    ui->GuessTxtBox->setEnabled(true);
    ui->SubmitBtn->setEnabled(true);
}

//exiting the program
void MainWindow::on_actionQuit_triggered()
{
    QMessageBox::information(this,"","Thank you for using the application! ");
    this->close();
}


//a little cheat in the app, if you click on the "WORDLE" lable for 8 times in enables the cheat.
int counter=0;
void MainWindow::on_worldeLable_clicked()
{

    counter++;

    if(counter==8)
    {
        ui->actionAEZAKEMI->setEnabled(true);
    }
}

//tutorial
void MainWindow::on_actionHowToPlay_triggered()
{
    QMessageBox::information(this,"Tutorial","1-Select a category \n 2-Enter your guesses(Pay attention to the length of the word) \n 3-# means that the letter is correct, X means that the letter is wrong \n 4-Keep guessing until you reach the word otherwise you will lose ");
}

//displaying the word (Cheat)
void MainWindow::on_actionAEZAKEMI_triggered()
{
    QString qstr = QString::fromStdString(SelectedWord);
    ui->label_sec->setText("word is: "+ qstr);
}



void MainWindow::on_label_sec_linkActivated(const QString &link)
{

}


int CurrentTry =0;
string ListOutput;

void MainWindow::on_SubmitBtn_clicked()
{

    string userinput = ui->GuessTxtBox->text().toStdString();
    toUpperCase(userinput);
    bool condition =CurrentTry < NumberOfTries && isguessValid(userinput,wordlength);
    bool isWon=false;

    while (condition){
        if (isAllMatch(SelectedWord, userinput))
        {

            QMessageBox::information(this,"Congratulations","You have found the word!");
            ui->label_status->setText("Game Won");
            ui->label_status->setStyleSheet("QLabel { color : green; }");
            //-------
            ui->GuessTxtBox->setEnabled(false);
            ui->SubmitBtn->setEnabled(false);
            //------
            ui->StartOverBtn->setEnabled(true);
            //-----

             isWon=true;

            break;
        }
        else{

            //displaying the correct and the incorrect letters using # and X
            for (int j = 0; j < SelectedWord.size(); j++)
            {

                    if (userinput[j] == SelectedWord[j])
                    {
                        ListOutput += "#";

                    }
                    else if(userinput[j] != SelectedWord[j])
                    {
                        ListOutput += "X";

                    }
            }

            break;

        }




    }

    //this portion happens when the user's guess in valid but wrong
    if(!isWon && condition)
    {

        string Temporary = std::to_string(CurrentTry+1);
        ui->listWidget->addItem(QString::fromStdString(Temporary+"          "+userinput+"            "+ ListOutput));

        ui->label_dis_guess->setText(QString::fromStdString(userinput));
        ui->label_dis_Cr->setText(QString::fromStdString(ListOutput));


        ListOutput="";


    CurrentTry++;
    QString tmpforlable4 = QString::number(NumberOfTries-CurrentTry);
    ui->label_4->setText("Guesses Left: "+tmpforlable4);
    }

    //This checks if the user has failed to guess the word and has outrun the number of tries.
    if(NumberOfTries-CurrentTry==0)
    {
    QMessageBox::critical(0,"Game over","You failed to find the word!\n Feel free to start over.");
    ui->label_status->setText("Game Lost");
    ui->label_status->setStyleSheet("QLabel { color : red; }");
    CurrentTry=0;

    //-------
    ui->GuessTxtBox->setEnabled(false);
    ui->SubmitBtn->setEnabled(false);
    //------
    ui->StartOverBtn->setEnabled(true);
    //-----

    }


}


//This one resets some elements of the app and makes everything ready for another round.
void MainWindow::on_StartOverBtn_clicked()
{

    //----
    ui->GuessTxtBox->setEnabled(false);
    ui->StartOverBtn->setEnabled(false);
    ui->SubmitBtn->setEnabled(false);
    //-----
    ui->StartBtn->setEnabled(true);
    ui->CatComboBox->setEnabled(true);
    //-----
    ui->GuessTxtBox->setText("");
    ui->label_sec->setText("");
    ui->label_dis_guess->setText("");
    ui->label_dis_Cr->setText("");
    ui->label_status->setText("");

    ui->label_3->setText("Length: ");
    ui->label_4->setText("Guesses Left: ");


    ui->listWidget->clear();
    ui->listWidget->addItem("No.      Last Guess        Correctness");



}


void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{

}

