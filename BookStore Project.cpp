#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <clocale>

using namespace std;


void printBooks(vector<vector<string>> vec){
    cout << endl;
    cout << "                              =" << endl;
    cout << "                           ======" << endl;
    cout << "                        ============     _____" << endl;
    cout << "                     ==================  |   |" << endl;
    cout << "                  =======================|   |" << endl;
    cout << "               ==========================|   |" << endl;
    cout << "            =============================|   |==" << endl;
    cout << "         ==========================================" << endl;
    cout << "      ================================================" << endl;
    cout << "   ==================  My Book Store  ===================" << endl;
    cout << "============================================================" << endl;


    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (j == 0){
                cout << "||   " << vec[i][j];
                for (int r = 0; r < (25 - vec[i][j].size()); r++){
                    cout << " ";
                }
            }else if(j == 1){
                cout << "||     " << vec[i][j] << "\t";
            }else{
                cout << "||   " << vec[i][j];
                for (int r = 0; r < (5 - vec[i][j].size()); r++){
                    cout << " ";
                }
                cout << "||";
            }

        }
        cout << endl;
    }
    cout << "============================================================" << endl;
    cout << "     /\\" << endl;
    cout << "     /" << endl;
    cout << "    / Queue Start" << endl;
    cout << "   /" << endl;
    cout << "  /" << endl;

}

bool checkBook(string name, vector<vector<string>> vec, int t = 0) {
    for (int i = 0; i < vec.size(); i++) {

        if (name == vec[i][0]) {
            cout << name << " is available..." << endl;
            t = 1;
            return true;
        }
    }
    if (t == 0) {
        cout << name << " is not available...";
        return false;
    }
    else{
        return false;
    }
}

vector<vector<string>> sellBook(string name, vector<vector<string>> vec,
                                int amount){

    bool isAvailable = checkBook(name,vec);

    if (isAvailable){

        for(int i = 0; i<vec.size(); i++) {

            if (vec[i][0] == name){
                int c = ((atoi(vec[i][2].c_str())) - amount);
                stringstream ss;
                ss << c;
                string s;
                ss >> s;
                if (c == 0){
                    cout << "The last book has been sold..." << endl;
                    vec.erase(vec.begin() + i);
                }else if (c < 0){
                    cout << "The book that trying to be bought cannot be supplied."
                            " There is not enough book to sale." << endl;
                }else{
                    vec[i][2] = s;
                }

            }
        }
    }else{
        cout << "The book you were looking for was not found.";
    }

    return vec;
}

vector<vector<string>> addBook(string name,string price, vector<vector<string>> vec, int amount){

    bool isAvailable = checkBook(name,vec);

    if (isAvailable){
        for(int i = 0; i<vec.size(); i++) {
            if (vec[i][0] == name) {
                int c = ((atoi(vec[i][2].c_str())) + amount);
                stringstream ss;
                ss << c;
                string s;
                ss >> s;
                vec[i][2] = s;
            }
        }

        return vec;
    }
    else{

        vec.push_back({name,price, to_string(amount)});


        return vec;
    }
}

void printline(queue<string> sira,int t = 1)
{

    queue<string> g = sira;
    while (!g.empty()) {

        cout << to_string(t) << '\t' << g.front() << endl;
        cout << "  O" << endl << " /|\\" << endl << " /.\\" << endl;
        g.pop();
        t++;
    }
    cout << '\n';
}


int main()
{
    vector<vector<string>> books{{"Kurk Mantolu Madonna","$19.90","2"},{"Son Ada","$9.90","3"},{"Nutuk","$49.90","20"},
                                 {"Suc ve Ceza","$9.90","40"},{"Gurur ve Onyargi","$29.90","30"},{"Ermis","$9.90","30"}};

    printBooks(books);

    queue<string> line;
    line.push("Mehmet Emre Ayar");
    line.push("Gulsum Ikbal Avsar");
    line.push("Kemalettin Kocyigit");
    line.push("Rene Magritte");
    line.push("Jason Statham");
    line.push("Christopher Nolan");
    line.push("Stanley Kubrick");
    line.push("David Fincher");
    line.push("Ted Mosby");
    line.push("Chandler Bing");

    printline(line);

    string time = "Morning";

    while (!line.empty()){


        if (time == "Morning"){
            cout << "Time ===>" << time << "!!!" << endl;
            cout << "Customer Name : " << line.front() << endl;
            cout << line.front() << " wants to buy '10 Suc ve Ceza'" << endl;
            books = sellBook("Suc ve Ceza",books,10);
            printBooks(books);
            line.pop();
            printline(line);

            cout << "Customer Name : " << line.front() << endl;
            cout << line.front() << " wants to buy '5 Kurk Mantolu Madonna'" << endl;
            books = sellBook("Kurk Mantolu Madonna",books,5);
            printBooks(books);
            line.pop();
            printline(line);

            cout << "Customer Name : " << line.front() << endl;
            cout << line.front() << " wants to buy '2 Dune'" << endl;
            books = sellBook("Dune",books,2);
            printBooks(books);
            line.pop();
            printline(line);
            time = "Deliver Time";
        }
        else if(time == "Deliver Time"){
            cout << "Deliver Time!!" << endl;
            cout << "Deliver contain:" << endl;
            cout << "- Book Name: Dune , Price: $12 , Amount: 15" << endl;
            cout << "- Book Name: The Hunger Games , Price: $7.90 , Amount: 5" << endl;
            cout << "- Book Name: Ermis , Price: $9.90 , Amount: 7" << endl;
            books = addBook("Dune","$12",books,15);
            books = addBook("The Hunger Games","$7.90",books,5);
            books = addBook("Ermis","$9.90",books,7);
            printBooks(books);
            printline(line);

            time = "Afternoon";
        }
        else if (time == "Afternoon"){
            cout << "Time ===>" << time << "!!!" << endl;
            cout << "Customer Name : " << line.front() << endl;
            cout << line.front() << " wants to buy '1 Son Ada'" << endl;
            books = sellBook("Son Ada",books,1);
            printBooks(books);
            line.pop();
            printline(line);

            cout << "Customer Name : " << line.front() << endl;
            cout << line.front() << " wants to buy '5 The Hunger Games'" << endl;
            books = sellBook("The Hunger Games",books,5);
            printBooks(books);
            line.pop();
            printline(line);

            cout << "Customer Name : " << line.front() << endl;
            cout << line.front() << " wants to buy '2 Dune'" << endl;
            books = sellBook("Dune",books,2);
            printBooks(books);
            line.pop();
            printline(line);
            time = "Morning";
        }

    }

    return 0;
}
