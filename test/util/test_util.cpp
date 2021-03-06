#include <gtest/gtest.h>
#include <iostream>
#include "util/util.h"

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

namespace kit {

TEST(testUtil, caseCpuUsage) {
    std::cout << CPUUsage() << std::endl;
}

TEST(testUtil, caseZone) {
    std::cout << Zone() << std::endl;
}

TEST(testUtil, caseHttpGet) {
    std::string body;
    int         status;
    std::tie(status, body, std::ignore) = HttpGet("http://www.baidu.com");
    std::cout << status << " " << body << std::endl;

    std::map<std::string, std::string> header;
    std::tie(status, body, header, std::ignore) = HttpGet("http://www.baidu.com", std::map<std::string, std::string>{});

    for (const auto& kv : header) {
        std::cout << kv.first << " => " << kv.second << std::endl;
    }
}

}
