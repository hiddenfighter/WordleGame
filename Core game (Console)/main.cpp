#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

//This function checks if the category input from the user is valid.
bool IsSelectedCategoryValid(string s) {
    //Here we check if the input is not empty and it is from 1 to 5, otherwise we return false with the right error message.
    if (!s.empty() && s.find_first_not_of("12345") == std::string::npos && s.length() == 1) {
        return true;
    } else if (s.empty()) {
        cout << "Error, Input cant be empty, Try Again" << endl << endl;
        return false;
    } else if (s.find_first_not_of("12345") != std::string::npos || s.length() != 1) {
        cout << "Error, Please Enter the correct numbers, Try Again" << endl << endl;
        return false;
    }
    else
        return false;

}


//This functions checks whether if the user's guess is valid.
bool isguessValid(string guess, int length) {

    if (guess.size() != length) {
        cout << "Error, Incorrect Length, Try Again:" << endl;
        return false;
    }
    if(guess.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ ") != std::string::npos) {
        cout << "Error, Use the english alphabet Only, Try Again:" << endl;
        return false;

    }
    else {

        return true;
    }

}

//This function checks whether if the guess is the same as the chosen word.
bool isAllMatch(std::string target, std::string guess) {
    for (int i = 0; i < guess.length(); i++) {
        if (guess[i] != target[i])
            return false;
    }
    return true;
}


//This function converts the user's input to UpperCase.
void toUpperCase(std::string &input) {
    std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::toupper(c); });
}


//This is the start of the program
int main() {
    
    //First we import the words for the five categories, this can be done in a variety of ways including: using a dictionacry API,importing from a file on the machine, importing from a database anc etc.
    //Here we defined five arrays with a size of 100 and filled it with 100 words.
    string animals[100] = {"ant", "bat", "bear", "bee", "bird", "camel", "cat", "cheetah", "chicken", "cow",
                           "crocodile", "deer", "dog", "dolphin", "duck", "eagle", "elephant", "fish", "fox", "frog",
                           "giraffe", "goat", "goldfish", "hamster", "hippopotamus", "horse", "kangaroo", "kitten",
                           "lion", "lobster", "monkey", "octopus", "owl", "panda", "parrot", "penguin", "pig", "puppy",
                           "rabbit", "rat", "scorpion", "seal", "shark", "sheep", "snail", "snake", "spider",
                           "squirrel", "tiger", "turtle", "wolf", "zebra", "alpaca", "antelope", "armadillo",
                           "bald eagle", "bat", "beaver", "buffalo", "butterfly", "camel", "caterpillar", "chimpanzee",
                           "coyote", "crab", "dinosaur", "dragon", "eagle", "elephant seal", "ferret", "flamingo",
                           "gazelle", "gecko", "gerbil", "gopher", "grizzly bear", "hamster", "hedgehog", "iguana",
                           "jaguar", "jellyfish", "koala", "lemur", "leopard", "llama", "lynx", "manatee", "meerkat",
                           "mole", "mongoose", "moose", "mosquito", "narwhal", "opossum", "otter", "pangolin",
                           "pelican", "platypus", "porcupine", "quokka",};
    string jobs[100] = {"trader", "accountant", "actor", "architect", "artist", "astronomer", "athlete", "attorney",
                        "author", "baker", "banker", "bartender", "biologist", "builder", "busdriver", "butcher",
                        "carpenter", "chef", "chemist", "cleaner", "clerk", "coach", "composer", "computerprogrammer",
                        "consultant", "contractor", "cook", "counselor", "dentist", "designer", "detective", "doctor",
                        "economist", "electrician", "engineer", "entrepreneur", "factoryworker", "farmer",
                        "firefighter", "fisherman", "flightattendant", "florist", "freelancer", "gardener",
                        "graphicdesigner", "hairdresser", "healthcareworker", "hotelmanager", "housekeeper",
                        "insuranceagent", "interpreter", "journalist", "judge", "lawyer", "lecturer", "librarian",
                        "lifeguard", "maintenanceworker", "manager", "marketingspecialist", "mechanic", "musician",
                        "nutritionist", "officeassistant", "painter", "paramedic", "pharmacist", "photographer",
                        "physician", "physicist", "pilot", "plumber", "policeofficer", "politician", "postalworker",
                        "professor", "psychologist", "realestateagent", "receptionist", "salesperson", "scientist",
                        "secretary", "securityguard", "softwaredeveloper", "socialworker", "soldier", "sportscoach",
                        "teacher", "technician", "therapist", "translator", "travelagent", "truckdriver",
                        "veterinarian", "videogamedesigner", "waiter", "webdeveloper", "writer", "yogainstructor",
                        "youtuber"};
    string food[100] = {"apple", "apricot", "avocado", "bacon", "bagel", "banana", "bean", "beef", "beer", "biscuit",
                        "blueberry", "bread", "broccoli", "butter", "cake", "carrot", "cheese", "cherry", "chicken",
                        "chips", "chocolate", "coffee", "cookie", "corn", "crab", "croissant", "cucumber", "curry",
                        "doughnut", "egg", "fajita", "fig", "fish", "fries", "garlic", "grape", "grapefruit",
                        "hamburger", "ham", "honey", "hotdog", "icecream", "jelly", "ketchup", "kiwi", "lobster",
                        "lollipop", "macaroni", "mango", "mayonnaise", "meatball", "milk", "muffin", "mushroom",
                        "mustard", "noodle", "oatmeal", "olive", "onion", "orange", "pancake", "pasta", "peach",
                        "peanutbutter", "pear", "pepper", "pickle", "pineapple", "pizza", "popcorn", "potato",
                        "pretzel", "pudding", "pumpkin", "quiche", "radish", "raspberry", "rice", "salad", "salmon",
                        "sandwich", "sausage", "shrimp", "soup", "spaghetti", "spinach", "steak", "strawberry", "sushi",
                        "sweetpotato", "taco", "toast", "toffee", "tomato", "turkey", "vanilla", "veal", "watermelon",
                        "waffle", "wine"};
    string cities[100] = {"tehran", "mashhad", "isfahan", "shiraz", "tabriz", "yazd", "kerman", "rasht", "qom", "ahvaz",
                          "dubai", "istanbul", "beirut", "cairo", "london", "paris", "berlin", "rome", "madrid",
                          "lisbon", "budapest", "vienna", "prague", "warsaw", "moscow", "bangkok", "tokyo", "beijing",
                          "seoul", "delhi", "mumbai", "jakarta", "manila", "hanoi", "sydney", "melbourne", "toronto",
                          "vancouver", "newyork", "losangeles", "chicago", "houston", "boston", "philadelphia",
                          "atlanta", "miami", "mexico", "brazilia", "buenosaires", "lima", "santiago", "bogota",
                          "caracas", "montreal", "ottawa", "quebec", "calgary", "edmonton", "halifax", "havana",
                          "kingston", "porto", "barcelona", "madrid", "valencia", "seville", "malaga", "rome",
                          "florence", "milan", "naples", "berlin", "frankfurt", "munich", "hamburg", "vienna",
                          "salzburg", "innsbruck", "brussels", "antwerp", "ghent", "bruges", "amsterdam", "rotterdam",
                          "thehague", "utrecht", "oslo", "bergen", "trondheim", "copenhagen", "aarhus", "stockholm",
                          "gothenburg", "malmo", "helsinki", "tampere", "turku", "reykjavik", "dublin"};
    string items[100] = {"alarm", "bag", "ball", "balloon", "bat", "battery", "bed", "belt", "bike", "blanket", "book",
                         "bottle", "bow", "broom", "brush", "bucket", "camera", "candle", "car", "chair", "clock",
                         "coat", "comb", "computer", "cup", "curtain", "desk", "door", "dress", "drum", "dumbbell",
                         "earring", "fan", "flag", "flashlight", "flower", "food", "fork", "fridge", "glasses", "glove",
                         "hairbrush", "hammer", "hat", "headphones", "helmet", "keyboard", "knife", "lamp", "lighter",
                         "map", "mirror", "mouse", "nail", "needle", "oven", "paint", "paper", "pen", "pencil", "phone",
                         "picture", "pillow", "plate", "pot", "radio", "remote", "ring", "rope", "rug", "scissors",
                         "shampoo", "shoe", "shovel", "soap", "socks", "spoon", "sunglasses", "table", "tape", "teapot",
                         "telephone", "television", "thermometer", "tissue", "toilet", "towel", "trash", "umbrella",
                         "vase", "wallet", "watch", "water", "wheel", "window", "wine", "zipper", "brush", "cushion",
                         "guitar"};

    //Here we display a welcome message and prompt the user to select a category by entering a number from 1 to 5.
    cout << "Welcome the the word guessing game! Please Select your desired category." << endl;
    string SelectedCategory;
    //We're using a do while loop here, because we want to let the user enter the category at lease once, regarding of the validity of the input.
    do {
        cout << "1.Animals" << endl;
        cout << "2.Jobs" << endl;
        cout << "3.Cities " << endl;
        cout << "4.Food" << endl;
        cout << "5.Items" << endl;
        cout << endl << "Type in the number of the category: ";
        getline(cin, SelectedCategory);
    }
    //this condition checks whether if the input is valid using the "IsSelectedCategoryValid" function.
    while (!IsSelectedCategoryValid(SelectedCategory));



    /* A random number between 0 and 99 gets generated here so that we can use it for picking a random word from the selected category by using it as the index of the array.
    we use the time as the seed of the rand function, using the rand() function without a random seed will result in a constant number, this is a common practice in c++. */
    srand((unsigned) time(NULL));
    int randomnumber = rand() % 99;
    //

    string SelectedWord;
    //here we choose a random word from the Selected Category using a switch statement.
    switch (stoi(SelectedCategory)) {

        case 1:
            SelectedWord = animals[randomnumber];

            break;

        case 2:
            SelectedWord = jobs[randomnumber];
            break;

        case 3:
            SelectedWord = cities[randomnumber];
            break;

        case 4:
            SelectedWord = food[randomnumber];
            break;

        case 5:
            SelectedWord = items[randomnumber];
            break;

    }

    //Here we convert the word into Uppercase for easier comparison using the "toUpperCase" function.
    toUpperCase(SelectedWord);


    //here we set some variables.
    int wordlength = SelectedWord.size();
    int CurrentTry = 0;
    //the number of tries can be any number but here i chose to set to the length of the chosen word, ] think it makes for fairer game, Feel free to change it to any number.
    int numberOfTries = wordlength;
    string userinput;

    //You can uncomment this line of code, it shows the selected word for cheating or debugging purposes.
    /*   cout << SelectedWord << endl;   */


    //We get an input from the user until he has tried to guess more than the allowed number of tries.
    while (CurrentTry < numberOfTries) {
        //Getting an input from the user atleast once, and repeating it until the input is valid.
        do {
            cout << "Please enter your guess (word length is " + to_string(wordlength) + ") or type Q to quit: ";
            getline(std::cin, userinput);
            toUpperCase(userinput);
            //we verify the validity of the input using the "isguessValid" function.
        } while (userinput != "Q" && !isguessValid(userinput, wordlength));

        //we exit the program if the input is q.
        if (userinput == "Q") {
            cout << "Quit game" << endl;
            break;
        }
        //Here we check if the guess completely matches the chosen word, and if it does user has won the game and we exit the program.
        if (isAllMatch(SelectedWord, userinput)) {
            cout << "Congrats! Your Found the word" << endl;
            break;

        }

        //at last if the user guess incorrectly, we add one to the tries and run the loop again.
        CurrentTry++;
        cout << "Incorrect, " << numberOfTries - CurrentTry << " Guesses remain!" << endl;

    }

    //after the user wasn't able to guess the word we display a game over message.
    if (CurrentTry == numberOfTries) {
        cout << "You didn't find the word, GAME OVER." << endl;
    }


}
