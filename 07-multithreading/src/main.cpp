#include <iostream>
#include <string>
#include <thread>      // for std::thread
#include <chrono>      // for std::chrono
#include <functional>  // for std::ref std::cref
#include <future>      // for std::future std::promise std::async
#include <mutex>       // for std::lock_guard std::unique_lock std::scoped_lock
#include <random>      // for std::uniform_int_distribution
#include <set>         // for std::set
#include <utility>     // for std::pair

void blink_thread_fun(const unsigned int id,
                      const std::chrono::milliseconds delay_ms)
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "  blink_thread_fun, id=" << id << " is blinking" << std::endl;
        std::this_thread::sleep_for(delay_ms);
    }

    std::cout << "  Finish blink_thread_fun, id=" << id << std::endl;;
}

void pop_thread_fun(const int& count)
{
    using namespace std::chrono_literals;

    if (0 >= count)
    {
        std::cerr << "Error : pop_thread_fun count must be greater than zero" << std::endl;
        return;
    }
    for (int i = count; i >= 0; --i)
    {
        std::cout << "  pop_thread_fun" << std::endl;
        std::this_thread::sleep_for(500ms);
    }
    std::cout << "  Finish pop_thread_fun" << std::endl;
}

class custom_class
{
public:
    custom_class() = default;

    void do_stuff()
    {
        auto start = std::chrono::steady_clock::now();
        unsigned long long fib {1};
        for (unsigned long long i = 0; i < 1000000u; ++i)
        {
            sdfsdf  // todo : I stop here !!!!!!!!!!!!!!!!!!!!!!
        }

    }

    void operator()()
    {
        do_stuff();
    }
};

/**
 * \brief Generates random numbers and sum results. This function should take a lot of time.
 */
std::pair<std::set<int>, unsigned int> gen_and_sum(const int count)
{
    std::random_device rd;
    std::mt19937 gen {rd()};
    std::uniform_int_distribution<int> distribution {0};  // from zero to max
    std::set<int> random_numbers;
    
    for (int i = 0; i < count; ++i)
    {
        random_numbers.insert(distribution(gen));
    }

    unsigned int sum {0};
    for ( const auto& el : random_numbers)
    {
        sum += static_cast<unsigned int>(el);
    }

    return std::make_pair(std::move(random_numbers), sum);
}

int main(int /*argc*/, char** /*argv*/)
{
    using namespace std::chrono_literals;

    std::cout << "Examples for multithreading" << std::endl << std::endl;

    // Case 1
    std::cout << "Case 1" << std::endl;
    std::thread blink_thread {blink_thread_fun, 101u, 200ms};  // this start imediatelly
    std::thread blink_2_thread {blink_thread_fun, 201u, 210ms};
    blink_thread.join();  // wait for finish thread
    blink_2_thread.join();

    int pop_count = 2;
    std::thread pop_thread {pop_thread_fun, std::cref(pop_count)};
    pop_thread.join();

    // Case 2 std::async and locks
    std::cout << "Case 2, std::async and locks" << std::endl;

    auto start_time = std::chrono::steady_clock::now();

    auto a2first = std::async(std::launch::async, gen_and_sum, 1000000);
    auto a2second = std::async(std::launch::async, gen_and_sum, 1000000);
    auto a2third = std::async(std::launch::async, gen_and_sum, 1000000);

    auto a2first_result = a2first.get();
    auto a2second_result = a2second.get();
    auto a2third_result = a2third.get();
    // auto a2first_result = gen_and_sum(1000000);  // todo : at mingw this is faster than async, why?
    // auto a2second_result = gen_and_sum(1000000);
    // auto a2third_result = gen_and_sum(1000000);

    auto end_time_dur = std::chrono::steady_clock::now() - start_time;
    std::cout << "  takes " << std::chrono::duration_cast<std::chrono::milliseconds>( end_time_dur ).count() << "ms"
              << std::endl;

    std::cout << "  a2first len=" << a2first_result.first.size() << ", sum=" << a2first_result.second << std::endl;
    std::cout << "  a2second len=" << a2second_result.first.size() << ", sum=" << a2second_result.second << std::endl;
    std::cout << "  a2third len=" << a2third_result.first.size() << ", sum=" << a2third_result.second << std::endl;
    
    return 0;
}

