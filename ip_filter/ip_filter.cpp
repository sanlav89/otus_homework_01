#include <cassert>
#include <cstdlib>
#include <iostream>
#include <list>
#include "ipaddr.h"

int main()
{
    try {

        // Input
        std::vector<IpAddr> ip_pool;
        ip_pool.reserve(1000);
        for(std::string line; std::getline(std::cin, line);) {
            std::vector<std::string> v = IpAddr::split(line, '\t');
            ip_pool.push_back(IpAddr(v.at(0)));
        }

        // Функции фильтрации:
        auto without_filter = [&ip_pool]()
        {
            for (auto ip = ip_pool.cbegin(); ip != ip_pool.end(); ++ip) {
                std::cout << ip->to_string() << std::endl;
            }
        };

        auto filter1 = [&ip_pool](auto first_byte)
        {
            for (auto ip = ip_pool.cbegin(); ip != ip_pool.end(); ++ip) {
                if (ip->byte(0) == first_byte) {
                    std::cout << ip->to_string() << std::endl;
                }
            }
        };

        auto filter2 = [&ip_pool](auto first_byte, auto second_byte)
        {
            for (auto ip = ip_pool.cbegin(); ip != ip_pool.end(); ++ip) {
                if (ip->byte(0) == first_byte && ip->byte(1) == second_byte) {
                    std::cout << ip->to_string() << std::endl;
                }
            }
        };

        auto filter_any = [&ip_pool](auto any_byte)
        {
            for (auto ip = ip_pool.cbegin(); ip != ip_pool.end(); ++ip) {
                if (ip->byte(0) == any_byte
                        || ip->byte(1) == any_byte
                        || ip->byte(2) == any_byte
                        || ip->byte(3) == any_byte
                        ) {
                    std::cout << ip->to_string() << std::endl;
                }
            }
        };

        // Reverse lexicographically sort
        std::sort(ip_pool.begin(), ip_pool.end());

        // Output all IPs
        without_filter();

        // Filter by first byte and output
        // ip = filter(1)
        filter1(1);

        // Filter by first and second bytes and output
        // ip = filter(46, 70)
        filter2(46, 70);

        // Filter by any byte and output
        // ip = filter_any(46)
        filter_any(46);

    } catch (const std::exception &e) {
        std::cerr << "Standart exception: " << e.what() << std::endl;
    } catch (const IpAddr &ip_addr) {
        std::cerr << "Error on ip-address: " << ip_addr.to_string() << std::endl;
    } catch (const std::string &msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}
