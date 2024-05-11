#include <map>
#include <iostream>
#include <algorithm>
#include <cassert>

#include "ns_common.h"
#include "split.h"

using namespace std;

namespace EXP4 {

    using MNS = std::map<std::string, int>;
    static const int REPORT_INTERVAL = 20000;
    static MNS mns;

    void create(std::istream& in){
        string line;
        int count = 0;
        while (getline(in, line)) {
            vector<string> parts = split(line);
            assert(parts.size() == 2);
            string hostname = parts[0];
            IPAddress ipaddress = std::stoi(parts[1]);
            if (!contain(hostname)) {
                insert(hostname, ipaddress);
                ++count;
            }
            if (count % REPORT_INTERVAL == 0) cout << ".";
        }
        cout << "done!\n";
    }

    bool contain(const HostName& hostname){
        auto it = mns.find(hostname);

        return it != mns.end();
    }

    void insert(const HostName& hostname, const IPAddress& ipaddress){
        mns.insert(make_pair(hostname, ipaddress));
    }

    bool remove(const HostName& hostname){
        if (!contain(hostname))
            return false;
        auto it = mns.find(hostname);
        mns.erase(it);

        return true;
    }

    IPAddress lookup(const HostName& hostname){
        auto it = mns.find(hostname);
        IPAddress ip_addr;
        if(it == mns.end())
            ip_addr = NON_EXISTING_ADDRESS;
        else
            ip_addr = (*it).second;

        return ip_addr;
    }


};