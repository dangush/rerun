// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/testing/archetypes/fuzzy.fbs".

#include "affix_fuzzer3.hpp"

#include <rerun/collection_adapter_builtins.hpp>

namespace rerun::archetypes {}

namespace rerun {

    Result<std::vector<DataCell>> AsComponents<archetypes::AffixFuzzer3>::serialize(
        const archetypes::AffixFuzzer3& archetype
    ) {
        using namespace archetypes;
        std::vector<DataCell> cells;
        cells.reserve(19);

        if (archetype.fuzz2001.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer1>::to_data_cell(
                &archetype.fuzz2001.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2002.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer2>::to_data_cell(
                &archetype.fuzz2002.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2003.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer3>::to_data_cell(
                &archetype.fuzz2003.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2004.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer4>::to_data_cell(
                &archetype.fuzz2004.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2005.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer5>::to_data_cell(
                &archetype.fuzz2005.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2006.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer6>::to_data_cell(
                &archetype.fuzz2006.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2007.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer7>::to_data_cell(
                &archetype.fuzz2007.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2008.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer8>::to_data_cell(
                &archetype.fuzz2008.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2009.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer9>::to_data_cell(
                &archetype.fuzz2009.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2010.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer10>::to_data_cell(
                &archetype.fuzz2010.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2011.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer11>::to_data_cell(
                &archetype.fuzz2011.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2012.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer12>::to_data_cell(
                &archetype.fuzz2012.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2013.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer13>::to_data_cell(
                &archetype.fuzz2013.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2014.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer14>::to_data_cell(
                &archetype.fuzz2014.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2015.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer15>::to_data_cell(
                &archetype.fuzz2015.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2016.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer16>::to_data_cell(
                &archetype.fuzz2016.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2017.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer17>::to_data_cell(
                &archetype.fuzz2017.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        if (archetype.fuzz2018.has_value()) {
            auto result = Loggable<rerun::components::AffixFuzzer18>::to_data_cell(
                &archetype.fuzz2018.value(),
                1
            );
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }
        {
            auto indicator = AffixFuzzer3::IndicatorComponent();
            auto result = Loggable<AffixFuzzer3::IndicatorComponent>::to_data_cell(&indicator, 1);
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }

        return cells;
    }
} // namespace rerun
