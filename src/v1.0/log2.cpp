#include  <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <tuple>
using namespace std;

void playSound(string soundFile) {
    string cmd = "paplay " + soundFile + " &";
    system(cmd.c_str());
}

void displayCSV() {
    system("cat log.csv");
}

void saveAndInput() {
    ofstream fout("log.csv", ios::app);
    if(!fout){
        cout << "Error opening file" << endl;
        return;
    }
    
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    int hour = timeinfo->tm_hour;
    int min = timeinfo->tm_min;
    if(min > 0) hour++;
    stringstream timestamp;
    timestamp << (1900 + timeinfo->tm_year)
              << setfill('0') << setw(2) << (1 + timeinfo->tm_mon)
              << setfill('0') << setw(2) << timeinfo->tm_mday
              << setfill('0') << setw(2) << hour
              << setfill('0') << setw(2) << 0;
    string dateTime = timestamp.str();
    fout << dateTime << ",";
    cout << "Enter scales (1-10) for the following parameters." << endl;
    cout << "There are 10 scale parameters to input, please input them in order." << endl;
    cout << "Anger scale (1-10): ";
    double anger = 0;
    cin >> anger;
    cout << "Hunger scale (1-10): ";
    double hunger = 0;
    cin >> hunger;
    cout << "Thirstty scale (1-10): ";
    double thirstty = 0;
    cin >> thirstty;
    double numbness = 0;
    cout << "How much scale your body leads to just exist (1-10): ";
    double leadingToExist = 0;
    cin >> leadingToExist;
    cout << "Sanity scale (1-10): ";
    double sanity = 0;
    cin >> sanity;
    cout << "Reading speed scale (1-10): ";
    double readspeed = 0;
    cin >> readspeed;
    cout << "Brain speed scale (1-10): ";
    double brainspeed = 0;
    cin >> brainspeed;
    cout << "Dopamine level scale (1-10): ";
    double dopaminelevel = 0;
    cin >> dopaminelevel;
    cout << "Sleepiness scale (1-10): ";
    double sleepiness = 0;
    cin >> sleepiness;
    cout << "Pain of hand scale (1-10): ";
    double painofhand = 0;
    cin >> painofhand;
    cout << "Ear warm scale (1-10): ";
    double earwarm = 0;
    cin >> earwarm;
    cout << "BPM scale (50 -120): ";
    double bpm = 0;
    cin >> bpm; 
    fout << anger << "," << hunger << "," << thirstty << "," << numbness << "," << leadingToExist << "," << sanity << "," << readspeed << "," << brainspeed << "," << dopaminelevel << "," << sleepiness << "," << painofhand << "," << earwarm << "," << bpm << endl;
    fout.close();
    cout << "Data saved" << endl;
}

void analyzeCSV() {
    static struct CachedData {
        vector<tuple<int, double, double, double, double, double, double, double, double, double, double, double, double, double>> records;
        bool loaded = false;
    } cache;
    
    if(!cache.loaded) {
        ifstream fin("log.csv");
        if(!fin){
            cout << "Error opening file" << endl;
            return;
        }
        
        string line;
        while(getline(fin, line)) {
            stringstream ss(line);
            string value;
            int hour = 0;
            double anger, hunger, thirstty, numbness, leadingToExist, sanity, readspeed, brainspeed, dopaminelevel, sleepiness, painofhand, earwarm, bpm;
            
            getline(ss, value, ','); hour = stoi(value.substr(8, 2));
            getline(ss, value, ','); anger = stod(value);
            getline(ss, value, ','); hunger = stod(value);
            getline(ss, value, ','); thirstty = stod(value);
            getline(ss, value, ','); numbness = stod(value);
            getline(ss, value, ','); leadingToExist = stod(value);
            getline(ss, value, ','); sanity = stod(value);
            getline(ss, value, ','); readspeed = stod(value);
            getline(ss, value, ','); brainspeed = stod(value);
            getline(ss, value, ','); dopaminelevel = stod(value);
            getline(ss, value, ','); sleepiness = stod(value);
            getline(ss, value, ','); painofhand = stod(value);
            getline(ss, value, ','); earwarm = stod(value);
            getline(ss, value); bpm = stod(value);
            
            cache.records.push_back(make_tuple(hour, anger, hunger, thirstty, numbness, leadingToExist, sanity, readspeed, brainspeed, dopaminelevel, sleepiness, painofhand, earwarm, bpm));
        }
        fin.close();
        cache.loaded = true;
    }
    
    vector<pair<int, int>> periods = {{5, 8}, {8, 12}, {12, 15}, {15, 20}, {20, 24}};
    
    for(auto period : periods) {
        double sumAnger = 0, sumHunger = 0, sumThirstty = 0, sumNumbness = 0, sumLeadingToExist = 0;
        double sumSanity = 0, sumReadSpeed = 0, sumBrainSpeed = 0, sumDopamineLevel = 0, sumSleepiness = 0;
        double sumPainOfHand = 0, sumEarwarm = 0, sumBPM = 0;
        int count = 0;
        
        for(auto record : cache.records) {
            int hour = get<0>(record);
            if(hour >= period.first && hour < period.second) {
                sumAnger += get<1>(record);
                sumHunger += get<2>(record);
                sumThirstty += get<3>(record);
                sumNumbness += get<4>(record);
                sumLeadingToExist += get<5>(record);
                sumSanity += get<6>(record);
                sumReadSpeed += get<7>(record);
                sumBrainSpeed += get<8>(record);
                sumDopamineLevel += get<9>(record);
                sumSleepiness += get<10>(record);
                sumPainOfHand += get<11>(record);
                sumEarwarm += get<12>(record);
                sumBPM += get<13>(record);
                count++;
            }
        }
        
        if(count > 0) {
            ofstream fout("analysis.csv", ios::app);
            if(!fout){
                cout << "Error opening file" << endl;
                return;
            }
            fout << period.first << ":00 - " << period.second << ":00,";
            fout << (sumAnger / count) << ",";
            fout << (sumHunger / count) << ",";
            fout << (sumThirstty / count) << ",";           
            fout << (sumNumbness / count) << ",";
            fout << (sumLeadingToExist / count) << ",";
            fout << (sumSanity / count) << ",";
            fout << (sumReadSpeed / count) << ",";
            fout << (sumBrainSpeed / count) << ",";
            fout << (sumDopamineLevel / count) << ",";
            fout << (sumSleepiness / count) << ",";
            fout << (sumPainOfHand / count) << ",";
            fout << (sumEarwarm / count) << ",";
            fout << (sumBPM / count) << endl;
            fout.close();
        }
    }
}

int main(){
    string soundFile = "./adcious_android.mp3";
    int reminderHour = 22;
    int lastReminder = -1;
    
    cout << "Log system started. Commands: 1=View CSV, 2=Input data, 3=Exit" << endl;
    cout << "-------------------------------------------------------------" << endl;
    
    while(true) {
        time_t now = time(0);
        tm* timeinfo = localtime(&now);
        if(timeinfo->tm_hour == reminderHour && lastReminder != reminderHour) {
            cout << "Time to input data!" << endl;
            playSound(soundFile);
            lastReminder = reminderHour;
        }
        
        if(timeinfo->tm_hour != reminderHour) {
            lastReminder = -1;
        }
        
        cout << "Enter command (1,2,3,4): ";
        int cmd;
        cin >> cmd;
        
        if(cmd == 1) {
            cout << "--------- CSV Contents ---------" << endl;
            displayCSV();
            cout << "--------------------------------" << endl;
        }
        else if(cmd == 2) {
            saveAndInput();
        }
        else if(cmd == 3) {
            cout << "Exiting..." << endl;
            break;
        }
        else if(cmd == 4) {
            cout << "Analyzing CSV data..." << endl;
            analyzeCSV();
        }
        else {
            cout << "Invalid command" << endl;
        }
    }
    
    return 0;
}