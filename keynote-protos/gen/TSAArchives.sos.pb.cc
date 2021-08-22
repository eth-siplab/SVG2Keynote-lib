// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TSAArchives.sos.proto

#include "TSAArchives.sos.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace TSASOS {
constexpr DrawableZOrderListArchive::DrawableZOrderListArchive(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : drawable_id_list_()
  , container_id_(nullptr)
  , drawable_id_list_undefined_(false){}
struct DrawableZOrderListArchiveDefaultTypeInternal {
  constexpr DrawableZOrderListArchiveDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~DrawableZOrderListArchiveDefaultTypeInternal() {}
  union {
    DrawableZOrderListArchive _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT DrawableZOrderListArchiveDefaultTypeInternal _DrawableZOrderListArchive_default_instance_;
}  // namespace TSASOS
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_TSAArchives_2esos_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_TSAArchives_2esos_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_TSAArchives_2esos_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_TSAArchives_2esos_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::TSASOS::DrawableZOrderListArchive, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::TSASOS::DrawableZOrderListArchive, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::TSASOS::DrawableZOrderListArchive, container_id_),
  PROTOBUF_FIELD_OFFSET(::TSASOS::DrawableZOrderListArchive, drawable_id_list_),
  PROTOBUF_FIELD_OFFSET(::TSASOS::DrawableZOrderListArchive, drawable_id_list_undefined_),
  0,
  ~0u,
  1,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::TSASOS::DrawableZOrderListArchive)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::TSASOS::_DrawableZOrderListArchive_default_instance_),
};

const char descriptor_table_protodef_TSAArchives_2esos_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025TSAArchives.sos.proto\022\006TSASOS\032\021TSPMess"
  "ages.proto\"\205\001\n\031DrawableZOrderListArchive"
  "\022\037\n\014container_id\030\001 \001(\0132\t.TSP.UUID\022#\n\020dra"
  "wable_id_list\030\002 \003(\0132\t.TSP.UUID\022\"\n\032drawab"
  "le_id_list_undefined\030\003 \001(\010"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_TSAArchives_2esos_2eproto_deps[1] = {
  &::descriptor_table_TSPMessages_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_TSAArchives_2esos_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_TSAArchives_2esos_2eproto = {
  false, false, 186, descriptor_table_protodef_TSAArchives_2esos_2eproto, "TSAArchives.sos.proto", 
  &descriptor_table_TSAArchives_2esos_2eproto_once, descriptor_table_TSAArchives_2esos_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_TSAArchives_2esos_2eproto::offsets,
  file_level_metadata_TSAArchives_2esos_2eproto, file_level_enum_descriptors_TSAArchives_2esos_2eproto, file_level_service_descriptors_TSAArchives_2esos_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_TSAArchives_2esos_2eproto_getter() {
  return &descriptor_table_TSAArchives_2esos_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_TSAArchives_2esos_2eproto(&descriptor_table_TSAArchives_2esos_2eproto);
namespace TSASOS {

// ===================================================================

class DrawableZOrderListArchive::_Internal {
 public:
  using HasBits = decltype(std::declval<DrawableZOrderListArchive>()._has_bits_);
  static const ::TSP::UUID& container_id(const DrawableZOrderListArchive* msg);
  static void set_has_container_id(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_drawable_id_list_undefined(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

const ::TSP::UUID&
DrawableZOrderListArchive::_Internal::container_id(const DrawableZOrderListArchive* msg) {
  return *msg->container_id_;
}
void DrawableZOrderListArchive::clear_container_id() {
  if (container_id_ != nullptr) container_id_->Clear();
  _has_bits_[0] &= ~0x00000001u;
}
void DrawableZOrderListArchive::clear_drawable_id_list() {
  drawable_id_list_.Clear();
}
DrawableZOrderListArchive::DrawableZOrderListArchive(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  drawable_id_list_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:TSASOS.DrawableZOrderListArchive)
}
DrawableZOrderListArchive::DrawableZOrderListArchive(const DrawableZOrderListArchive& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_),
      drawable_id_list_(from.drawable_id_list_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_container_id()) {
    container_id_ = new ::TSP::UUID(*from.container_id_);
  } else {
    container_id_ = nullptr;
  }
  drawable_id_list_undefined_ = from.drawable_id_list_undefined_;
  // @@protoc_insertion_point(copy_constructor:TSASOS.DrawableZOrderListArchive)
}

void DrawableZOrderListArchive::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&container_id_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&drawable_id_list_undefined_) -
    reinterpret_cast<char*>(&container_id_)) + sizeof(drawable_id_list_undefined_));
}

DrawableZOrderListArchive::~DrawableZOrderListArchive() {
  // @@protoc_insertion_point(destructor:TSASOS.DrawableZOrderListArchive)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void DrawableZOrderListArchive::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete container_id_;
}

void DrawableZOrderListArchive::ArenaDtor(void* object) {
  DrawableZOrderListArchive* _this = reinterpret_cast< DrawableZOrderListArchive* >(object);
  (void)_this;
}
void DrawableZOrderListArchive::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void DrawableZOrderListArchive::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void DrawableZOrderListArchive::Clear() {
// @@protoc_insertion_point(message_clear_start:TSASOS.DrawableZOrderListArchive)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  drawable_id_list_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(container_id_ != nullptr);
    container_id_->Clear();
  }
  drawable_id_list_undefined_ = false;
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* DrawableZOrderListArchive::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional .TSP.UUID container_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_container_id(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .TSP.UUID drawable_id_list = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_drawable_id_list(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      // optional bool drawable_id_list_undefined = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_drawable_id_list_undefined(&has_bits);
          drawable_id_list_undefined_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* DrawableZOrderListArchive::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:TSASOS.DrawableZOrderListArchive)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .TSP.UUID container_id = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::container_id(this), target, stream);
  }

  // repeated .TSP.UUID drawable_id_list = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_drawable_id_list_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_drawable_id_list(i), target, stream);
  }

  // optional bool drawable_id_list_undefined = 3;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(3, this->_internal_drawable_id_list_undefined(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TSASOS.DrawableZOrderListArchive)
  return target;
}

size_t DrawableZOrderListArchive::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:TSASOS.DrawableZOrderListArchive)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .TSP.UUID drawable_id_list = 2;
  total_size += 1UL * this->_internal_drawable_id_list_size();
  for (const auto& msg : this->drawable_id_list_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional .TSP.UUID container_id = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *container_id_);
    }

    // optional bool drawable_id_list_undefined = 3;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 + 1;
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void DrawableZOrderListArchive::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:TSASOS.DrawableZOrderListArchive)
  GOOGLE_DCHECK_NE(&from, this);
  const DrawableZOrderListArchive* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<DrawableZOrderListArchive>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:TSASOS.DrawableZOrderListArchive)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:TSASOS.DrawableZOrderListArchive)
    MergeFrom(*source);
  }
}

void DrawableZOrderListArchive::MergeFrom(const DrawableZOrderListArchive& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:TSASOS.DrawableZOrderListArchive)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  drawable_id_list_.MergeFrom(from.drawable_id_list_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_mutable_container_id()->::TSP::UUID::MergeFrom(from._internal_container_id());
    }
    if (cached_has_bits & 0x00000002u) {
      drawable_id_list_undefined_ = from.drawable_id_list_undefined_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void DrawableZOrderListArchive::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:TSASOS.DrawableZOrderListArchive)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DrawableZOrderListArchive::CopyFrom(const DrawableZOrderListArchive& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:TSASOS.DrawableZOrderListArchive)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DrawableZOrderListArchive::IsInitialized() const {
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(drawable_id_list_)) return false;
  if (_internal_has_container_id()) {
    if (!container_id_->IsInitialized()) return false;
  }
  return true;
}

void DrawableZOrderListArchive::InternalSwap(DrawableZOrderListArchive* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  drawable_id_list_.InternalSwap(&other->drawable_id_list_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(DrawableZOrderListArchive, drawable_id_list_undefined_)
      + sizeof(DrawableZOrderListArchive::drawable_id_list_undefined_)
      - PROTOBUF_FIELD_OFFSET(DrawableZOrderListArchive, container_id_)>(
          reinterpret_cast<char*>(&container_id_),
          reinterpret_cast<char*>(&other->container_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata DrawableZOrderListArchive::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_TSAArchives_2esos_2eproto_getter, &descriptor_table_TSAArchives_2esos_2eproto_once,
      file_level_metadata_TSAArchives_2esos_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace TSASOS
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::TSASOS::DrawableZOrderListArchive* Arena::CreateMaybeMessage< ::TSASOS::DrawableZOrderListArchive >(Arena* arena) {
  return Arena::CreateMessageInternal< ::TSASOS::DrawableZOrderListArchive >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
