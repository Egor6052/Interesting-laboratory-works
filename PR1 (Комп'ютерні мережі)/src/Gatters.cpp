#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include <array>
#include "../lib/Computer.h"

std::string execCommand(const std::string& cmd) {
    std::string result;
    // Відкриваємо процес для виконання команди
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        Computer::error("failed!");
    }
    
    // тут 128 - розмір буфера для зберігання результату
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe)) {
        result += buffer;
    }
    
    // Закриваємо процес
    pclose(pipe);
    
    return result;
}

std::string Computer::getNamePC() {
    return execCommand("../bash/get_name_pc.sh");
}

std::string Computer::getAddresLocalNetwork() {
    return execCommand("../bash/get_address_local_network.sh");
}

std::string Computer::getIP() {
    return execCommand("../bash/get_ip.sh");
}

std::string Computer::getMAC() {
    return execCommand("../bash/get_mac.sh");
}

std::string Computer::getTechnologyLocalNetwork() {
    return execCommand("../bash/get_technology_local_network.sh");
}

std::string Computer::getNetworkAdress() {
    return execCommand("../bash/get_network_address.sh");
}

std::string Computer::getNetworkMask() {
    return execCommand("../bash/get_network_mask.sh");
}

std::string Computer::getGatewayAdress() {
    return execCommand("../bash/get_gateway_address.sh");
}

std::string Computer::getInterface() {
    return execCommand("../bash/get_interface.sh");
}

std::string Computer::getMetrics() {
    return execCommand("../bash/get_metrics.sh");
}