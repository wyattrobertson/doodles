
#ifndef PYTHONEXTENSION_ACCUMULATE_HPP
#define PYTHONEXTENSION_ACCUMULATE_HPP

#include <iterator>

/**
 * Apply a function over the distance between two iterators starting with
 * the element pointed to by the first iterator and the passed value.
 *
 * @tparam Iterator A forward iterator.
 * @tparam Value The type to be accumulated.
 * @tparam Function The function to apply over the iterator range.
 * @param begin An iterator definining the first element to start.
 * @param end An iterator defining the last element to end on.
 * @param value The first value to start accumulation with.
 * @param function The function to apply between each element.
 * @return The accumulated value.
 */
template <typename Iterator, typename Value, typename Function>
Value accumulate(Iterator begin, Iterator end, Value&& value, Function&& function)
{
    while (begin != end)
    {
        value = function(value, *begin);
        ++begin;
    }
    return value;
}

/**
 * Apply a function over the distance between two iterators starting with
 * the element pointed to by the first iterator and the passed value.
 *
 * @tparam Iterator A forward iterator.
 * @tparam Value The type to be accumulated.
 * @param begin An iterator definining the first element to start.
 * @param end An iterator defining the last element to end on.
 * @param value The first value to start accumulation with.
 * @return The accumulated value.
 */
template <typename Iterator, typename Value>
Value accumulate(Iterator begin, Iterator end, Value&& value)
{
    while (begin != end)
    {
        value = value + *begin;
        ++begin;
    }
    return value;
}

#endif // PYTHONEXTENSION_ACCUMULATE_HPP

