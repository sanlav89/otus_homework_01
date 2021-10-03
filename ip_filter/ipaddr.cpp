#include "ipaddr.h"

std::vector<std::string> IpAddr::split(const std::string &str, char d)
{
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos) {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));
    return r;
}

IpAddr::IpAddr() : m_value(0)
{
}

IpAddr::IpAddr(const IpAddr &other) : m_value(other.m_value)
{
}

IpAddr::IpAddr(const std::string &ipAddr) : m_value(0)
{
    std::vector<std::string> bytes = split(ipAddr, '.');
    unsigned int value = 0;
    if (bytes.size() == BytesInIpAddr) {
        for (auto i = 0u; i < BytesInIpAddr; i++) {
            value += std::stoi(bytes.at(i)) << ((bytes.size() - i - 1) * SizeOfByte);
        }
    }
    m_value = value;
}

std::string IpAddr::ipAddr() const
{
    std::string result;
    for (auto i = 0; i < BytesInIpAddr; i++) {
        result.append(std::to_string(this->byte(i)));
        if (i < BytesInIpAddr - 1) {
            result.append(".");
        }
    }
    return result;
}

// Filter by first byte
bool IpAddr::filter(unsigned int &&first_byte) const
{
    return this->byte(0) == first_byte;
}

// Filter by first and second bytes
bool IpAddr::filter(unsigned int &&first_byte, unsigned int &&second_byte) const
{
    return this->byte(0) == first_byte && this->byte(1) == second_byte;
}

// Filter by any byte
bool IpAddr::filter_any(unsigned int &&any_byte) const
{
    return this->byte(0) == any_byte
            || this->byte(1) == any_byte
            || this->byte(2) == any_byte
            || this->byte(3) == any_byte
            ;
}

bool IpAddr::operator<(const IpAddr &other)
{
    return m_value > other.m_value;
}

IpAddr& IpAddr::operator=(const IpAddr &other)
{
    if (this == &other) {
        return *this;
    }
    m_value = other.m_value;
    return *this;
}
