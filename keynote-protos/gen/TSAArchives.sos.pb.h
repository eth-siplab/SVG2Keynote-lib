// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TSAArchives.sos.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_TSAArchives_2esos_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_TSAArchives_2esos_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015008 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "TSPMessages.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_TSAArchives_2esos_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_TSAArchives_2esos_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_TSAArchives_2esos_2eproto;
namespace TSASOS {
class DrawableZOrderListArchive;
struct DrawableZOrderListArchiveDefaultTypeInternal;
extern DrawableZOrderListArchiveDefaultTypeInternal _DrawableZOrderListArchive_default_instance_;
}  // namespace TSASOS
PROTOBUF_NAMESPACE_OPEN
template<> ::TSASOS::DrawableZOrderListArchive* Arena::CreateMaybeMessage<::TSASOS::DrawableZOrderListArchive>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace TSASOS {

// ===================================================================

class DrawableZOrderListArchive PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TSASOS.DrawableZOrderListArchive) */ {
 public:
  inline DrawableZOrderListArchive() : DrawableZOrderListArchive(nullptr) {}
  ~DrawableZOrderListArchive() override;
  explicit constexpr DrawableZOrderListArchive(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  DrawableZOrderListArchive(const DrawableZOrderListArchive& from);
  DrawableZOrderListArchive(DrawableZOrderListArchive&& from) noexcept
    : DrawableZOrderListArchive() {
    *this = ::std::move(from);
  }

  inline DrawableZOrderListArchive& operator=(const DrawableZOrderListArchive& from) {
    CopyFrom(from);
    return *this;
  }
  inline DrawableZOrderListArchive& operator=(DrawableZOrderListArchive&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const DrawableZOrderListArchive& default_instance() {
    return *internal_default_instance();
  }
  static inline const DrawableZOrderListArchive* internal_default_instance() {
    return reinterpret_cast<const DrawableZOrderListArchive*>(
               &_DrawableZOrderListArchive_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(DrawableZOrderListArchive& a, DrawableZOrderListArchive& b) {
    a.Swap(&b);
  }
  inline void Swap(DrawableZOrderListArchive* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(DrawableZOrderListArchive* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline DrawableZOrderListArchive* New() const final {
    return CreateMaybeMessage<DrawableZOrderListArchive>(nullptr);
  }

  DrawableZOrderListArchive* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<DrawableZOrderListArchive>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const DrawableZOrderListArchive& from);
  void MergeFrom(const DrawableZOrderListArchive& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DrawableZOrderListArchive* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TSASOS.DrawableZOrderListArchive";
  }
  protected:
  explicit DrawableZOrderListArchive(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDrawableIdListFieldNumber = 2,
    kContainerIdFieldNumber = 1,
    kDrawableIdListUndefinedFieldNumber = 3,
  };
  // repeated .TSP.UUID drawable_id_list = 2;
  int drawable_id_list_size() const;
  private:
  int _internal_drawable_id_list_size() const;
  public:
  void clear_drawable_id_list();
  ::TSP::UUID* mutable_drawable_id_list(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TSP::UUID >*
      mutable_drawable_id_list();
  private:
  const ::TSP::UUID& _internal_drawable_id_list(int index) const;
  ::TSP::UUID* _internal_add_drawable_id_list();
  public:
  const ::TSP::UUID& drawable_id_list(int index) const;
  ::TSP::UUID* add_drawable_id_list();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TSP::UUID >&
      drawable_id_list() const;

  // optional .TSP.UUID container_id = 1;
  bool has_container_id() const;
  private:
  bool _internal_has_container_id() const;
  public:
  void clear_container_id();
  const ::TSP::UUID& container_id() const;
  PROTOBUF_FUTURE_MUST_USE_RESULT ::TSP::UUID* release_container_id();
  ::TSP::UUID* mutable_container_id();
  void set_allocated_container_id(::TSP::UUID* container_id);
  private:
  const ::TSP::UUID& _internal_container_id() const;
  ::TSP::UUID* _internal_mutable_container_id();
  public:
  void unsafe_arena_set_allocated_container_id(
      ::TSP::UUID* container_id);
  ::TSP::UUID* unsafe_arena_release_container_id();

  // optional bool drawable_id_list_undefined = 3;
  bool has_drawable_id_list_undefined() const;
  private:
  bool _internal_has_drawable_id_list_undefined() const;
  public:
  void clear_drawable_id_list_undefined();
  bool drawable_id_list_undefined() const;
  void set_drawable_id_list_undefined(bool value);
  private:
  bool _internal_drawable_id_list_undefined() const;
  void _internal_set_drawable_id_list_undefined(bool value);
  public:

  // @@protoc_insertion_point(class_scope:TSASOS.DrawableZOrderListArchive)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TSP::UUID > drawable_id_list_;
  ::TSP::UUID* container_id_;
  bool drawable_id_list_undefined_;
  friend struct ::TableStruct_TSAArchives_2esos_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DrawableZOrderListArchive

// optional .TSP.UUID container_id = 1;
inline bool DrawableZOrderListArchive::_internal_has_container_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || container_id_ != nullptr);
  return value;
}
inline bool DrawableZOrderListArchive::has_container_id() const {
  return _internal_has_container_id();
}
inline const ::TSP::UUID& DrawableZOrderListArchive::_internal_container_id() const {
  const ::TSP::UUID* p = container_id_;
  return p != nullptr ? *p : reinterpret_cast<const ::TSP::UUID&>(
      ::TSP::_UUID_default_instance_);
}
inline const ::TSP::UUID& DrawableZOrderListArchive::container_id() const {
  // @@protoc_insertion_point(field_get:TSASOS.DrawableZOrderListArchive.container_id)
  return _internal_container_id();
}
inline void DrawableZOrderListArchive::unsafe_arena_set_allocated_container_id(
    ::TSP::UUID* container_id) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(container_id_);
  }
  container_id_ = container_id;
  if (container_id) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:TSASOS.DrawableZOrderListArchive.container_id)
}
inline ::TSP::UUID* DrawableZOrderListArchive::release_container_id() {
  _has_bits_[0] &= ~0x00000001u;
  ::TSP::UUID* temp = container_id_;
  container_id_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::TSP::UUID* DrawableZOrderListArchive::unsafe_arena_release_container_id() {
  // @@protoc_insertion_point(field_release:TSASOS.DrawableZOrderListArchive.container_id)
  _has_bits_[0] &= ~0x00000001u;
  ::TSP::UUID* temp = container_id_;
  container_id_ = nullptr;
  return temp;
}
inline ::TSP::UUID* DrawableZOrderListArchive::_internal_mutable_container_id() {
  _has_bits_[0] |= 0x00000001u;
  if (container_id_ == nullptr) {
    auto* p = CreateMaybeMessage<::TSP::UUID>(GetArena());
    container_id_ = p;
  }
  return container_id_;
}
inline ::TSP::UUID* DrawableZOrderListArchive::mutable_container_id() {
  // @@protoc_insertion_point(field_mutable:TSASOS.DrawableZOrderListArchive.container_id)
  return _internal_mutable_container_id();
}
inline void DrawableZOrderListArchive::set_allocated_container_id(::TSP::UUID* container_id) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(container_id_);
  }
  if (container_id) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(container_id)->GetArena();
    if (message_arena != submessage_arena) {
      container_id = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, container_id, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  container_id_ = container_id;
  // @@protoc_insertion_point(field_set_allocated:TSASOS.DrawableZOrderListArchive.container_id)
}

// repeated .TSP.UUID drawable_id_list = 2;
inline int DrawableZOrderListArchive::_internal_drawable_id_list_size() const {
  return drawable_id_list_.size();
}
inline int DrawableZOrderListArchive::drawable_id_list_size() const {
  return _internal_drawable_id_list_size();
}
inline ::TSP::UUID* DrawableZOrderListArchive::mutable_drawable_id_list(int index) {
  // @@protoc_insertion_point(field_mutable:TSASOS.DrawableZOrderListArchive.drawable_id_list)
  return drawable_id_list_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TSP::UUID >*
DrawableZOrderListArchive::mutable_drawable_id_list() {
  // @@protoc_insertion_point(field_mutable_list:TSASOS.DrawableZOrderListArchive.drawable_id_list)
  return &drawable_id_list_;
}
inline const ::TSP::UUID& DrawableZOrderListArchive::_internal_drawable_id_list(int index) const {
  return drawable_id_list_.Get(index);
}
inline const ::TSP::UUID& DrawableZOrderListArchive::drawable_id_list(int index) const {
  // @@protoc_insertion_point(field_get:TSASOS.DrawableZOrderListArchive.drawable_id_list)
  return _internal_drawable_id_list(index);
}
inline ::TSP::UUID* DrawableZOrderListArchive::_internal_add_drawable_id_list() {
  return drawable_id_list_.Add();
}
inline ::TSP::UUID* DrawableZOrderListArchive::add_drawable_id_list() {
  // @@protoc_insertion_point(field_add:TSASOS.DrawableZOrderListArchive.drawable_id_list)
  return _internal_add_drawable_id_list();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TSP::UUID >&
DrawableZOrderListArchive::drawable_id_list() const {
  // @@protoc_insertion_point(field_list:TSASOS.DrawableZOrderListArchive.drawable_id_list)
  return drawable_id_list_;
}

// optional bool drawable_id_list_undefined = 3;
inline bool DrawableZOrderListArchive::_internal_has_drawable_id_list_undefined() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool DrawableZOrderListArchive::has_drawable_id_list_undefined() const {
  return _internal_has_drawable_id_list_undefined();
}
inline void DrawableZOrderListArchive::clear_drawable_id_list_undefined() {
  drawable_id_list_undefined_ = false;
  _has_bits_[0] &= ~0x00000002u;
}
inline bool DrawableZOrderListArchive::_internal_drawable_id_list_undefined() const {
  return drawable_id_list_undefined_;
}
inline bool DrawableZOrderListArchive::drawable_id_list_undefined() const {
  // @@protoc_insertion_point(field_get:TSASOS.DrawableZOrderListArchive.drawable_id_list_undefined)
  return _internal_drawable_id_list_undefined();
}
inline void DrawableZOrderListArchive::_internal_set_drawable_id_list_undefined(bool value) {
  _has_bits_[0] |= 0x00000002u;
  drawable_id_list_undefined_ = value;
}
inline void DrawableZOrderListArchive::set_drawable_id_list_undefined(bool value) {
  _internal_set_drawable_id_list_undefined(value);
  // @@protoc_insertion_point(field_set:TSASOS.DrawableZOrderListArchive.drawable_id_list_undefined)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace TSASOS

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_TSAArchives_2esos_2eproto
