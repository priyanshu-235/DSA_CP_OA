#include <unordered_map>
#include<unordered_set>
#include <utility>

struct PairHash {
    size_t operator()(const std::pair<int,int>& p) const noexcept {
        // combine hash of first and second
        std::size_t h1 = std::hash<int>{}(p.first);
        std::size_t h2 = std::hash<int>{}(p.second);
        return h1 ^ (h2 << 1);  // simple combination
    }
};

std::unordered_map<std::pair<int,int>, int, PairHash> mp;
std::unordered_set<std::pair<int,int>, PairHash> st;

#include <unordered_map>

namespace std {
    template <>
    struct hash<std::pair<int,int>> {
        size_t operator()(const std::pair<int,int>& p) const noexcept {
            std::size_t h1 = std::hash<int>{}(p.first);
            std::size_t h2 = std::hash<int>{}(p.second);
            return h1 ^ (h2 << 1);
        }
    };
}

std::unordered_map<std::pair<int,int>, int> mp;


struct PairHash {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1,T2>& p) const noexcept {
        std::size_t h1 = std::hash<T1>{}(p.first);
        std::size_t h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};
std::unordered_map<std::pair<long long,long long>, int, PairHash> mp1;
std::unordered_set<std::pair<std::string,int>, PairHash> st2;

#include <unordered_map>

namespace std {
    template <>
    struct hash<std::pair<int,int>> {
        size_t operator()(const std::pair<int,int>& p) const noexcept {
            std::size_t h1 = std::hash<int>{}(p.first);
            std::size_t h2 = std::hash<int>{}(p.second);
            return h1 ^ (h2 << 1);
        }
    };
}

std::unordered_map<std::pair<int,int>, int> mp;


struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct PointHash {
    size_t operator()(const Point& p) const noexcept {
        std::size_t h1 = std::hash<int>{}(p.x);
        std::size_t h2 = std::hash<int>{}(p.y);
        return h1 ^ (h2 << 1);
    }
};

std::unordered_map<Point, int, PointHash> mp;
#include<vector>

struct VecHash {
    size_t operator()(const std::vector<int>& v) const noexcept {
        std::size_t ans = 0;
        std::hash<int> h;
        for (int x : v) {
            ans ^= h(x) + 0x9e3779b9 + (ans << 6) + (ans >> 2);
        }
        return ans;
    }
};
struct PairVecHash {
    size_t operator()(const std::pair<std::vector<int>, int>& p) const noexcept {
        VecHash vh;
        std::hash<int> hi;
        return vh(p.first) ^ (hi(p.second) << 1);
    }
};

auto pairHash = []<class T1, class T2>(const std::pair<T1,T2>& p) {
    return std::hash<T1>{}(p.first) ^ (std::hash<T2>{}(p.second) << 1);
};

std::unordered_map<
    std::pair<int,int>,
    int,
    decltype(pairHash)
> mp(10, pairHash); // 10 buckets, pass hash object

// 5. CP‑specific variations: avoiding hacks and improving speed
// 5.1. Randomized hash (splitmix-style) for unordered_map
// In Codeforces and similar contests, deterministic unordered_map can be hacked with worst‑case collision test files, causing TLE. Standard advice:

// Use a randomized custom hash: e.g., mix key with a random 64‑bit value and a strong mixing function (splitmix‑style), so an adversary cannot easily force collisions.

// Always attach this hash to any unordered_map / unordered_set you use in contests.

// Conceptually:

struct CustomHash {
    size_t operator()(uint64_t x) const noexcept {
        // add random seed, then mix bits strongly
        static const uint64_t FIXED_RANDOM = //...; // random at runtime
        x += FIXED_RANDOM;
        // apply a few shifts/multiplies to scramble bits
        // return x;
    }
};
// Then for composite keys, hash each part with CustomHash and combine.

// 5.2. gp_hash_table from pbdsMany guides recommend 
// #include<__gnu_pbds>
// __gnu_pbds::gp_hash_table<K,V,chash> (Policy Based Data Structures) as a faster hash map than unordered_map, again with a custom chash functor and often with randomization. This is particularly popular in Codeforces and USACO solutions that depend heavily on hash maps.

