#include <span>
#include <optional>

void testSpan() {
    auto data = std::span<char> (new char[100], 100);
    auto option = std::optional<char>{'a'};

}
