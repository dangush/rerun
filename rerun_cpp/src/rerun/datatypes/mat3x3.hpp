// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/mat3x3.fbs".

#pragma once

#include "../data_cell.hpp"
#include "../result.hpp"
#include "vec3d.hpp"

#include <array>
#include <cstdint>
#include <memory>

namespace arrow {
    class DataType;
    class FixedSizeListBuilder;
} // namespace arrow

namespace rerun::datatypes {
    /// **Datatype**: A 3x3 Matrix.
    ///
    /// Matrices in Rerun are stored as flat list of coefficients in column-major order:
    /// ```text
    ///             column 0       column 1       column 2
    ///        -------------------------------------------------
    /// row 0 | flat_columns[0] flat_columns[3] flat_columns[6]
    /// row 1 | flat_columns[1] flat_columns[4] flat_columns[7]
    /// row 2 | flat_columns[2] flat_columns[5] flat_columns[8]
    /// ```
    struct Mat3x3 {
        /// Flat list of matrix coefficients in column-major order.
        std::array<float, 9> flat_columns;

      public:
        // Extensions to generated type defined in 'mat3x3_ext.cpp'

        static const Mat3x3 IDENTITY;

        /// Creates a new 3x3 matrix from 3 *columns* of 3 elements each.
        Mat3x3(const Vec3D (&columns)[3])
            : flat_columns{
                  columns[0].x(),
                  columns[0].y(),
                  columns[0].z(),
                  columns[1].x(),
                  columns[1].y(),
                  columns[1].z(),
                  columns[2].x(),
                  columns[2].y(),
                  columns[2].z(),
              } {}

        /// Construct a new 3x3 matrix from a pointer to 9 floats (in row major order).
        explicit Mat3x3(const float* elements)
            : flat_columns{
                  elements[0],
                  elements[1],
                  elements[2],
                  elements[3],
                  elements[4],
                  elements[5],
                  elements[6],
                  elements[7],
                  elements[8],
              } {}

      public:
        Mat3x3() = default;

        Mat3x3(std::array<float, 9> flat_columns_) : flat_columns(flat_columns_) {}

        Mat3x3& operator=(std::array<float, 9> flat_columns_) {
            flat_columns = flat_columns_;
            return *this;
        }
    };
} // namespace rerun::datatypes

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<datatypes::Mat3x3> {
        static constexpr const char Name[] = "rerun.datatypes.Mat3x3";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::FixedSizeListBuilder* builder, const datatypes::Mat3x3* elements,
            size_t num_elements
        );

        /// Creates a Rerun DataCell from an array of `rerun::datatypes::Mat3x3` components.
        static Result<rerun::DataCell> to_data_cell(
            const datatypes::Mat3x3* instances, size_t num_instances
        );
    };
} // namespace rerun
