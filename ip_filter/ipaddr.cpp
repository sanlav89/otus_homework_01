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

IpAddr::IpAddr() :
    m_value{0}
{
}

IpAddr::IpAddr(const IpAddr &other) :
    m_value{other.m_value}
{
}

IpAddr::IpAddr(const std::string &ipAddr)
    : m_value{0}
{
    std::vector<std::string> bytes = split(ipAddr, '.');
    auto value = 0;
    if (bytes.size() == BytesInIpAddr) {
        for (auto i = 0u; i < BytesInIpAddr; i++) {
            if (!isValidByteValue(bytes.at(i))) {
                throw std::string("ERROR! Incorrect format: ") + ipAddr;
            }
            auto byte = std::stoi(bytes.at(i));
            if (!isValidByteValue(byte)) {
                throw std::string("ERROR! Value of any byte can't be greater than 255: ") + ipAddr;
            }
            value += byte << ((bytes.size() - i - 1) * SizeOfByte);
        }
    }
    m_value = value;
}

std::string IpAddr::to_string() const
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

bool IpAddr::operator<(const IpAddr &other)
{
    return m_value > other.m_value;
}

bool IpAddr::isValidByteValue(const std::string &byte_str)
{
    if (byte_str.size() > 3) {
        return false;
    }
    for (const auto &c : byte_str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool IpAddr::isValidByteValue(const unsigned int &byte)
{
    if (byte > 255) {
        return false;
    }
    return true;
}
