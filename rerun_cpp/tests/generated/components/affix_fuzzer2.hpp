// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/testing/components/fuzzy.fbs".

#pragma once

#include "../datatypes/affix_fuzzer1.hpp"

#include <cstdint>
#include <memory>
#include <rerun/data_cell.hpp>
#include <rerun/result.hpp>
#include <utility>

namespace arrow {
    class DataType;
    class StructBuilder;
} // namespace arrow

namespace rerun::components {
    struct AffixFuzzer2 {
        rerun::datatypes::AffixFuzzer1 single_required;

      public:
        AffixFuzzer2() = default;

        AffixFuzzer2(rerun::datatypes::AffixFuzzer1 single_required_)
            : single_required(std::move(single_required_)) {}

        AffixFuzzer2& operator=(rerun::datatypes::AffixFuzzer1 single_required_) {
            single_required = std::move(single_required_);
            return *this;
        }

        /// Cast to the underlying AffixFuzzer1 datatype
        operator rerun::datatypes::AffixFuzzer1() const {
            return single_required;
        }
    };
} // namespace rerun::components

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<components::AffixFuzzer2> {
        static constexpr const char Name[] = "rerun.testing.components.AffixFuzzer2";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::StructBuilder* builder, const components::AffixFuzzer2* elements,
            size_t num_elements
        );

        /// Creates a Rerun DataCell from an array of `rerun::components::AffixFuzzer2` components.
        static Result<rerun::DataCell> to_data_cell(
            const components::AffixFuzzer2* instances, size_t num_instances
        );
    };
} // namespace rerun
