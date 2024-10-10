// File: A1_T1_20230321.cpp
// Purpose: Revision on C++ concepts and Problem Solving
// Author: Mohamed Ashraf Mohamed Hassan // ID: 20230321 
// Section: s19

#include <bits/stdc++.h>
using namespace std;
void showMenu(){
    cout << "1. Correct the sentence" << endl;
    cout << "2. Prime number " << endl;
    cout << "3. Domino" << endl;
    cout << "4. Message Altering to Avoid Censorship." << endl;
    cout << "5. Exit" << endl;
}
int menu(){
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}
void mainProblem1() {
    char sentence[101];
    char ch;
    int index = 0;
    
    cout << "Enter a sentence: ";

    while (cin.get(ch) && ch != '.' && index < 99) {
        if (index > 0 && (sentence[index - 1] == ' ' && (ch == ' ' || ch == '\n'))) {
            continue;
        }
        if (ch == '\n') {
            ch = ' ';
        }
        sentence[index++] = ch;
    }

    sentence[index++] = '.';
    sentence[index] = '\0';

    if (index > 0) {
        for(int i = 0; i < index; ++i) {
            if(sentence[i] != ' ') {
                sentence[i] = toupper(sentence[i]);
                break;
            }
        }
        for (int i = 1; i < index; ++i) {
            sentence[i] = tolower(sentence[i]);
        }
    }

    cout << "Corrected sentence: " << sentence << endl;
}
void sieveAlgorithm(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }
}
int Getinput() {
    int n;
    cin >> n;
    return n;
}

void mainProblem2(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    sieveAlgorithm(n);
    cout << endl;
}
struct DominoT{
    int Left;
    int Right;
};

bool CanChain(vector<DominoT> &dominos,vector<bool> &used,int currentRight,vector<DominoT> &chain,int count){
    if(count == dominos.size()){
        return true;
    }
    for(size_t i = 0; i < dominos.size(); i++){
        if(used[i]){
            continue;
        }
        if(dominos[i].Left == currentRight){
            used[i] = true;
            chain.push_back(dominos[i]);
            if(CanChain(dominos,used,dominos[i].Right,chain,count+1)){
                return true;
            }
            chain.pop_back();
            used[i] = false;
        }
        if(dominos[i].Right == currentRight){
            used[i] = true;
            chain.push_back(dominos[i]);
            if(CanChain(dominos,used,dominos[i].Left,chain,count+1)){
                return true;
            }
            chain.pop_back();
            used[i] = false;
        }
    }
    return false;

}

bool chain(vector<DominoT> &dominos){
    vector<bool> used(dominos.size(),false);
    vector<DominoT> chain;
    for(size_t i = 0; i < dominos.size(); i++){
        used[i] = true;
        chain.push_back(dominos[i]);
        if(CanChain(dominos,used,dominos[i].Right,chain,1)){
            cout << "Domino chain: ";
            for (const auto& d : chain) {
                cout << d.Left << "|" << d.Right << " ";
            }
            cout << endl;
            
            return true;
        }
        chain.pop_back();
        used[i] = false;

    }
    cout << "No domino chain can be formed." << endl;
    return false;

}
vector<DominoT> getDominos(int n){
    vector<DominoT> dominos;
    for(int i = 0; i < n; i++){
        DominoT d;
        cin >> d.Left >> d.Right;
        dominos.push_back(d);
    }
    return dominos;

}

void mainProblem3(){
    int n;
    cout << "Enter the number of dominos: ";
    cin >> n;
    vector<DominoT> dominos = getDominos(n);
    chain(dominos);
    
}


// Function to load predefined synonyms
void loadPredefinedSynonyms(map<wstring, vector<wstring>>& synonyms) {
    synonyms[L"عنف"] = {L"اعتداء", L"عدوانية", L"عدوان"};
    synonyms[L"إرهاب"] = {L"عنف سياسي", L"تطرف", L"تهديد"};
    synonyms[L"غش"] = {L"خداع", L"تلاعب", L"احتيال"};
    synonyms[L"فساد"] = {L"انحلال", L"سوء إدارة", L"تدهور"};
    synonyms[L"كراهية"] = {L"عداء", L"ضغينة", L"بغض"};
    synonyms[L"تحرش"] = {L"اعتداء لفظي", L"إساءة", L"تعدي"};
    synonyms[L"تمييز"] = {L"انحياز", L"تفاوت", L"عدم المساواة"};
    synonyms[L"أمية"] = {L"نقص التعليم", L"عدم معرفة القراءة والكتابة", L"جهل"};
    synonyms[L"فقر"] = {L"عوز", L"احتياج", L"قلة الموارد"};
    synonyms[L"أزمة"] = {L"حالة طوارئ", L"وضع صعب", L"مشكلة حادة"};
    synonyms[L"إهانة"] = {L"تحقير", L"استهزاء", L"إزدراء"};
    synonyms[L"ممنوع"] = {L"محظور", L"غير مسموح", L"مقيد"};
    synonyms[L"خيانة"] = {L"غدر", L"عدم ولاء", L"خيانة الأمانة"};
    synonyms[L"احتجاج"] = {L"تظاهرة", L"معارضة", L"اعتصام"};
    synonyms[L"انتحار"] = {L"فقدان الأمل", L"أزمة نفسية", L"يأس"};
    synonyms[L"شغب"] = {L"اضطراب", L"فوضى", L"تمرد"};
    synonyms[L"تعصب"] = {L"تطرف", L"عدم تقبل الآخر", L"انغلاق فكري"};
    synonyms[L"تحريض"] = {L"تحريض على العنف", L"تشجيع على التوتر", L"إثارة الفوضى"};
    synonyms[L"إساءة"] = {L"سوء معاملة", L"استغلال", L"اعتداء"};
    synonyms[L"جنون"] = {L"اضطراب نفسي", L"فقدان السيطرة", L"شذوذ"};
    synonyms[L"فشل"] = {L"إخفاق", L"عدم نجاح", L"خسران"};
    synonyms[L"غضب"] = {L"انفعال", L"استياء", L"شعور بالضيق"};
    synonyms[L"تخريب"] = {L"تدمير ممتلكات", L"إتلاف", L"تخريب"};
    synonyms[L"كساد"] = {L"تراجع اقتصادي", L"أزمة مالية", L"ضعف اقتصادي"};
    synonyms[L"استغلال"] = {L"استثمار غير عادل", L"انتهاك", L"تحايل"};
    synonyms[L"خوف"] = {L"قلق", L"رعب", L"توتر"};
    synonyms[L"فقدان"] = {L"خسارة", L"انهيار", L"ضياع"};
    synonyms[L"هجوم"] = {L"اعتداء", L"غارة", L"اقتحام"};
    synonyms[L"انقسام"] = {L"خلاف", L"تفرقة", L"تصدع"};
    synonyms[L"صدمة"] = {L"انزعاج", L"تأثير نفسي", L"صدمة عاطفية"};
}

// Function to replace words in the message
void replaceCensoredWords(wstring& message, const map<wstring, vector<wstring>>& synonyms) {
    random_device rd;
    mt19937 gen(rd());

    for (const auto& pair : synonyms) {
        const wstring& word = pair.first;
        const vector<wstring>& alternatives = pair.second;

        if (!alternatives.empty()) {
            uniform_int_distribution<> dist(0, alternatives.size() - 1);

            size_t pos = 0;
            while ((pos = message.find(word, pos)) != wstring::npos) {
                wstring randomAlternative = alternatives[dist(gen)];
                message.replace(pos, word.length(), randomAlternative);
                pos += randomAlternative.length();
            }
        }
    }
}

// Function to write the message to a file
void writeMessageToFile(const string& filename, const wstring& message) {
    wofstream file(filename);  // Open as wide file stream 
    file.imbue(locale(file.getloc(), new codecvt_utf8<wchar_t>));

    if (!file.is_open()) {
        wcout << L"Error opening file for writing message." << endl;
        return;
    }

    file << message;
    file.close();
}

// Function to read a file
wstring readFile(const string& filename) {
    wifstream file(filename);
    file.imbue(locale(file.getloc(), new codecvt_utf8<wchar_t>));

    if (!file.is_open()) {
        wcout << L"Error opening file: ";
        cout << filename << endl;
        return L"";
    }

    // Read the entire file into a string (UTF-8)
    wstringstream buffer;
    buffer << file.rdbuf();
    wstring utf8Content = buffer.str();
    
    file.close();
    return utf8Content;
}

void mainProblem4() {
    map<wstring, vector<wstring>> synonyms;
    loadPredefinedSynonyms(synonyms);
    // Ask the user to input the filename
    wcout << L"Enter the filename to read the message from (e.g., message.txt): ";
    string filename;
    cin >> filename;
    wstring userMessage = readFile(filename);

    // If the file was read successfully
    if (!userMessage.empty()) {
        // Replace censored words with alternatives
        replaceCensoredWords(userMessage, synonyms);

        // Write the altered message to a new UTF-8 file
        writeMessageToFile("altered_message.txt", userMessage);

        wcout << L"Altered message written to altered_message.txt" << endl;
    } else {
        wcout << L"Failed to read the message from the file." << endl;
    }

    
}
int main(){
    while(true){
        showMenu();
        int choice = menu();
        switch(choice){
            case 1:
                mainProblem1();
                break;
            case 2:
                mainProblem2();
                break;
            case 3:
                mainProblem3();
                break;
            case 4:
                mainProblem4();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
        cout<< "======================================" << endl;
    }
}