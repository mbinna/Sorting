#include <cassert>
#include <iterator>

namespace {

template <class RandomIt>
RandomIt partition(RandomIt first, RandomIt last, RandomIt pivot)
{
    auto previousToLast = std::prev(last);
    auto pivotValue = *pivot;

    // Move pivot element to the end.
    std::swap(*pivot, *previousToLast);

    auto storeIndex = first;

    // Determine index for pivot element.
    for (auto i = first; i < previousToLast; ++i) {
        if (*i <= pivotValue) {
            std::swap(*i, *storeIndex);
            ++storeIndex;
        }
    }

    // Restore pivot element at determined index.
    std::swap(*storeIndex, *previousToLast);

    return storeIndex;
}

template <class RandomIt>
void quicksort(RandomIt first, RandomIt last)
{
    if (first >= last)
        return;

    // Pick pivot index and partition.
    auto pivot = first + std::distance(first, std::prev(last)) / 2;
    pivot = partition(first, last, pivot);
    
    // Sort each partition.
    quicksort(first, std::prev(pivot));
    quicksort(std::next(pivot), last);
}

} // namespace

namespace Binna {

template <class RandomIt>
void sortImpl(RandomIt first, RandomIt last, std::random_access_iterator_tag)
{
    assert(first <= last);
    quicksort(first, last);
}

template <class RandomIt>
void sort(RandomIt first, RandomIt last)
{
    typedef typename std::iterator_traits<RandomIt>::iterator_category category;
    sortImpl(first, last, category());
}

} // namespace Binna
