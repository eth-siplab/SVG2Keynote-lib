// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TNArchives.sos.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_TNArchives_2esos_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_TNArchives_2esos_2eproto

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
#include "TSDArchives.sos.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_TNArchives_2esos_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_TNArchives_2esos_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_TNArchives_2esos_2eproto;
namespace TNSOS {
class SheetStylePropertyChangeSetArchive;
struct SheetStylePropertyChangeSetArchiveDefaultTypeInternal;
extern SheetStylePropertyChangeSetArchiveDefaultTypeInternal _SheetStylePropertyChangeSetArchive_default_instance_;
}  // namespace TNSOS
PROTOBUF_NAMESPACE_OPEN
template<> ::TNSOS::SheetStylePropertyChangeSetArchive* Arena::CreateMaybeMessage<::TNSOS::SheetStylePropertyChangeSetArchive>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace TNSOS {

// ===================================================================

class SheetStylePropertyChangeSetArchive PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TNSOS.SheetStylePropertyChangeSetArchive) */ {
 public:
  inline SheetStylePropertyChangeSetArchive() : SheetStylePropertyChangeSetArchive(nullptr) {}
  ~SheetStylePropertyChangeSetArchive() override;
  explicit constexpr SheetStylePropertyChangeSetArchive(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  SheetStylePropertyChangeSetArchive(const SheetStylePropertyChangeSetArchive& from);
  SheetStylePropertyChangeSetArchive(SheetStylePropertyChangeSetArchive&& from) noexcept
    : SheetStylePropertyChangeSetArchive() {
    *this = ::std::move(from);
  }

  inline SheetStylePropertyChangeSetArchive& operator=(const SheetStylePropertyChangeSetArchive& from) {
    CopyFrom(from);
    return *this;
  }
  inline SheetStylePropertyChangeSetArchive& operator=(SheetStylePropertyChangeSetArchive&& from) noexcept {
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
  static const SheetStylePropertyChangeSetArchive& default_instance() {
    return *internal_default_instance();
  }
  static inline const SheetStylePropertyChangeSetArchive* internal_default_instance() {
    return reinterpret_cast<const SheetStylePropertyChangeSetArchive*>(
               &_SheetStylePropertyChangeSetArchive_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SheetStylePropertyChangeSetArchive& a, SheetStylePropertyChangeSetArchive& b) {
    a.Swap(&b);
  }
  inline void Swap(SheetStylePropertyChangeSetArchive* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SheetStylePropertyChangeSetArchive* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SheetStylePropertyChangeSetArchive* New() const final {
    return CreateMaybeMessage<SheetStylePropertyChangeSetArchive>(nullptr);
  }

  SheetStylePropertyChangeSetArchive* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SheetStylePropertyChangeSetArchive>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SheetStylePropertyChangeSetArchive& from);
  void MergeFrom(const SheetStylePropertyChangeSetArchive& from);
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
  void InternalSwap(SheetStylePropertyChangeSetArchive* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TNSOS.SheetStylePropertyChangeSetArchive";
  }
  protected:
  explicit SheetStylePropertyChangeSetArchive(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFillFieldNumber = 1,
    kFillUndefinedFieldNumber = 2,
  };
  // optional .TSDSOS.SpecFillArchive fill = 1;
  bool has_fill() const;
  private:
  bool _internal_has_fill() const;
  public:
  void clear_fill();
  const ::TSDSOS::SpecFillArchive& fill() const;
  PROTOBUF_FUTURE_MUST_USE_RESULT ::TSDSOS::SpecFillArchive* release_fill();
  ::TSDSOS::SpecFillArchive* mutable_fill();
  void set_allocated_fill(::TSDSOS::SpecFillArchive* fill);
  private:
  const ::TSDSOS::SpecFillArchive& _internal_fill() const;
  ::TSDSOS::SpecFillArchive* _internal_mutable_fill();
  public:
  void unsafe_arena_set_allocated_fill(
      ::TSDSOS::SpecFillArchive* fill);
  ::TSDSOS::SpecFillArchive* unsafe_arena_release_fill();

  // optional bool fill_undefined = 2;
  bool has_fill_undefined() const;
  private:
  bool _internal_has_fill_undefined() const;
  public:
  void clear_fill_undefined();
  bool fill_undefined() const;
  void set_fill_undefined(bool value);
  private:
  bool _internal_fill_undefined() const;
  void _internal_set_fill_undefined(bool value);
  public:

  // @@protoc_insertion_point(class_scope:TNSOS.SheetStylePropertyChangeSetArchive)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::TSDSOS::SpecFillArchive* fill_;
  bool fill_undefined_;
  friend struct ::TableStruct_TNArchives_2esos_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SheetStylePropertyChangeSetArchive

// optional .TSDSOS.SpecFillArchive fill = 1;
inline bool SheetStylePropertyChangeSetArchive::_internal_has_fill() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || fill_ != nullptr);
  return value;
}
inline bool SheetStylePropertyChangeSetArchive::has_fill() const {
  return _internal_has_fill();
}
inline const ::TSDSOS::SpecFillArchive& SheetStylePropertyChangeSetArchive::_internal_fill() const {
  const ::TSDSOS::SpecFillArchive* p = fill_;
  return p != nullptr ? *p : reinterpret_cast<const ::TSDSOS::SpecFillArchive&>(
      ::TSDSOS::_SpecFillArchive_default_instance_);
}
inline const ::TSDSOS::SpecFillArchive& SheetStylePropertyChangeSetArchive::fill() const {
  // @@protoc_insertion_point(field_get:TNSOS.SheetStylePropertyChangeSetArchive.fill)
  return _internal_fill();
}
inline void SheetStylePropertyChangeSetArchive::unsafe_arena_set_allocated_fill(
    ::TSDSOS::SpecFillArchive* fill) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(fill_);
  }
  fill_ = fill;
  if (fill) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:TNSOS.SheetStylePropertyChangeSetArchive.fill)
}
inline ::TSDSOS::SpecFillArchive* SheetStylePropertyChangeSetArchive::release_fill() {
  _has_bits_[0] &= ~0x00000001u;
  ::TSDSOS::SpecFillArchive* temp = fill_;
  fill_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::TSDSOS::SpecFillArchive* SheetStylePropertyChangeSetArchive::unsafe_arena_release_fill() {
  // @@protoc_insertion_point(field_release:TNSOS.SheetStylePropertyChangeSetArchive.fill)
  _has_bits_[0] &= ~0x00000001u;
  ::TSDSOS::SpecFillArchive* temp = fill_;
  fill_ = nullptr;
  return temp;
}
inline ::TSDSOS::SpecFillArchive* SheetStylePropertyChangeSetArchive::_internal_mutable_fill() {
  _has_bits_[0] |= 0x00000001u;
  if (fill_ == nullptr) {
    auto* p = CreateMaybeMessage<::TSDSOS::SpecFillArchive>(GetArena());
    fill_ = p;
  }
  return fill_;
}
inline ::TSDSOS::SpecFillArchive* SheetStylePropertyChangeSetArchive::mutable_fill() {
  // @@protoc_insertion_point(field_mutable:TNSOS.SheetStylePropertyChangeSetArchive.fill)
  return _internal_mutable_fill();
}
inline void SheetStylePropertyChangeSetArchive::set_allocated_fill(::TSDSOS::SpecFillArchive* fill) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(fill_);
  }
  if (fill) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(fill)->GetArena();
    if (message_arena != submessage_arena) {
      fill = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, fill, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  fill_ = fill;
  // @@protoc_insertion_point(field_set_allocated:TNSOS.SheetStylePropertyChangeSetArchive.fill)
}

// optional bool fill_undefined = 2;
inline bool SheetStylePropertyChangeSetArchive::_internal_has_fill_undefined() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool SheetStylePropertyChangeSetArchive::has_fill_undefined() const {
  return _internal_has_fill_undefined();
}
inline void SheetStylePropertyChangeSetArchive::clear_fill_undefined() {
  fill_undefined_ = false;
  _has_bits_[0] &= ~0x00000002u;
}
inline bool SheetStylePropertyChangeSetArchive::_internal_fill_undefined() const {
  return fill_undefined_;
}
inline bool SheetStylePropertyChangeSetArchive::fill_undefined() const {
  // @@protoc_insertion_point(field_get:TNSOS.SheetStylePropertyChangeSetArchive.fill_undefined)
  return _internal_fill_undefined();
}
inline void SheetStylePropertyChangeSetArchive::_internal_set_fill_undefined(bool value) {
  _has_bits_[0] |= 0x00000002u;
  fill_undefined_ = value;
}
inline void SheetStylePropertyChangeSetArchive::set_fill_undefined(bool value) {
  _internal_set_fill_undefined(value);
  // @@protoc_insertion_point(field_set:TNSOS.SheetStylePropertyChangeSetArchive.fill_undefined)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace TNSOS

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_TNArchives_2esos_2eproto
