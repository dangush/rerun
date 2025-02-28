// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/half_sizes3d.fbs".

#include "half_sizes3d.hpp"

#include "../datatypes/vec3d.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun::components {}

namespace rerun {
    const std::shared_ptr<arrow::DataType>& Loggable<components::HalfSizes3D>::arrow_datatype() {
        static const auto datatype = Loggable<rerun::datatypes::Vec3D>::arrow_datatype();
        return datatype;
    }

    rerun::Error Loggable<components::HalfSizes3D>::fill_arrow_array_builder(
        arrow::FixedSizeListBuilder* builder, const components::HalfSizes3D* elements,
        size_t num_elements
    ) {
        static_assert(sizeof(rerun::datatypes::Vec3D) == sizeof(components::HalfSizes3D));
        RR_RETURN_NOT_OK(Loggable<rerun::datatypes::Vec3D>::fill_arrow_array_builder(
            builder,
            reinterpret_cast<const rerun::datatypes::Vec3D*>(elements),
            num_elements
        ));

        return Error::ok();
    }

    Result<rerun::DataCell> Loggable<components::HalfSizes3D>::to_data_cell(
        const components::HalfSizes3D* instances, size_t num_instances
    ) {
        // TODO(andreas): Allow configuring the memory pool.
        arrow::MemoryPool* pool = arrow::default_memory_pool();
        auto datatype = arrow_datatype();

        ARROW_ASSIGN_OR_RAISE(auto builder, arrow::MakeBuilder(datatype, pool))
        if (instances && num_instances > 0) {
            RR_RETURN_NOT_OK(Loggable<components::HalfSizes3D>::fill_arrow_array_builder(
                static_cast<arrow::FixedSizeListBuilder*>(builder.get()),
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
