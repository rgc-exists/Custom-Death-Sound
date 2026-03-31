#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace deathsounds::utils {
    std::string formatDate(int32_t timestamp) {
        using namespace std::chrono;
        auto seconds = static_cast<time_t>(timestamp);
        auto tp = system_clock::from_time_t(seconds);
        return fmt::format("{:%Y-%m-%d}", tp);
    }
};