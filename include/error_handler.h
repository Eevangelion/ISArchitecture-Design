#pragma once

#include <string>

/*
* Класс-синглтон, отвечающий за обработку ошибок в программе.
*/
class error_handler_t {
    public:
        /*
        * Позволяет получить уникальный экземпляр класса.
        */
        static error_handler_t& get_instance();

        /*
        * Перечисление с классификацией возможных ошибок.
        */
        
        enum class error_type {
            EXIT_EXCEPTION,
            FILE_NOT_FOUND_EXCEPTION,
            FILE_IS_DIRECTORY_EXCEPTION,
            INVALID_INPUT_EXCEPTION,
            POPEN_FAILED_EXCEPTION,
            ARGUMENTS_INVALID_EXCEPTION,
        };

        /*
        * Выдает ошибку и сохраняет её описание, если таковое есть, в приватном поле класса.
        */

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