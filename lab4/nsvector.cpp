#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

#include "ns_common.h"
#include "split.h"

using namespace std;

namespace EXP4 {

    using VNS = std::vector<std::pair<std::string, int> >;
    static const int REPORT_INTERVAL = 20000;
    static VNS vns;

    void create(std::istream &in) {
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

    bool contain(const HostName &hostname) {
        auto it = find_if(vns.begin(), vns.end(), [&hostname](const std::pair<std::string, int> &vns_pair) {
            return vns_pair.first == hostname;
        });

        return it != vns.end();
    }

    void insert(const HostName &hostname, const IPAddress &ip_address) {
        vns.push_back(make_pair(hostname, ip_address));
    }

    bool remove(const HostName &hostname) {
        if (!contain(hostname))
            return false;
        auto it = remove_if(vns.begin(), vns.end(), [&hostname](const std::pair<std::string, int> vns_pair) {
            return vns_pair.first == hostname;
        });
        vns.erase(it, vns.end());

        return true;
    }

    IPAddress lookup(const HostName &hostname) {
        auto it = find_if(vns.begin(), vns.end(), [&hostname](const std::pair<std::string, int> &vns_pair) {
            return vns_pair.first == hostname;
        });
        IPAddress ip_addr;
        if(it == vns.end())
            ip_addr = NON_EXISTING_ADDRESS;
        else
            ip_addr = (*it).second;

        return ip_addr;
    }

}