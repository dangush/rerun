// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/class_description_map_elem.fbs".

#include "class_description_map_elem.hpp"

#include "class_description.hpp"
#include "class_id.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun::datatypes {}

namespace rerun {
    const std::shared_ptr<arrow::DataType>&
        Loggable<datatypes::ClassDescriptionMapElem>::arrow_datatype() {
        static const auto datatype = arrow::struct_({
            arrow::field("class_id", Loggable<rerun::datatypes::ClassId>::arrow_datatype(), false),
            arrow::field(
                "class_description",
                Loggable<rerun::datatypes::ClassDescription>::arrow_datatype(),
                false
            ),
        });
        return datatype;
    }

    rerun::Error Loggable<datatypes::ClassDescriptionMapElem>::fill_arrow_array_builder(
        arrow::StructBuilder* builder, const datatypes::ClassDescriptionMapElem* elements,
        size_t num_elements
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
            auto field_builder = static_cast<arrow::UInt16Builder*>(builder->field_builder(0));
            ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                RR_RETURN_NOT_OK(Loggable<rerun::datatypes::ClassId>::fill_arrow_array_builder(
                    field_builder,
                    &elements[elem_idx].class_id,
                    1
                ));
            }
        }
        {
            auto field_builder = static_cast<arrow::StructBuilder*>(builder->field_builder(1));
            ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                RR_RETURN_NOT_OK(
                    Loggable<rerun::datatypes::ClassDescription>::fill_arrow_array_builder(
                        field_builder,
                        &elements[elem_idx].class_description,
                        1
                    )
                );
            }
        }
        ARROW_RETURN_NOT_OK(builder->AppendValues(static_cast<int64_t>(num_elements), nullptr));

        return Error::ok();
    }

    Result<rerun::DataCell> Loggable<datatypes::ClassDescriptionMapElem>::to_data_cell(
        const datatypes::ClassDescriptionMapElem* instances, size_t num_instances
    ) {
        // TODO(andreas): Allow configuring the memory pool.
        arrow::MemoryPool* pool = arrow::default_memory_pool();
        auto datatype = arrow_datatype();

        ARROW_ASSIGN_OR_RAISE(auto builder, arrow::MakeBuilder(datatype, pool))
        if (instances && num_instances > 0) {
            RR_RETURN_NOT_OK(Loggable<datatypes::ClassDescriptionMapElem>::fill_arrow_array_builder(
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
