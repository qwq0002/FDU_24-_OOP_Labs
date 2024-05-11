#pragma once

#include <string>
#include <istream>

namespace EXP4 {

using HostName = std::string;
using IPAddress = unsigned int;
const IPAddress NON_EXISTING_ADDRESS = 0;


void create(std::istream& in);
bool contain(const HostName&);
void insert(const HostName&, const IPAddress&);
bool remove(const HostName&);
IPAddress lookup(const HostName&);

};
