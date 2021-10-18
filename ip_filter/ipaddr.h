#ifndef IPADDR_H
#define IPADDR_H

#include <string>
#include <vector>
#include <algorithm>

class IpAddr
{
public:

    // ("",  '.') -> [""]
    // ("11", '.') -> ["11"]
    // ("..", '.') -> ["", "", ""]
    // ("11.", '.') -> ["11", ""]
    // (".11", '.') -> ["", "11"]
    // ("11.22", '.') -> ["11", "22"]
    static std::vector<std::string> split(const std::string &str, char d);

    IpAddr();
    IpAddr(const IpAddr &other);
    IpAddr(const std::string &ipAddr);

    std::string to_string() const;

    auto byte(const int &number) const
    {
        if (number >= 0 && number < BytesInIpAddr) {
            return (m_value >> ((BytesInIpAddr - number - 1) * SizeOfByte) & 0xFF);
        }
        return 0;
    }

    bool operator<(const IpAddr &other);
    IpAddr& operator=(const IpAddr &other);

private:
    static const int BytesInIpAddr = 4;
    static const int SizeOfByte = 8;
    int m_value;

    bool isValidByteValue(const std::string &byte_str);
    bool isValidByteValue(const unsigned int &byte);

};

#endif // IPADDR_H
