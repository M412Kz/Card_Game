#include <iostream>
#include <cstdlib>
using namespace std;

class Card_game { //base class
    string value[14] = {" ","Ace" , "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" };
    public:
        string card_p1,card_p2,card_p3;
        string card_b1,card_b2,card_b3;
        int player_point1,player_point2,banker_point1,banker_point2;
        void setCard_player(int p1,int p2,int p3);
        void setCard_banker(int b1,int b2,int b3);
        void setPlayer_point(int pp1,int pp2);
        void setBanker_point(int bp1,int bp2);
        void showCard_player();
        void showCard_banker();
        int showResult(int pp1,int pp2,int bp1,int bp2);
};


void Card_game::setCard_player(int p1, int p2, int p3){
    card_p1 = value[p1];
    card_p2 = value[p2];
    card_p3 = value[p3];
};


void Card_game::setCard_banker(int b1, int b2, int b3){
    card_b1 = value[b1];
    card_b2 = value[b2];
    card_b3 = value[b3];
};


void Card_game::setPlayer_point(int pp1,int pp2){
    player_point1 = pp1;
    player_point2 = pp2;
};


void Card_game::setBanker_point(int bp1,int bp2){
    banker_point1 = bp1;
    banker_point2 = bp2;
};


void Card_game::showCard_player(){
    cout << "\x1B[107;44m      Player's card      \033[0m" << endl;
    cout << "Player's card 1 is " << card_p1 << endl;
    cout << "Player's card 2 is " << card_p2 << endl;
    if (player_point1>5) {
        cout << "\x1B[34mPlayer's point is \033[0m" << player_point1 << endl;
    }
    if (player_point1 <=5){
        cout << "Player's card 3 is " << card_p3 << endl;
        cout << "\x1B[34mPlayer's point with card 3 is \033[0m" << player_point2 << endl;
    }
};

void Card_game::showCard_banker(){
    cout << "\x1B[107;101m      Banker's card      \033[0m" << endl;
    cout << "Banker's card 1 is " << card_b1 << endl;
    cout << "Banker's card 2 is " << card_b2 << endl;
    if (banker_point1>5) {
        cout << "\x1B[31mBanker's point is \033[0m" << banker_point1 << endl;
    }
    if (banker_point1 <=5){
        cout << "Banker's card 3 is " << card_b3 << endl;
        cout << "\x1B[31mBanker's point with card 3 is \033[0m" << banker_point2 << endl;
    }
};


int Card_game::showResult(int pp1,int pp2,int bp1,int bp2){
    if(pp1 <= 5){
        cout << endl;
        if(bp1 <= 5){
            if(pp2 == bp2){
                cout << "\x1B[107;42m      TieGame !!!!!      \033[0m" << endl;
                return 3;
            }
            else if (pp2 > bp2){
                cout << "\x1B[107;44m     Player win!!!!!     \033[0m" << endl;
                return 1;
            }
            else if (pp2 < bp2){
                cout << "\x1B[107;101m     Banker win!!!!!     \033[0m" << endl;
                return 2;
            }
        }else if(bp1 > 5){
            if(pp2 == bp1){
                cout<< "\x1B[107;42m      TieGame !!!!!      \033[0m" << endl;
                return 3;
            }
            else if(pp2 > bp1){
                cout << "\x1B[107;44m     Player win!!!!!     \033[0m" << endl;
                return 1;
            }
            else if(pp2 < bp1){
                cout << "\x1B[107;101m     Banker win!!!!!     \033[0m" << endl;
                return 2;
            }
        }
    }
    else if(pp1 > 5){
        cout << endl;
        if(bp1 <= 5){
            if(pp1 == bp2){
                cout<< "\x1B[107;42m      TieGame !!!!!      \033[0m" << endl;
                return 3;
            }
            else if(pp1 > bp2){
                cout << "\x1B[107;44m     Player win!!!!!     \033[0m" << endl;
                return 1;
            }
            else if(pp1 < bp2){
                cout << "\x1B[107;101m     Banker win!!!!!     \033[0m" << endl;
                return 2;
            }
        }else if(bp1 > 5){
            if(pp1 == bp1){
                cout << "\x1B[107;42m   TieGame !!!!!   \033[0m" << endl;
                return 3;
            }
            else if(pp1 > bp1){
                cout << "\x1B[107;44m  Player win!!!!!  \033[0m" << endl;
                return 1;
            }
            else if(pp1 < bp1){
                cout << "\x1B[107;101m  Banker win!!!!!  \033[0m" << endl;
                return 2;
            }
        }
    }
    return 0;
};

class Calculation : public Card_game {
    public:
        int pp1, pp2, bp1, bp2;
        int calPlayer_point1(int p1, int p2);
        int calPlayer_point2(int p3);
        int calBanker_point1(int b1, int b2);
        int calBanker_point2(int p3);
};

int Calculation:: calPlayer_point1(int p1, int p2){
    if (p1 >= 10){p1 = 0;}
    if (p2 >= 10){p2 = 0;}
    pp1 = (p1 + p2)%10;
    return pp1;
};

int Calculation:: calPlayer_point2(int p3){
    if (p3 >= 10){p3 = 0;}
    pp2 = (pp1 + p3)%10;
    return pp2;
};

int Calculation:: calBanker_point1(int b1,int b2){
    if (b1 >= 10){b1 = 0;}
    if (b2 >= 10){b2 = 0;}
    bp1 = (b1 + b2)%10;
    return bp1;
};

int Calculation:: calBanker_point2(int b3){
    if (b3 >= 10){b3 = 0;}
    bp2 = (bp1 + b3)%10;
    return bp2;
};

class Player : public Calculation {

    public:
        int player_1, player_2, player_3;
        
        Player() {
            player_1 = 0;
            player_2 = 0;
            player_3 = 0;
        }
        
        Player(int p1, int p2, int p3) {
            player_1 = p1;
            player_2 = p2;
            player_3 = p3;
        }
};

class Banker : public Calculation {

    public:
        int banker_1, banker_2, banker_3;
        
        Banker() {
            banker_1 = 0;
            banker_2 = 0;
            banker_3 = 0;
        }
        
        Banker(int b1, int b2, int b3) {
            banker_1 = b1;
            banker_2 = b2;
            banker_3 = b3;
        }
};

int Random() {
    int pp1, pp2, bp1, bp2, i;
    srand(time(0)); 
    int p1 = 1 + (rand() % 13); 
    int p2 = 1 + (rand() % 13);
    int p3 = 1 + (rand() % 13);
    Player player_s(p1, p2, p3);
    pp1 = player_s.calPlayer_point1(p1, p2);
    pp2 = player_s.calPlayer_point2(p3);
    player_s.setCard_player(p1, p2, p3);
    player_s.setPlayer_point(pp1, pp2);
    player_s.showCard_player();
    
    int b1 = 1 + (rand() % 13); 
    int b2 = 1 + (rand() % 13);
    int b3 = 1 + (rand() % 13);
    Banker banker_s(b1,b2,b3);
    bp1 = banker_s.calBanker_point1(b1, b2);
    bp2 = banker_s.calBanker_point2(b3);
    banker_s.setCard_banker(b1, b2, b3);
    banker_s.setBanker_point(bp1, bp2);
    banker_s.showCard_banker();
    i = player_s.showResult(pp1, pp2, bp1, bp2);
    return i;
}

int Playgame() {
        cout << "\x1B[94m _________________________________\033[0m\t\t" << endl;
        cout << "\x1B[94m|                                 |\033[0m\t\t" << endl;
        cout << "\x1B[94m|\033[0m\t\t" << "Bet\t\t  " << "\x1B[94m|\033[0m\t\t" << endl;
        cout << "\x1B[94m|---------------------------------|\033[0m\t\t" << endl;
        cout << "\x1B[94m|\033[0m" << "\x1B[107;44m [1] : Player win!               \033[0m" << "\x1B[94m| \033[0m\t\t" << endl;
        cout << "\x1B[94m|\033[0m" << "\x1B[107;101m [2] : Banker win!               \033[0m" << "\x1B[94m| \033[0m\t\t" << endl;
        cout << "\x1B[94m|\033[0m" << "\x1B[107;42m [3] : TieGame                   \033[0m" << "\x1B[94m| \033[0m\t\t" << endl;
        cout << "\x1B[94m|_________________________________|\033[0m\t\t" << endl;
    return 0;
}

int Check() {
    string choice;
    do {
        cout << "Enter your choice : ";
        cin >> choice;
        if (!isdigit(choice[0])) {
            cout << "Error: Invalid input" << endl;
            Playgame();
            continue;
        }
        int choice_int = stoi(choice);
        if (choice_int == 1) {
            return 1;
        } 
        else if (choice_int == 2) {
            return 2;
        } 
        else if (choice_int == 3) {
            return 3;
        } else {
            cout << "Error: Invalid input" << endl;
            Playgame();
        }
    } while (true);
    return 0;
}

float betMoney(int b, int i, int a) {
    float bet = 0;
    
    if (i == 1) {
        if(i == a) {
            bet = b*2;
            cout << "\x1B[92m        You Win\033[0m\t\t" << endl;
        }
        else if(i != a) {
            cout << "\x1B[91m        You Lose\033[0m\t\t" << endl;
        }
    }
    else if (i == 2) {
        if(i == a) {
            bet = b*1.95;
            cout << "\x1B[92m        You Win\033[0m\t\t" << endl;
        }
        else if(i != a) {
            cout << "\x1B[91m        You Lose\033[0m\t\t" << endl;
        }
    }
    else if (i == 3) {
        if (i == a) {
            bet = b*6;
            cout << "\x1B[92m        You Win\033[0m\t\t" << endl;
        }
        else if (i != a) {
            cout << "\x1B[91m        You Lose\033[0m\t\t" << endl;
        }
    }
    return bet;
}

float Money(int balance_int, int b, float bet) {
    balance_int -= b;
    balance_int += bet;
    cout << "Your balance : " << balance_int << endl;
    return balance_int;
}

int Balance() {
    string balance;
    do {
        cout << "Enter your money : ";
        cin >> balance;
    } while(!isdigit(balance[0]));
    int balance_int = stoi(balance);
    return balance_int;
}

bool CheckBet(int b, int balance_int) {
    if(balance_int < b) {
        cout << "*******Insufficient funds in the account******" << endl;
        return false;
    }
    return true;
}

int Bet(int balance_int) {
    string bs;
    do {
        cout << "Enter your money to bet : ";
        cin >> bs;
    }while(!isdigit(bs[0]));
    int b = stoi(bs);
    return b;
}

int main(){
    string choice;
    int i, a, b, balance_int;
    int x = 0;
    int y = 0;
    string results[100];
    char rs[100], rs1[100];
    float bet;
    
    FILE *fptr;
    fptr = fopen("Static.txt","w");
    fclose(fptr);
    
    balance_int = Balance();
    
    do {
        cout << "\x1B[94m _________________________________\033[0m\t\t" << endl;
        cout << "\x1B[94m|                                 |\033[0m\t\t" << endl;
        cout << "\x1B[94m|            Card Game            |\033[0m\t\t" << endl;
        cout << "\x1B[94m|---------------------------------|\033[0m\t\t" << endl;
        cout << "\x1B[94m| [1] : Play                      |\033[0m\t\t" << endl;
        cout << "\x1B[94m| [2] : Show static               |\033[0m\t\t" << endl;
        cout << "\x1B[94m| [3] : Exit                      |\033[0m\t\t" << endl;
        cout << "\x1B[94m|_________________________________|\033[0m\t\t" << endl;
        cout << "Select your choice : ";
        cin >> choice;
        
        if (choice == "1") {
            fptr = fopen("Static.txt","w");
            Playgame();//play game
            i = Check();
            b = Bet(balance_int);
            if(!CheckBet(b, balance_int)) {
                continue;
            }
            a = Random();
            balance_int = Money(balance_int, b, betMoney(b,i,a));
            if(a == 1){
                results[y] = "Player Win";
            }else if (a == 2){
                results[y] = "Banker Win";
            }
            else if (a == 3){
                results[y] = "Tie Game";
            }
            y++;
            for (int i = 0; i < y; i++) { // loop through the array and write each result to the file
                fprintf(fptr, "%s\n", results[i].c_str());
            }
            if (balance_int <= 0){
                cout<<"*****Running out of money in the account******"<<endl;
                break;
            }
            fclose(fptr);
        }
        else if (choice == "2") {
            cout << "\x1B[107;101m              Static              \033[0m" <<endl;
            fptr = fopen("Static.txt","r");
            for (int i = 0; i < y; i++) {
                fscanf(fptr,"%s %s",rs,rs1);
                cout << rs << " " << rs1 <<endl;
            }
        }
        else if (choice == "3") {
            break; //Exit
        }
        else {
            cout<<"Error: Invalid input"<<endl;
        }
    } while (true);
}

