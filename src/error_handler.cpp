#include "error_handler.h"

#include <iostream>
#include <string>

error_handler_t& error_handler_t::get_instance() {
    static error_handler_t handler;
    return handler;
}

void error_handler_t::throw_error(error_handler_t::error_type const& type, std::string const& desc) {
    if (desc != "") {
        this->desc = desc;
    };

    throw type;
}

bool error_handler_t::handle_error(error_handler_t::error_type const& type) {
    switch (type) {
        case error_type::EXIT_EXCEPTION:
            std::cout << "Exit!" << std::endl;
            return true;
        case error_type::FILE_NOT_FOUND_EXCEPTION:
        case error_type::INVALID_INPUT_EXCEPTION:
        case error_type::POPEN_FAILED_EXCEPTION:
            std::cout << desc << std::endl;
            return false;
    }
}