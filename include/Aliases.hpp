#ifndef ALIASES_H
#define ALIASES_H

#include <memory>

template <typename T>
using U = std::unique_ptr<T>;

template <typename T>
using S = std::shared_ptr<T>;

#endif