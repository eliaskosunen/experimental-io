#pragma once

#include <type_traits>
#include <experimental/ranges/concepts>
#include <experimental/ranges/ranges>
#include <xio/bits/prelude.hpp>

XIO_BEGIN_NAMESPACE

template <class T>
META_CONCEPT UniquelyRepresented = std::has_unique_object_representations_v<T>;

template <class T>
META_CONCEPT TriviallyBufferable = UniquelyRepresented<T>;

template <class T>
META_CONCEPT Byte = TriviallyBufferable<T> && RANGES_NS::Regular<T> && sizeof(T) == 1;

template <RANGES_NS::Range Rng>
META_CONCEPT TriviallyBufferableRange = RANGES_NS::ContiguousRange<Rng> &&
    RANGES_NS::SizedRange<Rng> &&
    TriviallyBufferable<RANGES_NS::iter_value_t<RANGES_NS::iterator_t<Rng>>>;

template <RANGES_NS::Range Rng>
META_CONCEPT ByteRange = TriviallyBufferableRange<Rng> &&
    Byte<RANGES_NS::iter_value_t<RANGES_NS::iterator_t<Rng>>>;

XIO_END_NAMESPACE
