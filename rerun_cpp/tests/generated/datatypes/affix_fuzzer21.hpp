// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/testing/datatypes/fuzzy.fbs".

#pragma once

#include <cstdint>
#include <memory>
#include <rerun/collection.hpp>
#include <rerun/data_cell.hpp>
#include <rerun/half.hpp>
#include <rerun/result.hpp>

namespace arrow {
    class DataType;
    class StructBuilder;
} // namespace arrow

namespace rerun::datatypes {
    struct AffixFuzzer21 {
        rerun::half single_half;

        rerun::Collection<rerun::half> many_halves;

      public:
        AffixFuzzer21() = default;
    };
} // namespace rerun::datatypes

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<datatypes::AffixFuzzer21> {
        static constexpr const char Name[] = "rerun.testing.datatypes.AffixFuzzer21";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::StructBuilder* builder, const datatypes::AffixFuzzer21* elements,
            size_t num_elements
        );

        /// Creates a Rerun DataCell from an array of `rerun::datatypes::AffixFuzzer21` components.
        static Result<rerun::DataCell> to_data_cell(
            const datatypes::AffixFuzzer21* instances, size_t num_instances
        );
    };
} // namespace rerun
