// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/clear_is_recursive.fbs".

#include "clear_is_recursive.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun {
    namespace components {
        const char ClearIsRecursive::NAME[] = "rerun.components.ClearIsRecursive";

        const std::shared_ptr<arrow::DataType>& ClearIsRecursive::arrow_datatype() {
            static const auto datatype = arrow::boolean();
            return datatype;
        }

        Result<std::shared_ptr<arrow::BooleanBuilder>> ClearIsRecursive::new_arrow_array_builder(
            arrow::MemoryPool* memory_pool
        ) {
            if (memory_pool == nullptr) {
                return rerun::Error(ErrorCode::UnexpectedNullArgument, "Memory pool is null.");
            }

            return Result(std::make_shared<arrow::BooleanBuilder>(memory_pool));
        }

        rerun::Error ClearIsRecursive::fill_arrow_array_builder(
            arrow::BooleanBuilder* builder, const ClearIsRecursive* elements, size_t num_elements
        ) {
            if (builder == nullptr) {
                return rerun::Error(
                    ErrorCode::UnexpectedNullArgument,
                    "Passed array builder is null."
                );
            }
            if (elements == nullptr) {
                return rerun::Error(
                    ErrorCode::UnexpectedNullArgument,
                    "Cannot serialize null pointer to arrow array."
                );
            }

            static_assert(sizeof(*elements) == sizeof(elements->recursive));
            ARROW_RETURN_NOT_OK(builder->AppendValues(
                reinterpret_cast<const uint8_t*>(&elements->recursive),
                static_cast<int64_t>(num_elements)
            ));

            return Error::ok();
        }

        Result<rerun::DataCell> ClearIsRecursive::to_data_cell(
            const ClearIsRecursive* instances, size_t num_instances
        ) {
            // TODO(andreas): Allow configuring the memory pool.
            arrow::MemoryPool* pool = arrow::default_memory_pool();

            auto builder_result = ClearIsRecursive::new_arrow_array_builder(pool);
            RR_RETURN_NOT_OK(builder_result.error);
            auto builder = std::move(builder_result.value);
            if (instances && num_instances > 0) {
                RR_RETURN_NOT_OK(ClearIsRecursive::fill_arrow_array_builder(
                    builder.get(),
                    instances,
                    num_instances
                ));
            }
            std::shared_ptr<arrow::Array> array;
            ARROW_RETURN_NOT_OK(builder->Finish(&array));

            return rerun::DataCell::create(
                ClearIsRecursive::NAME,
                ClearIsRecursive::arrow_datatype(),
                std::move(array)
            );
        }
    } // namespace components
} // namespace rerun
