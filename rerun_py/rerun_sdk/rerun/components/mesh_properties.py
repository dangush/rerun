# DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/python.rs
# Based on "crates/re_types/definitions/rerun/components/mesh_properties.fbs".

# You can extend this class by creating a "MeshPropertiesExt" class in "mesh_properties_ext.py".

from __future__ import annotations

from .. import datatypes
from .._baseclasses import ComponentBatchMixin

__all__ = ["MeshProperties", "MeshPropertiesBatch", "MeshPropertiesType"]


class MeshProperties(datatypes.MeshProperties):
    """Optional triangle indices for a mesh."""

    # You can define your own __init__ function as a member of MeshPropertiesExt in mesh_properties_ext.py

    # Note: there are no fields here because MeshProperties delegates to datatypes.MeshProperties
    pass


class MeshPropertiesType(datatypes.MeshPropertiesType):
    _TYPE_NAME: str = "rerun.components.MeshProperties"


class MeshPropertiesBatch(datatypes.MeshPropertiesBatch, ComponentBatchMixin):
    _ARROW_TYPE = MeshPropertiesType()


# TODO(cmc): bring back registration to pyarrow once legacy types are gone
# pa.register_extension_type(MeshPropertiesType())
