#include "catch2.hpp"
#include <grpcpp/grpcpp.h>
#include <unordered_map>
#include "pantheon_ng.hpp"
#include "reason.hpp"


using namespace ees::pantheon_ng;
using namespace ees::exceptions;

// Teste básico de exceção
TEST_CASE("Test PantheonNgExceptions", "[pantheon_ng_exceptions]") {
    // Verificar se a exceção é lançada corretamente
    SECTION("Exceção com INVALID_ARGUMENT") {
        ees::pantheon_ng::PantheonNgExceptions ex(
            ees::exceptions::ErrorType::INVALID_ARGUMENT,
            PantheonNgExceptionReason::ADINF_COULD_NOT_BE_LESS_THEN_PRINF
        );

        // Verificar a mensagem de erro
        REQUIRE(std::string(ex.what()) == "ADINF_COULD_NOT_BE_LESS_THEN_PRINF");
    }

    SECTION("Exceção com NOT_FOUND") {
        ees::pantheon_ng::PantheonNgExceptions ex(
            ees::exceptions::ErrorType::NOT_FOUND,
            PantheonNgExceptionReason::FIRST_DISPLAY_TO_CONFIGURE_MUST_BE_METER_FLAG_ERROR
        );

        REQUIRE(std::string(ex.what()) == "FIRST_DISPLAY_TO_CONFIGURE_MUST_BE_METER_FLAG_ERROR");
    }

    SECTION("Exceção com UNKNOWN_ERROR") {
        ees::pantheon_ng::PantheonNgExceptions ex(
            ees::exceptions::ErrorType::UNKNOWN,
            PantheonNgExceptionReason::MISSING_EXCEPTION_ON_ELETRA_SDK
        );

        REQUIRE(std::string(ex.what()) == "MISSING_EXCEPTION_ON_ELETRA_SDK");
    }
}

// Teste para valores desconhecidos
TEST_CASE("Test PantheonNgExceptions with unknown error", "[pantheon_ng_exceptions]") {
    SECTION("Exceção com erro desconhecido") {
        ees::pantheon_ng::PantheonNgExceptions ex(
            ees::exceptions::ErrorType::UNKNOWN,
            static_cast<PantheonNgExceptionReason>(999) // Valor inválido
        );

        REQUIRE(std::string(ex.what()) == "MISSING_EXCEPTION_ON_ELETRA_SDK");
    }
}