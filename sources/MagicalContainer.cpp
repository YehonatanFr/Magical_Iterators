#include "MagicalContainer.hpp"

bool isPrime(int num) {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}


namespace ariel {

    // MagicalContainer

    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element) {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    int MagicalContainer::size() const {
        return elements.size();
    }

    // AscendingIterator

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& cont, std::vector<int>::const_iterator it)
        : container(cont), iterator(it) {}

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        // TODO: Implement the increment operator
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        // TODO: Implement the equality operator
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        // TODO: Implement the inequality operator
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        // TODO: Implement the greater than operator
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        // TODO: Implement the less than operator
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        // TODO: Implement the dereference operator
        return 0;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin(){
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end() {
        return *this;
    }

    // SideCrossIterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& cont,
        std::vector<int>::const_iterator fwdIt, std::vector<int>::const_reverse_iterator revIt, bool fwd)
        : container(cont), forwardIterator(fwdIt), reverseIterator(revIt), forward(fwd) {}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        // TODO: Implement the increment operator
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        // TODO: Implement the equality operator
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        // TODO: Implement the inequality operator
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        // TODO: Implement the greater than operator
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        // TODO: Implement the less than operator
        return false;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        // TODO: Implement the dereference operator
        return 0;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator:: begin(){
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator:: end() {
        return *this;
    }

    // PrimeIterator

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& cont, std::vector<int>::const_iterator it)
        : container(cont), iterator(it) {
        while (iterator != container.elements.end() && !isPrime(*iterator))
            ++iterator;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        // TODO: Implement the increment operator
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        // TODO: Implement the equality operator
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        // TODO: Implement the inequality operator
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        // TODO: Implement the greater than operator
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        // TODO: Implement the less than operator
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        // TODO: Implement the dereference operator
        return 0;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator:: begin(){
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator:: end(){
        return *this;
    }
} 
