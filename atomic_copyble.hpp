#pragma once
#Include <atomic>
//copyble std::atomic
template <typename T>
struct atomic {

    atomic() {}

    atomic(const atomic& other) {
        lock.store(other.lock.load());
    }

    inline atomic& operator=(const atomic& other) {
        if (this != &other) {
            lock.store(other.lock.load());
        }
        return *this;
    }

    atomic(atomic&& other) noexcept {
        lock.store(other.lock.load());
    }

    atomic& operator=(atomic&& other) noexcept {
        if (this != &other) {
            lock.store(other.lock.load());
        }
        return *this;
    }
    inline decltype(auto) operator -> () const noexcept {
        return &lock;
    }

    inline decltype(auto) operator -> () noexcept {
        return &lock;
    }

    std::atomic<T> lock{};

};
