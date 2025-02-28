// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/archetypes/view_coordinates.fbs".

#pragma once

#include "../collection.hpp"
#include "../components/view_coordinates.hpp"
#include "../data_cell.hpp"
#include "../indicator_component.hpp"
#include "../result.hpp"

#include <cstdint>
#include <utility>
#include <vector>

namespace rerun::archetypes {
    /// **Archetype**: How we interpret the coordinate system of an entity/space.
    ///
    /// For instance: What is "up"? What does the Z axis mean? Is this right-handed or left-handed?
    ///
    /// The three coordinates are always ordered as [x, y, z].
    ///
    /// For example [Right, Down, Forward] means that the X axis points to the right, the Y axis points
    /// down, and the Z axis points forward.
    ///
    /// ## Example
    ///
    /// ### View coordinates for adjusting the eye camera
    /// ![image](https://static.rerun.io/viewcoordinates/0833f0dc8616a676b7b2c566f2a6f613363680c5/full.png)
    ///
    /// ```cpp
    /// #include <rerun.hpp>
    ///
    /// int main() {
    ///     const auto rec = rerun::RecordingStream("rerun_example_view_coordinates");
    ///     rec.spawn().exit_on_failure();
    ///
    ///     rec.log_timeless("world", rerun::ViewCoordinates::RIGHT_HAND_Z_UP); // Set an up-axis
    ///     rec.log(
    ///         "world/xyz",
    ///         rerun::Arrows3D::from_vectors({{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}}
    ///         ).with_colors({{255, 0, 0}, {0, 255, 0}, {0, 0, 255}})
    ///     );
    /// }
    /// ```
    struct ViewCoordinates {
        rerun::components::ViewCoordinates xyz;

      public:
        static constexpr const char IndicatorComponentName[] =
            "rerun.components.ViewCoordinatesIndicator";

        /// Indicator component, used to identify the archetype when converting to a list of components.
        using IndicatorComponent = components::IndicatorComponent<IndicatorComponentName>;

      public:
        // Extensions to generated type defined in 'view_coordinates_ext.cpp'

        /// Construct Vec3D from x/y/z values.
        constexpr ViewCoordinates(uint8_t axis0, uint8_t axis1, uint8_t axis2)
            : xyz(rerun::components::ViewCoordinates(axis0, axis1, axis2)) {}

        // <BEGIN_GENERATED:declarations>
        // This section is generated by running `scripts/generate_view_coordinate_defs.py --cpp`
        static const rerun::archetypes::ViewCoordinates ULF;
        static const rerun::archetypes::ViewCoordinates UFL;
        static const rerun::archetypes::ViewCoordinates LUF;
        static const rerun::archetypes::ViewCoordinates LFU;
        static const rerun::archetypes::ViewCoordinates FUL;
        static const rerun::archetypes::ViewCoordinates FLU;
        static const rerun::archetypes::ViewCoordinates ULB;
        static const rerun::archetypes::ViewCoordinates UBL;
        static const rerun::archetypes::ViewCoordinates LUB;
        static const rerun::archetypes::ViewCoordinates LBU;
        static const rerun::archetypes::ViewCoordinates BUL;
        static const rerun::archetypes::ViewCoordinates BLU;
        static const rerun::archetypes::ViewCoordinates URF;
        static const rerun::archetypes::ViewCoordinates UFR;
        static const rerun::archetypes::ViewCoordinates RUF;
        static const rerun::archetypes::ViewCoordinates RFU;
        static const rerun::archetypes::ViewCoordinates FUR;
        static const rerun::archetypes::ViewCoordinates FRU;
        static const rerun::archetypes::ViewCoordinates URB;
        static const rerun::archetypes::ViewCoordinates UBR;
        static const rerun::archetypes::ViewCoordinates RUB;
        static const rerun::archetypes::ViewCoordinates RBU;
        static const rerun::archetypes::ViewCoordinates BUR;
        static const rerun::archetypes::ViewCoordinates BRU;
        static const rerun::archetypes::ViewCoordinates DLF;
        static const rerun::archetypes::ViewCoordinates DFL;
        static const rerun::archetypes::ViewCoordinates LDF;
        static const rerun::archetypes::ViewCoordinates LFD;
        static const rerun::archetypes::ViewCoordinates FDL;
        static const rerun::archetypes::ViewCoordinates FLD;
        static const rerun::archetypes::ViewCoordinates DLB;
        static const rerun::archetypes::ViewCoordinates DBL;
        static const rerun::archetypes::ViewCoordinates LDB;
        static const rerun::archetypes::ViewCoordinates LBD;
        static const rerun::archetypes::ViewCoordinates BDL;
        static const rerun::archetypes::ViewCoordinates BLD;
        static const rerun::archetypes::ViewCoordinates DRF;
        static const rerun::archetypes::ViewCoordinates DFR;
        static const rerun::archetypes::ViewCoordinates RDF;
        static const rerun::archetypes::ViewCoordinates RFD;
        static const rerun::archetypes::ViewCoordinates FDR;
        static const rerun::archetypes::ViewCoordinates FRD;
        static const rerun::archetypes::ViewCoordinates DRB;
        static const rerun::archetypes::ViewCoordinates DBR;
        static const rerun::archetypes::ViewCoordinates RDB;
        static const rerun::archetypes::ViewCoordinates RBD;
        static const rerun::archetypes::ViewCoordinates BDR;
        static const rerun::archetypes::ViewCoordinates BRD;
        static const rerun::archetypes::ViewCoordinates RIGHT_HAND_X_UP;
        static const rerun::archetypes::ViewCoordinates RIGHT_HAND_X_DOWN;
        static const rerun::archetypes::ViewCoordinates RIGHT_HAND_Y_UP;
        static const rerun::archetypes::ViewCoordinates RIGHT_HAND_Y_DOWN;
        static const rerun::archetypes::ViewCoordinates RIGHT_HAND_Z_UP;
        static const rerun::archetypes::ViewCoordinates RIGHT_HAND_Z_DOWN;
        static const rerun::archetypes::ViewCoordinates LEFT_HAND_X_UP;
        static const rerun::archetypes::ViewCoordinates LEFT_HAND_X_DOWN;
        static const rerun::archetypes::ViewCoordinates LEFT_HAND_Y_UP;
        static const rerun::archetypes::ViewCoordinates LEFT_HAND_Y_DOWN;
        static const rerun::archetypes::ViewCoordinates LEFT_HAND_Z_UP;
        static const rerun::archetypes::ViewCoordinates LEFT_HAND_Z_DOWN;
        // <END_GENERATED:declarations>

      public:
        ViewCoordinates() = default;
        ViewCoordinates(ViewCoordinates&& other) = default;

        explicit ViewCoordinates(rerun::components::ViewCoordinates _xyz) : xyz(std::move(_xyz)) {}

        /// Returns the number of primary instances of this archetype.
        size_t num_instances() const {
            return 1;
        }
    };

} // namespace rerun::archetypes

namespace rerun {
    /// \private
    template <typename T>
    struct AsComponents;

    /// \private
    template <>
    struct AsComponents<archetypes::ViewCoordinates> {
        /// Serialize all set component batches.
        static Result<std::vector<DataCell>> serialize(const archetypes::ViewCoordinates& archetype
        );
    };
} // namespace rerun
