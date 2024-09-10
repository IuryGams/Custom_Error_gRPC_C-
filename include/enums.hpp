#pragma once

enum class ErrorType
{
    UNKNOWN_ERROR,
    FRAME_IS_TOO_SHORT,
    CHECKSUM_DOES_NOT_MATCH,
    INVALID_ADDRESS,
};