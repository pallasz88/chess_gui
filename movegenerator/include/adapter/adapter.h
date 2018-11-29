#pragma once


#define GENERATOR_API __declspec(dllexport)

#include <string>

namespace Chess
{
    GENERATOR_API bool IsValidMove(std::string &move);

    GENERATOR_API void ParseFen(std::string &fenPosition);

    GENERATOR_API std::string GetFen();
}