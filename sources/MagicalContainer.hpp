#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <algorithm>

// namespace ariel
namespace ariel {

    class MagicalContainer {
    private:
        std::vector<int> elements;

    public:
        void addElement(int element);
        void removeElement(int element);
        int size() const;

        class AscendingIterator {
        private:
            const MagicalContainer& container;
            std::vector<int>::const_iterator iterator;

        public:
            AscendingIterator(const MagicalContainer& cont, std::vector<int>::const_iterator it);
            AscendingIterator& operator++();
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;

            AscendingIterator &begin();
            AscendingIterator &end();
        };

        class SideCrossIterator {
        private:
            const MagicalContainer& container;
            std::vector<int>::const_iterator forwardIterator;
            std::vector<int>::const_reverse_iterator reverseIterator;
            bool forward;

        public:
            SideCrossIterator(const MagicalContainer& cont, std::vector<int>::const_iterator fwdIt,
                std::vector<int>::const_reverse_iterator revIt, bool fwd);
            SideCrossIterator& operator++();
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;

            SideCrossIterator &begin();
            SideCrossIterator &end();
        };

        class PrimeIterator {
        private:
            const MagicalContainer& container;
            std::vector<int>::const_iterator iterator;

        public:
            PrimeIterator(const MagicalContainer& cont, std::vector<int>::const_iterator it);
            PrimeIterator& operator++();
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;

            PrimeIterator &begin();
            PrimeIterator &end();
        };

    };

} 


#endif
