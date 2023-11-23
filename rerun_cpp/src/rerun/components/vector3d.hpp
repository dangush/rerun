// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/vector3d.fbs".

#pragma once

#include "../data_cell.hpp"
#include "../datatypes/vec3d.hpp"
#include "../result.hpp"

#include <array>
#include <cstdint>
#include <memory>

namespace arrow {
    class DataType;
    class FixedSizeListBuilder;
} // namespace arrow

namespace rerun::components {
    /// **Component**: A vector in 3D space.
    struct Vector3D {
        rerun::datatypes::Vec3D vector;

      public:
        // Extensions to generated type defined in 'vector3d_ext.cpp'

        /// Construct Vector3D from x/y/z values.
        Vector3D(float x, float y, float z) : vector{x, y, z} {}

        /// Construct Vec3D from x/y/z float pointer.
        explicit Vector3D(const float* xyz) : vector{xyz[0], xyz[1], xyz[2]} {}

        float x() const {
            return vector.x();
        }

        float y() const {
            return vector.y();
        }

        float z() const {
            return vector.z();
        }

      public:
        Vector3D() = default;

        Vector3D(rerun::datatypes::Vec3D vector_) : vector(vector_) {}

        Vector3D& operator=(rerun::datatypes::Vec3D vector_) {
            vector = vector_;
            return *this;
        }

        Vector3D(std::array<float, 3> xyz_) : vector(xyz_) {}

        Vector3D& operator=(std::array<float, 3> xyz_) {
            vector = xyz_;
            return *this;
        }

        /// Cast to the underlying Vec3D datatype
        operator rerun::datatypes::Vec3D() const {
            return vector;
        }
    };
} // namespace rerun::components

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<components::Vector3D> {
        static constexpr const char Name[] = "rerun.components.Vector3D";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::FixedSizeListBuilder* builder, const components::Vector3D* elements,
            size_t num_elements
        );

        /// Creates a Rerun DataCell from an array of `rerun::components::Vector3D` components.
        static Result<rerun::DataCell> to_data_cell(
            const components::Vector3D* instances, size_t num_instances
        );
    };
} // namespace rerun
