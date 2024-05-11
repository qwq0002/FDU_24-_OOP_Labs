#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "ns_common.h"
#include "stopwatch.h"

using namespace std;
using namespace EXP4;

static const int Times = 100;

void test_create(istream&);
void test_contain();
void test_not_contain();
void test_insert_lookup_remove();
void test();

int main()
{
    test();
    return 0;
}

inline void log_time(Stopwatch& sw, size_t count=1)
{
    clog << "using time " << setprecision(8) << sw.getMilliseconds()/count << "ms\n";
}

void test()
{
    Stopwatch sw;
    sw.start();
    clog << "test create:      ";
    test_create(cin);
    sw.stop();
    log_time(sw);

    sw.start();
    clog << "test contains:    ";
    test_contain();
    sw.stop();
    log_time(sw);

    sw.start();
    clog << "test not contains:";
    test_not_contain();
    sw.stop();
    log_time(sw);

    sw.start();
    clog << "test insert/lookup/remove:";
    test_insert_lookup_remove();
    sw.stop();
    log_time(sw);
}

void test_create(istream& in)
{
    create(in);
}

void test_contain()
{
    vector<string> hostnames = {"xino1.com","somaskme.com","northernloudmouth.com", 
                                "jinjieinc.com", "emrstorage.com", "best3homesinsiouxfalls.com",
                                "wfzhcz.com","samoanew.com","mggbt951.com",
                                "hernandofierro.com","coloradovtc.com","baba49.net"
                                };
    int times = 0;
    for(auto n=0; n<Times; ++n){
        for(const auto& hostname: hostnames)
        {
            if(contain(hostname))
                ++times;
        }
        cout << ".";
    }
    cout << "done!\n";
}

void test_not_contain()
{
    vector<string> hostnames_ = {   "google.com","bing.com","baidu.com",
                                    "sina.com","yahoo.com","tesla.com",
                                    "z.com","abc.com","cnn.com",
                                    "fudan.edu.cn","taobao.com","gaode.com"
                                    };
    
    int times = 0;
    for(auto n=0; n<Times; ++n)
    {
        for(const auto& hostname: hostnames_)
        {
            if(!contain(hostname))
                ++times;
        }
        cout << ".";
    }
    cout << "done!\n";
}

void test_insert_lookup_remove()
{
    vector<string> hostnames_ = {   "google.com","bing.com","baidu.com",
                                    "sina.com","yahoo.com","tesla.com",
                                    "z.com","abc.com","cnn.com",
                                    "fudan.edu.cn","taobao.com","gaode.com"
                                    };
    
    int times = 0;
    for(auto n=0; n<Times; ++n)
    {
        for(const auto& hostname: hostnames_)
        {
            IPAddress ipaddress = 1;
            insert(hostname, ipaddress);
            ++times;
        }
        for(const auto& hostname: hostnames_)
        {
            IPAddress ipaddress = lookup(hostname);
            ++times;
        }

        for(const auto& hostname: hostnames_)
        {
            IPAddress ipaddress = 1;
            if(remove(hostname))
                ++times;
        }
        cout << ".";
    }
    cout << "done!\n";
}
