// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/blueprint/panel_view.fbs".

#pragma once

#include "../result.hpp"

#include <cstdint>
#include <memory>

namespace arrow {
    class DataType;
    class MemoryPool;
    class StructBuilder;
} // namespace arrow

namespace rerun {
    namespace blueprint {
        /// **Blueprint**: The state of the panels.
        ///
        /// Unstable. Used for the ongoing blueprint experimentations.
        struct PanelView {
            bool is_expanded;

          public:
            PanelView() = default;

            PanelView(bool is_expanded_) : is_expanded(is_expanded_) {}

            PanelView& operator=(bool is_expanded_) {
                is_expanded = is_expanded_;
                return *this;
            }

            /// Returns the arrow data type this type corresponds to.
            static const std::shared_ptr<arrow::DataType>& arrow_datatype();

            /// Creates a new array builder with an array of this type.
            static Result<std::shared_ptr<arrow::StructBuilder>> new_arrow_array_builder(
                arrow::MemoryPool* memory_pool
            );

            /// Fills an arrow array builder with an array of this type.
            static rerun::Error fill_arrow_array_builder(
                arrow::StructBuilder* builder, const PanelView* elements, size_t num_elements
            );
        };
    } // namespace blueprint
} // namespace rerun
