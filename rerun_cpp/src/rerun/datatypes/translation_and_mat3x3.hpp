// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/translation_and_mat3x3.fbs".

#pragma once

#include "../data_cell.hpp"
#include "../result.hpp"
#include "mat3x3.hpp"
#include "vec3d.hpp"

#include <cstdint>
#include <memory>
#include <optional>

namespace arrow {
    class DataType;
    class StructBuilder;
} // namespace arrow

namespace rerun::datatypes {
    /// **Datatype**: Representation of an affine transform via a 3x3 affine matrix paired with a translation.
    ///
    /// First applies the matrix, then the translation.
    struct TranslationAndMat3x3 {
        /// 3D translation, applied after the matrix.
        std::optional<rerun::datatypes::Vec3D> translation;

        /// 3x3 matrix for scale, rotation & shear.
        std::optional<rerun::datatypes::Mat3x3> mat3x3;

        /// If true, this transform is from the parent space to the space where the transform was logged.
        ///
        /// If false (default), the transform maps from this space to its parent,
        /// i.e. the translation is the position in the parent space.
        bool from_parent;

      public:
        // Extensions to generated type defined in 'translation_and_mat3x3_ext.cpp'

        /// Identity transformation.
        ///
        /// Applying this transform does not alter an entity's transformation.
        /// It has all optional fields set to `std::nullopt`.
        static const TranslationAndMat3x3 IDENTITY;

        /// Creates a new 3D transform from translation/matrix.
        ///
        /// \param translation_ \copydoc TranslationAndMat3x3::translation
        /// \param mat3x3_ \copydoc TranslationAndMat3x3::mat3x3
        /// \param from_parent_ \copydoc TranslationAndMat3x3::from_parent
        TranslationAndMat3x3(
            const std::optional<Vec3D>& translation_, const std::optional<Mat3x3>& mat3x3_,
            bool from_parent_
        )
            : translation(translation_), mat3x3(mat3x3_), from_parent(from_parent_) {}

        /// From rotation only.
        ///
        /// \param mat3x3_ \copydoc TranslationAndMat3x3::mat3x3
        /// \param from_parent_ \copydoc TranslationAndMat3x3::from_parent
        TranslationAndMat3x3(const Mat3x3& mat3x3_, bool from_parent_ = false)
            : translation(std::nullopt), mat3x3(mat3x3_), from_parent(from_parent_) {}

        /// From translation only.
        ///
        /// \param translation_ \copydoc TranslationAndMat3x3::translation
        /// \param from_parent_ \copydoc TranslationAndMat3x3::from_parent
        TranslationAndMat3x3(const Vec3D& translation_, bool from_parent_ = false)
            : translation(translation_), mat3x3(std::nullopt), from_parent(from_parent_) {}

      public:
        TranslationAndMat3x3() = default;
    };
} // namespace rerun::datatypes

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<datatypes::TranslationAndMat3x3> {
        static constexpr const char Name[] = "rerun.datatypes.TranslationAndMat3x3";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::StructBuilder* builder, const datatypes::TranslationAndMat3x3* elements,
            size_t num_elements
        );

        /// Creates a Rerun DataCell from an array of `rerun::datatypes::TranslationAndMat3x3` components.
        static Result<rerun::DataCell> to_data_cell(
            const datatypes::TranslationAndMat3x3* instances, size_t num_instances
        );
    };
} // namespace rerun
