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
#include <cmath>
using namespace std;

void playSound(const string& soundFile) {
    string command = "audacious iphone.mp3 " + soundFile + " > /dev/null 2>&1 &";
    system(command.c_str());
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
    if(anger >= 0 && anger <= 10){
        cout << "Anger scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Anger scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "Hunger scale (1-10): ";
    double hunger = 0;
    cin >> hunger;
    if(hunger >= 0 && hunger <= 10){
        cout << "Hunger scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Hunger scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "Thirstty scale (1-10): ";
    double thirstty = 0;
    cin >> thirstty;
    if(thirstty >= 0 && thirstty <= 10){
        cout << "Thirstty scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Thirstty scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "Numbness scale (1-10): ";
    double numbness = 0;
    cin >> numbness;
    if(numbness >= 0 && numbness <= 10){
        cout << "Numbness scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Numbness scale. Please enter a value between 1 and 10." << endl;
        return;
    }

    cout << "How much scale your body leads to just exist (1-10): ";
    double leadingToExist = 0;
    cin >> leadingToExist;
    if(leadingToExist >= 0 && leadingToExist <= 10){
        cout << "Leading to exist scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Leading to exist scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "Sanity scale (1-10): ";
    double sanity = 0;
    cin >> sanity;
    if(sanity >= 0 && sanity <= 10){
        cout << "Sanity scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Sanity scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "Reading speed scale (1-10): ";
    double readspeed = 0;
    cin >> readspeed;
    if(readspeed >= 0 && readspeed <= 10){
        cout << "Reading speed scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Reading speed scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "Brain speed scale (1-10): ";
    double brainspeed = 0;
    cin >> brainspeed;
    if(brainspeed >= 0 && brainspeed <= 10){
        cout << "Brain speed scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Brain speed scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "Dopamine level scale (1-10): ";
    double dopaminelevel = 0;
    cin >> dopaminelevel;
    if(dopaminelevel >= 0 && dopaminelevel <= 10){
        cout << "Dopamine level scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Dopamine level scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "Sleepiness scale (1-10): ";
    double sleepiness = 0;
    cin >> sleepiness;
    if(sleepiness >= 0 && sleepiness <= 10){
        cout << "Sleepiness scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Sleepiness scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "Pain of hand scale (1-10): ";
    double painofhand = 0;
    cin >> painofhand;
    if(painofhand >= 0 && painofhand <= 10){
        cout << "Pain of hand scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Pain of hand scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "Ear warm scale (1-10): ";
    double earwarm = 0;
    cin >> earwarm;
    if(earwarm >= 0 && earwarm <= 10){
        cout << "Ear warm scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for Ear warm scale. Please enter a value between 1 and 10." << endl;
        return;
    }
    cout << "BPM scale (50 -120): ";
    double bpm = 0;
    cin >> bpm;
    if(bpm >= 50 && bpm <= 120){
        cout << "BPM scale inputted successfully" << endl;
    } else {
        cout << "Invalid input for BPM scale. Please enter a value between 50 and 120." << endl;
        return;
    }
    fout << anger << "," << hunger << "," << thirstty << "," << numbness << "," << leadingToExist << "," << sanity << "," << readspeed << "," << brainspeed << "," << dopaminelevel << "," << sleepiness << "," << painofhand << "," << earwarm << "," << bpm << endl;
    fout.close();
    cout << "Data saved" << endl;
}

void significant_analyze() {
    ifstream fin("log.csv");
    if(!fin){
        cout << "Error opening file" << endl;
        return;
    }
    
    vector<vector<double>> allData;
    string line;
    
    // Read all data from log.csv
    while(getline(fin, line)) {
        stringstream ss(line);
        string value;
        vector<double> row;
        
        getline(ss, value, ','); // skip timestamp
        while(getline(ss, value, ',')) {
            row.push_back(stod(value));
        }
        if(!row.empty()) {
            allData.push_back(row);
        }
    }
    fin.close();
    
    if(allData.size() < 2) {
        cout << "Insufficient data for analysis" << endl;
        return;
    }
    
    // Calculate mean and standard deviation for each parameter
    vector<double> means(allData[0].size(), 0);
    vector<double> stddevs(allData[0].size(), 0);
    
    for(size_t col = 0; col < allData[0].size(); col++) {
        // Calculate mean: sum all values and divide by count
        double sum = 0;
        for(size_t row = 0; row < allData.size(); row++) {
            sum += allData[row][col];
        }
        means[col] = sum / allData.size();  // mean = Σx / n
        
        // Calculate standard deviation using sample formula
        double sumSq = 0;
        for(size_t row = 0; row < allData.size(); row++) {
            // Sum of squared deviations from mean
            sumSq += (allData[row][col] - means[col]) * (allData[row][col] - means[col]);
        }
        // Sample standard deviation: sqrt(Σ(x - mean)² / (n - 1))
        stddevs[col] = sqrt(sumSq / (allData.size() - 1));
    }
    
    // Calculate p-values (using coefficient of variation as significance metric)
    ofstream fout("significant_value.csv");
    if(!fout){
        cout << "Error opening file" << endl;
        return;
    }
    
    vector<string> paramNames = {"Anger", "Hunger", "Thirsty", "Numbness", "LeadingToExist", 
                                  "Sanity", "ReadSpeed", "BrainSpeed", "DopamineLevel", 
                                  "Sleepiness", "PainOfHand", "Earwarm", "BPM"};
    
    fout << "Parameter,Mean,StdDev,CV,PValue" << endl;
    
    for(size_t col = 0; col < allData[0].size() && col < paramNames.size(); col++) {
        double cv = (means[col] != 0) ? (stddevs[col] / means[col]) : 0;
        double pvalue = 2.0 / (1.0 + exp(cv)); // Sigmoid-based p-value
        
        fout << paramNames[col] << "," 
             << fixed << setprecision(4) << means[col] << "," 
             << stddevs[col] << "," 
             << cv << "," 
             << pvalue << endl;
    }
    fout.close();
    cout << "Analysis complete. Results saved to significant_value.csv" << endl;
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
    string soundFile = "../adcious_iphone.mp3";
    int lastReminder = -1;
    
    cout << "Log system started. Commands: 1=View CSV, 2=Input data, 3=Exit" << endl;
    cout << "-------------------------------------------------------------" << endl;
    
    while(true) {
        // 現在の時刻を取得
        time_t now = time(0);
        // ローカルタイムに変換
        tm* timeinfo = localtime(&now);
        // 現在の時刻を分単位で計算（時間 × 60 + 分）
        int currentMinute = timeinfo->tm_hour * 60 + timeinfo->tm_min;
        // リマインダーの分を60分単位で丸める
        int reminderMinute = (currentMinute / 60) * 60;
        
        if(reminderMinute != lastReminder && timeinfo->tm_min == 0) {
            cout << "Time to input data!" << endl;
            playSound(soundFile);
            lastReminder = reminderMinute;
        }
        
        int cmd = 0;
        cout << "---------------------------------------------" << endl;
        cout << " 1: Show csv file,\n 2: Input data,\n 3: Exit,\n 4: Analyze the csv file,\n 5: Show Significant Analysis.csv file\n" << endl;
        cout << "Enter command (1,2,3,4,5): ";
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
            cout << "Perfoming significant analysis..." << endl;
            analyzeCSV();
            significant_analyze();
    
        }
        else if(cmd == 5) {
            system("cat significant_value.csv");
        }

        else {
            cout << "Invalid command" << endl;
        }
    }
    
    return 0;
}