// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/archetypes/arrows3d.fbs".

#pragma once

#include "../collection.hpp"
#include "../compiler_utils.hpp"
#include "../components/class_id.hpp"
#include "../components/color.hpp"
#include "../components/instance_key.hpp"
#include "../components/position3d.hpp"
#include "../components/radius.hpp"
#include "../components/text.hpp"
#include "../components/vector3d.hpp"
#include "../data_cell.hpp"
#include "../indicator_component.hpp"
#include "../result.hpp"

#include <cstdint>
#include <optional>
#include <utility>
#include <vector>

namespace rerun::archetypes {
    /// **Archetype**: 3D arrows with optional colors, radii, labels, etc.
    ///
    /// ## Example
    ///
    /// ### Simple batch of 3D Arrows
    /// ![image](https://static.rerun.io/arrow3d_simple/55e2f794a520bbf7527d7b828b0264732146c5d0/full.png)
    ///
    /// ```cpp
    /// #include <rerun.hpp>
    ///
    /// #include <cmath>
    /// #include <vector>
    ///
    /// constexpr float TAU = 6.28318530717958647692528676655900577f;
    ///
    /// int main() {
    ///     const auto rec = rerun::RecordingStream("rerun_example_arrow3d");
    ///     rec.spawn().exit_on_failure();
    ///
    ///     std::vector<rerun::Position3D> origins;
    ///     std::vector<rerun::Vector3D> vectors;
    ///     std::vector<rerun::Color> colors;
    ///
    ///     for (int i = 0; i <100; ++i) {
    ///         origins.push_back({0, 0, 0});
    ///
    ///         float angle = TAU * static_cast<float>(i) * 0.01f;
    ///         float length = log2f(static_cast<float>(i + 1));
    ///         vectors.push_back({length * sinf(angle), 0.0, length * cosf(angle)});
    ///
    ///         uint8_t c = static_cast<uint8_t>(round(angle / TAU * 255.0f));
    ///         colors.push_back({static_cast<uint8_t>(255 - c), c, 128, 128});
    ///     }
    ///
    ///     rec.log(
    ///         "arrows",
    ///         rerun::Arrows3D::from_vectors(vectors).with_origins(origins).with_colors(colors)
    ///     );
    /// }
    /// ```
    struct Arrows3D {
        /// All the vectors for each arrow in the batch.
        Collection<rerun::components::Vector3D> vectors;

        /// All the origin (base) positions for each arrow in the batch.
        ///
        /// If no origins are set, (0, 0, 0) is used as the origin for each arrow.
        std::optional<Collection<rerun::components::Position3D>> origins;

        /// Optional radii for the arrows.
        ///
        /// The shaft is rendered as a line with `radius = 0.5 * radius`.
        /// The tip is rendered with `height = 2.0 * radius` and `radius = 1.0 * radius`.
        std::optional<Collection<rerun::components::Radius>> radii;

        /// Optional colors for the points.
        std::optional<Collection<rerun::components::Color>> colors;

        /// Optional text labels for the arrows.
        std::optional<Collection<rerun::components::Text>> labels;

        /// Optional class Ids for the points.
        ///
        /// The class ID provides colors and labels if not specified explicitly.
        std::optional<Collection<rerun::components::ClassId>> class_ids;

        /// Unique identifiers for each individual point in the batch.
        std::optional<Collection<rerun::components::InstanceKey>> instance_keys;

      public:
        static constexpr const char IndicatorComponentName[] = "rerun.components.Arrows3DIndicator";

        /// Indicator component, used to identify the archetype when converting to a list of components.
        using IndicatorComponent = components::IndicatorComponent<IndicatorComponentName>;

      public:
        // Extensions to generated type defined in 'arrows3d_ext.cpp'

        /// Creates new 3D arrows pointing in the given directions, with a base at the origin (0, 0,
        /// 0).
        static Arrows3D from_vectors(Collection<components::Vector3D> vectors_) {
            Arrows3D arrows;
            arrows.vectors = std::move(vectors_);
            return arrows;
        }

      public:
        Arrows3D() = default;
        Arrows3D(Arrows3D&& other) = default;

        /// All the origin (base) positions for each arrow in the batch.
        ///
        /// If no origins are set, (0, 0, 0) is used as the origin for each arrow.
        Arrows3D with_origins(Collection<rerun::components::Position3D> _origins) && {
            origins = std::move(_origins);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RERUN_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Optional radii for the arrows.
        ///
        /// The shaft is rendered as a line with `radius = 0.5 * radius`.
        /// The tip is rendered with `height = 2.0 * radius` and `radius = 1.0 * radius`.
        Arrows3D with_radii(Collection<rerun::components::Radius> _radii) && {
            radii = std::move(_radii);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RERUN_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Optional colors for the points.
        Arrows3D with_colors(Collection<rerun::components::Color> _colors) && {
            colors = std::move(_colors);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RERUN_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Optional text labels for the arrows.
        Arrows3D with_labels(Collection<rerun::components::Text> _labels) && {
            labels = std::move(_labels);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RERUN_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Optional class Ids for the points.
        ///
        /// The class ID provides colors and labels if not specified explicitly.
        Arrows3D with_class_ids(Collection<rerun::components::ClassId> _class_ids) && {
            class_ids = std::move(_class_ids);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RERUN_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Unique identifiers for each individual point in the batch.
        Arrows3D with_instance_keys(Collection<rerun::components::InstanceKey> _instance_keys) && {
            instance_keys = std::move(_instance_keys);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RERUN_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Returns the number of primary instances of this archetype.
        size_t num_instances() const {
            return vectors.size();
        }
    };

} // namespace rerun::archetypes

namespace rerun {
    /// \private
    template <typename T>
    struct AsComponents;

    /// \private
    template <>
    struct AsComponents<archetypes::Arrows3D> {
        /// Serialize all set component batches.
        static Result<std::vector<DataCell>> serialize(const archetypes::Arrows3D& archetype);
    };
} // namespace rerun
