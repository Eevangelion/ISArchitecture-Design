#pragma once

#include <exception/exception.h>

class error_handler_t {
    public:
        static error_handler_t& get_instance();
        
        enum class error_type {
            EXIT_EXCEPTION,
            FILE_NOT_FOUND_EXCEPTION,
            FILE_IS_DIRECTORY_EXCEPTION,
            INVALID_INPUT_EXCEPTION,
            POPEN_FAILED_EXCEPTION,
        };

        void throw_error(error_handler_t::error_type const& type, std::string const& desc = "");

        /*
        * Метод для обработки ошибок. Если возвращает true, то работа программы будет завершена.
        */
        bool handle_error(error_handler_t::error_type const& type);

    private:
        error_handler_t() = default;
        error_handler_t(error_handler_t const&) = delete;
        void operator=(error_handler_t const&) = delete;

        std::string desc;
};