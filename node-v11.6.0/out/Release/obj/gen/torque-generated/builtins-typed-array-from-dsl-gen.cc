#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins.h"
#include "src/code-factory.h"
#include "src/elements-kind.h"
#include "src/heap/factory-inl.h"
#include "src/objects.h"
#include "src/objects/bigint.h"
#include "builtins-typed-array-from-dsl-gen.h"

namespace v8 {
namespace internal {

using Node = compiler::Node;

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType17ATFixedUint8Array() {
  ElementsKind _return_140_impl;
  auto _return_140 = &_return_140_impl;
  USE(_return_140);
  Label label_macro_end_922_impl(this, {});
  Label* label_macro_end_922 = &label_macro_end_922_impl;
  USE(label_macro_end_922);
  // ../src/builtins/typed-array.tq:20:63
  {
    // ../src/builtins/typed-array.tq:21:5
    *_return_140 = implicit_cast<ElementsKind>(UINT8_ELEMENTS);
    Goto(label_macro_end_922);
  }
  BIND(label_macro_end_922);
  return implicit_cast<ElementsKind>((*_return_140));
}

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType16ATFixedInt8Array() {
  ElementsKind _return_141_impl;
  auto _return_141 = &_return_141_impl;
  USE(_return_141);
  Label label_macro_end_923_impl(this, {});
  Label* label_macro_end_923 = &label_macro_end_923_impl;
  USE(label_macro_end_923);
  // ../src/builtins/typed-array.tq:23:62
  {
    // ../src/builtins/typed-array.tq:24:5
    *_return_141 = implicit_cast<ElementsKind>(INT8_ELEMENTS);
    Goto(label_macro_end_923);
  }
  BIND(label_macro_end_923);
  return implicit_cast<ElementsKind>((*_return_141));
}

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType18ATFixedUint16Array() {
  ElementsKind _return_142_impl;
  auto _return_142 = &_return_142_impl;
  USE(_return_142);
  Label label_macro_end_924_impl(this, {});
  Label* label_macro_end_924 = &label_macro_end_924_impl;
  USE(label_macro_end_924);
  // ../src/builtins/typed-array.tq:26:64
  {
    // ../src/builtins/typed-array.tq:27:5
    *_return_142 = implicit_cast<ElementsKind>(UINT16_ELEMENTS);
    Goto(label_macro_end_924);
  }
  BIND(label_macro_end_924);
  return implicit_cast<ElementsKind>((*_return_142));
}

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType17ATFixedInt16Array() {
  ElementsKind _return_143_impl;
  auto _return_143 = &_return_143_impl;
  USE(_return_143);
  Label label_macro_end_925_impl(this, {});
  Label* label_macro_end_925 = &label_macro_end_925_impl;
  USE(label_macro_end_925);
  // ../src/builtins/typed-array.tq:29:63
  {
    // ../src/builtins/typed-array.tq:30:5
    *_return_143 = implicit_cast<ElementsKind>(INT16_ELEMENTS);
    Goto(label_macro_end_925);
  }
  BIND(label_macro_end_925);
  return implicit_cast<ElementsKind>((*_return_143));
}

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType18ATFixedUint32Array() {
  ElementsKind _return_144_impl;
  auto _return_144 = &_return_144_impl;
  USE(_return_144);
  Label label_macro_end_926_impl(this, {});
  Label* label_macro_end_926 = &label_macro_end_926_impl;
  USE(label_macro_end_926);
  // ../src/builtins/typed-array.tq:32:64
  {
    // ../src/builtins/typed-array.tq:33:5
    *_return_144 = implicit_cast<ElementsKind>(UINT32_ELEMENTS);
    Goto(label_macro_end_926);
  }
  BIND(label_macro_end_926);
  return implicit_cast<ElementsKind>((*_return_144));
}

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType17ATFixedInt32Array() {
  ElementsKind _return_145_impl;
  auto _return_145 = &_return_145_impl;
  USE(_return_145);
  Label label_macro_end_927_impl(this, {});
  Label* label_macro_end_927 = &label_macro_end_927_impl;
  USE(label_macro_end_927);
  // ../src/builtins/typed-array.tq:35:63
  {
    // ../src/builtins/typed-array.tq:36:5
    *_return_145 = implicit_cast<ElementsKind>(INT32_ELEMENTS);
    Goto(label_macro_end_927);
  }
  BIND(label_macro_end_927);
  return implicit_cast<ElementsKind>((*_return_145));
}

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType19ATFixedFloat32Array() {
  ElementsKind _return_146_impl;
  auto _return_146 = &_return_146_impl;
  USE(_return_146);
  Label label_macro_end_928_impl(this, {});
  Label* label_macro_end_928 = &label_macro_end_928_impl;
  USE(label_macro_end_928);
  // ../src/builtins/typed-array.tq:38:65
  {
    // ../src/builtins/typed-array.tq:39:5
    *_return_146 = implicit_cast<ElementsKind>(FLOAT32_ELEMENTS);
    Goto(label_macro_end_928);
  }
  BIND(label_macro_end_928);
  return implicit_cast<ElementsKind>((*_return_146));
}

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType19ATFixedFloat64Array() {
  ElementsKind _return_147_impl;
  auto _return_147 = &_return_147_impl;
  USE(_return_147);
  Label label_macro_end_929_impl(this, {});
  Label* label_macro_end_929 = &label_macro_end_929_impl;
  USE(label_macro_end_929);
  // ../src/builtins/typed-array.tq:41:65
  {
    // ../src/builtins/typed-array.tq:42:5
    *_return_147 = implicit_cast<ElementsKind>(FLOAT64_ELEMENTS);
    Goto(label_macro_end_929);
  }
  BIND(label_macro_end_929);
  return implicit_cast<ElementsKind>((*_return_147));
}

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType24ATFixedUint8ClampedArray() {
  ElementsKind _return_148_impl;
  auto _return_148 = &_return_148_impl;
  USE(_return_148);
  Label label_macro_end_930_impl(this, {});
  Label* label_macro_end_930 = &label_macro_end_930_impl;
  USE(label_macro_end_930);
  // ../src/builtins/typed-array.tq:44:70
  {
    // ../src/builtins/typed-array.tq:45:5
    *_return_148 = implicit_cast<ElementsKind>(UINT8_CLAMPED_ELEMENTS);
    Goto(label_macro_end_930);
  }
  BIND(label_macro_end_930);
  return implicit_cast<ElementsKind>((*_return_148));
}

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType21ATFixedBigUint64Array() {
  ElementsKind _return_149_impl;
  auto _return_149 = &_return_149_impl;
  USE(_return_149);
  Label label_macro_end_931_impl(this, {});
  Label* label_macro_end_931 = &label_macro_end_931_impl;
  USE(label_macro_end_931);
  // ../src/builtins/typed-array.tq:47:67
  {
    // ../src/builtins/typed-array.tq:48:5
    *_return_149 = implicit_cast<ElementsKind>(BIGUINT64_ELEMENTS);
    Goto(label_macro_end_931);
  }
  BIND(label_macro_end_931);
  return implicit_cast<ElementsKind>((*_return_149));
}

ElementsKind TypedArrayBuiltinsFromDSLAssembler::KindForArrayType20ATFixedBigInt64Array() {
  ElementsKind _return_150_impl;
  auto _return_150 = &_return_150_impl;
  USE(_return_150);
  Label label_macro_end_932_impl(this, {});
  Label* label_macro_end_932 = &label_macro_end_932_impl;
  USE(label_macro_end_932);
  // ../src/builtins/typed-array.tq:50:66
  {
    // ../src/builtins/typed-array.tq:51:5
    *_return_150 = implicit_cast<ElementsKind>(BIGINT64_ELEMENTS);
    Goto(label_macro_end_932);
  }
  BIND(label_macro_end_932);
  return implicit_cast<ElementsKind>((*_return_150));
}

compiler::TNode<Number> TypedArrayBuiltinsFromDSLAssembler::CallCompareWithDetachedCheck(TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<JSReceiver> p_comparefn, TNode<Object> p_a, TNode<Object> p_b, Label* label_Detached_143) {
  TVARIABLE(Number, _return_151_impl);
  auto _return_151 = &_return_151_impl;
  USE(_return_151);
  Label label_macro_end_933_impl(this, {_return_151});
  Label* label_macro_end_933 = &label_macro_end_933_impl;
  USE(label_macro_end_933);
  // ../src/builtins/typed-array.tq:72:42
  {
    // ../src/builtins/typed-array.tq:74:5
    TNode<Object> t474 = UncheckedCast<Object>(Call(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Object>>(Undefined()), implicit_cast<TNode<Object>>(p_a), implicit_cast<TNode<Object>>(p_b)));
    USE(implicit_cast<TNode<Object>>(t474));
    TNode<Number> t475 = UncheckedCast<Number>(ToNumber_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t474)));
    USE(implicit_cast<TNode<Number>>(t475));
    TNode<Number> v_578_impl;
    auto v_578 = &v_578_impl;
    USE(v_578);
    *v_578 = implicit_cast<TNode<Number>>(t475);
    // ../src/builtins/typed-array.tq:78:5
    {
      Label label__True_144_impl(this);
      Label* label__True_144 = &label__True_144_impl;
      USE(label__True_144);
      Label label__False_145_impl(this, {});
      Label* label__False_145 = &label__False_145_impl;
      USE(label__False_145);
      TNode<JSArrayBuffer> t476 = UncheckedCast<JSArrayBuffer>(LoadTypedArrayBuffer(implicit_cast<TNode<JSTypedArray>>(p_array)));
      TNode<BoolT> t477 = UncheckedCast<BoolT>(IsDetachedBuffer(implicit_cast<TNode<JSArrayBuffer>>(t476)));
      USE(implicit_cast<TNode<BoolT>>(t477));
      Branch(implicit_cast<TNode<BoolT>>(t477), label__True_144, label__False_145);
      if (label__True_144->is_used())
      {
        BIND(label__True_144);
        // ../src/builtins/typed-array.tq:78:41
        Goto(label_Detached_143);
      }
      BIND(label__False_145);
    }
    // ../src/builtins/typed-array.tq:81:5
    {
      Label label__True_146_impl(this);
      Label* label__True_146 = &label__True_146_impl;
      USE(label__True_146);
      Label label__False_147_impl(this, {});
      Label* label__False_147 = &label__False_147_impl;
      USE(label__False_147);
      TNode<BoolT> t478 = UncheckedCast<BoolT>(NumberIsNaN(implicit_cast<TNode<Number>>((*v_578))));
      USE(implicit_cast<TNode<BoolT>>(t478));
      Branch(implicit_cast<TNode<BoolT>>(t478), label__True_146, label__False_147);
      if (label__True_146->is_used())
      {
        BIND(label__True_146);
        // ../src/builtins/typed-array.tq:81:25
        int31_t t479 = 0;
        TNode<Number> t480 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t479)));
        *_return_151 = implicit_cast<TNode<Number>>(t480);
        Goto(label_macro_end_933);
      }
      BIND(label__False_147);
    }
    // ../src/builtins/typed-array.tq:84:5
    *_return_151 = implicit_cast<TNode<Number>>((*v_578));
    Goto(label_macro_end_933);
  }
  BIND(label_macro_end_933);
  return implicit_cast<TNode<Number>>((*_return_151).value());
}

void TypedArrayBuiltinsFromDSLAssembler::TypedArrayInsertionSort(TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<Smi> p_from_arg, TNode<Smi> p_to_arg, TNode<JSReceiver> p_comparefn, TNode<Code> p_Load, TNode<Code> p_Store, Label* label_Detached_148) {
  Label label_macro_end_934_impl(this, {});
  Label* label_macro_end_934 = &label_macro_end_934_impl;
  USE(label_macro_end_934);
  // ../src/builtins/typed-array.tq:91:19
  {
    // ../src/builtins/typed-array.tq:92:5
    TVARIABLE(Smi, from_152_impl);
    auto from_152 = &from_152_impl;
    USE(from_152);
    *from_152 = implicit_cast<TNode<Smi>>(p_from_arg);
    // ../src/builtins/typed-array.tq:93:5
    TVARIABLE(Smi, to_153_impl);
    auto to_153 = &to_153_impl;
    USE(to_153);
    *to_153 = implicit_cast<TNode<Smi>>(p_to_arg);
    // ../src/builtins/typed-array.tq:95:5
    {
      Label label__True_149_impl(this);
      Label* label__True_149 = &label__True_149_impl;
      USE(label__True_149);
      Label label__False_150_impl(this, {});
      Label* label__False_150 = &label__False_150_impl;
      USE(label__False_150);
      TNode<JSArrayBuffer> t481 = UncheckedCast<JSArrayBuffer>(LoadTypedArrayBuffer(implicit_cast<TNode<JSTypedArray>>(p_array)));
      TNode<BoolT> t482 = UncheckedCast<BoolT>(IsDetachedBuffer(implicit_cast<TNode<JSArrayBuffer>>(t481)));
      USE(implicit_cast<TNode<BoolT>>(t482));
      Branch(implicit_cast<TNode<BoolT>>(t482), label__True_149, label__False_150);
      if (label__True_149->is_used())
      {
        BIND(label__True_149);
        // ../src/builtins/typed-array.tq:95:41
        Goto(label_Detached_148);
      }
      BIND(label__False_150);
    }
    // ../src/builtins/typed-array.tq:97:5
    int31_t t483 = 1;
    TNode<Smi> t484 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t483)));
    TNode<Smi> t485 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*from_152).value()), implicit_cast<TNode<Smi>>(t484)));
    USE(implicit_cast<TNode<Smi>>(t485));
    TVARIABLE(Smi, i_154_impl);
    auto i_154 = &i_154_impl;
    USE(i_154);
    *i_154 = implicit_cast<TNode<Smi>>(t485);
    Label label__True_151_impl(this);
    Label* label__True_151 = &label__True_151_impl;
    USE(label__True_151);
    Label label__False_152_impl(this);
    Label* label__False_152 = &label__False_152_impl;
    USE(label__False_152);
    Label label_header_579_935_impl(this, {i_154});
    Label* label_header_579_935 = &label_header_579_935_impl;
    USE(label_header_579_935);
    Goto(label_header_579_935);
    BIND(label_header_579_935);
    Label label_action_580_936_impl(this);
    Label* label_action_580_936 = &label_action_580_936_impl;
    USE(label_action_580_936);
    TNode<BoolT> t486 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*i_154).value()), implicit_cast<TNode<Smi>>((*to_153).value())));
    USE(implicit_cast<TNode<BoolT>>(t486));
    Branch(implicit_cast<TNode<BoolT>>(t486), label__True_151, label__False_152);
    if (label__True_151->is_used())
    {
      BIND(label__True_151);
      // ../src/builtins/typed-array.tq:97:46
      {
        // ../src/builtins/typed-array.tq:98:7
        TNode<Object> t487 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*i_154).value())));
        USE(implicit_cast<TNode<Object>>(t487));
        TNode<Object> element_581_impl;
        auto element_581 = &element_581_impl;
        USE(element_581);
        *element_581 = implicit_cast<TNode<Object>>(t487);
        // ../src/builtins/typed-array.tq:99:7
        int31_t t488 = 1;
        TNode<Smi> t489 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t488)));
        TNode<Smi> t490 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*i_154).value()), implicit_cast<TNode<Smi>>(t489)));
        USE(implicit_cast<TNode<Smi>>(t490));
        TVARIABLE(Smi, j_155_impl);
        auto j_155 = &j_155_impl;
        USE(j_155);
        *j_155 = implicit_cast<TNode<Smi>>(t490);
        // ../src/builtins/typed-array.tq:100:7
        Label label__True_153_impl(this);
        Label* label__True_153 = &label__True_153_impl;
        USE(label__True_153);
        Label label__False_154_impl(this);
        Label* label__False_154 = &label__False_154_impl;
        USE(label__False_154);
        Label label_header_582_937_impl(this, {j_155});
        Label* label_header_582_937 = &label_header_582_937_impl;
        USE(label_header_582_937);
        Goto(label_header_582_937);
        BIND(label_header_582_937);
        Label label_action_583_938_impl(this);
        Label* label_action_583_938 = &label_action_583_938_impl;
        USE(label_action_583_938);
        TNode<BoolT> t491 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*j_155).value()), implicit_cast<TNode<Smi>>((*from_152).value())));
        USE(implicit_cast<TNode<BoolT>>(t491));
        Branch(implicit_cast<TNode<BoolT>>(t491), label__True_153, label__False_154);
        if (label__True_153->is_used())
        {
          BIND(label__True_153);
          // ../src/builtins/typed-array.tq:100:30
          {
            // ../src/builtins/typed-array.tq:101:9
            TNode<Object> t492 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*j_155).value())));
            USE(implicit_cast<TNode<Object>>(t492));
            TNode<Object> tmp_584_impl;
            auto tmp_584 = &tmp_584_impl;
            USE(tmp_584);
            *tmp_584 = implicit_cast<TNode<Object>>(t492);
            // ../src/builtins/typed-array.tq:102:9
            TNode<Number> t493 = UncheckedCast<Number>(CallCompareWithDetachedCheck(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Object>>((*tmp_584)), implicit_cast<TNode<Object>>((*element_581)), label_Detached_148));
            USE(implicit_cast<TNode<Number>>(t493));
            TNode<Number> order_585_impl;
            auto order_585 = &order_585_impl;
            USE(order_585);
            *order_585 = implicit_cast<TNode<Number>>(t493);
            // ../src/builtins/typed-array.tq:104:9
            {
              Label label__True_155_impl(this);
              Label* label__True_155 = &label__True_155_impl;
              USE(label__True_155);
              Label label__False_156_impl(this);
              Label* label__False_156 = &label__False_156_impl;
              USE(label__False_156);
              Label label_if_done_label_586_939_impl(this, {});
              Label* label_if_done_label_586_939 = &label_if_done_label_586_939_impl;
              USE(label_if_done_label_586_939);
              int31_t t494 = 0;
              TNode<Number> t495 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t494)));
              BranchIfNumberGreaterThan(implicit_cast<TNode<Number>>((*order_585)), implicit_cast<TNode<Number>>(t495), label__True_155, label__False_156);
              if (label__True_155->is_used())
              {
                BIND(label__True_155);
                // ../src/builtins/typed-array.tq:104:24
                {
                  // ../src/builtins/typed-array.tq:105:11
                  int31_t t496 = 1;
                  TNode<Smi> t497 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t496)));
                  TNode<Smi> t498 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*j_155).value()), implicit_cast<TNode<Smi>>(t497)));
                  USE(implicit_cast<TNode<Smi>>(t498));
                  TNode<Object> t499 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>(t498), implicit_cast<TNode<Object>>((*tmp_584))));
                  USE(implicit_cast<TNode<Object>>(t499));
                }
                Goto(label_if_done_label_586_939);
              }
              if (label__False_156->is_used())
              {
                BIND(label__False_156);
                // ../src/builtins/typed-array.tq:106:16
                {
                  // ../src/builtins/typed-array.tq:107:11
                  Goto(label__False_154);
                }
              }
              BIND(label_if_done_label_586_939);
            }
          }
          Goto(label_action_583_938);
        }
        {
          BIND(label_action_583_938);
          TNode<Smi> t500 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t501 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*j_155).value()), implicit_cast<TNode<Smi>>(t500)));
          *j_155 = implicit_cast<TNode<Smi>>(t501);
          Goto(label_header_582_937);
        }
        BIND(label__False_154);
        // ../src/builtins/typed-array.tq:110:7
        int31_t t502 = 1;
        TNode<Smi> t503 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t502)));
        TNode<Smi> t504 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*j_155).value()), implicit_cast<TNode<Smi>>(t503)));
        USE(implicit_cast<TNode<Smi>>(t504));
        TNode<Object> t505 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>(t504), implicit_cast<TNode<Object>>((*element_581))));
        USE(implicit_cast<TNode<Object>>(t505));
      }
      Goto(label_action_580_936);
    }
    {
      BIND(label_action_580_936);
      TNode<Smi> t506 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
      TNode<Smi> t507 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*i_154).value()), implicit_cast<TNode<Smi>>(t506)));
      *i_154 = implicit_cast<TNode<Smi>>(t507);
      Goto(label_header_579_935);
    }
    BIND(label__False_152);
  }
}

void TypedArrayBuiltinsFromDSLAssembler::TypedArrayQuickSortImpl(TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<Smi> p_from_arg, TNode<Smi> p_to_arg, TNode<JSReceiver> p_comparefn, TNode<Code> p_Load, TNode<Code> p_Store, Label* label_Detached_157) {
  Label label_macro_end_940_impl(this, {});
  Label* label_macro_end_940 = &label_macro_end_940_impl;
  USE(label_macro_end_940);
  // ../src/builtins/typed-array.tq:117:19
  {
    // ../src/builtins/typed-array.tq:118:5
    TVARIABLE(Smi, from_156_impl);
    auto from_156 = &from_156_impl;
    USE(from_156);
    *from_156 = implicit_cast<TNode<Smi>>(p_from_arg);
    // ../src/builtins/typed-array.tq:119:5
    TVARIABLE(Smi, to_157_impl);
    auto to_157 = &to_157_impl;
    USE(to_157);
    *to_157 = implicit_cast<TNode<Smi>>(p_to_arg);
    // ../src/builtins/typed-array.tq:121:5
    {
      Label label__True_158_impl(this);
      Label* label__True_158 = &label__True_158_impl;
      USE(label__True_158);
      Label label__False_159_impl(this);
      Label* label__False_159 = &label__False_159_impl;
      USE(label__False_159);
      Label label_header_587_941_impl(this, {from_156, to_157});
      Label* label_header_587_941 = &label_header_587_941_impl;
      USE(label_header_587_941);
      Goto(label_header_587_941);
      BIND(label_header_587_941);
      TNode<Smi> t508 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*to_157).value()), implicit_cast<TNode<Smi>>((*from_156).value())));
      USE(implicit_cast<TNode<Smi>>(t508));
      int31_t t509 = 1;
      TNode<Smi> t510 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t509)));
      TNode<BoolT> t511 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>(t508), implicit_cast<TNode<Smi>>(t510)));
      USE(implicit_cast<TNode<BoolT>>(t511));
      Branch(implicit_cast<TNode<BoolT>>(t511), label__True_158, label__False_159);
      if (label__True_158->is_used())
      {
        BIND(label__True_158);
        // ../src/builtins/typed-array.tq:121:27
        {
          // ../src/builtins/typed-array.tq:122:7
          {
            Label label__True_160_impl(this);
            Label* label__True_160 = &label__True_160_impl;
            USE(label__True_160);
            Label label__False_161_impl(this, {});
            Label* label__False_161 = &label__False_161_impl;
            USE(label__False_161);
            TNode<Smi> t512 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*to_157).value()), implicit_cast<TNode<Smi>>((*from_156).value())));
            USE(implicit_cast<TNode<Smi>>(t512));
            int31_t t513 = 10;
            TNode<Smi> t514 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t513)));
            TNode<BoolT> t515 = UncheckedCast<BoolT>(SmiLessThanOrEqual(implicit_cast<TNode<Smi>>(t512), implicit_cast<TNode<Smi>>(t514)));
            USE(implicit_cast<TNode<BoolT>>(t515));
            Branch(implicit_cast<TNode<BoolT>>(t515), label__True_160, label__False_161);
            if (label__True_160->is_used())
            {
              BIND(label__True_160);
              // ../src/builtins/typed-array.tq:122:28
              {
                // ../src/builtins/typed-array.tq:126:9
                TypedArrayInsertionSort(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*from_156).value()), implicit_cast<TNode<Smi>>((*to_157).value()), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Code>>(p_Store), label_Detached_157);
                // ../src/builtins/typed-array.tq:129:9
                Goto(label__False_159);
              }
            }
            BIND(label__False_161);
          }
          // ../src/builtins/typed-array.tq:134:7
          TNode<Smi> t516 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*to_157).value()), implicit_cast<TNode<Smi>>((*from_156).value())));
          USE(implicit_cast<TNode<Smi>>(t516));
          int31_t t517 = 1;
          TNode<Smi> t518 = UncheckedCast<Smi>(SmiShr(implicit_cast<TNode<Smi>>(t516), implicit_cast<int31_t>(t517)));
          USE(implicit_cast<TNode<Smi>>(t518));
          TNode<Smi> t519 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*from_156).value()), implicit_cast<TNode<Smi>>(t518)));
          USE(implicit_cast<TNode<Smi>>(t519));
          TNode<Smi> third_index_588_impl;
          auto third_index_588 = &third_index_588_impl;
          USE(third_index_588);
          *third_index_588 = implicit_cast<TNode<Smi>>(t519);
          // ../src/builtins/typed-array.tq:136:7
          {
            Label label__True_162_impl(this);
            Label* label__True_162 = &label__True_162_impl;
            USE(label__True_162);
            Label label__False_163_impl(this, {});
            Label* label__False_163 = &label__False_163_impl;
            USE(label__False_163);
            TNode<JSArrayBuffer> t520 = UncheckedCast<JSArrayBuffer>(LoadTypedArrayBuffer(implicit_cast<TNode<JSTypedArray>>(p_array)));
            TNode<BoolT> t521 = UncheckedCast<BoolT>(IsDetachedBuffer(implicit_cast<TNode<JSArrayBuffer>>(t520)));
            USE(implicit_cast<TNode<BoolT>>(t521));
            Branch(implicit_cast<TNode<BoolT>>(t521), label__True_162, label__False_163);
            if (label__True_162->is_used())
            {
              BIND(label__True_162);
              // ../src/builtins/typed-array.tq:136:43
              Goto(label_Detached_157);
            }
            BIND(label__False_163);
          }
          // ../src/builtins/typed-array.tq:139:7
          TNode<Object> t522 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*from_156).value())));
          USE(implicit_cast<TNode<Object>>(t522));
          TVARIABLE(Object, v0_158_impl);
          auto v0_158 = &v0_158_impl;
          USE(v0_158);
          *v0_158 = implicit_cast<TNode<Object>>(t522);
          // ../src/builtins/typed-array.tq:140:7
          int31_t t523 = 1;
          TNode<Smi> t524 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t523)));
          TNode<Smi> t525 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*to_157).value()), implicit_cast<TNode<Smi>>(t524)));
          USE(implicit_cast<TNode<Smi>>(t525));
          TNode<Object> t526 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>(t525)));
          USE(implicit_cast<TNode<Object>>(t526));
          TVARIABLE(Object, v1_159_impl);
          auto v1_159 = &v1_159_impl;
          USE(v1_159);
          *v1_159 = implicit_cast<TNode<Object>>(t526);
          // ../src/builtins/typed-array.tq:141:7
          TNode<Object> t527 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*third_index_588))));
          USE(implicit_cast<TNode<Object>>(t527));
          TVARIABLE(Object, v2_160_impl);
          auto v2_160 = &v2_160_impl;
          USE(v2_160);
          *v2_160 = implicit_cast<TNode<Object>>(t527);
          // ../src/builtins/typed-array.tq:143:7
          TNode<Number> t528 = UncheckedCast<Number>(CallCompareWithDetachedCheck(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Object>>((*v0_158).value()), implicit_cast<TNode<Object>>((*v1_159).value()), label_Detached_157));
          USE(implicit_cast<TNode<Number>>(t528));
          TNode<Number> c01_589_impl;
          auto c01_589 = &c01_589_impl;
          USE(c01_589);
          *c01_589 = implicit_cast<TNode<Number>>(t528);
          // ../src/builtins/typed-array.tq:145:7
          {
            Label label__True_164_impl(this);
            Label* label__True_164 = &label__True_164_impl;
            USE(label__True_164);
            Label label__False_165_impl(this, {v0_158, v1_159});
            Label* label__False_165 = &label__False_165_impl;
            USE(label__False_165);
            int31_t t529 = 0;
            TNode<Number> t530 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t529)));
            BranchIfNumberGreaterThan(implicit_cast<TNode<Number>>((*c01_589)), implicit_cast<TNode<Number>>(t530), label__True_164, label__False_165);
            if (label__True_164->is_used())
            {
              BIND(label__True_164);
              // ../src/builtins/typed-array.tq:145:20
              {
                // ../src/builtins/typed-array.tq:147:9
                TVARIABLE(Object, tmp_161_impl);
                auto tmp_161 = &tmp_161_impl;
                USE(tmp_161);
                *tmp_161 = implicit_cast<TNode<Object>>((*v0_158).value());
                // ../src/builtins/typed-array.tq:148:9
                *v0_158 = implicit_cast<TNode<Object>>((*v1_159).value());
                // ../src/builtins/typed-array.tq:149:9
                *v1_159 = implicit_cast<TNode<Object>>((*tmp_161).value());
              }
              Goto(label__False_165);
            }
            BIND(label__False_165);
          }
          // ../src/builtins/typed-array.tq:152:7
          TNode<Number> t531 = UncheckedCast<Number>(CallCompareWithDetachedCheck(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Object>>((*v0_158).value()), implicit_cast<TNode<Object>>((*v2_160).value()), label_Detached_157));
          USE(implicit_cast<TNode<Number>>(t531));
          TNode<Number> c02_590_impl;
          auto c02_590 = &c02_590_impl;
          USE(c02_590);
          *c02_590 = implicit_cast<TNode<Number>>(t531);
          // ../src/builtins/typed-array.tq:154:7
          {
            Label label__True_166_impl(this);
            Label* label__True_166 = &label__True_166_impl;
            USE(label__True_166);
            Label label__False_167_impl(this);
            Label* label__False_167 = &label__False_167_impl;
            USE(label__False_167);
            Label label_if_done_label_591_942_impl(this, {v0_158, v1_159, v2_160});
            Label* label_if_done_label_591_942 = &label_if_done_label_591_942_impl;
            USE(label_if_done_label_591_942);
            int31_t t532 = 0;
            TNode<Number> t533 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t532)));
            BranchIfNumberGreaterThanOrEqual(implicit_cast<TNode<Number>>((*c02_590)), implicit_cast<TNode<Number>>(t533), label__True_166, label__False_167);
            if (label__True_166->is_used())
            {
              BIND(label__True_166);
              // ../src/builtins/typed-array.tq:154:21
              {
                // ../src/builtins/typed-array.tq:156:9
                TNode<Object> tmp_592_impl;
                auto tmp_592 = &tmp_592_impl;
                USE(tmp_592);
                *tmp_592 = implicit_cast<TNode<Object>>((*v0_158).value());
                // ../src/builtins/typed-array.tq:157:9
                *v0_158 = implicit_cast<TNode<Object>>((*v2_160).value());
                // ../src/builtins/typed-array.tq:158:9
                *v2_160 = implicit_cast<TNode<Object>>((*v1_159).value());
                // ../src/builtins/typed-array.tq:159:9
                *v1_159 = implicit_cast<TNode<Object>>((*tmp_592));
              }
              Goto(label_if_done_label_591_942);
            }
            if (label__False_167->is_used())
            {
              BIND(label__False_167);
              // ../src/builtins/typed-array.tq:160:14
              {
                // ../src/builtins/typed-array.tq:162:9
                TNode<Number> t534 = UncheckedCast<Number>(CallCompareWithDetachedCheck(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Object>>((*v1_159).value()), implicit_cast<TNode<Object>>((*v2_160).value()), label_Detached_157));
                USE(implicit_cast<TNode<Number>>(t534));
                TNode<Number> c12_593_impl;
                auto c12_593 = &c12_593_impl;
                USE(c12_593);
                *c12_593 = implicit_cast<TNode<Number>>(t534);
                // ../src/builtins/typed-array.tq:164:9
                {
                  Label label__True_168_impl(this);
                  Label* label__True_168 = &label__True_168_impl;
                  USE(label__True_168);
                  Label label__False_169_impl(this, {v1_159, v2_160});
                  Label* label__False_169 = &label__False_169_impl;
                  USE(label__False_169);
                  int31_t t535 = 0;
                  TNode<Number> t536 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t535)));
                  BranchIfNumberGreaterThan(implicit_cast<TNode<Number>>((*c12_593)), implicit_cast<TNode<Number>>(t536), label__True_168, label__False_169);
                  if (label__True_168->is_used())
                  {
                    BIND(label__True_168);
                    // ../src/builtins/typed-array.tq:164:22
                    {
                      // ../src/builtins/typed-array.tq:166:11
                      TNode<Object> tmp_594_impl;
                      auto tmp_594 = &tmp_594_impl;
                      USE(tmp_594);
                      *tmp_594 = implicit_cast<TNode<Object>>((*v1_159).value());
                      // ../src/builtins/typed-array.tq:167:11
                      *v1_159 = implicit_cast<TNode<Object>>((*v2_160).value());
                      // ../src/builtins/typed-array.tq:168:11
                      *v2_160 = implicit_cast<TNode<Object>>((*tmp_594));
                    }
                    Goto(label__False_169);
                  }
                  BIND(label__False_169);
                }
              }
              Goto(label_if_done_label_591_942);
            }
            BIND(label_if_done_label_591_942);
          }
          // ../src/builtins/typed-array.tq:173:7
          TNode<Object> t537 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*from_156).value()), implicit_cast<TNode<Object>>((*v0_158).value())));
          USE(implicit_cast<TNode<Object>>(t537));
          // ../src/builtins/typed-array.tq:174:7
          int31_t t538 = 1;
          TNode<Smi> t539 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t538)));
          TNode<Smi> t540 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*to_157).value()), implicit_cast<TNode<Smi>>(t539)));
          USE(implicit_cast<TNode<Smi>>(t540));
          TNode<Object> t541 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>(t540), implicit_cast<TNode<Object>>((*v2_160).value())));
          USE(implicit_cast<TNode<Object>>(t541));
          // ../src/builtins/typed-array.tq:176:7
          TNode<Object> pivot_595_impl;
          auto pivot_595 = &pivot_595_impl;
          USE(pivot_595);
          *pivot_595 = implicit_cast<TNode<Object>>((*v1_159).value());
          // ../src/builtins/typed-array.tq:177:7
          int31_t t542 = 1;
          TNode<Smi> t543 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t542)));
          TNode<Smi> t544 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*from_156).value()), implicit_cast<TNode<Smi>>(t543)));
          USE(implicit_cast<TNode<Smi>>(t544));
          TVARIABLE(Smi, low_end_162_impl);
          auto low_end_162 = &low_end_162_impl;
          USE(low_end_162);
          *low_end_162 = implicit_cast<TNode<Smi>>(t544);
          // ../src/builtins/typed-array.tq:178:7
          int31_t t545 = 1;
          TNode<Smi> t546 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t545)));
          TNode<Smi> t547 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*to_157).value()), implicit_cast<TNode<Smi>>(t546)));
          USE(implicit_cast<TNode<Smi>>(t547));
          TVARIABLE(Smi, high_start_163_impl);
          auto high_start_163 = &high_start_163_impl;
          USE(high_start_163);
          *high_start_163 = implicit_cast<TNode<Smi>>(t547);
          // ../src/builtins/typed-array.tq:180:7
          TNode<Object> t548 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*low_end_162).value())));
          USE(implicit_cast<TNode<Object>>(t548));
          TVARIABLE(Object, low_end_value_164_impl);
          auto low_end_value_164 = &low_end_value_164_impl;
          USE(low_end_value_164);
          *low_end_value_164 = implicit_cast<TNode<Object>>(t548);
          // ../src/builtins/typed-array.tq:181:7
          TNode<Object> t549 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*third_index_588)), implicit_cast<TNode<Object>>((*low_end_value_164).value())));
          USE(implicit_cast<TNode<Object>>(t549));
          // ../src/builtins/typed-array.tq:182:7
          TNode<Object> t550 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*low_end_162).value()), implicit_cast<TNode<Object>>((*pivot_595))));
          USE(implicit_cast<TNode<Object>>(t550));
          // ../src/builtins/typed-array.tq:186:7
          int31_t t551 = 1;
          TNode<Smi> t552 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t551)));
          TNode<Smi> t553 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*low_end_162).value()), implicit_cast<TNode<Smi>>(t552)));
          USE(implicit_cast<TNode<Smi>>(t553));
          TVARIABLE(Smi, idx_165_impl);
          auto idx_165 = &idx_165_impl;
          USE(idx_165);
          *idx_165 = implicit_cast<TNode<Smi>>(t553);
          Label label__True_170_impl(this);
          Label* label__True_170 = &label__True_170_impl;
          USE(label__True_170);
          Label label__False_171_impl(this);
          Label* label__False_171 = &label__False_171_impl;
          USE(label__False_171);
          Label label_header_596_943_impl(this, {high_start_163, idx_165, low_end_162, low_end_value_164});
          Label* label_header_596_943 = &label_header_596_943_impl;
          USE(label_header_596_943);
          Goto(label_header_596_943);
          BIND(label_header_596_943);
          Label label_action_597_944_impl(this);
          Label* label_action_597_944 = &label_action_597_944_impl;
          USE(label_action_597_944);
          TNode<BoolT> t554 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*idx_165).value()), implicit_cast<TNode<Smi>>((*high_start_163).value())));
          USE(implicit_cast<TNode<BoolT>>(t554));
          Branch(implicit_cast<TNode<BoolT>>(t554), label__True_170, label__False_171);
          if (label__True_170->is_used())
          {
            BIND(label__True_170);
            // ../src/builtins/typed-array.tq:186:65
            {
              // ../src/builtins/typed-array.tq:187:9
              TNode<Object> t555 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*idx_165).value())));
              USE(implicit_cast<TNode<Object>>(t555));
              TVARIABLE(Object, element_166_impl);
              auto element_166 = &element_166_impl;
              USE(element_166);
              *element_166 = implicit_cast<TNode<Object>>(t555);
              // ../src/builtins/typed-array.tq:188:9
              TNode<Number> t556 = UncheckedCast<Number>(CallCompareWithDetachedCheck(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Object>>((*element_166).value()), implicit_cast<TNode<Object>>((*pivot_595)), label_Detached_157));
              USE(implicit_cast<TNode<Number>>(t556));
              TVARIABLE(Number, order_167_impl);
              auto order_167 = &order_167_impl;
              USE(order_167);
              *order_167 = implicit_cast<TNode<Number>>(t556);
              // ../src/builtins/typed-array.tq:191:9
              {
                Label label__True_172_impl(this);
                Label* label__True_172 = &label__True_172_impl;
                USE(label__True_172);
                Label label__False_173_impl(this);
                Label* label__False_173 = &label__False_173_impl;
                USE(label__False_173);
                Label label_if_done_label_598_945_impl(this, {element_166, high_start_163, low_end_162, low_end_value_164, order_167});
                Label* label_if_done_label_598_945 = &label_if_done_label_598_945_impl;
                USE(label_if_done_label_598_945);
                int31_t t557 = 0;
                TNode<Number> t558 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t557)));
                BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_167).value()), implicit_cast<TNode<Number>>(t558), label__True_172, label__False_173);
                if (label__True_172->is_used())
                {
                  BIND(label__True_172);
                  // ../src/builtins/typed-array.tq:191:24
                  {
                    // ../src/builtins/typed-array.tq:192:11
                    TNode<Object> t559 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*low_end_162).value())));
                    USE(implicit_cast<TNode<Object>>(t559));
                    *low_end_value_164 = implicit_cast<TNode<Object>>(t559);
                    // ../src/builtins/typed-array.tq:193:11
                    TNode<Object> t560 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*idx_165).value()), implicit_cast<TNode<Object>>((*low_end_value_164).value())));
                    USE(implicit_cast<TNode<Object>>(t560));
                    // ../src/builtins/typed-array.tq:194:11
                    TNode<Object> t561 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*low_end_162).value()), implicit_cast<TNode<Object>>((*element_166).value())));
                    USE(implicit_cast<TNode<Object>>(t561));
                    // ../src/builtins/typed-array.tq:195:11
                    TNode<Smi> t562 = implicit_cast<TNode<Smi>>((*low_end_162).value());
                    USE(t562);
                    TNode<Smi> t563 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                    TNode<Smi> t564 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*low_end_162).value()), implicit_cast<TNode<Smi>>(t563)));
                    *low_end_162 = implicit_cast<TNode<Smi>>(t564);
                  }
                  Goto(label_if_done_label_598_945);
                }
                if (label__False_173->is_used())
                {
                  BIND(label__False_173);
                  // ../src/builtins/typed-array.tq:196:16
                  {
                    Label label__True_174_impl(this);
                    Label* label__True_174 = &label__True_174_impl;
                    USE(label__True_174);
                    Label label__False_175_impl(this, {element_166, high_start_163, low_end_162, low_end_value_164, order_167});
                    Label* label__False_175 = &label__False_175_impl;
                    USE(label__False_175);
                    int31_t t565 = 0;
                    TNode<Number> t566 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t565)));
                    BranchIfNumberGreaterThan(implicit_cast<TNode<Number>>((*order_167).value()), implicit_cast<TNode<Number>>(t566), label__True_174, label__False_175);
                    if (label__True_174->is_used())
                    {
                      BIND(label__True_174);
                      // ../src/builtins/typed-array.tq:196:31
                      {
                        // ../src/builtins/typed-array.tq:197:11
                        TVARIABLE(BoolT, break_for_168_impl);
                        auto break_for_168 = &break_for_168_impl;
                        USE(break_for_168);
                        TNode<BoolT> t567 = UncheckedCast<BoolT>(from_constexpr6ATbool(implicit_cast<bool>(false)));
                        *break_for_168 = implicit_cast<TNode<BoolT>>(t567);
                        // ../src/builtins/typed-array.tq:199:11
                        {
                          Label label__True_176_impl(this);
                          Label* label__True_176 = &label__True_176_impl;
                          USE(label__True_176);
                          Label label__False_177_impl(this);
                          Label* label__False_177 = &label__False_177_impl;
                          USE(label__False_177);
                          Label label_header_599_946_impl(this, {break_for_168, high_start_163, order_167});
                          Label* label_header_599_946 = &label_header_599_946_impl;
                          USE(label_header_599_946);
                          Goto(label_header_599_946);
                          BIND(label_header_599_946);
                          int31_t t568 = 0;
                          TNode<Number> t569 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t568)));
                          BranchIfNumberGreaterThan(implicit_cast<TNode<Number>>((*order_167).value()), implicit_cast<TNode<Number>>(t569), label__True_176, label__False_177);
                          if (label__True_176->is_used())
                          {
                            BIND(label__True_176);
                            // ../src/builtins/typed-array.tq:199:29
                            {
                              // ../src/builtins/typed-array.tq:200:13
                              TNode<Smi> t570 = implicit_cast<TNode<Smi>>((*high_start_163).value());
                              USE(t570);
                              TNode<Smi> t571 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                              TNode<Smi> t572 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*high_start_163).value()), implicit_cast<TNode<Smi>>(t571)));
                              *high_start_163 = implicit_cast<TNode<Smi>>(t572);
                              // ../src/builtins/typed-array.tq:201:13
                              {
                                Label label__True_178_impl(this);
                                Label* label__True_178 = &label__True_178_impl;
                                USE(label__True_178);
                                Label label__False_179_impl(this, {break_for_168});
                                Label* label__False_179 = &label__False_179_impl;
                                USE(label__False_179);
                                TNode<BoolT> t573 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*high_start_163).value()), implicit_cast<TNode<Smi>>((*idx_165).value())));
                                USE(implicit_cast<TNode<BoolT>>(t573));
                                Branch(implicit_cast<TNode<BoolT>>(t573), label__True_178, label__False_179);
                                if (label__True_178->is_used())
                                {
                                  BIND(label__True_178);
                                  // ../src/builtins/typed-array.tq:201:36
                                  {
                                    // ../src/builtins/typed-array.tq:202:15
                                    TNode<BoolT> t574 = UncheckedCast<BoolT>(from_constexpr6ATbool(implicit_cast<bool>(true)));
                                    *break_for_168 = implicit_cast<TNode<BoolT>>(t574);
                                    // ../src/builtins/typed-array.tq:203:15
                                    Goto(label__False_177);
                                  }
                                }
                                BIND(label__False_179);
                              }
                              // ../src/builtins/typed-array.tq:206:13
                              TNode<Object> t575 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*high_start_163).value())));
                              USE(implicit_cast<TNode<Object>>(t575));
                              TNode<Object> top_elem_600_impl;
                              auto top_elem_600 = &top_elem_600_impl;
                              USE(top_elem_600);
                              *top_elem_600 = implicit_cast<TNode<Object>>(t575);
                              // ../src/builtins/typed-array.tq:207:13
                              TNode<Number> t576 = UncheckedCast<Number>(CallCompareWithDetachedCheck(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Object>>((*top_elem_600)), implicit_cast<TNode<Object>>((*pivot_595)), label_Detached_157));
                              USE(implicit_cast<TNode<Number>>(t576));
                              *order_167 = implicit_cast<TNode<Number>>(t576);
                            }
                            Goto(label_header_599_946);
                          }
                          BIND(label__False_177);
                        }
                        // ../src/builtins/typed-array.tq:211:11
                        {
                          Label label__True_180_impl(this);
                          Label* label__True_180 = &label__True_180_impl;
                          USE(label__True_180);
                          Label label__False_181_impl(this, {});
                          Label* label__False_181 = &label__False_181_impl;
                          USE(label__False_181);
                          Branch(implicit_cast<TNode<BoolT>>((*break_for_168).value()), label__True_180, label__False_181);
                          if (label__True_180->is_used())
                          {
                            BIND(label__True_180);
                            // ../src/builtins/typed-array.tq:211:26
                            {
                              // ../src/builtins/typed-array.tq:212:13
                              Goto(label__False_171);
                            }
                          }
                          BIND(label__False_181);
                        }
                        // ../src/builtins/typed-array.tq:215:11
                        TNode<Object> t577 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*high_start_163).value())));
                        USE(implicit_cast<TNode<Object>>(t577));
                        TNode<Object> high_start_value_601_impl;
                        auto high_start_value_601 = &high_start_value_601_impl;
                        USE(high_start_value_601);
                        *high_start_value_601 = implicit_cast<TNode<Object>>(t577);
                        // ../src/builtins/typed-array.tq:216:11
                        TNode<Object> t578 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*idx_165).value()), implicit_cast<TNode<Object>>((*high_start_value_601))));
                        USE(implicit_cast<TNode<Object>>(t578));
                        // ../src/builtins/typed-array.tq:217:11
                        TNode<Object> t579 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*high_start_163).value()), implicit_cast<TNode<Object>>((*element_166).value())));
                        USE(implicit_cast<TNode<Object>>(t579));
                        // ../src/builtins/typed-array.tq:219:11
                        {
                          Label label__True_182_impl(this);
                          Label* label__True_182 = &label__True_182_impl;
                          USE(label__True_182);
                          Label label__False_183_impl(this, {element_166, low_end_162, low_end_value_164});
                          Label* label__False_183 = &label__False_183_impl;
                          USE(label__False_183);
                          int31_t t580 = 0;
                          TNode<Number> t581 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t580)));
                          BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_167).value()), implicit_cast<TNode<Number>>(t581), label__True_182, label__False_183);
                          if (label__True_182->is_used())
                          {
                            BIND(label__True_182);
                            // ../src/builtins/typed-array.tq:219:26
                            {
                              // ../src/builtins/typed-array.tq:220:13
                              TNode<Object> t582 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*idx_165).value())));
                              USE(implicit_cast<TNode<Object>>(t582));
                              *element_166 = implicit_cast<TNode<Object>>(t582);
                              // ../src/builtins/typed-array.tq:222:13
                              TNode<Object> t583 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*low_end_162).value())));
                              USE(implicit_cast<TNode<Object>>(t583));
                              *low_end_value_164 = implicit_cast<TNode<Object>>(t583);
                              // ../src/builtins/typed-array.tq:223:13
                              TNode<Object> t584 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*idx_165).value()), implicit_cast<TNode<Object>>((*low_end_value_164).value())));
                              USE(implicit_cast<TNode<Object>>(t584));
                              // ../src/builtins/typed-array.tq:224:13
                              TNode<Object> t585 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*low_end_162).value()), implicit_cast<TNode<Object>>((*element_166).value())));
                              USE(implicit_cast<TNode<Object>>(t585));
                              // ../src/builtins/typed-array.tq:225:13
                              TNode<Smi> t586 = implicit_cast<TNode<Smi>>((*low_end_162).value());
                              USE(t586);
                              TNode<Smi> t587 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                              TNode<Smi> t588 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*low_end_162).value()), implicit_cast<TNode<Smi>>(t587)));
                              *low_end_162 = implicit_cast<TNode<Smi>>(t588);
                            }
                            Goto(label__False_183);
                          }
                          BIND(label__False_183);
                        }
                      }
                      Goto(label__False_175);
                    }
                    BIND(label__False_175);
                  }
                  Goto(label_if_done_label_598_945);
                }
                BIND(label_if_done_label_598_945);
              }
            }
            Goto(label_action_597_944);
          }
          {
            BIND(label_action_597_944);
            TNode<Smi> t589 = implicit_cast<TNode<Smi>>((*idx_165).value());
            USE(t589);
            TNode<Smi> t590 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
            TNode<Smi> t591 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*idx_165).value()), implicit_cast<TNode<Smi>>(t590)));
            *idx_165 = implicit_cast<TNode<Smi>>(t591);
            Goto(label_header_596_943);
          }
          BIND(label__False_171);
          // ../src/builtins/typed-array.tq:230:7
          {
            Label label__True_184_impl(this);
            Label* label__True_184 = &label__True_184_impl;
            USE(label__True_184);
            Label label__False_185_impl(this);
            Label* label__False_185 = &label__False_185_impl;
            USE(label__False_185);
            Label label_if_done_label_602_947_impl(this, {from_156, to_157});
            Label* label_if_done_label_602_947 = &label_if_done_label_602_947_impl;
            USE(label_if_done_label_602_947);
            TNode<Smi> t592 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*to_157).value()), implicit_cast<TNode<Smi>>((*high_start_163).value())));
            USE(implicit_cast<TNode<Smi>>(t592));
            TNode<Smi> t593 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*low_end_162).value()), implicit_cast<TNode<Smi>>((*from_156).value())));
            USE(implicit_cast<TNode<Smi>>(t593));
            TNode<BoolT> t594 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>(t592), implicit_cast<TNode<Smi>>(t593)));
            USE(implicit_cast<TNode<BoolT>>(t594));
            Branch(implicit_cast<TNode<BoolT>>(t594), label__True_184, label__False_185);
            if (label__True_184->is_used())
            {
              BIND(label__True_184);
              // ../src/builtins/typed-array.tq:230:49
              {
                // ../src/builtins/typed-array.tq:231:9
                TNode<JSTypedArray> t595 = UncheckedCast<JSTypedArray>(CallBuiltin(Builtins::kTypedArrayQuickSort, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*high_start_163).value()), implicit_cast<TNode<Smi>>((*to_157).value()), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Code>>(p_Store)));
                USE(implicit_cast<TNode<JSTypedArray>>(t595));
                // ../src/builtins/typed-array.tq:233:9
                *to_157 = implicit_cast<TNode<Smi>>((*low_end_162).value());
              }
              Goto(label_if_done_label_602_947);
            }
            if (label__False_185->is_used())
            {
              BIND(label__False_185);
              // ../src/builtins/typed-array.tq:234:14
              {
                // ../src/builtins/typed-array.tq:235:9
                TNode<JSTypedArray> t596 = UncheckedCast<JSTypedArray>(CallBuiltin(Builtins::kTypedArrayQuickSort, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>((*from_156).value()), implicit_cast<TNode<Smi>>((*low_end_162).value()), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Code>>(p_Store)));
                USE(implicit_cast<TNode<JSTypedArray>>(t596));
                // ../src/builtins/typed-array.tq:237:9
                *from_156 = implicit_cast<TNode<Smi>>((*high_start_163).value());
              }
              Goto(label_if_done_label_602_947);
            }
            BIND(label_if_done_label_602_947);
          }
        }
        Goto(label_header_587_941);
      }
      BIND(label__False_159);
    }
  }
}

TF_BUILTIN(TypedArrayQuickSort, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_from = UncheckedCast<Smi>(Parameter(Descriptor::kFrom));
  USE(p_from);
  TNode<Smi> p_to = UncheckedCast<Smi>(Parameter(Descriptor::kTo));
  USE(p_to);
  TNode<JSReceiver> p_comparefn = UncheckedCast<JSReceiver>(Parameter(Descriptor::kComparefn));
  USE(p_comparefn);
  TNode<Code> p_Load = UncheckedCast<Code>(Parameter(Descriptor::kLoad));
  USE(p_Load);
  TNode<Code> p_Store = UncheckedCast<Code>(Parameter(Descriptor::kStore));
  USE(p_Store);
  // ../src/builtins/typed-array.tq:244:72
  {
    // ../src/builtins/typed-array.tq:245:5
    {
      Label label_try_done_603_948_impl(this);
      Label* label_try_done_603_948 = &label_try_done_603_948_impl;
      USE(label_try_done_603_948);
      Label label_Detached_186_impl(this);
      Label* label_Detached_186 = &label_Detached_186_impl;
      USE(label_Detached_186);
      Label label_try_begin_604_949_impl(this);
      Label* label_try_begin_604_949 = &label_try_begin_604_949_impl;
      USE(label_try_begin_604_949);
      Goto(label_try_begin_604_949);
      if (label_try_begin_604_949->is_used())
      {
        BIND(label_try_begin_604_949);
        // ../src/builtins/typed-array.tq:245:9
        {
          // ../src/builtins/typed-array.tq:246:7
          TypedArrayQuickSortImpl(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>(p_array), implicit_cast<TNode<Smi>>(p_from), implicit_cast<TNode<Smi>>(p_to), implicit_cast<TNode<JSReceiver>>(p_comparefn), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Code>>(p_Store), label_Detached_186);
        }
        Goto(label_try_done_603_948);
      }
      if (label_Detached_186->is_used())
      {
        BIND(label_Detached_186);
        // ../src/builtins/typed-array.tq:249:20
        {
          // ../src/builtins/typed-array.tq:250:7
          const char* t597 = "%TypedArray%.prototype.sort";
          TNode<Object> t598 = UncheckedCast<Object>(from_constexpr22UT12ATHeapObject5ATSmi(implicit_cast<const char*>(t597)));
          ThrowTypeError(implicit_cast<TNode<Context>>(p_context), implicit_cast<MessageTemplate::Template>(MessageTemplate::kDetachedOperation), implicit_cast<TNode<Object>>(t598));
        }
      }
      BIND(label_try_done_603_948);
    }
    // ../src/builtins/typed-array.tq:253:5
    Return(implicit_cast<TNode<JSTypedArray>>(p_array));
  }
}

TF_BUILTIN(TypedArrayPrototypeSort, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  CodeStubArguments arguments_impl(this, ChangeInt32ToIntPtr(argc));
  TNode<Object> p_receiver = arguments_impl.GetReceiver();
  auto arguments = &arguments_impl;
  USE(arguments);
  USE(p_receiver);
  // ../src/builtins/typed-array.tq:258:71
  {
    // ../src/builtins/typed-array.tq:261:5
    auto t599 = [=]() {
      int31_t t601 = 0;
      TNode<IntPtrT> t602 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t601)));
      TNode<Object> t603 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t602)));
      return implicit_cast<TNode<Object>>(t603);
    };
    auto t600 = [=]() {
      return implicit_cast<TNode<Oddball>>(Undefined());
    };
    TVARIABLE(Object, t604_605_impl);
    auto t604_605 = &t604_605_impl;
    USE(t604_605);
    {
      Label label__True_187_impl(this);
      Label* label__True_187 = &label__True_187_impl;
      USE(label__True_187);
      Label label__False_188_impl(this);
      Label* label__False_188 = &label__False_188_impl;
      USE(label__False_188);
      Label label__done_606_950_impl(this, {t604_605});
      Label* label__done_606_950 = &label__done_606_950_impl;
      USE(label__done_606_950);
      TNode<IntPtrT> t605 = UncheckedCast<IntPtrT>(GetArgumentsLength(implicit_cast<CodeStubArguments*>(arguments)));
      int31_t t606 = 0;
      TNode<IntPtrT> t607 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t606)));
      TNode<BoolT> t608 = UncheckedCast<BoolT>(IntPtrGreaterThan(implicit_cast<TNode<IntPtrT>>(t605), implicit_cast<TNode<IntPtrT>>(t607)));
      USE(implicit_cast<TNode<BoolT>>(t608));
      Branch(implicit_cast<TNode<BoolT>>(t608), label__True_187, label__False_188);
      BIND(label__True_187);
            *t604_605 = implicit_cast<TNode<Object>>(t599());
      Goto(label__done_606_950);
      BIND(label__False_188);
            *t604_605 = implicit_cast<TNode<Object>>(t600());
      Goto(label__done_606_950);
      BIND(label__done_606_950);
    }
    TNode<Object> comparefn_obj_607_impl;
    auto comparefn_obj_607 = &comparefn_obj_607_impl;
    USE(comparefn_obj_607);
    *comparefn_obj_607 = implicit_cast<TNode<Object>>((*t604_605).value());
    // ../src/builtins/typed-array.tq:263:5
    {
      Label label__True_189_impl(this);
      Label* label__True_189 = &label__True_189_impl;
      USE(label__True_189);
      Label label__False_190_impl(this, {});
      Label* label__False_190 = &label__False_190_impl;
      USE(label__False_190);
      Label label__True_191_impl(this);
      Label* label__True_191 = &label__True_191_impl;
      USE(label__True_191);
      TNode<BoolT> t609 = UncheckedCast<BoolT>(WordNotEqual(implicit_cast<TNode<Object>>((*comparefn_obj_607)), implicit_cast<TNode<Object>>(Undefined())));
      USE(implicit_cast<TNode<BoolT>>(t609));
      GotoIfNot(implicit_cast<TNode<BoolT>>(t609), label__False_190);
      TNode<BoolT> t610 = UncheckedCast<BoolT>(TaggedIsCallable(implicit_cast<TNode<Object>>((*comparefn_obj_607))));
      USE(implicit_cast<TNode<BoolT>>(t610));
      TNode<BoolT> t611 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t610)));
      USE(implicit_cast<TNode<BoolT>>(t611));
      Branch(implicit_cast<TNode<BoolT>>(t611), label__True_189, label__False_190);
      if (label__True_189->is_used())
      {
        BIND(label__True_189);
        // ../src/builtins/typed-array.tq:263:73
        {
          // ../src/builtins/typed-array.tq:264:7
          ThrowTypeError(implicit_cast<TNode<Context>>(p_context), implicit_cast<MessageTemplate::Template>(MessageTemplate::kBadSortComparisonFunction), implicit_cast<TNode<Object>>((*comparefn_obj_607)));
        }
      }
      BIND(label__False_190);
    }
    // ../src/builtins/typed-array.tq:268:5
    TNode<Object> obj_608_impl;
    auto obj_608 = &obj_608_impl;
    USE(obj_608);
    *obj_608 = implicit_cast<TNode<Object>>(p_receiver);
    // ../src/builtins/typed-array.tq:272:5
    const char* t612 = "%TypedArray%.prototype.sort";
    TNode<JSTypedArray> t613 = UncheckedCast<JSTypedArray>(ValidateTypedArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*obj_608)), implicit_cast<const char*>(t612)));
    USE(implicit_cast<TNode<JSTypedArray>>(t613));
    TNode<JSTypedArray> array_609_impl;
    auto array_609 = &array_609_impl;
    USE(array_609);
    *array_609 = implicit_cast<TNode<JSTypedArray>>(t613);
    // ../src/builtins/typed-array.tq:276:5
    {
      Label label__True_192_impl(this);
      Label* label__True_192 = &label__True_192_impl;
      USE(label__True_192);
      Label label__False_193_impl(this, {});
      Label* label__False_193 = &label__False_193_impl;
      USE(label__False_193);
      TNode<BoolT> t614 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*comparefn_obj_607)), implicit_cast<TNode<Object>>(Undefined())));
      USE(implicit_cast<TNode<BoolT>>(t614));
      Branch(implicit_cast<TNode<BoolT>>(t614), label__True_192, label__False_193);
      if (label__True_192->is_used())
      {
        BIND(label__True_192);
        // ../src/builtins/typed-array.tq:276:37
        {
          // ../src/builtins/typed-array.tq:277:7
          TNode<JSTypedArray> t615 = UncheckedCast<JSTypedArray>(CallRuntime(Runtime::kTypedArraySortFast, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*obj_608))));
          USE(implicit_cast<TNode<JSTypedArray>>(t615));
          arguments->PopAndReturn(implicit_cast<TNode<JSTypedArray>>(t615));
        }
      }
      BIND(label__False_193);
    }
    // ../src/builtins/typed-array.tq:281:5
    TNode<Smi> t616 = UncheckedCast<Smi>(LoadTypedArrayLength(implicit_cast<TNode<JSTypedArray>>((*array_609))));
    TNode<Smi> len_610_impl;
    auto len_610 = &len_610_impl;
    USE(len_610);
    *len_610 = implicit_cast<TNode<Smi>>(t616);
    // ../src/builtins/typed-array.tq:283:5
    {
      Label label_try_done_611_951_impl(this);
      Label* label_try_done_611_951 = &label_try_done_611_951_impl;
      USE(label_try_done_611_951);
      Label label_CastError_194_impl(this);
      Label* label_CastError_194 = &label_CastError_194_impl;
      USE(label_CastError_194);
      Label label_try_begin_612_952_impl(this);
      Label* label_try_begin_612_952 = &label_try_begin_612_952_impl;
      USE(label_try_begin_612_952);
      Goto(label_try_begin_612_952);
      if (label_try_begin_612_952->is_used())
      {
        BIND(label_try_begin_612_952);
        // ../src/builtins/typed-array.tq:283:9
        {
          // ../src/builtins/typed-array.tq:284:7
          TNode<JSReceiver> t617 = UncheckedCast<JSReceiver>(cast45UT17ATJSBoundFunction12ATJSFunction9ATJSProxy(implicit_cast<TNode<Object>>((*comparefn_obj_607)), label_CastError_194));
          USE(implicit_cast<TNode<JSReceiver>>(t617));
          TNode<JSReceiver> comparefn_613_impl;
          auto comparefn_613 = &comparefn_613_impl;
          USE(comparefn_613);
          *comparefn_613 = implicit_cast<TNode<JSReceiver>>(t617);
          // ../src/builtins/typed-array.tq:286:7
          TVARIABLE(Code, loadfn_169_impl);
          auto loadfn_169 = &loadfn_169_impl;
          USE(loadfn_169);
          // ../src/builtins/typed-array.tq:287:7
          TVARIABLE(Code, storefn_170_impl);
          auto storefn_170 = &storefn_170_impl;
          USE(storefn_170);
          // ../src/builtins/typed-array.tq:289:7
          TNode<Int32T> t618 = UncheckedCast<Int32T>(LoadElementsKind(implicit_cast<TNode<JSTypedArray>>((*array_609))));
          TVARIABLE(Int32T, elements_kind_171_impl);
          auto elements_kind_171 = &elements_kind_171_impl;
          USE(elements_kind_171);
          *elements_kind_171 = implicit_cast<TNode<Int32T>>(t618);
          // ../src/builtins/typed-array.tq:291:7
          {
            Label label__True_195_impl(this);
            Label* label__True_195 = &label__True_195_impl;
            USE(label__True_195);
            Label label__False_196_impl(this);
            Label* label__False_196 = &label__False_196_impl;
            USE(label__False_196);
            Label label_if_done_label_614_953_impl(this, {loadfn_169, storefn_170});
            Label* label_if_done_label_614_953 = &label_if_done_label_614_953_impl;
            USE(label_if_done_label_614_953);
            TNode<BoolT> t619 = UncheckedCast<BoolT>(IsElementsKindGreaterThan(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<ElementsKind>(UINT32_ELEMENTS)));
            USE(implicit_cast<TNode<BoolT>>(t619));
            Branch(implicit_cast<TNode<BoolT>>(t619), label__True_195, label__False_196);
            if (label__True_195->is_used())
            {
              BIND(label__True_195);
              // ../src/builtins/typed-array.tq:291:70
              {
                // ../src/builtins/typed-array.tq:292:9
                {
                  Label label__True_197_impl(this);
                  Label* label__True_197 = &label__True_197_impl;
                  USE(label__True_197);
                  Label label__False_198_impl(this);
                  Label* label__False_198 = &label__False_198_impl;
                  USE(label__False_198);
                  Label label_if_done_label_615_954_impl(this, {loadfn_169, storefn_170});
                  Label* label_if_done_label_615_954 = &label_if_done_label_615_954_impl;
                  USE(label_if_done_label_615_954);
                  TNode<Int32T> t620 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(INT32_ELEMENTS)));
                  TNode<BoolT> t621 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t620)));
                  USE(implicit_cast<TNode<BoolT>>(t621));
                  Branch(implicit_cast<TNode<BoolT>>(t621), label__True_197, label__False_198);
                  if (label__True_197->is_used())
                  {
                    BIND(label__True_197);
                    // ../src/builtins/typed-array.tq:292:46
                    {
                      // ../src/builtins/typed-array.tq:293:11
                      *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt32Array).code()));
                      // ../src/builtins/typed-array.tq:294:11
                      *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt32Array).code()));
                    }
                    Goto(label_if_done_label_615_954);
                  }
                  if (label__False_198->is_used())
                  {
                    BIND(label__False_198);
                    // ../src/builtins/typed-array.tq:295:16
                    {
                      Label label__True_199_impl(this);
                      Label* label__True_199 = &label__True_199_impl;
                      USE(label__True_199);
                      Label label__False_200_impl(this);
                      Label* label__False_200 = &label__False_200_impl;
                      USE(label__False_200);
                      Label label_if_done_label_616_955_impl(this, {loadfn_169, storefn_170});
                      Label* label_if_done_label_616_955 = &label_if_done_label_616_955_impl;
                      USE(label_if_done_label_616_955);
                      TNode<Int32T> t622 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(FLOAT32_ELEMENTS)));
                      TNode<BoolT> t623 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t622)));
                      USE(implicit_cast<TNode<BoolT>>(t623));
                      Branch(implicit_cast<TNode<BoolT>>(t623), label__True_199, label__False_200);
                      if (label__True_199->is_used())
                      {
                        BIND(label__True_199);
                        // ../src/builtins/typed-array.tq:295:55
                        {
                          // ../src/builtins/typed-array.tq:296:11
                          *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement19ATFixedFloat32Array).code()));
                          // ../src/builtins/typed-array.tq:297:11
                          *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement19ATFixedFloat32Array).code()));
                        }
                        Goto(label_if_done_label_616_955);
                      }
                      if (label__False_200->is_used())
                      {
                        BIND(label__False_200);
                        // ../src/builtins/typed-array.tq:298:16
                        {
                          Label label__True_201_impl(this);
                          Label* label__True_201 = &label__True_201_impl;
                          USE(label__True_201);
                          Label label__False_202_impl(this);
                          Label* label__False_202 = &label__False_202_impl;
                          USE(label__False_202);
                          Label label_if_done_label_617_956_impl(this, {loadfn_169, storefn_170});
                          Label* label_if_done_label_617_956 = &label_if_done_label_617_956_impl;
                          USE(label_if_done_label_617_956);
                          TNode<Int32T> t624 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(FLOAT64_ELEMENTS)));
                          TNode<BoolT> t625 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t624)));
                          USE(implicit_cast<TNode<BoolT>>(t625));
                          Branch(implicit_cast<TNode<BoolT>>(t625), label__True_201, label__False_202);
                          if (label__True_201->is_used())
                          {
                            BIND(label__True_201);
                            // ../src/builtins/typed-array.tq:298:55
                            {
                              // ../src/builtins/typed-array.tq:299:11
                              *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement19ATFixedFloat64Array).code()));
                              // ../src/builtins/typed-array.tq:300:11
                              *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement19ATFixedFloat64Array).code()));
                            }
                            Goto(label_if_done_label_617_956);
                          }
                          if (label__False_202->is_used())
                          {
                            BIND(label__False_202);
                            // ../src/builtins/typed-array.tq:301:16
                            {
                              Label label__True_203_impl(this);
                              Label* label__True_203 = &label__True_203_impl;
                              USE(label__True_203);
                              Label label__False_204_impl(this);
                              Label* label__False_204 = &label__False_204_impl;
                              USE(label__False_204);
                              Label label_if_done_label_618_957_impl(this, {loadfn_169, storefn_170});
                              Label* label_if_done_label_618_957 = &label_if_done_label_618_957_impl;
                              USE(label_if_done_label_618_957);
                              TNode<Int32T> t626 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(UINT8_CLAMPED_ELEMENTS)));
                              TNode<BoolT> t627 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t626)));
                              USE(implicit_cast<TNode<BoolT>>(t627));
                              Branch(implicit_cast<TNode<BoolT>>(t627), label__True_203, label__False_204);
                              if (label__True_203->is_used())
                              {
                                BIND(label__True_203);
                                // ../src/builtins/typed-array.tq:301:61
                                {
                                  // ../src/builtins/typed-array.tq:302:11
                                  *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement24ATFixedUint8ClampedArray).code()));
                                  // ../src/builtins/typed-array.tq:303:11
                                  *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement24ATFixedUint8ClampedArray).code()));
                                }
                                Goto(label_if_done_label_618_957);
                              }
                              if (label__False_204->is_used())
                              {
                                BIND(label__False_204);
                                // ../src/builtins/typed-array.tq:304:16
                                {
                                  Label label__True_205_impl(this);
                                  Label* label__True_205 = &label__True_205_impl;
                                  USE(label__True_205);
                                  Label label__False_206_impl(this);
                                  Label* label__False_206 = &label__False_206_impl;
                                  USE(label__False_206);
                                  Label label_if_done_label_619_958_impl(this, {loadfn_169, storefn_170});
                                  Label* label_if_done_label_619_958 = &label_if_done_label_619_958_impl;
                                  USE(label_if_done_label_619_958);
                                  TNode<Int32T> t628 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(BIGUINT64_ELEMENTS)));
                                  TNode<BoolT> t629 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t628)));
                                  USE(implicit_cast<TNode<BoolT>>(t629));
                                  Branch(implicit_cast<TNode<BoolT>>(t629), label__True_205, label__False_206);
                                  if (label__True_205->is_used())
                                  {
                                    BIND(label__True_205);
                                    // ../src/builtins/typed-array.tq:304:57
                                    {
                                      // ../src/builtins/typed-array.tq:305:11
                                      *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement21ATFixedBigUint64Array).code()));
                                      // ../src/builtins/typed-array.tq:306:11
                                      *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement21ATFixedBigUint64Array).code()));
                                    }
                                    Goto(label_if_done_label_619_958);
                                  }
                                  if (label__False_206->is_used())
                                  {
                                    BIND(label__False_206);
                                    // ../src/builtins/typed-array.tq:307:16
                                    {
                                      Label label__True_207_impl(this);
                                      Label* label__True_207 = &label__True_207_impl;
                                      USE(label__True_207);
                                      Label label__False_208_impl(this);
                                      Label* label__False_208 = &label__False_208_impl;
                                      USE(label__False_208);
                                      Label label_if_done_label_620_959_impl(this, {loadfn_169, storefn_170});
                                      Label* label_if_done_label_620_959 = &label_if_done_label_620_959_impl;
                                      USE(label_if_done_label_620_959);
                                      TNode<Int32T> t630 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(BIGINT64_ELEMENTS)));
                                      TNode<BoolT> t631 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t630)));
                                      USE(implicit_cast<TNode<BoolT>>(t631));
                                      Branch(implicit_cast<TNode<BoolT>>(t631), label__True_207, label__False_208);
                                      if (label__True_207->is_used())
                                      {
                                        BIND(label__True_207);
                                        // ../src/builtins/typed-array.tq:307:56
                                        {
                                          // ../src/builtins/typed-array.tq:308:11
                                          *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement20ATFixedBigInt64Array).code()));
                                          // ../src/builtins/typed-array.tq:309:11
                                          *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement20ATFixedBigInt64Array).code()));
                                        }
                                        Goto(label_if_done_label_620_959);
                                      }
                                      if (label__False_208->is_used())
                                      {
                                        BIND(label__False_208);
                                        // ../src/builtins/typed-array.tq:310:16
                                        {
                                          // ../src/builtins/typed-array.tq:311:11
                                          Unreachable();
                                        }
                                      }
                                      BIND(label_if_done_label_620_959);
                                    }
                                    Goto(label_if_done_label_619_958);
                                  }
                                  BIND(label_if_done_label_619_958);
                                }
                                Goto(label_if_done_label_618_957);
                              }
                              BIND(label_if_done_label_618_957);
                            }
                            Goto(label_if_done_label_617_956);
                          }
                          BIND(label_if_done_label_617_956);
                        }
                        Goto(label_if_done_label_616_955);
                      }
                      BIND(label_if_done_label_616_955);
                    }
                    Goto(label_if_done_label_615_954);
                  }
                  BIND(label_if_done_label_615_954);
                }
              }
              Goto(label_if_done_label_614_953);
            }
            if (label__False_196->is_used())
            {
              BIND(label__False_196);
              // ../src/builtins/typed-array.tq:313:14
              {
                // ../src/builtins/typed-array.tq:314:9
                {
                  Label label__True_209_impl(this);
                  Label* label__True_209 = &label__True_209_impl;
                  USE(label__True_209);
                  Label label__False_210_impl(this);
                  Label* label__False_210 = &label__False_210_impl;
                  USE(label__False_210);
                  Label label_if_done_label_621_960_impl(this, {loadfn_169, storefn_170});
                  Label* label_if_done_label_621_960 = &label_if_done_label_621_960_impl;
                  USE(label_if_done_label_621_960);
                  TNode<Int32T> t632 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(UINT8_ELEMENTS)));
                  TNode<BoolT> t633 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t632)));
                  USE(implicit_cast<TNode<BoolT>>(t633));
                  Branch(implicit_cast<TNode<BoolT>>(t633), label__True_209, label__False_210);
                  if (label__True_209->is_used())
                  {
                    BIND(label__True_209);
                    // ../src/builtins/typed-array.tq:314:46
                    {
                      // ../src/builtins/typed-array.tq:315:11
                      *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedUint8Array).code()));
                      // ../src/builtins/typed-array.tq:316:11
                      *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedUint8Array).code()));
                    }
                    Goto(label_if_done_label_621_960);
                  }
                  if (label__False_210->is_used())
                  {
                    BIND(label__False_210);
                    // ../src/builtins/typed-array.tq:317:16
                    {
                      Label label__True_211_impl(this);
                      Label* label__True_211 = &label__True_211_impl;
                      USE(label__True_211);
                      Label label__False_212_impl(this);
                      Label* label__False_212 = &label__False_212_impl;
                      USE(label__False_212);
                      Label label_if_done_label_622_961_impl(this, {loadfn_169, storefn_170});
                      Label* label_if_done_label_622_961 = &label_if_done_label_622_961_impl;
                      USE(label_if_done_label_622_961);
                      TNode<Int32T> t634 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(INT8_ELEMENTS)));
                      TNode<BoolT> t635 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t634)));
                      USE(implicit_cast<TNode<BoolT>>(t635));
                      Branch(implicit_cast<TNode<BoolT>>(t635), label__True_211, label__False_212);
                      if (label__True_211->is_used())
                      {
                        BIND(label__True_211);
                        // ../src/builtins/typed-array.tq:317:52
                        {
                          // ../src/builtins/typed-array.tq:318:11
                          *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement16ATFixedInt8Array).code()));
                          // ../src/builtins/typed-array.tq:319:11
                          *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement16ATFixedInt8Array).code()));
                        }
                        Goto(label_if_done_label_622_961);
                      }
                      if (label__False_212->is_used())
                      {
                        BIND(label__False_212);
                        // ../src/builtins/typed-array.tq:320:16
                        {
                          Label label__True_213_impl(this);
                          Label* label__True_213 = &label__True_213_impl;
                          USE(label__True_213);
                          Label label__False_214_impl(this);
                          Label* label__False_214 = &label__False_214_impl;
                          USE(label__False_214);
                          Label label_if_done_label_623_962_impl(this, {loadfn_169, storefn_170});
                          Label* label_if_done_label_623_962 = &label_if_done_label_623_962_impl;
                          USE(label_if_done_label_623_962);
                          TNode<Int32T> t636 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(UINT16_ELEMENTS)));
                          TNode<BoolT> t637 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t636)));
                          USE(implicit_cast<TNode<BoolT>>(t637));
                          Branch(implicit_cast<TNode<BoolT>>(t637), label__True_213, label__False_214);
                          if (label__True_213->is_used())
                          {
                            BIND(label__True_213);
                            // ../src/builtins/typed-array.tq:320:54
                            {
                              // ../src/builtins/typed-array.tq:321:11
                              *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement18ATFixedUint16Array).code()));
                              // ../src/builtins/typed-array.tq:322:11
                              *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement18ATFixedUint16Array).code()));
                            }
                            Goto(label_if_done_label_623_962);
                          }
                          if (label__False_214->is_used())
                          {
                            BIND(label__False_214);
                            // ../src/builtins/typed-array.tq:323:16
                            {
                              Label label__True_215_impl(this);
                              Label* label__True_215 = &label__True_215_impl;
                              USE(label__True_215);
                              Label label__False_216_impl(this);
                              Label* label__False_216 = &label__False_216_impl;
                              USE(label__False_216);
                              Label label_if_done_label_624_963_impl(this, {loadfn_169, storefn_170});
                              Label* label_if_done_label_624_963 = &label_if_done_label_624_963_impl;
                              USE(label_if_done_label_624_963);
                              TNode<Int32T> t638 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(INT16_ELEMENTS)));
                              TNode<BoolT> t639 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t638)));
                              USE(implicit_cast<TNode<BoolT>>(t639));
                              Branch(implicit_cast<TNode<BoolT>>(t639), label__True_215, label__False_216);
                              if (label__True_215->is_used())
                              {
                                BIND(label__True_215);
                                // ../src/builtins/typed-array.tq:323:53
                                {
                                  // ../src/builtins/typed-array.tq:324:11
                                  *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement17ATFixedInt16Array).code()));
                                  // ../src/builtins/typed-array.tq:325:11
                                  *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement17ATFixedInt16Array).code()));
                                }
                                Goto(label_if_done_label_624_963);
                              }
                              if (label__False_216->is_used())
                              {
                                BIND(label__False_216);
                                // ../src/builtins/typed-array.tq:326:16
                                {
                                  Label label__True_217_impl(this);
                                  Label* label__True_217 = &label__True_217_impl;
                                  USE(label__True_217);
                                  Label label__False_218_impl(this);
                                  Label* label__False_218 = &label__False_218_impl;
                                  USE(label__False_218);
                                  Label label_if_done_label_625_964_impl(this, {loadfn_169, storefn_170});
                                  Label* label_if_done_label_625_964 = &label_if_done_label_625_964_impl;
                                  USE(label_if_done_label_625_964);
                                  TNode<Int32T> t640 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(UINT32_ELEMENTS)));
                                  TNode<BoolT> t641 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elements_kind_171).value()), implicit_cast<TNode<Int32T>>(t640)));
                                  USE(implicit_cast<TNode<BoolT>>(t641));
                                  Branch(implicit_cast<TNode<BoolT>>(t641), label__True_217, label__False_218);
                                  if (label__True_217->is_used())
                                  {
                                    BIND(label__True_217);
                                    // ../src/builtins/typed-array.tq:326:54
                                    {
                                      // ../src/builtins/typed-array.tq:327:11
                                      *loadfn_169 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoadFixedElement18ATFixedUint32Array).code()));
                                      // ../src/builtins/typed-array.tq:328:11
                                      *storefn_170 = implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStoreFixedElement18ATFixedUint32Array).code()));
                                    }
                                    Goto(label_if_done_label_625_964);
                                  }
                                  if (label__False_218->is_used())
                                  {
                                    BIND(label__False_218);
                                    // ../src/builtins/typed-array.tq:329:16
                                    {
                                      // ../src/builtins/typed-array.tq:330:11
                                      Unreachable();
                                    }
                                  }
                                  BIND(label_if_done_label_625_964);
                                }
                                Goto(label_if_done_label_624_963);
                              }
                              BIND(label_if_done_label_624_963);
                            }
                            Goto(label_if_done_label_623_962);
                          }
                          BIND(label_if_done_label_623_962);
                        }
                        Goto(label_if_done_label_622_961);
                      }
                      BIND(label_if_done_label_622_961);
                    }
                    Goto(label_if_done_label_621_960);
                  }
                  BIND(label_if_done_label_621_960);
                }
              }
              Goto(label_if_done_label_614_953);
            }
            BIND(label_if_done_label_614_953);
          }
          // ../src/builtins/typed-array.tq:334:7
          int31_t t642 = 0;
          TNode<Smi> t643 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t642)));
          TNode<JSTypedArray> t644 = UncheckedCast<JSTypedArray>(CallBuiltin(Builtins::kTypedArrayQuickSort, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSTypedArray>>((*array_609)), implicit_cast<TNode<Smi>>(t643), implicit_cast<TNode<Smi>>((*len_610)), implicit_cast<TNode<JSReceiver>>((*comparefn_613)), implicit_cast<TNode<Code>>((*loadfn_169).value()), implicit_cast<TNode<Code>>((*storefn_170).value())));
          USE(implicit_cast<TNode<JSTypedArray>>(t644));
        }
        Goto(label_try_done_611_951);
      }
      if (label_CastError_194->is_used())
      {
        BIND(label_CastError_194);
        // ../src/builtins/typed-array.tq:336:21
        {
          // ../src/builtins/typed-array.tq:337:7
          Unreachable();
        }
      }
      BIND(label_try_done_611_951);
    }
    // ../src/builtins/typed-array.tq:339:5
    arguments->PopAndReturn(implicit_cast<TNode<JSTypedArray>>((*array_609)));
  }
}

TF_BUILTIN(LoadFixedElement17ATFixedInt32Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2839 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2840 = KindForArrayType17ATFixedInt32Array();
    USE(implicit_cast<ElementsKind>(t2840));
    TNode<Object> t2841 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2839), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2840), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2841));
    Return(implicit_cast<TNode<Object>>(t2841));
  }
}

TF_BUILTIN(StoreFixedElement17ATFixedInt32Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2842 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2843 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2842)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2843));
    TNode<FixedTypedArrayBase> elements_933_impl;
    auto elements_933 = &elements_933_impl;
    USE(elements_933);
    *elements_933 = implicit_cast<TNode<FixedTypedArrayBase>>(t2843);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2844 = KindForArrayType17ATFixedInt32Array();
    USE(implicit_cast<ElementsKind>(t2844));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_933)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2844), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

TF_BUILTIN(LoadFixedElement19ATFixedFloat32Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2845 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2846 = KindForArrayType19ATFixedFloat32Array();
    USE(implicit_cast<ElementsKind>(t2846));
    TNode<Object> t2847 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2845), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2846), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2847));
    Return(implicit_cast<TNode<Object>>(t2847));
  }
}

TF_BUILTIN(StoreFixedElement19ATFixedFloat32Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2848 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2849 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2848)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2849));
    TNode<FixedTypedArrayBase> elements_934_impl;
    auto elements_934 = &elements_934_impl;
    USE(elements_934);
    *elements_934 = implicit_cast<TNode<FixedTypedArrayBase>>(t2849);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2850 = KindForArrayType19ATFixedFloat32Array();
    USE(implicit_cast<ElementsKind>(t2850));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_934)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2850), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

TF_BUILTIN(LoadFixedElement19ATFixedFloat64Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2851 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2852 = KindForArrayType19ATFixedFloat64Array();
    USE(implicit_cast<ElementsKind>(t2852));
    TNode<Object> t2853 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2851), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2852), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2853));
    Return(implicit_cast<TNode<Object>>(t2853));
  }
}

TF_BUILTIN(StoreFixedElement19ATFixedFloat64Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2854 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2855 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2854)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2855));
    TNode<FixedTypedArrayBase> elements_935_impl;
    auto elements_935 = &elements_935_impl;
    USE(elements_935);
    *elements_935 = implicit_cast<TNode<FixedTypedArrayBase>>(t2855);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2856 = KindForArrayType19ATFixedFloat64Array();
    USE(implicit_cast<ElementsKind>(t2856));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_935)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2856), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

TF_BUILTIN(LoadFixedElement24ATFixedUint8ClampedArray, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2857 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2858 = KindForArrayType24ATFixedUint8ClampedArray();
    USE(implicit_cast<ElementsKind>(t2858));
    TNode<Object> t2859 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2857), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2858), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2859));
    Return(implicit_cast<TNode<Object>>(t2859));
  }
}

TF_BUILTIN(StoreFixedElement24ATFixedUint8ClampedArray, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2860 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2861 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2860)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2861));
    TNode<FixedTypedArrayBase> elements_936_impl;
    auto elements_936 = &elements_936_impl;
    USE(elements_936);
    *elements_936 = implicit_cast<TNode<FixedTypedArrayBase>>(t2861);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2862 = KindForArrayType24ATFixedUint8ClampedArray();
    USE(implicit_cast<ElementsKind>(t2862));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_936)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2862), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

TF_BUILTIN(LoadFixedElement21ATFixedBigUint64Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2863 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2864 = KindForArrayType21ATFixedBigUint64Array();
    USE(implicit_cast<ElementsKind>(t2864));
    TNode<Object> t2865 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2863), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2864), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2865));
    Return(implicit_cast<TNode<Object>>(t2865));
  }
}

TF_BUILTIN(StoreFixedElement21ATFixedBigUint64Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2866 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2867 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2866)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2867));
    TNode<FixedTypedArrayBase> elements_937_impl;
    auto elements_937 = &elements_937_impl;
    USE(elements_937);
    *elements_937 = implicit_cast<TNode<FixedTypedArrayBase>>(t2867);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2868 = KindForArrayType21ATFixedBigUint64Array();
    USE(implicit_cast<ElementsKind>(t2868));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_937)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2868), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

TF_BUILTIN(LoadFixedElement20ATFixedBigInt64Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2869 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2870 = KindForArrayType20ATFixedBigInt64Array();
    USE(implicit_cast<ElementsKind>(t2870));
    TNode<Object> t2871 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2869), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2870), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2871));
    Return(implicit_cast<TNode<Object>>(t2871));
  }
}

TF_BUILTIN(StoreFixedElement20ATFixedBigInt64Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2872 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2873 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2872)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2873));
    TNode<FixedTypedArrayBase> elements_938_impl;
    auto elements_938 = &elements_938_impl;
    USE(elements_938);
    *elements_938 = implicit_cast<TNode<FixedTypedArrayBase>>(t2873);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2874 = KindForArrayType20ATFixedBigInt64Array();
    USE(implicit_cast<ElementsKind>(t2874));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_938)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2874), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

TF_BUILTIN(LoadFixedElement17ATFixedUint8Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2875 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2876 = KindForArrayType17ATFixedUint8Array();
    USE(implicit_cast<ElementsKind>(t2876));
    TNode<Object> t2877 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2875), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2876), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2877));
    Return(implicit_cast<TNode<Object>>(t2877));
  }
}

TF_BUILTIN(StoreFixedElement17ATFixedUint8Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2878 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2879 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2878)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2879));
    TNode<FixedTypedArrayBase> elements_939_impl;
    auto elements_939 = &elements_939_impl;
    USE(elements_939);
    *elements_939 = implicit_cast<TNode<FixedTypedArrayBase>>(t2879);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2880 = KindForArrayType17ATFixedUint8Array();
    USE(implicit_cast<ElementsKind>(t2880));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_939)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2880), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

TF_BUILTIN(LoadFixedElement16ATFixedInt8Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2881 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2882 = KindForArrayType16ATFixedInt8Array();
    USE(implicit_cast<ElementsKind>(t2882));
    TNode<Object> t2883 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2881), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2882), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2883));
    Return(implicit_cast<TNode<Object>>(t2883));
  }
}

TF_BUILTIN(StoreFixedElement16ATFixedInt8Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2884 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2885 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2884)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2885));
    TNode<FixedTypedArrayBase> elements_940_impl;
    auto elements_940 = &elements_940_impl;
    USE(elements_940);
    *elements_940 = implicit_cast<TNode<FixedTypedArrayBase>>(t2885);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2886 = KindForArrayType16ATFixedInt8Array();
    USE(implicit_cast<ElementsKind>(t2886));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_940)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2886), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

TF_BUILTIN(LoadFixedElement18ATFixedUint16Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2887 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2888 = KindForArrayType18ATFixedUint16Array();
    USE(implicit_cast<ElementsKind>(t2888));
    TNode<Object> t2889 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2887), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2888), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2889));
    Return(implicit_cast<TNode<Object>>(t2889));
  }
}

TF_BUILTIN(StoreFixedElement18ATFixedUint16Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2890 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2891 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2890)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2891));
    TNode<FixedTypedArrayBase> elements_941_impl;
    auto elements_941 = &elements_941_impl;
    USE(elements_941);
    *elements_941 = implicit_cast<TNode<FixedTypedArrayBase>>(t2891);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2892 = KindForArrayType18ATFixedUint16Array();
    USE(implicit_cast<ElementsKind>(t2892));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_941)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2892), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

TF_BUILTIN(LoadFixedElement17ATFixedInt16Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2893 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2894 = KindForArrayType17ATFixedInt16Array();
    USE(implicit_cast<ElementsKind>(t2894));
    TNode<Object> t2895 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2893), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2894), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2895));
    Return(implicit_cast<TNode<Object>>(t2895));
  }
}

TF_BUILTIN(StoreFixedElement17ATFixedInt16Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2896 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2897 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2896)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2897));
    TNode<FixedTypedArrayBase> elements_942_impl;
    auto elements_942 = &elements_942_impl;
    USE(elements_942);
    *elements_942 = implicit_cast<TNode<FixedTypedArrayBase>>(t2897);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2898 = KindForArrayType17ATFixedInt16Array();
    USE(implicit_cast<ElementsKind>(t2898));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_942)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2898), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

TF_BUILTIN(LoadFixedElement18ATFixedUint32Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../src/builtins/typed-array.tq:55:66
  {
    // ../src/builtins/typed-array.tq:56:5
    TNode<RawPtrT> t2899 = UncheckedCast<RawPtrT>(LoadDataPtr(implicit_cast<TNode<JSTypedArray>>(p_array)));
    ElementsKind t2900 = KindForArrayType18ATFixedUint32Array();
    USE(implicit_cast<ElementsKind>(t2900));
    TNode<Object> t2901 = UncheckedCast<Object>(LoadFixedTypedArrayElementAsTagged(implicit_cast<TNode<RawPtrT>>(t2899), implicit_cast<TNode<Smi>>(p_index), implicit_cast<ElementsKind>(t2900), implicit_cast<ParameterMode>(SMI_PARAMETERS)));
    USE(implicit_cast<TNode<Object>>(t2901));
    Return(implicit_cast<TNode<Object>>(t2901));
  }
}

TF_BUILTIN(StoreFixedElement18ATFixedUint32Array, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../src/builtins/typed-array.tq:62:30
  {
    // ../src/builtins/typed-array.tq:63:5
    TNode<FixedArrayBase> t2902 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedTypedArrayBase> t2903 = UncheckedCast<FixedTypedArrayBase>(unsafe_cast21ATFixedTypedArrayBase(implicit_cast<TNode<Object>>(t2902)));
    USE(implicit_cast<TNode<FixedTypedArrayBase>>(t2903));
    TNode<FixedTypedArrayBase> elements_943_impl;
    auto elements_943 = &elements_943_impl;
    USE(elements_943);
    *elements_943 = implicit_cast<TNode<FixedTypedArrayBase>>(t2903);
    // ../src/builtins/typed-array.tq:65:5
    ElementsKind t2904 = KindForArrayType18ATFixedUint32Array();
    USE(implicit_cast<ElementsKind>(t2904));
    StoreFixedTypedArrayElementFromTagged(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedTypedArrayBase>>((*elements_943)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<ElementsKind>(t2904), implicit_cast<ParameterMode>(SMI_PARAMETERS));
    // ../src/builtins/typed-array.tq:67:5
    Return(implicit_cast<TNode<Object>>(Undefined()));
  }
}

}  // namespace internal
}  // namespace v8

