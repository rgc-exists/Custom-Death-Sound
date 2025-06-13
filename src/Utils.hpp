#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace deathsounds::utils {
    std::string formatDate(int32_t millis) {
        using namespace std::chrono;
        std::time_t seconds = static_cast<std::time_t>(millis);
        std::tm local_tm = fmt::localtime(seconds);
        return fmt::format("{:%Y-%m-%d}", local_tm);
    }
};