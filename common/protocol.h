#pragma once
#include <cstdint>

namespace protocol {
    enum TcpMsgType: uint8_t {
        MSG_JOIN,
        MSG_INPUT,
        MSG_LEAVE
    };

    // Константы для валидации на сервере
    constexpr std::size_t TCP_HEADER_SIZE = 3;
    constexpr std::size_t JOIN_SIZE = 2;
    constexpr std::size_t INPUT_SIZE = 8;
    // TODO: continue later

    



}