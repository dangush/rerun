// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/material.fbs".

#include "material.hpp"

#include "../datatypes/material.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun::components {}

namespace rerun {
    const std::shared_ptr<arrow::DataType>& Loggable<components::Material>::arrow_datatype() {
        static const auto datatype = Loggable<rerun::datatypes::Material>::arrow_datatype();
        return datatype;
    }

    rerun::Error Loggable<components::Material>::fill_arrow_array_builder(
        arrow::StructBuilder* builder, const components::Material* elements, size_t num_elements
    ) {
        static_assert(sizeof(rerun::datatypes::Material) == sizeof(components::Material));
        RR_RETURN_NOT_OK(Loggable<rerun::datatypes::Material>::fill_arrow_array_builder(
            builder,
            reinterpret_cast<const rerun::datatypes::Material*>(elements),
            num_elements
        ));

        return Error::ok();
    }

    Result<rerun::DataCell> Loggable<components::Material>::to_data_cell(
        const components::Material* instances, size_t num_instances
    ) {
        // TODO(andreas): Allow configuring the memory pool.
        arrow::MemoryPool* pool = arrow::default_memory_pool();
        auto datatype = arrow_datatype();

        ARROW_ASSIGN_OR_RAISE(auto builder, arrow::MakeBuilder(datatype, pool))
        if (instances && num_instances > 0) {
            RR_RETURN_NOT_OK(Loggable<components::Material>::fill_arrow_array_builder(
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
