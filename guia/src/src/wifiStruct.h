#ifndef WIFISTRUCT_H
#define WIFISTRUCT_H

#include <string>
#include <vector>

using namespace std;


struct WIFI
{
        string BSSID;
        string Channel;
        string frequency;
        string Quality;
        string signal;
        string key;
        string ESSID;
        string mode;
        string beacon;
        string tsf;
        vector<int> senyal;
};

#endif // WIFISTRUCT_H
