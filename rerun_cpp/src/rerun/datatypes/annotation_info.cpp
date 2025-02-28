// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/annotation_info.fbs".

#include "annotation_info.hpp"

#include "rgba32.hpp"
#include "utf8.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun::datatypes {}

namespace rerun {
    const std::shared_ptr<arrow::DataType>& Loggable<datatypes::AnnotationInfo>::arrow_datatype() {
        static const auto datatype = arrow::struct_({
            arrow::field("id", arrow::uint16(), false),
            arrow::field("label", Loggable<rerun::datatypes::Utf8>::arrow_datatype(), true),
            arrow::field("color", Loggable<rerun::datatypes::Rgba32>::arrow_datatype(), true),
        });
        return datatype;
    }

    rerun::Error Loggable<datatypes::AnnotationInfo>::fill_arrow_array_builder(
        arrow::StructBuilder* builder, const datatypes::AnnotationInfo* elements,
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
                ARROW_RETURN_NOT_OK(field_builder->Append(elements[elem_idx].id));
            }
        }
        {
            auto field_builder = static_cast<arrow::StringBuilder*>(builder->field_builder(1));
            ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                const auto& element = elements[elem_idx];
                if (element.label.has_value()) {
                    RR_RETURN_NOT_OK(Loggable<rerun::datatypes::Utf8>::fill_arrow_array_builder(
                        field_builder,
                        &element.label.value(),
                        1
                    ));
                } else {
                    ARROW_RETURN_NOT_OK(field_builder->AppendNull());
                }
            }
        }
        {
            auto field_builder = static_cast<arrow::UInt32Builder*>(builder->field_builder(2));
            ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                const auto& element = elements[elem_idx];
                if (element.color.has_value()) {
                    RR_RETURN_NOT_OK(Loggable<rerun::datatypes::Rgba32>::fill_arrow_array_builder(
                        field_builder,
                        &element.color.value(),
                        1
                    ));
                } else {
                    ARROW_RETURN_NOT_OK(field_builder->AppendNull());
                }
            }
        }
        ARROW_RETURN_NOT_OK(builder->AppendValues(static_cast<int64_t>(num_elements), nullptr));

        return Error::ok();
    }

    Result<rerun::DataCell> Loggable<datatypes::AnnotationInfo>::to_data_cell(
        const datatypes::AnnotationInfo* instances, size_t num_instances
    ) {
        // TODO(andreas): Allow configuring the memory pool.
        arrow::MemoryPool* pool = arrow::default_memory_pool();
        auto datatype = arrow_datatype();

        ARROW_ASSIGN_OR_RAISE(auto builder, arrow::MakeBuilder(datatype, pool))
        if (instances && num_instances > 0) {
            RR_RETURN_NOT_OK(Loggable<datatypes::AnnotationInfo>::fill_arrow_array_builder(
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
