// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/blob.fbs".

#include "blob.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun::components {}

namespace rerun {
    const std::shared_ptr<arrow::DataType>& Loggable<components::Blob>::arrow_datatype() {
        static const auto datatype = arrow::list(arrow::field("item", arrow::uint8(), false));
        return datatype;
    }

    rerun::Error Loggable<components::Blob>::fill_arrow_array_builder(
        arrow::ListBuilder* builder, const components::Blob* elements, size_t num_elements
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

        auto value_builder = static_cast<arrow::UInt8Builder*>(builder->value_builder());
        ARROW_RETURN_NOT_OK(builder->Reserve(static_cast<int64_t>(num_elements)));
        ARROW_RETURN_NOT_OK(value_builder->Reserve(static_cast<int64_t>(num_elements * 2)));

        for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
            const auto& element = elements[elem_idx];
            ARROW_RETURN_NOT_OK(builder->Append());
            ARROW_RETURN_NOT_OK(value_builder->AppendValues(
                element.data.data(),
                static_cast<int64_t>(element.data.size()),
                nullptr
            ));
        }

        return Error::ok();
    }

    Result<rerun::DataCell> Loggable<components::Blob>::to_data_cell(
        const components::Blob* instances, size_t num_instances
    ) {
        // TODO(andreas): Allow configuring the memory pool.
        arrow::MemoryPool* pool = arrow::default_memory_pool();
        auto datatype = arrow_datatype();

        ARROW_ASSIGN_OR_RAISE(auto builder, arrow::MakeBuilder(datatype, pool))
        if (instances && num_instances > 0) {
            RR_RETURN_NOT_OK(Loggable<components::Blob>::fill_arrow_array_builder(
                static_cast<arrow::ListBuilder*>(builder.get()),
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
