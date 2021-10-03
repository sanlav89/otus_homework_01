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

    std::string ipAddr() const;

    // Filter by first byte
    bool filter(int &&first_byte) const;

    // Filter by first and second bytes
    bool filter(int &&first_byte, int &&second_byte) const;

    // Filter by any byte
    bool filter_any(int &&any_byte) const;

    bool operator<(const IpAddr &other);
    IpAddr& operator=(const IpAddr &other);

private:
    static const int BytesInIpAddr = 4;
    static const int SizeOfByte = 8;
    unsigned int m_value;

    int byte(const int &number) const;

};

#endif // IPADDR_H
