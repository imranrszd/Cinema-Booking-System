#include <iostream> //preprocessor direction
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <unistd.h>

using namespace std;

int bookingtime(string timer[], int m, int n); // function prototype
float membershipcategory(char m);
void capthacategory();
void seatChoice();
double foodMenu(int food);
double drinkMenu(int drink);

int minutes = 0;
int seconds = 15;

// function to display the timer
void displayClock()
{

    system("CLS");
    cout << setfill(' ') << setw(55) << "         TIMER         \n";
    cout << setfill(' ') << setw(55) << " -----------------------\n";
    cout << setfill(' ') << setw(29);
    cout << " "
         << "     |";
    cout << setfill('0') << setw(2) << minutes << " min | ";
    cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
    cout << setfill(' ') << setw(55) << " -----------------------\n";
}

float moviepriceage(int m) // function to calculate movie price based on age
{
    float price;
    if (m >= 12)
    {
        price = 17.00;
    }
    if (m < 12)
    {
        price = 12.50;
    }
    return price;
}

void welcomecategory() // fucntion to print First loading page
{
    cout << "     ===================================" << endl;
    cout << "     Welcome to Golden Screen Cinema.com" << endl;
    cout << "     ====================================" << endl;
    cout << endl;

    cout << "\nYou will soon be redirected to account log in page, PRESS ANY KEY TO CONTINUE...........";
    cout << endl;
}

void movietimecategory(string movie_time[], int m) // fnction to print time range of the movie
{
    cout << endl;
    cout << "           |========================|" << endl;
    cout << "           |  Time available TODAY  |" << endl;
    cout << "           |========================|" << endl;

    for (int index = 0; index < 3; index++) // print out the range
    {
        cout << "[" << index + 1 << "] -  " << movie_time[index] << " (duration 2hours)" << endl;
    }
}

void movieCategory(string movie_name[], int size) // function to print name of the movie showing
{

    cout << "                |=============|" << endl;
    cout << "                | NOW SHOWING |" << endl;
    cout << "                |=============|" << endl;

    for (int index = 0; index < 5; index++) // print out the name
    {
        cout << "[" << index + 1 << "]-  " << movie_name[index] << endl;
    }
    cout << "[6]-  Exits the program" << endl;
}

int moviechoicename(string movie_name[], int size, int m) // function to detect and print user input their choice of movie
{

    if (m == 1)
    {
        cout << "" << movie_name[0] << endl;
    }
    else if (m == 2)
    {
        cout << "" << movie_name[1] << endl;
    }
    else if (m == 3)
    {
        cout << "" << movie_name[2] << endl;
    }
    else if (m == 4)
    {
        cout << "" << movie_name[3] << endl;
    }
    else if (m == 5)
    {
        cout << "" << movie_name[4] << endl;
    }
    else if (m == 6)
    {
        cout << "Good Bye See You Again\n"
             << endl;
    }
    else
    {
        cout << endl;
        cout << "Invalid code" << endl;
    }
    cout << "Press any key to continue" << endl;
    return m;
}

int main()
{
    string username, password; // variable declaration and initialization
    int ch, choice, ticket, age, book, timers;
    char membershipanswer;
    float discount, moviePrice;
    char confirm;
    bool isMember;
    int pin, randomnumbers;

    string timer[] = {"12.00 am - 2.00pm", "4.00 pm - 6.00 pm", "8.00 pm - 10.00 pm"};                                                                        // array of available time list
    string movie[] = {"Thor: Love and Thunder", "Minions: The Rise of Gru", "Mat Kilau: Kebangkitan Pahlawan", "Top Gun Maverick", "Jurasic World: Dominan"}; // array of movie name list

    system("CLS");
    welcomecategory(); // display first page
    getch();           // to hold sceen

userlogin:
    system("CLS");
    cout << "      =================" << endl; // diplay message
    cout << "        ACCOUNT LOGIN" << endl;
    cout << "      =================" << endl;
    cout << endl;
    cout << "Please enter your account username: "; // ask to login account name
    cin >> username;

    cout << "Please enter your account password: "; // ask to login account password
    ch = getch();

    while (ch != 13)
    {
        password.push_back(ch);
        cout << '*';
        ch = getch(); // to make the password censcored
    }
    cout << endl;
    if (password == "user1")
    {
        cout << "Welcome";
    }
    cout << endl;

    capthacategory(); // display and ask to enter captha

    cout << endl;
    cout << "\nThe captcha you entered is correct.Press any key to continue........" << endl; // diplay message if captha enter correct
    getch();
    system("cls");

    cout << "WELCOME " << username << endl;                                                              // print back user name
    cout << "Have you subscribed to our membership?  you can get a 10% discount with membership(y/n): "; // ask if they have membership or not
    cin >> membershipanswer;                                                                             // get response of membership

    discount = membershipcategory(membershipanswer); //
    if (discount == 2)
    {
        cout << "You have subscribe our membership pls log in again,PRESS ANY KEY TO CONTINUE......." << endl;
        getch();
        goto userlogin; // to make user relogin again
    }

book:
    system("CLS");
    movieCategory(movie, 5); // print and display movie name list

    cout << "\nBOOKING NOW !!!: "; // ask movie they want to watch
    cin >> choice;

    moviechoicename(movie, 5, choice); // print and diplay movie choosen

    if (choice > 0 && choice < 6)
    {
        system("CLS");
        cout << "How many ticket?: "; // ask how many ticket
        cin >> ticket;                // get ticket
        cout << endl;

        int counter = 0;
        while (counter < ticket) // make a loop to get all user age based on ticket
        {
            cout << "Enter your age (person " << counter + 1 << "): ";
            cin >> age;
            if (age > 17 && choice == 4) // make sure their age meet the requirement
            {
            }
            else if (age > 12 && choice == 1 || age > 12 && choice == 5 || age > 12 && choice == 3)
            {
            }
            else if (age > 4 && choice == 2)
            {
            }
            else
            {
                cout << "Your age doesn't pass the requirment" << endl; // user will need to rechoice movie if age does'nt pass requirment
                cout << "Pls rechoose again movie or exit and press enter" << endl;
                getch();

                goto book;
            }
            counter++; // increament of counter
        }
    }
    else
    {
        return 0; // exit the program if enter wrong code
    }

    system("CLS");
    movietimecategory(timer, 3); // print and diplay movie time list

    cout << "\nPls choose the time: "; // ask what time they want to watch
timing:
    cin >> timers; // get time from user
    book = bookingtime(timer, 3, timers);

    if (book > 3)
    {
        cout << "Invalid code-Pls enter again: ";
        goto timing; // if time is invalid user need to enter time of movie again
    }

    // seat
    string seatChoose[ticket] = {};
    seatChoice(); // display and print seat available

    do
    {

        for (int n = 0; n < ticket; n++)
        {
            cout << "Choose your seat: "; // ask user to enter the seat choose
            cin >> seatChoose[n];         // get user seat number and char
            transform(seatChoose[n].begin(), seatChoose[n].end(), seatChoose[n].begin(), ::toupper);
        }

        cout << "Are you confirm? [Y/N]: ";
        cin >> confirm;

        if (toupper(confirm) == 'Y')
        {
            cout << "Confirming..." << endl;
            cout << "You will be redirecting to the Food and Drink Menu. Press enter to continue..." << endl;
            getch();

            system("cls");
        }

    } while (toupper(confirm) == 'N'); // will looping again if user enter N

    // Food and Drink menu
    char wantFood;
    string foodSize;

    cout << "Would you like to order a food? [Y/N]: "; // ask if they want food
    cin >> wantFood;
    int foodMany, foodChoice[] = {}, foodCounter = 0;
    double foodPrice, foodPriceTotal = 0;

    string food[] = {"Popcorn", "Nugget", "Sandwich"}; // food list
    double foodPrices[] = {8.00, 5.00, 4.00};          // food price
    string foodChoices[] = {};
    cout << fixed << showpoint << setprecision(2);

    // Food Menu
    while (toupper(wantFood) == 'Y') // looping if user want add food
    {
        cout << "           |===================================|" << endl;
        cout << "           |               Menu:               |" << endl;
        cout << "           |===================================|" << endl;

        cout << "Food: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "[" << i + 1 << "] " << food[i] << " (RM" << foodPrices[i] << ")" << endl; // print and diplay food and  price
        }

        cout << "Enter your choice: ";
        cin >> foodChoice[foodCounter]; // put the food choices in a int array

        foodPrice = foodMenu(foodChoice[foodCounter]);

        foodPriceTotal += foodPrice; // Totalling the price of food

        cout << "Your total of food is: RM" << foodPriceTotal << endl; // tell the customer their total of food

        cout << "Would you like to order another food? [Y/N]: "; // ask if the customer want another food
        cin >> wantFood;
        foodCounter++;
        system("cls");
    }

    char wantDrink, largeDrink;

    string drink[] = {"Coke", "Pepsi", "Sprite", "Fanta"}; // drink list
    double drinkPrices[] = {3.50, 3.00, 2.50, 3.00};       // drink price

    cout << "Would you like to order a drink? [Y/N]: "; // ask if they want drink
    cin >> wantDrink;
    int drinkMany, drinkChoice[] = {}, drinkCounter = 0;
    double drinkPrice, drinkPriceTotal = 0;

    // Drink Menu
    while (toupper(wantDrink) == 'Y') // looping if user want drink
    {
        cout << "           |===================================|" << endl; // display menu
        cout << "           |               Menu:               |" << endl;
        cout << "           |===================================|" << endl;

        cout << "Drink: " << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << "[" << i + 1 << "] " << drink[i] << " (RM" << drinkPrices[i] << ")" << endl; // print and display drink and price
        }

        cout << "Enter your choice: ";
        cin >> drinkChoice[drinkCounter]; // put the drink choices in a int array

        drinkPrice = drinkMenu(drinkChoice[drinkCounter]);

        cout << "Do you want to make your drink larger with RM2 more? [Y/N]: "; // ask user to add cup size
        cin >> largeDrink;
        if (toupper(largeDrink) == 'Y')
        {
            drinkPrice += 2; // calculate total of drink price
        }

        drinkPriceTotal += drinkPrice; // Totalling the price of drink

        cout << "Your total of food is: RM" << drinkPriceTotal << endl; // tell the customer their total of drink

        cout << "Would you like to order another drink? [Y/N]: "; // ask if the customer want another drink
        cin >> wantDrink;
        drinkCounter++;
        system("cls");
    }
    moviePrice = moviepriceage(age);                              // calculate movie price for age
    float TotalpriceFoodDrink = foodPriceTotal + drinkPriceTotal; // calculate total of the food and drink price

    // Payment
    float totalPayment = (moviePrice * ticket * discount) + TotalpriceFoodDrink; // calculate total of price need to pay include discount

    // Receipt
    system("CLS");
    cout << "Here is your receipt: " << endl;
    cout << endl;
    cout << "           |===================================|" << endl; // display receipt message
    cout << "           |             Receipt:              |" << endl;
    cout << "           |===================================|" << endl;
    cout << endl;
    cout << "Movie: " << movie[choice - 1] << endl;             // display movie choice by user
    cout << "Time of the movie: " << timer[timers - 1] << endl; // display movie time choice by user
    cout << "Your seat: ";                                      // diplay user seat
    for (int n = 0; n < ticket; n++)
    {
        cout << seatChoose[n] << ", ";
    }
    cout << endl;
    cout << "Ticket for " << ticket << " people: RM" << moviePrice * ticket << endl; // diplay how many ticket buy by user
    if (toupper(membershipanswer) == 'Y')
    {
        cout << "Discount include: 10%" << endl;
    }
    else if (toupper(membershipanswer) == 'N')
    {
        cout << "Discount aplied to movie ticket: none" << endl; // diplay discount include or nt
    }
    cout << "Total Food and Drink you order: RM" << TotalpriceFoodDrink << endl;
    cout << fixed << showpoint;
    cout << "Total all: RM" << setprecision(2) << totalPayment << endl; // diplay total price to user

    string toPay;
    cout << "Would you like to pay with cash or card? : " << endl;   // ask user to pay using card or cash
    cin >> toPay;                                                    // get payment method from user
    transform(toPay.begin(), toPay.end(), toPay.begin(), ::tolower); // transform input user to lower case

    cout << "You choose to pay with: " << toPay << endl;

    if (toPay == "cash") // payment method
    {
        cout << "Pls showthis Receipt at counter to pay" << endl;
        cout << "ID payment: " << rand() << endl; // diplay how user need to pay and id
    }
    else if (toPay == "card")
    {
        cout << "\nConfirming..." << endl;
        cout << "You will be redirecting to the payment page. Press any key to continue..." << endl;
        getch();

    payments:
        system("CLS");
        randomnumbers = (rand() % 100000) + 10000;
        cout << "Pls enter your pin number to confirm payment(Wait 15 second to process) :" << endl; // ask user to enter pin number
        cout << "pin number : " << randomnumbers << endl;                                            // get pin number
        cin >> pin;
        if (pin == randomnumbers)
        {
            while (true) // start timer from 00:00:15
            {

                // display the timer
                displayClock();
                sleep(1);
                seconds--;

                if (seconds == 00)

                {
                    cout << "Payment confirm and succesfull" << endl; // diplay this message if use input true pin number
                    return 0;                                         // exits program
                }
            }
        }

        else
        {
            while (true) // start timer from 00:00:15
            {

                // display the timer
                displayClock();
                sleep(1);
                seconds--;

                if (seconds == 00)

                {
                    cout << "Decline so pls enter pin number again,PRESS ANY KEY TO CONTINUE......" << endl; // diplay this message if use input false pin number
                    getch();
                    seconds = +15; // reset time to 15s
                    goto payments; // get user to pin number page back
                }
            }
        }
    }
    return 0; // exits program
}
int bookingtime(string timer[], int m, int n) // function  showing list time that have user choose
{

    switch (n)
    {
        {
        case 1:
            cout << timer[0] << endl; // print movie choose by user
            break;
        }

        {
        case 2:
            cout << timer[1] << endl;
            break;
        }

        {
        case 3:
            cout << timer[2] << endl;
            break;
        }

        {
        default:
            n > 3;
        }
    }
    return n;
}
float membershipcategory(char m) // function  membership answer to know discount and join membership
{
    float discount;
    char joinmembershipanswer;
    if (toupper(m) == 'Y')
    {
        discount = 0.9;
        cout << "Confirming..." << endl;
        cout << "You will be redirecting to Movie page. Press any key to continue..." << endl; // display message if user have membership
        getch();
    }
    else
    {

        cout << "Do you want to join membership now? [Y/N]" << endl; // ask user to join or not memberrship if user don't have membership
        cin >> joinmembershipanswer;                                 // get answer about joinmembership
        if (toupper(joinmembershipanswer) == 'Y')
        {

            discount = 2;
        }
        else
        {
            discount = 1;
        }
    }
    return discount;
}

void capthacategory() // captha to confirm if the user a bot or not
{
    int randomnumber;
    int captcha;
    do
    {
        randomnumber = (rand() % 100000) + 10000;
        cout << randomnumber;

        cout << endl;

        cout << "\nPlease retype the captcha to confirm you are not a robot: "; // if the captha enter was right user will proceed to next page
        cin >> captcha;                                                         // get captha

    } while (captcha != randomnumber);
}
void seatChoice() // function to print seat available
{
    char seatAlpha[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    cout << endl;
    cout << "           |===================================|" << endl;
    cout << "           |         Choose your seat:         |" << endl;
    cout << "           |===================================|" << endl;
    cout << endl;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++) // Show seat in one room
        {
            cout << "[ " << seatAlpha[i] << j + 1 << " ]";

            if (j == 1) // Seperate seat
            {
                cout << "   ";
            }
            if (j == 6) // Seperate seat
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "____________________________________________________________" << endl;
    cout << endl;
}
double foodMenu(int food) // function to know price of the food
{
    double fPrice;
    switch (food) // price for every food
    {
    case 1:
        fPrice = 8;
        break;
    case 2:
        fPrice = 5;
        break;
    case 3:
        fPrice = 4;
        break;
    default:
        break;
    }
    return fPrice;
}
double drinkMenu(int drink) // function drink price
{
    double dPrice;
    switch (drink) // price for every drink
    {
    case 1:
        dPrice = 3.50;
        break;
    case 2:
        dPrice = 3;
        break;
    case 3:
        dPrice = 2.50;
        break;
    case 4:
        dPrice = 3;
        break;
    default:
        break;
    }

    return dPrice;
}
