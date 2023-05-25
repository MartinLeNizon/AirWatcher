#if ! defined (Conversions_H)
#define Conversions_H


using namespace std;
#include <string>
#include <ctime>

inline time_t stringToTime_t(string &dateStr){
    tm timeinfo = {};

    // Lecture des composants de la date et de l'heure depuis la chaîne de caractères
    sscanf(dateStr.c_str(), "%d-%d-%d %d:%d:%d", &timeinfo.tm_year, &timeinfo.tm_mon,
           &timeinfo.tm_mday, &timeinfo.tm_hour, &timeinfo.tm_min, &timeinfo.tm_sec);
    
    // Les composants tm_year et tm_mon nécessitent des ajustements
    timeinfo.tm_year -= 1900; // L'année est relative à 1900
    timeinfo.tm_mon -= 1;     // Les mois sont numérotés à partir de 0 (0 = janvier)
    
    // Conversion de la struct tm en time_t
    time_t time = mktime(&timeinfo);
    return time;
}

inline string time_tToString(time_t time){
    tm* timeinfo = localtime(&time);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    string date=buffer;
    return date;
}

#endif