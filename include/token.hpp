#pragma once
#include <ostream>
#include <string_view>

namespace semp {
enum class TokenType {
  _RETURN,
  _IDENTIFIER,
  _INT_LITERAL,
  _STR_LITERAL,
  _LEFT_BRACE,
  _RIGHT_BRACE,
  _SEMICOLON,
  _EOF
};

struct Token {
  TokenType type;
  std::string_view lexeme;
  int line;
};

inline const char* to_string(TokenType type) {
  switch (type) {
    case TokenType::_IDENTIFIER:
      return "IDENTIFIER";
    case TokenType::_RETURN:
      return "RETURN";
    case TokenType::_INT_LITERAL:
      return "INT_LITERAL";
    case TokenType::_STR_LITERAL:
      return "STR_LITERAL";
    case TokenType::_LEFT_BRACE:
      return "LEFT_BRACE";
    case TokenType::_RIGHT_BRACE:
      return "RIGHT_BRACE";
    case TokenType::_SEMICOLON:
      return "SEMICOLON";
    case TokenType::_EOF:
      return "EOF";
    default:
      return "UNKNOWN";
  }
}

inline std::ostream& operator<<(std::ostream& os, const Token& token) {
  os << to_string(token.type) << "(" << token.lexeme << ")";
  return os;
}
}  // namespace semp
