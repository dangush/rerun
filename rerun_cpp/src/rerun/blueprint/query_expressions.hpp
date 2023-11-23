// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/blueprint/query_expressions.fbs".

#pragma once

#include "../collection.hpp"
#include "../data_cell.hpp"
#include "../result.hpp"

#include <cstdint>
#include <memory>
#include <string>
#include <utility>

namespace arrow {
    class DataType;
    class StructBuilder;
} // namespace arrow

namespace rerun::blueprint {
    /// **Blueprint**: A set of expressions used for a `DataQueryBlueprint`.
    ///
    /// Unstable. Used for the ongoing blueprint experimentations.
    struct QueryExpressions {
        /// A set of strings that can be parsed as `EntityPathExpression`s.
        rerun::Collection<std::string> expressions;

      public:
        QueryExpressions() = default;

        QueryExpressions(rerun::Collection<std::string> expressions_)
            : expressions(std::move(expressions_)) {}

        QueryExpressions& operator=(rerun::Collection<std::string> expressions_) {
            expressions = std::move(expressions_);
            return *this;
        }
    };
} // namespace rerun::blueprint

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<blueprint::QueryExpressions> {
        static constexpr const char Name[] = "rerun.blueprint.QueryExpressions";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::StructBuilder* builder, const blueprint::QueryExpressions* elements,
            size_t num_elements
        );

        /// Creates a Rerun DataCell from an array of `rerun::blueprint::QueryExpressions` components.
        static Result<rerun::DataCell> to_data_cell(
            const blueprint::QueryExpressions* instances, size_t num_instances
        );
    };
} // namespace rerun
