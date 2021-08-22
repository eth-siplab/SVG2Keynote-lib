// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TSKArchives.sos.proto

#include "TSKArchives.sos.pb.h"

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
namespace TSKSOS {
constexpr FixCorruptedDataCommandArchive::FixCorruptedDataCommandArchive(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : corrupted_digest_list_()
  , super_(nullptr)
  , corrupted_digest_list_undefined_(false){}
struct FixCorruptedDataCommandArchiveDefaultTypeInternal {
  constexpr FixCorruptedDataCommandArchiveDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~FixCorruptedDataCommandArchiveDefaultTypeInternal() {}
  union {
    FixCorruptedDataCommandArchive _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT FixCorruptedDataCommandArchiveDefaultTypeInternal _FixCorruptedDataCommandArchive_default_instance_;
}  // namespace TSKSOS
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_TSKArchives_2esos_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_TSKArchives_2esos_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_TSKArchives_2esos_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_TSKArchives_2esos_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::TSKSOS::FixCorruptedDataCommandArchive, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::TSKSOS::FixCorruptedDataCommandArchive, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::TSKSOS::FixCorruptedDataCommandArchive, super_),
  PROTOBUF_FIELD_OFFSET(::TSKSOS::FixCorruptedDataCommandArchive, corrupted_digest_list_),
  PROTOBUF_FIELD_OFFSET(::TSKSOS::FixCorruptedDataCommandArchive, corrupted_digest_list_undefined_),
  0,
  ~0u,
  1,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::TSKSOS::FixCorruptedDataCommandArchive)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::TSKSOS::_FixCorruptedDataCommandArchive_default_instance_),
};

const char descriptor_table_protodef_TSKArchives_2esos_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025TSKArchives.sos.proto\022\006TSKSOS\032\021TSKArch"
  "ives.proto\"\214\001\n\036FixCorruptedDataCommandAr"
  "chive\022\"\n\005super\030\001 \002(\0132\023.TSK.CommandArchiv"
  "e\022\035\n\025corrupted_digest_list\030\002 \003(\t\022\'\n\037corr"
  "upted_digest_list_undefined\030\003 \001(\010"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_TSKArchives_2esos_2eproto_deps[1] = {
  &::descriptor_table_TSKArchives_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_TSKArchives_2esos_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_TSKArchives_2esos_2eproto = {
  false, false, 193, descriptor_table_protodef_TSKArchives_2esos_2eproto, "TSKArchives.sos.proto", 
  &descriptor_table_TSKArchives_2esos_2eproto_once, descriptor_table_TSKArchives_2esos_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_TSKArchives_2esos_2eproto::offsets,
  file_level_metadata_TSKArchives_2esos_2eproto, file_level_enum_descriptors_TSKArchives_2esos_2eproto, file_level_service_descriptors_TSKArchives_2esos_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_TSKArchives_2esos_2eproto_getter() {
  return &descriptor_table_TSKArchives_2esos_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_TSKArchives_2esos_2eproto(&descriptor_table_TSKArchives_2esos_2eproto);
namespace TSKSOS {

// ===================================================================

class FixCorruptedDataCommandArchive::_Internal {
 public:
  using HasBits = decltype(std::declval<FixCorruptedDataCommandArchive>()._has_bits_);
  static const ::TSK::CommandArchive& super(const FixCorruptedDataCommandArchive* msg);
  static void set_has_super(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_corrupted_digest_list_undefined(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000001) ^ 0x00000001) != 0;
  }
};

const ::TSK::CommandArchive&
FixCorruptedDataCommandArchive::_Internal::super(const FixCorruptedDataCommandArchive* msg) {
  return *msg->super_;
}
void FixCorruptedDataCommandArchive::clear_super() {
  if (super_ != nullptr) super_->Clear();
  _has_bits_[0] &= ~0x00000001u;
}
FixCorruptedDataCommandArchive::FixCorruptedDataCommandArchive(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  corrupted_digest_list_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:TSKSOS.FixCorruptedDataCommandArchive)
}
FixCorruptedDataCommandArchive::FixCorruptedDataCommandArchive(const FixCorruptedDataCommandArchive& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_),
      corrupted_digest_list_(from.corrupted_digest_list_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_super()) {
    super_ = new ::TSK::CommandArchive(*from.super_);
  } else {
    super_ = nullptr;
  }
  corrupted_digest_list_undefined_ = from.corrupted_digest_list_undefined_;
  // @@protoc_insertion_point(copy_constructor:TSKSOS.FixCorruptedDataCommandArchive)
}

void FixCorruptedDataCommandArchive::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&super_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&corrupted_digest_list_undefined_) -
    reinterpret_cast<char*>(&super_)) + sizeof(corrupted_digest_list_undefined_));
}

FixCorruptedDataCommandArchive::~FixCorruptedDataCommandArchive() {
  // @@protoc_insertion_point(destructor:TSKSOS.FixCorruptedDataCommandArchive)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void FixCorruptedDataCommandArchive::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete super_;
}

void FixCorruptedDataCommandArchive::ArenaDtor(void* object) {
  FixCorruptedDataCommandArchive* _this = reinterpret_cast< FixCorruptedDataCommandArchive* >(object);
  (void)_this;
}
void FixCorruptedDataCommandArchive::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void FixCorruptedDataCommandArchive::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void FixCorruptedDataCommandArchive::Clear() {
// @@protoc_insertion_point(message_clear_start:TSKSOS.FixCorruptedDataCommandArchive)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  corrupted_digest_list_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(super_ != nullptr);
    super_->Clear();
  }
  corrupted_digest_list_undefined_ = false;
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* FixCorruptedDataCommandArchive::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required .TSK.CommandArchive super = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_super(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated string corrupted_digest_list = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_corrupted_digest_list();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            #ifndef NDEBUG
            ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "TSKSOS.FixCorruptedDataCommandArchive.corrupted_digest_list");
            #endif  // !NDEBUG
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      // optional bool corrupted_digest_list_undefined = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_corrupted_digest_list_undefined(&has_bits);
          corrupted_digest_list_undefined_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* FixCorruptedDataCommandArchive::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:TSKSOS.FixCorruptedDataCommandArchive)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .TSK.CommandArchive super = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::super(this), target, stream);
  }

  // repeated string corrupted_digest_list = 2;
  for (int i = 0, n = this->_internal_corrupted_digest_list_size(); i < n; i++) {
    const auto& s = this->_internal_corrupted_digest_list(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "TSKSOS.FixCorruptedDataCommandArchive.corrupted_digest_list");
    target = stream->WriteString(2, s, target);
  }

  // optional bool corrupted_digest_list_undefined = 3;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(3, this->_internal_corrupted_digest_list_undefined(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TSKSOS.FixCorruptedDataCommandArchive)
  return target;
}

size_t FixCorruptedDataCommandArchive::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:TSKSOS.FixCorruptedDataCommandArchive)
  size_t total_size = 0;

  // required .TSK.CommandArchive super = 1;
  if (_internal_has_super()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *super_);
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string corrupted_digest_list = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(corrupted_digest_list_.size());
  for (int i = 0, n = corrupted_digest_list_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      corrupted_digest_list_.Get(i));
  }

  // optional bool corrupted_digest_list_undefined = 3;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000002u) {
    total_size += 1 + 1;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void FixCorruptedDataCommandArchive::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:TSKSOS.FixCorruptedDataCommandArchive)
  GOOGLE_DCHECK_NE(&from, this);
  const FixCorruptedDataCommandArchive* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<FixCorruptedDataCommandArchive>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:TSKSOS.FixCorruptedDataCommandArchive)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:TSKSOS.FixCorruptedDataCommandArchive)
    MergeFrom(*source);
  }
}

void FixCorruptedDataCommandArchive::MergeFrom(const FixCorruptedDataCommandArchive& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:TSKSOS.FixCorruptedDataCommandArchive)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  corrupted_digest_list_.MergeFrom(from.corrupted_digest_list_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_mutable_super()->::TSK::CommandArchive::MergeFrom(from._internal_super());
    }
    if (cached_has_bits & 0x00000002u) {
      corrupted_digest_list_undefined_ = from.corrupted_digest_list_undefined_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void FixCorruptedDataCommandArchive::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:TSKSOS.FixCorruptedDataCommandArchive)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FixCorruptedDataCommandArchive::CopyFrom(const FixCorruptedDataCommandArchive& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:TSKSOS.FixCorruptedDataCommandArchive)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FixCorruptedDataCommandArchive::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  if (_internal_has_super()) {
    if (!super_->IsInitialized()) return false;
  }
  return true;
}

void FixCorruptedDataCommandArchive::InternalSwap(FixCorruptedDataCommandArchive* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  corrupted_digest_list_.InternalSwap(&other->corrupted_digest_list_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(FixCorruptedDataCommandArchive, corrupted_digest_list_undefined_)
      + sizeof(FixCorruptedDataCommandArchive::corrupted_digest_list_undefined_)
      - PROTOBUF_FIELD_OFFSET(FixCorruptedDataCommandArchive, super_)>(
          reinterpret_cast<char*>(&super_),
          reinterpret_cast<char*>(&other->super_));
}

::PROTOBUF_NAMESPACE_ID::Metadata FixCorruptedDataCommandArchive::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_TSKArchives_2esos_2eproto_getter, &descriptor_table_TSKArchives_2esos_2eproto_once,
      file_level_metadata_TSKArchives_2esos_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace TSKSOS
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::TSKSOS::FixCorruptedDataCommandArchive* Arena::CreateMaybeMessage< ::TSKSOS::FixCorruptedDataCommandArchive >(Arena* arena) {
  return Arena::CreateMessageInternal< ::TSKSOS::FixCorruptedDataCommandArchive >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
