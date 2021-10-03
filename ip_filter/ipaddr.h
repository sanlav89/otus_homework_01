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
    bool filter(unsigned int &&first_byte) const;

    // Filter by first and second bytes
    bool filter(unsigned int &&first_byte, unsigned int &&second_byte) const;

    // Filter by any byte
    bool filter_any(unsigned int &&any_byte) const;

    bool operator<(const IpAddr &other);
    IpAddr& operator=(const IpAddr &other);

private:
    static const int BytesInIpAddr = 4;
    static const int SizeOfByte = 8;
    unsigned int m_value;

    auto byte(const int &number) const
    {
        if (number >= 0 && number < BytesInIpAddr) {
            return (m_value >> ((BytesInIpAddr - number - 1) * SizeOfByte) & 0xFF);
        }
        return 0u;
    }

};

#endif // IPADDR_H
