// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/testing/datatypes/fuzzy.fbs".

#include "affix_fuzzer21.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun::datatypes {}

namespace rerun {
    const std::shared_ptr<arrow::DataType>& Loggable<datatypes::AffixFuzzer21>::arrow_datatype() {
        static const auto datatype = arrow::struct_({
            arrow::field("single_half", arrow::float16(), false),
            arrow::field(
                "many_halves",
                arrow::list(arrow::field("item", arrow::float16(), false)),
                false
            ),
        });
        return datatype;
    }

    rerun::Error Loggable<datatypes::AffixFuzzer21>::fill_arrow_array_builder(
        arrow::StructBuilder* builder, const datatypes::AffixFuzzer21* elements, size_t num_elements
    ) {
        if (builder == nullptr) {
            return rerun::Error(ErrorCode::UnexpectedNullArgument, "Passed array builder is null.");
        }
        if (elements == nullptr) {
            return rerun::Error(
                ErrorCode::UnexpectedNullArgument,
                "Cannot serialize null pointer to arrow array."
            );
        }

        {
            auto field_builder = static_cast<arrow::HalfFloatBuilder*>(builder->field_builder(0));
            ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                ARROW_RETURN_NOT_OK(field_builder->Append(
                    *reinterpret_cast<const uint16_t*>(&(elements[elem_idx].single_half))
                ));
            }
        }
        {
            auto field_builder = static_cast<arrow::ListBuilder*>(builder->field_builder(1));
            auto value_builder =
                static_cast<arrow::HalfFloatBuilder*>(field_builder->value_builder());
            ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
            ARROW_RETURN_NOT_OK(value_builder->Reserve(static_cast<int64_t>(num_elements * 2)));

            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                const auto& element = elements[elem_idx];
                ARROW_RETURN_NOT_OK(field_builder->Append());
                ARROW_RETURN_NOT_OK(value_builder->AppendValues(
                    reinterpret_cast<const uint16_t*>(element.many_halves.data()),
                    static_cast<int64_t>(element.many_halves.size()),
                    nullptr
                ));
            }
        }
        ARROW_RETURN_NOT_OK(builder->AppendValues(static_cast<int64_t>(num_elements), nullptr));

        return Error::ok();
    }

    Result<rerun::DataCell> Loggable<datatypes::AffixFuzzer21>::to_data_cell(
        const datatypes::AffixFuzzer21* instances, size_t num_instances
    ) {
        // TODO(andreas): Allow configuring the memory pool.
        arrow::MemoryPool* pool = arrow::default_memory_pool();
        auto datatype = arrow_datatype();

        ARROW_ASSIGN_OR_RAISE(auto builder, arrow::MakeBuilder(datatype, pool))
        if (instances && num_instances > 0) {
            RR_RETURN_NOT_OK(Loggable<datatypes::AffixFuzzer21>::fill_arrow_array_builder(
                static_cast<arrow::StructBuilder*>(builder.get()),
                instances,
                num_instances
            ));
        }
        std::shared_ptr<arrow::Array> array;
        ARROW_RETURN_NOT_OK(builder->Finish(&array));

        static const Result<ComponentTypeHandle> component_type =
            ComponentType(Name, datatype).register_component();
        RR_RETURN_NOT_OK(component_type.error);

        DataCell cell;
        cell.num_instances = num_instances;
        cell.array = std::move(array);
        cell.component_type = component_type.value;
        return cell;
    }
} // namespace rerun
