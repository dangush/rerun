// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/archetypes/line_strips3d.fbs".

#include "line_strips3d.hpp"

#include "../collection_adapter_builtins.hpp"

namespace rerun::archetypes {}

namespace rerun {

    Result<std::vector<DataCell>> AsComponents<archetypes::LineStrips3D>::serialize(
        const archetypes::LineStrips3D& archetype
    ) {
        using namespace archetypes;
        std::vector<DataCell> cells;
        cells.reserve(7);

        {
            auto result = Loggable<rerun::components::LineStrip3D>::to_data_cell(
                archetype.strips.data(),
                archetype.strips.size()
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.radii.has_value()) {
            auto result = Loggable<rerun::components::Radius>::to_data_cell(
                archetype.radii.value().data(),
                archetype.radii.value().size()
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.colors.has_value()) {
            auto result = Loggable<rerun::components::Color>::to_data_cell(
                archetype.colors.value().data(),
                archetype.colors.value().size()
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.labels.has_value()) {
            auto result = Loggable<rerun::components::Text>::to_data_cell(
                archetype.labels.value().data(),
                archetype.labels.value().size()
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.class_ids.has_value()) {
            auto result = Loggable<rerun::components::ClassId>::to_data_cell(
                archetype.class_ids.value().data(),
                archetype.class_ids.value().size()
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.instance_keys.has_value()) {
            auto result = Loggable<rerun::components::InstanceKey>::to_data_cell(
                archetype.instance_keys.value().data(),
                archetype.instance_keys.value().size()
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        {
            auto indicator = LineStrips3D::IndicatorComponent();
            auto result = Loggable<LineStrips3D::IndicatorComponent>::to_data_cell(&indicator, 1);
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }

        return cells;
    }
} // namespace rerun
