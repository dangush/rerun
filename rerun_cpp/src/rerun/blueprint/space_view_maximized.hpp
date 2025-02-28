// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/blueprint/space_view_maximized.fbs".

#pragma once

#include "../collection.hpp"
#include "../data_cell.hpp"
#include "../result.hpp"

#include <cstdint>
#include <memory>
#include <optional>
#include <utility>

namespace arrow {
    class DataType;
    class ListBuilder;
} // namespace arrow

namespace rerun::blueprint {
    /// **Blueprint**: Whether a space view is maximized.
    ///
    /// Unstable. Used for the ongoing blueprint experimentations.
    struct SpaceViewMaximized {
        std::optional<rerun::Collection<uint8_t>> id;

      public:
        SpaceViewMaximized() = default;

        SpaceViewMaximized(std::optional<rerun::Collection<uint8_t>> id_) : id(std::move(id_)) {}

        SpaceViewMaximized& operator=(std::optional<rerun::Collection<uint8_t>> id_) {
            id = std::move(id_);
            return *this;
        }
    };
} // namespace rerun::blueprint

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<blueprint::SpaceViewMaximized> {
        static constexpr const char Name[] = "rerun.blueprint.SpaceViewMaximized";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::ListBuilder* builder, const blueprint::SpaceViewMaximized* elements,
            size_t num_elements
        );

        /// Creates a Rerun DataCell from an array of `rerun::blueprint::SpaceViewMaximized` components.
        static Result<rerun::DataCell> to_data_cell(
            const blueprint::SpaceViewMaximized* instances, size_t num_instances
        );
    };
} // namespace rerun
