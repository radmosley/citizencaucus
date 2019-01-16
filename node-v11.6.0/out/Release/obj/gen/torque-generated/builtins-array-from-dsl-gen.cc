#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins.h"
#include "src/code-factory.h"
#include "src/elements-kind.h"
#include "src/heap/factory-inl.h"
#include "src/objects.h"
#include "src/objects/bigint.h"
#include "builtins-array-from-dsl-gen.h"

namespace v8 {
namespace internal {

using Node = compiler::Node;

compiler::TNode<Number> ArrayBuiltinsFromDSLAssembler::GetLengthProperty(TNode<Context> p_context, TNode<Object> p_o) {
  TVARIABLE(Number, _return_71_impl);
  auto _return_71 = &_return_71_impl;
  USE(_return_71);
  Label label_macro_end_856_impl(this, {_return_71});
  Label* label_macro_end_856 = &label_macro_end_856_impl;
  USE(label_macro_end_856);
  // ../src/builtins/array.tq:17:64
  {
    // ../src/builtins/array.tq:18:5
    {
      Label label__True_23_impl(this);
      Label* label__True_23 = &label__True_23_impl;
      USE(label__True_23);
      Label label__False_24_impl(this);
      Label* label__False_24 = &label__False_24_impl;
      USE(label__False_24);
      Label label_if_done_label_483_857_impl(this, {});
      Label* label_if_done_label_483_857 = &label_if_done_label_483_857_impl;
      USE(label_if_done_label_483_857);
      BranchIfFastJSArray(implicit_cast<TNode<Object>>(p_o), implicit_cast<TNode<Context>>(p_context), label__True_23, label__False_24);
      if (label__True_23->is_used())
      {
        BIND(label__True_23);
        // ../src/builtins/array.tq:18:42
        {
          // ../src/builtins/array.tq:19:7
          TNode<JSArray> t94 = UncheckedCast<JSArray>(unsafe_cast9ATJSArray(implicit_cast<TNode<Object>>(p_o)));
          USE(implicit_cast<TNode<JSArray>>(t94));
          TVARIABLE(JSArray, a_72_impl);
          auto a_72 = &a_72_impl;
          USE(a_72);
          *a_72 = implicit_cast<TNode<JSArray>>(t94);
          // ../src/builtins/array.tq:20:7
          TNode<Smi> t95 = UncheckedCast<Smi>(LoadFastJSArrayLength(implicit_cast<TNode<JSArray>>((*a_72).value())));
          *_return_71 = implicit_cast<TNode<Number>>(t95);
          Goto(label_macro_end_856);
        }
      }
      if (label__False_24->is_used())
      {
        BIND(label__False_24);
        // ../src/builtins/array.tq:22:7
        {
          // ../src/builtins/array.tq:23:9
          const char* t96 = "length";
          TNode<Object> t97 = UncheckedCast<Object>(from_constexpr22UT12ATHeapObject5ATSmi(implicit_cast<const char*>(t96)));
          TNode<Object> t98 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_o), implicit_cast<TNode<Object>>(t97)));
          USE(implicit_cast<TNode<Object>>(t98));
          TNode<Number> t99 = UncheckedCast<Number>(ToLength_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t98)));
          USE(implicit_cast<TNode<Number>>(t99));
          *_return_71 = implicit_cast<TNode<Number>>(t99);
          Goto(label_macro_end_856);
        }
      }
    }
  }
  BIND(label_macro_end_856);
  return implicit_cast<TNode<Number>>((*_return_71).value());
}

compiler::TNode<Object> ArrayBuiltinsFromDSLAssembler::FastArraySplice(TNode<Context> p_context, CodeStubArguments* p_args, TNode<Object> p_o, TNode<Number> p_originalLengthNumber, TNode<Number> p_actualStartNumber, TNode<Smi> p_insertCount, TNode<Number> p_actualDeleteCountNumber, Label* label_Bailout_25) {
  TVARIABLE(Object, _return_73_impl);
  auto _return_73 = &_return_73_impl;
  USE(_return_73);
  Label label_macro_end_858_impl(this, {_return_73});
  Label* label_macro_end_858 = &label_macro_end_858_impl;
  USE(label_macro_end_858);
  // ../src/builtins/array.tq:31:18
  {
    // ../src/builtins/array.tq:32:5
    TNode<Smi> t100 = UncheckedCast<Smi>(cast5ATSmi(implicit_cast<TNode<Object>>(p_originalLengthNumber), label_Bailout_25));
    USE(implicit_cast<TNode<Smi>>(t100));
    TVARIABLE(Smi, originalLength_74_impl);
    auto originalLength_74 = &originalLength_74_impl;
    USE(originalLength_74);
    *originalLength_74 = implicit_cast<TNode<Smi>>(t100);
    // ../src/builtins/array.tq:33:5
    TNode<Smi> t101 = UncheckedCast<Smi>(cast5ATSmi(implicit_cast<TNode<Object>>(p_actualStartNumber), label_Bailout_25));
    USE(implicit_cast<TNode<Smi>>(t101));
    TVARIABLE(Smi, actualStart_75_impl);
    auto actualStart_75 = &actualStart_75_impl;
    USE(actualStart_75);
    *actualStart_75 = implicit_cast<TNode<Smi>>(t101);
    // ../src/builtins/array.tq:34:5
    TNode<Smi> t102 = UncheckedCast<Smi>(cast5ATSmi(implicit_cast<TNode<Object>>(p_actualDeleteCountNumber), label_Bailout_25));
    USE(implicit_cast<TNode<Smi>>(t102));
    TVARIABLE(Smi, actualDeleteCount_76_impl);
    auto actualDeleteCount_76 = &actualDeleteCount_76_impl;
    USE(actualDeleteCount_76);
    *actualDeleteCount_76 = implicit_cast<TNode<Smi>>(t102);
    // ../src/builtins/array.tq:36:5
    TNode<Smi> t103 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_insertCount), implicit_cast<TNode<Smi>>((*actualDeleteCount_76).value())));
    USE(implicit_cast<TNode<Smi>>(t103));
    TVARIABLE(Smi, lengthDelta_77_impl);
    auto lengthDelta_77 = &lengthDelta_77_impl;
    USE(lengthDelta_77);
    *lengthDelta_77 = implicit_cast<TNode<Smi>>(t103);
    // ../src/builtins/array.tq:37:5
    TNode<Smi> t104 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*originalLength_74).value()), implicit_cast<TNode<Smi>>((*lengthDelta_77).value())));
    USE(implicit_cast<TNode<Smi>>(t104));
    TVARIABLE(Smi, newLength_78_impl);
    auto newLength_78 = &newLength_78_impl;
    USE(newLength_78);
    *newLength_78 = implicit_cast<TNode<Smi>>(t104);
    // ../src/builtins/array.tq:39:5
    TNode<JSArray> t105 = UncheckedCast<JSArray>(cast9ATJSArray(implicit_cast<TNode<Object>>(p_o), label_Bailout_25));
    USE(implicit_cast<TNode<JSArray>>(t105));
    TVARIABLE(JSArray, a_79_impl);
    auto a_79 = &a_79_impl;
    USE(a_79);
    *a_79 = implicit_cast<TNode<JSArray>>(t105);
    // ../src/builtins/array.tq:41:5
    TNode<Map> t106 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>((*a_79).value())));
    TVARIABLE(Map, map_80_impl);
    auto map_80 = &map_80_impl;
    USE(map_80);
    *map_80 = implicit_cast<TNode<Map>>(t106);
    // ../src/builtins/array.tq:42:5
    {
      Label label__True_26_impl(this);
      Label* label__True_26 = &label__True_26_impl;
      USE(label__True_26);
      Label label__False_27_impl(this, {});
      Label* label__False_27 = &label__False_27_impl;
      USE(label__False_27);
      TNode<BoolT> t107 = UncheckedCast<BoolT>(IsPrototypeInitialArrayPrototype(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Map>>((*map_80).value())));
      USE(implicit_cast<TNode<BoolT>>(t107));
      TNode<BoolT> t108 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t107)));
      USE(implicit_cast<TNode<BoolT>>(t108));
      Branch(implicit_cast<TNode<BoolT>>(t108), label__True_26, label__False_27);
      if (label__True_26->is_used())
      {
        BIND(label__True_26);
        // ../src/builtins/array.tq:42:58
        Goto(label_Bailout_25);
      }
      BIND(label__False_27);
    }
    // ../src/builtins/array.tq:43:5
    {
      Label label__True_28_impl(this);
      Label* label__True_28 = &label__True_28_impl;
      USE(label__True_28);
      Label label__False_29_impl(this, {});
      Label* label__False_29 = &label__False_29_impl;
      USE(label__False_29);
      TNode<BoolT> t109 = UncheckedCast<BoolT>(IsNoElementsProtectorCellInvalid());
      USE(implicit_cast<TNode<BoolT>>(t109));
      Branch(implicit_cast<TNode<BoolT>>(t109), label__True_28, label__False_29);
      if (label__True_28->is_used())
      {
        BIND(label__True_28);
        // ../src/builtins/array.tq:43:45
        Goto(label_Bailout_25);
      }
      BIND(label__False_29);
    }
    // ../src/builtins/array.tq:44:5
    {
      Label label__True_30_impl(this);
      Label* label__True_30 = &label__True_30_impl;
      USE(label__True_30);
      Label label__False_31_impl(this, {});
      Label* label__False_31 = &label__False_31_impl;
      USE(label__False_31);
      TNode<BoolT> t110 = UncheckedCast<BoolT>(IsArraySpeciesProtectorCellInvalid());
      USE(implicit_cast<TNode<BoolT>>(t110));
      Branch(implicit_cast<TNode<BoolT>>(t110), label__True_30, label__False_31);
      if (label__True_30->is_used())
      {
        BIND(label__True_30);
        // ../src/builtins/array.tq:44:47
        Goto(label_Bailout_25);
      }
      BIND(label__False_31);
    }
    // ../src/builtins/array.tq:47:5
    TNode<Int32T> t111 = UncheckedCast<Int32T>(EnsureArrayPushable(implicit_cast<TNode<Map>>((*map_80).value()), label_Bailout_25));
    USE(implicit_cast<TNode<Int32T>>(t111));
    TVARIABLE(Int32T, elementsKind_81_impl);
    auto elementsKind_81 = &elementsKind_81_impl;
    USE(elementsKind_81);
    *elementsKind_81 = implicit_cast<TNode<Int32T>>(t111);
    // ../src/builtins/array.tq:48:5
    {
      Label label__True_32_impl(this);
      Label* label__True_32 = &label__True_32_impl;
      USE(label__True_32);
      Label label__False_33_impl(this, {});
      Label* label__False_33 = &label__False_33_impl;
      USE(label__False_33);
      TNode<BoolT> t112 = UncheckedCast<BoolT>(IsFastElementsKind(implicit_cast<TNode<Int32T>>((*elementsKind_81).value())));
      USE(implicit_cast<TNode<BoolT>>(t112));
      TNode<BoolT> t113 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t112)));
      USE(implicit_cast<TNode<BoolT>>(t113));
      Branch(implicit_cast<TNode<BoolT>>(t113), label__True_32, label__False_33);
      if (label__True_32->is_used())
      {
        BIND(label__True_32);
        // ../src/builtins/array.tq:48:44
        Goto(label_Bailout_25);
      }
      BIND(label__False_33);
    }
    // ../src/builtins/array.tq:51:5
    {
      Label label__True_34_impl(this);
      Label* label__True_34 = &label__True_34_impl;
      USE(label__True_34);
      Label label__False_35_impl(this, {});
      Label* label__False_35 = &label__False_35_impl;
      USE(label__False_35);
      TNode<BoolT> t114 = UncheckedCast<BoolT>(IsFastSmiOrTaggedElementsKind(implicit_cast<TNode<Int32T>>((*elementsKind_81).value())));
      USE(implicit_cast<TNode<BoolT>>(t114));
      TNode<BoolT> t115 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t114)));
      USE(implicit_cast<TNode<BoolT>>(t115));
      Branch(implicit_cast<TNode<BoolT>>(t115), label__True_34, label__False_35);
      if (label__True_34->is_used())
      {
        BIND(label__True_34);
        // ../src/builtins/array.tq:51:55
        Goto(label_Bailout_25);
      }
      BIND(label__False_35);
    }
    // ../src/builtins/array.tq:53:5
    {
      Label label__True_36_impl(this);
      Label* label__True_36 = &label__True_36_impl;
      USE(label__True_36);
      Label label__False_37_impl(this, {});
      Label* label__False_37 = &label__False_37_impl;
      USE(label__False_37);
      TNode<BoolT> t116 = UncheckedCast<BoolT>(IsFastSmiElementsKind(implicit_cast<TNode<Int32T>>((*elementsKind_81).value())));
      USE(implicit_cast<TNode<BoolT>>(t116));
      Branch(implicit_cast<TNode<BoolT>>(t116), label__True_36, label__False_37);
      if (label__True_36->is_used())
      {
        BIND(label__True_36);
        // ../src/builtins/array.tq:53:46
        {
          // ../src/builtins/array.tq:54:7
          int31_t t117 = 2;
          TNode<IntPtrT> t118 = UncheckedCast<IntPtrT>(GetArgumentsLength(implicit_cast<CodeStubArguments*>(p_args)));
          Label label_body_484_859_impl(this);
          Label* label_body_484_859 = &label_body_484_859_impl;
          USE(label_body_484_859);
          Label label_increment_485_860_impl(this);
          Label* label_increment_485_860 = &label_increment_485_860_impl;
          USE(label_increment_485_860);
          Label label_exit_486_861_impl(this);
          Label* label_exit_486_861 = &label_exit_486_861_impl;
          USE(label_exit_486_861);
          TVARIABLE(IntPtrT, _for_index_t119_487_impl);
          auto _for_index_t119_487 = &_for_index_t119_487_impl;
          USE(_for_index_t119_487);
          TNode<IntPtrT> t120 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t117)));
          *_for_index_t119_487 = implicit_cast<TNode<IntPtrT>>(t120);
          Label label_header_488_862_impl(this, {_for_index_t119_487});
          Label* label_header_488_862 = &label_header_488_862_impl;
          USE(label_header_488_862);
          Goto(label_header_488_862);
          BIND(label_header_488_862);
          TNode<BoolT> t121 = UncheckedCast<BoolT>(IntPtrLessThan(implicit_cast<TNode<IntPtrT>>((*_for_index_t119_487).value()), implicit_cast<TNode<IntPtrT>>(t118)));
          Branch(implicit_cast<TNode<BoolT>>(t121), label_body_484_859, label_exit_486_861);
          BIND(label_body_484_859);
          TNode<Object> t122 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(p_args), implicit_cast<TNode<IntPtrT>>((*_for_index_t119_487).value())));
          TVARIABLE(Object, e_82_impl);
          auto e_82 = &e_82_impl;
          USE(e_82);
          *e_82 = implicit_cast<TNode<Object>>(t122);
          // ../src/builtins/array.tq:54:41
          {
            // ../src/builtins/array.tq:55:9
            {
              Label label__True_38_impl(this);
              Label* label__True_38 = &label__True_38_impl;
              USE(label__True_38);
              Label label__False_39_impl(this, {});
              Label* label__False_39 = &label__False_39_impl;
              USE(label__False_39);
              TNode<BoolT> t123 = UncheckedCast<BoolT>(TaggedIsNotSmi(implicit_cast<TNode<Object>>((*e_82).value())));
              USE(implicit_cast<TNode<BoolT>>(t123));
              Branch(implicit_cast<TNode<BoolT>>(t123), label__True_38, label__False_39);
              if (label__True_38->is_used())
              {
                BIND(label__True_38);
                // ../src/builtins/array.tq:55:32
                Goto(label_Bailout_25);
              }
              BIND(label__False_39);
            }
          }
          Goto(label_increment_485_860);
          BIND(label_increment_485_860);
          TNode<IntPtrT> t124 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(1)));
          TNode<IntPtrT> t125 = UncheckedCast<IntPtrT>(IntPtrAdd(implicit_cast<TNode<IntPtrT>>((*_for_index_t119_487).value()), implicit_cast<TNode<IntPtrT>>(t124)));
          *_for_index_t119_487 = implicit_cast<TNode<IntPtrT>>(t125);
          Goto(label_header_488_862);
          BIND(label_exit_486_861);
        }
        Goto(label__False_37);
      }
      BIND(label__False_37);
    }
    // ../src/builtins/array.tq:60:5
    TNode<Number> t126 = UncheckedCast<Number>(LoadJSArrayLength(implicit_cast<TNode<JSArray>>((*a_79).value())));
    TNode<Smi> t127 = UncheckedCast<Smi>(cast5ATSmi(implicit_cast<TNode<Object>>(t126), label_Bailout_25));
    USE(implicit_cast<TNode<Smi>>(t127));
    TVARIABLE(Smi, length_83_impl);
    auto length_83 = &length_83_impl;
    USE(length_83);
    *length_83 = implicit_cast<TNode<Smi>>(t127);
    // ../src/builtins/array.tq:61:5
    {
      Label label__True_40_impl(this);
      Label* label__True_40 = &label__True_40_impl;
      USE(label__True_40);
      Label label__False_41_impl(this, {});
      Label* label__False_41 = &label__False_41_impl;
      USE(label__False_41);
      TNode<BoolT> t128 = UncheckedCast<BoolT>(SmiNotEqual(implicit_cast<TNode<Smi>>((*originalLength_74).value()), implicit_cast<TNode<Smi>>((*length_83).value())));
      USE(implicit_cast<TNode<BoolT>>(t128));
      Branch(implicit_cast<TNode<BoolT>>(t128), label__True_40, label__False_41);
      if (label__True_40->is_used())
      {
        BIND(label__True_40);
        // ../src/builtins/array.tq:61:35
        Goto(label_Bailout_25);
      }
      BIND(label__False_41);
    }
    // ../src/builtins/array.tq:63:5
    TNode<JSArray> t129 = UncheckedCast<JSArray>(CallBuiltin(Builtins::kExtractFastJSArray, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSArray>>((*a_79).value()), implicit_cast<TNode<Smi>>((*actualStart_75).value()), implicit_cast<TNode<Smi>>((*actualDeleteCount_76).value())));
    USE(implicit_cast<TNode<JSArray>>(t129));
    TVARIABLE(JSArray, deletedResult_84_impl);
    auto deletedResult_84 = &deletedResult_84_impl;
    USE(deletedResult_84);
    *deletedResult_84 = implicit_cast<TNode<JSArray>>(t129);
    // ../src/builtins/array.tq:66:5
    {
      Label label__True_42_impl(this);
      Label* label__True_42 = &label__True_42_impl;
      USE(label__True_42);
      Label label__False_43_impl(this, {});
      Label* label__False_43 = &label__False_43_impl;
      USE(label__False_43);
      int31_t t130 = 0;
      TNode<Smi> t131 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t130)));
      TNode<BoolT> t132 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*newLength_78).value()), implicit_cast<TNode<Smi>>(t131)));
      USE(implicit_cast<TNode<BoolT>>(t132));
      Branch(implicit_cast<TNode<BoolT>>(t132), label__True_42, label__False_43);
      if (label__True_42->is_used())
      {
        BIND(label__True_42);
        // ../src/builtins/array.tq:66:25
        {
          // ../src/builtins/array.tq:67:7
          StoreElements(implicit_cast<TNode<JSObject>>((*a_79).value()), implicit_cast<TNode<FixedArrayBase>>(kEmptyFixedArray()));
          // ../src/builtins/array.tq:68:7
          int31_t t133 = 0;
          TNode<Smi> t134 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t133)));
          StoreJSArrayLength(implicit_cast<TNode<JSArray>>((*a_79).value()), implicit_cast<TNode<Smi>>(t134));
          // ../src/builtins/array.tq:69:7
          *_return_73 = implicit_cast<TNode<Object>>((*deletedResult_84).value());
          Goto(label_macro_end_858);
        }
      }
      BIND(label__False_43);
    }
    // ../src/builtins/array.tq:72:5
    TNode<FixedArrayBase> t135 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>((*a_79).value())));
    TNode<FixedArray> t136 = UncheckedCast<FixedArray>(cast12ATFixedArray(implicit_cast<TNode<HeapObject>>(t135), label_Bailout_25));
    USE(implicit_cast<TNode<FixedArray>>(t136));
    TVARIABLE(FixedArray, elements_85_impl);
    auto elements_85 = &elements_85_impl;
    USE(elements_85);
    *elements_85 = implicit_cast<TNode<FixedArray>>(t136);
    // ../src/builtins/array.tq:73:5
    TNode<Map> t137 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>((*elements_85).value())));
    TVARIABLE(Map, elementsMap_86_impl);
    auto elementsMap_86 = &elementsMap_86_impl;
    USE(elementsMap_86);
    *elementsMap_86 = implicit_cast<TNode<Map>>(t137);
    // ../src/builtins/array.tq:77:5
    TVARIABLE(FixedArray, newElements_87_impl);
    auto newElements_87 = &newElements_87_impl;
    USE(newElements_87);
    *newElements_87 = implicit_cast<TNode<FixedArray>>((*elements_85).value());
    // ../src/builtins/array.tq:78:5
    {
      Label label__True_44_impl(this);
      Label* label__True_44 = &label__True_44_impl;
      USE(label__True_44);
      Label label__False_45_impl(this, {newElements_87});
      Label* label__False_45 = &label__False_45_impl;
      USE(label__False_45);
      Label label__False_46_impl(this);
      Label* label__False_46 = &label__False_46_impl;
      USE(label__False_46);
      TNode<BoolT> t138 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*elementsMap_86).value()), implicit_cast<TNode<Object>>(kCOWMap())));
      USE(implicit_cast<TNode<BoolT>>(t138));
      GotoIf(implicit_cast<TNode<BoolT>>(t138), label__True_44);
      int31_t t139 = 0;
      TNode<Smi> t140 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t139)));
      TNode<BoolT> t141 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*lengthDelta_77).value()), implicit_cast<TNode<Smi>>(t140)));
      USE(implicit_cast<TNode<BoolT>>(t141));
      Branch(implicit_cast<TNode<BoolT>>(t141), label__True_44, label__False_45);
      if (label__True_44->is_used())
      {
        BIND(label__True_44);
        // ../src/builtins/array.tq:78:56
        {
          // ../src/builtins/array.tq:79:7
          int31_t t142 = 0;
          TNode<Smi> t143 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t142)));
          TNode<FixedArray> t144 = UncheckedCast<FixedArray>(ExtractFixedArray(implicit_cast<TNode<FixedArray>>((*elements_85).value()), implicit_cast<TNode<Smi>>(t143), implicit_cast<TNode<Smi>>((*actualStart_75).value()), implicit_cast<TNode<Smi>>((*newLength_78).value()), implicit_cast<ExtractFixedArrayFlags>(ExtractFixedArrayFlag::kAllFixedArrays)));
          USE(implicit_cast<TNode<FixedArray>>(t144));
          *newElements_87 = implicit_cast<TNode<FixedArray>>(t144);
          // ../src/builtins/array.tq:81:7
          StoreMap(implicit_cast<TNode<HeapObject>>((*newElements_87).value()), implicit_cast<TNode<Map>>((*elementsMap_86).value()));
          // ../src/builtins/array.tq:82:7
          StoreElements(implicit_cast<TNode<JSObject>>((*a_79).value()), implicit_cast<TNode<FixedArrayBase>>((*newElements_87).value()));
        }
        Goto(label__False_45);
      }
      BIND(label__False_45);
    }
    // ../src/builtins/array.tq:86:5
    // ../src/builtins/array.tq:89:5
    TVARIABLE(Smi, k_88_impl);
    auto k_88 = &k_88_impl;
    USE(k_88);
    *k_88 = implicit_cast<TNode<Smi>>((*actualStart_75).value());
    // ../src/builtins/array.tq:90:5
    {
      Label label__True_47_impl(this);
      Label* label__True_47 = &label__True_47_impl;
      USE(label__True_47);
      Label label__False_48_impl(this, {k_88});
      Label* label__False_48 = &label__False_48_impl;
      USE(label__False_48);
      int31_t t145 = 0;
      TNode<Smi> t146 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t145)));
      TNode<BoolT> t147 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>(p_insertCount), implicit_cast<TNode<Smi>>(t146)));
      USE(implicit_cast<TNode<BoolT>>(t147));
      Branch(implicit_cast<TNode<BoolT>>(t147), label__True_47, label__False_48);
      if (label__True_47->is_used())
      {
        BIND(label__True_47);
        // ../src/builtins/array.tq:90:26
        {
          // ../src/builtins/array.tq:91:7
          int31_t t148 = 2;
          TNode<IntPtrT> t149 = UncheckedCast<IntPtrT>(GetArgumentsLength(implicit_cast<CodeStubArguments*>(p_args)));
          Label label_body_489_863_impl(this);
          Label* label_body_489_863 = &label_body_489_863_impl;
          USE(label_body_489_863);
          Label label_increment_490_864_impl(this);
          Label* label_increment_490_864 = &label_increment_490_864_impl;
          USE(label_increment_490_864);
          Label label_exit_491_865_impl(this);
          Label* label_exit_491_865 = &label_exit_491_865_impl;
          USE(label_exit_491_865);
          TVARIABLE(IntPtrT, _for_index_t150_492_impl);
          auto _for_index_t150_492 = &_for_index_t150_492_impl;
          USE(_for_index_t150_492);
          TNode<IntPtrT> t151 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t148)));
          *_for_index_t150_492 = implicit_cast<TNode<IntPtrT>>(t151);
          Label label_header_493_866_impl(this, {_for_index_t150_492, k_88});
          Label* label_header_493_866 = &label_header_493_866_impl;
          USE(label_header_493_866);
          Goto(label_header_493_866);
          BIND(label_header_493_866);
          TNode<BoolT> t152 = UncheckedCast<BoolT>(IntPtrLessThan(implicit_cast<TNode<IntPtrT>>((*_for_index_t150_492).value()), implicit_cast<TNode<IntPtrT>>(t149)));
          Branch(implicit_cast<TNode<BoolT>>(t152), label_body_489_863, label_exit_491_865);
          BIND(label_body_489_863);
          TNode<Object> t153 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(p_args), implicit_cast<TNode<IntPtrT>>((*_for_index_t150_492).value())));
          TVARIABLE(Object, e_89_impl);
          auto e_89 = &e_89_impl;
          USE(e_89);
          *e_89 = implicit_cast<TNode<Object>>(t153);
          // ../src/builtins/array.tq:91:41
          {
            // ../src/builtins/array.tq:92:9
            TNode<Smi> t154 = implicit_cast<TNode<Smi>>((*k_88).value());
            USE(t154);
            TNode<Smi> t155 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
            TNode<Smi> t156 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*k_88).value()), implicit_cast<TNode<Smi>>(t155)));
            *k_88 = implicit_cast<TNode<Smi>>(t156);
            StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>((*newElements_87).value()), implicit_cast<TNode<Smi>>(t154), implicit_cast<TNode<Object>>((*e_89).value()));
          }
          Goto(label_increment_490_864);
          BIND(label_increment_490_864);
          TNode<IntPtrT> t157 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(1)));
          TNode<IntPtrT> t158 = UncheckedCast<IntPtrT>(IntPtrAdd(implicit_cast<TNode<IntPtrT>>((*_for_index_t150_492).value()), implicit_cast<TNode<IntPtrT>>(t157)));
          *_for_index_t150_492 = implicit_cast<TNode<IntPtrT>>(t158);
          Goto(label_header_493_866);
          BIND(label_exit_491_865);
        }
        Goto(label__False_48);
      }
      BIND(label__False_48);
    }
    // ../src/builtins/array.tq:97:5
    TNode<Smi> t159 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_83).value()), implicit_cast<TNode<Smi>>((*actualStart_75).value())));
    USE(implicit_cast<TNode<Smi>>(t159));
    TNode<Smi> t160 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t159), implicit_cast<TNode<Smi>>((*actualDeleteCount_76).value())));
    USE(implicit_cast<TNode<Smi>>(t160));
    TVARIABLE(Smi, count_90_impl);
    auto count_90 = &count_90_impl;
    USE(count_90);
    *count_90 = implicit_cast<TNode<Smi>>(t160);
    // ../src/builtins/array.tq:98:5
    {
      Label label__True_49_impl(this);
      Label* label__True_49 = &label__True_49_impl;
      USE(label__True_49);
      Label label__False_50_impl(this);
      Label* label__False_50 = &label__False_50_impl;
      USE(label__False_50);
      Label label_header_494_867_impl(this, {count_90, k_88});
      Label* label_header_494_867 = &label_header_494_867_impl;
      USE(label_header_494_867);
      Goto(label_header_494_867);
      BIND(label_header_494_867);
      int31_t t161 = 0;
      TNode<Smi> t162 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t161)));
      TNode<BoolT> t163 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*count_90).value()), implicit_cast<TNode<Smi>>(t162)));
      USE(implicit_cast<TNode<BoolT>>(t163));
      Branch(implicit_cast<TNode<BoolT>>(t163), label__True_49, label__False_50);
      if (label__True_49->is_used())
      {
        BIND(label__True_49);
        // ../src/builtins/array.tq:98:23
        {
          // ../src/builtins/array.tq:99:7
          TNode<Smi> t164 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*k_88).value()), implicit_cast<TNode<Smi>>((*lengthDelta_77).value())));
          USE(implicit_cast<TNode<Smi>>(t164));
          TNode<Object> t165 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*elements_85).value()), implicit_cast<TNode<Smi>>(t164)));
          TVARIABLE(Object, e_91_impl);
          auto e_91 = &e_91_impl;
          USE(e_91);
          *e_91 = implicit_cast<TNode<Object>>(t165);
          // ../src/builtins/array.tq:100:7
          TNode<Smi> t166 = implicit_cast<TNode<Smi>>((*k_88).value());
          USE(t166);
          TNode<Smi> t167 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t168 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*k_88).value()), implicit_cast<TNode<Smi>>(t167)));
          *k_88 = implicit_cast<TNode<Smi>>(t168);
          StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>((*newElements_87).value()), implicit_cast<TNode<Smi>>(t166), implicit_cast<TNode<Object>>((*e_91).value()));
          // ../src/builtins/array.tq:101:7
          TNode<Smi> t169 = implicit_cast<TNode<Smi>>((*count_90).value());
          USE(t169);
          TNode<Smi> t170 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t171 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*count_90).value()), implicit_cast<TNode<Smi>>(t170)));
          *count_90 = implicit_cast<TNode<Smi>>(t171);
        }
        Goto(label_header_494_867);
      }
      BIND(label__False_50);
    }
    // ../src/builtins/array.tq:107:5
    {
      Label label__True_51_impl(this);
      Label* label__True_51 = &label__True_51_impl;
      USE(label__True_51);
      Label label__False_52_impl(this, {k_88});
      Label* label__False_52 = &label__False_52_impl;
      USE(label__False_52);
      TNode<BoolT> t172 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*elements_85).value()), implicit_cast<TNode<Object>>((*newElements_87).value())));
      USE(implicit_cast<TNode<BoolT>>(t172));
      Branch(implicit_cast<TNode<BoolT>>(t172), label__True_51, label__False_52);
      if (label__True_51->is_used())
      {
        BIND(label__True_51);
        // ../src/builtins/array.tq:107:34
        {
          // ../src/builtins/array.tq:108:7
          TNode<Smi> t173 = UncheckedCast<Smi>(LoadFixedArrayBaseLength(implicit_cast<TNode<FixedArrayBase>>((*elements_85).value())));
          TVARIABLE(Smi, limit_92_impl);
          auto limit_92 = &limit_92_impl;
          USE(limit_92);
          *limit_92 = implicit_cast<TNode<Smi>>(t173);
          // ../src/builtins/array.tq:109:7
          {
            Label label__True_53_impl(this);
            Label* label__True_53 = &label__True_53_impl;
            USE(label__True_53);
            Label label__False_54_impl(this);
            Label* label__False_54 = &label__False_54_impl;
            USE(label__False_54);
            Label label_header_495_868_impl(this, {k_88});
            Label* label_header_495_868 = &label_header_495_868_impl;
            USE(label_header_495_868);
            Goto(label_header_495_868);
            BIND(label_header_495_868);
            TNode<BoolT> t174 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*k_88).value()), implicit_cast<TNode<Smi>>((*limit_92).value())));
            USE(implicit_cast<TNode<BoolT>>(t174));
            Branch(implicit_cast<TNode<BoolT>>(t174), label__True_53, label__False_54);
            if (label__True_53->is_used())
            {
              BIND(label__True_53);
              // ../src/builtins/array.tq:109:25
              {
                // ../src/builtins/array.tq:110:9
                TNode<Smi> t175 = implicit_cast<TNode<Smi>>((*k_88).value());
                USE(t175);
                TNode<Smi> t176 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                TNode<Smi> t177 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*k_88).value()), implicit_cast<TNode<Smi>>(t176)));
                *k_88 = implicit_cast<TNode<Smi>>(t177);
                StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>((*newElements_87).value()), implicit_cast<TNode<Smi>>(t175), implicit_cast<TNode<Object>>(Hole()));
              }
              Goto(label_header_495_868);
            }
            BIND(label__False_54);
          }
        }
        Goto(label__False_52);
      }
      BIND(label__False_52);
    }
    // ../src/builtins/array.tq:115:5
    StoreJSArrayLength(implicit_cast<TNode<JSArray>>((*a_79).value()), implicit_cast<TNode<Smi>>((*newLength_78).value()));
    // ../src/builtins/array.tq:117:5
    *_return_73 = implicit_cast<TNode<Object>>((*deletedResult_84).value());
    Goto(label_macro_end_858);
  }
  BIND(label_macro_end_858);
  return implicit_cast<TNode<Object>>((*_return_73).value());
}

TF_BUILTIN(ArraySpliceTorque, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  CodeStubArguments arguments_impl(this, ChangeInt32ToIntPtr(argc));
  TNode<Object> p_receiver = arguments_impl.GetReceiver();
  auto arguments = &arguments_impl;
  USE(arguments);
  USE(p_receiver);
  // ../src/builtins/array.tq:122:65
  {
    // ../src/builtins/array.tq:124:5
    TNode<JSReceiver> t178 = UncheckedCast<JSReceiver>(CallBuiltin(Builtins::kToObject, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_receiver)));
    USE(implicit_cast<TNode<JSReceiver>>(t178));
    TVARIABLE(JSReceiver, o_93_impl);
    auto o_93 = &o_93_impl;
    USE(o_93);
    *o_93 = implicit_cast<TNode<JSReceiver>>(t178);
    // ../src/builtins/array.tq:127:5
    TNode<Number> t179 = UncheckedCast<Number>(GetLengthProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value())));
    USE(implicit_cast<TNode<Number>>(t179));
    TVARIABLE(Number, len_94_impl);
    auto len_94 = &len_94_impl;
    USE(len_94);
    *len_94 = implicit_cast<TNode<Number>>(t179);
    // ../src/builtins/array.tq:130:5
    int31_t t180 = 0;
    TNode<IntPtrT> t181 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t180)));
    TNode<Object> t182 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t181)));
    TVARIABLE(Object, start_95_impl);
    auto start_95 = &start_95_impl;
    USE(start_95);
    *start_95 = implicit_cast<TNode<Object>>(t182);
    // ../src/builtins/array.tq:131:5
    TNode<Number> t183 = UncheckedCast<Number>(ToInteger_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*start_95).value())));
    USE(implicit_cast<TNode<Number>>(t183));
    TVARIABLE(Number, relativeStart_96_impl);
    auto relativeStart_96 = &relativeStart_96_impl;
    USE(relativeStart_96);
    *relativeStart_96 = implicit_cast<TNode<Number>>(t183);
    // ../src/builtins/array.tq:136:5
    auto t184 = [=]() {
      TNode<Number> t186 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*len_94).value()), implicit_cast<TNode<Number>>((*relativeStart_96).value())));
      USE(implicit_cast<TNode<Number>>(t186));
      int31_t t187 = 0;
      TNode<Number> t188 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t187)));
      TNode<Number> t189 = UncheckedCast<Number>(max(implicit_cast<TNode<Number>>(t186), implicit_cast<TNode<Number>>(t188)));
      USE(implicit_cast<TNode<Number>>(t189));
      return implicit_cast<TNode<Number>>(t189);
    };
    auto t185 = [=]() {
      TNode<Number> t190 = UncheckedCast<Number>(min(implicit_cast<TNode<Number>>((*relativeStart_96).value()), implicit_cast<TNode<Number>>((*len_94).value())));
      USE(implicit_cast<TNode<Number>>(t190));
      return implicit_cast<TNode<Number>>(t190);
    };
    TVARIABLE(Number, t191_496_impl);
    auto t191_496 = &t191_496_impl;
    USE(t191_496);
    {
      Label label__True_55_impl(this);
      Label* label__True_55 = &label__True_55_impl;
      USE(label__True_55);
      Label label__False_56_impl(this);
      Label* label__False_56 = &label__False_56_impl;
      USE(label__False_56);
      Label label__done_497_869_impl(this, {t191_496});
      Label* label__done_497_869 = &label__done_497_869_impl;
      USE(label__done_497_869);
      int31_t t192 = 0;
      TNode<Number> t193 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t192)));
      BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*relativeStart_96).value()), implicit_cast<TNode<Number>>(t193), label__True_55, label__False_56);
      BIND(label__True_55);
            *t191_496 = implicit_cast<TNode<Number>>(t184());
      Goto(label__done_497_869);
      BIND(label__False_56);
            *t191_496 = implicit_cast<TNode<Number>>(t185());
      Goto(label__done_497_869);
      BIND(label__done_497_869);
    }
    TVARIABLE(Number, actualStart_97_impl);
    auto actualStart_97 = &actualStart_97_impl;
    USE(actualStart_97);
    *actualStart_97 = implicit_cast<TNode<Number>>((*t191_496).value());
    // ../src/builtins/array.tq:140:5
    TVARIABLE(Smi, insertCount_98_impl);
    auto insertCount_98 = &insertCount_98_impl;
    USE(insertCount_98);
    // ../src/builtins/array.tq:141:5
    TVARIABLE(Number, actualDeleteCount_99_impl);
    auto actualDeleteCount_99 = &actualDeleteCount_99_impl;
    USE(actualDeleteCount_99);
    // ../src/builtins/array.tq:143:5
    {
      Label label__True_57_impl(this);
      Label* label__True_57 = &label__True_57_impl;
      USE(label__True_57);
      Label label__False_58_impl(this);
      Label* label__False_58 = &label__False_58_impl;
      USE(label__False_58);
      Label label_if_done_label_498_870_impl(this, {actualDeleteCount_99, insertCount_98});
      Label* label_if_done_label_498_870 = &label_if_done_label_498_870_impl;
      USE(label_if_done_label_498_870);
      TNode<IntPtrT> t194 = UncheckedCast<IntPtrT>(GetArgumentsLength(implicit_cast<CodeStubArguments*>(arguments)));
      int31_t t195 = 0;
      TNode<IntPtrT> t196 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t195)));
      TNode<BoolT> t197 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<IntPtrT>>(t194), implicit_cast<TNode<IntPtrT>>(t196)));
      USE(implicit_cast<TNode<BoolT>>(t197));
      Branch(implicit_cast<TNode<BoolT>>(t197), label__True_57, label__False_58);
      if (label__True_57->is_used())
      {
        BIND(label__True_57);
        // ../src/builtins/array.tq:143:32
        {
          // ../src/builtins/array.tq:145:7
          int31_t t198 = 0;
          TNode<Smi> t199 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t198)));
          *insertCount_98 = implicit_cast<TNode<Smi>>(t199);
          // ../src/builtins/array.tq:147:7
          int31_t t200 = 0;
          TNode<Number> t201 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t200)));
          *actualDeleteCount_99 = implicit_cast<TNode<Number>>(t201);
        }
        Goto(label_if_done_label_498_870);
      }
      if (label__False_58->is_used())
      {
        BIND(label__False_58);
        // ../src/builtins/array.tq:149:12
        {
          Label label__True_59_impl(this);
          Label* label__True_59 = &label__True_59_impl;
          USE(label__True_59);
          Label label__False_60_impl(this);
          Label* label__False_60 = &label__False_60_impl;
          USE(label__False_60);
          Label label_if_done_label_499_871_impl(this, {actualDeleteCount_99, insertCount_98});
          Label* label_if_done_label_499_871 = &label_if_done_label_499_871_impl;
          USE(label_if_done_label_499_871);
          TNode<IntPtrT> t202 = UncheckedCast<IntPtrT>(GetArgumentsLength(implicit_cast<CodeStubArguments*>(arguments)));
          int31_t t203 = 1;
          TNode<IntPtrT> t204 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t203)));
          TNode<BoolT> t205 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<IntPtrT>>(t202), implicit_cast<TNode<IntPtrT>>(t204)));
          USE(implicit_cast<TNode<BoolT>>(t205));
          Branch(implicit_cast<TNode<BoolT>>(t205), label__True_59, label__False_60);
          if (label__True_59->is_used())
          {
            BIND(label__True_59);
            // ../src/builtins/array.tq:149:39
            {
              // ../src/builtins/array.tq:151:7
              int31_t t206 = 0;
              TNode<Smi> t207 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t206)));
              *insertCount_98 = implicit_cast<TNode<Smi>>(t207);
              // ../src/builtins/array.tq:153:7
              TNode<Number> t208 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*len_94).value()), implicit_cast<TNode<Number>>((*actualStart_97).value())));
              USE(implicit_cast<TNode<Number>>(t208));
              *actualDeleteCount_99 = implicit_cast<TNode<Number>>(t208);
            }
            Goto(label_if_done_label_499_871);
          }
          if (label__False_60->is_used())
          {
            BIND(label__False_60);
            // ../src/builtins/array.tq:155:12
            {
              // ../src/builtins/array.tq:157:7
              TNode<IntPtrT> t209 = UncheckedCast<IntPtrT>(GetArgumentsLength(implicit_cast<CodeStubArguments*>(arguments)));
              TNode<Smi> t210 = UncheckedCast<Smi>(convert5ATSmi(implicit_cast<TNode<IntPtrT>>(t209)));
              USE(implicit_cast<TNode<Smi>>(t210));
              int31_t t211 = 2;
              TNode<Smi> t212 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t211)));
              TNode<Smi> t213 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t210), implicit_cast<TNode<Smi>>(t212)));
              USE(implicit_cast<TNode<Smi>>(t213));
              *insertCount_98 = implicit_cast<TNode<Smi>>(t213);
              // ../src/builtins/array.tq:159:7
              int31_t t214 = 1;
              TNode<IntPtrT> t215 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t214)));
              TNode<Object> t216 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t215)));
              TVARIABLE(Object, deleteCount_100_impl);
              auto deleteCount_100 = &deleteCount_100_impl;
              USE(deleteCount_100);
              *deleteCount_100 = implicit_cast<TNode<Object>>(t216);
              // ../src/builtins/array.tq:160:7
              TNode<Number> t217 = UncheckedCast<Number>(ToInteger_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*deleteCount_100).value())));
              USE(implicit_cast<TNode<Number>>(t217));
              TVARIABLE(Number, dc_101_impl);
              auto dc_101 = &dc_101_impl;
              USE(dc_101);
              *dc_101 = implicit_cast<TNode<Number>>(t217);
              // ../src/builtins/array.tq:162:7
              int31_t t218 = 0;
              TNode<Number> t219 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t218)));
              TNode<Number> t220 = UncheckedCast<Number>(max(implicit_cast<TNode<Number>>((*dc_101).value()), implicit_cast<TNode<Number>>(t219)));
              USE(implicit_cast<TNode<Number>>(t220));
              TNode<Number> t221 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*len_94).value()), implicit_cast<TNode<Number>>((*actualStart_97).value())));
              USE(implicit_cast<TNode<Number>>(t221));
              TNode<Number> t222 = UncheckedCast<Number>(min(implicit_cast<TNode<Number>>(t220), implicit_cast<TNode<Number>>(t221)));
              USE(implicit_cast<TNode<Number>>(t222));
              *actualDeleteCount_99 = implicit_cast<TNode<Number>>(t222);
            }
            Goto(label_if_done_label_499_871);
          }
          BIND(label_if_done_label_499_871);
        }
        Goto(label_if_done_label_498_870);
      }
      BIND(label_if_done_label_498_870);
    }
    // ../src/builtins/array.tq:167:5
    {
      Label label__True_61_impl(this);
      Label* label__True_61 = &label__True_61_impl;
      USE(label__True_61);
      Label label__False_62_impl(this, {});
      Label* label__False_62 = &label__False_62_impl;
      USE(label__False_62);
      TNode<Number> t223 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*len_94).value()), implicit_cast<TNode<Number>>((*insertCount_98).value())));
      USE(implicit_cast<TNode<Number>>(t223));
      TNode<Number> t224 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>(t223), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value())));
      USE(implicit_cast<TNode<Number>>(t224));
      TNode<Number> t225 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<double>(kMaxSafeInteger)));
      BranchIfNumberGreaterThan(implicit_cast<TNode<Number>>(t224), implicit_cast<TNode<Number>>(t225), label__True_61, label__False_62);
      if (label__True_61->is_used())
      {
        BIND(label__True_61);
        // ../src/builtins/array.tq:167:66
        {
          // ../src/builtins/array.tq:168:7
          ThrowRangeError(implicit_cast<TNode<Context>>(p_context), implicit_cast<MessageTemplate::Template>(MessageTemplate::kInvalidArrayLength));
        }
      }
      BIND(label__False_62);
    }
    // ../src/builtins/array.tq:171:5
    {
      Label label_try_done_500_872_impl(this);
      Label* label_try_done_500_872 = &label_try_done_500_872_impl;
      USE(label_try_done_500_872);
      Label label_Bailout_63_impl(this);
      Label* label_Bailout_63 = &label_Bailout_63_impl;
      USE(label_Bailout_63);
      Label label_try_begin_501_873_impl(this);
      Label* label_try_begin_501_873 = &label_try_begin_501_873_impl;
      USE(label_try_begin_501_873);
      Goto(label_try_begin_501_873);
      if (label_try_begin_501_873->is_used())
      {
        BIND(label_try_begin_501_873);
        // ../src/builtins/array.tq:171:9
        {
          // ../src/builtins/array.tq:172:7
          TNode<Object> t226 = UncheckedCast<Object>(FastArraySplice(implicit_cast<TNode<Context>>(p_context), implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Number>>((*len_94).value()), implicit_cast<TNode<Number>>((*actualStart_97).value()), implicit_cast<TNode<Smi>>((*insertCount_98).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value()), label_Bailout_63));
          USE(implicit_cast<TNode<Object>>(t226));
          arguments->PopAndReturn(implicit_cast<TNode<Object>>(t226));
        }
      }
      if (label_Bailout_63->is_used())
      {
        BIND(label_Bailout_63);
        // ../src/builtins/array.tq:176:19
        {
        }
        Goto(label_try_done_500_872);
      }
      BIND(label_try_done_500_872);
    }
    // ../src/builtins/array.tq:181:5
    TNode<Object> t227 = UncheckedCast<Object>(ArraySpeciesCreate(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value())));
    USE(implicit_cast<TNode<Object>>(t227));
    TVARIABLE(Object, a_102_impl);
    auto a_102 = &a_102_impl;
    USE(a_102);
    *a_102 = implicit_cast<TNode<Object>>(t227);
    // ../src/builtins/array.tq:184:5
    int31_t t228 = 0;
    TVARIABLE(Number, k_103_impl);
    auto k_103 = &k_103_impl;
    USE(k_103);
    TNode<Number> t229 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t228)));
    *k_103 = implicit_cast<TNode<Number>>(t229);
    // ../src/builtins/array.tq:187:5
    {
      Label label__True_64_impl(this);
      Label* label__True_64 = &label__True_64_impl;
      USE(label__True_64);
      Label label__False_65_impl(this);
      Label* label__False_65 = &label__False_65_impl;
      USE(label__False_65);
      Label label_header_502_874_impl(this, {k_103});
      Label* label_header_502_874 = &label_header_502_874_impl;
      USE(label_header_502_874);
      Goto(label_header_502_874);
      BIND(label_header_502_874);
      BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*k_103).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value()), label__True_64, label__False_65);
      if (label__True_64->is_used())
      {
        BIND(label__True_64);
        // ../src/builtins/array.tq:187:35
        {
          // ../src/builtins/array.tq:189:7
          TNode<Number> t230 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*actualStart_97).value()), implicit_cast<TNode<Number>>((*k_103).value())));
          USE(implicit_cast<TNode<Number>>(t230));
          TNode<String> t231 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t230)));
          USE(implicit_cast<TNode<String>>(t231));
          TVARIABLE(String, from_104_impl);
          auto from_104 = &from_104_impl;
          USE(from_104);
          *from_104 = implicit_cast<TNode<String>>(t231);
          // ../src/builtins/array.tq:192:7
          TNode<Oddball> t232 = UncheckedCast<Oddball>(CallBuiltin(Builtins::kHasProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*o_93).value()), implicit_cast<TNode<Object>>((*from_104).value())));
          USE(implicit_cast<TNode<Oddball>>(t232));
          TVARIABLE(Oddball, fromPresent_105_impl);
          auto fromPresent_105 = &fromPresent_105_impl;
          USE(fromPresent_105);
          *fromPresent_105 = implicit_cast<TNode<Oddball>>(t232);
          // ../src/builtins/array.tq:195:7
          {
            Label label__True_66_impl(this);
            Label* label__True_66 = &label__True_66_impl;
            USE(label__True_66);
            Label label__False_67_impl(this, {});
            Label* label__False_67 = &label__False_67_impl;
            USE(label__False_67);
            TNode<BoolT> t233 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*fromPresent_105).value()), implicit_cast<TNode<Object>>(True())));
            USE(implicit_cast<TNode<BoolT>>(t233));
            Branch(implicit_cast<TNode<BoolT>>(t233), label__True_66, label__False_67);
            if (label__True_66->is_used())
            {
              BIND(label__True_66);
              // ../src/builtins/array.tq:195:32
              {
                // ../src/builtins/array.tq:197:9
                TNode<Object> t234 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Object>>((*from_104).value())));
                USE(implicit_cast<TNode<Object>>(t234));
                TVARIABLE(Object, fromValue_106_impl);
                auto fromValue_106 = &fromValue_106_impl;
                USE(fromValue_106);
                *fromValue_106 = implicit_cast<TNode<Object>>(t234);
                // ../src/builtins/array.tq:200:9
                TNode<String> t235 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*k_103).value())));
                USE(implicit_cast<TNode<String>>(t235));
                CallRuntime(Runtime::kCreateDataProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*a_102).value()), implicit_cast<TNode<Object>>(t235), implicit_cast<TNode<Object>>((*fromValue_106).value()));
              }
              Goto(label__False_67);
            }
            BIND(label__False_67);
          }
          // ../src/builtins/array.tq:204:7
          int31_t t236 = 1;
          TNode<Number> t237 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t236)));
          TNode<Number> t238 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*k_103).value()), implicit_cast<TNode<Number>>(t237)));
          USE(implicit_cast<TNode<Number>>(t238));
          *k_103 = implicit_cast<TNode<Number>>(t238);
        }
        Goto(label_header_502_874);
      }
      BIND(label__False_65);
    }
    // ../src/builtins/array.tq:208:5
    const char* t239 = "length";
    TNode<Object> t240 = UncheckedCast<Object>(from_constexpr22UT12ATHeapObject5ATSmi(implicit_cast<const char*>(t239)));
    CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*a_102).value()), implicit_cast<TNode<Object>>(t240), implicit_cast<TNode<Object>>((*actualDeleteCount_99).value()));
    // ../src/builtins/array.tq:215:5
    TVARIABLE(Number, itemCount_107_impl);
    auto itemCount_107 = &itemCount_107_impl;
    USE(itemCount_107);
    *itemCount_107 = implicit_cast<TNode<Number>>((*insertCount_98).value());
    // ../src/builtins/array.tq:218:5
    {
      Label label__True_68_impl(this);
      Label* label__True_68 = &label__True_68_impl;
      USE(label__True_68);
      Label label__False_69_impl(this);
      Label* label__False_69 = &label__False_69_impl;
      USE(label__False_69);
      Label label_if_done_label_503_875_impl(this, {});
      Label* label_if_done_label_503_875 = &label_if_done_label_503_875_impl;
      USE(label_if_done_label_503_875);
      BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*itemCount_107).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value()), label__True_68, label__False_69);
      if (label__True_68->is_used())
      {
        BIND(label__True_68);
        // ../src/builtins/array.tq:218:40
        {
          // ../src/builtins/array.tq:220:7
          TVARIABLE(Number, k_108_impl);
          auto k_108 = &k_108_impl;
          USE(k_108);
          *k_108 = implicit_cast<TNode<Number>>((*actualStart_97).value());
          // ../src/builtins/array.tq:223:7
          {
            Label label__True_70_impl(this);
            Label* label__True_70 = &label__True_70_impl;
            USE(label__True_70);
            Label label__False_71_impl(this);
            Label* label__False_71 = &label__False_71_impl;
            USE(label__False_71);
            Label label_header_504_876_impl(this, {k_108});
            Label* label_header_504_876 = &label_header_504_876_impl;
            USE(label_header_504_876);
            Goto(label_header_504_876);
            BIND(label_header_504_876);
            TNode<Number> t241 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*len_94).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value())));
            USE(implicit_cast<TNode<Number>>(t241));
            BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*k_108).value()), implicit_cast<TNode<Number>>(t241), label__True_70, label__False_71);
            if (label__True_70->is_used())
            {
              BIND(label__True_70);
              // ../src/builtins/array.tq:223:45
              {
                // ../src/builtins/array.tq:225:9
                TNode<Number> t242 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*k_108).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value())));
                USE(implicit_cast<TNode<Number>>(t242));
                TNode<String> t243 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t242)));
                USE(implicit_cast<TNode<String>>(t243));
                TVARIABLE(String, from_109_impl);
                auto from_109 = &from_109_impl;
                USE(from_109);
                *from_109 = implicit_cast<TNode<String>>(t243);
                // ../src/builtins/array.tq:227:9
                TNode<Number> t244 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*k_108).value()), implicit_cast<TNode<Number>>((*itemCount_107).value())));
                USE(implicit_cast<TNode<Number>>(t244));
                TNode<String> t245 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t244)));
                USE(implicit_cast<TNode<String>>(t245));
                TVARIABLE(String, to_110_impl);
                auto to_110 = &to_110_impl;
                USE(to_110);
                *to_110 = implicit_cast<TNode<String>>(t245);
                // ../src/builtins/array.tq:230:9
                TNode<Oddball> t246 = UncheckedCast<Oddball>(CallBuiltin(Builtins::kHasProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*o_93).value()), implicit_cast<TNode<Object>>((*from_109).value())));
                USE(implicit_cast<TNode<Oddball>>(t246));
                TVARIABLE(Oddball, fromPresent_111_impl);
                auto fromPresent_111 = &fromPresent_111_impl;
                USE(fromPresent_111);
                *fromPresent_111 = implicit_cast<TNode<Oddball>>(t246);
                // ../src/builtins/array.tq:233:9
                {
                  Label label__True_72_impl(this);
                  Label* label__True_72 = &label__True_72_impl;
                  USE(label__True_72);
                  Label label__False_73_impl(this);
                  Label* label__False_73 = &label__False_73_impl;
                  USE(label__False_73);
                  Label label_if_done_label_505_877_impl(this, {});
                  Label* label_if_done_label_505_877 = &label_if_done_label_505_877_impl;
                  USE(label_if_done_label_505_877);
                  TNode<BoolT> t247 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*fromPresent_111).value()), implicit_cast<TNode<Object>>(True())));
                  USE(implicit_cast<TNode<BoolT>>(t247));
                  Branch(implicit_cast<TNode<BoolT>>(t247), label__True_72, label__False_73);
                  if (label__True_72->is_used())
                  {
                    BIND(label__True_72);
                    // ../src/builtins/array.tq:233:34
                    {
                      // ../src/builtins/array.tq:235:11
                      TNode<Object> t248 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Object>>((*from_109).value())));
                      USE(implicit_cast<TNode<Object>>(t248));
                      TVARIABLE(Object, fromValue_112_impl);
                      auto fromValue_112 = &fromValue_112_impl;
                      USE(fromValue_112);
                      *fromValue_112 = implicit_cast<TNode<Object>>(t248);
                      // ../src/builtins/array.tq:238:11
                      CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Object>>((*to_110).value()), implicit_cast<TNode<Object>>((*fromValue_112).value()));
                    }
                    Goto(label_if_done_label_505_877);
                  }
                  if (label__False_73->is_used())
                  {
                    BIND(label__False_73);
                    // ../src/builtins/array.tq:241:16
                    {
                      // ../src/builtins/array.tq:243:11
                      TNode<Smi> t249 = UncheckedCast<Smi>(from_constexpr14ATLanguageMode(implicit_cast<LanguageMode>(LanguageMode::kStrict)));
                      CallBuiltin(Builtins::kDeleteProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Object>>((*to_110).value()), implicit_cast<TNode<Smi>>(t249));
                    }
                    Goto(label_if_done_label_505_877);
                  }
                  BIND(label_if_done_label_505_877);
                }
                // ../src/builtins/array.tq:246:9
                int31_t t250 = 1;
                TNode<Number> t251 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t250)));
                TNode<Number> t252 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*k_108).value()), implicit_cast<TNode<Number>>(t251)));
                USE(implicit_cast<TNode<Number>>(t252));
                *k_108 = implicit_cast<TNode<Number>>(t252);
              }
              Goto(label_header_504_876);
            }
            BIND(label__False_71);
          }
          // ../src/builtins/array.tq:250:7
          *k_108 = implicit_cast<TNode<Number>>((*len_94).value());
          // ../src/builtins/array.tq:252:7
          {
            Label label__True_74_impl(this);
            Label* label__True_74 = &label__True_74_impl;
            USE(label__True_74);
            Label label__False_75_impl(this);
            Label* label__False_75 = &label__False_75_impl;
            USE(label__False_75);
            Label label_header_506_878_impl(this, {k_108});
            Label* label_header_506_878 = &label_header_506_878_impl;
            USE(label_header_506_878);
            Goto(label_header_506_878);
            BIND(label_header_506_878);
            TNode<Number> t253 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*len_94).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value())));
            USE(implicit_cast<TNode<Number>>(t253));
            TNode<Number> t254 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>(t253), implicit_cast<TNode<Number>>((*itemCount_107).value())));
            USE(implicit_cast<TNode<Number>>(t254));
            BranchIfNumberGreaterThan(implicit_cast<TNode<Number>>((*k_108).value()), implicit_cast<TNode<Number>>(t254), label__True_74, label__False_75);
            if (label__True_74->is_used())
            {
              BIND(label__True_74);
              // ../src/builtins/array.tq:252:57
              {
                // ../src/builtins/array.tq:254:9
                int31_t t255 = 1;
                TNode<Number> t256 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t255)));
                TNode<Number> t257 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*k_108).value()), implicit_cast<TNode<Number>>(t256)));
                USE(implicit_cast<TNode<Number>>(t257));
                TNode<String> t258 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t257)));
                USE(implicit_cast<TNode<String>>(t258));
                TNode<Smi> t259 = UncheckedCast<Smi>(from_constexpr14ATLanguageMode(implicit_cast<LanguageMode>(LanguageMode::kStrict)));
                CallBuiltin(Builtins::kDeleteProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Object>>(t258), implicit_cast<TNode<Smi>>(t259));
                // ../src/builtins/array.tq:257:9
                int31_t t260 = 1;
                TNode<Number> t261 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t260)));
                TNode<Number> t262 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*k_108).value()), implicit_cast<TNode<Number>>(t261)));
                USE(implicit_cast<TNode<Number>>(t262));
                *k_108 = implicit_cast<TNode<Number>>(t262);
              }
              Goto(label_header_506_878);
            }
            BIND(label__False_75);
          }
        }
        Goto(label_if_done_label_503_875);
      }
      if (label__False_69->is_used())
      {
        BIND(label__False_69);
        // ../src/builtins/array.tq:260:12
        {
          Label label__True_76_impl(this);
          Label* label__True_76 = &label__True_76_impl;
          USE(label__True_76);
          Label label__False_77_impl(this, {});
          Label* label__False_77 = &label__False_77_impl;
          USE(label__False_77);
          BranchIfNumberGreaterThan(implicit_cast<TNode<Number>>((*itemCount_107).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value()), label__True_76, label__False_77);
          if (label__True_76->is_used())
          {
            BIND(label__True_76);
            // ../src/builtins/array.tq:260:47
            {
              // ../src/builtins/array.tq:262:7
              TNode<Number> t263 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*len_94).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value())));
              USE(implicit_cast<TNode<Number>>(t263));
              TVARIABLE(Number, k_113_impl);
              auto k_113 = &k_113_impl;
              USE(k_113);
              *k_113 = implicit_cast<TNode<Number>>(t263);
              // ../src/builtins/array.tq:265:7
              {
                Label label__True_78_impl(this);
                Label* label__True_78 = &label__True_78_impl;
                USE(label__True_78);
                Label label__False_79_impl(this);
                Label* label__False_79 = &label__False_79_impl;
                USE(label__False_79);
                Label label_header_507_879_impl(this, {k_113});
                Label* label_header_507_879 = &label_header_507_879_impl;
                USE(label_header_507_879);
                Goto(label_header_507_879);
                BIND(label_header_507_879);
                BranchIfNumberGreaterThan(implicit_cast<TNode<Number>>((*k_113).value()), implicit_cast<TNode<Number>>((*actualStart_97).value()), label__True_78, label__False_79);
                if (label__True_78->is_used())
                {
                  BIND(label__True_78);
                  // ../src/builtins/array.tq:265:31
                  {
                    // ../src/builtins/array.tq:267:9
                    TNode<Number> t264 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*k_113).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value())));
                    USE(implicit_cast<TNode<Number>>(t264));
                    int31_t t265 = 1;
                    TNode<Number> t266 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t265)));
                    TNode<Number> t267 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>(t264), implicit_cast<TNode<Number>>(t266)));
                    USE(implicit_cast<TNode<Number>>(t267));
                    TNode<String> t268 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t267)));
                    USE(implicit_cast<TNode<String>>(t268));
                    TVARIABLE(String, from_114_impl);
                    auto from_114 = &from_114_impl;
                    USE(from_114);
                    *from_114 = implicit_cast<TNode<String>>(t268);
                    // ../src/builtins/array.tq:270:9
                    TNode<Number> t269 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*k_113).value()), implicit_cast<TNode<Number>>((*itemCount_107).value())));
                    USE(implicit_cast<TNode<Number>>(t269));
                    int31_t t270 = 1;
                    TNode<Number> t271 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t270)));
                    TNode<Number> t272 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>(t269), implicit_cast<TNode<Number>>(t271)));
                    USE(implicit_cast<TNode<Number>>(t272));
                    TNode<String> t273 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t272)));
                    USE(implicit_cast<TNode<String>>(t273));
                    TVARIABLE(String, to_115_impl);
                    auto to_115 = &to_115_impl;
                    USE(to_115);
                    *to_115 = implicit_cast<TNode<String>>(t273);
                    // ../src/builtins/array.tq:273:9
                    TNode<Oddball> t274 = UncheckedCast<Oddball>(CallBuiltin(Builtins::kHasProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*o_93).value()), implicit_cast<TNode<Object>>((*from_114).value())));
                    USE(implicit_cast<TNode<Oddball>>(t274));
                    TVARIABLE(Oddball, fromPresent_116_impl);
                    auto fromPresent_116 = &fromPresent_116_impl;
                    USE(fromPresent_116);
                    *fromPresent_116 = implicit_cast<TNode<Oddball>>(t274);
                    // ../src/builtins/array.tq:276:9
                    {
                      Label label__True_80_impl(this);
                      Label* label__True_80 = &label__True_80_impl;
                      USE(label__True_80);
                      Label label__False_81_impl(this);
                      Label* label__False_81 = &label__False_81_impl;
                      USE(label__False_81);
                      Label label_if_done_label_508_880_impl(this, {});
                      Label* label_if_done_label_508_880 = &label_if_done_label_508_880_impl;
                      USE(label_if_done_label_508_880);
                      TNode<BoolT> t275 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*fromPresent_116).value()), implicit_cast<TNode<Object>>(True())));
                      USE(implicit_cast<TNode<BoolT>>(t275));
                      Branch(implicit_cast<TNode<BoolT>>(t275), label__True_80, label__False_81);
                      if (label__True_80->is_used())
                      {
                        BIND(label__True_80);
                        // ../src/builtins/array.tq:276:34
                        {
                          // ../src/builtins/array.tq:278:11
                          TNode<Object> t276 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Object>>((*from_114).value())));
                          USE(implicit_cast<TNode<Object>>(t276));
                          TVARIABLE(Object, fromValue_117_impl);
                          auto fromValue_117 = &fromValue_117_impl;
                          USE(fromValue_117);
                          *fromValue_117 = implicit_cast<TNode<Object>>(t276);
                          // ../src/builtins/array.tq:281:11
                          CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Object>>((*to_115).value()), implicit_cast<TNode<Object>>((*fromValue_117).value()));
                        }
                        Goto(label_if_done_label_508_880);
                      }
                      if (label__False_81->is_used())
                      {
                        BIND(label__False_81);
                        // ../src/builtins/array.tq:284:16
                        {
                          // ../src/builtins/array.tq:286:11
                          TNode<Smi> t277 = UncheckedCast<Smi>(from_constexpr14ATLanguageMode(implicit_cast<LanguageMode>(LanguageMode::kStrict)));
                          CallBuiltin(Builtins::kDeleteProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Object>>((*to_115).value()), implicit_cast<TNode<Smi>>(t277));
                        }
                        Goto(label_if_done_label_508_880);
                      }
                      BIND(label_if_done_label_508_880);
                    }
                    // ../src/builtins/array.tq:290:9
                    int31_t t278 = 1;
                    TNode<Number> t279 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t278)));
                    TNode<Number> t280 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*k_113).value()), implicit_cast<TNode<Number>>(t279)));
                    USE(implicit_cast<TNode<Number>>(t280));
                    *k_113 = implicit_cast<TNode<Number>>(t280);
                  }
                  Goto(label_header_507_879);
                }
                BIND(label__False_79);
              }
            }
            Goto(label__False_77);
          }
          BIND(label__False_77);
        }
        Goto(label_if_done_label_503_875);
      }
      BIND(label_if_done_label_503_875);
    }
    // ../src/builtins/array.tq:295:5
    *k_103 = implicit_cast<TNode<Number>>((*actualStart_97).value());
    // ../src/builtins/array.tq:300:5
    {
      Label label__True_82_impl(this);
      Label* label__True_82 = &label__True_82_impl;
      USE(label__True_82);
      Label label__False_83_impl(this, {k_103});
      Label* label__False_83 = &label__False_83_impl;
      USE(label__False_83);
      TNode<IntPtrT> t281 = UncheckedCast<IntPtrT>(GetArgumentsLength(implicit_cast<CodeStubArguments*>(arguments)));
      int31_t t282 = 2;
      TNode<IntPtrT> t283 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t282)));
      TNode<BoolT> t284 = UncheckedCast<BoolT>(IntPtrGreaterThan(implicit_cast<TNode<IntPtrT>>(t281), implicit_cast<TNode<IntPtrT>>(t283)));
      USE(implicit_cast<TNode<BoolT>>(t284));
      Branch(implicit_cast<TNode<BoolT>>(t284), label__True_82, label__False_83);
      if (label__True_82->is_used())
      {
        BIND(label__True_82);
        // ../src/builtins/array.tq:300:31
        {
          // ../src/builtins/array.tq:301:7
          int31_t t285 = 2;
          TNode<IntPtrT> t286 = UncheckedCast<IntPtrT>(GetArgumentsLength(implicit_cast<CodeStubArguments*>(arguments)));
          Label label_body_509_881_impl(this);
          Label* label_body_509_881 = &label_body_509_881_impl;
          USE(label_body_509_881);
          Label label_increment_510_882_impl(this);
          Label* label_increment_510_882 = &label_increment_510_882_impl;
          USE(label_increment_510_882);
          Label label_exit_511_883_impl(this);
          Label* label_exit_511_883 = &label_exit_511_883_impl;
          USE(label_exit_511_883);
          TVARIABLE(IntPtrT, _for_index_t287_512_impl);
          auto _for_index_t287_512 = &_for_index_t287_512_impl;
          USE(_for_index_t287_512);
          TNode<IntPtrT> t288 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t285)));
          *_for_index_t287_512 = implicit_cast<TNode<IntPtrT>>(t288);
          Label label_header_513_884_impl(this, {_for_index_t287_512, k_103});
          Label* label_header_513_884 = &label_header_513_884_impl;
          USE(label_header_513_884);
          Goto(label_header_513_884);
          BIND(label_header_513_884);
          TNode<BoolT> t289 = UncheckedCast<BoolT>(IntPtrLessThan(implicit_cast<TNode<IntPtrT>>((*_for_index_t287_512).value()), implicit_cast<TNode<IntPtrT>>(t286)));
          Branch(implicit_cast<TNode<BoolT>>(t289), label_body_509_881, label_exit_511_883);
          BIND(label_body_509_881);
          TNode<Object> t290 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>((*_for_index_t287_512).value())));
          TVARIABLE(Object, e_118_impl);
          auto e_118 = &e_118_impl;
          USE(e_118);
          *e_118 = implicit_cast<TNode<Object>>(t290);
          // ../src/builtins/array.tq:301:46
          {
            // ../src/builtins/array.tq:303:9
            TNode<String> t291 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*k_103).value())));
            USE(implicit_cast<TNode<String>>(t291));
            CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Object>>(t291), implicit_cast<TNode<Object>>((*e_118).value()));
            // ../src/builtins/array.tq:306:9
            int31_t t292 = 1;
            TNode<Number> t293 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t292)));
            TNode<Number> t294 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*k_103).value()), implicit_cast<TNode<Number>>(t293)));
            USE(implicit_cast<TNode<Number>>(t294));
            *k_103 = implicit_cast<TNode<Number>>(t294);
          }
          Goto(label_increment_510_882);
          BIND(label_increment_510_882);
          TNode<IntPtrT> t295 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(1)));
          TNode<IntPtrT> t296 = UncheckedCast<IntPtrT>(IntPtrAdd(implicit_cast<TNode<IntPtrT>>((*_for_index_t287_512).value()), implicit_cast<TNode<IntPtrT>>(t295)));
          *_for_index_t287_512 = implicit_cast<TNode<IntPtrT>>(t296);
          Goto(label_header_513_884);
          BIND(label_exit_511_883);
        }
        Goto(label__False_83);
      }
      BIND(label__False_83);
    }
    // ../src/builtins/array.tq:312:5
    const char* t297 = "length";
    TNode<Number> t298 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*len_94).value()), implicit_cast<TNode<Number>>((*actualDeleteCount_99).value())));
    USE(implicit_cast<TNode<Number>>(t298));
    TNode<Number> t299 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>(t298), implicit_cast<TNode<Number>>((*itemCount_107).value())));
    USE(implicit_cast<TNode<Number>>(t299));
    TNode<Object> t300 = UncheckedCast<Object>(from_constexpr22UT12ATHeapObject5ATSmi(implicit_cast<const char*>(t297)));
    CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_93).value()), implicit_cast<TNode<Object>>(t300), implicit_cast<TNode<Object>>(t299));
    // ../src/builtins/array.tq:314:5
    arguments->PopAndReturn(implicit_cast<TNode<Object>>((*a_102).value()));
  }
}

compiler::TNode<Number> ArrayBuiltinsFromDSLAssembler::ConvertToRelativeIndex(TNode<Number> p_index, TNode<Number> p_length) {
  TVARIABLE(Number, _return_119_impl);
  auto _return_119 = &_return_119_impl;
  USE(_return_119);
  Label label_macro_end_885_impl(this, {_return_119});
  Label* label_macro_end_885 = &label_macro_end_885_impl;
  USE(label_macro_end_885);
  // ../src/builtins/array-copywithin.tq:6:71
  {
    // ../src/builtins/array-copywithin.tq:7:5
    auto t301 = [=]() {
      TNode<Number> t303 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>(p_index), implicit_cast<TNode<Number>>(p_length)));
      USE(implicit_cast<TNode<Number>>(t303));
      int31_t t304 = 0;
      TNode<Number> t305 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t304)));
      TNode<Number> t306 = UncheckedCast<Number>(max(implicit_cast<TNode<Number>>(t303), implicit_cast<TNode<Number>>(t305)));
      USE(implicit_cast<TNode<Number>>(t306));
      return implicit_cast<TNode<Number>>(t306);
    };
    auto t302 = [=]() {
      TNode<Number> t307 = UncheckedCast<Number>(min(implicit_cast<TNode<Number>>(p_index), implicit_cast<TNode<Number>>(p_length)));
      USE(implicit_cast<TNode<Number>>(t307));
      return implicit_cast<TNode<Number>>(t307);
    };
    TVARIABLE(Number, t308_514_impl);
    auto t308_514 = &t308_514_impl;
    USE(t308_514);
    {
      Label label__True_84_impl(this);
      Label* label__True_84 = &label__True_84_impl;
      USE(label__True_84);
      Label label__False_85_impl(this);
      Label* label__False_85 = &label__False_85_impl;
      USE(label__False_85);
      Label label__done_515_886_impl(this, {t308_514});
      Label* label__done_515_886 = &label__done_515_886_impl;
      USE(label__done_515_886);
      int31_t t309 = 0;
      TNode<Number> t310 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t309)));
      BranchIfNumberLessThan(implicit_cast<TNode<Number>>(p_index), implicit_cast<TNode<Number>>(t310), label__True_84, label__False_85);
      BIND(label__True_84);
            *t308_514 = implicit_cast<TNode<Number>>(t301());
      Goto(label__done_515_886);
      BIND(label__False_85);
            *t308_514 = implicit_cast<TNode<Number>>(t302());
      Goto(label__done_515_886);
      BIND(label__done_515_886);
    }
    *_return_119 = implicit_cast<TNode<Number>>((*t308_514).value());
    Goto(label_macro_end_885);
  }
  BIND(label_macro_end_885);
  return implicit_cast<TNode<Number>>((*_return_119).value());
}

TF_BUILTIN(ArrayPrototypeCopyWithin, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  CodeStubArguments arguments_impl(this, ChangeInt32ToIntPtr(argc));
  TNode<Object> p_receiver = arguments_impl.GetReceiver();
  auto arguments = &arguments_impl;
  USE(arguments);
  USE(p_receiver);
  // ../src/builtins/array-copywithin.tq:12:65
  {
    // ../src/builtins/array-copywithin.tq:14:5
    TNode<JSReceiver> t311 = UncheckedCast<JSReceiver>(ToObject_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_receiver)));
    USE(implicit_cast<TNode<JSReceiver>>(t311));
    TNode<JSReceiver> object_516_impl;
    auto object_516 = &object_516_impl;
    USE(object_516);
    *object_516 = implicit_cast<TNode<JSReceiver>>(t311);
    // ../src/builtins/array-copywithin.tq:17:5
    TNode<Number> t312 = UncheckedCast<Number>(GetLengthProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_516))));
    USE(implicit_cast<TNode<Number>>(t312));
    TNode<Number> length_517_impl;
    auto length_517 = &length_517_impl;
    USE(length_517);
    *length_517 = implicit_cast<TNode<Number>>(t312);
    // ../src/builtins/array-copywithin.tq:20:5
    int31_t t313 = 0;
    TNode<IntPtrT> t314 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t313)));
    TNode<Object> t315 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t314)));
    TNode<Number> t316 = UncheckedCast<Number>(ToInteger_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t315)));
    USE(implicit_cast<TNode<Number>>(t316));
    TNode<Number> relative_target_518_impl;
    auto relative_target_518 = &relative_target_518_impl;
    USE(relative_target_518);
    *relative_target_518 = implicit_cast<TNode<Number>>(t316);
    // ../src/builtins/array-copywithin.tq:24:5
    TNode<Number> t317 = UncheckedCast<Number>(ConvertToRelativeIndex(implicit_cast<TNode<Number>>((*relative_target_518)), implicit_cast<TNode<Number>>((*length_517))));
    USE(implicit_cast<TNode<Number>>(t317));
    TVARIABLE(Number, to_120_impl);
    auto to_120 = &to_120_impl;
    USE(to_120);
    *to_120 = implicit_cast<TNode<Number>>(t317);
    // ../src/builtins/array-copywithin.tq:27:5
    int31_t t318 = 1;
    TNode<IntPtrT> t319 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t318)));
    TNode<Object> t320 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t319)));
    TNode<Number> t321 = UncheckedCast<Number>(ToInteger_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t320)));
    USE(implicit_cast<TNode<Number>>(t321));
    TNode<Number> relative_start_519_impl;
    auto relative_start_519 = &relative_start_519_impl;
    USE(relative_start_519);
    *relative_start_519 = implicit_cast<TNode<Number>>(t321);
    // ../src/builtins/array-copywithin.tq:31:5
    TNode<Number> t322 = UncheckedCast<Number>(ConvertToRelativeIndex(implicit_cast<TNode<Number>>((*relative_start_519)), implicit_cast<TNode<Number>>((*length_517))));
    USE(implicit_cast<TNode<Number>>(t322));
    TVARIABLE(Number, from_121_impl);
    auto from_121 = &from_121_impl;
    USE(from_121);
    *from_121 = implicit_cast<TNode<Number>>(t322);
    // ../src/builtins/array-copywithin.tq:35:5
    TVARIABLE(Number, relative_end_122_impl);
    auto relative_end_122 = &relative_end_122_impl;
    USE(relative_end_122);
    *relative_end_122 = implicit_cast<TNode<Number>>((*length_517));
    // ../src/builtins/array-copywithin.tq:36:5
    {
      Label label__True_86_impl(this);
      Label* label__True_86 = &label__True_86_impl;
      USE(label__True_86);
      Label label__False_87_impl(this, {relative_end_122});
      Label* label__False_87 = &label__False_87_impl;
      USE(label__False_87);
      int31_t t323 = 2;
      TNode<IntPtrT> t324 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t323)));
      TNode<Object> t325 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t324)));
      TNode<BoolT> t326 = UncheckedCast<BoolT>(WordNotEqual(implicit_cast<TNode<Object>>(t325), implicit_cast<TNode<Object>>(Undefined())));
      USE(implicit_cast<TNode<BoolT>>(t326));
      Branch(implicit_cast<TNode<BoolT>>(t326), label__True_86, label__False_87);
      if (label__True_86->is_used())
      {
        BIND(label__True_86);
        // ../src/builtins/array-copywithin.tq:36:36
        {
          // ../src/builtins/array-copywithin.tq:37:7
          int31_t t327 = 2;
          TNode<IntPtrT> t328 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t327)));
          TNode<Object> t329 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t328)));
          TNode<Number> t330 = UncheckedCast<Number>(ToInteger_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t329)));
          USE(implicit_cast<TNode<Number>>(t330));
          *relative_end_122 = implicit_cast<TNode<Number>>(t330);
        }
        Goto(label__False_87);
      }
      BIND(label__False_87);
    }
    // ../src/builtins/array-copywithin.tq:42:5
    TNode<Number> t331 = UncheckedCast<Number>(ConvertToRelativeIndex(implicit_cast<TNode<Number>>((*relative_end_122).value()), implicit_cast<TNode<Number>>((*length_517))));
    USE(implicit_cast<TNode<Number>>(t331));
    TNode<Number> final_520_impl;
    auto final_520 = &final_520_impl;
    USE(final_520);
    *final_520 = implicit_cast<TNode<Number>>(t331);
    // ../src/builtins/array-copywithin.tq:45:5
    TNode<Number> t332 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*final_520)), implicit_cast<TNode<Number>>((*from_121).value())));
    USE(implicit_cast<TNode<Number>>(t332));
    TNode<Number> t333 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*length_517)), implicit_cast<TNode<Number>>((*to_120).value())));
    USE(implicit_cast<TNode<Number>>(t333));
    TNode<Number> t334 = UncheckedCast<Number>(min(implicit_cast<TNode<Number>>(t332), implicit_cast<TNode<Number>>(t333)));
    USE(implicit_cast<TNode<Number>>(t334));
    TVARIABLE(Number, count_123_impl);
    auto count_123 = &count_123_impl;
    USE(count_123);
    *count_123 = implicit_cast<TNode<Number>>(t334);
    // ../src/builtins/array-copywithin.tq:48:5
    int31_t t335 = 1;
    TVARIABLE(Number, direction_124_impl);
    auto direction_124 = &direction_124_impl;
    USE(direction_124);
    TNode<Number> t336 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t335)));
    *direction_124 = implicit_cast<TNode<Number>>(t336);
    // ../src/builtins/array-copywithin.tq:50:5
    {
      Label label__True_88_impl(this);
      Label* label__True_88 = &label__True_88_impl;
      USE(label__True_88);
      Label label__False_89_impl(this, {direction_124, from_121, to_120});
      Label* label__False_89 = &label__False_89_impl;
      USE(label__False_89);
      Label label__True_90_impl(this);
      Label* label__True_90 = &label__True_90_impl;
      USE(label__True_90);
      BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*from_121).value()), implicit_cast<TNode<Number>>((*to_120).value()), label__True_90, label__False_89);
      BIND(label__True_90);
      TNode<Number> t337 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*from_121).value()), implicit_cast<TNode<Number>>((*count_123).value())));
      USE(implicit_cast<TNode<Number>>(t337));
      BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*to_120).value()), implicit_cast<TNode<Number>>(t337), label__True_88, label__False_89);
      if (label__True_88->is_used())
      {
        BIND(label__True_88);
        // ../src/builtins/array-copywithin.tq:50:43
        {
          // ../src/builtins/array-copywithin.tq:52:7
          int31_t t338 = -1;
          TNode<Number> t339 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t338)));
          *direction_124 = implicit_cast<TNode<Number>>(t339);
          // ../src/builtins/array-copywithin.tq:55:7
          TNode<Number> t340 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*from_121).value()), implicit_cast<TNode<Number>>((*count_123).value())));
          USE(implicit_cast<TNode<Number>>(t340));
          int31_t t341 = 1;
          TNode<Number> t342 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t341)));
          TNode<Number> t343 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>(t340), implicit_cast<TNode<Number>>(t342)));
          USE(implicit_cast<TNode<Number>>(t343));
          *from_121 = implicit_cast<TNode<Number>>(t343);
          // ../src/builtins/array-copywithin.tq:58:7
          TNode<Number> t344 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*to_120).value()), implicit_cast<TNode<Number>>((*count_123).value())));
          USE(implicit_cast<TNode<Number>>(t344));
          int31_t t345 = 1;
          TNode<Number> t346 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t345)));
          TNode<Number> t347 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>(t344), implicit_cast<TNode<Number>>(t346)));
          USE(implicit_cast<TNode<Number>>(t347));
          *to_120 = implicit_cast<TNode<Number>>(t347);
        }
        Goto(label__False_89);
      }
      BIND(label__False_89);
    }
    // ../src/builtins/array-copywithin.tq:62:5
    {
      Label label__True_91_impl(this);
      Label* label__True_91 = &label__True_91_impl;
      USE(label__True_91);
      Label label__False_92_impl(this);
      Label* label__False_92 = &label__False_92_impl;
      USE(label__False_92);
      Label label_header_521_887_impl(this, {count_123, from_121, to_120});
      Label* label_header_521_887 = &label_header_521_887_impl;
      USE(label_header_521_887);
      Goto(label_header_521_887);
      BIND(label_header_521_887);
      int31_t t348 = 0;
      TNode<Number> t349 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t348)));
      BranchIfNumberGreaterThan(implicit_cast<TNode<Number>>((*count_123).value()), implicit_cast<TNode<Number>>(t349), label__True_91, label__False_92);
      if (label__True_91->is_used())
      {
        BIND(label__True_91);
        // ../src/builtins/array-copywithin.tq:62:23
        {
          // ../src/builtins/array-copywithin.tq:66:7
          TNode<Oddball> t350 = UncheckedCast<Oddball>(CallBuiltin(Builtins::kHasProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*object_516)), implicit_cast<TNode<Object>>((*from_121).value())));
          USE(implicit_cast<TNode<Oddball>>(t350));
          TNode<Oddball> from_present_522_impl;
          auto from_present_522 = &from_present_522_impl;
          USE(from_present_522);
          *from_present_522 = implicit_cast<TNode<Oddball>>(t350);
          // ../src/builtins/array-copywithin.tq:69:7
          {
            Label label__True_93_impl(this);
            Label* label__True_93 = &label__True_93_impl;
            USE(label__True_93);
            Label label__False_94_impl(this);
            Label* label__False_94 = &label__False_94_impl;
            USE(label__False_94);
            Label label_if_done_label_523_888_impl(this, {});
            Label* label_if_done_label_523_888 = &label_if_done_label_523_888_impl;
            USE(label_if_done_label_523_888);
            TNode<BoolT> t351 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*from_present_522)), implicit_cast<TNode<Object>>(True())));
            USE(implicit_cast<TNode<BoolT>>(t351));
            Branch(implicit_cast<TNode<BoolT>>(t351), label__True_93, label__False_94);
            if (label__True_93->is_used())
            {
              BIND(label__True_93);
              // ../src/builtins/array-copywithin.tq:69:33
              {
                // ../src/builtins/array-copywithin.tq:71:9
                TNode<Object> t352 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_516)), implicit_cast<TNode<Object>>((*from_121).value())));
                USE(implicit_cast<TNode<Object>>(t352));
                TNode<Object> from_val_524_impl;
                auto from_val_524 = &from_val_524_impl;
                USE(from_val_524);
                *from_val_524 = implicit_cast<TNode<Object>>(t352);
                // ../src/builtins/array-copywithin.tq:74:9
                CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_516)), implicit_cast<TNode<Object>>((*to_120).value()), implicit_cast<TNode<Object>>((*from_val_524)));
              }
              Goto(label_if_done_label_523_888);
            }
            if (label__False_94->is_used())
            {
              BIND(label__False_94);
              // ../src/builtins/array-copywithin.tq:75:14
              {
                // ../src/builtins/array-copywithin.tq:77:9
                TNode<Smi> t353 = UncheckedCast<Smi>(from_constexpr14ATLanguageMode(implicit_cast<LanguageMode>(LanguageMode::kStrict)));
                CallBuiltin(Builtins::kDeleteProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_516)), implicit_cast<TNode<Object>>((*to_120).value()), implicit_cast<TNode<Smi>>(t353));
              }
              Goto(label_if_done_label_523_888);
            }
            BIND(label_if_done_label_523_888);
          }
          // ../src/builtins/array-copywithin.tq:81:7
          TNode<Number> t354 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*from_121).value()), implicit_cast<TNode<Number>>((*direction_124).value())));
          USE(implicit_cast<TNode<Number>>(t354));
          *from_121 = implicit_cast<TNode<Number>>(t354);
          // ../src/builtins/array-copywithin.tq:84:7
          TNode<Number> t355 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*to_120).value()), implicit_cast<TNode<Number>>((*direction_124).value())));
          USE(implicit_cast<TNode<Number>>(t355));
          *to_120 = implicit_cast<TNode<Number>>(t355);
          // ../src/builtins/array-copywithin.tq:87:7
          TNode<Number> t356 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Number> t357 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*count_123).value()), implicit_cast<TNode<Number>>(t356)));
          *count_123 = implicit_cast<TNode<Number>>(t357);
        }
        Goto(label_header_521_887);
      }
      BIND(label__False_92);
    }
    // ../src/builtins/array-copywithin.tq:91:5
    arguments->PopAndReturn(implicit_cast<TNode<Object>>((*object_516)));
  }
}

compiler::TNode<Object> ArrayBuiltinsFromDSLAssembler::ArrayForEachTorqueContinuation(TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, TNode<Smi> p_initial_k) {
  TVARIABLE(Object, _return_125_impl);
  auto _return_125 = &_return_125_impl;
  USE(_return_125);
  Label label_macro_end_889_impl(this, {_return_125});
  Label* label_macro_end_889 = &label_macro_end_889_impl;
  USE(label_macro_end_889);
  // ../src/builtins/array-foreach.tq:8:48
  {
    // ../src/builtins/array-foreach.tq:11:5
    TVARIABLE(Smi, k_126_impl);
    auto k_126 = &k_126_impl;
    USE(k_126);
    *k_126 = implicit_cast<TNode<Smi>>(p_initial_k);
    Label label__True_95_impl(this);
    Label* label__True_95 = &label__True_95_impl;
    USE(label__True_95);
    Label label__False_96_impl(this);
    Label* label__False_96 = &label__False_96_impl;
    USE(label__False_96);
    Label label_header_525_890_impl(this, {k_126});
    Label* label_header_525_890 = &label_header_525_890_impl;
    USE(label_header_525_890);
    Goto(label_header_525_890);
    BIND(label_header_525_890);
    Label label_action_526_891_impl(this);
    Label* label_action_526_891 = &label_action_526_891_impl;
    USE(label_action_526_891);
    BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*k_126).value()), implicit_cast<TNode<Number>>(p_len), label__True_95, label__False_96);
    if (label__True_95->is_used())
    {
      BIND(label__True_95);
      // ../src/builtins/array-foreach.tq:11:54
      {
        // ../src/builtins/array-foreach.tq:13:7
        TNode<String> t358 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*k_126).value())));
        USE(implicit_cast<TNode<String>>(t358));
        TNode<String> pK_527_impl;
        auto pK_527 = &pK_527_impl;
        USE(pK_527);
        *pK_527 = implicit_cast<TNode<String>>(t358);
        // ../src/builtins/array-foreach.tq:16:7
        TNode<Oddball> t359 = UncheckedCast<Oddball>(CallBuiltin(Builtins::kHasProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>(p_o), implicit_cast<TNode<Object>>((*pK_527))));
        USE(implicit_cast<TNode<Oddball>>(t359));
        TNode<Oddball> kPresent_528_impl;
        auto kPresent_528 = &kPresent_528_impl;
        USE(kPresent_528);
        *kPresent_528 = implicit_cast<TNode<Oddball>>(t359);
        // ../src/builtins/array-foreach.tq:19:7
        {
          Label label__True_97_impl(this);
          Label* label__True_97 = &label__True_97_impl;
          USE(label__True_97);
          Label label__False_98_impl(this, {});
          Label* label__False_98 = &label__False_98_impl;
          USE(label__False_98);
          TNode<BoolT> t360 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*kPresent_528)), implicit_cast<TNode<Object>>(True())));
          USE(implicit_cast<TNode<BoolT>>(t360));
          Branch(implicit_cast<TNode<BoolT>>(t360), label__True_97, label__False_98);
          if (label__True_97->is_used())
          {
            BIND(label__True_97);
            // ../src/builtins/array-foreach.tq:19:29
            {
              // ../src/builtins/array-foreach.tq:21:9
              TNode<Object> t361 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_o), implicit_cast<TNode<Object>>((*pK_527))));
              USE(implicit_cast<TNode<Object>>(t361));
              TNode<Object> kValue_529_impl;
              auto kValue_529 = &kValue_529_impl;
              USE(kValue_529);
              *kValue_529 = implicit_cast<TNode<Object>>(t361);
              // ../src/builtins/array-foreach.tq:24:9
              TNode<Object> t362 = UncheckedCast<Object>(Call(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>(p_callbackfn), implicit_cast<TNode<Object>>(p_thisArg), implicit_cast<TNode<Object>>((*kValue_529)), implicit_cast<TNode<Object>>((*k_126).value()), implicit_cast<TNode<Object>>(p_o)));
              USE(implicit_cast<TNode<Object>>(t362));
            }
            Goto(label__False_98);
          }
          BIND(label__False_98);
        }
      }
      Goto(label_action_526_891);
    }
    {
      BIND(label_action_526_891);
      int31_t t363 = 1;
      TNode<Smi> t364 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t363)));
      TNode<Smi> t365 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*k_126).value()), implicit_cast<TNode<Smi>>(t364)));
      USE(implicit_cast<TNode<Smi>>(t365));
      *k_126 = implicit_cast<TNode<Smi>>(t365);
      Goto(label_header_525_890);
    }
    BIND(label__False_96);
    // ../src/builtins/array-foreach.tq:29:5
    *_return_125 = implicit_cast<TNode<Object>>(Undefined());
    Goto(label_macro_end_889);
  }
  BIND(label_macro_end_889);
  return implicit_cast<TNode<Object>>((*_return_125).value());
}

TF_BUILTIN(ArrayForEachLoopEagerDeoptContinuation, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<Object> p_receiver = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_callback = UncheckedCast<Object>(Parameter(Descriptor::kCallback));
  USE(p_callback);
  TNode<Object> p_thisArg = UncheckedCast<Object>(Parameter(Descriptor::kThisArg));
  USE(p_thisArg);
  TNode<Object> p_initialK = UncheckedCast<Object>(Parameter(Descriptor::kInitialK));
  USE(p_initialK);
  TNode<Object> p_length = UncheckedCast<Object>(Parameter(Descriptor::kLength));
  USE(p_length);
  // ../src/builtins/array-foreach.tq:34:49
  {
    // ../src/builtins/array-foreach.tq:38:5
    TNode<JSReceiver> t366 = UncheckedCast<JSReceiver>(unsafe_cast12ATJSReceiver(implicit_cast<TNode<Object>>(p_receiver)));
    USE(implicit_cast<TNode<JSReceiver>>(t366));
    TNode<JSReceiver> jsreceiver_530_impl;
    auto jsreceiver_530 = &jsreceiver_530_impl;
    USE(jsreceiver_530);
    *jsreceiver_530 = implicit_cast<TNode<JSReceiver>>(t366);
    // ../src/builtins/array-foreach.tq:39:5
    TNode<Object> t367 = UncheckedCast<Object>(CallBuiltin(Builtins::kArrayForEachLoopContinuation, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*jsreceiver_530)), implicit_cast<TNode<Object>>(p_callback), implicit_cast<TNode<Object>>(p_thisArg), implicit_cast<TNode<Object>>(Undefined()), implicit_cast<TNode<Object>>((*jsreceiver_530)), implicit_cast<TNode<Object>>(p_initialK), implicit_cast<TNode<Object>>(p_length), implicit_cast<TNode<Object>>(Undefined())));
    USE(implicit_cast<TNode<Object>>(t367));
    Return(implicit_cast<TNode<Object>>(t367));
  }
}

TF_BUILTIN(ArrayForEachLoopLazyDeoptContinuation, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<Object> p_receiver = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_callback = UncheckedCast<Object>(Parameter(Descriptor::kCallback));
  USE(p_callback);
  TNode<Object> p_thisArg = UncheckedCast<Object>(Parameter(Descriptor::kThisArg));
  USE(p_thisArg);
  TNode<Object> p_initialK = UncheckedCast<Object>(Parameter(Descriptor::kInitialK));
  USE(p_initialK);
  TNode<Object> p_length = UncheckedCast<Object>(Parameter(Descriptor::kLength));
  USE(p_length);
  TNode<Object> p_result = UncheckedCast<Object>(Parameter(Descriptor::kResult));
  USE(p_result);
  // ../src/builtins/array-foreach.tq:46:65
  {
    // ../src/builtins/array-foreach.tq:50:5
    TNode<JSReceiver> t368 = UncheckedCast<JSReceiver>(unsafe_cast12ATJSReceiver(implicit_cast<TNode<Object>>(p_receiver)));
    USE(implicit_cast<TNode<JSReceiver>>(t368));
    TNode<JSReceiver> jsreceiver_531_impl;
    auto jsreceiver_531 = &jsreceiver_531_impl;
    USE(jsreceiver_531);
    *jsreceiver_531 = implicit_cast<TNode<JSReceiver>>(t368);
    // ../src/builtins/array-foreach.tq:51:5
    TNode<Object> t369 = UncheckedCast<Object>(CallBuiltin(Builtins::kArrayForEachLoopContinuation, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*jsreceiver_531)), implicit_cast<TNode<Object>>(p_callback), implicit_cast<TNode<Object>>(p_thisArg), implicit_cast<TNode<Object>>(Undefined()), implicit_cast<TNode<Object>>((*jsreceiver_531)), implicit_cast<TNode<Object>>(p_initialK), implicit_cast<TNode<Object>>(p_length), implicit_cast<TNode<Object>>(Undefined())));
    USE(implicit_cast<TNode<Object>>(t369));
    Return(implicit_cast<TNode<Object>>(t369));
  }
}

TF_BUILTIN(ArrayForEachLoopContinuation, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSReceiver> p_receiver = UncheckedCast<JSReceiver>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_callback = UncheckedCast<Object>(Parameter(Descriptor::kCallback));
  USE(p_callback);
  TNode<Object> p_thisArg = UncheckedCast<Object>(Parameter(Descriptor::kThisArg));
  USE(p_thisArg);
  TNode<Object> p_array = UncheckedCast<Object>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Object> p_object = UncheckedCast<Object>(Parameter(Descriptor::kObject));
  USE(p_object);
  TNode<Object> p_initialK = UncheckedCast<Object>(Parameter(Descriptor::kInitialK));
  USE(p_initialK);
  TNode<Object> p_length = UncheckedCast<Object>(Parameter(Descriptor::kLength));
  USE(p_length);
  TNode<Object> p_to = UncheckedCast<Object>(Parameter(Descriptor::kTo));
  USE(p_to);
  // ../src/builtins/array-foreach.tq:59:27
  {
    // ../src/builtins/array-foreach.tq:60:5
    {
      Label label_try_done_532_892_impl(this);
      Label* label_try_done_532_892 = &label_try_done_532_892_impl;
      USE(label_try_done_532_892);
      Label label_Unexpected_99_impl(this);
      Label* label_Unexpected_99 = &label_Unexpected_99_impl;
      USE(label_Unexpected_99);
      Label label_try_begin_533_893_impl(this);
      Label* label_try_begin_533_893 = &label_try_begin_533_893_impl;
      USE(label_try_begin_533_893);
      Goto(label_try_begin_533_893);
      if (label_try_begin_533_893->is_used())
      {
        BIND(label_try_begin_533_893);
        // ../src/builtins/array-foreach.tq:60:9
        {
          // ../src/builtins/array-foreach.tq:61:7
          TNode<JSReceiver> t370 = UncheckedCast<JSReceiver>(cast45UT17ATJSBoundFunction12ATJSFunction9ATJSProxy(implicit_cast<TNode<Object>>(p_callback), label_Unexpected_99));
          USE(implicit_cast<TNode<JSReceiver>>(t370));
          TNode<JSReceiver> callbackfn_534_impl;
          auto callbackfn_534 = &callbackfn_534_impl;
          USE(callbackfn_534);
          *callbackfn_534 = implicit_cast<TNode<JSReceiver>>(t370);
          // ../src/builtins/array-foreach.tq:63:7
          TNode<Smi> t371 = UncheckedCast<Smi>(cast5ATSmi(implicit_cast<TNode<Object>>(p_initialK), label_Unexpected_99));
          USE(implicit_cast<TNode<Smi>>(t371));
          TNode<Smi> k_535_impl;
          auto k_535 = &k_535_impl;
          USE(k_535);
          *k_535 = implicit_cast<TNode<Smi>>(t371);
          // ../src/builtins/array-foreach.tq:64:7
          TNode<Number> t372 = UncheckedCast<Number>(cast22UT12ATHeapNumber5ATSmi(implicit_cast<TNode<Object>>(p_length), label_Unexpected_99));
          USE(implicit_cast<TNode<Number>>(t372));
          TNode<Number> number_length_536_impl;
          auto number_length_536 = &number_length_536_impl;
          USE(number_length_536);
          *number_length_536 = implicit_cast<TNode<Number>>(t372);
          // ../src/builtins/array-foreach.tq:66:7
          TNode<Object> t373 = UncheckedCast<Object>(ArrayForEachTorqueContinuation(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>(p_receiver), implicit_cast<TNode<Number>>((*number_length_536)), implicit_cast<TNode<JSReceiver>>((*callbackfn_534)), implicit_cast<TNode<Object>>(p_thisArg), implicit_cast<TNode<Smi>>((*k_535))));
          USE(implicit_cast<TNode<Object>>(t373));
          Return(implicit_cast<TNode<Object>>(t373));
        }
      }
      if (label_Unexpected_99->is_used())
      {
        BIND(label_Unexpected_99);
        // ../src/builtins/array-foreach.tq:69:22
        {
          // ../src/builtins/array-foreach.tq:70:7
          Unreachable();
        }
      }
    }
  }
}

compiler::TNode<Object> ArrayBuiltinsFromDSLAssembler::FastArrayForEach(TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, Label* label_Bailout_100, TVariable<Smi>* Bailout0_127) {
  TVARIABLE(Object, _return_128_impl);
  auto _return_128 = &_return_128_impl;
  USE(_return_128);
  Label label_macro_end_894_impl(this, {_return_128});
  Label* label_macro_end_894 = &label_macro_end_894_impl;
  USE(label_macro_end_894);
  // ../src/builtins/array-foreach.tq:111:16
  {
    // ../src/builtins/array-foreach.tq:112:5
    int31_t t374 = 0;
    TVARIABLE(Smi, k_129_impl);
    auto k_129 = &k_129_impl;
    USE(k_129);
    TNode<Smi> t375 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t374)));
    *k_129 = implicit_cast<TNode<Smi>>(t375);
    // ../src/builtins/array-foreach.tq:113:5
    {
      Label label_try_done_537_895_impl(this);
      Label* label_try_done_537_895 = &label_try_done_537_895_impl;
      USE(label_try_done_537_895);
      Label label_Slow_101_impl(this);
      Label* label_Slow_101 = &label_Slow_101_impl;
      USE(label_Slow_101);
      Label label_try_begin_538_896_impl(this);
      Label* label_try_begin_538_896 = &label_try_begin_538_896_impl;
      USE(label_try_begin_538_896);
      Goto(label_try_begin_538_896);
      if (label_try_begin_538_896->is_used())
      {
        BIND(label_try_begin_538_896);
        // ../src/builtins/array-foreach.tq:113:9
        {
          // ../src/builtins/array-foreach.tq:114:7
          TNode<Smi> t376 = UncheckedCast<Smi>(cast5ATSmi(implicit_cast<TNode<Object>>(p_len), label_Slow_101));
          USE(implicit_cast<TNode<Smi>>(t376));
          TNode<Smi> smi_len_539_impl;
          auto smi_len_539 = &smi_len_539_impl;
          USE(smi_len_539);
          *smi_len_539 = implicit_cast<TNode<Smi>>(t376);
          // ../src/builtins/array-foreach.tq:115:7
          TNode<JSArray> t377 = UncheckedCast<JSArray>(cast9ATJSArray(implicit_cast<TNode<HeapObject>>(p_o), label_Slow_101));
          USE(implicit_cast<TNode<JSArray>>(t377));
          TNode<JSArray> a_540_impl;
          auto a_540 = &a_540_impl;
          USE(a_540);
          *a_540 = implicit_cast<TNode<JSArray>>(t377);
          // ../src/builtins/array-foreach.tq:116:7
          TNode<Map> t378 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>((*a_540))));
          TNode<Map> map_541_impl;
          auto map_541 = &map_541_impl;
          USE(map_541);
          *map_541 = implicit_cast<TNode<Map>>(t378);
          // ../src/builtins/array-foreach.tq:118:7
          {
            Label label__True_102_impl(this);
            Label* label__True_102 = &label__True_102_impl;
            USE(label__True_102);
            Label label__False_103_impl(this, {});
            Label* label__False_103 = &label__False_103_impl;
            USE(label__False_103);
            TNode<BoolT> t379 = UncheckedCast<BoolT>(IsPrototypeInitialArrayPrototype(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Map>>((*map_541))));
            USE(implicit_cast<TNode<BoolT>>(t379));
            TNode<BoolT> t380 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t379)));
            USE(implicit_cast<TNode<BoolT>>(t380));
            Branch(implicit_cast<TNode<BoolT>>(t380), label__True_102, label__False_103);
            if (label__True_102->is_used())
            {
              BIND(label__True_102);
              // ../src/builtins/array-foreach.tq:118:60
              Goto(label_Slow_101);
            }
            BIND(label__False_103);
          }
          // ../src/builtins/array-foreach.tq:119:7
          TNode<Int32T> t381 = UncheckedCast<Int32T>(LoadMapElementsKind(implicit_cast<TNode<Map>>((*map_541))));
          TNode<Int32T> elementsKind_542_impl;
          auto elementsKind_542 = &elementsKind_542_impl;
          USE(elementsKind_542);
          *elementsKind_542 = implicit_cast<TNode<Int32T>>(t381);
          // ../src/builtins/array-foreach.tq:120:7
          {
            Label label__True_104_impl(this);
            Label* label__True_104 = &label__True_104_impl;
            USE(label__True_104);
            Label label__False_105_impl(this, {});
            Label* label__False_105 = &label__False_105_impl;
            USE(label__False_105);
            TNode<BoolT> t382 = UncheckedCast<BoolT>(IsFastElementsKind(implicit_cast<TNode<Int32T>>((*elementsKind_542))));
            USE(implicit_cast<TNode<BoolT>>(t382));
            TNode<BoolT> t383 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t382)));
            USE(implicit_cast<TNode<BoolT>>(t383));
            Branch(implicit_cast<TNode<BoolT>>(t383), label__True_104, label__False_105);
            if (label__True_104->is_used())
            {
              BIND(label__True_104);
              // ../src/builtins/array-foreach.tq:120:46
              Goto(label_Slow_101);
            }
            BIND(label__False_105);
          }
          // ../src/builtins/array-foreach.tq:122:7
          {
            Label label__True_106_impl(this);
            Label* label__True_106 = &label__True_106_impl;
            USE(label__True_106);
            Label label__False_107_impl(this);
            Label* label__False_107 = &label__False_107_impl;
            USE(label__False_107);
            Label label_if_done_label_543_897_impl(this, {});
            Label* label_if_done_label_543_897 = &label_if_done_label_543_897_impl;
            USE(label_if_done_label_543_897);
            TNode<BoolT> t384 = UncheckedCast<BoolT>(IsElementsKindGreaterThan(implicit_cast<TNode<Int32T>>((*elementsKind_542)), implicit_cast<ElementsKind>(HOLEY_ELEMENTS)));
            USE(implicit_cast<TNode<BoolT>>(t384));
            Branch(implicit_cast<TNode<BoolT>>(t384), label__True_106, label__False_107);
            if (label__True_106->is_used())
            {
              BIND(label__True_106);
              // ../src/builtins/array-foreach.tq:122:68
              {
                // ../src/builtins/array-foreach.tq:123:9
                VisitAllElements18ATFixedDoubleArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSArray>>((*a_540)), implicit_cast<TNode<Smi>>((*smi_len_539)), implicit_cast<TNode<JSReceiver>>(p_callbackfn), implicit_cast<TNode<Object>>(p_thisArg), label_Bailout_100, Bailout0_127);
              }
              Goto(label_if_done_label_543_897);
            }
            if (label__False_107->is_used())
            {
              BIND(label__False_107);
              // ../src/builtins/array-foreach.tq:126:14
              {
                // ../src/builtins/array-foreach.tq:127:9
                VisitAllElements12ATFixedArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSArray>>((*a_540)), implicit_cast<TNode<Smi>>((*smi_len_539)), implicit_cast<TNode<JSReceiver>>(p_callbackfn), implicit_cast<TNode<Object>>(p_thisArg), label_Bailout_100, Bailout0_127);
              }
              Goto(label_if_done_label_543_897);
            }
            BIND(label_if_done_label_543_897);
          }
        }
        Goto(label_try_done_537_895);
      }
      if (label_Slow_101->is_used())
      {
        BIND(label_Slow_101);
        // ../src/builtins/array-foreach.tq:131:16
        {
          // ../src/builtins/array-foreach.tq:132:7
          *Bailout0_127 = implicit_cast<TNode<Smi>>((*k_129).value());
          Goto(label_Bailout_100);
        }
      }
      BIND(label_try_done_537_895);
    }
    // ../src/builtins/array-foreach.tq:134:5
    *_return_128 = implicit_cast<TNode<Object>>(Undefined());
    Goto(label_macro_end_894);
  }
  BIND(label_macro_end_894);
  return implicit_cast<TNode<Object>>((*_return_128).value());
}

TF_BUILTIN(ArrayForEach, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  CodeStubArguments arguments_impl(this, ChangeInt32ToIntPtr(argc));
  TNode<Object> p_receiver = arguments_impl.GetReceiver();
  auto arguments = &arguments_impl;
  USE(arguments);
  USE(p_receiver);
  // ../src/builtins/array-foreach.tq:139:65
  {
    // ../src/builtins/array-foreach.tq:140:5
    {
      Label label_try_done_544_898_impl(this);
      Label* label_try_done_544_898 = &label_try_done_544_898_impl;
      USE(label_try_done_544_898);
      Label label_TypeError_108_impl(this);
      Label* label_TypeError_108 = &label_TypeError_108_impl;
      USE(label_TypeError_108);
      Label label_NullOrUndefinedError_109_impl(this);
      Label* label_NullOrUndefinedError_109 = &label_NullOrUndefinedError_109_impl;
      USE(label_NullOrUndefinedError_109);
      Label label_try_begin_545_899_impl(this);
      Label* label_try_begin_545_899 = &label_try_begin_545_899_impl;
      USE(label_try_begin_545_899);
      Goto(label_try_begin_545_899);
      if (label_try_begin_545_899->is_used())
      {
        BIND(label_try_begin_545_899);
        // ../src/builtins/array-foreach.tq:140:9
        {
          // ../src/builtins/array-foreach.tq:141:7
          {
            Label label__True_110_impl(this);
            Label* label__True_110 = &label__True_110_impl;
            USE(label__True_110);
            Label label__False_111_impl(this, {});
            Label* label__False_111 = &label__False_111_impl;
            USE(label__False_111);
            TNode<BoolT> t385 = UncheckedCast<BoolT>(IsNullOrUndefined(implicit_cast<TNode<Object>>(p_receiver)));
            USE(implicit_cast<TNode<BoolT>>(t385));
            Branch(implicit_cast<TNode<BoolT>>(t385), label__True_110, label__False_111);
            if (label__True_110->is_used())
            {
              BIND(label__True_110);
              // ../src/builtins/array-foreach.tq:141:40
              {
                // ../src/builtins/array-foreach.tq:142:9
                Goto(label_NullOrUndefinedError_109);
              }
            }
            BIND(label__False_111);
          }
          // ../src/builtins/array-foreach.tq:146:7
          TNode<JSReceiver> t386 = UncheckedCast<JSReceiver>(ToObject_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_receiver)));
          USE(implicit_cast<TNode<JSReceiver>>(t386));
          TNode<JSReceiver> o_546_impl;
          auto o_546 = &o_546_impl;
          USE(o_546);
          *o_546 = implicit_cast<TNode<JSReceiver>>(t386);
          // ../src/builtins/array-foreach.tq:149:7
          TNode<Number> t387 = UncheckedCast<Number>(GetLengthProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*o_546))));
          USE(implicit_cast<TNode<Number>>(t387));
          TNode<Number> len_547_impl;
          auto len_547 = &len_547_impl;
          USE(len_547);
          *len_547 = implicit_cast<TNode<Number>>(t387);
          // ../src/builtins/array-foreach.tq:152:7
          {
            Label label__True_112_impl(this);
            Label* label__True_112 = &label__True_112_impl;
            USE(label__True_112);
            Label label__False_113_impl(this, {});
            Label* label__False_113 = &label__False_113_impl;
            USE(label__False_113);
            TNode<IntPtrT> t388 = UncheckedCast<IntPtrT>(GetArgumentsLength(implicit_cast<CodeStubArguments*>(arguments)));
            int31_t t389 = 0;
            TNode<IntPtrT> t390 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t389)));
            TNode<BoolT> t391 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<IntPtrT>>(t388), implicit_cast<TNode<IntPtrT>>(t390)));
            USE(implicit_cast<TNode<BoolT>>(t391));
            Branch(implicit_cast<TNode<BoolT>>(t391), label__True_112, label__False_113);
            if (label__True_112->is_used())
            {
              BIND(label__True_112);
              // ../src/builtins/array-foreach.tq:152:34
              {
                // ../src/builtins/array-foreach.tq:153:9
                Goto(label_TypeError_108);
              }
            }
            BIND(label__False_113);
          }
          // ../src/builtins/array-foreach.tq:155:7
          int31_t t392 = 0;
          TNode<IntPtrT> t393 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t392)));
          TNode<Object> t394 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t393)));
          TNode<JSReceiver> t395 = UncheckedCast<JSReceiver>(cast45UT17ATJSBoundFunction12ATJSFunction9ATJSProxy(implicit_cast<TNode<Object>>(t394), label_TypeError_108));
          USE(implicit_cast<TNode<JSReceiver>>(t395));
          TNode<JSReceiver> callbackfn_548_impl;
          auto callbackfn_548 = &callbackfn_548_impl;
          USE(callbackfn_548);
          *callbackfn_548 = implicit_cast<TNode<JSReceiver>>(t395);
          // ../src/builtins/array-foreach.tq:159:7
          auto t396 = [=]() {
            int31_t t398 = 1;
            TNode<IntPtrT> t399 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t398)));
            TNode<Object> t400 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t399)));
            return implicit_cast<TNode<Object>>(t400);
          };
          auto t397 = [=]() {
            return implicit_cast<TNode<Oddball>>(Undefined());
          };
          TVARIABLE(Object, t401_549_impl);
          auto t401_549 = &t401_549_impl;
          USE(t401_549);
          {
            Label label__True_114_impl(this);
            Label* label__True_114 = &label__True_114_impl;
            USE(label__True_114);
            Label label__False_115_impl(this);
            Label* label__False_115 = &label__False_115_impl;
            USE(label__False_115);
            Label label__done_550_900_impl(this, {t401_549});
            Label* label__done_550_900 = &label__done_550_900_impl;
            USE(label__done_550_900);
            TNode<IntPtrT> t402 = UncheckedCast<IntPtrT>(GetArgumentsLength(implicit_cast<CodeStubArguments*>(arguments)));
            int31_t t403 = 1;
            TNode<IntPtrT> t404 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t403)));
            TNode<BoolT> t405 = UncheckedCast<BoolT>(IntPtrGreaterThan(implicit_cast<TNode<IntPtrT>>(t402), implicit_cast<TNode<IntPtrT>>(t404)));
            USE(implicit_cast<TNode<BoolT>>(t405));
            Branch(implicit_cast<TNode<BoolT>>(t405), label__True_114, label__False_115);
            BIND(label__True_114);
                        *t401_549 = implicit_cast<TNode<Object>>(t396());
            Goto(label__done_550_900);
            BIND(label__False_115);
                        *t401_549 = implicit_cast<TNode<Object>>(t397());
            Goto(label__done_550_900);
            BIND(label__done_550_900);
          }
          TNode<Object> thisArg_551_impl;
          auto thisArg_551 = &thisArg_551_impl;
          USE(thisArg_551);
          *thisArg_551 = implicit_cast<TNode<Object>>((*t401_549).value());
          // ../src/builtins/array-foreach.tq:162:7
          int31_t t406 = 0;
          TVARIABLE(Smi, k_130_impl);
          auto k_130 = &k_130_impl;
          USE(k_130);
          TNode<Smi> t407 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t406)));
          *k_130 = implicit_cast<TNode<Smi>>(t407);
          // ../src/builtins/array-foreach.tq:163:7
          {
            Label label_try_done_552_901_impl(this);
            Label* label_try_done_552_901 = &label_try_done_552_901_impl;
            USE(label_try_done_552_901);
            Label label_Bailout_116_impl(this);
            Label* label_Bailout_116 = &label_Bailout_116_impl;
            USE(label_Bailout_116);
            TVARIABLE(Smi, k_value_131_impl);
            auto k_value_131 = &k_value_131_impl;
            USE(k_value_131);
            Label label_try_begin_553_902_impl(this);
            Label* label_try_begin_553_902 = &label_try_begin_553_902_impl;
            USE(label_try_begin_553_902);
            Goto(label_try_begin_553_902);
            if (label_try_begin_553_902->is_used())
            {
              BIND(label_try_begin_553_902);
              // ../src/builtins/array-foreach.tq:163:11
              {
                // ../src/builtins/array-foreach.tq:164:9
                TNode<Object> t408 = UncheckedCast<Object>(FastArrayForEach(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*o_546)), implicit_cast<TNode<Number>>((*len_547)), implicit_cast<TNode<JSReceiver>>((*callbackfn_548)), implicit_cast<TNode<Object>>((*thisArg_551)), label_Bailout_116, k_value_131));
                USE(implicit_cast<TNode<Object>>(t408));
                arguments->PopAndReturn(implicit_cast<TNode<Object>>(t408));
              }
            }
            if (label_Bailout_116->is_used())
            {
              BIND(label_Bailout_116);
              // ../src/builtins/array-foreach.tq:167:35
              {
                // ../src/builtins/array-foreach.tq:168:9
                *k_130 = implicit_cast<TNode<Smi>>((*k_value_131).value());
              }
              Goto(label_try_done_552_901);
            }
            BIND(label_try_done_552_901);
          }
          // ../src/builtins/array-foreach.tq:171:7
          TNode<Object> t409 = UncheckedCast<Object>(ArrayForEachTorqueContinuation(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*o_546)), implicit_cast<TNode<Number>>((*len_547)), implicit_cast<TNode<JSReceiver>>((*callbackfn_548)), implicit_cast<TNode<Object>>((*thisArg_551)), implicit_cast<TNode<Smi>>((*k_130).value())));
          USE(implicit_cast<TNode<Object>>(t409));
          arguments->PopAndReturn(implicit_cast<TNode<Object>>(t409));
        }
      }
      if (label_TypeError_108->is_used())
      {
        BIND(label_TypeError_108);
        // ../src/builtins/array-foreach.tq:174:21
        {
          // ../src/builtins/array-foreach.tq:175:7
          int31_t t410 = 0;
          TNode<IntPtrT> t411 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t410)));
          TNode<Object> t412 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t411)));
          ThrowTypeError(implicit_cast<TNode<Context>>(p_context), implicit_cast<MessageTemplate::Template>(MessageTemplate::kCalledNonCallable), implicit_cast<TNode<Object>>(t412));
        }
      }
      if (label_NullOrUndefinedError_109->is_used())
      {
        BIND(label_NullOrUndefinedError_109);
        // ../src/builtins/array-foreach.tq:177:32
        {
          // ../src/builtins/array-foreach.tq:178:7
          const char* t413 = "Array.prototype.forEach";
          TNode<Object> t414 = UncheckedCast<Object>(from_constexpr22UT12ATHeapObject5ATSmi(implicit_cast<const char*>(t413)));
          ThrowTypeError(implicit_cast<TNode<Context>>(p_context), implicit_cast<MessageTemplate::Template>(MessageTemplate::kCalledOnNullOrUndefined), implicit_cast<TNode<Object>>(t414));
        }
      }
    }
  }
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::LoadElement23ATFastPackedSmiElements5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index) {
  TVARIABLE(Smi, _return_132_impl);
  auto _return_132 = &_return_132_impl;
  USE(_return_132);
  Label label_macro_end_903_impl(this, {_return_132});
  Label* label_macro_end_903 = &label_macro_end_903_impl;
  USE(label_macro_end_903);
  // ../src/builtins/array-reverse.tq:10:50
  {
    // ../src/builtins/array-reverse.tq:11:5
    TNode<FixedArray> t415 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedArray>>(t415));
    TNode<FixedArray> elems_554_impl;
    auto elems_554 = &elems_554_impl;
    USE(elems_554);
    *elems_554 = implicit_cast<TNode<FixedArray>>(t415);
    // ../src/builtins/array-reverse.tq:12:5
    TNode<Object> t416 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*elems_554)), implicit_cast<TNode<Smi>>(p_index)));
    TNode<Smi> t417 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(t416)));
    USE(implicit_cast<TNode<Smi>>(t417));
    *_return_132 = implicit_cast<TNode<Smi>>(t417);
    Goto(label_macro_end_903);
  }
  BIND(label_macro_end_903);
  return implicit_cast<TNode<Smi>>((*_return_132).value());
}

compiler::TNode<Object> ArrayBuiltinsFromDSLAssembler::LoadElement26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index) {
  TVARIABLE(Object, _return_133_impl);
  auto _return_133 = &_return_133_impl;
  USE(_return_133);
  Label label_macro_end_904_impl(this, {_return_133});
  Label* label_macro_end_904 = &label_macro_end_904_impl;
  USE(label_macro_end_904);
  // ../src/builtins/array-reverse.tq:16:53
  {
    // ../src/builtins/array-reverse.tq:17:5
    TNode<FixedArray> t418 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedArray>>(t418));
    TNode<FixedArray> elems_555_impl;
    auto elems_555 = &elems_555_impl;
    USE(elems_555);
    *elems_555 = implicit_cast<TNode<FixedArray>>(t418);
    // ../src/builtins/array-reverse.tq:18:5
    TNode<Object> t419 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*elems_555)), implicit_cast<TNode<Smi>>(p_index)));
    *_return_133 = implicit_cast<TNode<Object>>(t419);
    Goto(label_macro_end_904);
  }
  BIND(label_macro_end_904);
  return implicit_cast<TNode<Object>>((*_return_133).value());
}

compiler::TNode<Float64T> ArrayBuiltinsFromDSLAssembler::LoadElement26ATFastPackedDoubleElements9ATfloat64(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index) {
  TVARIABLE(Float64T, _return_134_impl);
  auto _return_134 = &_return_134_impl;
  USE(_return_134);
  Label label_macro_end_905_impl(this, {_return_134});
  Label* label_macro_end_905 = &label_macro_end_905_impl;
  USE(label_macro_end_905);
  // ../src/builtins/array-reverse.tq:22:54
  {
    // ../src/builtins/array-reverse.tq:23:5
    {
      Label label_try_done_556_906_impl(this);
      Label* label_try_done_556_906 = &label_try_done_556_906_impl;
      USE(label_try_done_556_906);
      Label label_Hole_117_impl(this);
      Label* label_Hole_117 = &label_Hole_117_impl;
      USE(label_Hole_117);
      Label label_try_begin_557_907_impl(this);
      Label* label_try_begin_557_907 = &label_try_begin_557_907_impl;
      USE(label_try_begin_557_907);
      Goto(label_try_begin_557_907);
      if (label_try_begin_557_907->is_used())
      {
        BIND(label_try_begin_557_907);
        // ../src/builtins/array-reverse.tq:23:9
        {
          // ../src/builtins/array-reverse.tq:24:7
          TNode<FixedDoubleArray> t420 = UncheckedCast<FixedDoubleArray>(unsafe_cast18ATFixedDoubleArray(implicit_cast<TNode<Object>>(p_elements)));
          USE(implicit_cast<TNode<FixedDoubleArray>>(t420));
          TNode<FixedDoubleArray> elems_558_impl;
          auto elems_558 = &elems_558_impl;
          USE(elems_558);
          *elems_558 = implicit_cast<TNode<FixedDoubleArray>>(t420);
          // ../src/builtins/array-reverse.tq:25:7
          TNode<Float64T> t421 = UncheckedCast<Float64T>(LoadDoubleWithHoleCheck(implicit_cast<TNode<FixedDoubleArray>>((*elems_558)), implicit_cast<TNode<Smi>>(p_index), label_Hole_117));
          USE(implicit_cast<TNode<Float64T>>(t421));
          *_return_134 = implicit_cast<TNode<Float64T>>(t421);
          Goto(label_macro_end_905);
        }
      }
      if (label_Hole_117->is_used())
      {
        BIND(label_Hole_117);
        // ../src/builtins/array-reverse.tq:27:16
        {
          // ../src/builtins/array-reverse.tq:30:7
          Unreachable();
        }
      }
    }
  }
  BIND(label_macro_end_905);
  return implicit_cast<TNode<Float64T>>((*_return_134).value());
}

void ArrayBuiltinsFromDSLAssembler::StoreElement23ATFastPackedSmiElements5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, TNode<Smi> p_value) {
  Label label_macro_end_908_impl(this, {});
  Label* label_macro_end_908 = &label_macro_end_908_impl;
  USE(label_macro_end_908);
  // ../src/builtins/array-reverse.tq:38:57
  {
    // ../src/builtins/array-reverse.tq:39:5
    TNode<FixedArray> t422 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedArray>>(t422));
    TNode<FixedArray> elems_559_impl;
    auto elems_559 = &elems_559_impl;
    USE(elems_559);
    *elems_559 = implicit_cast<TNode<FixedArray>>(t422);
    // ../src/builtins/array-reverse.tq:40:5
    StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>((*elems_559)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<WriteBarrierMode>(SKIP_WRITE_BARRIER));
  }
}

void ArrayBuiltinsFromDSLAssembler::StoreElement26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, TNode<Object> p_value) {
  Label label_macro_end_909_impl(this, {});
  Label* label_macro_end_909 = &label_macro_end_909_impl;
  USE(label_macro_end_909);
  // ../src/builtins/array-reverse.tq:44:60
  {
    // ../src/builtins/array-reverse.tq:45:5
    TNode<FixedArray> t423 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedArray>>(t423));
    TNode<FixedArray> elems_560_impl;
    auto elems_560 = &elems_560_impl;
    USE(elems_560);
    *elems_560 = implicit_cast<TNode<FixedArray>>(t423);
    // ../src/builtins/array-reverse.tq:46:5
    StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>((*elems_560)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value));
  }
}

void ArrayBuiltinsFromDSLAssembler::StoreElement26ATFastPackedDoubleElements9ATfloat64(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, TNode<Float64T> p_value) {
  Label label_macro_end_910_impl(this, {});
  Label* label_macro_end_910 = &label_macro_end_910_impl;
  USE(label_macro_end_910);
  // ../src/builtins/array-reverse.tq:50:61
  {
    // ../src/builtins/array-reverse.tq:51:5
    TNode<FixedDoubleArray> t424 = UncheckedCast<FixedDoubleArray>(unsafe_cast18ATFixedDoubleArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedDoubleArray>>(t424));
    TNode<FixedDoubleArray> elems_561_impl;
    auto elems_561 = &elems_561_impl;
    USE(elems_561);
    *elems_561 = implicit_cast<TNode<FixedDoubleArray>>(t424);
    // ../src/builtins/array-reverse.tq:53:5
    // ../src/builtins/array-reverse.tq:54:5
    StoreFixedDoubleArrayElementWithSmiIndex(implicit_cast<TNode<FixedDoubleArray>>((*elems_561)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Float64T>>(p_value));
  }
}

compiler::TNode<Object> ArrayBuiltinsFromDSLAssembler::GenericArrayReverse(TNode<Context> p_context, TNode<Object> p_receiver) {
  TVARIABLE(Object, _return_135_impl);
  auto _return_135 = &_return_135_impl;
  USE(_return_135);
  Label label_macro_end_911_impl(this, {_return_135});
  Label* label_macro_end_911 = &label_macro_end_911_impl;
  USE(label_macro_end_911);
  // ../src/builtins/array-reverse.tq:75:73
  {
    // ../src/builtins/array-reverse.tq:77:5
    TNode<JSReceiver> t425 = UncheckedCast<JSReceiver>(ToObject_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_receiver)));
    USE(implicit_cast<TNode<JSReceiver>>(t425));
    TNode<JSReceiver> object_562_impl;
    auto object_562 = &object_562_impl;
    USE(object_562);
    *object_562 = implicit_cast<TNode<JSReceiver>>(t425);
    // ../src/builtins/array-reverse.tq:80:5
    TNode<Number> t426 = UncheckedCast<Number>(GetLengthProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_562))));
    USE(implicit_cast<TNode<Number>>(t426));
    TNode<Number> length_563_impl;
    auto length_563 = &length_563_impl;
    USE(length_563);
    *length_563 = implicit_cast<TNode<Number>>(t426);
    // ../src/builtins/array-reverse.tq:89:5
    int31_t t427 = 0;
    TVARIABLE(Number, lower_136_impl);
    auto lower_136 = &lower_136_impl;
    USE(lower_136);
    TNode<Number> t428 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t427)));
    *lower_136 = implicit_cast<TNode<Number>>(t428);
    // ../src/builtins/array-reverse.tq:90:5
    int31_t t429 = 1;
    TNode<Number> t430 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t429)));
    TNode<Number> t431 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*length_563)), implicit_cast<TNode<Number>>(t430)));
    USE(implicit_cast<TNode<Number>>(t431));
    TVARIABLE(Number, upper_137_impl);
    auto upper_137 = &upper_137_impl;
    USE(upper_137);
    *upper_137 = implicit_cast<TNode<Number>>(t431);
    // ../src/builtins/array-reverse.tq:92:5
    {
      Label label__True_118_impl(this);
      Label* label__True_118 = &label__True_118_impl;
      USE(label__True_118);
      Label label__False_119_impl(this);
      Label* label__False_119 = &label__False_119_impl;
      USE(label__False_119);
      Label label_header_564_912_impl(this, {lower_136, upper_137});
      Label* label_header_564_912 = &label_header_564_912_impl;
      USE(label_header_564_912);
      Goto(label_header_564_912);
      BIND(label_header_564_912);
      BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*lower_136).value()), implicit_cast<TNode<Number>>((*upper_137).value()), label__True_118, label__False_119);
      if (label__True_118->is_used())
      {
        BIND(label__True_118);
        // ../src/builtins/array-reverse.tq:92:27
        {
          // ../src/builtins/array-reverse.tq:93:7
          TVARIABLE(Object, lower_value_138_impl);
          auto lower_value_138 = &lower_value_138_impl;
          USE(lower_value_138);
          *lower_value_138 = implicit_cast<TNode<Object>>(Undefined());
          // ../src/builtins/array-reverse.tq:94:7
          TVARIABLE(Object, upper_value_139_impl);
          auto upper_value_139 = &upper_value_139_impl;
          USE(upper_value_139);
          *upper_value_139 = implicit_cast<TNode<Object>>(Undefined());
          // ../src/builtins/array-reverse.tq:99:7
          TNode<Oddball> t432 = UncheckedCast<Oddball>(CallBuiltin(Builtins::kHasProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*object_562)), implicit_cast<TNode<Object>>((*lower_136).value())));
          USE(implicit_cast<TNode<Oddball>>(t432));
          TNode<Oddball> lower_exists_565_impl;
          auto lower_exists_565 = &lower_exists_565_impl;
          USE(lower_exists_565);
          *lower_exists_565 = implicit_cast<TNode<Oddball>>(t432);
          // ../src/builtins/array-reverse.tq:102:7
          {
            Label label__True_120_impl(this);
            Label* label__True_120 = &label__True_120_impl;
            USE(label__True_120);
            Label label__False_121_impl(this, {lower_value_138});
            Label* label__False_121 = &label__False_121_impl;
            USE(label__False_121);
            TNode<BoolT> t433 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*lower_exists_565)), implicit_cast<TNode<Object>>(True())));
            USE(implicit_cast<TNode<BoolT>>(t433));
            Branch(implicit_cast<TNode<BoolT>>(t433), label__True_120, label__False_121);
            if (label__True_120->is_used())
            {
              BIND(label__True_120);
              // ../src/builtins/array-reverse.tq:102:33
              {
                // ../src/builtins/array-reverse.tq:104:9
                TNode<Object> t434 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_562)), implicit_cast<TNode<Object>>((*lower_136).value())));
                USE(implicit_cast<TNode<Object>>(t434));
                *lower_value_138 = implicit_cast<TNode<Object>>(t434);
              }
              Goto(label__False_121);
            }
            BIND(label__False_121);
          }
          // ../src/builtins/array-reverse.tq:108:7
          TNode<Oddball> t435 = UncheckedCast<Oddball>(CallBuiltin(Builtins::kHasProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*object_562)), implicit_cast<TNode<Object>>((*upper_137).value())));
          USE(implicit_cast<TNode<Oddball>>(t435));
          TNode<Oddball> upper_exists_566_impl;
          auto upper_exists_566 = &upper_exists_566_impl;
          USE(upper_exists_566);
          *upper_exists_566 = implicit_cast<TNode<Oddball>>(t435);
          // ../src/builtins/array-reverse.tq:111:7
          {
            Label label__True_122_impl(this);
            Label* label__True_122 = &label__True_122_impl;
            USE(label__True_122);
            Label label__False_123_impl(this, {upper_value_139});
            Label* label__False_123 = &label__False_123_impl;
            USE(label__False_123);
            TNode<BoolT> t436 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*upper_exists_566)), implicit_cast<TNode<Object>>(True())));
            USE(implicit_cast<TNode<BoolT>>(t436));
            Branch(implicit_cast<TNode<BoolT>>(t436), label__True_122, label__False_123);
            if (label__True_122->is_used())
            {
              BIND(label__True_122);
              // ../src/builtins/array-reverse.tq:111:33
              {
                // ../src/builtins/array-reverse.tq:113:9
                TNode<Object> t437 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_562)), implicit_cast<TNode<Object>>((*upper_137).value())));
                USE(implicit_cast<TNode<Object>>(t437));
                *upper_value_139 = implicit_cast<TNode<Object>>(t437);
              }
              Goto(label__False_123);
            }
            BIND(label__False_123);
          }
          // ../src/builtins/array-reverse.tq:117:7
          {
            Label label__True_124_impl(this);
            Label* label__True_124 = &label__True_124_impl;
            USE(label__True_124);
            Label label__False_125_impl(this);
            Label* label__False_125 = &label__False_125_impl;
            USE(label__False_125);
            Label label_if_done_label_567_913_impl(this, {});
            Label* label_if_done_label_567_913 = &label_if_done_label_567_913_impl;
            USE(label_if_done_label_567_913);
            Label label__True_126_impl(this);
            Label* label__True_126 = &label__True_126_impl;
            USE(label__True_126);
            TNode<BoolT> t438 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*lower_exists_565)), implicit_cast<TNode<Object>>(True())));
            USE(implicit_cast<TNode<BoolT>>(t438));
            GotoIfNot(implicit_cast<TNode<BoolT>>(t438), label__False_125);
            TNode<BoolT> t439 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*upper_exists_566)), implicit_cast<TNode<Object>>(True())));
            USE(implicit_cast<TNode<BoolT>>(t439));
            Branch(implicit_cast<TNode<BoolT>>(t439), label__True_124, label__False_125);
            if (label__True_124->is_used())
            {
              BIND(label__True_124);
              // ../src/builtins/array-reverse.tq:117:57
              {
                // ../src/builtins/array-reverse.tq:119:9
                CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_562)), implicit_cast<TNode<Object>>((*lower_136).value()), implicit_cast<TNode<Object>>((*upper_value_139).value()));
                // ../src/builtins/array-reverse.tq:122:9
                CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_562)), implicit_cast<TNode<Object>>((*upper_137).value()), implicit_cast<TNode<Object>>((*lower_value_138).value()));
              }
              Goto(label_if_done_label_567_913);
            }
            if (label__False_125->is_used())
            {
              BIND(label__False_125);
              // ../src/builtins/array-reverse.tq:123:14
              {
                Label label__True_127_impl(this);
                Label* label__True_127 = &label__True_127_impl;
                USE(label__True_127);
                Label label__False_128_impl(this);
                Label* label__False_128 = &label__False_128_impl;
                USE(label__False_128);
                Label label_if_done_label_568_914_impl(this, {});
                Label* label_if_done_label_568_914 = &label_if_done_label_568_914_impl;
                USE(label_if_done_label_568_914);
                Label label__True_129_impl(this);
                Label* label__True_129 = &label__True_129_impl;
                USE(label__True_129);
                TNode<BoolT> t440 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*lower_exists_565)), implicit_cast<TNode<Object>>(False())));
                USE(implicit_cast<TNode<BoolT>>(t440));
                GotoIfNot(implicit_cast<TNode<BoolT>>(t440), label__False_128);
                TNode<BoolT> t441 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*upper_exists_566)), implicit_cast<TNode<Object>>(True())));
                USE(implicit_cast<TNode<BoolT>>(t441));
                Branch(implicit_cast<TNode<BoolT>>(t441), label__True_127, label__False_128);
                if (label__True_127->is_used())
                {
                  BIND(label__True_127);
                  // ../src/builtins/array-reverse.tq:123:65
                  {
                    // ../src/builtins/array-reverse.tq:125:9
                    CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_562)), implicit_cast<TNode<Object>>((*lower_136).value()), implicit_cast<TNode<Object>>((*upper_value_139).value()));
                    // ../src/builtins/array-reverse.tq:128:9
                    TNode<Smi> t442 = UncheckedCast<Smi>(from_constexpr14ATLanguageMode(implicit_cast<LanguageMode>(LanguageMode::kStrict)));
                    CallBuiltin(Builtins::kDeleteProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_562)), implicit_cast<TNode<Object>>((*upper_137).value()), implicit_cast<TNode<Smi>>(t442));
                  }
                  Goto(label_if_done_label_568_914);
                }
                if (label__False_128->is_used())
                {
                  BIND(label__False_128);
                  // ../src/builtins/array-reverse.tq:129:14
                  {
                    Label label__True_130_impl(this);
                    Label* label__True_130 = &label__True_130_impl;
                    USE(label__True_130);
                    Label label__False_131_impl(this, {});
                    Label* label__False_131 = &label__False_131_impl;
                    USE(label__False_131);
                    Label label__True_132_impl(this);
                    Label* label__True_132 = &label__True_132_impl;
                    USE(label__True_132);
                    TNode<BoolT> t443 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*lower_exists_565)), implicit_cast<TNode<Object>>(True())));
                    USE(implicit_cast<TNode<BoolT>>(t443));
                    GotoIfNot(implicit_cast<TNode<BoolT>>(t443), label__False_131);
                    TNode<BoolT> t444 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>((*upper_exists_566)), implicit_cast<TNode<Object>>(False())));
                    USE(implicit_cast<TNode<BoolT>>(t444));
                    Branch(implicit_cast<TNode<BoolT>>(t444), label__True_130, label__False_131);
                    if (label__True_130->is_used())
                    {
                      BIND(label__True_130);
                      // ../src/builtins/array-reverse.tq:129:65
                      {
                        // ../src/builtins/array-reverse.tq:131:9
                        TNode<Smi> t445 = UncheckedCast<Smi>(from_constexpr14ATLanguageMode(implicit_cast<LanguageMode>(LanguageMode::kStrict)));
                        CallBuiltin(Builtins::kDeleteProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_562)), implicit_cast<TNode<Object>>((*lower_136).value()), implicit_cast<TNode<Smi>>(t445));
                        // ../src/builtins/array-reverse.tq:134:9
                        CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*object_562)), implicit_cast<TNode<Object>>((*upper_137).value()), implicit_cast<TNode<Object>>((*lower_value_138).value()));
                      }
                      Goto(label__False_131);
                    }
                    BIND(label__False_131);
                  }
                  Goto(label_if_done_label_568_914);
                }
                BIND(label_if_done_label_568_914);
              }
              Goto(label_if_done_label_567_913);
            }
            BIND(label_if_done_label_567_913);
          }
          // ../src/builtins/array-reverse.tq:138:7
          TNode<Number> t446 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Number> t447 = UncheckedCast<Number>(NumberAdd(implicit_cast<TNode<Number>>((*lower_136).value()), implicit_cast<TNode<Number>>(t446)));
          *lower_136 = implicit_cast<TNode<Number>>(t447);
          // ../src/builtins/array-reverse.tq:139:7
          TNode<Number> t448 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Number> t449 = UncheckedCast<Number>(NumberSub(implicit_cast<TNode<Number>>((*upper_137).value()), implicit_cast<TNode<Number>>(t448)));
          *upper_137 = implicit_cast<TNode<Number>>(t449);
        }
        Goto(label_header_564_912);
      }
      BIND(label__False_119);
    }
    // ../src/builtins/array-reverse.tq:143:5
    *_return_135 = implicit_cast<TNode<Object>>((*object_562));
    Goto(label_macro_end_911);
  }
  BIND(label_macro_end_911);
  return implicit_cast<TNode<Object>>((*_return_135).value());
}

void ArrayBuiltinsFromDSLAssembler::EnsureWriteableFastElements(TNode<JSArray> p_array) {
  Label label_macro_end_915_impl(this, {});
  Label* label_macro_end_915 = &label_macro_end_915_impl;
  USE(label_macro_end_915);
  // ../src/builtins/array-reverse.tq:146:53
  {
    // ../src/builtins/array-reverse.tq:147:5
    TNode<FixedArrayBase> t450 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>(p_array)));
    TNode<FixedArrayBase> elements_569_impl;
    auto elements_569 = &elements_569_impl;
    USE(elements_569);
    *elements_569 = implicit_cast<TNode<FixedArrayBase>>(t450);
    // ../src/builtins/array-reverse.tq:148:5
    {
      Label label__True_133_impl(this);
      Label* label__True_133 = &label__True_133_impl;
      USE(label__True_133);
      Label label__False_134_impl(this, {});
      Label* label__False_134 = &label__False_134_impl;
      USE(label__False_134);
      TNode<Map> t451 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>((*elements_569))));
      TNode<BoolT> t452 = UncheckedCast<BoolT>(WordNotEqual(implicit_cast<TNode<Object>>(t451), implicit_cast<TNode<Object>>(kCOWMap())));
      USE(implicit_cast<TNode<BoolT>>(t452));
      Branch(implicit_cast<TNode<BoolT>>(t452), label__True_133, label__False_134);
      if (label__True_133->is_used())
      {
        BIND(label__True_133);
        // ../src/builtins/array-reverse.tq:148:34
        Goto(label_macro_end_915);
      }
      BIND(label__False_134);
    }
    // ../src/builtins/array-reverse.tq:152:5
    // ../src/builtins/array-reverse.tq:154:5
    TNode<Smi> t453 = UncheckedCast<Smi>(LoadFastJSArrayLength(implicit_cast<TNode<JSArray>>(p_array)));
    TNode<Smi> length_570_impl;
    auto length_570 = &length_570_impl;
    USE(length_570);
    *length_570 = implicit_cast<TNode<Smi>>(t453);
    // ../src/builtins/array-reverse.tq:155:5
    TNode<FixedArray> t454 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>((*elements_569))));
    USE(implicit_cast<TNode<FixedArray>>(t454));
    int31_t t455 = 0;
    TNode<Smi> t456 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t455)));
    TNode<FixedArray> t457 = UncheckedCast<FixedArray>(ExtractFixedArray(implicit_cast<TNode<FixedArray>>(t454), implicit_cast<TNode<Smi>>(t456), implicit_cast<TNode<Smi>>((*length_570)), implicit_cast<TNode<Smi>>((*length_570)), implicit_cast<ExtractFixedArrayFlags>(ExtractFixedArrayFlag::kFixedArrays)));
    USE(implicit_cast<TNode<FixedArray>>(t457));
    StoreElements(implicit_cast<TNode<JSObject>>(p_array), implicit_cast<TNode<FixedArrayBase>>(t457));
  }
  Goto(label_macro_end_915);
  BIND(label_macro_end_915);
}

void ArrayBuiltinsFromDSLAssembler::TryFastPackedArrayReverse(TNode<Object> p_receiver, Label* label_Slow_135) {
  Label label_macro_end_916_impl(this, {});
  Label* label_macro_end_916 = &label_macro_end_916_impl;
  USE(label_macro_end_916);
  // ../src/builtins/array-reverse.tq:159:65
  {
    // ../src/builtins/array-reverse.tq:160:5
    TNode<JSArray> t458 = UncheckedCast<JSArray>(cast9ATJSArray(implicit_cast<TNode<Object>>(p_receiver), label_Slow_135));
    USE(implicit_cast<TNode<JSArray>>(t458));
    TNode<JSArray> array_571_impl;
    auto array_571 = &array_571_impl;
    USE(array_571);
    *array_571 = implicit_cast<TNode<JSArray>>(t458);
    // ../src/builtins/array-reverse.tq:161:5
    EnsureWriteableFastElements(implicit_cast<TNode<JSArray>>((*array_571)));
    // ../src/builtins/array-reverse.tq:162:5
    // ../src/builtins/array-reverse.tq:164:5
    TNode<Map> t459 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>((*array_571))));
    TNode<Int32T> t460 = UncheckedCast<Int32T>(LoadMapElementsKind(implicit_cast<TNode<Map>>(t459)));
    TNode<Int32T> kind_572_impl;
    auto kind_572 = &kind_572_impl;
    USE(kind_572);
    *kind_572 = implicit_cast<TNode<Int32T>>(t460);
    // ../src/builtins/array-reverse.tq:165:5
    {
      Label label__True_136_impl(this);
      Label* label__True_136 = &label__True_136_impl;
      USE(label__True_136);
      Label label__False_137_impl(this);
      Label* label__False_137 = &label__False_137_impl;
      USE(label__False_137);
      Label label_if_done_label_573_917_impl(this, {});
      Label* label_if_done_label_573_917 = &label_if_done_label_573_917_impl;
      USE(label_if_done_label_573_917);
      TNode<Int32T> t461 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(PACKED_SMI_ELEMENTS)));
      TNode<BoolT> t462 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*kind_572)), implicit_cast<TNode<Int32T>>(t461)));
      USE(implicit_cast<TNode<BoolT>>(t462));
      Branch(implicit_cast<TNode<BoolT>>(t462), label__True_136, label__False_137);
      if (label__True_136->is_used())
      {
        BIND(label__True_136);
        // ../src/builtins/array-reverse.tq:165:38
        {
          // ../src/builtins/array-reverse.tq:166:7
          TNode<FixedArrayBase> t463 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>((*array_571))));
          TNode<Smi> t464 = UncheckedCast<Smi>(LoadFastJSArrayLength(implicit_cast<TNode<JSArray>>((*array_571))));
          FastPackedArrayReverse23ATFastPackedSmiElements5ATSmi(implicit_cast<TNode<FixedArrayBase>>(t463), implicit_cast<TNode<Smi>>(t464));
        }
        Goto(label_if_done_label_573_917);
      }
      if (label__False_137->is_used())
      {
        BIND(label__False_137);
        // ../src/builtins/array-reverse.tq:168:12
        {
          Label label__True_138_impl(this);
          Label* label__True_138 = &label__True_138_impl;
          USE(label__True_138);
          Label label__False_139_impl(this);
          Label* label__False_139 = &label__False_139_impl;
          USE(label__False_139);
          Label label_if_done_label_574_918_impl(this, {});
          Label* label_if_done_label_574_918 = &label_if_done_label_574_918_impl;
          USE(label_if_done_label_574_918);
          TNode<Int32T> t465 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(PACKED_ELEMENTS)));
          TNode<BoolT> t466 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*kind_572)), implicit_cast<TNode<Int32T>>(t465)));
          USE(implicit_cast<TNode<BoolT>>(t466));
          Branch(implicit_cast<TNode<BoolT>>(t466), label__True_138, label__False_139);
          if (label__True_138->is_used())
          {
            BIND(label__True_138);
            // ../src/builtins/array-reverse.tq:168:41
            {
              // ../src/builtins/array-reverse.tq:169:7
              TNode<FixedArrayBase> t467 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>((*array_571))));
              TNode<Smi> t468 = UncheckedCast<Smi>(LoadFastJSArrayLength(implicit_cast<TNode<JSArray>>((*array_571))));
              FastPackedArrayReverse26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(implicit_cast<TNode<FixedArrayBase>>(t467), implicit_cast<TNode<Smi>>(t468));
            }
            Goto(label_if_done_label_574_918);
          }
          if (label__False_139->is_used())
          {
            BIND(label__False_139);
            // ../src/builtins/array-reverse.tq:171:12
            {
              Label label__True_140_impl(this);
              Label* label__True_140 = &label__True_140_impl;
              USE(label__True_140);
              Label label__False_141_impl(this);
              Label* label__False_141 = &label__False_141_impl;
              USE(label__False_141);
              Label label_if_done_label_575_919_impl(this, {});
              Label* label_if_done_label_575_919 = &label_if_done_label_575_919_impl;
              USE(label_if_done_label_575_919);
              TNode<Int32T> t469 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(PACKED_DOUBLE_ELEMENTS)));
              TNode<BoolT> t470 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*kind_572)), implicit_cast<TNode<Int32T>>(t469)));
              USE(implicit_cast<TNode<BoolT>>(t470));
              Branch(implicit_cast<TNode<BoolT>>(t470), label__True_140, label__False_141);
              if (label__True_140->is_used())
              {
                BIND(label__True_140);
                // ../src/builtins/array-reverse.tq:171:48
                {
                  // ../src/builtins/array-reverse.tq:172:7
                  TNode<FixedArrayBase> t471 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>((*array_571))));
                  TNode<Smi> t472 = UncheckedCast<Smi>(LoadFastJSArrayLength(implicit_cast<TNode<JSArray>>((*array_571))));
                  FastPackedArrayReverse26ATFastPackedDoubleElements9ATfloat64(implicit_cast<TNode<FixedArrayBase>>(t471), implicit_cast<TNode<Smi>>(t472));
                }
                Goto(label_if_done_label_575_919);
              }
              if (label__False_141->is_used())
              {
                BIND(label__False_141);
                // ../src/builtins/array-reverse.tq:174:12
                {
                  // ../src/builtins/array-reverse.tq:175:7
                  Goto(label_Slow_135);
                }
              }
              BIND(label_if_done_label_575_919);
            }
            Goto(label_if_done_label_574_918);
          }
          BIND(label_if_done_label_574_918);
        }
        Goto(label_if_done_label_573_917);
      }
      BIND(label_if_done_label_573_917);
    }
  }
}

TF_BUILTIN(ArrayPrototypeReverse, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  CodeStubArguments arguments_impl(this, ChangeInt32ToIntPtr(argc));
  TNode<Object> p_receiver = arguments_impl.GetReceiver();
  auto arguments = &arguments_impl;
  USE(arguments);
  USE(p_receiver);
  // ../src/builtins/array-reverse.tq:181:65
  {
    // ../src/builtins/array-reverse.tq:182:5
    {
      Label label_try_done_576_920_impl(this);
      Label* label_try_done_576_920 = &label_try_done_576_920_impl;
      USE(label_try_done_576_920);
      Label label_Baseline_142_impl(this);
      Label* label_Baseline_142 = &label_Baseline_142_impl;
      USE(label_Baseline_142);
      Label label_try_begin_577_921_impl(this);
      Label* label_try_begin_577_921 = &label_try_begin_577_921_impl;
      USE(label_try_begin_577_921);
      Goto(label_try_begin_577_921);
      if (label_try_begin_577_921->is_used())
      {
        BIND(label_try_begin_577_921);
        // ../src/builtins/array-reverse.tq:182:9
        {
          // ../src/builtins/array-reverse.tq:183:7
          TryFastPackedArrayReverse(implicit_cast<TNode<Object>>(p_receiver), label_Baseline_142);
          // ../src/builtins/array-reverse.tq:184:7
          arguments->PopAndReturn(implicit_cast<TNode<Object>>(p_receiver));
        }
      }
      if (label_Baseline_142->is_used())
      {
        BIND(label_Baseline_142);
        // ../src/builtins/array-reverse.tq:186:20
        {
          // ../src/builtins/array-reverse.tq:187:7
          TNode<Object> t473 = UncheckedCast<Object>(GenericArrayReverse(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_receiver)));
          USE(implicit_cast<TNode<Object>>(t473));
          arguments->PopAndReturn(implicit_cast<TNode<Object>>(t473));
        }
      }
    }
  }
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::kGenericElementsAccessorId() {
  int31_t t1792 = 0;
  TNode<Smi> t1793 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t1792)));
  return implicit_cast<TNode<Smi>>(t1793);
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::kFastElementsAccessorId() {
  int31_t t1794 = 1;
  TNode<Smi> t1795 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t1794)));
  return implicit_cast<TNode<Smi>>(t1795);
}

int31_t ArrayBuiltinsFromDSLAssembler::kReceiverIdx() {
  int31_t t1796 = 0;
  return implicit_cast<int31_t>(t1796);
}

int31_t ArrayBuiltinsFromDSLAssembler::kInitialReceiverMapIdx() {
  int31_t t1797 = 1;
  return implicit_cast<int31_t>(t1797);
}

int31_t ArrayBuiltinsFromDSLAssembler::kInitialReceiverLengthIdx() {
  int31_t t1798 = 2;
  return implicit_cast<int31_t>(t1798);
}

int31_t ArrayBuiltinsFromDSLAssembler::kUserCmpFnIdx() {
  int31_t t1799 = 3;
  return implicit_cast<int31_t>(t1799);
}

int31_t ArrayBuiltinsFromDSLAssembler::kSortComparePtrIdx() {
  int31_t t1800 = 4;
  return implicit_cast<int31_t>(t1800);
}

int31_t ArrayBuiltinsFromDSLAssembler::kLoadFnIdx() {
  int31_t t1801 = 5;
  return implicit_cast<int31_t>(t1801);
}

int31_t ArrayBuiltinsFromDSLAssembler::kStoreFnIdx() {
  int31_t t1802 = 6;
  return implicit_cast<int31_t>(t1802);
}

int31_t ArrayBuiltinsFromDSLAssembler::kCanUseSameAccessorFnIdx() {
  int31_t t1803 = 7;
  return implicit_cast<int31_t>(t1803);
}

int31_t ArrayBuiltinsFromDSLAssembler::kBailoutStatusIdx() {
  int31_t t1804 = 8;
  return implicit_cast<int31_t>(t1804);
}

int31_t ArrayBuiltinsFromDSLAssembler::kMinGallopIdx() {
  int31_t t1805 = 9;
  return implicit_cast<int31_t>(t1805);
}

int31_t ArrayBuiltinsFromDSLAssembler::kPendingRunsSizeIdx() {
  int31_t t1806 = 10;
  return implicit_cast<int31_t>(t1806);
}

int31_t ArrayBuiltinsFromDSLAssembler::kPendingRunsIdx() {
  int31_t t1807 = 11;
  return implicit_cast<int31_t>(t1807);
}

int31_t ArrayBuiltinsFromDSLAssembler::kTempArraySizeIdx() {
  int31_t t1808 = 12;
  return implicit_cast<int31_t>(t1808);
}

int31_t ArrayBuiltinsFromDSLAssembler::kTempArrayIdx() {
  int31_t t1809 = 13;
  return implicit_cast<int31_t>(t1809);
}

int31_t ArrayBuiltinsFromDSLAssembler::kAccessorIdx() {
  int31_t t1810 = 14;
  return implicit_cast<int31_t>(t1810);
}

compiler::TNode<IntPtrT> ArrayBuiltinsFromDSLAssembler::kSortStateSize() {
  int31_t t1811 = 15;
  TNode<IntPtrT> t1812 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t1811)));
  return implicit_cast<TNode<IntPtrT>>(t1812);
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::kFailure() {
  int31_t t1813 = -1;
  TNode<Smi> t1814 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t1813)));
  return implicit_cast<TNode<Smi>>(t1814);
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::kSuccess() {
  int31_t t1815 = 0;
  TNode<Smi> t1816 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t1815)));
  return implicit_cast<TNode<Smi>>(t1816);
}

int31_t ArrayBuiltinsFromDSLAssembler::kMaxMergePending() {
  int31_t t1817 = 85;
  return implicit_cast<int31_t>(t1817);
}

int31_t ArrayBuiltinsFromDSLAssembler::kMinGallopWins() {
  int31_t t1818 = 7;
  return implicit_cast<int31_t>(t1818);
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::kSortStateTempSize() {
  int31_t t1819 = 32;
  TNode<Smi> t1820 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t1819)));
  return implicit_cast<TNode<Smi>>(t1820);
}

TF_BUILTIN(Load23ATFastPackedSmiElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../third_party/v8/builtins/array-sort.tq:135:27
  {
    // ../third_party/v8/builtins/array-sort.tq:136:5
    TNode<FixedArray> t1821 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedArray>>(t1821));
    TNode<FixedArray> elems_734_impl;
    auto elems_734 = &elems_734_impl;
    USE(elems_734);
    *elems_734 = implicit_cast<TNode<FixedArray>>(t1821);
    // ../third_party/v8/builtins/array-sort.tq:137:5
    TNode<Object> t1822 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*elems_734)), implicit_cast<TNode<Smi>>(p_index)));
    Return(implicit_cast<TNode<Object>>(t1822));
  }
}

TF_BUILTIN(Load25ATFastSmiOrObjectElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../third_party/v8/builtins/array-sort.tq:142:27
  {
    // ../third_party/v8/builtins/array-sort.tq:143:5
    TNode<FixedArray> t1823 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedArray>>(t1823));
    TNode<FixedArray> elems_735_impl;
    auto elems_735 = &elems_735_impl;
    USE(elems_735);
    *elems_735 = implicit_cast<TNode<FixedArray>>(t1823);
    // ../third_party/v8/builtins/array-sort.tq:144:5
    TNode<Object> t1824 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*elems_735)), implicit_cast<TNode<Smi>>(p_index)));
    TNode<Object> result_736_impl;
    auto result_736 = &result_736_impl;
    USE(result_736);
    *result_736 = implicit_cast<TNode<Object>>(t1824);
    // ../third_party/v8/builtins/array-sort.tq:145:5
    {
      Label label__True_467_impl(this);
      Label* label__True_467 = &label__True_467_impl;
      USE(label__True_467);
      Label label__False_468_impl(this, {});
      Label* label__False_468 = &label__False_468_impl;
      USE(label__False_468);
      TNode<BoolT> t1825 = UncheckedCast<BoolT>(IsTheHole(implicit_cast<TNode<Object>>((*result_736))));
      USE(implicit_cast<TNode<BoolT>>(t1825));
      Branch(implicit_cast<TNode<BoolT>>(t1825), label__True_467, label__False_468);
      if (label__True_467->is_used())
      {
        BIND(label__True_467);
        // ../third_party/v8/builtins/array-sort.tq:145:28
        {
          // ../third_party/v8/builtins/array-sort.tq:149:7
          TNode<Smi> t1826 = UncheckedCast<Smi>(Failure(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t1826));
          Return(implicit_cast<TNode<Object>>(t1826));
        }
      }
      BIND(label__False_468);
    }
    // ../third_party/v8/builtins/array-sort.tq:151:5
    Return(implicit_cast<TNode<Object>>((*result_736)));
  }
}

TF_BUILTIN(Load20ATFastDoubleElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../third_party/v8/builtins/array-sort.tq:156:27
  {
    // ../third_party/v8/builtins/array-sort.tq:157:5
    {
      Label label_try_done_737_1047_impl(this);
      Label* label_try_done_737_1047 = &label_try_done_737_1047_impl;
      USE(label_try_done_737_1047);
      Label label_Bailout_469_impl(this);
      Label* label_Bailout_469 = &label_Bailout_469_impl;
      USE(label_Bailout_469);
      Label label_try_begin_738_1048_impl(this);
      Label* label_try_begin_738_1048 = &label_try_begin_738_1048_impl;
      USE(label_try_begin_738_1048);
      Goto(label_try_begin_738_1048);
      if (label_try_begin_738_1048->is_used())
      {
        BIND(label_try_begin_738_1048);
        // ../third_party/v8/builtins/array-sort.tq:157:9
        {
          // ../third_party/v8/builtins/array-sort.tq:158:7
          TNode<FixedDoubleArray> t1827 = UncheckedCast<FixedDoubleArray>(unsafe_cast18ATFixedDoubleArray(implicit_cast<TNode<Object>>(p_elements)));
          USE(implicit_cast<TNode<FixedDoubleArray>>(t1827));
          TNode<FixedDoubleArray> elems_739_impl;
          auto elems_739 = &elems_739_impl;
          USE(elems_739);
          *elems_739 = implicit_cast<TNode<FixedDoubleArray>>(t1827);
          // ../third_party/v8/builtins/array-sort.tq:159:7
          TNode<Float64T> t1828 = UncheckedCast<Float64T>(LoadDoubleWithHoleCheck(implicit_cast<TNode<FixedDoubleArray>>((*elems_739)), implicit_cast<TNode<Smi>>(p_index), label_Bailout_469));
          USE(implicit_cast<TNode<Float64T>>(t1828));
          TNode<Float64T> value_740_impl;
          auto value_740 = &value_740_impl;
          USE(value_740);
          *value_740 = implicit_cast<TNode<Float64T>>(t1828);
          // ../third_party/v8/builtins/array-sort.tq:161:7
          TNode<HeapNumber> t1829 = UncheckedCast<HeapNumber>(AllocateHeapNumberWithValue(implicit_cast<TNode<Float64T>>((*value_740))));
          USE(implicit_cast<TNode<HeapNumber>>(t1829));
          Return(implicit_cast<TNode<Object>>(t1829));
        }
      }
      if (label_Bailout_469->is_used())
      {
        BIND(label_Bailout_469);
        // ../third_party/v8/builtins/array-sort.tq:163:19
        {
          // ../third_party/v8/builtins/array-sort.tq:167:7
          TNode<Smi> t1830 = UncheckedCast<Smi>(Failure(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t1830));
          Return(implicit_cast<TNode<Object>>(t1830));
        }
      }
    }
  }
}

TF_BUILTIN(Load20ATDictionaryElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../third_party/v8/builtins/array-sort.tq:173:27
  {
    // ../third_party/v8/builtins/array-sort.tq:174:5
    {
      Label label_try_done_741_1049_impl(this);
      Label* label_try_done_741_1049 = &label_try_done_741_1049_impl;
      USE(label_try_done_741_1049);
      Label label_Bailout_470_impl(this);
      Label* label_Bailout_470 = &label_Bailout_470_impl;
      USE(label_Bailout_470);
      Label label_try_begin_742_1050_impl(this);
      Label* label_try_begin_742_1050 = &label_try_begin_742_1050_impl;
      USE(label_try_begin_742_1050);
      Goto(label_try_begin_742_1050);
      if (label_try_begin_742_1050->is_used())
      {
        BIND(label_try_begin_742_1050);
        // ../third_party/v8/builtins/array-sort.tq:174:9
        {
          // ../third_party/v8/builtins/array-sort.tq:175:7
          TNode<NumberDictionary> t1831 = UncheckedCast<NumberDictionary>(unsafe_cast18ATNumberDictionary(implicit_cast<TNode<Object>>(p_elements)));
          USE(implicit_cast<TNode<NumberDictionary>>(t1831));
          TNode<NumberDictionary> dictionary_743_impl;
          auto dictionary_743 = &dictionary_743_impl;
          USE(dictionary_743);
          *dictionary_743 = implicit_cast<TNode<NumberDictionary>>(t1831);
          // ../third_party/v8/builtins/array-sort.tq:177:7
          TNode<IntPtrT> t1832 = UncheckedCast<IntPtrT>(convert8ATintptr(implicit_cast<TNode<Smi>>(p_index)));
          USE(implicit_cast<TNode<IntPtrT>>(t1832));
          TNode<IntPtrT> intptr_index_744_impl;
          auto intptr_index_744 = &intptr_index_744_impl;
          USE(intptr_index_744);
          *intptr_index_744 = implicit_cast<TNode<IntPtrT>>(t1832);
          // ../third_party/v8/builtins/array-sort.tq:178:7
          TNode<Object> t1833 = UncheckedCast<Object>(BasicLoadNumberDictionaryElement(implicit_cast<TNode<NumberDictionary>>((*dictionary_743)), implicit_cast<TNode<IntPtrT>>((*intptr_index_744)), label_Bailout_470, label_Bailout_470));
          USE(implicit_cast<TNode<Object>>(t1833));
          TNode<Object> value_745_impl;
          auto value_745 = &value_745_impl;
          USE(value_745);
          *value_745 = implicit_cast<TNode<Object>>(t1833);
          // ../third_party/v8/builtins/array-sort.tq:181:7
          Return(implicit_cast<TNode<Object>>((*value_745)));
        }
      }
      if (label_Bailout_470->is_used())
      {
        BIND(label_Bailout_470);
        // ../third_party/v8/builtins/array-sort.tq:183:19
        {
          // ../third_party/v8/builtins/array-sort.tq:184:7
          TNode<Smi> t1834 = UncheckedCast<Smi>(Failure(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t1834));
          Return(implicit_cast<TNode<Object>>(t1834));
        }
      }
    }
  }
}

TF_BUILTIN(Load19ATTempArrayElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../third_party/v8/builtins/array-sort.tq:190:27
  {
    // ../third_party/v8/builtins/array-sort.tq:191:5
    // ../third_party/v8/builtins/array-sort.tq:192:5
    TNode<FixedArray> t1835 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedArray>>(t1835));
    TNode<FixedArray> elems_746_impl;
    auto elems_746 = &elems_746_impl;
    USE(elems_746);
    *elems_746 = implicit_cast<TNode<FixedArray>>(t1835);
    // ../third_party/v8/builtins/array-sort.tq:193:5
    TNode<Object> t1836 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*elems_746)), implicit_cast<TNode<Smi>>(p_index)));
    Return(implicit_cast<TNode<Object>>(t1836));
  }
}

TF_BUILTIN(Store23ATFastPackedSmiElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../third_party/v8/builtins/array-sort.tq:205:27
  {
    // ../third_party/v8/builtins/array-sort.tq:206:5
    TNode<FixedArray> t1837 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedArray>>(t1837));
    TNode<FixedArray> elems_747_impl;
    auto elems_747 = &elems_747_impl;
    USE(elems_747);
    *elems_747 = implicit_cast<TNode<FixedArray>>(t1837);
    // ../third_party/v8/builtins/array-sort.tq:207:5
    StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>((*elems_747)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value), implicit_cast<WriteBarrierMode>(SKIP_WRITE_BARRIER));
    // ../third_party/v8/builtins/array-sort.tq:208:5
    Return(implicit_cast<TNode<Smi>>(kSuccess()));
  }
}

TF_BUILTIN(Store25ATFastSmiOrObjectElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../third_party/v8/builtins/array-sort.tq:213:27
  {
    // ../third_party/v8/builtins/array-sort.tq:214:5
    TNode<FixedArray> t1838 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedArray>>(t1838));
    TNode<FixedArray> elems_748_impl;
    auto elems_748 = &elems_748_impl;
    USE(elems_748);
    *elems_748 = implicit_cast<TNode<FixedArray>>(t1838);
    // ../third_party/v8/builtins/array-sort.tq:215:5
    StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>((*elems_748)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value));
    // ../third_party/v8/builtins/array-sort.tq:216:5
    Return(implicit_cast<TNode<Smi>>(kSuccess()));
  }
}

TF_BUILTIN(Store20ATFastDoubleElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../third_party/v8/builtins/array-sort.tq:221:27
  {
    // ../third_party/v8/builtins/array-sort.tq:222:5
    TNode<FixedDoubleArray> t1839 = UncheckedCast<FixedDoubleArray>(unsafe_cast18ATFixedDoubleArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedDoubleArray>>(t1839));
    TNode<FixedDoubleArray> elems_749_impl;
    auto elems_749 = &elems_749_impl;
    USE(elems_749);
    *elems_749 = implicit_cast<TNode<FixedDoubleArray>>(t1839);
    // ../third_party/v8/builtins/array-sort.tq:223:5
    TNode<HeapNumber> t1840 = UncheckedCast<HeapNumber>(unsafe_cast12ATHeapNumber(implicit_cast<TNode<Object>>(p_value)));
    USE(implicit_cast<TNode<HeapNumber>>(t1840));
    TNode<HeapNumber> heap_val_750_impl;
    auto heap_val_750 = &heap_val_750_impl;
    USE(heap_val_750);
    *heap_val_750 = implicit_cast<TNode<HeapNumber>>(t1840);
    // ../third_party/v8/builtins/array-sort.tq:225:5
    TNode<Float64T> t1841 = UncheckedCast<Float64T>(convert9ATfloat64(implicit_cast<TNode<HeapNumber>>((*heap_val_750))));
    USE(implicit_cast<TNode<Float64T>>(t1841));
    TNode<Float64T> t1842 = UncheckedCast<Float64T>(Float64SilenceNaN(implicit_cast<TNode<Float64T>>(t1841)));
    USE(implicit_cast<TNode<Float64T>>(t1842));
    TNode<Float64T> val_751_impl;
    auto val_751 = &val_751_impl;
    USE(val_751);
    *val_751 = implicit_cast<TNode<Float64T>>(t1842);
    // ../third_party/v8/builtins/array-sort.tq:226:5
    StoreFixedDoubleArrayElementWithSmiIndex(implicit_cast<TNode<FixedDoubleArray>>((*elems_749)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Float64T>>((*val_751)));
    // ../third_party/v8/builtins/array-sort.tq:227:5
    Return(implicit_cast<TNode<Smi>>(kSuccess()));
  }
}

TF_BUILTIN(Store20ATDictionaryElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../third_party/v8/builtins/array-sort.tq:232:27
  {
    // ../third_party/v8/builtins/array-sort.tq:233:5
    TNode<NumberDictionary> t1843 = UncheckedCast<NumberDictionary>(unsafe_cast18ATNumberDictionary(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<NumberDictionary>>(t1843));
    TNode<NumberDictionary> dictionary_752_impl;
    auto dictionary_752 = &dictionary_752_impl;
    USE(dictionary_752);
    *dictionary_752 = implicit_cast<TNode<NumberDictionary>>(t1843);
    // ../third_party/v8/builtins/array-sort.tq:235:5
    TNode<IntPtrT> t1844 = UncheckedCast<IntPtrT>(convert8ATintptr(implicit_cast<TNode<Smi>>(p_index)));
    USE(implicit_cast<TNode<IntPtrT>>(t1844));
    TNode<IntPtrT> intptr_index_753_impl;
    auto intptr_index_753 = &intptr_index_753_impl;
    USE(intptr_index_753);
    *intptr_index_753 = implicit_cast<TNode<IntPtrT>>(t1844);
    // ../third_party/v8/builtins/array-sort.tq:236:5
    {
      Label label_try_done_754_1051_impl(this);
      Label* label_try_done_754_1051 = &label_try_done_754_1051_impl;
      USE(label_try_done_754_1051);
      Label label_ReadOnly_471_impl(this);
      Label* label_ReadOnly_471 = &label_ReadOnly_471_impl;
      USE(label_ReadOnly_471);
      Label label_Fail_472_impl(this);
      Label* label_Fail_472 = &label_Fail_472_impl;
      USE(label_Fail_472);
      Label label_try_begin_755_1052_impl(this);
      Label* label_try_begin_755_1052 = &label_try_begin_755_1052_impl;
      USE(label_try_begin_755_1052);
      Goto(label_try_begin_755_1052);
      if (label_try_begin_755_1052->is_used())
      {
        BIND(label_try_begin_755_1052);
        // ../third_party/v8/builtins/array-sort.tq:236:9
        {
          // ../third_party/v8/builtins/array-sort.tq:237:7
          BasicStoreNumberDictionaryElement(implicit_cast<TNode<NumberDictionary>>((*dictionary_752)), implicit_cast<TNode<IntPtrT>>((*intptr_index_753)), implicit_cast<TNode<Object>>(p_value), label_Fail_472, label_Fail_472, label_ReadOnly_471);
          // ../third_party/v8/builtins/array-sort.tq:239:7
          Return(implicit_cast<TNode<Smi>>(kSuccess()));
        }
      }
      if (label_ReadOnly_471->is_used())
      {
        BIND(label_ReadOnly_471);
        // ../third_party/v8/builtins/array-sort.tq:241:20
        {
          // ../third_party/v8/builtins/array-sort.tq:244:7
          TNode<JSReceiver> t1845 = UncheckedCast<JSReceiver>(GetReceiver(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<JSReceiver>>(t1845));
          TNode<JSReceiver> receiver_756_impl;
          auto receiver_756 = &receiver_756_impl;
          USE(receiver_756);
          *receiver_756 = implicit_cast<TNode<JSReceiver>>(t1845);
          // ../third_party/v8/builtins/array-sort.tq:245:7
          TNode<Object> t1846 = UncheckedCast<Object>(Typeof(implicit_cast<TNode<Object>>((*receiver_756))));
          USE(implicit_cast<TNode<Object>>(t1846));
          ThrowTypeError(implicit_cast<TNode<Context>>(p_context), implicit_cast<MessageTemplate::Template>(MessageTemplate::kStrictReadOnlyProperty), implicit_cast<TNode<Object>>(p_index), implicit_cast<TNode<Object>>(t1846), implicit_cast<TNode<Object>>((*receiver_756)));
        }
      }
      if (label_Fail_472->is_used())
      {
        BIND(label_Fail_472);
        // ../third_party/v8/builtins/array-sort.tq:248:16
        {
          // ../third_party/v8/builtins/array-sort.tq:249:7
          TNode<Smi> t1847 = UncheckedCast<Smi>(Failure(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t1847));
          Return(implicit_cast<TNode<Smi>>(t1847));
        }
      }
    }
  }
}

TF_BUILTIN(Store19ATTempArrayElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../third_party/v8/builtins/array-sort.tq:255:27
  {
    // ../third_party/v8/builtins/array-sort.tq:256:5
    TNode<FixedArray> t1848 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(p_elements)));
    USE(implicit_cast<TNode<FixedArray>>(t1848));
    TNode<FixedArray> elems_757_impl;
    auto elems_757 = &elems_757_impl;
    USE(elems_757);
    *elems_757 = implicit_cast<TNode<FixedArray>>(t1848);
    // ../third_party/v8/builtins/array-sort.tq:257:5
    StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>((*elems_757)), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value));
    // ../third_party/v8/builtins/array-sort.tq:258:5
    Return(implicit_cast<TNode<Smi>>(kSuccess()));
  }
}

TF_BUILTIN(SortCompareDefault, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<Object> p_comparefn = UncheckedCast<Object>(Parameter(Descriptor::kComparefn));
  USE(p_comparefn);
  TNode<Object> p_x = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(p_x);
  TNode<Object> p_y = UncheckedCast<Object>(Parameter(Descriptor::kY));
  USE(p_y);
  // ../third_party/v8/builtins/array-sort.tq:283:74
  {
    // ../third_party/v8/builtins/array-sort.tq:284:5
    // ../third_party/v8/builtins/array-sort.tq:286:5
    {
      Label label__True_473_impl(this);
      Label* label__True_473 = &label__True_473_impl;
      USE(label__True_473);
      Label label__False_474_impl(this, {});
      Label* label__False_474 = &label__False_474_impl;
      USE(label__False_474);
      Label label__True_475_impl(this);
      Label* label__True_475 = &label__True_475_impl;
      USE(label__True_475);
      TNode<BoolT> t1853 = UncheckedCast<BoolT>(TaggedIsSmi(implicit_cast<TNode<Object>>(p_x)));
      USE(implicit_cast<TNode<BoolT>>(t1853));
      GotoIfNot(implicit_cast<TNode<BoolT>>(t1853), label__False_474);
      TNode<BoolT> t1854 = UncheckedCast<BoolT>(TaggedIsSmi(implicit_cast<TNode<Object>>(p_y)));
      USE(implicit_cast<TNode<BoolT>>(t1854));
      Branch(implicit_cast<TNode<BoolT>>(t1854), label__True_473, label__False_474);
      if (label__True_473->is_used())
      {
        BIND(label__True_473);
        // ../third_party/v8/builtins/array-sort.tq:286:43
        {
          // ../third_party/v8/builtins/array-sort.tq:288:7
          TNode<Number> t1855 = UncheckedCast<Number>(CallRuntime(Runtime::kSmiLexicographicCompare, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_x), implicit_cast<TNode<Object>>(p_y)));
          USE(implicit_cast<TNode<Number>>(t1855));
          Return(implicit_cast<TNode<Number>>(t1855));
        }
      }
      BIND(label__False_474);
    }
    // ../third_party/v8/builtins/array-sort.tq:292:5
    TNode<String> t1856 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_x)));
    USE(implicit_cast<TNode<String>>(t1856));
    TNode<String> xString_758_impl;
    auto xString_758 = &xString_758_impl;
    USE(xString_758);
    *xString_758 = implicit_cast<TNode<String>>(t1856);
    // ../third_party/v8/builtins/array-sort.tq:295:5
    TNode<String> t1857 = UncheckedCast<String>(ToString_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_y)));
    USE(implicit_cast<TNode<String>>(t1857));
    TNode<String> yString_759_impl;
    auto yString_759 = &yString_759_impl;
    USE(yString_759);
    *yString_759 = implicit_cast<TNode<String>>(t1857);
    // ../third_party/v8/builtins/array-sort.tq:300:5
    {
      Label label__True_476_impl(this);
      Label* label__True_476 = &label__True_476_impl;
      USE(label__True_476);
      Label label__False_477_impl(this, {});
      Label* label__False_477 = &label__False_477_impl;
      USE(label__False_477);
      TNode<Oddball> t1858 = UncheckedCast<Oddball>(CallBuiltin(Builtins::kStringLessThan, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<String>>((*xString_758)), implicit_cast<TNode<String>>((*yString_759))));
      USE(implicit_cast<TNode<Oddball>>(t1858));
      TNode<BoolT> t1859 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>(t1858), implicit_cast<TNode<Object>>(True())));
      USE(implicit_cast<TNode<BoolT>>(t1859));
      Branch(implicit_cast<TNode<BoolT>>(t1859), label__True_476, label__False_477);
      if (label__True_476->is_used())
      {
        BIND(label__True_476);
        // ../third_party/v8/builtins/array-sort.tq:300:60
        int31_t t1860 = -1;
        TNode<Number> t1861 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t1860)));
        Return(implicit_cast<TNode<Number>>(t1861));
      }
      BIND(label__False_477);
    }
    // ../third_party/v8/builtins/array-sort.tq:305:5
    {
      Label label__True_478_impl(this);
      Label* label__True_478 = &label__True_478_impl;
      USE(label__True_478);
      Label label__False_479_impl(this, {});
      Label* label__False_479 = &label__False_479_impl;
      USE(label__False_479);
      TNode<Oddball> t1862 = UncheckedCast<Oddball>(CallBuiltin(Builtins::kStringLessThan, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<String>>((*yString_759)), implicit_cast<TNode<String>>((*xString_758))));
      USE(implicit_cast<TNode<Oddball>>(t1862));
      TNode<BoolT> t1863 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>(t1862), implicit_cast<TNode<Object>>(True())));
      USE(implicit_cast<TNode<BoolT>>(t1863));
      Branch(implicit_cast<TNode<BoolT>>(t1863), label__True_478, label__False_479);
      if (label__True_478->is_used())
      {
        BIND(label__True_478);
        // ../third_party/v8/builtins/array-sort.tq:305:60
        int31_t t1864 = 1;
        TNode<Number> t1865 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t1864)));
        Return(implicit_cast<TNode<Number>>(t1865));
      }
      BIND(label__False_479);
    }
    // ../third_party/v8/builtins/array-sort.tq:308:5
    int31_t t1866 = 0;
    TNode<Number> t1867 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t1866)));
    Return(implicit_cast<TNode<Number>>(t1867));
  }
}

TF_BUILTIN(SortCompareUserFn, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<Object> p_comparefn = UncheckedCast<Object>(Parameter(Descriptor::kComparefn));
  USE(p_comparefn);
  TNode<Object> p_x = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(p_x);
  TNode<Object> p_y = UncheckedCast<Object>(Parameter(Descriptor::kY));
  USE(p_y);
  // ../third_party/v8/builtins/array-sort.tq:312:74
  {
    // ../third_party/v8/builtins/array-sort.tq:313:5
    // ../third_party/v8/builtins/array-sort.tq:314:5
    TNode<JSReceiver> t1868 = UncheckedCast<JSReceiver>(unsafe_cast45UT17ATJSBoundFunction12ATJSFunction9ATJSProxy(implicit_cast<TNode<Object>>(p_comparefn)));
    USE(implicit_cast<TNode<JSReceiver>>(t1868));
    TNode<JSReceiver> cmpfn_760_impl;
    auto cmpfn_760 = &cmpfn_760_impl;
    USE(cmpfn_760);
    *cmpfn_760 = implicit_cast<TNode<JSReceiver>>(t1868);
    // ../third_party/v8/builtins/array-sort.tq:317:5
    TNode<Object> t1869 = UncheckedCast<Object>(Call(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*cmpfn_760)), implicit_cast<TNode<Object>>(Undefined()), implicit_cast<TNode<Object>>(p_x), implicit_cast<TNode<Object>>(p_y)));
    USE(implicit_cast<TNode<Object>>(t1869));
    TNode<Number> t1870 = UncheckedCast<Number>(ToNumber_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t1869)));
    USE(implicit_cast<TNode<Number>>(t1870));
    TNode<Number> v_761_impl;
    auto v_761 = &v_761_impl;
    USE(v_761);
    *v_761 = implicit_cast<TNode<Number>>(t1870);
    // ../third_party/v8/builtins/array-sort.tq:321:5
    {
      Label label__True_480_impl(this);
      Label* label__True_480 = &label__True_480_impl;
      USE(label__True_480);
      Label label__False_481_impl(this, {});
      Label* label__False_481 = &label__False_481_impl;
      USE(label__False_481);
      TNode<BoolT> t1871 = UncheckedCast<BoolT>(NumberIsNaN(implicit_cast<TNode<Number>>((*v_761))));
      USE(implicit_cast<TNode<BoolT>>(t1871));
      Branch(implicit_cast<TNode<BoolT>>(t1871), label__True_480, label__False_481);
      if (label__True_480->is_used())
      {
        BIND(label__True_480);
        // ../third_party/v8/builtins/array-sort.tq:321:25
        int31_t t1872 = 0;
        TNode<Number> t1873 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t1872)));
        Return(implicit_cast<TNode<Number>>(t1873));
      }
      BIND(label__False_481);
    }
    // ../third_party/v8/builtins/array-sort.tq:324:5
    Return(implicit_cast<TNode<Number>>((*v_761)));
  }
}

TF_BUILTIN(CanUseSameAccessor25ATGenericElementsAccessor, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSReceiver> p_receiver = UncheckedCast<JSReceiver>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_initialReceiverMap = UncheckedCast<Object>(Parameter(Descriptor::kInitialReceiverMap));
  USE(p_initialReceiverMap);
  TNode<Number> p_initialReceiverLength = UncheckedCast<Number>(Parameter(Descriptor::kInitialReceiverLength));
  USE(p_initialReceiverLength);
  // ../third_party/v8/builtins/array-sort.tq:344:47
  {
    // ../third_party/v8/builtins/array-sort.tq:346:5
    Return(implicit_cast<TNode<Oddball>>(True()));
  }
}

TF_BUILTIN(CanUseSameAccessor20ATDictionaryElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSReceiver> p_receiver = UncheckedCast<JSReceiver>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_initialReceiverMap = UncheckedCast<Object>(Parameter(Descriptor::kInitialReceiverMap));
  USE(p_initialReceiverMap);
  TNode<Number> p_initialReceiverLength = UncheckedCast<Number>(Parameter(Descriptor::kInitialReceiverLength));
  USE(p_initialReceiverLength);
  // ../third_party/v8/builtins/array-sort.tq:351:47
  {
    // ../third_party/v8/builtins/array-sort.tq:352:5
    TNode<JSReceiver> t1874 = UncheckedCast<JSReceiver>(unsafe_cast12ATJSReceiver(implicit_cast<TNode<Object>>(p_receiver)));
    USE(implicit_cast<TNode<JSReceiver>>(t1874));
    TVARIABLE(JSReceiver, obj_337_impl);
    auto obj_337 = &obj_337_impl;
    USE(obj_337);
    *obj_337 = implicit_cast<TNode<JSReceiver>>(t1874);
    // ../third_party/v8/builtins/array-sort.tq:353:5
    TNode<Map> t1875 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>((*obj_337).value())));
    TNode<BoolT> t1876 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>(t1875), implicit_cast<TNode<Object>>(p_initialReceiverMap)));
    USE(implicit_cast<TNode<BoolT>>(t1876));
    TNode<Oddball> t1877 = UncheckedCast<Oddball>(SelectBooleanConstant(implicit_cast<TNode<BoolT>>(t1876)));
    USE(implicit_cast<TNode<Oddball>>(t1877));
    Return(implicit_cast<TNode<Oddball>>(t1877));
  }
}

compiler::TNode<Number> ArrayBuiltinsFromDSLAssembler::CallCompareFn(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Object> p_x, TNode<Object> p_y, Label* label_Bailout_482) {
  TVARIABLE(Number, _return_338_impl);
  auto _return_338 = &_return_338_impl;
  USE(_return_338);
  Label label_macro_end_1057_impl(this, {_return_338});
  Label* label_macro_end_1057 = &label_macro_end_1057_impl;
  USE(label_macro_end_1057);
  // ../third_party/v8/builtins/array-sort.tq:358:18
  {
    // ../third_party/v8/builtins/array-sort.tq:359:5
    TNode<Object> t1878 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kUserCmpFnIdx())));
    TNode<Object> userCmpFn_762_impl;
    auto userCmpFn_762 = &userCmpFn_762_impl;
    USE(userCmpFn_762);
    *userCmpFn_762 = implicit_cast<TNode<Object>>(t1878);
    // ../third_party/v8/builtins/array-sort.tq:360:5
    TNode<Object> t1879 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kSortComparePtrIdx())));
    TNode<Code> t1880 = UncheckedCast<Code>(unsafe_cast108FT9ATContext22UT12ATHeapObject5ATSmi22UT12ATHeapObject5ATSmi22UT12ATHeapObject5ATSmi22UT12ATHeapNumber5ATSmi(implicit_cast<TNode<Object>>(t1879)));
    USE(implicit_cast<TNode<Code>>(t1880));
    TNode<Code> sortCompare_763_impl;
    auto sortCompare_763 = &sortCompare_763_impl;
    USE(sortCompare_763);
    *sortCompare_763 = implicit_cast<TNode<Code>>(t1880);
    // ../third_party/v8/builtins/array-sort.tq:363:5
    TNode<Number> t1881 = UncheckedCast<Number>(CallStub(Builtins::CallableFor(isolate(), Builtins::kSortCompareDefault).descriptor(), implicit_cast<TNode<Code>>((*sortCompare_763)), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*userCmpFn_762)), implicit_cast<TNode<Object>>(p_x), implicit_cast<TNode<Object>>(p_y)));
    USE(implicit_cast<TNode<Number>>(t1881));
    TNode<Number> result_764_impl;
    auto result_764 = &result_764_impl;
    USE(result_764);
    *result_764 = implicit_cast<TNode<Number>>(t1881);
    // ../third_party/v8/builtins/array-sort.tq:365:5
    TNode<JSReceiver> t1882 = UncheckedCast<JSReceiver>(GetReceiver(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<JSReceiver>>(t1882));
    TNode<JSReceiver> receiver_765_impl;
    auto receiver_765 = &receiver_765_impl;
    USE(receiver_765);
    *receiver_765 = implicit_cast<TNode<JSReceiver>>(t1882);
    // ../third_party/v8/builtins/array-sort.tq:366:5
    TNode<Object> t1883 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kInitialReceiverMapIdx())));
    TNode<Object> initialReceiverMap_766_impl;
    auto initialReceiverMap_766 = &initialReceiverMap_766_impl;
    USE(initialReceiverMap_766);
    *initialReceiverMap_766 = implicit_cast<TNode<Object>>(t1883);
    // ../third_party/v8/builtins/array-sort.tq:367:5
    TNode<Object> t1884 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kInitialReceiverLengthIdx())));
    TNode<Number> t1885 = UncheckedCast<Number>(unsafe_cast22UT12ATHeapNumber5ATSmi(implicit_cast<TNode<Object>>(t1884)));
    USE(implicit_cast<TNode<Number>>(t1885));
    TNode<Number> initialReceiverLength_767_impl;
    auto initialReceiverLength_767 = &initialReceiverLength_767_impl;
    USE(initialReceiverLength_767);
    *initialReceiverLength_767 = implicit_cast<TNode<Number>>(t1885);
    // ../third_party/v8/builtins/array-sort.tq:369:5
    TNode<Code> t1886 = UncheckedCast<Code>(GetCanUseSameAccessorFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Code>>(t1886));
    TNode<Code> CanUseSameAccessor_768_impl;
    auto CanUseSameAccessor_768 = &CanUseSameAccessor_768_impl;
    USE(CanUseSameAccessor_768);
    *CanUseSameAccessor_768 = implicit_cast<TNode<Code>>(t1886);
    // ../third_party/v8/builtins/array-sort.tq:372:5
    {
      Label label__True_483_impl(this);
      Label* label__True_483 = &label__True_483_impl;
      USE(label__True_483);
      Label label__False_484_impl(this, {});
      Label* label__False_484 = &label__False_484_impl;
      USE(label__False_484);
      TNode<Oddball> t1887 = UncheckedCast<Oddball>(CallStub(Builtins::CallableFor(isolate(), Builtins::kCanUseSameAccessor25ATGenericElementsAccessor).descriptor(), implicit_cast<TNode<Code>>((*CanUseSameAccessor_768)), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>((*receiver_765)), implicit_cast<TNode<Object>>((*initialReceiverMap_766)), implicit_cast<TNode<Number>>((*initialReceiverLength_767))));
      USE(implicit_cast<TNode<Oddball>>(t1887));
      TNode<BoolT> t1888 = UncheckedCast<BoolT>(IsFalse(implicit_cast<TNode<Oddball>>(t1887)));
      USE(implicit_cast<TNode<BoolT>>(t1888));
      Branch(implicit_cast<TNode<BoolT>>(t1888), label__True_483, label__False_484);
      if (label__True_483->is_used())
      {
        BIND(label__True_483);
        // ../third_party/v8/builtins/array-sort.tq:373:76
        {
          // ../third_party/v8/builtins/array-sort.tq:374:7
          Goto(label_Bailout_482);
        }
      }
      BIND(label__False_484);
    }
    // ../third_party/v8/builtins/array-sort.tq:376:5
    *_return_338 = implicit_cast<TNode<Number>>((*result_764));
    Goto(label_macro_end_1057);
  }
  BIND(label_macro_end_1057);
  return implicit_cast<TNode<Number>>((*_return_338).value());
}

compiler::TNode<HeapObject> ArrayBuiltinsFromDSLAssembler::ReloadElements(TNode<FixedArray> p_sortState) {
  TVARIABLE(HeapObject, _return_339_impl);
  auto _return_339 = &_return_339_impl;
  USE(_return_339);
  Label label_macro_end_1058_impl(this, {_return_339});
  Label* label_macro_end_1058 = &label_macro_end_1058_impl;
  USE(label_macro_end_1058);
  // ../third_party/v8/builtins/array-sort.tq:383:59
  {
    // ../third_party/v8/builtins/array-sort.tq:384:5
    TNode<JSReceiver> t1889 = UncheckedCast<JSReceiver>(GetReceiver(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<JSReceiver>>(t1889));
    TNode<JSReceiver> receiver_769_impl;
    auto receiver_769 = &receiver_769_impl;
    USE(receiver_769);
    *receiver_769 = implicit_cast<TNode<JSReceiver>>(t1889);
    // ../third_party/v8/builtins/array-sort.tq:385:5
    {
      Label label__True_485_impl(this);
      Label* label__True_485 = &label__True_485_impl;
      USE(label__True_485);
      Label label__False_486_impl(this, {});
      Label* label__False_486 = &label__False_486_impl;
      USE(label__False_486);
      TNode<Object> t1890 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kAccessorIdx())));
      TNode<BoolT> t1891 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>(t1890), implicit_cast<TNode<Object>>(kGenericElementsAccessorId())));
      USE(implicit_cast<TNode<BoolT>>(t1891));
      Branch(implicit_cast<TNode<BoolT>>(t1891), label__True_485, label__False_486);
      if (label__True_485->is_used())
      {
        BIND(label__True_485);
        // ../third_party/v8/builtins/array-sort.tq:385:64
        *_return_339 = implicit_cast<TNode<HeapObject>>((*receiver_769));
        Goto(label_macro_end_1058);
      }
      BIND(label__False_486);
    }
    // ../third_party/v8/builtins/array-sort.tq:387:5
    TNode<JSObject> t1892 = UncheckedCast<JSObject>(unsafe_cast10ATJSObject(implicit_cast<TNode<Object>>((*receiver_769))));
    USE(implicit_cast<TNode<JSObject>>(t1892));
    TNode<JSObject> object_770_impl;
    auto object_770 = &object_770_impl;
    USE(object_770);
    *object_770 = implicit_cast<TNode<JSObject>>(t1892);
    // ../third_party/v8/builtins/array-sort.tq:388:5
    TNode<FixedArrayBase> t1893 = UncheckedCast<FixedArrayBase>(LoadElements(implicit_cast<TNode<JSObject>>((*object_770))));
    *_return_339 = implicit_cast<TNode<HeapObject>>(t1893);
    Goto(label_macro_end_1058);
  }
  BIND(label_macro_end_1058);
  return implicit_cast<TNode<HeapObject>>((*_return_339).value());
}

compiler::TNode<Code> ArrayBuiltinsFromDSLAssembler::GetLoadFn(TNode<FixedArray> p_sortState) {
  TVARIABLE(Code, _return_340_impl);
  auto _return_340 = &_return_340_impl;
  USE(_return_340);
  Label label_macro_end_1059_impl(this, {_return_340});
  Label* label_macro_end_1059 = &label_macro_end_1059_impl;
  USE(label_macro_end_1059);
  // ../third_party/v8/builtins/array-sort.tq:391:50
  {
    // ../third_party/v8/builtins/array-sort.tq:392:5
    TNode<Object> t1894 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kLoadFnIdx())));
    TNode<Code> t1895 = UncheckedCast<Code>(unsafe_cast70FT9ATContext12ATFixedArray12ATHeapObject5ATSmi22UT12ATHeapObject5ATSmi(implicit_cast<TNode<Object>>(t1894)));
    USE(implicit_cast<TNode<Code>>(t1895));
    *_return_340 = implicit_cast<TNode<Code>>(t1895);
    Goto(label_macro_end_1059);
  }
  BIND(label_macro_end_1059);
  return implicit_cast<TNode<Code>>((*_return_340).value());
}

compiler::TNode<Code> ArrayBuiltinsFromDSLAssembler::GetStoreFn(TNode<FixedArray> p_sortState) {
  TVARIABLE(Code, _return_341_impl);
  auto _return_341 = &_return_341_impl;
  USE(_return_341);
  Label label_macro_end_1060_impl(this, {_return_341});
  Label* label_macro_end_1060 = &label_macro_end_1060_impl;
  USE(label_macro_end_1060);
  // ../third_party/v8/builtins/array-sort.tq:395:52
  {
    // ../third_party/v8/builtins/array-sort.tq:396:5
    TNode<Object> t1896 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kStoreFnIdx())));
    TNode<Code> t1897 = UncheckedCast<Code>(unsafe_cast76FT9ATContext12ATFixedArray12ATHeapObject5ATSmi22UT12ATHeapObject5ATSmi5ATSmi(implicit_cast<TNode<Object>>(t1896)));
    USE(implicit_cast<TNode<Code>>(t1897));
    *_return_341 = implicit_cast<TNode<Code>>(t1897);
    Goto(label_macro_end_1060);
  }
  BIND(label_macro_end_1060);
  return implicit_cast<TNode<Code>>((*_return_341).value());
}

compiler::TNode<Code> ArrayBuiltinsFromDSLAssembler::GetCanUseSameAccessorFn(TNode<FixedArray> p_sortState) {
  TVARIABLE(Code, _return_342_impl);
  auto _return_342 = &_return_342_impl;
  USE(_return_342);
  Label label_macro_end_1061_impl(this, {_return_342});
  Label* label_macro_end_1061 = &label_macro_end_1061_impl;
  USE(label_macro_end_1061);
  // ../third_party/v8/builtins/array-sort.tq:399:78
  {
    // ../third_party/v8/builtins/array-sort.tq:400:5
    TNode<Object> t1898 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kCanUseSameAccessorFnIdx())));
    TNode<Code> t1899 = UncheckedCast<Code>(unsafe_cast84FT9ATContext12ATJSReceiver22UT12ATHeapObject5ATSmi22UT12ATHeapNumber5ATSmi9ATBoolean(implicit_cast<TNode<Object>>(t1898)));
    USE(implicit_cast<TNode<Code>>(t1899));
    *_return_342 = implicit_cast<TNode<Code>>(t1899);
    Goto(label_macro_end_1061);
  }
  BIND(label_macro_end_1061);
  return implicit_cast<TNode<Code>>((*_return_342).value());
}

compiler::TNode<JSReceiver> ArrayBuiltinsFromDSLAssembler::GetReceiver(TNode<FixedArray> p_sortState) {
  TVARIABLE(JSReceiver, _return_343_impl);
  auto _return_343 = &_return_343_impl;
  USE(_return_343);
  Label label_macro_end_1062_impl(this, {_return_343});
  Label* label_macro_end_1062 = &label_macro_end_1062_impl;
  USE(label_macro_end_1062);
  // ../third_party/v8/builtins/array-sort.tq:404:56
  {
    // ../third_party/v8/builtins/array-sort.tq:405:5
    TNode<Object> t1900 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kReceiverIdx())));
    TNode<JSReceiver> t1901 = UncheckedCast<JSReceiver>(unsafe_cast12ATJSReceiver(implicit_cast<TNode<Object>>(t1900)));
    USE(implicit_cast<TNode<JSReceiver>>(t1901));
    *_return_343 = implicit_cast<TNode<JSReceiver>>(t1901);
    Goto(label_macro_end_1062);
  }
  BIND(label_macro_end_1062);
  return implicit_cast<TNode<JSReceiver>>((*_return_343).value());
}

compiler::TNode<FixedArray> ArrayBuiltinsFromDSLAssembler::GetTempArray(TNode<FixedArray> p_sortState) {
  TVARIABLE(FixedArray, _return_344_impl);
  auto _return_344 = &_return_344_impl;
  USE(_return_344);
  Label label_macro_end_1063_impl(this, {_return_344});
  Label* label_macro_end_1063 = &label_macro_end_1063_impl;
  USE(label_macro_end_1063);
  // ../third_party/v8/builtins/array-sort.tq:409:57
  {
    // ../third_party/v8/builtins/array-sort.tq:410:5
    TNode<Object> t1902 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kTempArrayIdx())));
    TNode<FixedArray> t1903 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(t1902)));
    USE(implicit_cast<TNode<FixedArray>>(t1903));
    *_return_344 = implicit_cast<TNode<FixedArray>>(t1903);
    Goto(label_macro_end_1063);
  }
  BIND(label_macro_end_1063);
  return implicit_cast<TNode<FixedArray>>((*_return_344).value());
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::GetPendingRunsSize(TNode<FixedArray> p_sortState) {
  TVARIABLE(Smi, _return_345_impl);
  auto _return_345 = &_return_345_impl;
  USE(_return_345);
  Label label_macro_end_1064_impl(this, {_return_345});
  Label* label_macro_end_1064 = &label_macro_end_1064_impl;
  USE(label_macro_end_1064);
  // ../third_party/v8/builtins/array-sort.tq:415:56
  {
    // ../third_party/v8/builtins/array-sort.tq:416:5
    // ../third_party/v8/builtins/array-sort.tq:417:5
    TNode<Object> t1904 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kPendingRunsSizeIdx())));
    TNode<Smi> t1905 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(t1904)));
    USE(implicit_cast<TNode<Smi>>(t1905));
    TNode<Smi> stack_size_771_impl;
    auto stack_size_771 = &stack_size_771_impl;
    USE(stack_size_771);
    *stack_size_771 = implicit_cast<TNode<Smi>>(t1905);
    // ../third_party/v8/builtins/array-sort.tq:419:5
    // ../third_party/v8/builtins/array-sort.tq:420:5
    *_return_345 = implicit_cast<TNode<Smi>>((*stack_size_771));
    Goto(label_macro_end_1064);
  }
  BIND(label_macro_end_1064);
  return implicit_cast<TNode<Smi>>((*_return_345).value());
}

void ArrayBuiltinsFromDSLAssembler::SetPendingRunsSize(TNode<FixedArray> p_sortState, TNode<Smi> p_value) {
  Label label_macro_end_1065_impl(this, {});
  Label* label_macro_end_1065 = &label_macro_end_1065_impl;
  USE(label_macro_end_1065);
  // ../third_party/v8/builtins/array-sort.tq:423:63
  {
    // ../third_party/v8/builtins/array-sort.tq:424:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kPendingRunsSizeIdx()), implicit_cast<TNode<Object>>(p_value));
  }
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::GetPendingRunBase(TNode<FixedArray> p_pendingRuns, TNode<Smi> p_run) {
  TVARIABLE(Smi, _return_346_impl);
  auto _return_346 = &_return_346_impl;
  USE(_return_346);
  Label label_macro_end_1066_impl(this, {_return_346});
  Label* label_macro_end_1066 = &label_macro_end_1066_impl;
  USE(label_macro_end_1066);
  // ../third_party/v8/builtins/array-sort.tq:427:67
  {
    // ../third_party/v8/builtins/array-sort.tq:428:5
    int31_t t1906 = 1;
    TNode<Smi> t1907 = UncheckedCast<Smi>(SmiShl(implicit_cast<TNode<Smi>>(p_run), implicit_cast<int31_t>(t1906)));
    USE(implicit_cast<TNode<Smi>>(t1907));
    TNode<Object> t1908 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_pendingRuns), implicit_cast<TNode<Smi>>(t1907)));
    TNode<Smi> t1909 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(t1908)));
    USE(implicit_cast<TNode<Smi>>(t1909));
    *_return_346 = implicit_cast<TNode<Smi>>(t1909);
    Goto(label_macro_end_1066);
  }
  BIND(label_macro_end_1066);
  return implicit_cast<TNode<Smi>>((*_return_346).value());
}

void ArrayBuiltinsFromDSLAssembler::SetPendingRunBase(TNode<FixedArray> p_pendingRuns, TNode<Smi> p_run, TNode<Smi> p_value) {
  Label label_macro_end_1067_impl(this, {});
  Label* label_macro_end_1067 = &label_macro_end_1067_impl;
  USE(label_macro_end_1067);
  // ../third_party/v8/builtins/array-sort.tq:431:74
  {
    // ../third_party/v8/builtins/array-sort.tq:432:5
    int31_t t1910 = 1;
    TNode<Smi> t1911 = UncheckedCast<Smi>(SmiShl(implicit_cast<TNode<Smi>>(p_run), implicit_cast<int31_t>(t1910)));
    USE(implicit_cast<TNode<Smi>>(t1911));
    StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>(p_pendingRuns), implicit_cast<TNode<Smi>>(t1911), implicit_cast<TNode<Object>>(p_value));
  }
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::GetPendingRunLength(TNode<FixedArray> p_pendingRuns, TNode<Smi> p_run) {
  TVARIABLE(Smi, _return_347_impl);
  auto _return_347 = &_return_347_impl;
  USE(_return_347);
  Label label_macro_end_1068_impl(this, {_return_347});
  Label* label_macro_end_1068 = &label_macro_end_1068_impl;
  USE(label_macro_end_1068);
  // ../third_party/v8/builtins/array-sort.tq:435:69
  {
    // ../third_party/v8/builtins/array-sort.tq:436:5
    int31_t t1912 = 1;
    TNode<Smi> t1913 = UncheckedCast<Smi>(SmiShl(implicit_cast<TNode<Smi>>(p_run), implicit_cast<int31_t>(t1912)));
    USE(implicit_cast<TNode<Smi>>(t1913));
    int31_t t1914 = 1;
    TNode<Smi> t1915 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t1914)));
    TNode<Smi> t1916 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(t1913), implicit_cast<TNode<Smi>>(t1915)));
    USE(implicit_cast<TNode<Smi>>(t1916));
    TNode<Object> t1917 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_pendingRuns), implicit_cast<TNode<Smi>>(t1916)));
    TNode<Smi> t1918 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(t1917)));
    USE(implicit_cast<TNode<Smi>>(t1918));
    *_return_347 = implicit_cast<TNode<Smi>>(t1918);
    Goto(label_macro_end_1068);
  }
  BIND(label_macro_end_1068);
  return implicit_cast<TNode<Smi>>((*_return_347).value());
}

void ArrayBuiltinsFromDSLAssembler::SetPendingRunLength(TNode<FixedArray> p_pendingRuns, TNode<Smi> p_run, TNode<Smi> p_value) {
  Label label_macro_end_1069_impl(this, {});
  Label* label_macro_end_1069 = &label_macro_end_1069_impl;
  USE(label_macro_end_1069);
  // ../third_party/v8/builtins/array-sort.tq:439:76
  {
    // ../third_party/v8/builtins/array-sort.tq:440:5
    int31_t t1919 = 1;
    TNode<Smi> t1920 = UncheckedCast<Smi>(SmiShl(implicit_cast<TNode<Smi>>(p_run), implicit_cast<int31_t>(t1919)));
    USE(implicit_cast<TNode<Smi>>(t1920));
    int31_t t1921 = 1;
    TNode<Smi> t1922 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t1921)));
    TNode<Smi> t1923 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(t1920), implicit_cast<TNode<Smi>>(t1922)));
    USE(implicit_cast<TNode<Smi>>(t1923));
    StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>(p_pendingRuns), implicit_cast<TNode<Smi>>(t1923), implicit_cast<TNode<Object>>(p_value));
  }
}

void ArrayBuiltinsFromDSLAssembler::PushRun(TNode<FixedArray> p_sortState, TNode<Smi> p_base, TNode<Smi> p_length) {
  Label label_macro_end_1070_impl(this, {});
  Label* label_macro_end_1070 = &label_macro_end_1070_impl;
  USE(label_macro_end_1070);
  // ../third_party/v8/builtins/array-sort.tq:443:64
  {
    // ../third_party/v8/builtins/array-sort.tq:444:5
    // ../third_party/v8/builtins/array-sort.tq:446:5
    TNode<Smi> t1924 = UncheckedCast<Smi>(GetPendingRunsSize(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Smi>>(t1924));
    TNode<Smi> stack_size_772_impl;
    auto stack_size_772 = &stack_size_772_impl;
    USE(stack_size_772);
    *stack_size_772 = implicit_cast<TNode<Smi>>(t1924);
    // ../third_party/v8/builtins/array-sort.tq:447:5
    TNode<Object> t1925 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kPendingRunsIdx())));
    TNode<FixedArray> t1926 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(t1925)));
    USE(implicit_cast<TNode<FixedArray>>(t1926));
    TNode<FixedArray> pending_runs_773_impl;
    auto pending_runs_773 = &pending_runs_773_impl;
    USE(pending_runs_773);
    *pending_runs_773 = implicit_cast<TNode<FixedArray>>(t1926);
    // ../third_party/v8/builtins/array-sort.tq:450:5
    SetPendingRunBase(implicit_cast<TNode<FixedArray>>((*pending_runs_773)), implicit_cast<TNode<Smi>>((*stack_size_772)), implicit_cast<TNode<Smi>>(p_base));
    // ../third_party/v8/builtins/array-sort.tq:451:5
    SetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_773)), implicit_cast<TNode<Smi>>((*stack_size_772)), implicit_cast<TNode<Smi>>(p_length));
    // ../third_party/v8/builtins/array-sort.tq:453:5
    int31_t t1927 = 1;
    TNode<Smi> t1928 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t1927)));
    TNode<Smi> t1929 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*stack_size_772)), implicit_cast<TNode<Smi>>(t1928)));
    USE(implicit_cast<TNode<Smi>>(t1929));
    SetPendingRunsSize(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>(t1929));
  }
}

compiler::TNode<FixedArray> ArrayBuiltinsFromDSLAssembler::GetTempArray(TNode<FixedArray> p_sortState, TNode<Smi> p_requestedSize) {
  TVARIABLE(FixedArray, _return_348_impl);
  auto _return_348 = &_return_348_impl;
  USE(_return_348);
  Label label_macro_end_1071_impl(this, {_return_348});
  Label* label_macro_end_1071 = &label_macro_end_1071_impl;
  USE(label_macro_end_1071);
  // ../third_party/v8/builtins/array-sort.tq:458:77
  {
    // ../third_party/v8/builtins/array-sort.tq:459:5
    TNode<Smi> t1930 = UncheckedCast<Smi>(SmiMax(implicit_cast<TNode<Smi>>(kSortStateTempSize()), implicit_cast<TNode<Smi>>(p_requestedSize)));
    USE(implicit_cast<TNode<Smi>>(t1930));
    TNode<Smi> min_size_774_impl;
    auto min_size_774 = &min_size_774_impl;
    USE(min_size_774);
    *min_size_774 = implicit_cast<TNode<Smi>>(t1930);
    // ../third_party/v8/builtins/array-sort.tq:461:5
    TNode<Object> t1931 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kTempArraySizeIdx())));
    TNode<Smi> t1932 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(t1931)));
    USE(implicit_cast<TNode<Smi>>(t1932));
    TNode<Smi> current_size_775_impl;
    auto current_size_775 = &current_size_775_impl;
    USE(current_size_775);
    *current_size_775 = implicit_cast<TNode<Smi>>(t1932);
    // ../third_party/v8/builtins/array-sort.tq:462:5
    {
      Label label__True_487_impl(this);
      Label* label__True_487 = &label__True_487_impl;
      USE(label__True_487);
      Label label__False_488_impl(this, {});
      Label* label__False_488 = &label__False_488_impl;
      USE(label__False_488);
      TNode<BoolT> t1933 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*current_size_775)), implicit_cast<TNode<Smi>>((*min_size_774))));
      USE(implicit_cast<TNode<BoolT>>(t1933));
      Branch(implicit_cast<TNode<BoolT>>(t1933), label__True_487, label__False_488);
      if (label__True_487->is_used())
      {
        BIND(label__True_487);
        // ../third_party/v8/builtins/array-sort.tq:462:35
        {
          // ../third_party/v8/builtins/array-sort.tq:463:7
          TNode<FixedArray> t1934 = UncheckedCast<FixedArray>(GetTempArray(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<FixedArray>>(t1934));
          *_return_348 = implicit_cast<TNode<FixedArray>>(t1934);
          Goto(label_macro_end_1071);
        }
      }
      BIND(label__False_488);
    }
    // ../third_party/v8/builtins/array-sort.tq:466:5
    TNode<IntPtrT> t1935 = UncheckedCast<IntPtrT>(convert8ATintptr(implicit_cast<TNode<Smi>>((*min_size_774))));
    USE(implicit_cast<TNode<IntPtrT>>(t1935));
    TNode<FixedArray> t1936 = UncheckedCast<FixedArray>(AllocateZeroedFixedArray(implicit_cast<TNode<IntPtrT>>(t1935)));
    USE(implicit_cast<TNode<FixedArray>>(t1936));
    TNode<FixedArray> temp_array_776_impl;
    auto temp_array_776 = &temp_array_776_impl;
    USE(temp_array_776);
    *temp_array_776 = implicit_cast<TNode<FixedArray>>(t1936);
    // ../third_party/v8/builtins/array-sort.tq:468:5
    FillFixedArrayWithSmiZero(implicit_cast<TNode<FixedArray>>((*temp_array_776)), implicit_cast<TNode<Smi>>((*min_size_774)));
    // ../third_party/v8/builtins/array-sort.tq:470:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kTempArraySizeIdx()), implicit_cast<TNode<Object>>((*min_size_774)));
    // ../third_party/v8/builtins/array-sort.tq:471:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kTempArrayIdx()), implicit_cast<TNode<Object>>((*temp_array_776)));
    // ../third_party/v8/builtins/array-sort.tq:472:5
    *_return_348 = implicit_cast<TNode<FixedArray>>((*temp_array_776));
    Goto(label_macro_end_1071);
  }
  BIND(label_macro_end_1071);
  return implicit_cast<TNode<FixedArray>>((*_return_348).value());
}

void ArrayBuiltinsFromDSLAssembler::EnsureSuccess(TNode<FixedArray> p_sortState, Label* label_Bailout_489) {
  Label label_macro_end_1072_impl(this, {});
  Label* label_macro_end_1072 = &label_macro_end_1072_impl;
  USE(label_macro_end_1072);
  // ../third_party/v8/builtins/array-sort.tq:476:61
  {
    // ../third_party/v8/builtins/array-sort.tq:477:5
    TNode<Object> t1937 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kBailoutStatusIdx())));
    TNode<Smi> t1938 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(t1937)));
    USE(implicit_cast<TNode<Smi>>(t1938));
    TNode<Smi> status_777_impl;
    auto status_777 = &status_777_impl;
    USE(status_777);
    *status_777 = implicit_cast<TNode<Smi>>(t1938);
    // ../third_party/v8/builtins/array-sort.tq:478:5
    {
      Label label__True_490_impl(this);
      Label* label__True_490 = &label__True_490_impl;
      USE(label__True_490);
      Label label__False_491_impl(this, {});
      Label* label__False_491 = &label__False_491_impl;
      USE(label__False_491);
      TNode<BoolT> t1939 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*status_777)), implicit_cast<TNode<Smi>>(kFailure())));
      USE(implicit_cast<TNode<BoolT>>(t1939));
      Branch(implicit_cast<TNode<BoolT>>(t1939), label__True_490, label__False_491);
      if (label__True_490->is_used())
      {
        BIND(label__True_490);
        // ../third_party/v8/builtins/array-sort.tq:478:29
        Goto(label_Bailout_489);
      }
      BIND(label__False_491);
    }
  }
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::Failure(TNode<FixedArray> p_sortState) {
  TVARIABLE(Smi, _return_349_impl);
  auto _return_349 = &_return_349_impl;
  USE(_return_349);
  Label label_macro_end_1073_impl(this, {_return_349});
  Label* label_macro_end_1073 = &label_macro_end_1073_impl;
  USE(label_macro_end_1073);
  // ../third_party/v8/builtins/array-sort.tq:482:45
  {
    // ../third_party/v8/builtins/array-sort.tq:483:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kBailoutStatusIdx()), implicit_cast<TNode<Object>>(kFailure()));
    // ../third_party/v8/builtins/array-sort.tq:484:5
    *_return_349 = implicit_cast<TNode<Smi>>(kFailure());
    Goto(label_macro_end_1073);
  }
  BIND(label_macro_end_1073);
  return implicit_cast<TNode<Smi>>((*_return_349).value());
}

compiler::TNode<Object> ArrayBuiltinsFromDSLAssembler::CallLoad(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_Load, TNode<HeapObject> p_elements, TNode<Smi> p_index, Label* label_Bailout_492) {
  TVARIABLE(Object, _return_350_impl);
  auto _return_350 = &_return_350_impl;
  USE(_return_350);
  Label label_macro_end_1074_impl(this, {_return_350});
  Label* label_macro_end_1074 = &label_macro_end_1074_impl;
  USE(label_macro_end_1074);
  // ../third_party/v8/builtins/array-sort.tq:493:64
  {
    // ../third_party/v8/builtins/array-sort.tq:494:5
    TNode<Object> t1940 = UncheckedCast<Object>(CallStub(Builtins::CallableFor(isolate(), Builtins::kLoad23ATFastPackedSmiElements).descriptor(), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>(p_index)));
    USE(implicit_cast<TNode<Object>>(t1940));
    TNode<Object> result_778_impl;
    auto result_778 = &result_778_impl;
    USE(result_778);
    *result_778 = implicit_cast<TNode<Object>>(t1940);
    // ../third_party/v8/builtins/array-sort.tq:495:5
    EnsureSuccess(implicit_cast<TNode<FixedArray>>(p_sortState), label_Bailout_492);
    // ../third_party/v8/builtins/array-sort.tq:496:5
    *_return_350 = implicit_cast<TNode<Object>>((*result_778));
    Goto(label_macro_end_1074);
  }
  BIND(label_macro_end_1074);
  return implicit_cast<TNode<Object>>((*_return_350).value());
}

void ArrayBuiltinsFromDSLAssembler::CallStore(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_Store, TNode<HeapObject> p_elements, TNode<Smi> p_index, TNode<Object> p_value, Label* label_Bailout_493) {
  Label label_macro_end_1075_impl(this, {});
  Label* label_macro_end_1075 = &label_macro_end_1075_impl;
  USE(label_macro_end_1075);
  // ../third_party/v8/builtins/array-sort.tq:501:71
  {
    // ../third_party/v8/builtins/array-sort.tq:502:5
    TNode<Smi> t1941 = UncheckedCast<Smi>(CallStub(Builtins::CallableFor(isolate(), Builtins::kStore23ATFastPackedSmiElements).descriptor(), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>(p_index), implicit_cast<TNode<Object>>(p_value)));
    USE(implicit_cast<TNode<Smi>>(t1941));
    // ../third_party/v8/builtins/array-sort.tq:503:5
    EnsureSuccess(implicit_cast<TNode<FixedArray>>(p_sortState), label_Bailout_493);
  }
}

void ArrayBuiltinsFromDSLAssembler::CallCopyFromTempArray(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<HeapObject> p_dstElements, TNode<Smi> p_dstPos, TNode<FixedArray> p_tempArray, TNode<Smi> p_srcPos, TNode<Smi> p_length, Label* label_Bailout_494) {
  Label label_macro_end_1076_impl(this, {});
  Label* label_macro_end_1076 = &label_macro_end_1076_impl;
  USE(label_macro_end_1076);
  // ../third_party/v8/builtins/array-sort.tq:509:18
  {
    // ../third_party/v8/builtins/array-sort.tq:510:5
    TNode<Smi> t1942 = UncheckedCast<Smi>(CallBuiltin(Builtins::kCopyFromTempArray, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>(p_dstElements), implicit_cast<TNode<Smi>>(p_dstPos), implicit_cast<TNode<FixedArray>>(p_tempArray), implicit_cast<TNode<Smi>>(p_srcPos), implicit_cast<TNode<Smi>>(p_length)));
    USE(implicit_cast<TNode<Smi>>(t1942));
    // ../third_party/v8/builtins/array-sort.tq:512:5
    EnsureSuccess(implicit_cast<TNode<FixedArray>>(p_sortState), label_Bailout_494);
  }
}

void ArrayBuiltinsFromDSLAssembler::CallCopyWithinSortArray(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<HeapObject> p_elements, TNode<Smi> p_srcPos, TNode<Smi> p_dstPos, TNode<Smi> p_length, Label* label_Bailout_495) {
  Label label_macro_end_1077_impl(this, {});
  Label* label_macro_end_1077 = &label_macro_end_1077_impl;
  USE(label_macro_end_1077);
  // ../third_party/v8/builtins/array-sort.tq:518:18
  {
    // ../third_party/v8/builtins/array-sort.tq:519:5
    TNode<Smi> t1943 = UncheckedCast<Smi>(CallBuiltin(Builtins::kCopyWithinSortArray, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>(p_srcPos), implicit_cast<TNode<Smi>>(p_dstPos), implicit_cast<TNode<Smi>>(p_length)));
    USE(implicit_cast<TNode<Smi>>(t1943));
    // ../third_party/v8/builtins/array-sort.tq:520:5
    EnsureSuccess(implicit_cast<TNode<FixedArray>>(p_sortState), label_Bailout_495);
  }
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::CallGallopRight(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_Load, TNode<Object> p_key, TNode<Smi> p_base, TNode<Smi> p_length, TNode<Smi> p_hint, TNode<Oddball> p_useTempArray, Label* label_Bailout_496) {
  TVARIABLE(Smi, _return_351_impl);
  auto _return_351 = &_return_351_impl;
  USE(_return_351);
  Label label_macro_end_1078_impl(this, {_return_351});
  Label* label_macro_end_1078 = &label_macro_end_1078_impl;
  USE(label_macro_end_1078);
  // ../third_party/v8/builtins/array-sort.tq:526:18
  {
    // ../third_party/v8/builtins/array-sort.tq:527:5
    TNode<Smi> t1944 = UncheckedCast<Smi>(CallBuiltin(Builtins::kGallopRight, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Object>>(p_key), implicit_cast<TNode<Smi>>(p_base), implicit_cast<TNode<Smi>>(p_length), implicit_cast<TNode<Smi>>(p_hint), implicit_cast<TNode<Oddball>>(p_useTempArray)));
    USE(implicit_cast<TNode<Smi>>(t1944));
    TNode<Smi> result_779_impl;
    auto result_779 = &result_779_impl;
    USE(result_779);
    *result_779 = implicit_cast<TNode<Smi>>(t1944);
    // ../third_party/v8/builtins/array-sort.tq:529:5
    EnsureSuccess(implicit_cast<TNode<FixedArray>>(p_sortState), label_Bailout_496);
    // ../third_party/v8/builtins/array-sort.tq:530:5
    *_return_351 = implicit_cast<TNode<Smi>>((*result_779));
    Goto(label_macro_end_1078);
  }
  BIND(label_macro_end_1078);
  return implicit_cast<TNode<Smi>>((*_return_351).value());
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::CallGallopLeft(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_Load, TNode<Object> p_key, TNode<Smi> p_base, TNode<Smi> p_length, TNode<Smi> p_hint, TNode<Oddball> p_useTempArray, Label* label_Bailout_497) {
  TVARIABLE(Smi, _return_352_impl);
  auto _return_352 = &_return_352_impl;
  USE(_return_352);
  Label label_macro_end_1079_impl(this, {_return_352});
  Label* label_macro_end_1079 = &label_macro_end_1079_impl;
  USE(label_macro_end_1079);
  // ../third_party/v8/builtins/array-sort.tq:536:18
  {
    // ../third_party/v8/builtins/array-sort.tq:537:5
    TNode<Smi> t1945 = UncheckedCast<Smi>(CallBuiltin(Builtins::kGallopLeft, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<Object>>(p_key), implicit_cast<TNode<Smi>>(p_base), implicit_cast<TNode<Smi>>(p_length), implicit_cast<TNode<Smi>>(p_hint), implicit_cast<TNode<Oddball>>(p_useTempArray)));
    USE(implicit_cast<TNode<Smi>>(t1945));
    TNode<Smi> result_780_impl;
    auto result_780 = &result_780_impl;
    USE(result_780);
    *result_780 = implicit_cast<TNode<Smi>>(t1945);
    // ../third_party/v8/builtins/array-sort.tq:539:5
    EnsureSuccess(implicit_cast<TNode<FixedArray>>(p_sortState), label_Bailout_497);
    // ../third_party/v8/builtins/array-sort.tq:540:5
    *_return_352 = implicit_cast<TNode<Smi>>((*result_780));
    Goto(label_macro_end_1079);
  }
  BIND(label_macro_end_1079);
  return implicit_cast<TNode<Smi>>((*_return_352).value());
}

void ArrayBuiltinsFromDSLAssembler::CallMergeAt(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Smi> p_i, Label* label_Bailout_498) {
  Label label_macro_end_1080_impl(this, {});
  Label* label_macro_end_1080 = &label_macro_end_1080_impl;
  USE(label_macro_end_1080);
  // ../third_party/v8/builtins/array-sort.tq:544:18
  {
    // ../third_party/v8/builtins/array-sort.tq:545:5
    TNode<Smi> t1946 = UncheckedCast<Smi>(CallBuiltin(Builtins::kMergeAt, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>(p_i)));
    USE(implicit_cast<TNode<Smi>>(t1946));
    // ../third_party/v8/builtins/array-sort.tq:546:5
    EnsureSuccess(implicit_cast<TNode<FixedArray>>(p_sortState), label_Bailout_498);
  }
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::GetReceiverLengthProperty(TNode<Context> p_context, TNode<FixedArray> p_sortState) {
  TVARIABLE(Smi, _return_353_impl);
  auto _return_353 = &_return_353_impl;
  USE(_return_353);
  Label label_macro_end_1081_impl(this, {_return_353});
  Label* label_macro_end_1081 = &label_macro_end_1081_impl;
  USE(label_macro_end_1081);
  // ../third_party/v8/builtins/array-sort.tq:551:53
  {
    // ../third_party/v8/builtins/array-sort.tq:552:5
    TNode<JSReceiver> t1947 = UncheckedCast<JSReceiver>(GetReceiver(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<JSReceiver>>(t1947));
    TNode<JSReceiver> receiver_781_impl;
    auto receiver_781 = &receiver_781_impl;
    USE(receiver_781);
    *receiver_781 = implicit_cast<TNode<JSReceiver>>(t1947);
    // ../third_party/v8/builtins/array-sort.tq:554:5
    {
      Label label__True_499_impl(this);
      Label* label__True_499 = &label__True_499_impl;
      USE(label__True_499);
      Label label__False_500_impl(this, {});
      Label* label__False_500 = &label__False_500_impl;
      USE(label__False_500);
      TNode<BoolT> t1948 = UncheckedCast<BoolT>(IsJSArray(implicit_cast<TNode<HeapObject>>((*receiver_781))));
      USE(implicit_cast<TNode<BoolT>>(t1948));
      Branch(implicit_cast<TNode<BoolT>>(t1948), label__True_499, label__False_500);
      if (label__True_499->is_used())
      {
        BIND(label__True_499);
        // ../third_party/v8/builtins/array-sort.tq:554:30
        TNode<JSArray> t1949 = UncheckedCast<JSArray>(unsafe_cast9ATJSArray(implicit_cast<TNode<Object>>((*receiver_781))));
        USE(implicit_cast<TNode<JSArray>>(t1949));
        TNode<Smi> t1950 = UncheckedCast<Smi>(LoadFastJSArrayLength(implicit_cast<TNode<JSArray>>(t1949)));
        *_return_353 = implicit_cast<TNode<Smi>>(t1950);
        Goto(label_macro_end_1081);
      }
      BIND(label__False_500);
    }
    // ../third_party/v8/builtins/array-sort.tq:556:5
    const char* t1951 = "length";
    TNode<Object> t1952 = UncheckedCast<Object>(from_constexpr22UT12ATHeapObject5ATSmi(implicit_cast<const char*>(t1951)));
    TNode<Object> t1953 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*receiver_781)), implicit_cast<TNode<Object>>(t1952)));
    USE(implicit_cast<TNode<Object>>(t1953));
    TNode<Number> t1954 = UncheckedCast<Number>(ToLength_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t1953)));
    USE(implicit_cast<TNode<Number>>(t1954));
    TNode<Number> len_782_impl;
    auto len_782 = &len_782_impl;
    USE(len_782);
    *len_782 = implicit_cast<TNode<Number>>(t1954);
    // ../third_party/v8/builtins/array-sort.tq:558:5
    TNode<Smi> t1955 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>((*len_782))));
    USE(implicit_cast<TNode<Smi>>(t1955));
    *_return_353 = implicit_cast<TNode<Smi>>(t1955);
    Goto(label_macro_end_1081);
  }
  BIND(label_macro_end_1081);
  return implicit_cast<TNode<Smi>>((*_return_353).value());
}

void ArrayBuiltinsFromDSLAssembler::CopyToTempArray(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_Load, TNode<HeapObject> p_srcElements, TNode<Smi> p_srcPos, TNode<FixedArray> p_tempArray, TNode<Smi> p_dstPos, TNode<Smi> p_length, Label* label_Bailout_501) {
  Label label_macro_end_1082_impl(this, {});
  Label* label_macro_end_1082 = &label_macro_end_1082_impl;
  USE(label_macro_end_1082);
  // ../third_party/v8/builtins/array-sort.tq:565:18
  {
    // ../third_party/v8/builtins/array-sort.tq:566:5
    // ../third_party/v8/builtins/array-sort.tq:567:5
    // ../third_party/v8/builtins/array-sort.tq:568:5
    // ../third_party/v8/builtins/array-sort.tq:569:5
    // ../third_party/v8/builtins/array-sort.tq:571:5
    TVARIABLE(Smi, src_idx_354_impl);
    auto src_idx_354 = &src_idx_354_impl;
    USE(src_idx_354);
    *src_idx_354 = implicit_cast<TNode<Smi>>(p_srcPos);
    // ../third_party/v8/builtins/array-sort.tq:572:5
    TVARIABLE(Smi, dst_idx_355_impl);
    auto dst_idx_355 = &dst_idx_355_impl;
    USE(dst_idx_355);
    *dst_idx_355 = implicit_cast<TNode<Smi>>(p_dstPos);
    // ../third_party/v8/builtins/array-sort.tq:573:5
    TNode<Smi> t1956 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_srcPos), implicit_cast<TNode<Smi>>(p_length)));
    USE(implicit_cast<TNode<Smi>>(t1956));
    TVARIABLE(Smi, to_356_impl);
    auto to_356 = &to_356_impl;
    USE(to_356);
    *to_356 = implicit_cast<TNode<Smi>>(t1956);
    // ../third_party/v8/builtins/array-sort.tq:575:5
    {
      Label label__True_502_impl(this);
      Label* label__True_502 = &label__True_502_impl;
      USE(label__True_502);
      Label label__False_503_impl(this);
      Label* label__False_503 = &label__False_503_impl;
      USE(label__False_503);
      Label label_header_783_1083_impl(this, {dst_idx_355, src_idx_354});
      Label* label_header_783_1083 = &label_header_783_1083_impl;
      USE(label_header_783_1083);
      Goto(label_header_783_1083);
      BIND(label_header_783_1083);
      TNode<BoolT> t1957 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*src_idx_354).value()), implicit_cast<TNode<Smi>>((*to_356).value())));
      USE(implicit_cast<TNode<BoolT>>(t1957));
      Branch(implicit_cast<TNode<BoolT>>(t1957), label__True_502, label__False_503);
      if (label__True_502->is_used())
      {
        BIND(label__True_502);
        // ../third_party/v8/builtins/array-sort.tq:575:26
        {
          // ../third_party/v8/builtins/array-sort.tq:576:7
          TNode<Smi> t1958 = implicit_cast<TNode<Smi>>((*src_idx_354).value());
          USE(t1958);
          TNode<Smi> t1959 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t1960 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*src_idx_354).value()), implicit_cast<TNode<Smi>>(t1959)));
          *src_idx_354 = implicit_cast<TNode<Smi>>(t1960);
          TNode<Object> t1961 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(p_srcElements), implicit_cast<TNode<Smi>>(t1958), label_Bailout_501));
          USE(implicit_cast<TNode<Object>>(t1961));
          TVARIABLE(Object, element_357_impl);
          auto element_357 = &element_357_impl;
          USE(element_357);
          *element_357 = implicit_cast<TNode<Object>>(t1961);
          // ../third_party/v8/builtins/array-sort.tq:579:7
          TNode<Smi> t1962 = implicit_cast<TNode<Smi>>((*dst_idx_355).value());
          USE(t1962);
          TNode<Smi> t1963 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t1964 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dst_idx_355).value()), implicit_cast<TNode<Smi>>(t1963)));
          *dst_idx_355 = implicit_cast<TNode<Smi>>(t1964);
          StoreFixedArrayElementSmi(implicit_cast<TNode<FixedArray>>(p_tempArray), implicit_cast<TNode<Smi>>(t1962), implicit_cast<TNode<Object>>((*element_357).value()));
        }
        Goto(label_header_783_1083);
      }
      BIND(label__False_503);
    }
  }
}

TF_BUILTIN(CopyFromTempArray, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_dstElements = UncheckedCast<HeapObject>(Parameter(Descriptor::kDstElements));
  USE(p_dstElements);
  TNode<Smi> p_dstPos = UncheckedCast<Smi>(Parameter(Descriptor::kDstPos));
  USE(p_dstPos);
  TNode<FixedArray> p_tempArray = UncheckedCast<FixedArray>(Parameter(Descriptor::kTempArray));
  USE(p_tempArray);
  TNode<Smi> p_srcPos = UncheckedCast<Smi>(Parameter(Descriptor::kSrcPos));
  USE(p_srcPos);
  TNode<Smi> p_length = UncheckedCast<Smi>(Parameter(Descriptor::kLength));
  USE(p_length);
  // ../third_party/v8/builtins/array-sort.tq:585:74
  {
    // ../third_party/v8/builtins/array-sort.tq:586:5
    // ../third_party/v8/builtins/array-sort.tq:587:5
    // ../third_party/v8/builtins/array-sort.tq:588:5
    // ../third_party/v8/builtins/array-sort.tq:589:5
    // ../third_party/v8/builtins/array-sort.tq:591:5
    TNode<Code> t1965 = UncheckedCast<Code>(GetStoreFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Code>>(t1965));
    TVARIABLE(Code, Store_358_impl);
    auto Store_358 = &Store_358_impl;
    USE(Store_358);
    *Store_358 = implicit_cast<TNode<Code>>(t1965);
    // ../third_party/v8/builtins/array-sort.tq:593:5
    TVARIABLE(Smi, src_idx_359_impl);
    auto src_idx_359 = &src_idx_359_impl;
    USE(src_idx_359);
    *src_idx_359 = implicit_cast<TNode<Smi>>(p_srcPos);
    // ../third_party/v8/builtins/array-sort.tq:594:5
    TVARIABLE(Smi, dst_idx_360_impl);
    auto dst_idx_360 = &dst_idx_360_impl;
    USE(dst_idx_360);
    *dst_idx_360 = implicit_cast<TNode<Smi>>(p_dstPos);
    // ../third_party/v8/builtins/array-sort.tq:595:5
    TNode<Smi> t1966 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_srcPos), implicit_cast<TNode<Smi>>(p_length)));
    USE(implicit_cast<TNode<Smi>>(t1966));
    TVARIABLE(Smi, to_361_impl);
    auto to_361 = &to_361_impl;
    USE(to_361);
    *to_361 = implicit_cast<TNode<Smi>>(t1966);
    // ../third_party/v8/builtins/array-sort.tq:596:5
    {
      Label label_try_done_784_1084_impl(this);
      Label* label_try_done_784_1084 = &label_try_done_784_1084_impl;
      USE(label_try_done_784_1084);
      Label label_Bailout_504_impl(this);
      Label* label_Bailout_504 = &label_Bailout_504_impl;
      USE(label_Bailout_504);
      Label label_try_begin_785_1085_impl(this);
      Label* label_try_begin_785_1085 = &label_try_begin_785_1085_impl;
      USE(label_try_begin_785_1085);
      Goto(label_try_begin_785_1085);
      if (label_try_begin_785_1085->is_used())
      {
        BIND(label_try_begin_785_1085);
        // ../third_party/v8/builtins/array-sort.tq:596:9
        {
          // ../third_party/v8/builtins/array-sort.tq:597:7
          {
            Label label__True_505_impl(this);
            Label* label__True_505 = &label__True_505_impl;
            USE(label__True_505);
            Label label__False_506_impl(this);
            Label* label__False_506 = &label__False_506_impl;
            USE(label__False_506);
            Label label_header_786_1086_impl(this, {dst_idx_360, src_idx_359});
            Label* label_header_786_1086 = &label_header_786_1086_impl;
            USE(label_header_786_1086);
            Goto(label_header_786_1086);
            BIND(label_header_786_1086);
            TNode<BoolT> t1967 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*src_idx_359).value()), implicit_cast<TNode<Smi>>((*to_361).value())));
            USE(implicit_cast<TNode<BoolT>>(t1967));
            Branch(implicit_cast<TNode<BoolT>>(t1967), label__True_505, label__False_506);
            if (label__True_505->is_used())
            {
              BIND(label__True_505);
              // ../third_party/v8/builtins/array-sort.tq:597:28
              {
                // ../third_party/v8/builtins/array-sort.tq:598:9
                TNode<Smi> t1968 = implicit_cast<TNode<Smi>>((*dst_idx_360).value());
                USE(t1968);
                TNode<Smi> t1969 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                TNode<Smi> t1970 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dst_idx_360).value()), implicit_cast<TNode<Smi>>(t1969)));
                *dst_idx_360 = implicit_cast<TNode<Smi>>(t1970);
                TNode<Smi> t1971 = implicit_cast<TNode<Smi>>((*src_idx_359).value());
                USE(t1971);
                TNode<Smi> t1972 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                TNode<Smi> t1973 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*src_idx_359).value()), implicit_cast<TNode<Smi>>(t1972)));
                *src_idx_359 = implicit_cast<TNode<Smi>>(t1973);
                TNode<Object> t1974 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_tempArray), implicit_cast<TNode<Smi>>(t1971)));
                CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Store_358).value()), implicit_cast<TNode<HeapObject>>(p_dstElements), implicit_cast<TNode<Smi>>(t1968), implicit_cast<TNode<Object>>(t1974), label_Bailout_504);
              }
              Goto(label_header_786_1086);
            }
            BIND(label__False_506);
          }
          // ../third_party/v8/builtins/array-sort.tq:603:7
          Return(implicit_cast<TNode<Smi>>(kSuccess()));
        }
      }
      if (label_Bailout_504->is_used())
      {
        BIND(label_Bailout_504);
        // ../third_party/v8/builtins/array-sort.tq:605:19
        {
          // ../third_party/v8/builtins/array-sort.tq:606:7
          TNode<Smi> t1975 = UncheckedCast<Smi>(Failure(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t1975));
          Return(implicit_cast<TNode<Smi>>(t1975));
        }
      }
    }
  }
}

TF_BUILTIN(CopyWithinSortArray, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_srcPos = UncheckedCast<Smi>(Parameter(Descriptor::kSrcPos));
  USE(p_srcPos);
  TNode<Smi> p_dstPos = UncheckedCast<Smi>(Parameter(Descriptor::kDstPos));
  USE(p_dstPos);
  TNode<Smi> p_length = UncheckedCast<Smi>(Parameter(Descriptor::kLength));
  USE(p_length);
  // ../third_party/v8/builtins/array-sort.tq:612:51
  {
    // ../third_party/v8/builtins/array-sort.tq:613:5
    // ../third_party/v8/builtins/array-sort.tq:614:5
    // ../third_party/v8/builtins/array-sort.tq:615:5
    // ../third_party/v8/builtins/array-sort.tq:616:5
    // ../third_party/v8/builtins/array-sort.tq:618:5
    {
      Label label_try_done_787_1087_impl(this);
      Label* label_try_done_787_1087 = &label_try_done_787_1087_impl;
      USE(label_try_done_787_1087);
      Label label_Bailout_507_impl(this);
      Label* label_Bailout_507 = &label_Bailout_507_impl;
      USE(label_Bailout_507);
      Label label_try_begin_788_1088_impl(this);
      Label* label_try_begin_788_1088 = &label_try_begin_788_1088_impl;
      USE(label_try_begin_788_1088);
      Goto(label_try_begin_788_1088);
      if (label_try_begin_788_1088->is_used())
      {
        BIND(label_try_begin_788_1088);
        // ../third_party/v8/builtins/array-sort.tq:618:9
        {
          // ../third_party/v8/builtins/array-sort.tq:619:7
          TNode<Code> t1976 = UncheckedCast<Code>(GetLoadFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Code>>(t1976));
          TVARIABLE(Code, Load_362_impl);
          auto Load_362 = &Load_362_impl;
          USE(Load_362);
          *Load_362 = implicit_cast<TNode<Code>>(t1976);
          // ../third_party/v8/builtins/array-sort.tq:620:7
          TNode<Code> t1977 = UncheckedCast<Code>(GetStoreFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Code>>(t1977));
          TVARIABLE(Code, Store_363_impl);
          auto Store_363 = &Store_363_impl;
          USE(Store_363);
          *Store_363 = implicit_cast<TNode<Code>>(t1977);
          // ../third_party/v8/builtins/array-sort.tq:622:7
          {
            Label label__True_508_impl(this);
            Label* label__True_508 = &label__True_508_impl;
            USE(label__True_508);
            Label label__False_509_impl(this);
            Label* label__False_509 = &label__False_509_impl;
            USE(label__False_509);
            Label label_if_done_label_789_1089_impl(this, {});
            Label* label_if_done_label_789_1089 = &label_if_done_label_789_1089_impl;
            USE(label_if_done_label_789_1089);
            TNode<BoolT> t1978 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>(p_srcPos), implicit_cast<TNode<Smi>>(p_dstPos)));
            USE(implicit_cast<TNode<BoolT>>(t1978));
            Branch(implicit_cast<TNode<BoolT>>(t1978), label__True_508, label__False_509);
            if (label__True_508->is_used())
            {
              BIND(label__True_508);
              // ../third_party/v8/builtins/array-sort.tq:622:28
              {
                // ../third_party/v8/builtins/array-sort.tq:623:9
                TNode<Smi> t1979 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_srcPos), implicit_cast<TNode<Smi>>(p_length)));
                USE(implicit_cast<TNode<Smi>>(t1979));
                int31_t t1980 = 1;
                TNode<Smi> t1981 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t1980)));
                TNode<Smi> t1982 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t1979), implicit_cast<TNode<Smi>>(t1981)));
                USE(implicit_cast<TNode<Smi>>(t1982));
                TVARIABLE(Smi, src_idx_364_impl);
                auto src_idx_364 = &src_idx_364_impl;
                USE(src_idx_364);
                *src_idx_364 = implicit_cast<TNode<Smi>>(t1982);
                // ../third_party/v8/builtins/array-sort.tq:624:9
                TNode<Smi> t1983 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_dstPos), implicit_cast<TNode<Smi>>(p_length)));
                USE(implicit_cast<TNode<Smi>>(t1983));
                int31_t t1984 = 1;
                TNode<Smi> t1985 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t1984)));
                TNode<Smi> t1986 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t1983), implicit_cast<TNode<Smi>>(t1985)));
                USE(implicit_cast<TNode<Smi>>(t1986));
                TVARIABLE(Smi, dst_idx_365_impl);
                auto dst_idx_365 = &dst_idx_365_impl;
                USE(dst_idx_365);
                *dst_idx_365 = implicit_cast<TNode<Smi>>(t1986);
                // ../third_party/v8/builtins/array-sort.tq:625:9
                {
                  Label label__True_510_impl(this);
                  Label* label__True_510 = &label__True_510_impl;
                  USE(label__True_510);
                  Label label__False_511_impl(this);
                  Label* label__False_511 = &label__False_511_impl;
                  USE(label__False_511);
                  Label label_header_790_1090_impl(this, {dst_idx_365, src_idx_364});
                  Label* label_header_790_1090 = &label_header_790_1090_impl;
                  USE(label_header_790_1090);
                  Goto(label_header_790_1090);
                  BIND(label_header_790_1090);
                  TNode<BoolT> t1987 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*src_idx_364).value()), implicit_cast<TNode<Smi>>(p_srcPos)));
                  USE(implicit_cast<TNode<BoolT>>(t1987));
                  Branch(implicit_cast<TNode<BoolT>>(t1987), label__True_510, label__False_511);
                  if (label__True_510->is_used())
                  {
                    BIND(label__True_510);
                    // ../third_party/v8/builtins/array-sort.tq:625:35
                    {
                      // ../third_party/v8/builtins/array-sort.tq:626:11
                      TNode<Smi> t1988 = implicit_cast<TNode<Smi>>((*src_idx_364).value());
                      USE(t1988);
                      TNode<Smi> t1989 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t1990 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*src_idx_364).value()), implicit_cast<TNode<Smi>>(t1989)));
                      *src_idx_364 = implicit_cast<TNode<Smi>>(t1990);
                      TNode<Smi> t1991 = implicit_cast<TNode<Smi>>((*dst_idx_365).value());
                      USE(t1991);
                      TNode<Smi> t1992 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t1993 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*dst_idx_365).value()), implicit_cast<TNode<Smi>>(t1992)));
                      *dst_idx_365 = implicit_cast<TNode<Smi>>(t1993);
                      CopyElement(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_362).value()), implicit_cast<TNode<Code>>((*Store_363).value()), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>(t1988), implicit_cast<TNode<Smi>>(t1991), label_Bailout_507);
                    }
                    Goto(label_header_790_1090);
                  }
                  BIND(label__False_511);
                }
              }
              Goto(label_if_done_label_789_1089);
            }
            if (label__False_509->is_used())
            {
              BIND(label__False_509);
              // ../third_party/v8/builtins/array-sort.tq:630:14
              {
                // ../third_party/v8/builtins/array-sort.tq:631:9
                TVARIABLE(Smi, src_idx_366_impl);
                auto src_idx_366 = &src_idx_366_impl;
                USE(src_idx_366);
                *src_idx_366 = implicit_cast<TNode<Smi>>(p_srcPos);
                // ../third_party/v8/builtins/array-sort.tq:632:9
                TVARIABLE(Smi, dst_idx_367_impl);
                auto dst_idx_367 = &dst_idx_367_impl;
                USE(dst_idx_367);
                *dst_idx_367 = implicit_cast<TNode<Smi>>(p_dstPos);
                // ../third_party/v8/builtins/array-sort.tq:633:9
                TNode<Smi> t1994 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_srcPos), implicit_cast<TNode<Smi>>(p_length)));
                USE(implicit_cast<TNode<Smi>>(t1994));
                TVARIABLE(Smi, to_368_impl);
                auto to_368 = &to_368_impl;
                USE(to_368);
                *to_368 = implicit_cast<TNode<Smi>>(t1994);
                // ../third_party/v8/builtins/array-sort.tq:634:9
                {
                  Label label__True_512_impl(this);
                  Label* label__True_512 = &label__True_512_impl;
                  USE(label__True_512);
                  Label label__False_513_impl(this);
                  Label* label__False_513 = &label__False_513_impl;
                  USE(label__False_513);
                  Label label_header_791_1091_impl(this, {dst_idx_367, src_idx_366});
                  Label* label_header_791_1091 = &label_header_791_1091_impl;
                  USE(label_header_791_1091);
                  Goto(label_header_791_1091);
                  BIND(label_header_791_1091);
                  TNode<BoolT> t1995 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*src_idx_366).value()), implicit_cast<TNode<Smi>>((*to_368).value())));
                  USE(implicit_cast<TNode<BoolT>>(t1995));
                  Branch(implicit_cast<TNode<BoolT>>(t1995), label__True_512, label__False_513);
                  if (label__True_512->is_used())
                  {
                    BIND(label__True_512);
                    // ../third_party/v8/builtins/array-sort.tq:634:30
                    {
                      // ../third_party/v8/builtins/array-sort.tq:635:11
                      TNode<Smi> t1996 = implicit_cast<TNode<Smi>>((*src_idx_366).value());
                      USE(t1996);
                      TNode<Smi> t1997 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t1998 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*src_idx_366).value()), implicit_cast<TNode<Smi>>(t1997)));
                      *src_idx_366 = implicit_cast<TNode<Smi>>(t1998);
                      TNode<Smi> t1999 = implicit_cast<TNode<Smi>>((*dst_idx_367).value());
                      USE(t1999);
                      TNode<Smi> t2000 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t2001 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dst_idx_367).value()), implicit_cast<TNode<Smi>>(t2000)));
                      *dst_idx_367 = implicit_cast<TNode<Smi>>(t2001);
                      CopyElement(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_362).value()), implicit_cast<TNode<Code>>((*Store_363).value()), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>(t1996), implicit_cast<TNode<Smi>>(t1999), label_Bailout_507);
                    }
                    Goto(label_header_791_1091);
                  }
                  BIND(label__False_513);
                }
              }
              Goto(label_if_done_label_789_1089);
            }
            BIND(label_if_done_label_789_1089);
          }
          // ../third_party/v8/builtins/array-sort.tq:640:7
          Return(implicit_cast<TNode<Smi>>(kSuccess()));
        }
      }
      if (label_Bailout_507->is_used())
      {
        BIND(label_Bailout_507);
        // ../third_party/v8/builtins/array-sort.tq:642:19
        {
          // ../third_party/v8/builtins/array-sort.tq:643:7
          TNode<Smi> t2002 = UncheckedCast<Smi>(Failure(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t2002));
          Return(implicit_cast<TNode<Smi>>(t2002));
        }
      }
    }
  }
}

TF_BUILTIN(BinaryInsertionSort, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<Smi> p_low = UncheckedCast<Smi>(Parameter(Descriptor::kLow));
  USE(p_low);
  TNode<Smi> p_startArg = UncheckedCast<Smi>(Parameter(Descriptor::kStartArg));
  USE(p_startArg);
  TNode<Smi> p_high = UncheckedCast<Smi>(Parameter(Descriptor::kHigh));
  USE(p_high);
  // ../third_party/v8/builtins/array-sort.tq:659:23
  {
    // ../third_party/v8/builtins/array-sort.tq:660:5
    // ../third_party/v8/builtins/array-sort.tq:662:5
    {
      Label label_try_done_792_1092_impl(this);
      Label* label_try_done_792_1092 = &label_try_done_792_1092_impl;
      USE(label_try_done_792_1092);
      Label label_Bailout_514_impl(this);
      Label* label_Bailout_514 = &label_Bailout_514_impl;
      USE(label_Bailout_514);
      Label label_try_begin_793_1093_impl(this);
      Label* label_try_begin_793_1093 = &label_try_begin_793_1093_impl;
      USE(label_try_begin_793_1093);
      Goto(label_try_begin_793_1093);
      if (label_try_begin_793_1093->is_used())
      {
        BIND(label_try_begin_793_1093);
        // ../third_party/v8/builtins/array-sort.tq:662:9
        {
          // ../third_party/v8/builtins/array-sort.tq:663:7
          TNode<HeapObject> t2003 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<HeapObject>>(t2003));
          TVARIABLE(HeapObject, elements_369_impl);
          auto elements_369 = &elements_369_impl;
          USE(elements_369);
          *elements_369 = implicit_cast<TNode<HeapObject>>(t2003);
          // ../third_party/v8/builtins/array-sort.tq:665:7
          TNode<Code> t2004 = UncheckedCast<Code>(GetLoadFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Code>>(t2004));
          TNode<Code> Load_794_impl;
          auto Load_794 = &Load_794_impl;
          USE(Load_794);
          *Load_794 = implicit_cast<TNode<Code>>(t2004);
          // ../third_party/v8/builtins/array-sort.tq:666:7
          TNode<Code> t2005 = UncheckedCast<Code>(GetStoreFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Code>>(t2005));
          TNode<Code> Store_795_impl;
          auto Store_795 = &Store_795_impl;
          USE(Store_795);
          *Store_795 = implicit_cast<TNode<Code>>(t2005);
          // ../third_party/v8/builtins/array-sort.tq:668:7
          auto t2006 = [=]() {
            int31_t t2008 = 1;
            TNode<Smi> t2009 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2008)));
            TNode<Smi> t2010 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_startArg), implicit_cast<TNode<Smi>>(t2009)));
            USE(implicit_cast<TNode<Smi>>(t2010));
            return implicit_cast<TNode<Smi>>(t2010);
          };
          auto t2007 = [=]() {
            return implicit_cast<TNode<Smi>>(p_startArg);
          };
          TVARIABLE(Smi, t2011_796_impl);
          auto t2011_796 = &t2011_796_impl;
          USE(t2011_796);
          {
            Label label__True_515_impl(this);
            Label* label__True_515 = &label__True_515_impl;
            USE(label__True_515);
            Label label__False_516_impl(this);
            Label* label__False_516 = &label__False_516_impl;
            USE(label__False_516);
            Label label__done_797_1094_impl(this, {t2011_796});
            Label* label__done_797_1094 = &label__done_797_1094_impl;
            USE(label__done_797_1094);
            TNode<BoolT> t2012 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>(p_low), implicit_cast<TNode<Smi>>(p_startArg)));
            USE(implicit_cast<TNode<BoolT>>(t2012));
            Branch(implicit_cast<TNode<BoolT>>(t2012), label__True_515, label__False_516);
            BIND(label__True_515);
                        *t2011_796 = implicit_cast<TNode<Smi>>(t2006());
            Goto(label__done_797_1094);
            BIND(label__False_516);
                        *t2011_796 = implicit_cast<TNode<Smi>>(t2007());
            Goto(label__done_797_1094);
            BIND(label__done_797_1094);
          }
          TVARIABLE(Smi, start_370_impl);
          auto start_370 = &start_370_impl;
          USE(start_370);
          *start_370 = implicit_cast<TNode<Smi>>((*t2011_796).value());
          // ../third_party/v8/builtins/array-sort.tq:670:7
          Label label__True_517_impl(this);
          Label* label__True_517 = &label__True_517_impl;
          USE(label__True_517);
          Label label__False_518_impl(this);
          Label* label__False_518 = &label__False_518_impl;
          USE(label__False_518);
          Label label_header_798_1095_impl(this, {elements_369, start_370});
          Label* label_header_798_1095 = &label_header_798_1095_impl;
          USE(label_header_798_1095);
          Goto(label_header_798_1095);
          BIND(label_header_798_1095);
          Label label_action_799_1096_impl(this);
          Label* label_action_799_1096 = &label_action_799_1096_impl;
          USE(label_action_799_1096);
          TNode<BoolT> t2013 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*start_370).value()), implicit_cast<TNode<Smi>>(p_high)));
          USE(implicit_cast<TNode<BoolT>>(t2013));
          Branch(implicit_cast<TNode<BoolT>>(t2013), label__True_517, label__False_518);
          if (label__True_517->is_used())
          {
            BIND(label__True_517);
            // ../third_party/v8/builtins/array-sort.tq:670:37
            {
              // ../third_party/v8/builtins/array-sort.tq:672:9
              TVARIABLE(Smi, left_371_impl);
              auto left_371 = &left_371_impl;
              USE(left_371);
              *left_371 = implicit_cast<TNode<Smi>>(p_low);
              // ../third_party/v8/builtins/array-sort.tq:673:9
              TVARIABLE(Smi, right_372_impl);
              auto right_372 = &right_372_impl;
              USE(right_372);
              *right_372 = implicit_cast<TNode<Smi>>((*start_370).value());
              // ../third_party/v8/builtins/array-sort.tq:675:9
              TNode<Object> t2014 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_794)), implicit_cast<TNode<HeapObject>>((*elements_369).value()), implicit_cast<TNode<Smi>>((*right_372).value()), label_Bailout_514));
              USE(implicit_cast<TNode<Object>>(t2014));
              TNode<Object> pivot_800_impl;
              auto pivot_800 = &pivot_800_impl;
              USE(pivot_800);
              *pivot_800 = implicit_cast<TNode<Object>>(t2014);
              // ../third_party/v8/builtins/array-sort.tq:682:9
              // ../third_party/v8/builtins/array-sort.tq:685:9
              {
                Label label__True_519_impl(this);
                Label* label__True_519 = &label__True_519_impl;
                USE(label__True_519);
                Label label__False_520_impl(this);
                Label* label__False_520 = &label__False_520_impl;
                USE(label__False_520);
                Label label_header_801_1097_impl(this, {elements_369, left_371, right_372});
                Label* label_header_801_1097 = &label_header_801_1097_impl;
                USE(label_header_801_1097);
                Goto(label_header_801_1097);
                BIND(label_header_801_1097);
                TNode<BoolT> t2015 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*left_371).value()), implicit_cast<TNode<Smi>>((*right_372).value())));
                USE(implicit_cast<TNode<BoolT>>(t2015));
                Branch(implicit_cast<TNode<BoolT>>(t2015), label__True_519, label__False_520);
                if (label__True_519->is_used())
                {
                  BIND(label__True_519);
                  // ../third_party/v8/builtins/array-sort.tq:685:30
                  {
                    // ../third_party/v8/builtins/array-sort.tq:686:11
                    TNode<Smi> t2016 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*right_372).value()), implicit_cast<TNode<Smi>>((*left_371).value())));
                    USE(implicit_cast<TNode<Smi>>(t2016));
                    int31_t t2017 = 1;
                    TNode<Smi> t2018 = UncheckedCast<Smi>(SmiShr(implicit_cast<TNode<Smi>>(t2016), implicit_cast<int31_t>(t2017)));
                    USE(implicit_cast<TNode<Smi>>(t2018));
                    TNode<Smi> t2019 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*left_371).value()), implicit_cast<TNode<Smi>>(t2018)));
                    USE(implicit_cast<TNode<Smi>>(t2019));
                    TNode<Smi> mid_802_impl;
                    auto mid_802 = &mid_802_impl;
                    USE(mid_802);
                    *mid_802 = implicit_cast<TNode<Smi>>(t2019);
                    // ../third_party/v8/builtins/array-sort.tq:687:11
                    TNode<Object> t2020 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_794)), implicit_cast<TNode<HeapObject>>((*elements_369).value()), implicit_cast<TNode<Smi>>((*mid_802)), label_Bailout_514));
                    USE(implicit_cast<TNode<Object>>(t2020));
                    TNode<Object> mid_element_803_impl;
                    auto mid_element_803 = &mid_element_803_impl;
                    USE(mid_element_803);
                    *mid_element_803 = implicit_cast<TNode<Object>>(t2020);
                    // ../third_party/v8/builtins/array-sort.tq:690:11
                    TNode<Number> t2021 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>((*pivot_800)), implicit_cast<TNode<Object>>((*mid_element_803)), label_Bailout_514));
                    USE(implicit_cast<TNode<Number>>(t2021));
                    TNode<Number> order_804_impl;
                    auto order_804 = &order_804_impl;
                    USE(order_804);
                    *order_804 = implicit_cast<TNode<Number>>(t2021);
                    // ../third_party/v8/builtins/array-sort.tq:693:11
                    TNode<HeapObject> t2022 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
                    USE(implicit_cast<TNode<HeapObject>>(t2022));
                    *elements_369 = implicit_cast<TNode<HeapObject>>(t2022);
                    // ../third_party/v8/builtins/array-sort.tq:695:11
                    {
                      Label label__True_521_impl(this);
                      Label* label__True_521 = &label__True_521_impl;
                      USE(label__True_521);
                      Label label__False_522_impl(this);
                      Label* label__False_522 = &label__False_522_impl;
                      USE(label__False_522);
                      Label label_if_done_label_805_1098_impl(this, {left_371, right_372});
                      Label* label_if_done_label_805_1098 = &label_if_done_label_805_1098_impl;
                      USE(label_if_done_label_805_1098);
                      int31_t t2023 = 0;
                      TNode<Number> t2024 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2023)));
                      BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_804)), implicit_cast<TNode<Number>>(t2024), label__True_521, label__False_522);
                      if (label__True_521->is_used())
                      {
                        BIND(label__True_521);
                        // ../third_party/v8/builtins/array-sort.tq:695:26
                        {
                          // ../third_party/v8/builtins/array-sort.tq:696:13
                          *right_372 = implicit_cast<TNode<Smi>>((*mid_802));
                        }
                        Goto(label_if_done_label_805_1098);
                      }
                      if (label__False_522->is_used())
                      {
                        BIND(label__False_522);
                        // ../third_party/v8/builtins/array-sort.tq:697:18
                        {
                          // ../third_party/v8/builtins/array-sort.tq:698:13
                          int31_t t2025 = 1;
                          TNode<Smi> t2026 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2025)));
                          TNode<Smi> t2027 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*mid_802)), implicit_cast<TNode<Smi>>(t2026)));
                          USE(implicit_cast<TNode<Smi>>(t2027));
                          *left_371 = implicit_cast<TNode<Smi>>(t2027);
                        }
                        Goto(label_if_done_label_805_1098);
                      }
                      BIND(label_if_done_label_805_1098);
                    }
                  }
                  Goto(label_header_801_1097);
                }
                BIND(label__False_520);
              }
              // ../third_party/v8/builtins/array-sort.tq:701:9
              // ../third_party/v8/builtins/array-sort.tq:711:9
              TVARIABLE(Smi, p_373_impl);
              auto p_373 = &p_373_impl;
              USE(p_373);
              *p_373 = implicit_cast<TNode<Smi>>((*start_370).value());
              Label label__True_523_impl(this);
              Label* label__True_523 = &label__True_523_impl;
              USE(label__True_523);
              Label label__False_524_impl(this);
              Label* label__False_524 = &label__False_524_impl;
              USE(label__False_524);
              Label label_header_806_1099_impl(this, {p_373});
              Label* label_header_806_1099 = &label_header_806_1099_impl;
              USE(label_header_806_1099);
              Goto(label_header_806_1099);
              BIND(label_header_806_1099);
              Label label_action_807_1100_impl(this);
              Label* label_action_807_1100 = &label_action_807_1100_impl;
              USE(label_action_807_1100);
              TNode<BoolT> t2028 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*p_373).value()), implicit_cast<TNode<Smi>>((*left_371).value())));
              USE(implicit_cast<TNode<BoolT>>(t2028));
              Branch(implicit_cast<TNode<BoolT>>(t2028), label__True_523, label__False_524);
              if (label__True_523->is_used())
              {
                BIND(label__True_523);
                // ../third_party/v8/builtins/array-sort.tq:711:49
                {
                  // ../third_party/v8/builtins/array-sort.tq:712:11
                  int31_t t2029 = 1;
                  TNode<Smi> t2030 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2029)));
                  TNode<Smi> t2031 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*p_373).value()), implicit_cast<TNode<Smi>>(t2030)));
                  USE(implicit_cast<TNode<Smi>>(t2031));
                  CopyElement(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_794)), implicit_cast<TNode<Code>>((*Store_795)), implicit_cast<TNode<HeapObject>>((*elements_369).value()), implicit_cast<TNode<Smi>>(t2031), implicit_cast<TNode<Smi>>((*p_373).value()), label_Bailout_514);
                }
                Goto(label_action_807_1100);
              }
              {
                BIND(label_action_807_1100);
                TNode<Smi> t2032 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                TNode<Smi> t2033 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*p_373).value()), implicit_cast<TNode<Smi>>(t2032)));
                *p_373 = implicit_cast<TNode<Smi>>(t2033);
                Goto(label_header_806_1099);
              }
              BIND(label__False_524);
              // ../third_party/v8/builtins/array-sort.tq:715:9
              CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Store_795)), implicit_cast<TNode<HeapObject>>((*elements_369).value()), implicit_cast<TNode<Smi>>((*left_371).value()), implicit_cast<TNode<Object>>((*pivot_800)), label_Bailout_514);
            }
            Goto(label_action_799_1096);
          }
          {
            BIND(label_action_799_1096);
            TNode<Smi> t2034 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
            TNode<Smi> t2035 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*start_370).value()), implicit_cast<TNode<Smi>>(t2034)));
            *start_370 = implicit_cast<TNode<Smi>>(t2035);
            Goto(label_header_798_1095);
          }
          BIND(label__False_518);
          // ../third_party/v8/builtins/array-sort.tq:718:7
          Return(implicit_cast<TNode<Smi>>(kSuccess()));
        }
      }
      if (label_Bailout_514->is_used())
      {
        BIND(label_Bailout_514);
        // ../third_party/v8/builtins/array-sort.tq:720:19
        {
          // ../third_party/v8/builtins/array-sort.tq:721:7
          TNode<Smi> t2036 = UncheckedCast<Smi>(Failure(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t2036));
          Return(implicit_cast<TNode<Smi>>(t2036));
        }
      }
    }
  }
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::CountAndMakeRun(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Smi> p_lowArg, TNode<Smi> p_high, Label* label_Bailout_525) {
  TVARIABLE(Smi, _return_374_impl);
  auto _return_374 = &_return_374_impl;
  USE(_return_374);
  Label label_macro_end_1101_impl(this, {_return_374});
  Label* label_macro_end_1101 = &label_macro_end_1101_impl;
  USE(label_macro_end_1101);
  // ../third_party/v8/builtins/array-sort.tq:744:18
  {
    // ../third_party/v8/builtins/array-sort.tq:745:5
    // ../third_party/v8/builtins/array-sort.tq:747:5
    TNode<HeapObject> t2037 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<HeapObject>>(t2037));
    TVARIABLE(HeapObject, elements_375_impl);
    auto elements_375 = &elements_375_impl;
    USE(elements_375);
    *elements_375 = implicit_cast<TNode<HeapObject>>(t2037);
    // ../third_party/v8/builtins/array-sort.tq:748:5
    TNode<Code> t2038 = UncheckedCast<Code>(GetLoadFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Code>>(t2038));
    TNode<Code> Load_808_impl;
    auto Load_808 = &Load_808_impl;
    USE(Load_808);
    *Load_808 = implicit_cast<TNode<Code>>(t2038);
    // ../third_party/v8/builtins/array-sort.tq:749:5
    TNode<Code> t2039 = UncheckedCast<Code>(GetStoreFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Code>>(t2039));
    TNode<Code> Store_809_impl;
    auto Store_809 = &Store_809_impl;
    USE(Store_809);
    *Store_809 = implicit_cast<TNode<Code>>(t2039);
    // ../third_party/v8/builtins/array-sort.tq:751:5
    int31_t t2040 = 1;
    TNode<Smi> t2041 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2040)));
    TNode<Smi> t2042 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_lowArg), implicit_cast<TNode<Smi>>(t2041)));
    USE(implicit_cast<TNode<Smi>>(t2042));
    TVARIABLE(Smi, low_376_impl);
    auto low_376 = &low_376_impl;
    USE(low_376);
    *low_376 = implicit_cast<TNode<Smi>>(t2042);
    // ../third_party/v8/builtins/array-sort.tq:752:5
    {
      Label label__True_526_impl(this);
      Label* label__True_526 = &label__True_526_impl;
      USE(label__True_526);
      Label label__False_527_impl(this, {});
      Label* label__False_527 = &label__False_527_impl;
      USE(label__False_527);
      TNode<BoolT> t2043 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*low_376).value()), implicit_cast<TNode<Smi>>(p_high)));
      USE(implicit_cast<TNode<BoolT>>(t2043));
      Branch(implicit_cast<TNode<BoolT>>(t2043), label__True_526, label__False_527);
      if (label__True_526->is_used())
      {
        BIND(label__True_526);
        // ../third_party/v8/builtins/array-sort.tq:752:22
        int31_t t2044 = 1;
        TNode<Smi> t2045 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2044)));
        *_return_374 = implicit_cast<TNode<Smi>>(t2045);
        Goto(label_macro_end_1101);
      }
      BIND(label__False_527);
    }
    // ../third_party/v8/builtins/array-sort.tq:754:5
    int31_t t2046 = 2;
    TVARIABLE(Smi, run_length_377_impl);
    auto run_length_377 = &run_length_377_impl;
    USE(run_length_377);
    TNode<Smi> t2047 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2046)));
    *run_length_377 = implicit_cast<TNode<Smi>>(t2047);
    // ../third_party/v8/builtins/array-sort.tq:756:5
    TNode<Object> t2048 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_808)), implicit_cast<TNode<HeapObject>>((*elements_375).value()), implicit_cast<TNode<Smi>>((*low_376).value()), label_Bailout_525));
    USE(implicit_cast<TNode<Object>>(t2048));
    TNode<Object> element_low_810_impl;
    auto element_low_810 = &element_low_810_impl;
    USE(element_low_810);
    *element_low_810 = implicit_cast<TNode<Object>>(t2048);
    // ../third_party/v8/builtins/array-sort.tq:758:5
    int31_t t2049 = 1;
    TNode<Smi> t2050 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2049)));
    TNode<Smi> t2051 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*low_376).value()), implicit_cast<TNode<Smi>>(t2050)));
    USE(implicit_cast<TNode<Smi>>(t2051));
    TNode<Object> t2052 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_808)), implicit_cast<TNode<HeapObject>>((*elements_375).value()), implicit_cast<TNode<Smi>>(t2051), label_Bailout_525));
    USE(implicit_cast<TNode<Object>>(t2052));
    TNode<Object> element_low_pred_811_impl;
    auto element_low_pred_811 = &element_low_pred_811_impl;
    USE(element_low_pred_811);
    *element_low_pred_811 = implicit_cast<TNode<Object>>(t2052);
    // ../third_party/v8/builtins/array-sort.tq:760:5
    TNode<Number> t2053 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>((*element_low_810)), implicit_cast<TNode<Object>>((*element_low_pred_811)), label_Bailout_525));
    USE(implicit_cast<TNode<Number>>(t2053));
    TVARIABLE(Number, order_378_impl);
    auto order_378 = &order_378_impl;
    USE(order_378);
    *order_378 = implicit_cast<TNode<Number>>(t2053);
    // ../third_party/v8/builtins/array-sort.tq:763:5
    TNode<HeapObject> t2054 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<HeapObject>>(t2054));
    *elements_375 = implicit_cast<TNode<HeapObject>>(t2054);
    // ../third_party/v8/builtins/array-sort.tq:768:5
    auto t2055 = [=]() {
      return implicit_cast<bool>(true);
    };
    auto t2056 = [=]() {
      return implicit_cast<bool>(false);
    };
    TVARIABLE(BoolT, t2057_812_impl);
    auto t2057_812 = &t2057_812_impl;
    USE(t2057_812);
    {
      Label label__True_528_impl(this);
      Label* label__True_528 = &label__True_528_impl;
      USE(label__True_528);
      Label label__False_529_impl(this);
      Label* label__False_529 = &label__False_529_impl;
      USE(label__False_529);
      Label label__done_813_1102_impl(this, {t2057_812});
      Label* label__done_813_1102 = &label__done_813_1102_impl;
      USE(label__done_813_1102);
      int31_t t2058 = 0;
      TNode<Number> t2059 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2058)));
      BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_378).value()), implicit_cast<TNode<Number>>(t2059), label__True_528, label__False_529);
      BIND(label__True_528);
            TNode<BoolT> t2060 = UncheckedCast<BoolT>(from_constexpr6ATbool(implicit_cast<bool>(t2055())));
      *t2057_812 = implicit_cast<TNode<BoolT>>(t2060);
      Goto(label__done_813_1102);
      BIND(label__False_529);
            TNode<BoolT> t2061 = UncheckedCast<BoolT>(from_constexpr6ATbool(implicit_cast<bool>(t2056())));
      *t2057_812 = implicit_cast<TNode<BoolT>>(t2061);
      Goto(label__done_813_1102);
      BIND(label__done_813_1102);
    }
    TNode<BoolT> is_descending_814_impl;
    auto is_descending_814 = &is_descending_814_impl;
    USE(is_descending_814);
    *is_descending_814 = implicit_cast<TNode<BoolT>>((*t2057_812).value());
    // ../third_party/v8/builtins/array-sort.tq:770:5
    TVARIABLE(Object, previous_element_379_impl);
    auto previous_element_379 = &previous_element_379_impl;
    USE(previous_element_379);
    *previous_element_379 = implicit_cast<TNode<Object>>((*element_low_810));
    // ../third_party/v8/builtins/array-sort.tq:771:5
    int31_t t2062 = 1;
    TNode<Smi> t2063 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2062)));
    TNode<Smi> t2064 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*low_376).value()), implicit_cast<TNode<Smi>>(t2063)));
    USE(implicit_cast<TNode<Smi>>(t2064));
    TVARIABLE(Smi, idx_380_impl);
    auto idx_380 = &idx_380_impl;
    USE(idx_380);
    *idx_380 = implicit_cast<TNode<Smi>>(t2064);
    Label label__True_530_impl(this);
    Label* label__True_530 = &label__True_530_impl;
    USE(label__True_530);
    Label label__False_531_impl(this);
    Label* label__False_531 = &label__False_531_impl;
    USE(label__False_531);
    Label label_header_815_1103_impl(this, {elements_375, idx_380, order_378, previous_element_379, run_length_377});
    Label* label_header_815_1103 = &label_header_815_1103_impl;
    USE(label_header_815_1103);
    Goto(label_header_815_1103);
    BIND(label_header_815_1103);
    Label label_action_816_1104_impl(this);
    Label* label_action_816_1104 = &label_action_816_1104_impl;
    USE(label_action_816_1104);
    TNode<BoolT> t2065 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*idx_380).value()), implicit_cast<TNode<Smi>>(p_high)));
    USE(implicit_cast<TNode<BoolT>>(t2065));
    Branch(implicit_cast<TNode<BoolT>>(t2065), label__True_530, label__False_531);
    if (label__True_530->is_used())
    {
      BIND(label__True_530);
      // ../third_party/v8/builtins/array-sort.tq:771:53
      {
        // ../third_party/v8/builtins/array-sort.tq:772:7
        TNode<Object> t2066 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_808)), implicit_cast<TNode<HeapObject>>((*elements_375).value()), implicit_cast<TNode<Smi>>((*idx_380).value()), label_Bailout_525));
        USE(implicit_cast<TNode<Object>>(t2066));
        TNode<Object> current_element_817_impl;
        auto current_element_817 = &current_element_817_impl;
        USE(current_element_817);
        *current_element_817 = implicit_cast<TNode<Object>>(t2066);
        // ../third_party/v8/builtins/array-sort.tq:774:7
        TNode<Number> t2067 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>((*current_element_817)), implicit_cast<TNode<Object>>((*previous_element_379).value()), label_Bailout_525));
        USE(implicit_cast<TNode<Number>>(t2067));
        *order_378 = implicit_cast<TNode<Number>>(t2067);
        // ../third_party/v8/builtins/array-sort.tq:777:7
        TNode<HeapObject> t2068 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
        USE(implicit_cast<TNode<HeapObject>>(t2068));
        *elements_375 = implicit_cast<TNode<HeapObject>>(t2068);
        // ../third_party/v8/builtins/array-sort.tq:779:7
        {
          Label label__True_532_impl(this);
          Label* label__True_532 = &label__True_532_impl;
          USE(label__True_532);
          Label label__False_533_impl(this);
          Label* label__False_533 = &label__False_533_impl;
          USE(label__False_533);
          Label label_if_done_label_818_1105_impl(this, {});
          Label* label_if_done_label_818_1105 = &label_if_done_label_818_1105_impl;
          USE(label_if_done_label_818_1105);
          Branch(implicit_cast<TNode<BoolT>>((*is_descending_814)), label__True_532, label__False_533);
          if (label__True_532->is_used())
          {
            BIND(label__True_532);
            // ../third_party/v8/builtins/array-sort.tq:779:26
            {
              // ../third_party/v8/builtins/array-sort.tq:780:9
              {
                Label label__True_534_impl(this);
                Label* label__True_534 = &label__True_534_impl;
                USE(label__True_534);
                Label label__False_535_impl(this, {});
                Label* label__False_535 = &label__False_535_impl;
                USE(label__False_535);
                int31_t t2069 = 0;
                TNode<Number> t2070 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2069)));
                BranchIfNumberGreaterThanOrEqual(implicit_cast<TNode<Number>>((*order_378).value()), implicit_cast<TNode<Number>>(t2070), label__True_534, label__False_535);
                if (label__True_534->is_used())
                {
                  BIND(label__True_534);
                  // ../third_party/v8/builtins/array-sort.tq:780:25
                  Goto(label__False_531);
                }
                BIND(label__False_535);
              }
            }
            Goto(label_if_done_label_818_1105);
          }
          if (label__False_533->is_used())
          {
            BIND(label__False_533);
            // ../third_party/v8/builtins/array-sort.tq:781:14
            {
              // ../third_party/v8/builtins/array-sort.tq:782:9
              {
                Label label__True_536_impl(this);
                Label* label__True_536 = &label__True_536_impl;
                USE(label__True_536);
                Label label__False_537_impl(this, {});
                Label* label__False_537 = &label__False_537_impl;
                USE(label__False_537);
                int31_t t2071 = 0;
                TNode<Number> t2072 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2071)));
                BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_378).value()), implicit_cast<TNode<Number>>(t2072), label__True_536, label__False_537);
                if (label__True_536->is_used())
                {
                  BIND(label__True_536);
                  // ../third_party/v8/builtins/array-sort.tq:782:24
                  Goto(label__False_531);
                }
                BIND(label__False_537);
              }
            }
            Goto(label_if_done_label_818_1105);
          }
          BIND(label_if_done_label_818_1105);
        }
        // ../third_party/v8/builtins/array-sort.tq:785:7
        *previous_element_379 = implicit_cast<TNode<Object>>((*current_element_817));
        // ../third_party/v8/builtins/array-sort.tq:786:7
        TNode<Smi> t2073 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
        TNode<Smi> t2074 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*run_length_377).value()), implicit_cast<TNode<Smi>>(t2073)));
        *run_length_377 = implicit_cast<TNode<Smi>>(t2074);
      }
      Goto(label_action_816_1104);
    }
    {
      BIND(label_action_816_1104);
      TNode<Smi> t2075 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
      TNode<Smi> t2076 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*idx_380).value()), implicit_cast<TNode<Smi>>(t2075)));
      *idx_380 = implicit_cast<TNode<Smi>>(t2076);
      Goto(label_header_815_1103);
    }
    BIND(label__False_531);
    // ../third_party/v8/builtins/array-sort.tq:789:5
    {
      Label label__True_538_impl(this);
      Label* label__True_538 = &label__True_538_impl;
      USE(label__True_538);
      Label label__False_539_impl(this, {});
      Label* label__False_539 = &label__False_539_impl;
      USE(label__False_539);
      Branch(implicit_cast<TNode<BoolT>>((*is_descending_814)), label__True_538, label__False_539);
      if (label__True_538->is_used())
      {
        BIND(label__True_538);
        // ../third_party/v8/builtins/array-sort.tq:789:24
        {
          // ../third_party/v8/builtins/array-sort.tq:790:7
          TNode<Smi> t2077 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_lowArg), implicit_cast<TNode<Smi>>((*run_length_377).value())));
          USE(implicit_cast<TNode<Smi>>(t2077));
          ReverseRange(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_808)), implicit_cast<TNode<Code>>((*Store_809)), implicit_cast<TNode<HeapObject>>((*elements_375).value()), implicit_cast<TNode<Smi>>(p_lowArg), implicit_cast<TNode<Smi>>(t2077), label_Bailout_525);
        }
        Goto(label__False_539);
      }
      BIND(label__False_539);
    }
    // ../third_party/v8/builtins/array-sort.tq:796:5
    *_return_374 = implicit_cast<TNode<Smi>>((*run_length_377).value());
    Goto(label_macro_end_1101);
  }
  BIND(label_macro_end_1101);
  return implicit_cast<TNode<Smi>>((*_return_374).value());
}

void ArrayBuiltinsFromDSLAssembler::ReverseRange(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_Load, TNode<Code> p_Store, TNode<HeapObject> p_elements, TNode<Smi> p_from, TNode<Smi> p_to, Label* label_Bailout_540) {
  Label label_macro_end_1106_impl(this, {});
  Label* label_macro_end_1106 = &label_macro_end_1106_impl;
  USE(label_macro_end_1106);
  // ../third_party/v8/builtins/array-sort.tq:802:18
  {
    // ../third_party/v8/builtins/array-sort.tq:803:5
    TVARIABLE(Smi, low_381_impl);
    auto low_381 = &low_381_impl;
    USE(low_381);
    *low_381 = implicit_cast<TNode<Smi>>(p_from);
    // ../third_party/v8/builtins/array-sort.tq:804:5
    int31_t t2078 = 1;
    TNode<Smi> t2079 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2078)));
    TNode<Smi> t2080 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_to), implicit_cast<TNode<Smi>>(t2079)));
    USE(implicit_cast<TNode<Smi>>(t2080));
    TVARIABLE(Smi, high_382_impl);
    auto high_382 = &high_382_impl;
    USE(high_382);
    *high_382 = implicit_cast<TNode<Smi>>(t2080);
    // ../third_party/v8/builtins/array-sort.tq:806:5
    {
      Label label__True_541_impl(this);
      Label* label__True_541 = &label__True_541_impl;
      USE(label__True_541);
      Label label__False_542_impl(this);
      Label* label__False_542 = &label__False_542_impl;
      USE(label__False_542);
      Label label_header_819_1107_impl(this, {high_382, low_381});
      Label* label_header_819_1107 = &label_header_819_1107_impl;
      USE(label_header_819_1107);
      Goto(label_header_819_1107);
      BIND(label_header_819_1107);
      TNode<BoolT> t2081 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*low_381).value()), implicit_cast<TNode<Smi>>((*high_382).value())));
      USE(implicit_cast<TNode<BoolT>>(t2081));
      Branch(implicit_cast<TNode<BoolT>>(t2081), label__True_541, label__False_542);
      if (label__True_541->is_used())
      {
        BIND(label__True_541);
        // ../third_party/v8/builtins/array-sort.tq:806:24
        {
          // ../third_party/v8/builtins/array-sort.tq:807:7
          TNode<Object> t2082 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>((*low_381).value()), label_Bailout_540));
          USE(implicit_cast<TNode<Object>>(t2082));
          TNode<Object> element_low_820_impl;
          auto element_low_820 = &element_low_820_impl;
          USE(element_low_820);
          *element_low_820 = implicit_cast<TNode<Object>>(t2082);
          // ../third_party/v8/builtins/array-sort.tq:809:7
          TNode<Object> t2083 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>((*high_382).value()), label_Bailout_540));
          USE(implicit_cast<TNode<Object>>(t2083));
          TNode<Object> element_high_821_impl;
          auto element_high_821 = &element_high_821_impl;
          USE(element_high_821);
          *element_high_821 = implicit_cast<TNode<Object>>(t2083);
          // ../third_party/v8/builtins/array-sort.tq:811:7
          TNode<Smi> t2084 = implicit_cast<TNode<Smi>>((*low_381).value());
          USE(t2084);
          TNode<Smi> t2085 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t2086 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*low_381).value()), implicit_cast<TNode<Smi>>(t2085)));
          *low_381 = implicit_cast<TNode<Smi>>(t2086);
          CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>(t2084), implicit_cast<TNode<Object>>((*element_high_821)), label_Bailout_540);
          // ../third_party/v8/builtins/array-sort.tq:813:7
          TNode<Smi> t2087 = implicit_cast<TNode<Smi>>((*high_382).value());
          USE(t2087);
          TNode<Smi> t2088 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t2089 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*high_382).value()), implicit_cast<TNode<Smi>>(t2088)));
          *high_382 = implicit_cast<TNode<Smi>>(t2089);
          CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>(t2087), implicit_cast<TNode<Object>>((*element_low_820)), label_Bailout_540);
        }
        Goto(label_header_819_1107);
      }
      BIND(label__False_542);
    }
  }
}

TF_BUILTIN(MergeAt, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<Smi> p_i = UncheckedCast<Smi>(Parameter(Descriptor::kI));
  USE(p_i);
  // ../third_party/v8/builtins/array-sort.tq:820:73
  {
    // ../third_party/v8/builtins/array-sort.tq:821:5
    TNode<Smi> t2090 = UncheckedCast<Smi>(GetPendingRunsSize(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Smi>>(t2090));
    TNode<Smi> stack_size_822_impl;
    auto stack_size_822 = &stack_size_822_impl;
    USE(stack_size_822);
    *stack_size_822 = implicit_cast<TNode<Smi>>(t2090);
    // ../third_party/v8/builtins/array-sort.tq:825:5
    // ../third_party/v8/builtins/array-sort.tq:826:5
    // ../third_party/v8/builtins/array-sort.tq:827:5
    // ../third_party/v8/builtins/array-sort.tq:829:5
    TNode<HeapObject> t2091 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<HeapObject>>(t2091));
    TVARIABLE(HeapObject, elements_383_impl);
    auto elements_383 = &elements_383_impl;
    USE(elements_383);
    *elements_383 = implicit_cast<TNode<HeapObject>>(t2091);
    // ../third_party/v8/builtins/array-sort.tq:830:5
    TNode<Code> t2092 = UncheckedCast<Code>(GetLoadFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Code>>(t2092));
    TNode<Code> Load_823_impl;
    auto Load_823 = &Load_823_impl;
    USE(Load_823);
    *Load_823 = implicit_cast<TNode<Code>>(t2092);
    // ../third_party/v8/builtins/array-sort.tq:832:5
    TNode<Object> t2093 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kPendingRunsIdx())));
    TNode<FixedArray> t2094 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(t2093)));
    USE(implicit_cast<TNode<FixedArray>>(t2094));
    TNode<FixedArray> pending_runs_824_impl;
    auto pending_runs_824 = &pending_runs_824_impl;
    USE(pending_runs_824);
    *pending_runs_824 = implicit_cast<TNode<FixedArray>>(t2094);
    // ../third_party/v8/builtins/array-sort.tq:834:5
    TNode<Smi> t2095 = UncheckedCast<Smi>(GetPendingRunBase(implicit_cast<TNode<FixedArray>>((*pending_runs_824)), implicit_cast<TNode<Smi>>(p_i)));
    USE(implicit_cast<TNode<Smi>>(t2095));
    TVARIABLE(Smi, base_a_384_impl);
    auto base_a_384 = &base_a_384_impl;
    USE(base_a_384);
    *base_a_384 = implicit_cast<TNode<Smi>>(t2095);
    // ../third_party/v8/builtins/array-sort.tq:835:5
    TNode<Smi> t2096 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_824)), implicit_cast<TNode<Smi>>(p_i)));
    USE(implicit_cast<TNode<Smi>>(t2096));
    TVARIABLE(Smi, length_a_385_impl);
    auto length_a_385 = &length_a_385_impl;
    USE(length_a_385);
    *length_a_385 = implicit_cast<TNode<Smi>>(t2096);
    // ../third_party/v8/builtins/array-sort.tq:836:5
    int31_t t2097 = 1;
    TNode<Smi> t2098 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2097)));
    TNode<Smi> t2099 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_i), implicit_cast<TNode<Smi>>(t2098)));
    USE(implicit_cast<TNode<Smi>>(t2099));
    TNode<Smi> t2100 = UncheckedCast<Smi>(GetPendingRunBase(implicit_cast<TNode<FixedArray>>((*pending_runs_824)), implicit_cast<TNode<Smi>>(t2099)));
    USE(implicit_cast<TNode<Smi>>(t2100));
    TVARIABLE(Smi, base_b_386_impl);
    auto base_b_386 = &base_b_386_impl;
    USE(base_b_386);
    *base_b_386 = implicit_cast<TNode<Smi>>(t2100);
    // ../third_party/v8/builtins/array-sort.tq:837:5
    int31_t t2101 = 1;
    TNode<Smi> t2102 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2101)));
    TNode<Smi> t2103 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_i), implicit_cast<TNode<Smi>>(t2102)));
    USE(implicit_cast<TNode<Smi>>(t2103));
    TNode<Smi> t2104 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_824)), implicit_cast<TNode<Smi>>(t2103)));
    USE(implicit_cast<TNode<Smi>>(t2104));
    TVARIABLE(Smi, length_b_387_impl);
    auto length_b_387 = &length_b_387_impl;
    USE(length_b_387);
    *length_b_387 = implicit_cast<TNode<Smi>>(t2104);
    // ../third_party/v8/builtins/array-sort.tq:838:5
    // ../third_party/v8/builtins/array-sort.tq:839:5
    // ../third_party/v8/builtins/array-sort.tq:844:5
    TNode<Smi> t2105 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*length_a_385).value()), implicit_cast<TNode<Smi>>((*length_b_387).value())));
    USE(implicit_cast<TNode<Smi>>(t2105));
    SetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_824)), implicit_cast<TNode<Smi>>(p_i), implicit_cast<TNode<Smi>>(t2105));
    // ../third_party/v8/builtins/array-sort.tq:845:5
    {
      Label label__True_543_impl(this);
      Label* label__True_543 = &label__True_543_impl;
      USE(label__True_543);
      Label label__False_544_impl(this, {});
      Label* label__False_544 = &label__False_544_impl;
      USE(label__False_544);
      int31_t t2106 = 3;
      TNode<Smi> t2107 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2106)));
      TNode<Smi> t2108 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*stack_size_822)), implicit_cast<TNode<Smi>>(t2107)));
      USE(implicit_cast<TNode<Smi>>(t2108));
      TNode<BoolT> t2109 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>(p_i), implicit_cast<TNode<Smi>>(t2108)));
      USE(implicit_cast<TNode<BoolT>>(t2109));
      Branch(implicit_cast<TNode<BoolT>>(t2109), label__True_543, label__False_544);
      if (label__True_543->is_used())
      {
        BIND(label__True_543);
        // ../third_party/v8/builtins/array-sort.tq:845:30
        {
          // ../third_party/v8/builtins/array-sort.tq:846:7
          int31_t t2110 = 2;
          TNode<Smi> t2111 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2110)));
          TNode<Smi> t2112 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_i), implicit_cast<TNode<Smi>>(t2111)));
          USE(implicit_cast<TNode<Smi>>(t2112));
          TNode<Smi> t2113 = UncheckedCast<Smi>(GetPendingRunBase(implicit_cast<TNode<FixedArray>>((*pending_runs_824)), implicit_cast<TNode<Smi>>(t2112)));
          USE(implicit_cast<TNode<Smi>>(t2113));
          TNode<Smi> base_825_impl;
          auto base_825 = &base_825_impl;
          USE(base_825);
          *base_825 = implicit_cast<TNode<Smi>>(t2113);
          // ../third_party/v8/builtins/array-sort.tq:847:7
          int31_t t2114 = 2;
          TNode<Smi> t2115 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2114)));
          TNode<Smi> t2116 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_i), implicit_cast<TNode<Smi>>(t2115)));
          USE(implicit_cast<TNode<Smi>>(t2116));
          TNode<Smi> t2117 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_824)), implicit_cast<TNode<Smi>>(t2116)));
          USE(implicit_cast<TNode<Smi>>(t2117));
          TNode<Smi> length_826_impl;
          auto length_826 = &length_826_impl;
          USE(length_826);
          *length_826 = implicit_cast<TNode<Smi>>(t2117);
          // ../third_party/v8/builtins/array-sort.tq:848:7
          int31_t t2118 = 1;
          TNode<Smi> t2119 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2118)));
          TNode<Smi> t2120 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_i), implicit_cast<TNode<Smi>>(t2119)));
          USE(implicit_cast<TNode<Smi>>(t2120));
          SetPendingRunBase(implicit_cast<TNode<FixedArray>>((*pending_runs_824)), implicit_cast<TNode<Smi>>(t2120), implicit_cast<TNode<Smi>>((*base_825)));
          // ../third_party/v8/builtins/array-sort.tq:849:7
          int31_t t2121 = 1;
          TNode<Smi> t2122 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2121)));
          TNode<Smi> t2123 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_i), implicit_cast<TNode<Smi>>(t2122)));
          USE(implicit_cast<TNode<Smi>>(t2123));
          SetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_824)), implicit_cast<TNode<Smi>>(t2123), implicit_cast<TNode<Smi>>((*length_826)));
        }
        Goto(label__False_544);
      }
      BIND(label__False_544);
    }
    // ../third_party/v8/builtins/array-sort.tq:851:5
    int31_t t2124 = 1;
    TNode<Smi> t2125 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2124)));
    TNode<Smi> t2126 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*stack_size_822)), implicit_cast<TNode<Smi>>(t2125)));
    USE(implicit_cast<TNode<Smi>>(t2126));
    SetPendingRunsSize(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>(t2126));
    // ../third_party/v8/builtins/array-sort.tq:853:5
    {
      Label label_try_done_827_1108_impl(this);
      Label* label_try_done_827_1108 = &label_try_done_827_1108_impl;
      USE(label_try_done_827_1108);
      Label label_Bailout_545_impl(this);
      Label* label_Bailout_545 = &label_Bailout_545_impl;
      USE(label_Bailout_545);
      Label label_try_begin_828_1109_impl(this);
      Label* label_try_begin_828_1109 = &label_try_begin_828_1109_impl;
      USE(label_try_begin_828_1109);
      Goto(label_try_begin_828_1109);
      if (label_try_begin_828_1109->is_used())
      {
        BIND(label_try_begin_828_1109);
        // ../third_party/v8/builtins/array-sort.tq:853:9
        {
          // ../third_party/v8/builtins/array-sort.tq:856:7
          TNode<Object> t2127 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_823)), implicit_cast<TNode<HeapObject>>((*elements_383).value()), implicit_cast<TNode<Smi>>((*base_b_386).value()), label_Bailout_545));
          USE(implicit_cast<TNode<Object>>(t2127));
          TNode<Object> key_right_829_impl;
          auto key_right_829 = &key_right_829_impl;
          USE(key_right_829);
          *key_right_829 = implicit_cast<TNode<Object>>(t2127);
          // ../third_party/v8/builtins/array-sort.tq:859:7
          int31_t t2128 = 0;
          TNode<Smi> t2129 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2128)));
          TNode<Smi> t2130 = UncheckedCast<Smi>(CallGallopRight(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_823)), implicit_cast<TNode<Object>>((*key_right_829)), implicit_cast<TNode<Smi>>((*base_a_384).value()), implicit_cast<TNode<Smi>>((*length_a_385).value()), implicit_cast<TNode<Smi>>(t2129), implicit_cast<TNode<Oddball>>(False()), label_Bailout_545));
          USE(implicit_cast<TNode<Smi>>(t2130));
          TNode<Smi> k_830_impl;
          auto k_830 = &k_830_impl;
          USE(k_830);
          *k_830 = implicit_cast<TNode<Smi>>(t2130);
          // ../third_party/v8/builtins/array-sort.tq:862:7
          TNode<HeapObject> t2131 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<HeapObject>>(t2131));
          *elements_383 = implicit_cast<TNode<HeapObject>>(t2131);
          // ../third_party/v8/builtins/array-sort.tq:863:7
          // ../third_party/v8/builtins/array-sort.tq:865:7
          TNode<Smi> t2132 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*base_a_384).value()), implicit_cast<TNode<Smi>>((*k_830))));
          USE(implicit_cast<TNode<Smi>>(t2132));
          *base_a_384 = implicit_cast<TNode<Smi>>(t2132);
          // ../third_party/v8/builtins/array-sort.tq:866:7
          TNode<Smi> t2133 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_a_385).value()), implicit_cast<TNode<Smi>>((*k_830))));
          USE(implicit_cast<TNode<Smi>>(t2133));
          *length_a_385 = implicit_cast<TNode<Smi>>(t2133);
          // ../third_party/v8/builtins/array-sort.tq:867:7
          {
            Label label__True_546_impl(this);
            Label* label__True_546 = &label__True_546_impl;
            USE(label__True_546);
            Label label__False_547_impl(this, {});
            Label* label__False_547 = &label__False_547_impl;
            USE(label__False_547);
            int31_t t2134 = 0;
            TNode<Smi> t2135 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2134)));
            TNode<BoolT> t2136 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_a_385).value()), implicit_cast<TNode<Smi>>(t2135)));
            USE(implicit_cast<TNode<BoolT>>(t2136));
            Branch(implicit_cast<TNode<BoolT>>(t2136), label__True_546, label__False_547);
            if (label__True_546->is_used())
            {
              BIND(label__True_546);
              // ../third_party/v8/builtins/array-sort.tq:867:26
              Return(implicit_cast<TNode<Smi>>(kSuccess()));
            }
            BIND(label__False_547);
          }
          // ../third_party/v8/builtins/array-sort.tq:868:7
          // ../third_party/v8/builtins/array-sort.tq:872:7
          TNode<Smi> t2137 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*base_a_384).value()), implicit_cast<TNode<Smi>>((*length_a_385).value())));
          USE(implicit_cast<TNode<Smi>>(t2137));
          int31_t t2138 = 1;
          TNode<Smi> t2139 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2138)));
          TNode<Smi> t2140 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t2137), implicit_cast<TNode<Smi>>(t2139)));
          USE(implicit_cast<TNode<Smi>>(t2140));
          TNode<Object> t2141 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_823)), implicit_cast<TNode<HeapObject>>((*elements_383).value()), implicit_cast<TNode<Smi>>(t2140), label_Bailout_545));
          USE(implicit_cast<TNode<Object>>(t2141));
          TVARIABLE(Object, key_left_388_impl);
          auto key_left_388 = &key_left_388_impl;
          USE(key_left_388);
          *key_left_388 = implicit_cast<TNode<Object>>(t2141);
          // ../third_party/v8/builtins/array-sort.tq:875:7
          int31_t t2142 = 1;
          TNode<Smi> t2143 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2142)));
          TNode<Smi> t2144 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_387).value()), implicit_cast<TNode<Smi>>(t2143)));
          USE(implicit_cast<TNode<Smi>>(t2144));
          TNode<Smi> t2145 = UncheckedCast<Smi>(CallGallopLeft(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Load_823)), implicit_cast<TNode<Object>>((*key_left_388).value()), implicit_cast<TNode<Smi>>((*base_b_386).value()), implicit_cast<TNode<Smi>>((*length_b_387).value()), implicit_cast<TNode<Smi>>(t2144), implicit_cast<TNode<Oddball>>(False()), label_Bailout_545));
          USE(implicit_cast<TNode<Smi>>(t2145));
          *length_b_387 = implicit_cast<TNode<Smi>>(t2145);
          // ../third_party/v8/builtins/array-sort.tq:878:7
          TNode<HeapObject> t2146 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<HeapObject>>(t2146));
          *elements_383 = implicit_cast<TNode<HeapObject>>(t2146);
          // ../third_party/v8/builtins/array-sort.tq:879:7
          // ../third_party/v8/builtins/array-sort.tq:880:7
          {
            Label label__True_548_impl(this);
            Label* label__True_548 = &label__True_548_impl;
            USE(label__True_548);
            Label label__False_549_impl(this, {});
            Label* label__False_549 = &label__False_549_impl;
            USE(label__False_549);
            int31_t t2147 = 0;
            TNode<Smi> t2148 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2147)));
            TNode<BoolT> t2149 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_b_387).value()), implicit_cast<TNode<Smi>>(t2148)));
            USE(implicit_cast<TNode<BoolT>>(t2149));
            Branch(implicit_cast<TNode<BoolT>>(t2149), label__True_548, label__False_549);
            if (label__True_548->is_used())
            {
              BIND(label__True_548);
              // ../third_party/v8/builtins/array-sort.tq:880:26
              Return(implicit_cast<TNode<Smi>>(kSuccess()));
            }
            BIND(label__False_549);
          }
          // ../third_party/v8/builtins/array-sort.tq:884:7
          {
            Label label__True_550_impl(this);
            Label* label__True_550 = &label__True_550_impl;
            USE(label__True_550);
            Label label__False_551_impl(this);
            Label* label__False_551 = &label__False_551_impl;
            USE(label__False_551);
            Label label_if_done_label_831_1110_impl(this, {});
            Label* label_if_done_label_831_1110 = &label_if_done_label_831_1110_impl;
            USE(label_if_done_label_831_1110);
            TNode<BoolT> t2150 = UncheckedCast<BoolT>(SmiLessThanOrEqual(implicit_cast<TNode<Smi>>((*length_a_385).value()), implicit_cast<TNode<Smi>>((*length_b_387).value())));
            USE(implicit_cast<TNode<BoolT>>(t2150));
            Branch(implicit_cast<TNode<BoolT>>(t2150), label__True_550, label__False_551);
            if (label__True_550->is_used())
            {
              BIND(label__True_550);
              // ../third_party/v8/builtins/array-sort.tq:884:33
              {
                // ../third_party/v8/builtins/array-sort.tq:885:9
                MergeLow(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>((*base_a_384).value()), implicit_cast<TNode<Smi>>((*length_a_385).value()), implicit_cast<TNode<Smi>>((*base_b_386).value()), implicit_cast<TNode<Smi>>((*length_b_387).value()), label_Bailout_545);
              }
              Goto(label_if_done_label_831_1110);
            }
            if (label__False_551->is_used())
            {
              BIND(label__False_551);
              // ../third_party/v8/builtins/array-sort.tq:887:14
              {
                // ../third_party/v8/builtins/array-sort.tq:888:9
                MergeHigh(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>((*base_a_384).value()), implicit_cast<TNode<Smi>>((*length_a_385).value()), implicit_cast<TNode<Smi>>((*base_b_386).value()), implicit_cast<TNode<Smi>>((*length_b_387).value()), label_Bailout_545);
              }
              Goto(label_if_done_label_831_1110);
            }
            BIND(label_if_done_label_831_1110);
          }
          // ../third_party/v8/builtins/array-sort.tq:891:7
          Return(implicit_cast<TNode<Smi>>(kSuccess()));
        }
      }
      if (label_Bailout_545->is_used())
      {
        BIND(label_Bailout_545);
        // ../third_party/v8/builtins/array-sort.tq:893:19
        {
          // ../third_party/v8/builtins/array-sort.tq:894:7
          TNode<Smi> t2151 = UncheckedCast<Smi>(Failure(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t2151));
          Return(implicit_cast<TNode<Smi>>(t2151));
        }
      }
    }
  }
}

compiler::TNode<HeapObject> ArrayBuiltinsFromDSLAssembler::LoadElementsOrTempArray(TNode<Oddball> p_useTempArray, TNode<FixedArray> p_sortState) {
  TVARIABLE(HeapObject, _return_389_impl);
  auto _return_389 = &_return_389_impl;
  USE(_return_389);
  Label label_macro_end_1111_impl(this, {_return_389});
  Label* label_macro_end_1111 = &label_macro_end_1111_impl;
  USE(label_macro_end_1111);
  // ../third_party/v8/builtins/array-sort.tq:899:65
  {
    // ../third_party/v8/builtins/array-sort.tq:900:5
    auto t2152 = [=]() {
      TNode<FixedArray> t2154 = UncheckedCast<FixedArray>(GetTempArray(implicit_cast<TNode<FixedArray>>(p_sortState)));
      USE(implicit_cast<TNode<FixedArray>>(t2154));
      return implicit_cast<TNode<FixedArray>>(t2154);
    };
    auto t2153 = [=]() {
      TNode<HeapObject> t2155 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
      USE(implicit_cast<TNode<HeapObject>>(t2155));
      return implicit_cast<TNode<HeapObject>>(t2155);
    };
    TVARIABLE(HeapObject, t2156_832_impl);
    auto t2156_832 = &t2156_832_impl;
    USE(t2156_832);
    {
      Label label__True_552_impl(this);
      Label* label__True_552 = &label__True_552_impl;
      USE(label__True_552);
      Label label__False_553_impl(this);
      Label* label__False_553 = &label__False_553_impl;
      USE(label__False_553);
      Label label__done_833_1112_impl(this, {t2156_832});
      Label* label__done_833_1112 = &label__done_833_1112_impl;
      USE(label__done_833_1112);
      TNode<BoolT> t2157 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>(p_useTempArray), implicit_cast<TNode<Object>>(True())));
      USE(implicit_cast<TNode<BoolT>>(t2157));
      Branch(implicit_cast<TNode<BoolT>>(t2157), label__True_552, label__False_553);
      BIND(label__True_552);
            *t2156_832 = implicit_cast<TNode<HeapObject>>(t2152());
      Goto(label__done_833_1112);
      BIND(label__False_553);
            *t2156_832 = implicit_cast<TNode<HeapObject>>(t2153());
      Goto(label__done_833_1112);
      BIND(label__done_833_1112);
    }
    *_return_389 = implicit_cast<TNode<HeapObject>>((*t2156_832).value());
    Goto(label_macro_end_1111);
  }
  BIND(label_macro_end_1111);
  return implicit_cast<TNode<HeapObject>>((*_return_389).value());
}

TF_BUILTIN(GallopLeft, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<Code> p_Load = UncheckedCast<Code>(Parameter(Descriptor::kLoad));
  USE(p_Load);
  TNode<Object> p_key = UncheckedCast<Object>(Parameter(Descriptor::kKey));
  USE(p_key);
  TNode<Smi> p_base = UncheckedCast<Smi>(Parameter(Descriptor::kBase));
  USE(p_base);
  TNode<Smi> p_length = UncheckedCast<Smi>(Parameter(Descriptor::kLength));
  USE(p_length);
  TNode<Smi> p_hint = UncheckedCast<Smi>(Parameter(Descriptor::kHint));
  USE(p_hint);
  TNode<Oddball> p_useTempArray = UncheckedCast<Oddball>(Parameter(Descriptor::kUseTempArray));
  USE(p_useTempArray);
  // ../third_party/v8/builtins/array-sort.tq:923:70
  {
    // ../third_party/v8/builtins/array-sort.tq:924:5
    // ../third_party/v8/builtins/array-sort.tq:925:5
    // ../third_party/v8/builtins/array-sort.tq:927:5
    int31_t t2158 = 0;
    TVARIABLE(Smi, last_ofs_390_impl);
    auto last_ofs_390 = &last_ofs_390_impl;
    USE(last_ofs_390);
    TNode<Smi> t2159 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2158)));
    *last_ofs_390 = implicit_cast<TNode<Smi>>(t2159);
    // ../third_party/v8/builtins/array-sort.tq:928:5
    int31_t t2160 = 1;
    TVARIABLE(Smi, offset_391_impl);
    auto offset_391 = &offset_391_impl;
    USE(offset_391);
    TNode<Smi> t2161 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2160)));
    *offset_391 = implicit_cast<TNode<Smi>>(t2161);
    // ../third_party/v8/builtins/array-sort.tq:930:5
    {
      Label label_try_done_834_1113_impl(this);
      Label* label_try_done_834_1113 = &label_try_done_834_1113_impl;
      USE(label_try_done_834_1113);
      Label label_Bailout_554_impl(this);
      Label* label_Bailout_554 = &label_Bailout_554_impl;
      USE(label_Bailout_554);
      Label label_try_begin_835_1114_impl(this);
      Label* label_try_begin_835_1114 = &label_try_begin_835_1114_impl;
      USE(label_try_begin_835_1114);
      Goto(label_try_begin_835_1114);
      if (label_try_begin_835_1114->is_used())
      {
        BIND(label_try_begin_835_1114);
        // ../third_party/v8/builtins/array-sort.tq:930:9
        {
          // ../third_party/v8/builtins/array-sort.tq:931:7
          TNode<HeapObject> t2162 = UncheckedCast<HeapObject>(LoadElementsOrTempArray(implicit_cast<TNode<Oddball>>(p_useTempArray), implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<HeapObject>>(t2162));
          TNode<Smi> t2163 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_base), implicit_cast<TNode<Smi>>(p_hint)));
          USE(implicit_cast<TNode<Smi>>(t2163));
          TNode<Object> t2164 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(t2162), implicit_cast<TNode<Smi>>(t2163), label_Bailout_554));
          USE(implicit_cast<TNode<Object>>(t2164));
          TNode<Object> base_hint_element_836_impl;
          auto base_hint_element_836 = &base_hint_element_836_impl;
          USE(base_hint_element_836);
          *base_hint_element_836 = implicit_cast<TNode<Object>>(t2164);
          // ../third_party/v8/builtins/array-sort.tq:935:7
          TNode<Number> t2165 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>((*base_hint_element_836)), implicit_cast<TNode<Object>>(p_key), label_Bailout_554));
          USE(implicit_cast<TNode<Number>>(t2165));
          TVARIABLE(Number, order_392_impl);
          auto order_392 = &order_392_impl;
          USE(order_392);
          *order_392 = implicit_cast<TNode<Number>>(t2165);
          // ../third_party/v8/builtins/array-sort.tq:939:7
          {
            Label label__True_555_impl(this);
            Label* label__True_555 = &label__True_555_impl;
            USE(label__True_555);
            Label label__False_556_impl(this);
            Label* label__False_556 = &label__False_556_impl;
            USE(label__False_556);
            Label label_if_done_label_837_1115_impl(this, {last_ofs_390, offset_391, order_392});
            Label* label_if_done_label_837_1115 = &label_if_done_label_837_1115_impl;
            USE(label_if_done_label_837_1115);
            int31_t t2166 = 0;
            TNode<Number> t2167 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2166)));
            BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_392).value()), implicit_cast<TNode<Number>>(t2167), label__True_555, label__False_556);
            if (label__True_555->is_used())
            {
              BIND(label__True_555);
              // ../third_party/v8/builtins/array-sort.tq:939:22
              {
                // ../third_party/v8/builtins/array-sort.tq:944:9
                TNode<Smi> t2168 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_length), implicit_cast<TNode<Smi>>(p_hint)));
                USE(implicit_cast<TNode<Smi>>(t2168));
                TVARIABLE(Smi, max_ofs_393_impl);
                auto max_ofs_393 = &max_ofs_393_impl;
                USE(max_ofs_393);
                *max_ofs_393 = implicit_cast<TNode<Smi>>(t2168);
                // ../third_party/v8/builtins/array-sort.tq:945:9
                {
                  Label label__True_557_impl(this);
                  Label* label__True_557 = &label__True_557_impl;
                  USE(label__True_557);
                  Label label__False_558_impl(this);
                  Label* label__False_558 = &label__False_558_impl;
                  USE(label__False_558);
                  Label label_header_838_1116_impl(this, {last_ofs_390, offset_391, order_392});
                  Label* label_header_838_1116 = &label_header_838_1116_impl;
                  USE(label_header_838_1116);
                  Goto(label_header_838_1116);
                  BIND(label_header_838_1116);
                  TNode<BoolT> t2169 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*offset_391).value()), implicit_cast<TNode<Smi>>((*max_ofs_393).value())));
                  USE(implicit_cast<TNode<BoolT>>(t2169));
                  Branch(implicit_cast<TNode<BoolT>>(t2169), label__True_557, label__False_558);
                  if (label__True_557->is_used())
                  {
                    BIND(label__True_557);
                    // ../third_party/v8/builtins/array-sort.tq:945:34
                    {
                      // ../third_party/v8/builtins/array-sort.tq:946:11
                      TNode<HeapObject> t2170 = UncheckedCast<HeapObject>(LoadElementsOrTempArray(implicit_cast<TNode<Oddball>>(p_useTempArray), implicit_cast<TNode<FixedArray>>(p_sortState)));
                      USE(implicit_cast<TNode<HeapObject>>(t2170));
                      TNode<Smi> t2171 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_base), implicit_cast<TNode<Smi>>(p_hint)));
                      USE(implicit_cast<TNode<Smi>>(t2171));
                      TNode<Smi> t2172 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(t2171), implicit_cast<TNode<Smi>>((*offset_391).value())));
                      USE(implicit_cast<TNode<Smi>>(t2172));
                      TNode<Object> t2173 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(t2170), implicit_cast<TNode<Smi>>(t2172), label_Bailout_554));
                      USE(implicit_cast<TNode<Object>>(t2173));
                      TNode<Object> offset_element_839_impl;
                      auto offset_element_839 = &offset_element_839_impl;
                      USE(offset_element_839);
                      *offset_element_839 = implicit_cast<TNode<Object>>(t2173);
                      // ../third_party/v8/builtins/array-sort.tq:951:11
                      TNode<Number> t2174 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>((*offset_element_839)), implicit_cast<TNode<Object>>(p_key), label_Bailout_554));
                      USE(implicit_cast<TNode<Number>>(t2174));
                      *order_392 = implicit_cast<TNode<Number>>(t2174);
                      // ../third_party/v8/builtins/array-sort.tq:955:11
                      {
                        Label label__True_559_impl(this);
                        Label* label__True_559 = &label__True_559_impl;
                        USE(label__True_559);
                        Label label__False_560_impl(this, {});
                        Label* label__False_560 = &label__False_560_impl;
                        USE(label__False_560);
                        int31_t t2175 = 0;
                        TNode<Number> t2176 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2175)));
                        BranchIfNumberGreaterThanOrEqual(implicit_cast<TNode<Number>>((*order_392).value()), implicit_cast<TNode<Number>>(t2176), label__True_559, label__False_560);
                        if (label__True_559->is_used())
                        {
                          BIND(label__True_559);
                          // ../third_party/v8/builtins/array-sort.tq:955:27
                          Goto(label__False_558);
                        }
                        BIND(label__False_560);
                      }
                      // ../third_party/v8/builtins/array-sort.tq:957:11
                      *last_ofs_390 = implicit_cast<TNode<Smi>>((*offset_391).value());
                      // ../third_party/v8/builtins/array-sort.tq:958:11
                      int31_t t2177 = 1;
                      TNode<Smi> t2178 = UncheckedCast<Smi>(SmiShl(implicit_cast<TNode<Smi>>((*offset_391).value()), implicit_cast<int31_t>(t2177)));
                      USE(implicit_cast<TNode<Smi>>(t2178));
                      int31_t t2179 = 1;
                      TNode<Smi> t2180 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2179)));
                      TNode<Smi> t2181 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(t2178), implicit_cast<TNode<Smi>>(t2180)));
                      USE(implicit_cast<TNode<Smi>>(t2181));
                      *offset_391 = implicit_cast<TNode<Smi>>(t2181);
                      // ../third_party/v8/builtins/array-sort.tq:961:11
                      {
                        Label label__True_561_impl(this);
                        Label* label__True_561 = &label__True_561_impl;
                        USE(label__True_561);
                        Label label__False_562_impl(this, {offset_391});
                        Label* label__False_562 = &label__False_562_impl;
                        USE(label__False_562);
                        int31_t t2182 = 0;
                        TNode<Smi> t2183 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2182)));
                        TNode<BoolT> t2184 = UncheckedCast<BoolT>(SmiLessThanOrEqual(implicit_cast<TNode<Smi>>((*offset_391).value()), implicit_cast<TNode<Smi>>(t2183)));
                        USE(implicit_cast<TNode<BoolT>>(t2184));
                        Branch(implicit_cast<TNode<BoolT>>(t2184), label__True_561, label__False_562);
                        if (label__True_561->is_used())
                        {
                          BIND(label__True_561);
                          // ../third_party/v8/builtins/array-sort.tq:961:28
                          *offset_391 = implicit_cast<TNode<Smi>>((*max_ofs_393).value());
                          Goto(label__False_562);
                        }
                        BIND(label__False_562);
                      }
                    }
                    Goto(label_header_838_1116);
                  }
                  BIND(label__False_558);
                }
                // ../third_party/v8/builtins/array-sort.tq:964:9
                {
                  Label label__True_563_impl(this);
                  Label* label__True_563 = &label__True_563_impl;
                  USE(label__True_563);
                  Label label__False_564_impl(this, {offset_391});
                  Label* label__False_564 = &label__False_564_impl;
                  USE(label__False_564);
                  TNode<BoolT> t2185 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*offset_391).value()), implicit_cast<TNode<Smi>>((*max_ofs_393).value())));
                  USE(implicit_cast<TNode<BoolT>>(t2185));
                  Branch(implicit_cast<TNode<BoolT>>(t2185), label__True_563, label__False_564);
                  if (label__True_563->is_used())
                  {
                    BIND(label__True_563);
                    // ../third_party/v8/builtins/array-sort.tq:964:31
                    *offset_391 = implicit_cast<TNode<Smi>>((*max_ofs_393).value());
                    Goto(label__False_564);
                  }
                  BIND(label__False_564);
                }
                // ../third_party/v8/builtins/array-sort.tq:967:9
                TNode<Smi> t2186 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*last_ofs_390).value()), implicit_cast<TNode<Smi>>(p_hint)));
                USE(implicit_cast<TNode<Smi>>(t2186));
                *last_ofs_390 = implicit_cast<TNode<Smi>>(t2186);
                // ../third_party/v8/builtins/array-sort.tq:968:9
                TNode<Smi> t2187 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*offset_391).value()), implicit_cast<TNode<Smi>>(p_hint)));
                USE(implicit_cast<TNode<Smi>>(t2187));
                *offset_391 = implicit_cast<TNode<Smi>>(t2187);
              }
              Goto(label_if_done_label_837_1115);
            }
            if (label__False_556->is_used())
            {
              BIND(label__False_556);
              // ../third_party/v8/builtins/array-sort.tq:969:14
              {
                // ../third_party/v8/builtins/array-sort.tq:972:9
                // ../third_party/v8/builtins/array-sort.tq:975:9
                int31_t t2188 = 1;
                TNode<Smi> t2189 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2188)));
                TNode<Smi> t2190 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_hint), implicit_cast<TNode<Smi>>(t2189)));
                USE(implicit_cast<TNode<Smi>>(t2190));
                TVARIABLE(Smi, max_ofs_394_impl);
                auto max_ofs_394 = &max_ofs_394_impl;
                USE(max_ofs_394);
                *max_ofs_394 = implicit_cast<TNode<Smi>>(t2190);
                // ../third_party/v8/builtins/array-sort.tq:976:9
                {
                  Label label__True_565_impl(this);
                  Label* label__True_565 = &label__True_565_impl;
                  USE(label__True_565);
                  Label label__False_566_impl(this);
                  Label* label__False_566 = &label__False_566_impl;
                  USE(label__False_566);
                  Label label_header_840_1117_impl(this, {last_ofs_390, offset_391, order_392});
                  Label* label_header_840_1117 = &label_header_840_1117_impl;
                  USE(label_header_840_1117);
                  Goto(label_header_840_1117);
                  BIND(label_header_840_1117);
                  TNode<BoolT> t2191 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*offset_391).value()), implicit_cast<TNode<Smi>>((*max_ofs_394).value())));
                  USE(implicit_cast<TNode<BoolT>>(t2191));
                  Branch(implicit_cast<TNode<BoolT>>(t2191), label__True_565, label__False_566);
                  if (label__True_565->is_used())
                  {
                    BIND(label__True_565);
                    // ../third_party/v8/builtins/array-sort.tq:976:34
                    {
                      // ../third_party/v8/builtins/array-sort.tq:977:11
                      TNode<HeapObject> t2192 = UncheckedCast<HeapObject>(LoadElementsOrTempArray(implicit_cast<TNode<Oddball>>(p_useTempArray), implicit_cast<TNode<FixedArray>>(p_sortState)));
                      USE(implicit_cast<TNode<HeapObject>>(t2192));
                      TNode<Smi> t2193 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_base), implicit_cast<TNode<Smi>>(p_hint)));
                      USE(implicit_cast<TNode<Smi>>(t2193));
                      TNode<Smi> t2194 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t2193), implicit_cast<TNode<Smi>>((*offset_391).value())));
                      USE(implicit_cast<TNode<Smi>>(t2194));
                      TNode<Object> t2195 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(t2192), implicit_cast<TNode<Smi>>(t2194), label_Bailout_554));
                      USE(implicit_cast<TNode<Object>>(t2195));
                      TNode<Object> offset_element_841_impl;
                      auto offset_element_841 = &offset_element_841_impl;
                      USE(offset_element_841);
                      *offset_element_841 = implicit_cast<TNode<Object>>(t2195);
                      // ../third_party/v8/builtins/array-sort.tq:982:11
                      TNode<Number> t2196 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>((*offset_element_841)), implicit_cast<TNode<Object>>(p_key), label_Bailout_554));
                      USE(implicit_cast<TNode<Number>>(t2196));
                      *order_392 = implicit_cast<TNode<Number>>(t2196);
                      // ../third_party/v8/builtins/array-sort.tq:985:11
                      {
                        Label label__True_567_impl(this);
                        Label* label__True_567 = &label__True_567_impl;
                        USE(label__True_567);
                        Label label__False_568_impl(this, {});
                        Label* label__False_568 = &label__False_568_impl;
                        USE(label__False_568);
                        int31_t t2197 = 0;
                        TNode<Number> t2198 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2197)));
                        BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_392).value()), implicit_cast<TNode<Number>>(t2198), label__True_567, label__False_568);
                        if (label__True_567->is_used())
                        {
                          BIND(label__True_567);
                          // ../third_party/v8/builtins/array-sort.tq:985:26
                          Goto(label__False_566);
                        }
                        BIND(label__False_568);
                      }
                      // ../third_party/v8/builtins/array-sort.tq:987:11
                      *last_ofs_390 = implicit_cast<TNode<Smi>>((*offset_391).value());
                      // ../third_party/v8/builtins/array-sort.tq:988:11
                      int31_t t2199 = 1;
                      TNode<Smi> t2200 = UncheckedCast<Smi>(SmiShl(implicit_cast<TNode<Smi>>((*offset_391).value()), implicit_cast<int31_t>(t2199)));
                      USE(implicit_cast<TNode<Smi>>(t2200));
                      int31_t t2201 = 1;
                      TNode<Smi> t2202 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2201)));
                      TNode<Smi> t2203 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(t2200), implicit_cast<TNode<Smi>>(t2202)));
                      USE(implicit_cast<TNode<Smi>>(t2203));
                      *offset_391 = implicit_cast<TNode<Smi>>(t2203);
                      // ../third_party/v8/builtins/array-sort.tq:991:11
                      {
                        Label label__True_569_impl(this);
                        Label* label__True_569 = &label__True_569_impl;
                        USE(label__True_569);
                        Label label__False_570_impl(this, {offset_391});
                        Label* label__False_570 = &label__False_570_impl;
                        USE(label__False_570);
                        int31_t t2204 = 0;
                        TNode<Smi> t2205 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2204)));
                        TNode<BoolT> t2206 = UncheckedCast<BoolT>(SmiLessThanOrEqual(implicit_cast<TNode<Smi>>((*offset_391).value()), implicit_cast<TNode<Smi>>(t2205)));
                        USE(implicit_cast<TNode<BoolT>>(t2206));
                        Branch(implicit_cast<TNode<BoolT>>(t2206), label__True_569, label__False_570);
                        if (label__True_569->is_used())
                        {
                          BIND(label__True_569);
                          // ../third_party/v8/builtins/array-sort.tq:991:28
                          *offset_391 = implicit_cast<TNode<Smi>>((*max_ofs_394).value());
                          Goto(label__False_570);
                        }
                        BIND(label__False_570);
                      }
                    }
                    Goto(label_header_840_1117);
                  }
                  BIND(label__False_566);
                }
                // ../third_party/v8/builtins/array-sort.tq:994:9
                {
                  Label label__True_571_impl(this);
                  Label* label__True_571 = &label__True_571_impl;
                  USE(label__True_571);
                  Label label__False_572_impl(this, {offset_391});
                  Label* label__False_572 = &label__False_572_impl;
                  USE(label__False_572);
                  TNode<BoolT> t2207 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*offset_391).value()), implicit_cast<TNode<Smi>>((*max_ofs_394).value())));
                  USE(implicit_cast<TNode<BoolT>>(t2207));
                  Branch(implicit_cast<TNode<BoolT>>(t2207), label__True_571, label__False_572);
                  if (label__True_571->is_used())
                  {
                    BIND(label__True_571);
                    // ../third_party/v8/builtins/array-sort.tq:994:31
                    *offset_391 = implicit_cast<TNode<Smi>>((*max_ofs_394).value());
                    Goto(label__False_572);
                  }
                  BIND(label__False_572);
                }
                // ../third_party/v8/builtins/array-sort.tq:997:9
                TNode<Smi> tmp_842_impl;
                auto tmp_842 = &tmp_842_impl;
                USE(tmp_842);
                *tmp_842 = implicit_cast<TNode<Smi>>((*last_ofs_390).value());
                // ../third_party/v8/builtins/array-sort.tq:998:9
                TNode<Smi> t2208 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_hint), implicit_cast<TNode<Smi>>((*offset_391).value())));
                USE(implicit_cast<TNode<Smi>>(t2208));
                *last_ofs_390 = implicit_cast<TNode<Smi>>(t2208);
                // ../third_party/v8/builtins/array-sort.tq:999:9
                TNode<Smi> t2209 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_hint), implicit_cast<TNode<Smi>>((*tmp_842))));
                USE(implicit_cast<TNode<Smi>>(t2209));
                *offset_391 = implicit_cast<TNode<Smi>>(t2209);
              }
              Goto(label_if_done_label_837_1115);
            }
            BIND(label_if_done_label_837_1115);
          }
          // ../third_party/v8/builtins/array-sort.tq:1002:7
          // ../third_party/v8/builtins/array-sort.tq:1008:7
          TNode<Smi> t2210 = implicit_cast<TNode<Smi>>((*last_ofs_390).value());
          USE(t2210);
          TNode<Smi> t2211 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t2212 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*last_ofs_390).value()), implicit_cast<TNode<Smi>>(t2211)));
          *last_ofs_390 = implicit_cast<TNode<Smi>>(t2212);
          // ../third_party/v8/builtins/array-sort.tq:1009:7
          {
            Label label__True_573_impl(this);
            Label* label__True_573 = &label__True_573_impl;
            USE(label__True_573);
            Label label__False_574_impl(this);
            Label* label__False_574 = &label__False_574_impl;
            USE(label__False_574);
            Label label_header_843_1118_impl(this, {last_ofs_390, offset_391, order_392});
            Label* label_header_843_1118 = &label_header_843_1118_impl;
            USE(label_header_843_1118);
            Goto(label_header_843_1118);
            BIND(label_header_843_1118);
            TNode<BoolT> t2213 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*last_ofs_390).value()), implicit_cast<TNode<Smi>>((*offset_391).value())));
            USE(implicit_cast<TNode<BoolT>>(t2213));
            Branch(implicit_cast<TNode<BoolT>>(t2213), label__True_573, label__False_574);
            if (label__True_573->is_used())
            {
              BIND(label__True_573);
              // ../third_party/v8/builtins/array-sort.tq:1009:33
              {
                // ../third_party/v8/builtins/array-sort.tq:1010:9
                TNode<Smi> t2214 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*offset_391).value()), implicit_cast<TNode<Smi>>((*last_ofs_390).value())));
                USE(implicit_cast<TNode<Smi>>(t2214));
                int31_t t2215 = 1;
                TNode<Smi> t2216 = UncheckedCast<Smi>(SmiShr(implicit_cast<TNode<Smi>>(t2214), implicit_cast<int31_t>(t2215)));
                USE(implicit_cast<TNode<Smi>>(t2216));
                TNode<Smi> t2217 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*last_ofs_390).value()), implicit_cast<TNode<Smi>>(t2216)));
                USE(implicit_cast<TNode<Smi>>(t2217));
                TNode<Smi> m_844_impl;
                auto m_844 = &m_844_impl;
                USE(m_844);
                *m_844 = implicit_cast<TNode<Smi>>(t2217);
                // ../third_party/v8/builtins/array-sort.tq:1012:9
                TNode<HeapObject> t2218 = UncheckedCast<HeapObject>(LoadElementsOrTempArray(implicit_cast<TNode<Oddball>>(p_useTempArray), implicit_cast<TNode<FixedArray>>(p_sortState)));
                USE(implicit_cast<TNode<HeapObject>>(t2218));
                TNode<Smi> t2219 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_base), implicit_cast<TNode<Smi>>((*m_844))));
                USE(implicit_cast<TNode<Smi>>(t2219));
                TNode<Object> t2220 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(t2218), implicit_cast<TNode<Smi>>(t2219), label_Bailout_554));
                USE(implicit_cast<TNode<Object>>(t2220));
                TNode<Object> base_m_element_845_impl;
                auto base_m_element_845 = &base_m_element_845_impl;
                USE(base_m_element_845);
                *base_m_element_845 = implicit_cast<TNode<Object>>(t2220);
                // ../third_party/v8/builtins/array-sort.tq:1016:9
                TNode<Number> t2221 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>((*base_m_element_845)), implicit_cast<TNode<Object>>(p_key), label_Bailout_554));
                USE(implicit_cast<TNode<Number>>(t2221));
                *order_392 = implicit_cast<TNode<Number>>(t2221);
                // ../third_party/v8/builtins/array-sort.tq:1019:9
                {
                  Label label__True_575_impl(this);
                  Label* label__True_575 = &label__True_575_impl;
                  USE(label__True_575);
                  Label label__False_576_impl(this);
                  Label* label__False_576 = &label__False_576_impl;
                  USE(label__False_576);
                  Label label_if_done_label_846_1119_impl(this, {last_ofs_390, offset_391});
                  Label* label_if_done_label_846_1119 = &label_if_done_label_846_1119_impl;
                  USE(label_if_done_label_846_1119);
                  int31_t t2222 = 0;
                  TNode<Number> t2223 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2222)));
                  BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_392).value()), implicit_cast<TNode<Number>>(t2223), label__True_575, label__False_576);
                  if (label__True_575->is_used())
                  {
                    BIND(label__True_575);
                    // ../third_party/v8/builtins/array-sort.tq:1019:24
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1020:11
                      int31_t t2224 = 1;
                      TNode<Smi> t2225 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2224)));
                      TNode<Smi> t2226 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*m_844)), implicit_cast<TNode<Smi>>(t2225)));
                      USE(implicit_cast<TNode<Smi>>(t2226));
                      *last_ofs_390 = implicit_cast<TNode<Smi>>(t2226);
                    }
                    Goto(label_if_done_label_846_1119);
                  }
                  if (label__False_576->is_used())
                  {
                    BIND(label__False_576);
                    // ../third_party/v8/builtins/array-sort.tq:1021:16
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1022:11
                      *offset_391 = implicit_cast<TNode<Smi>>((*m_844));
                    }
                    Goto(label_if_done_label_846_1119);
                  }
                  BIND(label_if_done_label_846_1119);
                }
              }
              Goto(label_header_843_1118);
            }
            BIND(label__False_574);
          }
          // ../third_party/v8/builtins/array-sort.tq:1026:7
          // ../third_party/v8/builtins/array-sort.tq:1027:7
          // ../third_party/v8/builtins/array-sort.tq:1028:7
          Return(implicit_cast<TNode<Smi>>((*offset_391).value()));
        }
      }
      if (label_Bailout_554->is_used())
      {
        BIND(label_Bailout_554);
        // ../third_party/v8/builtins/array-sort.tq:1030:19
        {
          // ../third_party/v8/builtins/array-sort.tq:1031:7
          TNode<Smi> t2227 = UncheckedCast<Smi>(Failure(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t2227));
          Return(implicit_cast<TNode<Smi>>(t2227));
        }
      }
    }
  }
}

TF_BUILTIN(GallopRight, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<Code> p_Load = UncheckedCast<Code>(Parameter(Descriptor::kLoad));
  USE(p_Load);
  TNode<Object> p_key = UncheckedCast<Object>(Parameter(Descriptor::kKey));
  USE(p_key);
  TNode<Smi> p_base = UncheckedCast<Smi>(Parameter(Descriptor::kBase));
  USE(p_base);
  TNode<Smi> p_length = UncheckedCast<Smi>(Parameter(Descriptor::kLength));
  USE(p_length);
  TNode<Smi> p_hint = UncheckedCast<Smi>(Parameter(Descriptor::kHint));
  USE(p_hint);
  TNode<Oddball> p_useTempArray = UncheckedCast<Oddball>(Parameter(Descriptor::kUseTempArray));
  USE(p_useTempArray);
  // ../third_party/v8/builtins/array-sort.tq:1046:70
  {
    // ../third_party/v8/builtins/array-sort.tq:1047:5
    // ../third_party/v8/builtins/array-sort.tq:1048:5
    // ../third_party/v8/builtins/array-sort.tq:1050:5
    int31_t t2228 = 0;
    TVARIABLE(Smi, last_ofs_395_impl);
    auto last_ofs_395 = &last_ofs_395_impl;
    USE(last_ofs_395);
    TNode<Smi> t2229 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2228)));
    *last_ofs_395 = implicit_cast<TNode<Smi>>(t2229);
    // ../third_party/v8/builtins/array-sort.tq:1051:5
    int31_t t2230 = 1;
    TVARIABLE(Smi, offset_396_impl);
    auto offset_396 = &offset_396_impl;
    USE(offset_396);
    TNode<Smi> t2231 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2230)));
    *offset_396 = implicit_cast<TNode<Smi>>(t2231);
    // ../third_party/v8/builtins/array-sort.tq:1053:5
    {
      Label label_try_done_847_1120_impl(this);
      Label* label_try_done_847_1120 = &label_try_done_847_1120_impl;
      USE(label_try_done_847_1120);
      Label label_Bailout_577_impl(this);
      Label* label_Bailout_577 = &label_Bailout_577_impl;
      USE(label_Bailout_577);
      Label label_try_begin_848_1121_impl(this);
      Label* label_try_begin_848_1121 = &label_try_begin_848_1121_impl;
      USE(label_try_begin_848_1121);
      Goto(label_try_begin_848_1121);
      if (label_try_begin_848_1121->is_used())
      {
        BIND(label_try_begin_848_1121);
        // ../third_party/v8/builtins/array-sort.tq:1053:9
        {
          // ../third_party/v8/builtins/array-sort.tq:1054:7
          TNode<HeapObject> t2232 = UncheckedCast<HeapObject>(LoadElementsOrTempArray(implicit_cast<TNode<Oddball>>(p_useTempArray), implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<HeapObject>>(t2232));
          TNode<Smi> t2233 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_base), implicit_cast<TNode<Smi>>(p_hint)));
          USE(implicit_cast<TNode<Smi>>(t2233));
          TNode<Object> t2234 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(t2232), implicit_cast<TNode<Smi>>(t2233), label_Bailout_577));
          USE(implicit_cast<TNode<Object>>(t2234));
          TNode<Object> base_hint_element_849_impl;
          auto base_hint_element_849 = &base_hint_element_849_impl;
          USE(base_hint_element_849);
          *base_hint_element_849 = implicit_cast<TNode<Object>>(t2234);
          // ../third_party/v8/builtins/array-sort.tq:1058:7
          TNode<Number> t2235 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>(p_key), implicit_cast<TNode<Object>>((*base_hint_element_849)), label_Bailout_577));
          USE(implicit_cast<TNode<Number>>(t2235));
          TVARIABLE(Number, order_397_impl);
          auto order_397 = &order_397_impl;
          USE(order_397);
          *order_397 = implicit_cast<TNode<Number>>(t2235);
          // ../third_party/v8/builtins/array-sort.tq:1062:7
          {
            Label label__True_578_impl(this);
            Label* label__True_578 = &label__True_578_impl;
            USE(label__True_578);
            Label label__False_579_impl(this);
            Label* label__False_579 = &label__False_579_impl;
            USE(label__False_579);
            Label label_if_done_label_850_1122_impl(this, {last_ofs_395, offset_396, order_397});
            Label* label_if_done_label_850_1122 = &label_if_done_label_850_1122_impl;
            USE(label_if_done_label_850_1122);
            int31_t t2236 = 0;
            TNode<Number> t2237 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2236)));
            BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_397).value()), implicit_cast<TNode<Number>>(t2237), label__True_578, label__False_579);
            if (label__True_578->is_used())
            {
              BIND(label__True_578);
              // ../third_party/v8/builtins/array-sort.tq:1062:22
              {
                // ../third_party/v8/builtins/array-sort.tq:1067:9
                int31_t t2238 = 1;
                TNode<Smi> t2239 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2238)));
                TNode<Smi> t2240 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_hint), implicit_cast<TNode<Smi>>(t2239)));
                USE(implicit_cast<TNode<Smi>>(t2240));
                TVARIABLE(Smi, max_ofs_398_impl);
                auto max_ofs_398 = &max_ofs_398_impl;
                USE(max_ofs_398);
                *max_ofs_398 = implicit_cast<TNode<Smi>>(t2240);
                // ../third_party/v8/builtins/array-sort.tq:1068:9
                {
                  Label label__True_580_impl(this);
                  Label* label__True_580 = &label__True_580_impl;
                  USE(label__True_580);
                  Label label__False_581_impl(this);
                  Label* label__False_581 = &label__False_581_impl;
                  USE(label__False_581);
                  Label label_header_851_1123_impl(this, {last_ofs_395, offset_396, order_397});
                  Label* label_header_851_1123 = &label_header_851_1123_impl;
                  USE(label_header_851_1123);
                  Goto(label_header_851_1123);
                  BIND(label_header_851_1123);
                  TNode<BoolT> t2241 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*offset_396).value()), implicit_cast<TNode<Smi>>((*max_ofs_398).value())));
                  USE(implicit_cast<TNode<BoolT>>(t2241));
                  Branch(implicit_cast<TNode<BoolT>>(t2241), label__True_580, label__False_581);
                  if (label__True_580->is_used())
                  {
                    BIND(label__True_580);
                    // ../third_party/v8/builtins/array-sort.tq:1068:34
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1069:11
                      TNode<HeapObject> t2242 = UncheckedCast<HeapObject>(LoadElementsOrTempArray(implicit_cast<TNode<Oddball>>(p_useTempArray), implicit_cast<TNode<FixedArray>>(p_sortState)));
                      USE(implicit_cast<TNode<HeapObject>>(t2242));
                      TNode<Smi> t2243 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_base), implicit_cast<TNode<Smi>>(p_hint)));
                      USE(implicit_cast<TNode<Smi>>(t2243));
                      TNode<Smi> t2244 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t2243), implicit_cast<TNode<Smi>>((*offset_396).value())));
                      USE(implicit_cast<TNode<Smi>>(t2244));
                      TNode<Object> t2245 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(t2242), implicit_cast<TNode<Smi>>(t2244), label_Bailout_577));
                      USE(implicit_cast<TNode<Object>>(t2245));
                      TNode<Object> offset_element_852_impl;
                      auto offset_element_852 = &offset_element_852_impl;
                      USE(offset_element_852);
                      *offset_element_852 = implicit_cast<TNode<Object>>(t2245);
                      // ../third_party/v8/builtins/array-sort.tq:1074:11
                      TNode<Number> t2246 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>(p_key), implicit_cast<TNode<Object>>((*offset_element_852)), label_Bailout_577));
                      USE(implicit_cast<TNode<Number>>(t2246));
                      *order_397 = implicit_cast<TNode<Number>>(t2246);
                      // ../third_party/v8/builtins/array-sort.tq:1077:11
                      {
                        Label label__True_582_impl(this);
                        Label* label__True_582 = &label__True_582_impl;
                        USE(label__True_582);
                        Label label__False_583_impl(this, {});
                        Label* label__False_583 = &label__False_583_impl;
                        USE(label__False_583);
                        int31_t t2247 = 0;
                        TNode<Number> t2248 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2247)));
                        BranchIfNumberGreaterThanOrEqual(implicit_cast<TNode<Number>>((*order_397).value()), implicit_cast<TNode<Number>>(t2248), label__True_582, label__False_583);
                        if (label__True_582->is_used())
                        {
                          BIND(label__True_582);
                          // ../third_party/v8/builtins/array-sort.tq:1077:27
                          Goto(label__False_581);
                        }
                        BIND(label__False_583);
                      }
                      // ../third_party/v8/builtins/array-sort.tq:1079:11
                      *last_ofs_395 = implicit_cast<TNode<Smi>>((*offset_396).value());
                      // ../third_party/v8/builtins/array-sort.tq:1080:11
                      int31_t t2249 = 1;
                      TNode<Smi> t2250 = UncheckedCast<Smi>(SmiShl(implicit_cast<TNode<Smi>>((*offset_396).value()), implicit_cast<int31_t>(t2249)));
                      USE(implicit_cast<TNode<Smi>>(t2250));
                      int31_t t2251 = 1;
                      TNode<Smi> t2252 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2251)));
                      TNode<Smi> t2253 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(t2250), implicit_cast<TNode<Smi>>(t2252)));
                      USE(implicit_cast<TNode<Smi>>(t2253));
                      *offset_396 = implicit_cast<TNode<Smi>>(t2253);
                      // ../third_party/v8/builtins/array-sort.tq:1083:11
                      {
                        Label label__True_584_impl(this);
                        Label* label__True_584 = &label__True_584_impl;
                        USE(label__True_584);
                        Label label__False_585_impl(this, {offset_396});
                        Label* label__False_585 = &label__False_585_impl;
                        USE(label__False_585);
                        int31_t t2254 = 0;
                        TNode<Smi> t2255 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2254)));
                        TNode<BoolT> t2256 = UncheckedCast<BoolT>(SmiLessThanOrEqual(implicit_cast<TNode<Smi>>((*offset_396).value()), implicit_cast<TNode<Smi>>(t2255)));
                        USE(implicit_cast<TNode<BoolT>>(t2256));
                        Branch(implicit_cast<TNode<BoolT>>(t2256), label__True_584, label__False_585);
                        if (label__True_584->is_used())
                        {
                          BIND(label__True_584);
                          // ../third_party/v8/builtins/array-sort.tq:1083:28
                          *offset_396 = implicit_cast<TNode<Smi>>((*max_ofs_398).value());
                          Goto(label__False_585);
                        }
                        BIND(label__False_585);
                      }
                    }
                    Goto(label_header_851_1123);
                  }
                  BIND(label__False_581);
                }
                // ../third_party/v8/builtins/array-sort.tq:1086:9
                {
                  Label label__True_586_impl(this);
                  Label* label__True_586 = &label__True_586_impl;
                  USE(label__True_586);
                  Label label__False_587_impl(this, {offset_396});
                  Label* label__False_587 = &label__False_587_impl;
                  USE(label__False_587);
                  TNode<BoolT> t2257 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*offset_396).value()), implicit_cast<TNode<Smi>>((*max_ofs_398).value())));
                  USE(implicit_cast<TNode<BoolT>>(t2257));
                  Branch(implicit_cast<TNode<BoolT>>(t2257), label__True_586, label__False_587);
                  if (label__True_586->is_used())
                  {
                    BIND(label__True_586);
                    // ../third_party/v8/builtins/array-sort.tq:1086:31
                    *offset_396 = implicit_cast<TNode<Smi>>((*max_ofs_398).value());
                    Goto(label__False_587);
                  }
                  BIND(label__False_587);
                }
                // ../third_party/v8/builtins/array-sort.tq:1089:9
                TNode<Smi> tmp_853_impl;
                auto tmp_853 = &tmp_853_impl;
                USE(tmp_853);
                *tmp_853 = implicit_cast<TNode<Smi>>((*last_ofs_395).value());
                // ../third_party/v8/builtins/array-sort.tq:1090:9
                TNode<Smi> t2258 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_hint), implicit_cast<TNode<Smi>>((*offset_396).value())));
                USE(implicit_cast<TNode<Smi>>(t2258));
                *last_ofs_395 = implicit_cast<TNode<Smi>>(t2258);
                // ../third_party/v8/builtins/array-sort.tq:1091:9
                TNode<Smi> t2259 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_hint), implicit_cast<TNode<Smi>>((*tmp_853))));
                USE(implicit_cast<TNode<Smi>>(t2259));
                *offset_396 = implicit_cast<TNode<Smi>>(t2259);
              }
              Goto(label_if_done_label_850_1122);
            }
            if (label__False_579->is_used())
            {
              BIND(label__False_579);
              // ../third_party/v8/builtins/array-sort.tq:1092:14
              {
                // ../third_party/v8/builtins/array-sort.tq:1097:9
                TNode<Smi> t2260 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_length), implicit_cast<TNode<Smi>>(p_hint)));
                USE(implicit_cast<TNode<Smi>>(t2260));
                TVARIABLE(Smi, max_ofs_399_impl);
                auto max_ofs_399 = &max_ofs_399_impl;
                USE(max_ofs_399);
                *max_ofs_399 = implicit_cast<TNode<Smi>>(t2260);
                // ../third_party/v8/builtins/array-sort.tq:1098:9
                {
                  Label label__True_588_impl(this);
                  Label* label__True_588 = &label__True_588_impl;
                  USE(label__True_588);
                  Label label__False_589_impl(this);
                  Label* label__False_589 = &label__False_589_impl;
                  USE(label__False_589);
                  Label label_header_854_1124_impl(this, {last_ofs_395, offset_396, order_397});
                  Label* label_header_854_1124 = &label_header_854_1124_impl;
                  USE(label_header_854_1124);
                  Goto(label_header_854_1124);
                  BIND(label_header_854_1124);
                  TNode<BoolT> t2261 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*offset_396).value()), implicit_cast<TNode<Smi>>((*max_ofs_399).value())));
                  USE(implicit_cast<TNode<BoolT>>(t2261));
                  Branch(implicit_cast<TNode<BoolT>>(t2261), label__True_588, label__False_589);
                  if (label__True_588->is_used())
                  {
                    BIND(label__True_588);
                    // ../third_party/v8/builtins/array-sort.tq:1098:34
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1099:11
                      TNode<HeapObject> t2262 = UncheckedCast<HeapObject>(LoadElementsOrTempArray(implicit_cast<TNode<Oddball>>(p_useTempArray), implicit_cast<TNode<FixedArray>>(p_sortState)));
                      USE(implicit_cast<TNode<HeapObject>>(t2262));
                      TNode<Smi> t2263 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_base), implicit_cast<TNode<Smi>>(p_hint)));
                      USE(implicit_cast<TNode<Smi>>(t2263));
                      TNode<Smi> t2264 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(t2263), implicit_cast<TNode<Smi>>((*offset_396).value())));
                      USE(implicit_cast<TNode<Smi>>(t2264));
                      TNode<Object> t2265 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(t2262), implicit_cast<TNode<Smi>>(t2264), label_Bailout_577));
                      USE(implicit_cast<TNode<Object>>(t2265));
                      TNode<Object> offset_element_855_impl;
                      auto offset_element_855 = &offset_element_855_impl;
                      USE(offset_element_855);
                      *offset_element_855 = implicit_cast<TNode<Object>>(t2265);
                      // ../third_party/v8/builtins/array-sort.tq:1104:11
                      TNode<Number> t2266 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>(p_key), implicit_cast<TNode<Object>>((*offset_element_855)), label_Bailout_577));
                      USE(implicit_cast<TNode<Number>>(t2266));
                      *order_397 = implicit_cast<TNode<Number>>(t2266);
                      // ../third_party/v8/builtins/array-sort.tq:1108:11
                      {
                        Label label__True_590_impl(this);
                        Label* label__True_590 = &label__True_590_impl;
                        USE(label__True_590);
                        Label label__False_591_impl(this, {});
                        Label* label__False_591 = &label__False_591_impl;
                        USE(label__False_591);
                        int31_t t2267 = 0;
                        TNode<Number> t2268 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2267)));
                        BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_397).value()), implicit_cast<TNode<Number>>(t2268), label__True_590, label__False_591);
                        if (label__True_590->is_used())
                        {
                          BIND(label__True_590);
                          // ../third_party/v8/builtins/array-sort.tq:1108:26
                          Goto(label__False_589);
                        }
                        BIND(label__False_591);
                      }
                      // ../third_party/v8/builtins/array-sort.tq:1110:11
                      *last_ofs_395 = implicit_cast<TNode<Smi>>((*offset_396).value());
                      // ../third_party/v8/builtins/array-sort.tq:1111:11
                      int31_t t2269 = 1;
                      TNode<Smi> t2270 = UncheckedCast<Smi>(SmiShl(implicit_cast<TNode<Smi>>((*offset_396).value()), implicit_cast<int31_t>(t2269)));
                      USE(implicit_cast<TNode<Smi>>(t2270));
                      int31_t t2271 = 1;
                      TNode<Smi> t2272 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2271)));
                      TNode<Smi> t2273 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(t2270), implicit_cast<TNode<Smi>>(t2272)));
                      USE(implicit_cast<TNode<Smi>>(t2273));
                      *offset_396 = implicit_cast<TNode<Smi>>(t2273);
                      // ../third_party/v8/builtins/array-sort.tq:1114:11
                      {
                        Label label__True_592_impl(this);
                        Label* label__True_592 = &label__True_592_impl;
                        USE(label__True_592);
                        Label label__False_593_impl(this, {offset_396});
                        Label* label__False_593 = &label__False_593_impl;
                        USE(label__False_593);
                        int31_t t2274 = 0;
                        TNode<Smi> t2275 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2274)));
                        TNode<BoolT> t2276 = UncheckedCast<BoolT>(SmiLessThanOrEqual(implicit_cast<TNode<Smi>>((*offset_396).value()), implicit_cast<TNode<Smi>>(t2275)));
                        USE(implicit_cast<TNode<BoolT>>(t2276));
                        Branch(implicit_cast<TNode<BoolT>>(t2276), label__True_592, label__False_593);
                        if (label__True_592->is_used())
                        {
                          BIND(label__True_592);
                          // ../third_party/v8/builtins/array-sort.tq:1114:28
                          *offset_396 = implicit_cast<TNode<Smi>>((*max_ofs_399).value());
                          Goto(label__False_593);
                        }
                        BIND(label__False_593);
                      }
                    }
                    Goto(label_header_854_1124);
                  }
                  BIND(label__False_589);
                }
                // ../third_party/v8/builtins/array-sort.tq:1117:9
                {
                  Label label__True_594_impl(this);
                  Label* label__True_594 = &label__True_594_impl;
                  USE(label__True_594);
                  Label label__False_595_impl(this, {offset_396});
                  Label* label__False_595 = &label__False_595_impl;
                  USE(label__False_595);
                  TNode<BoolT> t2277 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*offset_396).value()), implicit_cast<TNode<Smi>>((*max_ofs_399).value())));
                  USE(implicit_cast<TNode<BoolT>>(t2277));
                  Branch(implicit_cast<TNode<BoolT>>(t2277), label__True_594, label__False_595);
                  if (label__True_594->is_used())
                  {
                    BIND(label__True_594);
                    // ../third_party/v8/builtins/array-sort.tq:1117:31
                    *offset_396 = implicit_cast<TNode<Smi>>((*max_ofs_399).value());
                    Goto(label__False_595);
                  }
                  BIND(label__False_595);
                }
                // ../third_party/v8/builtins/array-sort.tq:1120:9
                TNode<Smi> t2278 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*last_ofs_395).value()), implicit_cast<TNode<Smi>>(p_hint)));
                USE(implicit_cast<TNode<Smi>>(t2278));
                *last_ofs_395 = implicit_cast<TNode<Smi>>(t2278);
                // ../third_party/v8/builtins/array-sort.tq:1121:9
                TNode<Smi> t2279 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*offset_396).value()), implicit_cast<TNode<Smi>>(p_hint)));
                USE(implicit_cast<TNode<Smi>>(t2279));
                *offset_396 = implicit_cast<TNode<Smi>>(t2279);
              }
              Goto(label_if_done_label_850_1122);
            }
            BIND(label_if_done_label_850_1122);
          }
          // ../third_party/v8/builtins/array-sort.tq:1123:7
          // ../third_party/v8/builtins/array-sort.tq:1129:7
          TNode<Smi> t2280 = implicit_cast<TNode<Smi>>((*last_ofs_395).value());
          USE(t2280);
          TNode<Smi> t2281 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t2282 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*last_ofs_395).value()), implicit_cast<TNode<Smi>>(t2281)));
          *last_ofs_395 = implicit_cast<TNode<Smi>>(t2282);
          // ../third_party/v8/builtins/array-sort.tq:1130:7
          {
            Label label__True_596_impl(this);
            Label* label__True_596 = &label__True_596_impl;
            USE(label__True_596);
            Label label__False_597_impl(this);
            Label* label__False_597 = &label__False_597_impl;
            USE(label__False_597);
            Label label_header_856_1125_impl(this, {last_ofs_395, offset_396, order_397});
            Label* label_header_856_1125 = &label_header_856_1125_impl;
            USE(label_header_856_1125);
            Goto(label_header_856_1125);
            BIND(label_header_856_1125);
            TNode<BoolT> t2283 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*last_ofs_395).value()), implicit_cast<TNode<Smi>>((*offset_396).value())));
            USE(implicit_cast<TNode<BoolT>>(t2283));
            Branch(implicit_cast<TNode<BoolT>>(t2283), label__True_596, label__False_597);
            if (label__True_596->is_used())
            {
              BIND(label__True_596);
              // ../third_party/v8/builtins/array-sort.tq:1130:33
              {
                // ../third_party/v8/builtins/array-sort.tq:1131:9
                TNode<Smi> t2284 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*offset_396).value()), implicit_cast<TNode<Smi>>((*last_ofs_395).value())));
                USE(implicit_cast<TNode<Smi>>(t2284));
                int31_t t2285 = 1;
                TNode<Smi> t2286 = UncheckedCast<Smi>(SmiShr(implicit_cast<TNode<Smi>>(t2284), implicit_cast<int31_t>(t2285)));
                USE(implicit_cast<TNode<Smi>>(t2286));
                TNode<Smi> t2287 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*last_ofs_395).value()), implicit_cast<TNode<Smi>>(t2286)));
                USE(implicit_cast<TNode<Smi>>(t2287));
                TNode<Smi> m_857_impl;
                auto m_857 = &m_857_impl;
                USE(m_857);
                *m_857 = implicit_cast<TNode<Smi>>(t2287);
                // ../third_party/v8/builtins/array-sort.tq:1133:9
                TNode<HeapObject> t2288 = UncheckedCast<HeapObject>(LoadElementsOrTempArray(implicit_cast<TNode<Oddball>>(p_useTempArray), implicit_cast<TNode<FixedArray>>(p_sortState)));
                USE(implicit_cast<TNode<HeapObject>>(t2288));
                TNode<Smi> t2289 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_base), implicit_cast<TNode<Smi>>((*m_857))));
                USE(implicit_cast<TNode<Smi>>(t2289));
                TNode<Object> t2290 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(t2288), implicit_cast<TNode<Smi>>(t2289), label_Bailout_577));
                USE(implicit_cast<TNode<Object>>(t2290));
                TNode<Object> base_m_element_858_impl;
                auto base_m_element_858 = &base_m_element_858_impl;
                USE(base_m_element_858);
                *base_m_element_858 = implicit_cast<TNode<Object>>(t2290);
                // ../third_party/v8/builtins/array-sort.tq:1137:9
                TNode<Number> t2291 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>(p_key), implicit_cast<TNode<Object>>((*base_m_element_858)), label_Bailout_577));
                USE(implicit_cast<TNode<Number>>(t2291));
                *order_397 = implicit_cast<TNode<Number>>(t2291);
                // ../third_party/v8/builtins/array-sort.tq:1140:9
                {
                  Label label__True_598_impl(this);
                  Label* label__True_598 = &label__True_598_impl;
                  USE(label__True_598);
                  Label label__False_599_impl(this);
                  Label* label__False_599 = &label__False_599_impl;
                  USE(label__False_599);
                  Label label_if_done_label_859_1126_impl(this, {last_ofs_395, offset_396});
                  Label* label_if_done_label_859_1126 = &label_if_done_label_859_1126_impl;
                  USE(label_if_done_label_859_1126);
                  int31_t t2292 = 0;
                  TNode<Number> t2293 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2292)));
                  BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_397).value()), implicit_cast<TNode<Number>>(t2293), label__True_598, label__False_599);
                  if (label__True_598->is_used())
                  {
                    BIND(label__True_598);
                    // ../third_party/v8/builtins/array-sort.tq:1140:24
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1141:11
                      *offset_396 = implicit_cast<TNode<Smi>>((*m_857));
                    }
                    Goto(label_if_done_label_859_1126);
                  }
                  if (label__False_599->is_used())
                  {
                    BIND(label__False_599);
                    // ../third_party/v8/builtins/array-sort.tq:1142:16
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1143:11
                      int31_t t2294 = 1;
                      TNode<Smi> t2295 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2294)));
                      TNode<Smi> t2296 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*m_857)), implicit_cast<TNode<Smi>>(t2295)));
                      USE(implicit_cast<TNode<Smi>>(t2296));
                      *last_ofs_395 = implicit_cast<TNode<Smi>>(t2296);
                    }
                    Goto(label_if_done_label_859_1126);
                  }
                  BIND(label_if_done_label_859_1126);
                }
              }
              Goto(label_header_856_1125);
            }
            BIND(label__False_597);
          }
          // ../third_party/v8/builtins/array-sort.tq:1147:7
          // ../third_party/v8/builtins/array-sort.tq:1148:7
          // ../third_party/v8/builtins/array-sort.tq:1149:7
          Return(implicit_cast<TNode<Smi>>((*offset_396).value()));
        }
      }
      if (label_Bailout_577->is_used())
      {
        BIND(label_Bailout_577);
        // ../third_party/v8/builtins/array-sort.tq:1151:19
        {
          // ../third_party/v8/builtins/array-sort.tq:1152:7
          TNode<Smi> t2297 = UncheckedCast<Smi>(Failure(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t2297));
          Return(implicit_cast<TNode<Smi>>(t2297));
        }
      }
    }
  }
}

void ArrayBuiltinsFromDSLAssembler::CopyElement(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_Load, TNode<Code> p_Store, TNode<HeapObject> p_elements, TNode<Smi> p_from, TNode<Smi> p_to, Label* label_Bailout_600) {
  Label label_macro_end_1127_impl(this, {});
  Label* label_macro_end_1127 = &label_macro_end_1127_impl;
  USE(label_macro_end_1127);
  // ../third_party/v8/builtins/array-sort.tq:1160:18
  {
    // ../third_party/v8/builtins/array-sort.tq:1161:5
    TNode<Object> t2298 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Load), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>(p_from), label_Bailout_600));
    USE(implicit_cast<TNode<Object>>(t2298));
    TNode<Object> element_860_impl;
    auto element_860 = &element_860_impl;
    USE(element_860);
    *element_860 = implicit_cast<TNode<Object>>(t2298);
    // ../third_party/v8/builtins/array-sort.tq:1163:5
    CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(p_Store), implicit_cast<TNode<HeapObject>>(p_elements), implicit_cast<TNode<Smi>>(p_to), implicit_cast<TNode<Object>>((*element_860)), label_Bailout_600);
  }
}

void ArrayBuiltinsFromDSLAssembler::MergeLow(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Smi> p_baseA, TNode<Smi> p_lengthA, TNode<Smi> p_baseB, TNode<Smi> p_lengthB, Label* label_Bailout_601) {
  Label label_macro_end_1128_impl(this, {});
  Label* label_macro_end_1128 = &label_macro_end_1128_impl;
  USE(label_macro_end_1128);
  // ../third_party/v8/builtins/array-sort.tq:1176:18
  {
    // ../third_party/v8/builtins/array-sort.tq:1177:5
    // ../third_party/v8/builtins/array-sort.tq:1178:5
    // ../third_party/v8/builtins/array-sort.tq:1179:5
    // ../third_party/v8/builtins/array-sort.tq:1181:5
    TVARIABLE(Smi, length_a_400_impl);
    auto length_a_400 = &length_a_400_impl;
    USE(length_a_400);
    *length_a_400 = implicit_cast<TNode<Smi>>(p_lengthA);
    // ../third_party/v8/builtins/array-sort.tq:1182:5
    TVARIABLE(Smi, length_b_401_impl);
    auto length_b_401 = &length_b_401_impl;
    USE(length_b_401);
    *length_b_401 = implicit_cast<TNode<Smi>>(p_lengthB);
    // ../third_party/v8/builtins/array-sort.tq:1184:5
    TNode<HeapObject> t2299 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<HeapObject>>(t2299));
    TVARIABLE(HeapObject, elements_402_impl);
    auto elements_402 = &elements_402_impl;
    USE(elements_402);
    *elements_402 = implicit_cast<TNode<HeapObject>>(t2299);
    // ../third_party/v8/builtins/array-sort.tq:1185:5
    TNode<Code> t2300 = UncheckedCast<Code>(GetLoadFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Code>>(t2300));
    TNode<Code> LoadF_861_impl;
    auto LoadF_861 = &LoadF_861_impl;
    USE(LoadF_861);
    *LoadF_861 = implicit_cast<TNode<Code>>(t2300);
    // ../third_party/v8/builtins/array-sort.tq:1186:5
    TNode<Code> t2301 = UncheckedCast<Code>(GetStoreFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Code>>(t2301));
    TNode<Code> Store_862_impl;
    auto Store_862 = &Store_862_impl;
    USE(Store_862);
    *Store_862 = implicit_cast<TNode<Code>>(t2301);
    // ../third_party/v8/builtins/array-sort.tq:1188:5
    TNode<FixedArray> t2302 = UncheckedCast<FixedArray>(GetTempArray(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>((*length_a_400).value())));
    USE(implicit_cast<TNode<FixedArray>>(t2302));
    TNode<FixedArray> temp_array_863_impl;
    auto temp_array_863 = &temp_array_863_impl;
    USE(temp_array_863);
    *temp_array_863 = implicit_cast<TNode<FixedArray>>(t2302);
    // ../third_party/v8/builtins/array-sort.tq:1189:5
    int31_t t2303 = 0;
    TNode<Smi> t2304 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2303)));
    CopyToTempArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_861)), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>(p_baseA), implicit_cast<TNode<FixedArray>>((*temp_array_863)), implicit_cast<TNode<Smi>>(t2304), implicit_cast<TNode<Smi>>((*length_a_400).value()), label_Bailout_601);
    // ../third_party/v8/builtins/array-sort.tq:1193:5
    TVARIABLE(Smi, dest_403_impl);
    auto dest_403 = &dest_403_impl;
    USE(dest_403);
    *dest_403 = implicit_cast<TNode<Smi>>(p_baseA);
    // ../third_party/v8/builtins/array-sort.tq:1194:5
    int31_t t2305 = 0;
    TVARIABLE(Smi, cursor_temp_404_impl);
    auto cursor_temp_404 = &cursor_temp_404_impl;
    USE(cursor_temp_404);
    TNode<Smi> t2306 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2305)));
    *cursor_temp_404 = implicit_cast<TNode<Smi>>(t2306);
    // ../third_party/v8/builtins/array-sort.tq:1195:5
    TVARIABLE(Smi, cursor_b_405_impl);
    auto cursor_b_405 = &cursor_b_405_impl;
    USE(cursor_b_405);
    *cursor_b_405 = implicit_cast<TNode<Smi>>(p_baseB);
    // ../third_party/v8/builtins/array-sort.tq:1197:5
    TNode<Smi> t2307 = implicit_cast<TNode<Smi>>((*cursor_b_405).value());
    USE(t2307);
    TNode<Smi> t2308 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
    TNode<Smi> t2309 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*cursor_b_405).value()), implicit_cast<TNode<Smi>>(t2308)));
    *cursor_b_405 = implicit_cast<TNode<Smi>>(t2309);
    TNode<Smi> t2310 = implicit_cast<TNode<Smi>>((*dest_403).value());
    USE(t2310);
    TNode<Smi> t2311 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
    TNode<Smi> t2312 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Smi>>(t2311)));
    *dest_403 = implicit_cast<TNode<Smi>>(t2312);
    CopyElement(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_861)), implicit_cast<TNode<Code>>((*Store_862)), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>(t2307), implicit_cast<TNode<Smi>>(t2310), label_Bailout_601);
    // ../third_party/v8/builtins/array-sort.tq:1200:5
    {
      Label label_try_done_864_1129_impl(this);
      Label* label_try_done_864_1129 = &label_try_done_864_1129_impl;
      USE(label_try_done_864_1129);
      Label label_Succeed_602_impl(this);
      Label* label_Succeed_602 = &label_Succeed_602_impl;
      USE(label_Succeed_602);
      Label label_CopyB_603_impl(this);
      Label* label_CopyB_603 = &label_CopyB_603_impl;
      USE(label_CopyB_603);
      Label label_try_begin_865_1130_impl(this);
      Label* label_try_begin_865_1130 = &label_try_begin_865_1130_impl;
      USE(label_try_begin_865_1130);
      Goto(label_try_begin_865_1130);
      if (label_try_begin_865_1130->is_used())
      {
        BIND(label_try_begin_865_1130);
        // ../third_party/v8/builtins/array-sort.tq:1200:9
        {
          // ../third_party/v8/builtins/array-sort.tq:1201:7
          {
            Label label__True_604_impl(this);
            Label* label__True_604 = &label__True_604_impl;
            USE(label__True_604);
            Label label__False_605_impl(this, {length_b_401});
            Label* label__False_605 = &label__False_605_impl;
            USE(label__False_605);
            TNode<Smi> t2313 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
            TNode<Smi> t2314 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_401).value()), implicit_cast<TNode<Smi>>(t2313)));
            *length_b_401 = implicit_cast<TNode<Smi>>(t2314);
            int31_t t2315 = 0;
            TNode<Smi> t2316 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2315)));
            TNode<BoolT> t2317 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>(t2314), implicit_cast<TNode<Smi>>(t2316)));
            USE(implicit_cast<TNode<BoolT>>(t2317));
            Branch(implicit_cast<TNode<BoolT>>(t2317), label__True_604, label__False_605);
            if (label__True_604->is_used())
            {
              BIND(label__True_604);
              // ../third_party/v8/builtins/array-sort.tq:1201:28
              Goto(label_Succeed_602);
            }
            BIND(label__False_605);
          }
          // ../third_party/v8/builtins/array-sort.tq:1202:7
          {
            Label label__True_606_impl(this);
            Label* label__True_606 = &label__True_606_impl;
            USE(label__True_606);
            Label label__False_607_impl(this, {});
            Label* label__False_607 = &label__False_607_impl;
            USE(label__False_607);
            int31_t t2318 = 1;
            TNode<Smi> t2319 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2318)));
            TNode<BoolT> t2320 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_a_400).value()), implicit_cast<TNode<Smi>>(t2319)));
            USE(implicit_cast<TNode<BoolT>>(t2320));
            Branch(implicit_cast<TNode<BoolT>>(t2320), label__True_606, label__False_607);
            if (label__True_606->is_used())
            {
              BIND(label__True_606);
              // ../third_party/v8/builtins/array-sort.tq:1202:26
              Goto(label_CopyB_603);
            }
            BIND(label__False_607);
          }
          // ../third_party/v8/builtins/array-sort.tq:1204:7
          TNode<Object> t2321 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kMinGallopIdx())));
          TNode<Smi> t2322 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(t2321)));
          USE(implicit_cast<TNode<Smi>>(t2322));
          TVARIABLE(Smi, min_gallop_406_impl);
          auto min_gallop_406 = &min_gallop_406_impl;
          USE(min_gallop_406);
          *min_gallop_406 = implicit_cast<TNode<Smi>>(t2322);
          // ../third_party/v8/builtins/array-sort.tq:1207:7
          {
            Label label__True_608_impl(this);
            Label* label__True_608 = &label__True_608_impl;
            USE(label__True_608);
            Label label__False_609_impl(this);
            Label* label__False_609 = &label__False_609_impl;
            USE(label__False_609);
            Label label_header_866_1131_impl(this, {cursor_b_405, cursor_temp_404, dest_403, elements_402, length_a_400, length_b_401, min_gallop_406});
            Label* label_header_866_1131 = &label_header_866_1131_impl;
            USE(label_header_866_1131);
            Goto(label_header_866_1131);
            BIND(label_header_866_1131);
            TNode<BoolT> t2323 = UncheckedCast<BoolT>(Int32TrueConstant());
            USE(implicit_cast<TNode<BoolT>>(t2323));
            Branch(implicit_cast<TNode<BoolT>>(t2323), label__True_608, label__False_609);
            if (label__True_608->is_used())
            {
              BIND(label__True_608);
              // ../third_party/v8/builtins/array-sort.tq:1207:35
              {
                // ../third_party/v8/builtins/array-sort.tq:1208:9
                int31_t t2324 = 0;
                TVARIABLE(Smi, nof_wins_a_407_impl);
                auto nof_wins_a_407 = &nof_wins_a_407_impl;
                USE(nof_wins_a_407);
                TNode<Smi> t2325 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2324)));
                *nof_wins_a_407 = implicit_cast<TNode<Smi>>(t2325);
                // ../third_party/v8/builtins/array-sort.tq:1209:9
                int31_t t2326 = 0;
                TVARIABLE(Smi, nof_wins_b_408_impl);
                auto nof_wins_b_408 = &nof_wins_b_408_impl;
                USE(nof_wins_b_408);
                TNode<Smi> t2327 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2326)));
                *nof_wins_b_408 = implicit_cast<TNode<Smi>>(t2327);
                // ../third_party/v8/builtins/array-sort.tq:1215:9
                {
                  Label label__True_610_impl(this);
                  Label* label__True_610 = &label__True_610_impl;
                  USE(label__True_610);
                  Label label__False_611_impl(this);
                  Label* label__False_611 = &label__False_611_impl;
                  USE(label__False_611);
                  Label label_header_867_1132_impl(this, {cursor_b_405, cursor_temp_404, dest_403, elements_402, length_a_400, length_b_401, nof_wins_a_407, nof_wins_b_408});
                  Label* label_header_867_1132 = &label_header_867_1132_impl;
                  USE(label_header_867_1132);
                  Goto(label_header_867_1132);
                  BIND(label_header_867_1132);
                  TNode<BoolT> t2328 = UncheckedCast<BoolT>(Int32TrueConstant());
                  USE(implicit_cast<TNode<BoolT>>(t2328));
                  Branch(implicit_cast<TNode<BoolT>>(t2328), label__True_610, label__False_611);
                  if (label__True_610->is_used())
                  {
                    BIND(label__True_610);
                    // ../third_party/v8/builtins/array-sort.tq:1215:37
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1216:11
                      // ../third_party/v8/builtins/array-sort.tq:1218:11
                      TNode<Object> t2329 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_861)), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>((*cursor_b_405).value()), label_Bailout_601));
                      USE(implicit_cast<TNode<Object>>(t2329));
                      TVARIABLE(Object, element_b_409_impl);
                      auto element_b_409 = &element_b_409_impl;
                      USE(element_b_409);
                      *element_b_409 = implicit_cast<TNode<Object>>(t2329);
                      // ../third_party/v8/builtins/array-sort.tq:1221:11
                      TNode<Object> t2330 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*temp_array_863)), implicit_cast<TNode<Smi>>((*cursor_temp_404).value())));
                      TNode<Number> t2331 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>((*element_b_409).value()), implicit_cast<TNode<Object>>(t2330), label_Bailout_601));
                      USE(implicit_cast<TNode<Number>>(t2331));
                      TVARIABLE(Number, order_410_impl);
                      auto order_410 = &order_410_impl;
                      USE(order_410);
                      *order_410 = implicit_cast<TNode<Number>>(t2331);
                      // ../third_party/v8/builtins/array-sort.tq:1224:11
                      TNode<HeapObject> t2332 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
                      USE(implicit_cast<TNode<HeapObject>>(t2332));
                      *elements_402 = implicit_cast<TNode<HeapObject>>(t2332);
                      // ../third_party/v8/builtins/array-sort.tq:1226:11
                      {
                        Label label__True_612_impl(this);
                        Label* label__True_612 = &label__True_612_impl;
                        USE(label__True_612);
                        Label label__False_613_impl(this);
                        Label* label__False_613 = &label__False_613_impl;
                        USE(label__False_613);
                        Label label_if_done_label_868_1133_impl(this, {cursor_b_405, cursor_temp_404, dest_403, length_a_400, length_b_401, nof_wins_a_407, nof_wins_b_408});
                        Label* label_if_done_label_868_1133 = &label_if_done_label_868_1133_impl;
                        USE(label_if_done_label_868_1133);
                        int31_t t2333 = 0;
                        TNode<Number> t2334 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2333)));
                        BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_410).value()), implicit_cast<TNode<Number>>(t2334), label__True_612, label__False_613);
                        if (label__True_612->is_used())
                        {
                          BIND(label__True_612);
                          // ../third_party/v8/builtins/array-sort.tq:1226:26
                          {
                            // ../third_party/v8/builtins/array-sort.tq:1227:13
                            CopyElement(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_861)), implicit_cast<TNode<Code>>((*Store_862)), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>((*cursor_b_405).value()), implicit_cast<TNode<Smi>>((*dest_403).value()), label_Bailout_601);
                            // ../third_party/v8/builtins/array-sort.tq:1231:13
                            TNode<Smi> t2335 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2336 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*cursor_b_405).value()), implicit_cast<TNode<Smi>>(t2335)));
                            *cursor_b_405 = implicit_cast<TNode<Smi>>(t2336);
                            // ../third_party/v8/builtins/array-sort.tq:1232:13
                            TNode<Smi> t2337 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2338 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Smi>>(t2337)));
                            *dest_403 = implicit_cast<TNode<Smi>>(t2338);
                            // ../third_party/v8/builtins/array-sort.tq:1233:13
                            TNode<Smi> t2339 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2340 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*nof_wins_b_408).value()), implicit_cast<TNode<Smi>>(t2339)));
                            *nof_wins_b_408 = implicit_cast<TNode<Smi>>(t2340);
                            // ../third_party/v8/builtins/array-sort.tq:1234:13
                            TNode<Smi> t2341 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2342 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_401).value()), implicit_cast<TNode<Smi>>(t2341)));
                            *length_b_401 = implicit_cast<TNode<Smi>>(t2342);
                            // ../third_party/v8/builtins/array-sort.tq:1235:13
                            int31_t t2343 = 0;
                            TNode<Smi> t2344 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2343)));
                            *nof_wins_a_407 = implicit_cast<TNode<Smi>>(t2344);
                            // ../third_party/v8/builtins/array-sort.tq:1237:13
                            {
                              Label label__True_614_impl(this);
                              Label* label__True_614 = &label__True_614_impl;
                              USE(label__True_614);
                              Label label__False_615_impl(this, {});
                              Label* label__False_615 = &label__False_615_impl;
                              USE(label__False_615);
                              int31_t t2345 = 0;
                              TNode<Smi> t2346 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2345)));
                              TNode<BoolT> t2347 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_b_401).value()), implicit_cast<TNode<Smi>>(t2346)));
                              USE(implicit_cast<TNode<BoolT>>(t2347));
                              Branch(implicit_cast<TNode<BoolT>>(t2347), label__True_614, label__False_615);
                              if (label__True_614->is_used())
                              {
                                BIND(label__True_614);
                                // ../third_party/v8/builtins/array-sort.tq:1237:32
                                Goto(label_Succeed_602);
                              }
                              BIND(label__False_615);
                            }
                            // ../third_party/v8/builtins/array-sort.tq:1238:13
                            {
                              Label label__True_616_impl(this);
                              Label* label__True_616 = &label__True_616_impl;
                              USE(label__True_616);
                              Label label__False_617_impl(this, {});
                              Label* label__False_617 = &label__False_617_impl;
                              USE(label__False_617);
                              TNode<BoolT> t2348 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*nof_wins_b_408).value()), implicit_cast<TNode<Smi>>((*min_gallop_406).value())));
                              USE(implicit_cast<TNode<BoolT>>(t2348));
                              Branch(implicit_cast<TNode<BoolT>>(t2348), label__True_616, label__False_617);
                              if (label__True_616->is_used())
                              {
                                BIND(label__True_616);
                                // ../third_party/v8/builtins/array-sort.tq:1238:43
                                Goto(label__False_611);
                              }
                              BIND(label__False_617);
                            }
                          }
                          Goto(label_if_done_label_868_1133);
                        }
                        if (label__False_613->is_used())
                        {
                          BIND(label__False_613);
                          // ../third_party/v8/builtins/array-sort.tq:1239:18
                          {
                            // ../third_party/v8/builtins/array-sort.tq:1240:13
                            TNode<Object> t2349 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*temp_array_863)), implicit_cast<TNode<Smi>>((*cursor_temp_404).value())));
                            CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Store_862)), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Object>>(t2349), label_Bailout_601);
                            // ../third_party/v8/builtins/array-sort.tq:1245:13
                            TNode<Smi> t2350 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2351 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*cursor_temp_404).value()), implicit_cast<TNode<Smi>>(t2350)));
                            *cursor_temp_404 = implicit_cast<TNode<Smi>>(t2351);
                            // ../third_party/v8/builtins/array-sort.tq:1246:13
                            TNode<Smi> t2352 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2353 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Smi>>(t2352)));
                            *dest_403 = implicit_cast<TNode<Smi>>(t2353);
                            // ../third_party/v8/builtins/array-sort.tq:1247:13
                            TNode<Smi> t2354 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2355 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*nof_wins_a_407).value()), implicit_cast<TNode<Smi>>(t2354)));
                            *nof_wins_a_407 = implicit_cast<TNode<Smi>>(t2355);
                            // ../third_party/v8/builtins/array-sort.tq:1248:13
                            TNode<Smi> t2356 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2357 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_a_400).value()), implicit_cast<TNode<Smi>>(t2356)));
                            *length_a_400 = implicit_cast<TNode<Smi>>(t2357);
                            // ../third_party/v8/builtins/array-sort.tq:1249:13
                            int31_t t2358 = 0;
                            TNode<Smi> t2359 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2358)));
                            *nof_wins_b_408 = implicit_cast<TNode<Smi>>(t2359);
                            // ../third_party/v8/builtins/array-sort.tq:1251:13
                            {
                              Label label__True_618_impl(this);
                              Label* label__True_618 = &label__True_618_impl;
                              USE(label__True_618);
                              Label label__False_619_impl(this, {});
                              Label* label__False_619 = &label__False_619_impl;
                              USE(label__False_619);
                              int31_t t2360 = 1;
                              TNode<Smi> t2361 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2360)));
                              TNode<BoolT> t2362 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_a_400).value()), implicit_cast<TNode<Smi>>(t2361)));
                              USE(implicit_cast<TNode<BoolT>>(t2362));
                              Branch(implicit_cast<TNode<BoolT>>(t2362), label__True_618, label__False_619);
                              if (label__True_618->is_used())
                              {
                                BIND(label__True_618);
                                // ../third_party/v8/builtins/array-sort.tq:1251:32
                                Goto(label_CopyB_603);
                              }
                              BIND(label__False_619);
                            }
                            // ../third_party/v8/builtins/array-sort.tq:1252:13
                            {
                              Label label__True_620_impl(this);
                              Label* label__True_620 = &label__True_620_impl;
                              USE(label__True_620);
                              Label label__False_621_impl(this, {});
                              Label* label__False_621 = &label__False_621_impl;
                              USE(label__False_621);
                              TNode<BoolT> t2363 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*nof_wins_a_407).value()), implicit_cast<TNode<Smi>>((*min_gallop_406).value())));
                              USE(implicit_cast<TNode<BoolT>>(t2363));
                              Branch(implicit_cast<TNode<BoolT>>(t2363), label__True_620, label__False_621);
                              if (label__True_620->is_used())
                              {
                                BIND(label__True_620);
                                // ../third_party/v8/builtins/array-sort.tq:1252:43
                                Goto(label__False_611);
                              }
                              BIND(label__False_621);
                            }
                          }
                          Goto(label_if_done_label_868_1133);
                        }
                        BIND(label_if_done_label_868_1133);
                      }
                    }
                    Goto(label_header_867_1132);
                  }
                  BIND(label__False_611);
                }
                // ../third_party/v8/builtins/array-sort.tq:1259:9
                TNode<Smi> t2364 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                TNode<Smi> t2365 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*min_gallop_406).value()), implicit_cast<TNode<Smi>>(t2364)));
                *min_gallop_406 = implicit_cast<TNode<Smi>>(t2365);
                // ../third_party/v8/builtins/array-sort.tq:1260:9
                TVARIABLE(BoolT, first_iteration_411_impl);
                auto first_iteration_411 = &first_iteration_411_impl;
                USE(first_iteration_411);
                TNode<BoolT> t2366 = UncheckedCast<BoolT>(from_constexpr6ATbool(implicit_cast<bool>(true)));
                *first_iteration_411 = implicit_cast<TNode<BoolT>>(t2366);
                // ../third_party/v8/builtins/array-sort.tq:1261:9
                {
                  Label label__True_622_impl(this);
                  Label* label__True_622 = &label__True_622_impl;
                  USE(label__True_622);
                  Label label__False_623_impl(this);
                  Label* label__False_623 = &label__False_623_impl;
                  USE(label__False_623);
                  Label label_header_869_1134_impl(this, {cursor_b_405, cursor_temp_404, dest_403, elements_402, first_iteration_411, length_a_400, length_b_401, min_gallop_406, nof_wins_a_407, nof_wins_b_408});
                  Label* label_header_869_1134 = &label_header_869_1134_impl;
                  USE(label_header_869_1134);
                  Goto(label_header_869_1134);
                  BIND(label_header_869_1134);
                  Label label__False_624_impl(this);
                  Label* label__False_624 = &label__False_624_impl;
                  USE(label__False_624);
                  Label label__False_625_impl(this);
                  Label* label__False_625 = &label__False_625_impl;
                  USE(label__False_625);
                  TNode<Smi> t2367 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(kMinGallopWins())));
                  TNode<BoolT> t2368 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*nof_wins_a_407).value()), implicit_cast<TNode<Smi>>(t2367)));
                  USE(implicit_cast<TNode<BoolT>>(t2368));
                  GotoIf(implicit_cast<TNode<BoolT>>(t2368), label__True_622);
                  TNode<Smi> t2369 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(kMinGallopWins())));
                  TNode<BoolT> t2370 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*nof_wins_b_408).value()), implicit_cast<TNode<Smi>>(t2369)));
                  USE(implicit_cast<TNode<BoolT>>(t2370));
                  GotoIf(implicit_cast<TNode<BoolT>>(t2370), label__True_622);
                  Branch(implicit_cast<TNode<BoolT>>((*first_iteration_411).value()), label__True_622, label__False_623);
                  if (label__True_622->is_used())
                  {
                    BIND(label__True_622);
                    // ../third_party/v8/builtins/array-sort.tq:1262:33
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1263:11
                      TNode<BoolT> t2371 = UncheckedCast<BoolT>(from_constexpr6ATbool(implicit_cast<bool>(false)));
                      *first_iteration_411 = implicit_cast<TNode<BoolT>>(t2371);
                      // ../third_party/v8/builtins/array-sort.tq:1264:11
                      // ../third_party/v8/builtins/array-sort.tq:1266:11
                      int31_t t2372 = 1;
                      int31_t t2373 = 1;
                      TNode<Smi> t2374 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2373)));
                      TNode<Smi> t2375 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*min_gallop_406).value()), implicit_cast<TNode<Smi>>(t2374)));
                      USE(implicit_cast<TNode<Smi>>(t2375));
                      TNode<Smi> t2376 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2372)));
                      TNode<Smi> t2377 = UncheckedCast<Smi>(SmiMax(implicit_cast<TNode<Smi>>(t2376), implicit_cast<TNode<Smi>>(t2375)));
                      USE(implicit_cast<TNode<Smi>>(t2377));
                      *min_gallop_406 = implicit_cast<TNode<Smi>>(t2377);
                      // ../third_party/v8/builtins/array-sort.tq:1267:11
                      StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kMinGallopIdx()), implicit_cast<TNode<Object>>((*min_gallop_406).value()));
                      // ../third_party/v8/builtins/array-sort.tq:1269:11
                      TNode<Object> t2378 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_861)), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>((*cursor_b_405).value()), label_Bailout_601));
                      USE(implicit_cast<TNode<Object>>(t2378));
                      TVARIABLE(Object, key_right_412_impl);
                      auto key_right_412 = &key_right_412_impl;
                      USE(key_right_412);
                      *key_right_412 = implicit_cast<TNode<Object>>(t2378);
                      // ../third_party/v8/builtins/array-sort.tq:1272:11
                      int31_t t2379 = 0;
                      TNode<Smi> t2380 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2379)));
                      TNode<Smi> t2381 = UncheckedCast<Smi>(CallGallopRight(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoad19ATTempArrayElements).code())), implicit_cast<TNode<Object>>((*key_right_412).value()), implicit_cast<TNode<Smi>>((*cursor_temp_404).value()), implicit_cast<TNode<Smi>>((*length_a_400).value()), implicit_cast<TNode<Smi>>(t2380), implicit_cast<TNode<Oddball>>(True()), label_Bailout_601));
                      USE(implicit_cast<TNode<Smi>>(t2381));
                      *nof_wins_a_407 = implicit_cast<TNode<Smi>>(t2381);
                      // ../third_party/v8/builtins/array-sort.tq:1275:11
                      TNode<HeapObject> t2382 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
                      USE(implicit_cast<TNode<HeapObject>>(t2382));
                      *elements_402 = implicit_cast<TNode<HeapObject>>(t2382);
                      // ../third_party/v8/builtins/array-sort.tq:1276:11
                      // ../third_party/v8/builtins/array-sort.tq:1278:11
                      {
                        Label label__True_626_impl(this);
                        Label* label__True_626 = &label__True_626_impl;
                        USE(label__True_626);
                        Label label__False_627_impl(this, {cursor_temp_404, dest_403, length_a_400});
                        Label* label__False_627 = &label__False_627_impl;
                        USE(label__False_627);
                        int31_t t2383 = 0;
                        TNode<Smi> t2384 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2383)));
                        TNode<BoolT> t2385 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*nof_wins_a_407).value()), implicit_cast<TNode<Smi>>(t2384)));
                        USE(implicit_cast<TNode<BoolT>>(t2385));
                        Branch(implicit_cast<TNode<BoolT>>(t2385), label__True_626, label__False_627);
                        if (label__True_626->is_used())
                        {
                          BIND(label__True_626);
                          // ../third_party/v8/builtins/array-sort.tq:1278:31
                          {
                            // ../third_party/v8/builtins/array-sort.tq:1279:13
                            CallCopyFromTempArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<FixedArray>>((*temp_array_863)), implicit_cast<TNode<Smi>>((*cursor_temp_404).value()), implicit_cast<TNode<Smi>>((*nof_wins_a_407).value()), label_Bailout_601);
                            // ../third_party/v8/builtins/array-sort.tq:1282:13
                            TNode<Smi> t2386 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Smi>>((*nof_wins_a_407).value())));
                            USE(implicit_cast<TNode<Smi>>(t2386));
                            *dest_403 = implicit_cast<TNode<Smi>>(t2386);
                            // ../third_party/v8/builtins/array-sort.tq:1283:13
                            TNode<Smi> t2387 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*cursor_temp_404).value()), implicit_cast<TNode<Smi>>((*nof_wins_a_407).value())));
                            USE(implicit_cast<TNode<Smi>>(t2387));
                            *cursor_temp_404 = implicit_cast<TNode<Smi>>(t2387);
                            // ../third_party/v8/builtins/array-sort.tq:1284:13
                            TNode<Smi> t2388 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_a_400).value()), implicit_cast<TNode<Smi>>((*nof_wins_a_407).value())));
                            USE(implicit_cast<TNode<Smi>>(t2388));
                            *length_a_400 = implicit_cast<TNode<Smi>>(t2388);
                            // ../third_party/v8/builtins/array-sort.tq:1286:13
                            {
                              Label label__True_628_impl(this);
                              Label* label__True_628 = &label__True_628_impl;
                              USE(label__True_628);
                              Label label__False_629_impl(this, {});
                              Label* label__False_629 = &label__False_629_impl;
                              USE(label__False_629);
                              int31_t t2389 = 1;
                              TNode<Smi> t2390 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2389)));
                              TNode<BoolT> t2391 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_a_400).value()), implicit_cast<TNode<Smi>>(t2390)));
                              USE(implicit_cast<TNode<BoolT>>(t2391));
                              Branch(implicit_cast<TNode<BoolT>>(t2391), label__True_628, label__False_629);
                              if (label__True_628->is_used())
                              {
                                BIND(label__True_628);
                                // ../third_party/v8/builtins/array-sort.tq:1286:32
                                Goto(label_CopyB_603);
                              }
                              BIND(label__False_629);
                            }
                            // ../third_party/v8/builtins/array-sort.tq:1290:13
                            {
                              Label label__True_630_impl(this);
                              Label* label__True_630 = &label__True_630_impl;
                              USE(label__True_630);
                              Label label__False_631_impl(this, {});
                              Label* label__False_631 = &label__False_631_impl;
                              USE(label__False_631);
                              int31_t t2392 = 0;
                              TNode<Smi> t2393 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2392)));
                              TNode<BoolT> t2394 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_a_400).value()), implicit_cast<TNode<Smi>>(t2393)));
                              USE(implicit_cast<TNode<BoolT>>(t2394));
                              Branch(implicit_cast<TNode<BoolT>>(t2394), label__True_630, label__False_631);
                              if (label__True_630->is_used())
                              {
                                BIND(label__True_630);
                                // ../third_party/v8/builtins/array-sort.tq:1290:32
                                Goto(label_Succeed_602);
                              }
                              BIND(label__False_631);
                            }
                          }
                          Goto(label__False_627);
                        }
                        BIND(label__False_627);
                      }
                      // ../third_party/v8/builtins/array-sort.tq:1292:11
                      TNode<Smi> t2395 = implicit_cast<TNode<Smi>>((*cursor_b_405).value());
                      USE(t2395);
                      TNode<Smi> t2396 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t2397 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*cursor_b_405).value()), implicit_cast<TNode<Smi>>(t2396)));
                      *cursor_b_405 = implicit_cast<TNode<Smi>>(t2397);
                      TNode<Smi> t2398 = implicit_cast<TNode<Smi>>((*dest_403).value());
                      USE(t2398);
                      TNode<Smi> t2399 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t2400 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Smi>>(t2399)));
                      *dest_403 = implicit_cast<TNode<Smi>>(t2400);
                      CopyElement(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_861)), implicit_cast<TNode<Code>>((*Store_862)), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>(t2395), implicit_cast<TNode<Smi>>(t2398), label_Bailout_601);
                      // ../third_party/v8/builtins/array-sort.tq:1295:11
                      {
                        Label label__True_632_impl(this);
                        Label* label__True_632 = &label__True_632_impl;
                        USE(label__True_632);
                        Label label__False_633_impl(this, {length_b_401});
                        Label* label__False_633 = &label__False_633_impl;
                        USE(label__False_633);
                        TNode<Smi> t2401 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                        TNode<Smi> t2402 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_401).value()), implicit_cast<TNode<Smi>>(t2401)));
                        *length_b_401 = implicit_cast<TNode<Smi>>(t2402);
                        int31_t t2403 = 0;
                        TNode<Smi> t2404 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2403)));
                        TNode<BoolT> t2405 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>(t2402), implicit_cast<TNode<Smi>>(t2404)));
                        USE(implicit_cast<TNode<BoolT>>(t2405));
                        Branch(implicit_cast<TNode<BoolT>>(t2405), label__True_632, label__False_633);
                        if (label__True_632->is_used())
                        {
                          BIND(label__True_632);
                          // ../third_party/v8/builtins/array-sort.tq:1295:32
                          Goto(label_Succeed_602);
                        }
                        BIND(label__False_633);
                      }
                      // ../third_party/v8/builtins/array-sort.tq:1297:11
                      TNode<Object> t2406 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*temp_array_863)), implicit_cast<TNode<Smi>>((*cursor_temp_404).value())));
                      int31_t t2407 = 0;
                      TNode<Smi> t2408 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2407)));
                      TNode<Smi> t2409 = UncheckedCast<Smi>(CallGallopLeft(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_861)), implicit_cast<TNode<Object>>(t2406), implicit_cast<TNode<Smi>>((*cursor_b_405).value()), implicit_cast<TNode<Smi>>((*length_b_401).value()), implicit_cast<TNode<Smi>>(t2408), implicit_cast<TNode<Oddball>>(False()), label_Bailout_601));
                      USE(implicit_cast<TNode<Smi>>(t2409));
                      *nof_wins_b_408 = implicit_cast<TNode<Smi>>(t2409);
                      // ../third_party/v8/builtins/array-sort.tq:1301:11
                      TNode<HeapObject> t2410 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
                      USE(implicit_cast<TNode<HeapObject>>(t2410));
                      *elements_402 = implicit_cast<TNode<HeapObject>>(t2410);
                      // ../third_party/v8/builtins/array-sort.tq:1302:11
                      // ../third_party/v8/builtins/array-sort.tq:1303:11
                      {
                        Label label__True_634_impl(this);
                        Label* label__True_634 = &label__True_634_impl;
                        USE(label__True_634);
                        Label label__False_635_impl(this, {cursor_b_405, dest_403, length_b_401});
                        Label* label__False_635 = &label__False_635_impl;
                        USE(label__False_635);
                        int31_t t2411 = 0;
                        TNode<Smi> t2412 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2411)));
                        TNode<BoolT> t2413 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*nof_wins_b_408).value()), implicit_cast<TNode<Smi>>(t2412)));
                        USE(implicit_cast<TNode<BoolT>>(t2413));
                        Branch(implicit_cast<TNode<BoolT>>(t2413), label__True_634, label__False_635);
                        if (label__True_634->is_used())
                        {
                          BIND(label__True_634);
                          // ../third_party/v8/builtins/array-sort.tq:1303:31
                          {
                            // ../third_party/v8/builtins/array-sort.tq:1304:13
                            CallCopyWithinSortArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>((*cursor_b_405).value()), implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Smi>>((*nof_wins_b_408).value()), label_Bailout_601);
                            // ../third_party/v8/builtins/array-sort.tq:1308:13
                            TNode<Smi> t2414 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Smi>>((*nof_wins_b_408).value())));
                            USE(implicit_cast<TNode<Smi>>(t2414));
                            *dest_403 = implicit_cast<TNode<Smi>>(t2414);
                            // ../third_party/v8/builtins/array-sort.tq:1309:13
                            TNode<Smi> t2415 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*cursor_b_405).value()), implicit_cast<TNode<Smi>>((*nof_wins_b_408).value())));
                            USE(implicit_cast<TNode<Smi>>(t2415));
                            *cursor_b_405 = implicit_cast<TNode<Smi>>(t2415);
                            // ../third_party/v8/builtins/array-sort.tq:1310:13
                            TNode<Smi> t2416 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_401).value()), implicit_cast<TNode<Smi>>((*nof_wins_b_408).value())));
                            USE(implicit_cast<TNode<Smi>>(t2416));
                            *length_b_401 = implicit_cast<TNode<Smi>>(t2416);
                            // ../third_party/v8/builtins/array-sort.tq:1312:13
                            {
                              Label label__True_636_impl(this);
                              Label* label__True_636 = &label__True_636_impl;
                              USE(label__True_636);
                              Label label__False_637_impl(this, {});
                              Label* label__False_637 = &label__False_637_impl;
                              USE(label__False_637);
                              int31_t t2417 = 0;
                              TNode<Smi> t2418 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2417)));
                              TNode<BoolT> t2419 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_b_401).value()), implicit_cast<TNode<Smi>>(t2418)));
                              USE(implicit_cast<TNode<BoolT>>(t2419));
                              Branch(implicit_cast<TNode<BoolT>>(t2419), label__True_636, label__False_637);
                              if (label__True_636->is_used())
                              {
                                BIND(label__True_636);
                                // ../third_party/v8/builtins/array-sort.tq:1312:32
                                Goto(label_Succeed_602);
                              }
                              BIND(label__False_637);
                            }
                          }
                          Goto(label__False_635);
                        }
                        BIND(label__False_635);
                      }
                      // ../third_party/v8/builtins/array-sort.tq:1314:11
                      TNode<Smi> t2420 = implicit_cast<TNode<Smi>>((*dest_403).value());
                      USE(t2420);
                      TNode<Smi> t2421 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t2422 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Smi>>(t2421)));
                      *dest_403 = implicit_cast<TNode<Smi>>(t2422);
                      TNode<Smi> t2423 = implicit_cast<TNode<Smi>>((*cursor_temp_404).value());
                      USE(t2423);
                      TNode<Smi> t2424 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t2425 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*cursor_temp_404).value()), implicit_cast<TNode<Smi>>(t2424)));
                      *cursor_temp_404 = implicit_cast<TNode<Smi>>(t2425);
                      TNode<Object> t2426 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*temp_array_863)), implicit_cast<TNode<Smi>>(t2423)));
                      CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Store_862)), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>(t2420), implicit_cast<TNode<Object>>(t2426), label_Bailout_601);
                      // ../third_party/v8/builtins/array-sort.tq:1318:11
                      {
                        Label label__True_638_impl(this);
                        Label* label__True_638 = &label__True_638_impl;
                        USE(label__True_638);
                        Label label__False_639_impl(this, {length_a_400});
                        Label* label__False_639 = &label__False_639_impl;
                        USE(label__False_639);
                        TNode<Smi> t2427 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                        TNode<Smi> t2428 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_a_400).value()), implicit_cast<TNode<Smi>>(t2427)));
                        *length_a_400 = implicit_cast<TNode<Smi>>(t2428);
                        int31_t t2429 = 1;
                        TNode<Smi> t2430 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2429)));
                        TNode<BoolT> t2431 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>(t2428), implicit_cast<TNode<Smi>>(t2430)));
                        USE(implicit_cast<TNode<BoolT>>(t2431));
                        Branch(implicit_cast<TNode<BoolT>>(t2431), label__True_638, label__False_639);
                        if (label__True_638->is_used())
                        {
                          BIND(label__True_638);
                          // ../third_party/v8/builtins/array-sort.tq:1318:32
                          Goto(label_CopyB_603);
                        }
                        BIND(label__False_639);
                      }
                    }
                    Goto(label_header_869_1134);
                  }
                  BIND(label__False_623);
                }
                // ../third_party/v8/builtins/array-sort.tq:1320:9
                TNode<Smi> t2432 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                TNode<Smi> t2433 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*min_gallop_406).value()), implicit_cast<TNode<Smi>>(t2432)));
                *min_gallop_406 = implicit_cast<TNode<Smi>>(t2433);
                // ../third_party/v8/builtins/array-sort.tq:1321:9
                StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kMinGallopIdx()), implicit_cast<TNode<Object>>((*min_gallop_406).value()));
              }
              Goto(label_header_866_1131);
            }
            BIND(label__False_609);
          }
        }
        Goto(label_try_done_864_1129);
      }
      if (label_Succeed_602->is_used())
      {
        BIND(label_Succeed_602);
        // ../third_party/v8/builtins/array-sort.tq:1324:19
        {
          // ../third_party/v8/builtins/array-sort.tq:1325:7
          {
            Label label__True_640_impl(this);
            Label* label__True_640 = &label__True_640_impl;
            USE(label__True_640);
            Label label__False_641_impl(this, {});
            Label* label__False_641 = &label__False_641_impl;
            USE(label__False_641);
            int31_t t2434 = 0;
            TNode<Smi> t2435 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2434)));
            TNode<BoolT> t2436 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*length_a_400).value()), implicit_cast<TNode<Smi>>(t2435)));
            USE(implicit_cast<TNode<BoolT>>(t2436));
            Branch(implicit_cast<TNode<BoolT>>(t2436), label__True_640, label__False_641);
            if (label__True_640->is_used())
            {
              BIND(label__True_640);
              // ../third_party/v8/builtins/array-sort.tq:1325:25
              {
                // ../third_party/v8/builtins/array-sort.tq:1326:9
                CallCopyFromTempArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<FixedArray>>((*temp_array_863)), implicit_cast<TNode<Smi>>((*cursor_temp_404).value()), implicit_cast<TNode<Smi>>((*length_a_400).value()), label_Bailout_601);
              }
              Goto(label__False_641);
            }
            BIND(label__False_641);
          }
        }
        Goto(label_try_done_864_1129);
      }
      if (label_CopyB_603->is_used())
      {
        BIND(label_CopyB_603);
        // ../third_party/v8/builtins/array-sort.tq:1331:17
        {
          // ../third_party/v8/builtins/array-sort.tq:1332:7
          // ../third_party/v8/builtins/array-sort.tq:1334:7
          CallCopyWithinSortArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>((*cursor_b_405).value()), implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Smi>>((*length_b_401).value()), label_Bailout_601);
          // ../third_party/v8/builtins/array-sort.tq:1337:7
          TNode<Smi> t2437 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_403).value()), implicit_cast<TNode<Smi>>((*length_b_401).value())));
          USE(implicit_cast<TNode<Smi>>(t2437));
          TNode<Object> t2438 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*temp_array_863)), implicit_cast<TNode<Smi>>((*cursor_temp_404).value())));
          CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Store_862)), implicit_cast<TNode<HeapObject>>((*elements_402).value()), implicit_cast<TNode<Smi>>(t2437), implicit_cast<TNode<Object>>(t2438), label_Bailout_601);
        }
        Goto(label_try_done_864_1129);
      }
      BIND(label_try_done_864_1129);
    }
  }
}

void ArrayBuiltinsFromDSLAssembler::MergeHigh(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Smi> p_baseA, TNode<Smi> p_lengthA, TNode<Smi> p_baseB, TNode<Smi> p_lengthB, Label* label_Bailout_642) {
  Label label_macro_end_1135_impl(this, {});
  Label* label_macro_end_1135 = &label_macro_end_1135_impl;
  USE(label_macro_end_1135);
  // ../third_party/v8/builtins/array-sort.tq:1351:18
  {
    // ../third_party/v8/builtins/array-sort.tq:1352:5
    // ../third_party/v8/builtins/array-sort.tq:1353:5
    // ../third_party/v8/builtins/array-sort.tq:1354:5
    // ../third_party/v8/builtins/array-sort.tq:1356:5
    TVARIABLE(Smi, length_a_413_impl);
    auto length_a_413 = &length_a_413_impl;
    USE(length_a_413);
    *length_a_413 = implicit_cast<TNode<Smi>>(p_lengthA);
    // ../third_party/v8/builtins/array-sort.tq:1357:5
    TVARIABLE(Smi, length_b_414_impl);
    auto length_b_414 = &length_b_414_impl;
    USE(length_b_414);
    *length_b_414 = implicit_cast<TNode<Smi>>(p_lengthB);
    // ../third_party/v8/builtins/array-sort.tq:1359:5
    TNode<HeapObject> t2439 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<HeapObject>>(t2439));
    TVARIABLE(HeapObject, elements_415_impl);
    auto elements_415 = &elements_415_impl;
    USE(elements_415);
    *elements_415 = implicit_cast<TNode<HeapObject>>(t2439);
    // ../third_party/v8/builtins/array-sort.tq:1360:5
    TNode<Code> t2440 = UncheckedCast<Code>(GetLoadFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Code>>(t2440));
    TNode<Code> LoadF_870_impl;
    auto LoadF_870 = &LoadF_870_impl;
    USE(LoadF_870);
    *LoadF_870 = implicit_cast<TNode<Code>>(t2440);
    // ../third_party/v8/builtins/array-sort.tq:1361:5
    TNode<Code> t2441 = UncheckedCast<Code>(GetStoreFn(implicit_cast<TNode<FixedArray>>(p_sortState)));
    USE(implicit_cast<TNode<Code>>(t2441));
    TNode<Code> Store_871_impl;
    auto Store_871 = &Store_871_impl;
    USE(Store_871);
    *Store_871 = implicit_cast<TNode<Code>>(t2441);
    // ../third_party/v8/builtins/array-sort.tq:1363:5
    TNode<FixedArray> t2442 = UncheckedCast<FixedArray>(GetTempArray(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>((*length_b_414).value())));
    USE(implicit_cast<TNode<FixedArray>>(t2442));
    TNode<FixedArray> temp_array_872_impl;
    auto temp_array_872 = &temp_array_872_impl;
    USE(temp_array_872);
    *temp_array_872 = implicit_cast<TNode<FixedArray>>(t2442);
    // ../third_party/v8/builtins/array-sort.tq:1364:5
    int31_t t2443 = 0;
    TNode<Smi> t2444 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2443)));
    CopyToTempArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_870)), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>(p_baseB), implicit_cast<TNode<FixedArray>>((*temp_array_872)), implicit_cast<TNode<Smi>>(t2444), implicit_cast<TNode<Smi>>((*length_b_414).value()), label_Bailout_642);
    // ../third_party/v8/builtins/array-sort.tq:1369:5
    TNode<Smi> t2445 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_baseB), implicit_cast<TNode<Smi>>((*length_b_414).value())));
    USE(implicit_cast<TNode<Smi>>(t2445));
    int31_t t2446 = 1;
    TNode<Smi> t2447 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2446)));
    TNode<Smi> t2448 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t2445), implicit_cast<TNode<Smi>>(t2447)));
    USE(implicit_cast<TNode<Smi>>(t2448));
    TVARIABLE(Smi, dest_416_impl);
    auto dest_416 = &dest_416_impl;
    USE(dest_416);
    *dest_416 = implicit_cast<TNode<Smi>>(t2448);
    // ../third_party/v8/builtins/array-sort.tq:1370:5
    int31_t t2449 = 1;
    TNode<Smi> t2450 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2449)));
    TNode<Smi> t2451 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2450)));
    USE(implicit_cast<TNode<Smi>>(t2451));
    TVARIABLE(Smi, cursor_temp_417_impl);
    auto cursor_temp_417 = &cursor_temp_417_impl;
    USE(cursor_temp_417);
    *cursor_temp_417 = implicit_cast<TNode<Smi>>(t2451);
    // ../third_party/v8/builtins/array-sort.tq:1371:5
    TNode<Smi> t2452 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>(p_baseA), implicit_cast<TNode<Smi>>((*length_a_413).value())));
    USE(implicit_cast<TNode<Smi>>(t2452));
    int31_t t2453 = 1;
    TNode<Smi> t2454 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2453)));
    TNode<Smi> t2455 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t2452), implicit_cast<TNode<Smi>>(t2454)));
    USE(implicit_cast<TNode<Smi>>(t2455));
    TVARIABLE(Smi, cursor_a_418_impl);
    auto cursor_a_418 = &cursor_a_418_impl;
    USE(cursor_a_418);
    *cursor_a_418 = implicit_cast<TNode<Smi>>(t2455);
    // ../third_party/v8/builtins/array-sort.tq:1373:5
    TNode<Smi> t2456 = implicit_cast<TNode<Smi>>((*cursor_a_418).value());
    USE(t2456);
    TNode<Smi> t2457 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
    TNode<Smi> t2458 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*cursor_a_418).value()), implicit_cast<TNode<Smi>>(t2457)));
    *cursor_a_418 = implicit_cast<TNode<Smi>>(t2458);
    TNode<Smi> t2459 = implicit_cast<TNode<Smi>>((*dest_416).value());
    USE(t2459);
    TNode<Smi> t2460 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
    TNode<Smi> t2461 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>(t2460)));
    *dest_416 = implicit_cast<TNode<Smi>>(t2461);
    CopyElement(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_870)), implicit_cast<TNode<Code>>((*Store_871)), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>(t2456), implicit_cast<TNode<Smi>>(t2459), label_Bailout_642);
    // ../third_party/v8/builtins/array-sort.tq:1376:5
    {
      Label label_try_done_873_1136_impl(this);
      Label* label_try_done_873_1136 = &label_try_done_873_1136_impl;
      USE(label_try_done_873_1136);
      Label label_Succeed_643_impl(this);
      Label* label_Succeed_643 = &label_Succeed_643_impl;
      USE(label_Succeed_643);
      Label label_CopyA_644_impl(this);
      Label* label_CopyA_644 = &label_CopyA_644_impl;
      USE(label_CopyA_644);
      Label label_try_begin_874_1137_impl(this);
      Label* label_try_begin_874_1137 = &label_try_begin_874_1137_impl;
      USE(label_try_begin_874_1137);
      Goto(label_try_begin_874_1137);
      if (label_try_begin_874_1137->is_used())
      {
        BIND(label_try_begin_874_1137);
        // ../third_party/v8/builtins/array-sort.tq:1376:9
        {
          // ../third_party/v8/builtins/array-sort.tq:1377:7
          {
            Label label__True_645_impl(this);
            Label* label__True_645 = &label__True_645_impl;
            USE(label__True_645);
            Label label__False_646_impl(this, {length_a_413});
            Label* label__False_646 = &label__False_646_impl;
            USE(label__False_646);
            TNode<Smi> t2462 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
            TNode<Smi> t2463 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_a_413).value()), implicit_cast<TNode<Smi>>(t2462)));
            *length_a_413 = implicit_cast<TNode<Smi>>(t2463);
            int31_t t2464 = 0;
            TNode<Smi> t2465 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2464)));
            TNode<BoolT> t2466 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>(t2463), implicit_cast<TNode<Smi>>(t2465)));
            USE(implicit_cast<TNode<BoolT>>(t2466));
            Branch(implicit_cast<TNode<BoolT>>(t2466), label__True_645, label__False_646);
            if (label__True_645->is_used())
            {
              BIND(label__True_645);
              // ../third_party/v8/builtins/array-sort.tq:1377:28
              Goto(label_Succeed_643);
            }
            BIND(label__False_646);
          }
          // ../third_party/v8/builtins/array-sort.tq:1378:7
          {
            Label label__True_647_impl(this);
            Label* label__True_647 = &label__True_647_impl;
            USE(label__True_647);
            Label label__False_648_impl(this, {});
            Label* label__False_648 = &label__False_648_impl;
            USE(label__False_648);
            int31_t t2467 = 1;
            TNode<Smi> t2468 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2467)));
            TNode<BoolT> t2469 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2468)));
            USE(implicit_cast<TNode<BoolT>>(t2469));
            Branch(implicit_cast<TNode<BoolT>>(t2469), label__True_647, label__False_648);
            if (label__True_647->is_used())
            {
              BIND(label__True_647);
              // ../third_party/v8/builtins/array-sort.tq:1378:26
              Goto(label_CopyA_644);
            }
            BIND(label__False_648);
          }
          // ../third_party/v8/builtins/array-sort.tq:1380:7
          TNode<Object> t2470 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kMinGallopIdx())));
          TNode<Smi> t2471 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(t2470)));
          USE(implicit_cast<TNode<Smi>>(t2471));
          TVARIABLE(Smi, min_gallop_419_impl);
          auto min_gallop_419 = &min_gallop_419_impl;
          USE(min_gallop_419);
          *min_gallop_419 = implicit_cast<TNode<Smi>>(t2471);
          // ../third_party/v8/builtins/array-sort.tq:1383:7
          {
            Label label__True_649_impl(this);
            Label* label__True_649 = &label__True_649_impl;
            USE(label__True_649);
            Label label__False_650_impl(this);
            Label* label__False_650 = &label__False_650_impl;
            USE(label__False_650);
            Label label_header_875_1138_impl(this, {cursor_a_418, cursor_temp_417, dest_416, elements_415, length_a_413, length_b_414, min_gallop_419});
            Label* label_header_875_1138 = &label_header_875_1138_impl;
            USE(label_header_875_1138);
            Goto(label_header_875_1138);
            BIND(label_header_875_1138);
            TNode<BoolT> t2472 = UncheckedCast<BoolT>(Int32TrueConstant());
            USE(implicit_cast<TNode<BoolT>>(t2472));
            Branch(implicit_cast<TNode<BoolT>>(t2472), label__True_649, label__False_650);
            if (label__True_649->is_used())
            {
              BIND(label__True_649);
              // ../third_party/v8/builtins/array-sort.tq:1383:35
              {
                // ../third_party/v8/builtins/array-sort.tq:1384:9
                int31_t t2473 = 0;
                TVARIABLE(Smi, nof_wins_a_420_impl);
                auto nof_wins_a_420 = &nof_wins_a_420_impl;
                USE(nof_wins_a_420);
                TNode<Smi> t2474 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2473)));
                *nof_wins_a_420 = implicit_cast<TNode<Smi>>(t2474);
                // ../third_party/v8/builtins/array-sort.tq:1385:9
                int31_t t2475 = 0;
                TVARIABLE(Smi, nof_wins_b_421_impl);
                auto nof_wins_b_421 = &nof_wins_b_421_impl;
                USE(nof_wins_b_421);
                TNode<Smi> t2476 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2475)));
                *nof_wins_b_421 = implicit_cast<TNode<Smi>>(t2476);
                // ../third_party/v8/builtins/array-sort.tq:1391:9
                {
                  Label label__True_651_impl(this);
                  Label* label__True_651 = &label__True_651_impl;
                  USE(label__True_651);
                  Label label__False_652_impl(this);
                  Label* label__False_652 = &label__False_652_impl;
                  USE(label__False_652);
                  Label label_header_876_1139_impl(this, {cursor_a_418, cursor_temp_417, dest_416, elements_415, length_a_413, length_b_414, nof_wins_a_420, nof_wins_b_421});
                  Label* label_header_876_1139 = &label_header_876_1139_impl;
                  USE(label_header_876_1139);
                  Goto(label_header_876_1139);
                  BIND(label_header_876_1139);
                  TNode<BoolT> t2477 = UncheckedCast<BoolT>(Int32TrueConstant());
                  USE(implicit_cast<TNode<BoolT>>(t2477));
                  Branch(implicit_cast<TNode<BoolT>>(t2477), label__True_651, label__False_652);
                  if (label__True_651->is_used())
                  {
                    BIND(label__True_651);
                    // ../third_party/v8/builtins/array-sort.tq:1391:37
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1392:11
                      // ../third_party/v8/builtins/array-sort.tq:1394:11
                      TNode<Object> t2478 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_870)), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>((*cursor_a_418).value()), label_Bailout_642));
                      USE(implicit_cast<TNode<Object>>(t2478));
                      TVARIABLE(Object, element_a_422_impl);
                      auto element_a_422 = &element_a_422_impl;
                      USE(element_a_422);
                      *element_a_422 = implicit_cast<TNode<Object>>(t2478);
                      // ../third_party/v8/builtins/array-sort.tq:1397:11
                      TNode<Object> t2479 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*temp_array_872)), implicit_cast<TNode<Smi>>((*cursor_temp_417).value())));
                      TNode<Number> t2480 = UncheckedCast<Number>(CallCompareFn(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Object>>(t2479), implicit_cast<TNode<Object>>((*element_a_422).value()), label_Bailout_642));
                      USE(implicit_cast<TNode<Number>>(t2480));
                      TVARIABLE(Number, order_423_impl);
                      auto order_423 = &order_423_impl;
                      USE(order_423);
                      *order_423 = implicit_cast<TNode<Number>>(t2480);
                      // ../third_party/v8/builtins/array-sort.tq:1400:11
                      TNode<HeapObject> t2481 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
                      USE(implicit_cast<TNode<HeapObject>>(t2481));
                      *elements_415 = implicit_cast<TNode<HeapObject>>(t2481);
                      // ../third_party/v8/builtins/array-sort.tq:1402:11
                      {
                        Label label__True_653_impl(this);
                        Label* label__True_653 = &label__True_653_impl;
                        USE(label__True_653);
                        Label label__False_654_impl(this);
                        Label* label__False_654 = &label__False_654_impl;
                        USE(label__False_654);
                        Label label_if_done_label_877_1140_impl(this, {cursor_a_418, cursor_temp_417, dest_416, length_a_413, length_b_414, nof_wins_a_420, nof_wins_b_421});
                        Label* label_if_done_label_877_1140 = &label_if_done_label_877_1140_impl;
                        USE(label_if_done_label_877_1140);
                        int31_t t2482 = 0;
                        TNode<Number> t2483 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2482)));
                        BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*order_423).value()), implicit_cast<TNode<Number>>(t2483), label__True_653, label__False_654);
                        if (label__True_653->is_used())
                        {
                          BIND(label__True_653);
                          // ../third_party/v8/builtins/array-sort.tq:1402:26
                          {
                            // ../third_party/v8/builtins/array-sort.tq:1403:13
                            CopyElement(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_870)), implicit_cast<TNode<Code>>((*Store_871)), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>((*cursor_a_418).value()), implicit_cast<TNode<Smi>>((*dest_416).value()), label_Bailout_642);
                            // ../third_party/v8/builtins/array-sort.tq:1407:13
                            TNode<Smi> t2484 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2485 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*cursor_a_418).value()), implicit_cast<TNode<Smi>>(t2484)));
                            *cursor_a_418 = implicit_cast<TNode<Smi>>(t2485);
                            // ../third_party/v8/builtins/array-sort.tq:1408:13
                            TNode<Smi> t2486 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2487 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>(t2486)));
                            *dest_416 = implicit_cast<TNode<Smi>>(t2487);
                            // ../third_party/v8/builtins/array-sort.tq:1409:13
                            TNode<Smi> t2488 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2489 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*nof_wins_a_420).value()), implicit_cast<TNode<Smi>>(t2488)));
                            *nof_wins_a_420 = implicit_cast<TNode<Smi>>(t2489);
                            // ../third_party/v8/builtins/array-sort.tq:1410:13
                            TNode<Smi> t2490 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2491 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_a_413).value()), implicit_cast<TNode<Smi>>(t2490)));
                            *length_a_413 = implicit_cast<TNode<Smi>>(t2491);
                            // ../third_party/v8/builtins/array-sort.tq:1411:13
                            int31_t t2492 = 0;
                            TNode<Smi> t2493 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2492)));
                            *nof_wins_b_421 = implicit_cast<TNode<Smi>>(t2493);
                            // ../third_party/v8/builtins/array-sort.tq:1413:13
                            {
                              Label label__True_655_impl(this);
                              Label* label__True_655 = &label__True_655_impl;
                              USE(label__True_655);
                              Label label__False_656_impl(this, {});
                              Label* label__False_656 = &label__False_656_impl;
                              USE(label__False_656);
                              int31_t t2494 = 0;
                              TNode<Smi> t2495 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2494)));
                              TNode<BoolT> t2496 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_a_413).value()), implicit_cast<TNode<Smi>>(t2495)));
                              USE(implicit_cast<TNode<BoolT>>(t2496));
                              Branch(implicit_cast<TNode<BoolT>>(t2496), label__True_655, label__False_656);
                              if (label__True_655->is_used())
                              {
                                BIND(label__True_655);
                                // ../third_party/v8/builtins/array-sort.tq:1413:32
                                Goto(label_Succeed_643);
                              }
                              BIND(label__False_656);
                            }
                            // ../third_party/v8/builtins/array-sort.tq:1414:13
                            {
                              Label label__True_657_impl(this);
                              Label* label__True_657 = &label__True_657_impl;
                              USE(label__True_657);
                              Label label__False_658_impl(this, {});
                              Label* label__False_658 = &label__False_658_impl;
                              USE(label__False_658);
                              TNode<BoolT> t2497 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*nof_wins_a_420).value()), implicit_cast<TNode<Smi>>((*min_gallop_419).value())));
                              USE(implicit_cast<TNode<BoolT>>(t2497));
                              Branch(implicit_cast<TNode<BoolT>>(t2497), label__True_657, label__False_658);
                              if (label__True_657->is_used())
                              {
                                BIND(label__True_657);
                                // ../third_party/v8/builtins/array-sort.tq:1414:43
                                Goto(label__False_652);
                              }
                              BIND(label__False_658);
                            }
                          }
                          Goto(label_if_done_label_877_1140);
                        }
                        if (label__False_654->is_used())
                        {
                          BIND(label__False_654);
                          // ../third_party/v8/builtins/array-sort.tq:1415:18
                          {
                            // ../third_party/v8/builtins/array-sort.tq:1416:13
                            TNode<Object> t2498 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*temp_array_872)), implicit_cast<TNode<Smi>>((*cursor_temp_417).value())));
                            CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Store_871)), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Object>>(t2498), label_Bailout_642);
                            // ../third_party/v8/builtins/array-sort.tq:1421:13
                            TNode<Smi> t2499 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2500 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*cursor_temp_417).value()), implicit_cast<TNode<Smi>>(t2499)));
                            *cursor_temp_417 = implicit_cast<TNode<Smi>>(t2500);
                            // ../third_party/v8/builtins/array-sort.tq:1422:13
                            TNode<Smi> t2501 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2502 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>(t2501)));
                            *dest_416 = implicit_cast<TNode<Smi>>(t2502);
                            // ../third_party/v8/builtins/array-sort.tq:1423:13
                            TNode<Smi> t2503 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2504 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*nof_wins_b_421).value()), implicit_cast<TNode<Smi>>(t2503)));
                            *nof_wins_b_421 = implicit_cast<TNode<Smi>>(t2504);
                            // ../third_party/v8/builtins/array-sort.tq:1424:13
                            TNode<Smi> t2505 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                            TNode<Smi> t2506 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2505)));
                            *length_b_414 = implicit_cast<TNode<Smi>>(t2506);
                            // ../third_party/v8/builtins/array-sort.tq:1425:13
                            int31_t t2507 = 0;
                            TNode<Smi> t2508 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2507)));
                            *nof_wins_a_420 = implicit_cast<TNode<Smi>>(t2508);
                            // ../third_party/v8/builtins/array-sort.tq:1427:13
                            {
                              Label label__True_659_impl(this);
                              Label* label__True_659 = &label__True_659_impl;
                              USE(label__True_659);
                              Label label__False_660_impl(this, {});
                              Label* label__False_660 = &label__False_660_impl;
                              USE(label__False_660);
                              int31_t t2509 = 1;
                              TNode<Smi> t2510 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2509)));
                              TNode<BoolT> t2511 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2510)));
                              USE(implicit_cast<TNode<BoolT>>(t2511));
                              Branch(implicit_cast<TNode<BoolT>>(t2511), label__True_659, label__False_660);
                              if (label__True_659->is_used())
                              {
                                BIND(label__True_659);
                                // ../third_party/v8/builtins/array-sort.tq:1427:32
                                Goto(label_CopyA_644);
                              }
                              BIND(label__False_660);
                            }
                            // ../third_party/v8/builtins/array-sort.tq:1428:13
                            {
                              Label label__True_661_impl(this);
                              Label* label__True_661 = &label__True_661_impl;
                              USE(label__True_661);
                              Label label__False_662_impl(this, {});
                              Label* label__False_662 = &label__False_662_impl;
                              USE(label__False_662);
                              TNode<BoolT> t2512 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*nof_wins_b_421).value()), implicit_cast<TNode<Smi>>((*min_gallop_419).value())));
                              USE(implicit_cast<TNode<BoolT>>(t2512));
                              Branch(implicit_cast<TNode<BoolT>>(t2512), label__True_661, label__False_662);
                              if (label__True_661->is_used())
                              {
                                BIND(label__True_661);
                                // ../third_party/v8/builtins/array-sort.tq:1428:43
                                Goto(label__False_652);
                              }
                              BIND(label__False_662);
                            }
                          }
                          Goto(label_if_done_label_877_1140);
                        }
                        BIND(label_if_done_label_877_1140);
                      }
                    }
                    Goto(label_header_876_1139);
                  }
                  BIND(label__False_652);
                }
                // ../third_party/v8/builtins/array-sort.tq:1435:9
                TNode<Smi> t2513 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                TNode<Smi> t2514 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*min_gallop_419).value()), implicit_cast<TNode<Smi>>(t2513)));
                *min_gallop_419 = implicit_cast<TNode<Smi>>(t2514);
                // ../third_party/v8/builtins/array-sort.tq:1436:9
                TVARIABLE(BoolT, first_iteration_424_impl);
                auto first_iteration_424 = &first_iteration_424_impl;
                USE(first_iteration_424);
                TNode<BoolT> t2515 = UncheckedCast<BoolT>(from_constexpr6ATbool(implicit_cast<bool>(true)));
                *first_iteration_424 = implicit_cast<TNode<BoolT>>(t2515);
                // ../third_party/v8/builtins/array-sort.tq:1437:9
                {
                  Label label__True_663_impl(this);
                  Label* label__True_663 = &label__True_663_impl;
                  USE(label__True_663);
                  Label label__False_664_impl(this);
                  Label* label__False_664 = &label__False_664_impl;
                  USE(label__False_664);
                  Label label_header_878_1141_impl(this, {cursor_a_418, cursor_temp_417, dest_416, elements_415, first_iteration_424, length_a_413, length_b_414, min_gallop_419, nof_wins_a_420, nof_wins_b_421});
                  Label* label_header_878_1141 = &label_header_878_1141_impl;
                  USE(label_header_878_1141);
                  Goto(label_header_878_1141);
                  BIND(label_header_878_1141);
                  Label label__False_665_impl(this);
                  Label* label__False_665 = &label__False_665_impl;
                  USE(label__False_665);
                  Label label__False_666_impl(this);
                  Label* label__False_666 = &label__False_666_impl;
                  USE(label__False_666);
                  TNode<Smi> t2516 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(kMinGallopWins())));
                  TNode<BoolT> t2517 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*nof_wins_a_420).value()), implicit_cast<TNode<Smi>>(t2516)));
                  USE(implicit_cast<TNode<BoolT>>(t2517));
                  GotoIf(implicit_cast<TNode<BoolT>>(t2517), label__True_663);
                  TNode<Smi> t2518 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(kMinGallopWins())));
                  TNode<BoolT> t2519 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*nof_wins_b_421).value()), implicit_cast<TNode<Smi>>(t2518)));
                  USE(implicit_cast<TNode<BoolT>>(t2519));
                  GotoIf(implicit_cast<TNode<BoolT>>(t2519), label__True_663);
                  Branch(implicit_cast<TNode<BoolT>>((*first_iteration_424).value()), label__True_663, label__False_664);
                  if (label__True_663->is_used())
                  {
                    BIND(label__True_663);
                    // ../third_party/v8/builtins/array-sort.tq:1438:33
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1439:11
                      TNode<BoolT> t2520 = UncheckedCast<BoolT>(from_constexpr6ATbool(implicit_cast<bool>(false)));
                      *first_iteration_424 = implicit_cast<TNode<BoolT>>(t2520);
                      // ../third_party/v8/builtins/array-sort.tq:1441:11
                      // ../third_party/v8/builtins/array-sort.tq:1443:11
                      int31_t t2521 = 1;
                      int31_t t2522 = 1;
                      TNode<Smi> t2523 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2522)));
                      TNode<Smi> t2524 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*min_gallop_419).value()), implicit_cast<TNode<Smi>>(t2523)));
                      USE(implicit_cast<TNode<Smi>>(t2524));
                      TNode<Smi> t2525 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2521)));
                      TNode<Smi> t2526 = UncheckedCast<Smi>(SmiMax(implicit_cast<TNode<Smi>>(t2525), implicit_cast<TNode<Smi>>(t2524)));
                      USE(implicit_cast<TNode<Smi>>(t2526));
                      *min_gallop_419 = implicit_cast<TNode<Smi>>(t2526);
                      // ../third_party/v8/builtins/array-sort.tq:1444:11
                      StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kMinGallopIdx()), implicit_cast<TNode<Object>>((*min_gallop_419).value()));
                      // ../third_party/v8/builtins/array-sort.tq:1446:11
                      TNode<Object> t2527 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*temp_array_872)), implicit_cast<TNode<Smi>>((*cursor_temp_417).value())));
                      int31_t t2528 = 1;
                      TNode<Smi> t2529 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2528)));
                      TNode<Smi> t2530 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_a_413).value()), implicit_cast<TNode<Smi>>(t2529)));
                      USE(implicit_cast<TNode<Smi>>(t2530));
                      TNode<Smi> t2531 = UncheckedCast<Smi>(CallGallopRight(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_870)), implicit_cast<TNode<Object>>(t2527), implicit_cast<TNode<Smi>>(p_baseA), implicit_cast<TNode<Smi>>((*length_a_413).value()), implicit_cast<TNode<Smi>>(t2530), implicit_cast<TNode<Oddball>>(False()), label_Bailout_642));
                      USE(implicit_cast<TNode<Smi>>(t2531));
                      TVARIABLE(Smi, k_425_impl);
                      auto k_425 = &k_425_impl;
                      USE(k_425);
                      *k_425 = implicit_cast<TNode<Smi>>(t2531);
                      // ../third_party/v8/builtins/array-sort.tq:1450:11
                      TNode<HeapObject> t2532 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
                      USE(implicit_cast<TNode<HeapObject>>(t2532));
                      *elements_415 = implicit_cast<TNode<HeapObject>>(t2532);
                      // ../third_party/v8/builtins/array-sort.tq:1451:11
                      // ../third_party/v8/builtins/array-sort.tq:1452:11
                      TNode<Smi> t2533 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_a_413).value()), implicit_cast<TNode<Smi>>((*k_425).value())));
                      USE(implicit_cast<TNode<Smi>>(t2533));
                      *nof_wins_a_420 = implicit_cast<TNode<Smi>>(t2533);
                      // ../third_party/v8/builtins/array-sort.tq:1454:11
                      {
                        Label label__True_667_impl(this);
                        Label* label__True_667 = &label__True_667_impl;
                        USE(label__True_667);
                        Label label__False_668_impl(this, {cursor_a_418, dest_416, length_a_413});
                        Label* label__False_668 = &label__False_668_impl;
                        USE(label__False_668);
                        int31_t t2534 = 0;
                        TNode<Smi> t2535 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2534)));
                        TNode<BoolT> t2536 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*nof_wins_a_420).value()), implicit_cast<TNode<Smi>>(t2535)));
                        USE(implicit_cast<TNode<BoolT>>(t2536));
                        Branch(implicit_cast<TNode<BoolT>>(t2536), label__True_667, label__False_668);
                        if (label__True_667->is_used())
                        {
                          BIND(label__True_667);
                          // ../third_party/v8/builtins/array-sort.tq:1454:31
                          {
                            // ../third_party/v8/builtins/array-sort.tq:1455:13
                            TNode<Smi> t2537 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>((*nof_wins_a_420).value())));
                            USE(implicit_cast<TNode<Smi>>(t2537));
                            *dest_416 = implicit_cast<TNode<Smi>>(t2537);
                            // ../third_party/v8/builtins/array-sort.tq:1456:13
                            TNode<Smi> t2538 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*cursor_a_418).value()), implicit_cast<TNode<Smi>>((*nof_wins_a_420).value())));
                            USE(implicit_cast<TNode<Smi>>(t2538));
                            *cursor_a_418 = implicit_cast<TNode<Smi>>(t2538);
                            // ../third_party/v8/builtins/array-sort.tq:1457:13
                            int31_t t2539 = 1;
                            TNode<Smi> t2540 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2539)));
                            TNode<Smi> t2541 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*cursor_a_418).value()), implicit_cast<TNode<Smi>>(t2540)));
                            USE(implicit_cast<TNode<Smi>>(t2541));
                            int31_t t2542 = 1;
                            TNode<Smi> t2543 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2542)));
                            TNode<Smi> t2544 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>(t2543)));
                            USE(implicit_cast<TNode<Smi>>(t2544));
                            CallCopyWithinSortArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>(t2541), implicit_cast<TNode<Smi>>(t2544), implicit_cast<TNode<Smi>>((*nof_wins_a_420).value()), label_Bailout_642);
                            // ../third_party/v8/builtins/array-sort.tq:1462:13
                            TNode<Smi> t2545 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_a_413).value()), implicit_cast<TNode<Smi>>((*nof_wins_a_420).value())));
                            USE(implicit_cast<TNode<Smi>>(t2545));
                            *length_a_413 = implicit_cast<TNode<Smi>>(t2545);
                            // ../third_party/v8/builtins/array-sort.tq:1463:13
                            {
                              Label label__True_669_impl(this);
                              Label* label__True_669 = &label__True_669_impl;
                              USE(label__True_669);
                              Label label__False_670_impl(this, {});
                              Label* label__False_670 = &label__False_670_impl;
                              USE(label__False_670);
                              int31_t t2546 = 0;
                              TNode<Smi> t2547 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2546)));
                              TNode<BoolT> t2548 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_a_413).value()), implicit_cast<TNode<Smi>>(t2547)));
                              USE(implicit_cast<TNode<BoolT>>(t2548));
                              Branch(implicit_cast<TNode<BoolT>>(t2548), label__True_669, label__False_670);
                              if (label__True_669->is_used())
                              {
                                BIND(label__True_669);
                                // ../third_party/v8/builtins/array-sort.tq:1463:32
                                Goto(label_Succeed_643);
                              }
                              BIND(label__False_670);
                            }
                          }
                          Goto(label__False_668);
                        }
                        BIND(label__False_668);
                      }
                      // ../third_party/v8/builtins/array-sort.tq:1465:11
                      TNode<Smi> t2549 = implicit_cast<TNode<Smi>>((*dest_416).value());
                      USE(t2549);
                      TNode<Smi> t2550 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t2551 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>(t2550)));
                      *dest_416 = implicit_cast<TNode<Smi>>(t2551);
                      TNode<Smi> t2552 = implicit_cast<TNode<Smi>>((*cursor_temp_417).value());
                      USE(t2552);
                      TNode<Smi> t2553 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t2554 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*cursor_temp_417).value()), implicit_cast<TNode<Smi>>(t2553)));
                      *cursor_temp_417 = implicit_cast<TNode<Smi>>(t2554);
                      TNode<Object> t2555 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*temp_array_872)), implicit_cast<TNode<Smi>>(t2552)));
                      CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Store_871)), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>(t2549), implicit_cast<TNode<Object>>(t2555), label_Bailout_642);
                      // ../third_party/v8/builtins/array-sort.tq:1469:11
                      {
                        Label label__True_671_impl(this);
                        Label* label__True_671 = &label__True_671_impl;
                        USE(label__True_671);
                        Label label__False_672_impl(this, {length_b_414});
                        Label* label__False_672 = &label__False_672_impl;
                        USE(label__False_672);
                        TNode<Smi> t2556 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                        TNode<Smi> t2557 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2556)));
                        *length_b_414 = implicit_cast<TNode<Smi>>(t2557);
                        int31_t t2558 = 1;
                        TNode<Smi> t2559 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2558)));
                        TNode<BoolT> t2560 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>(t2557), implicit_cast<TNode<Smi>>(t2559)));
                        USE(implicit_cast<TNode<BoolT>>(t2560));
                        Branch(implicit_cast<TNode<BoolT>>(t2560), label__True_671, label__False_672);
                        if (label__True_671->is_used())
                        {
                          BIND(label__True_671);
                          // ../third_party/v8/builtins/array-sort.tq:1469:32
                          Goto(label_CopyA_644);
                        }
                        BIND(label__False_672);
                      }
                      // ../third_party/v8/builtins/array-sort.tq:1471:11
                      TNode<Object> t2561 = UncheckedCast<Object>(CallLoad(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_870)), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>((*cursor_a_418).value()), label_Bailout_642));
                      USE(implicit_cast<TNode<Object>>(t2561));
                      TVARIABLE(Object, key_426_impl);
                      auto key_426 = &key_426_impl;
                      USE(key_426);
                      *key_426 = implicit_cast<TNode<Object>>(t2561);
                      // ../third_party/v8/builtins/array-sort.tq:1474:11
                      int31_t t2562 = 0;
                      int31_t t2563 = 1;
                      TNode<Smi> t2564 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2563)));
                      TNode<Smi> t2565 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2564)));
                      USE(implicit_cast<TNode<Smi>>(t2565));
                      TNode<Smi> t2566 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2562)));
                      TNode<Smi> t2567 = UncheckedCast<Smi>(CallGallopLeft(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoad19ATTempArrayElements).code())), implicit_cast<TNode<Object>>((*key_426).value()), implicit_cast<TNode<Smi>>(t2566), implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2565), implicit_cast<TNode<Oddball>>(True()), label_Bailout_642));
                      USE(implicit_cast<TNode<Smi>>(t2567));
                      *k_425 = implicit_cast<TNode<Smi>>(t2567);
                      // ../third_party/v8/builtins/array-sort.tq:1477:11
                      TNode<HeapObject> t2568 = UncheckedCast<HeapObject>(ReloadElements(implicit_cast<TNode<FixedArray>>(p_sortState)));
                      USE(implicit_cast<TNode<HeapObject>>(t2568));
                      *elements_415 = implicit_cast<TNode<HeapObject>>(t2568);
                      // ../third_party/v8/builtins/array-sort.tq:1478:11
                      // ../third_party/v8/builtins/array-sort.tq:1479:11
                      TNode<Smi> t2569 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>((*k_425).value())));
                      USE(implicit_cast<TNode<Smi>>(t2569));
                      *nof_wins_b_421 = implicit_cast<TNode<Smi>>(t2569);
                      // ../third_party/v8/builtins/array-sort.tq:1481:11
                      {
                        Label label__True_673_impl(this);
                        Label* label__True_673 = &label__True_673_impl;
                        USE(label__True_673);
                        Label label__False_674_impl(this, {cursor_temp_417, dest_416, length_b_414});
                        Label* label__False_674 = &label__False_674_impl;
                        USE(label__False_674);
                        int31_t t2570 = 0;
                        TNode<Smi> t2571 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2570)));
                        TNode<BoolT> t2572 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*nof_wins_b_421).value()), implicit_cast<TNode<Smi>>(t2571)));
                        USE(implicit_cast<TNode<BoolT>>(t2572));
                        Branch(implicit_cast<TNode<BoolT>>(t2572), label__True_673, label__False_674);
                        if (label__True_673->is_used())
                        {
                          BIND(label__True_673);
                          // ../third_party/v8/builtins/array-sort.tq:1481:31
                          {
                            // ../third_party/v8/builtins/array-sort.tq:1482:13
                            TNode<Smi> t2573 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>((*nof_wins_b_421).value())));
                            USE(implicit_cast<TNode<Smi>>(t2573));
                            *dest_416 = implicit_cast<TNode<Smi>>(t2573);
                            // ../third_party/v8/builtins/array-sort.tq:1483:13
                            TNode<Smi> t2574 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*cursor_temp_417).value()), implicit_cast<TNode<Smi>>((*nof_wins_b_421).value())));
                            USE(implicit_cast<TNode<Smi>>(t2574));
                            *cursor_temp_417 = implicit_cast<TNode<Smi>>(t2574);
                            // ../third_party/v8/builtins/array-sort.tq:1484:13
                            int31_t t2575 = 1;
                            TNode<Smi> t2576 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2575)));
                            TNode<Smi> t2577 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>(t2576)));
                            USE(implicit_cast<TNode<Smi>>(t2577));
                            int31_t t2578 = 1;
                            TNode<Smi> t2579 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2578)));
                            TNode<Smi> t2580 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*cursor_temp_417).value()), implicit_cast<TNode<Smi>>(t2579)));
                            USE(implicit_cast<TNode<Smi>>(t2580));
                            CallCopyFromTempArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>(t2577), implicit_cast<TNode<FixedArray>>((*temp_array_872)), implicit_cast<TNode<Smi>>(t2580), implicit_cast<TNode<Smi>>((*nof_wins_b_421).value()), label_Bailout_642);
                            // ../third_party/v8/builtins/array-sort.tq:1488:13
                            TNode<Smi> t2581 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>((*nof_wins_b_421).value())));
                            USE(implicit_cast<TNode<Smi>>(t2581));
                            *length_b_414 = implicit_cast<TNode<Smi>>(t2581);
                            // ../third_party/v8/builtins/array-sort.tq:1489:13
                            {
                              Label label__True_675_impl(this);
                              Label* label__True_675 = &label__True_675_impl;
                              USE(label__True_675);
                              Label label__False_676_impl(this, {});
                              Label* label__False_676 = &label__False_676_impl;
                              USE(label__False_676);
                              int31_t t2582 = 1;
                              TNode<Smi> t2583 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2582)));
                              TNode<BoolT> t2584 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2583)));
                              USE(implicit_cast<TNode<BoolT>>(t2584));
                              Branch(implicit_cast<TNode<BoolT>>(t2584), label__True_675, label__False_676);
                              if (label__True_675->is_used())
                              {
                                BIND(label__True_675);
                                // ../third_party/v8/builtins/array-sort.tq:1489:32
                                Goto(label_CopyA_644);
                              }
                              BIND(label__False_676);
                            }
                            // ../third_party/v8/builtins/array-sort.tq:1493:13
                            {
                              Label label__True_677_impl(this);
                              Label* label__True_677 = &label__True_677_impl;
                              USE(label__True_677);
                              Label label__False_678_impl(this, {});
                              Label* label__False_678 = &label__False_678_impl;
                              USE(label__False_678);
                              int31_t t2585 = 0;
                              TNode<Smi> t2586 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2585)));
                              TNode<BoolT> t2587 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2586)));
                              USE(implicit_cast<TNode<BoolT>>(t2587));
                              Branch(implicit_cast<TNode<BoolT>>(t2587), label__True_677, label__False_678);
                              if (label__True_677->is_used())
                              {
                                BIND(label__True_677);
                                // ../third_party/v8/builtins/array-sort.tq:1493:32
                                Goto(label_Succeed_643);
                              }
                              BIND(label__False_678);
                            }
                          }
                          Goto(label__False_674);
                        }
                        BIND(label__False_674);
                      }
                      // ../third_party/v8/builtins/array-sort.tq:1495:11
                      TNode<Smi> t2588 = implicit_cast<TNode<Smi>>((*cursor_a_418).value());
                      USE(t2588);
                      TNode<Smi> t2589 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t2590 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*cursor_a_418).value()), implicit_cast<TNode<Smi>>(t2589)));
                      *cursor_a_418 = implicit_cast<TNode<Smi>>(t2590);
                      TNode<Smi> t2591 = implicit_cast<TNode<Smi>>((*dest_416).value());
                      USE(t2591);
                      TNode<Smi> t2592 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t2593 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>(t2592)));
                      *dest_416 = implicit_cast<TNode<Smi>>(t2593);
                      CopyElement(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*LoadF_870)), implicit_cast<TNode<Code>>((*Store_871)), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>(t2588), implicit_cast<TNode<Smi>>(t2591), label_Bailout_642);
                      // ../third_party/v8/builtins/array-sort.tq:1498:11
                      {
                        Label label__True_679_impl(this);
                        Label* label__True_679 = &label__True_679_impl;
                        USE(label__True_679);
                        Label label__False_680_impl(this, {length_a_413});
                        Label* label__False_680 = &label__False_680_impl;
                        USE(label__False_680);
                        TNode<Smi> t2594 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                        TNode<Smi> t2595 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_a_413).value()), implicit_cast<TNode<Smi>>(t2594)));
                        *length_a_413 = implicit_cast<TNode<Smi>>(t2595);
                        int31_t t2596 = 0;
                        TNode<Smi> t2597 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2596)));
                        TNode<BoolT> t2598 = UncheckedCast<BoolT>(SmiEqual(implicit_cast<TNode<Smi>>(t2595), implicit_cast<TNode<Smi>>(t2597)));
                        USE(implicit_cast<TNode<BoolT>>(t2598));
                        Branch(implicit_cast<TNode<BoolT>>(t2598), label__True_679, label__False_680);
                        if (label__True_679->is_used())
                        {
                          BIND(label__True_679);
                          // ../third_party/v8/builtins/array-sort.tq:1498:32
                          Goto(label_Succeed_643);
                        }
                        BIND(label__False_680);
                      }
                    }
                    Goto(label_header_878_1141);
                  }
                  BIND(label__False_664);
                }
                // ../third_party/v8/builtins/array-sort.tq:1500:9
                TNode<Smi> t2599 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                TNode<Smi> t2600 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*min_gallop_419).value()), implicit_cast<TNode<Smi>>(t2599)));
                *min_gallop_419 = implicit_cast<TNode<Smi>>(t2600);
                // ../third_party/v8/builtins/array-sort.tq:1501:9
                StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kMinGallopIdx()), implicit_cast<TNode<Object>>((*min_gallop_419).value()));
              }
              Goto(label_header_875_1138);
            }
            BIND(label__False_650);
          }
        }
        Goto(label_try_done_873_1136);
      }
      if (label_Succeed_643->is_used())
      {
        BIND(label_Succeed_643);
        // ../third_party/v8/builtins/array-sort.tq:1504:19
        {
          // ../third_party/v8/builtins/array-sort.tq:1505:7
          {
            Label label__True_681_impl(this);
            Label* label__True_681 = &label__True_681_impl;
            USE(label__True_681);
            Label label__False_682_impl(this, {});
            Label* label__False_682 = &label__False_682_impl;
            USE(label__False_682);
            int31_t t2601 = 0;
            TNode<Smi> t2602 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2601)));
            TNode<BoolT> t2603 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2602)));
            USE(implicit_cast<TNode<BoolT>>(t2603));
            Branch(implicit_cast<TNode<BoolT>>(t2603), label__True_681, label__False_682);
            if (label__True_681->is_used())
            {
              BIND(label__True_681);
              // ../third_party/v8/builtins/array-sort.tq:1505:25
              {
                // ../third_party/v8/builtins/array-sort.tq:1506:9
                // ../third_party/v8/builtins/array-sort.tq:1507:9
                int31_t t2604 = 1;
                TNode<Smi> t2605 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2604)));
                TNode<Smi> t2606 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*length_b_414).value()), implicit_cast<TNode<Smi>>(t2605)));
                USE(implicit_cast<TNode<Smi>>(t2606));
                TNode<Smi> t2607 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>(t2606)));
                USE(implicit_cast<TNode<Smi>>(t2607));
                int31_t t2608 = 0;
                TNode<Smi> t2609 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2608)));
                CallCopyFromTempArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>(t2607), implicit_cast<TNode<FixedArray>>((*temp_array_872)), implicit_cast<TNode<Smi>>(t2609), implicit_cast<TNode<Smi>>((*length_b_414).value()), label_Bailout_642);
              }
              Goto(label__False_682);
            }
            BIND(label__False_682);
          }
        }
        Goto(label_try_done_873_1136);
      }
      if (label_CopyA_644->is_used())
      {
        BIND(label_CopyA_644);
        // ../third_party/v8/builtins/array-sort.tq:1512:17
        {
          // ../third_party/v8/builtins/array-sort.tq:1513:7
          // ../third_party/v8/builtins/array-sort.tq:1516:7
          TNode<Smi> t2610 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>((*length_a_413).value())));
          USE(implicit_cast<TNode<Smi>>(t2610));
          *dest_416 = implicit_cast<TNode<Smi>>(t2610);
          // ../third_party/v8/builtins/array-sort.tq:1517:7
          TNode<Smi> t2611 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*cursor_a_418).value()), implicit_cast<TNode<Smi>>((*length_a_413).value())));
          USE(implicit_cast<TNode<Smi>>(t2611));
          *cursor_a_418 = implicit_cast<TNode<Smi>>(t2611);
          // ../third_party/v8/builtins/array-sort.tq:1518:7
          int31_t t2612 = 1;
          TNode<Smi> t2613 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2612)));
          TNode<Smi> t2614 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*cursor_a_418).value()), implicit_cast<TNode<Smi>>(t2613)));
          USE(implicit_cast<TNode<Smi>>(t2614));
          int31_t t2615 = 1;
          TNode<Smi> t2616 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2615)));
          TNode<Smi> t2617 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Smi>>(t2616)));
          USE(implicit_cast<TNode<Smi>>(t2617));
          CallCopyWithinSortArray(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>(t2614), implicit_cast<TNode<Smi>>(t2617), implicit_cast<TNode<Smi>>((*length_a_413).value()), label_Bailout_642);
          // ../third_party/v8/builtins/array-sort.tq:1521:7
          TNode<Object> t2618 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>((*temp_array_872)), implicit_cast<TNode<Smi>>((*cursor_temp_417).value())));
          CallStore(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Code>>((*Store_871)), implicit_cast<TNode<HeapObject>>((*elements_415).value()), implicit_cast<TNode<Smi>>((*dest_416).value()), implicit_cast<TNode<Object>>(t2618), label_Bailout_642);
        }
        Goto(label_try_done_873_1136);
      }
      BIND(label_try_done_873_1136);
    }
  }
}

compiler::TNode<Smi> ArrayBuiltinsFromDSLAssembler::ComputeMinRunLength(TNode<Smi> p_nArg) {
  TVARIABLE(Smi, _return_427_impl);
  auto _return_427 = &_return_427_impl;
  USE(_return_427);
  Label label_macro_end_1142_impl(this, {_return_427});
  Label* label_macro_end_1142 = &label_macro_end_1142_impl;
  USE(label_macro_end_1142);
  // ../third_party/v8/builtins/array-sort.tq:1536:45
  {
    // ../third_party/v8/builtins/array-sort.tq:1537:5
    TVARIABLE(Smi, n_428_impl);
    auto n_428 = &n_428_impl;
    USE(n_428);
    *n_428 = implicit_cast<TNode<Smi>>(p_nArg);
    // ../third_party/v8/builtins/array-sort.tq:1538:5
    int31_t t2619 = 0;
    TVARIABLE(Smi, r_429_impl);
    auto r_429 = &r_429_impl;
    USE(r_429);
    TNode<Smi> t2620 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2619)));
    *r_429 = implicit_cast<TNode<Smi>>(t2620);
    // ../third_party/v8/builtins/array-sort.tq:1540:5
    // ../third_party/v8/builtins/array-sort.tq:1541:5
    {
      Label label__True_683_impl(this);
      Label* label__True_683 = &label__True_683_impl;
      USE(label__True_683);
      Label label__False_684_impl(this);
      Label* label__False_684 = &label__False_684_impl;
      USE(label__False_684);
      Label label_header_879_1143_impl(this, {n_428, r_429});
      Label* label_header_879_1143 = &label_header_879_1143_impl;
      USE(label_header_879_1143);
      Goto(label_header_879_1143);
      BIND(label_header_879_1143);
      int31_t t2621 = 64;
      TNode<Smi> t2622 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2621)));
      TNode<BoolT> t2623 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(implicit_cast<TNode<Smi>>((*n_428).value()), implicit_cast<TNode<Smi>>(t2622)));
      USE(implicit_cast<TNode<BoolT>>(t2623));
      Branch(implicit_cast<TNode<BoolT>>(t2623), label__True_683, label__False_684);
      if (label__True_683->is_used())
      {
        BIND(label__True_683);
        // ../third_party/v8/builtins/array-sort.tq:1541:21
        {
          // ../third_party/v8/builtins/array-sort.tq:1542:7
          int31_t t2624 = 1;
          TNode<Smi> t2625 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2624)));
          TNode<Smi> t2626 = UncheckedCast<Smi>(SmiAnd(implicit_cast<TNode<Smi>>((*n_428).value()), implicit_cast<TNode<Smi>>(t2625)));
          USE(implicit_cast<TNode<Smi>>(t2626));
          TNode<Smi> t2627 = UncheckedCast<Smi>(SmiOr(implicit_cast<TNode<Smi>>((*r_429).value()), implicit_cast<TNode<Smi>>(t2626)));
          USE(implicit_cast<TNode<Smi>>(t2627));
          *r_429 = implicit_cast<TNode<Smi>>(t2627);
          // ../third_party/v8/builtins/array-sort.tq:1543:7
          int31_t t2628 = 1;
          TNode<Smi> t2629 = UncheckedCast<Smi>(SmiShr(implicit_cast<TNode<Smi>>((*n_428).value()), implicit_cast<int31_t>(t2628)));
          USE(implicit_cast<TNode<Smi>>(t2629));
          *n_428 = implicit_cast<TNode<Smi>>(t2629);
        }
        Goto(label_header_879_1143);
      }
      BIND(label__False_684);
    }
    // ../third_party/v8/builtins/array-sort.tq:1546:5
    TNode<Smi> t2630 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*n_428).value()), implicit_cast<TNode<Smi>>((*r_429).value())));
    USE(implicit_cast<TNode<Smi>>(t2630));
    TNode<Smi> min_run_length_880_impl;
    auto min_run_length_880 = &min_run_length_880_impl;
    USE(min_run_length_880);
    *min_run_length_880 = implicit_cast<TNode<Smi>>(t2630);
    // ../third_party/v8/builtins/array-sort.tq:1547:5
    // ../third_party/v8/builtins/array-sort.tq:1548:5
    *_return_427 = implicit_cast<TNode<Smi>>((*min_run_length_880));
    Goto(label_macro_end_1142);
  }
  BIND(label_macro_end_1142);
  return implicit_cast<TNode<Smi>>((*_return_427).value());
}

compiler::TNode<BoolT> ArrayBuiltinsFromDSLAssembler::RunInvariantEstablished(TNode<FixedArray> p_pendingRuns, TNode<Smi> p_n) {
  TVARIABLE(BoolT, _return_430_impl);
  auto _return_430 = &_return_430_impl;
  USE(_return_430);
  Label label_macro_end_1144_impl(this, {_return_430});
  Label* label_macro_end_1144 = &label_macro_end_1144_impl;
  USE(label_macro_end_1144);
  // ../third_party/v8/builtins/array-sort.tq:1552:72
  {
    // ../third_party/v8/builtins/array-sort.tq:1553:5
    {
      Label label__True_685_impl(this);
      Label* label__True_685 = &label__True_685_impl;
      USE(label__True_685);
      Label label__False_686_impl(this, {});
      Label* label__False_686 = &label__False_686_impl;
      USE(label__False_686);
      int31_t t2631 = 2;
      TNode<Smi> t2632 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2631)));
      TNode<BoolT> t2633 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>(p_n), implicit_cast<TNode<Smi>>(t2632)));
      USE(implicit_cast<TNode<BoolT>>(t2633));
      Branch(implicit_cast<TNode<BoolT>>(t2633), label__True_685, label__False_686);
      if (label__True_685->is_used())
      {
        BIND(label__True_685);
        // ../third_party/v8/builtins/array-sort.tq:1553:16
        TNode<BoolT> t2634 = UncheckedCast<BoolT>(from_constexpr6ATbool(implicit_cast<bool>(true)));
        *_return_430 = implicit_cast<TNode<BoolT>>(t2634);
        Goto(label_macro_end_1144);
      }
      BIND(label__False_686);
    }
    // ../third_party/v8/builtins/array-sort.tq:1555:5
    TNode<Smi> t2635 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>(p_pendingRuns), implicit_cast<TNode<Smi>>(p_n)));
    USE(implicit_cast<TNode<Smi>>(t2635));
    TNode<Smi> run_length_n_881_impl;
    auto run_length_n_881 = &run_length_n_881_impl;
    USE(run_length_n_881);
    *run_length_n_881 = implicit_cast<TNode<Smi>>(t2635);
    // ../third_party/v8/builtins/array-sort.tq:1556:5
    int31_t t2636 = 1;
    TNode<Smi> t2637 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2636)));
    TNode<Smi> t2638 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_n), implicit_cast<TNode<Smi>>(t2637)));
    USE(implicit_cast<TNode<Smi>>(t2638));
    TNode<Smi> t2639 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>(p_pendingRuns), implicit_cast<TNode<Smi>>(t2638)));
    USE(implicit_cast<TNode<Smi>>(t2639));
    TNode<Smi> run_length_nm_882_impl;
    auto run_length_nm_882 = &run_length_nm_882_impl;
    USE(run_length_nm_882);
    *run_length_nm_882 = implicit_cast<TNode<Smi>>(t2639);
    // ../third_party/v8/builtins/array-sort.tq:1557:5
    int31_t t2640 = 2;
    TNode<Smi> t2641 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2640)));
    TNode<Smi> t2642 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_n), implicit_cast<TNode<Smi>>(t2641)));
    USE(implicit_cast<TNode<Smi>>(t2642));
    TNode<Smi> t2643 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>(p_pendingRuns), implicit_cast<TNode<Smi>>(t2642)));
    USE(implicit_cast<TNode<Smi>>(t2643));
    TNode<Smi> run_length_nmm_883_impl;
    auto run_length_nmm_883 = &run_length_nmm_883_impl;
    USE(run_length_nmm_883);
    *run_length_nmm_883 = implicit_cast<TNode<Smi>>(t2643);
    // ../third_party/v8/builtins/array-sort.tq:1559:5
    TNode<Smi> t2644 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*run_length_nm_882)), implicit_cast<TNode<Smi>>((*run_length_n_881))));
    USE(implicit_cast<TNode<Smi>>(t2644));
    TNode<BoolT> t2645 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*run_length_nmm_883)), implicit_cast<TNode<Smi>>(t2644)));
    USE(implicit_cast<TNode<BoolT>>(t2645));
    *_return_430 = implicit_cast<TNode<BoolT>>(t2645);
    Goto(label_macro_end_1144);
  }
  BIND(label_macro_end_1144);
  return implicit_cast<TNode<BoolT>>((*_return_430).value());
}

void ArrayBuiltinsFromDSLAssembler::MergeCollapse(TNode<Context> p_context, TNode<FixedArray> p_sortState, Label* label_Bailout_687) {
  Label label_macro_end_1145_impl(this, {});
  Label* label_macro_end_1145 = &label_macro_end_1145_impl;
  USE(label_macro_end_1145);
  // ../third_party/v8/builtins/array-sort.tq:1572:18
  {
    // ../third_party/v8/builtins/array-sort.tq:1573:5
    TNode<Object> t2646 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kPendingRunsIdx())));
    TNode<FixedArray> t2647 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(t2646)));
    USE(implicit_cast<TNode<FixedArray>>(t2647));
    TNode<FixedArray> pending_runs_884_impl;
    auto pending_runs_884 = &pending_runs_884_impl;
    USE(pending_runs_884);
    *pending_runs_884 = implicit_cast<TNode<FixedArray>>(t2647);
    // ../third_party/v8/builtins/array-sort.tq:1577:5
    {
      Label label__True_688_impl(this);
      Label* label__True_688 = &label__True_688_impl;
      USE(label__True_688);
      Label label__False_689_impl(this);
      Label* label__False_689 = &label__False_689_impl;
      USE(label__False_689);
      Label label_header_885_1146_impl(this, {});
      Label* label_header_885_1146 = &label_header_885_1146_impl;
      USE(label_header_885_1146);
      Goto(label_header_885_1146);
      BIND(label_header_885_1146);
      TNode<Smi> t2648 = UncheckedCast<Smi>(GetPendingRunsSize(implicit_cast<TNode<FixedArray>>(p_sortState)));
      USE(implicit_cast<TNode<Smi>>(t2648));
      int31_t t2649 = 1;
      TNode<Smi> t2650 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2649)));
      TNode<BoolT> t2651 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>(t2648), implicit_cast<TNode<Smi>>(t2650)));
      USE(implicit_cast<TNode<BoolT>>(t2651));
      Branch(implicit_cast<TNode<BoolT>>(t2651), label__True_688, label__False_689);
      if (label__True_688->is_used())
      {
        BIND(label__True_688);
        // ../third_party/v8/builtins/array-sort.tq:1577:47
        {
          // ../third_party/v8/builtins/array-sort.tq:1578:7
          TNode<Smi> t2652 = UncheckedCast<Smi>(GetPendingRunsSize(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t2652));
          int31_t t2653 = 2;
          TNode<Smi> t2654 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2653)));
          TNode<Smi> t2655 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t2652), implicit_cast<TNode<Smi>>(t2654)));
          USE(implicit_cast<TNode<Smi>>(t2655));
          TVARIABLE(Smi, n_431_impl);
          auto n_431 = &n_431_impl;
          USE(n_431);
          *n_431 = implicit_cast<TNode<Smi>>(t2655);
          // ../third_party/v8/builtins/array-sort.tq:1580:7
          {
            Label label__True_690_impl(this);
            Label* label__True_690 = &label__True_690_impl;
            USE(label__True_690);
            Label label__False_691_impl(this);
            Label* label__False_691 = &label__False_691_impl;
            USE(label__False_691);
            Label label_if_done_label_886_1147_impl(this, {n_431});
            Label* label_if_done_label_886_1147 = &label_if_done_label_886_1147_impl;
            USE(label_if_done_label_886_1147);
            Label label__False_692_impl(this);
            Label* label__False_692 = &label__False_692_impl;
            USE(label__False_692);
            int31_t t2656 = 1;
            TNode<Smi> t2657 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2656)));
            TNode<Smi> t2658 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*n_431).value()), implicit_cast<TNode<Smi>>(t2657)));
            USE(implicit_cast<TNode<Smi>>(t2658));
            TNode<BoolT> t2659 = UncheckedCast<BoolT>(RunInvariantEstablished(implicit_cast<TNode<FixedArray>>((*pending_runs_884)), implicit_cast<TNode<Smi>>(t2658)));
            USE(implicit_cast<TNode<BoolT>>(t2659));
            TNode<BoolT> t2660 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t2659)));
            USE(implicit_cast<TNode<BoolT>>(t2660));
            GotoIf(implicit_cast<TNode<BoolT>>(t2660), label__True_690);
            TNode<BoolT> t2661 = UncheckedCast<BoolT>(RunInvariantEstablished(implicit_cast<TNode<FixedArray>>((*pending_runs_884)), implicit_cast<TNode<Smi>>((*n_431).value())));
            USE(implicit_cast<TNode<BoolT>>(t2661));
            TNode<BoolT> t2662 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t2661)));
            USE(implicit_cast<TNode<BoolT>>(t2662));
            Branch(implicit_cast<TNode<BoolT>>(t2662), label__True_690, label__False_691);
            if (label__True_690->is_used())
            {
              BIND(label__True_690);
              // ../third_party/v8/builtins/array-sort.tq:1581:54
              {
                // ../third_party/v8/builtins/array-sort.tq:1582:9
                {
                  Label label__True_693_impl(this);
                  Label* label__True_693 = &label__True_693_impl;
                  USE(label__True_693);
                  Label label__False_694_impl(this, {n_431});
                  Label* label__False_694 = &label__False_694_impl;
                  USE(label__False_694);
                  int31_t t2663 = 1;
                  TNode<Smi> t2664 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2663)));
                  TNode<Smi> t2665 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*n_431).value()), implicit_cast<TNode<Smi>>(t2664)));
                  USE(implicit_cast<TNode<Smi>>(t2665));
                  TNode<Smi> t2666 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_884)), implicit_cast<TNode<Smi>>(t2665)));
                  USE(implicit_cast<TNode<Smi>>(t2666));
                  int31_t t2667 = 1;
                  TNode<Smi> t2668 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2667)));
                  TNode<Smi> t2669 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*n_431).value()), implicit_cast<TNode<Smi>>(t2668)));
                  USE(implicit_cast<TNode<Smi>>(t2669));
                  TNode<Smi> t2670 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_884)), implicit_cast<TNode<Smi>>(t2669)));
                  USE(implicit_cast<TNode<Smi>>(t2670));
                  TNode<BoolT> t2671 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>(t2666), implicit_cast<TNode<Smi>>(t2670)));
                  USE(implicit_cast<TNode<BoolT>>(t2671));
                  Branch(implicit_cast<TNode<BoolT>>(t2671), label__True_693, label__False_694);
                  if (label__True_693->is_used())
                  {
                    BIND(label__True_693);
                    // ../third_party/v8/builtins/array-sort.tq:1583:55
                    {
                      // ../third_party/v8/builtins/array-sort.tq:1584:11
                      TNode<Smi> t2672 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                      TNode<Smi> t2673 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*n_431).value()), implicit_cast<TNode<Smi>>(t2672)));
                      *n_431 = implicit_cast<TNode<Smi>>(t2673);
                    }
                    Goto(label__False_694);
                  }
                  BIND(label__False_694);
                }
                // ../third_party/v8/builtins/array-sort.tq:1587:9
                CallMergeAt(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>((*n_431).value()), label_Bailout_687);
              }
              Goto(label_if_done_label_886_1147);
            }
            if (label__False_691->is_used())
            {
              BIND(label__False_691);
              // ../third_party/v8/builtins/array-sort.tq:1588:14
              {
                Label label__True_695_impl(this);
                Label* label__True_695 = &label__True_695_impl;
                USE(label__True_695);
                Label label__False_696_impl(this);
                Label* label__False_696 = &label__False_696_impl;
                USE(label__False_696);
                Label label_if_done_label_887_1148_impl(this, {});
                Label* label_if_done_label_887_1148 = &label_if_done_label_887_1148_impl;
                USE(label_if_done_label_887_1148);
                TNode<Smi> t2674 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_884)), implicit_cast<TNode<Smi>>((*n_431).value())));
                USE(implicit_cast<TNode<Smi>>(t2674));
                int31_t t2675 = 1;
                TNode<Smi> t2676 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2675)));
                TNode<Smi> t2677 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*n_431).value()), implicit_cast<TNode<Smi>>(t2676)));
                USE(implicit_cast<TNode<Smi>>(t2677));
                TNode<Smi> t2678 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_884)), implicit_cast<TNode<Smi>>(t2677)));
                USE(implicit_cast<TNode<Smi>>(t2678));
                TNode<BoolT> t2679 = UncheckedCast<BoolT>(SmiLessThanOrEqual(implicit_cast<TNode<Smi>>(t2674), implicit_cast<TNode<Smi>>(t2678)));
                USE(implicit_cast<TNode<BoolT>>(t2679));
                Branch(implicit_cast<TNode<BoolT>>(t2679), label__True_695, label__False_696);
                if (label__True_695->is_used())
                {
                  BIND(label__True_695);
                  // ../third_party/v8/builtins/array-sort.tq:1590:53
                  {
                    // ../third_party/v8/builtins/array-sort.tq:1591:9
                    CallMergeAt(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>((*n_431).value()), label_Bailout_687);
                  }
                  Goto(label_if_done_label_887_1148);
                }
                if (label__False_696->is_used())
                {
                  BIND(label__False_696);
                  // ../third_party/v8/builtins/array-sort.tq:1592:14
                  {
                    // ../third_party/v8/builtins/array-sort.tq:1593:9
                    Goto(label__False_689);
                  }
                }
                BIND(label_if_done_label_887_1148);
              }
              Goto(label_if_done_label_886_1147);
            }
            BIND(label_if_done_label_886_1147);
          }
        }
        Goto(label_header_885_1146);
      }
      BIND(label__False_689);
    }
  }
}

void ArrayBuiltinsFromDSLAssembler::MergeForceCollapse(TNode<Context> p_context, TNode<FixedArray> p_sortState, Label* label_Bailout_697) {
  Label label_macro_end_1149_impl(this, {});
  Label* label_macro_end_1149 = &label_macro_end_1149_impl;
  USE(label_macro_end_1149);
  // ../third_party/v8/builtins/array-sort.tq:1601:18
  {
    // ../third_party/v8/builtins/array-sort.tq:1602:5
    TNode<Object> t2680 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kPendingRunsIdx())));
    TNode<FixedArray> t2681 = UncheckedCast<FixedArray>(unsafe_cast12ATFixedArray(implicit_cast<TNode<Object>>(t2680)));
    USE(implicit_cast<TNode<FixedArray>>(t2681));
    TVARIABLE(FixedArray, pending_runs_432_impl);
    auto pending_runs_432 = &pending_runs_432_impl;
    USE(pending_runs_432);
    *pending_runs_432 = implicit_cast<TNode<FixedArray>>(t2681);
    // ../third_party/v8/builtins/array-sort.tq:1606:5
    {
      Label label__True_698_impl(this);
      Label* label__True_698 = &label__True_698_impl;
      USE(label__True_698);
      Label label__False_699_impl(this);
      Label* label__False_699 = &label__False_699_impl;
      USE(label__False_699);
      Label label_header_888_1150_impl(this, {});
      Label* label_header_888_1150 = &label_header_888_1150_impl;
      USE(label_header_888_1150);
      Goto(label_header_888_1150);
      BIND(label_header_888_1150);
      TNode<Smi> t2682 = UncheckedCast<Smi>(GetPendingRunsSize(implicit_cast<TNode<FixedArray>>(p_sortState)));
      USE(implicit_cast<TNode<Smi>>(t2682));
      int31_t t2683 = 1;
      TNode<Smi> t2684 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2683)));
      TNode<BoolT> t2685 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>(t2682), implicit_cast<TNode<Smi>>(t2684)));
      USE(implicit_cast<TNode<BoolT>>(t2685));
      Branch(implicit_cast<TNode<BoolT>>(t2685), label__True_698, label__False_699);
      if (label__True_698->is_used())
      {
        BIND(label__True_698);
        // ../third_party/v8/builtins/array-sort.tq:1606:47
        {
          // ../third_party/v8/builtins/array-sort.tq:1607:7
          TNode<Smi> t2686 = UncheckedCast<Smi>(GetPendingRunsSize(implicit_cast<TNode<FixedArray>>(p_sortState)));
          USE(implicit_cast<TNode<Smi>>(t2686));
          int31_t t2687 = 2;
          TNode<Smi> t2688 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2687)));
          TNode<Smi> t2689 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(t2686), implicit_cast<TNode<Smi>>(t2688)));
          USE(implicit_cast<TNode<Smi>>(t2689));
          TVARIABLE(Smi, n_433_impl);
          auto n_433 = &n_433_impl;
          USE(n_433);
          *n_433 = implicit_cast<TNode<Smi>>(t2689);
          // ../third_party/v8/builtins/array-sort.tq:1609:7
          {
            Label label__True_700_impl(this);
            Label* label__True_700 = &label__True_700_impl;
            USE(label__True_700);
            Label label__False_701_impl(this, {n_433});
            Label* label__False_701 = &label__False_701_impl;
            USE(label__False_701);
            Label label__True_702_impl(this);
            Label* label__True_702 = &label__True_702_impl;
            USE(label__True_702);
            int31_t t2690 = 0;
            TNode<Smi> t2691 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2690)));
            TNode<BoolT> t2692 = UncheckedCast<BoolT>(SmiGreaterThan(implicit_cast<TNode<Smi>>((*n_433).value()), implicit_cast<TNode<Smi>>(t2691)));
            USE(implicit_cast<TNode<BoolT>>(t2692));
            GotoIfNot(implicit_cast<TNode<BoolT>>(t2692), label__False_701);
            int31_t t2693 = 1;
            TNode<Smi> t2694 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2693)));
            TNode<Smi> t2695 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*n_433).value()), implicit_cast<TNode<Smi>>(t2694)));
            USE(implicit_cast<TNode<Smi>>(t2695));
            TNode<Smi> t2696 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_432).value()), implicit_cast<TNode<Smi>>(t2695)));
            USE(implicit_cast<TNode<Smi>>(t2696));
            int31_t t2697 = 1;
            TNode<Smi> t2698 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2697)));
            TNode<Smi> t2699 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*n_433).value()), implicit_cast<TNode<Smi>>(t2698)));
            USE(implicit_cast<TNode<Smi>>(t2699));
            TNode<Smi> t2700 = UncheckedCast<Smi>(GetPendingRunLength(implicit_cast<TNode<FixedArray>>((*pending_runs_432).value()), implicit_cast<TNode<Smi>>(t2699)));
            USE(implicit_cast<TNode<Smi>>(t2700));
            TNode<BoolT> t2701 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>(t2696), implicit_cast<TNode<Smi>>(t2700)));
            USE(implicit_cast<TNode<BoolT>>(t2701));
            Branch(implicit_cast<TNode<BoolT>>(t2701), label__True_700, label__False_701);
            if (label__True_700->is_used())
            {
              BIND(label__True_700);
              // ../third_party/v8/builtins/array-sort.tq:1611:57
              {
                // ../third_party/v8/builtins/array-sort.tq:1612:9
                TNode<Smi> t2702 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
                TNode<Smi> t2703 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*n_433).value()), implicit_cast<TNode<Smi>>(t2702)));
                *n_433 = implicit_cast<TNode<Smi>>(t2703);
              }
              Goto(label__False_701);
            }
            BIND(label__False_701);
          }
          // ../third_party/v8/builtins/array-sort.tq:1614:7
          CallMergeAt(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>((*n_433).value()), label_Bailout_697);
        }
        Goto(label_header_888_1150);
      }
      BIND(label__False_699);
    }
  }
}

void ArrayBuiltinsFromDSLAssembler::InitializeSortState(TNode<FixedArray> p_sortState) {
  Label label_macro_end_1151_impl(this, {});
  Label* label_macro_end_1151 = &label_macro_end_1151_impl;
  USE(label_macro_end_1151);
  // ../third_party/v8/builtins/array-sort.tq:1618:52
  {
    // ../third_party/v8/builtins/array-sort.tq:1619:5
    TNode<Smi> t2704 = UncheckedCast<Smi>(SmiConstant(implicit_cast<int31_t>(kMinGallopWins())));
    USE(implicit_cast<TNode<Smi>>(t2704));
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kMinGallopIdx()), implicit_cast<TNode<Object>>(t2704));
    // ../third_party/v8/builtins/array-sort.tq:1620:5
    int31_t t2705 = 0;
    TNode<Smi> t2706 = UncheckedCast<Smi>(SmiConstant(implicit_cast<int31_t>(t2705)));
    USE(implicit_cast<TNode<Smi>>(t2706));
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kTempArraySizeIdx()), implicit_cast<TNode<Object>>(t2706));
    // ../third_party/v8/builtins/array-sort.tq:1622:5
    int31_t t2707 = 0;
    TNode<Smi> t2708 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2707)));
    SetPendingRunsSize(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>(t2708));
    // ../third_party/v8/builtins/array-sort.tq:1623:5
    TNode<IntPtrT> t2709 = UncheckedCast<IntPtrT>(convert8ATintptr(implicit_cast<int31_t>(kMaxMergePending())));
    USE(implicit_cast<TNode<IntPtrT>>(t2709));
    TNode<FixedArray> t2710 = UncheckedCast<FixedArray>(AllocateZeroedFixedArray(implicit_cast<TNode<IntPtrT>>(t2709)));
    USE(implicit_cast<TNode<FixedArray>>(t2710));
    TVARIABLE(FixedArray, pending_runs_434_impl);
    auto pending_runs_434 = &pending_runs_434_impl;
    USE(pending_runs_434);
    *pending_runs_434 = implicit_cast<TNode<FixedArray>>(t2710);
    // ../third_party/v8/builtins/array-sort.tq:1625:5
    TNode<Smi> t2711 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(kMaxMergePending())));
    FillFixedArrayWithSmiZero(implicit_cast<TNode<FixedArray>>((*pending_runs_434).value()), implicit_cast<TNode<Smi>>(t2711));
    // ../third_party/v8/builtins/array-sort.tq:1626:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kPendingRunsIdx()), implicit_cast<TNode<Object>>((*pending_runs_434).value()));
  }
}

void ArrayBuiltinsFromDSLAssembler::InitializeSortStateAccessor25ATGenericElementsAccessor(TNode<FixedArray> p_sortState) {
  Label label_macro_end_1152_impl(this, {});
  Label* label_macro_end_1152 = &label_macro_end_1152_impl;
  USE(label_macro_end_1152);
  // ../third_party/v8/builtins/array-sort.tq:1636:79
  {
    // ../third_party/v8/builtins/array-sort.tq:1637:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kAccessorIdx()), implicit_cast<TNode<Object>>(kGenericElementsAccessorId()));
    // ../third_party/v8/builtins/array-sort.tq:1638:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kLoadFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoad25ATGenericElementsAccessor).code())));
    // ../third_party/v8/builtins/array-sort.tq:1639:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kStoreFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStore25ATGenericElementsAccessor).code())));
    // ../third_party/v8/builtins/array-sort.tq:1640:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kCanUseSameAccessorFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kCanUseSameAccessor25ATGenericElementsAccessor).code())));
  }
}

void ArrayBuiltinsFromDSLAssembler::ArrayTimSortImpl(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Smi> p_length, Label* label_Bailout_703) {
  Label label_macro_end_1153_impl(this, {});
  Label* label_macro_end_1153 = &label_macro_end_1153_impl;
  USE(label_macro_end_1153);
  // ../third_party/v8/builtins/array-sort.tq:1645:18
  {
    // ../third_party/v8/builtins/array-sort.tq:1646:5
    InitializeSortState(implicit_cast<TNode<FixedArray>>(p_sortState));
    // ../third_party/v8/builtins/array-sort.tq:1648:5
    {
      Label label__True_704_impl(this);
      Label* label__True_704 = &label__True_704_impl;
      USE(label__True_704);
      Label label__False_705_impl(this, {});
      Label* label__False_705 = &label__False_705_impl;
      USE(label__False_705);
      int31_t t2712 = 2;
      TNode<Smi> t2713 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2712)));
      TNode<BoolT> t2714 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>(p_length), implicit_cast<TNode<Smi>>(t2713)));
      USE(implicit_cast<TNode<BoolT>>(t2714));
      Branch(implicit_cast<TNode<BoolT>>(t2714), label__True_704, label__False_705);
      if (label__True_704->is_used())
      {
        BIND(label__True_704);
        // ../third_party/v8/builtins/array-sort.tq:1648:21
        Goto(label_macro_end_1153);
      }
      BIND(label__False_705);
    }
    // ../third_party/v8/builtins/array-sort.tq:1649:5
    TVARIABLE(Smi, remaining_435_impl);
    auto remaining_435 = &remaining_435_impl;
    USE(remaining_435);
    *remaining_435 = implicit_cast<TNode<Smi>>(p_length);
    // ../third_party/v8/builtins/array-sort.tq:1653:5
    int31_t t2715 = 0;
    TVARIABLE(Smi, low_436_impl);
    auto low_436 = &low_436_impl;
    USE(low_436);
    TNode<Smi> t2716 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2715)));
    *low_436 = implicit_cast<TNode<Smi>>(t2716);
    // ../third_party/v8/builtins/array-sort.tq:1654:5
    TNode<Smi> t2717 = UncheckedCast<Smi>(ComputeMinRunLength(implicit_cast<TNode<Smi>>((*remaining_435).value())));
    USE(implicit_cast<TNode<Smi>>(t2717));
    TNode<Smi> min_run_length_889_impl;
    auto min_run_length_889 = &min_run_length_889_impl;
    USE(min_run_length_889);
    *min_run_length_889 = implicit_cast<TNode<Smi>>(t2717);
    // ../third_party/v8/builtins/array-sort.tq:1655:5
    {
      Label label__True_706_impl(this);
      Label* label__True_706 = &label__True_706_impl;
      USE(label__True_706);
      Label label__False_707_impl(this);
      Label* label__False_707 = &label__False_707_impl;
      USE(label__False_707);
      Label label_header_890_1154_impl(this, {low_436, remaining_435});
      Label* label_header_890_1154 = &label_header_890_1154_impl;
      USE(label_header_890_1154);
      Goto(label_header_890_1154);
      BIND(label_header_890_1154);
      int31_t t2718 = 0;
      TNode<Smi> t2719 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2718)));
      TNode<BoolT> t2720 = UncheckedCast<BoolT>(SmiNotEqual(implicit_cast<TNode<Smi>>((*remaining_435).value()), implicit_cast<TNode<Smi>>(t2719)));
      USE(implicit_cast<TNode<BoolT>>(t2720));
      Branch(implicit_cast<TNode<BoolT>>(t2720), label__True_706, label__False_707);
      if (label__True_706->is_used())
      {
        BIND(label__True_706);
        // ../third_party/v8/builtins/array-sort.tq:1655:28
        {
          // ../third_party/v8/builtins/array-sort.tq:1656:7
          TNode<Smi> t2721 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*low_436).value()), implicit_cast<TNode<Smi>>((*remaining_435).value())));
          USE(implicit_cast<TNode<Smi>>(t2721));
          TNode<Smi> t2722 = UncheckedCast<Smi>(CountAndMakeRun(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>((*low_436).value()), implicit_cast<TNode<Smi>>(t2721), label_Bailout_703));
          USE(implicit_cast<TNode<Smi>>(t2722));
          TVARIABLE(Smi, current_run_length_437_impl);
          auto current_run_length_437 = &current_run_length_437_impl;
          USE(current_run_length_437);
          *current_run_length_437 = implicit_cast<TNode<Smi>>(t2722);
          // ../third_party/v8/builtins/array-sort.tq:1661:7
          {
            Label label__True_708_impl(this);
            Label* label__True_708 = &label__True_708_impl;
            USE(label__True_708);
            Label label__False_709_impl(this, {current_run_length_437});
            Label* label__False_709 = &label__False_709_impl;
            USE(label__False_709);
            TNode<BoolT> t2723 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*current_run_length_437).value()), implicit_cast<TNode<Smi>>((*min_run_length_889))));
            USE(implicit_cast<TNode<BoolT>>(t2723));
            Branch(implicit_cast<TNode<BoolT>>(t2723), label__True_708, label__False_709);
            if (label__True_708->is_used())
            {
              BIND(label__True_708);
              // ../third_party/v8/builtins/array-sort.tq:1661:48
              {
                // ../third_party/v8/builtins/array-sort.tq:1662:9
                TNode<Smi> t2724 = UncheckedCast<Smi>(SmiMin(implicit_cast<TNode<Smi>>((*min_run_length_889)), implicit_cast<TNode<Smi>>((*remaining_435).value())));
                USE(implicit_cast<TNode<Smi>>(t2724));
                TNode<Smi> forced_run_length_891_impl;
                auto forced_run_length_891 = &forced_run_length_891_impl;
                USE(forced_run_length_891);
                *forced_run_length_891 = implicit_cast<TNode<Smi>>(t2724);
                // ../third_party/v8/builtins/array-sort.tq:1663:9
                TNode<Smi> t2725 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*low_436).value()), implicit_cast<TNode<Smi>>((*current_run_length_437).value())));
                USE(implicit_cast<TNode<Smi>>(t2725));
                TNode<Smi> t2726 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*low_436).value()), implicit_cast<TNode<Smi>>((*forced_run_length_891))));
                USE(implicit_cast<TNode<Smi>>(t2726));
                TNode<Smi> t2727 = UncheckedCast<Smi>(CallBuiltin(Builtins::kBinaryInsertionSort, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>((*low_436).value()), implicit_cast<TNode<Smi>>(t2725), implicit_cast<TNode<Smi>>(t2726)));
                USE(implicit_cast<TNode<Smi>>(t2727));
                // ../third_party/v8/builtins/array-sort.tq:1666:9
                EnsureSuccess(implicit_cast<TNode<FixedArray>>(p_sortState), label_Bailout_703);
                // ../third_party/v8/builtins/array-sort.tq:1667:9
                *current_run_length_437 = implicit_cast<TNode<Smi>>((*forced_run_length_891));
              }
              Goto(label__False_709);
            }
            BIND(label__False_709);
          }
          // ../third_party/v8/builtins/array-sort.tq:1671:7
          PushRun(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>((*low_436).value()), implicit_cast<TNode<Smi>>((*current_run_length_437).value()));
          // ../third_party/v8/builtins/array-sort.tq:1673:7
          MergeCollapse(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), label_Bailout_703);
          // ../third_party/v8/builtins/array-sort.tq:1676:7
          TNode<Smi> t2728 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*low_436).value()), implicit_cast<TNode<Smi>>((*current_run_length_437).value())));
          USE(implicit_cast<TNode<Smi>>(t2728));
          *low_436 = implicit_cast<TNode<Smi>>(t2728);
          // ../third_party/v8/builtins/array-sort.tq:1677:7
          TNode<Smi> t2729 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*remaining_435).value()), implicit_cast<TNode<Smi>>((*current_run_length_437).value())));
          USE(implicit_cast<TNode<Smi>>(t2729));
          *remaining_435 = implicit_cast<TNode<Smi>>(t2729);
        }
        Goto(label_header_890_1154);
      }
      BIND(label__False_707);
    }
    // ../third_party/v8/builtins/array-sort.tq:1680:5
    MergeForceCollapse(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), label_Bailout_703);
    // ../third_party/v8/builtins/array-sort.tq:1681:5
    // ../third_party/v8/builtins/array-sort.tq:1682:5
  }
  Goto(label_macro_end_1153);
  BIND(label_macro_end_1153);
}

TF_BUILTIN(ArrayTimSort, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<Smi> p_length = UncheckedCast<Smi>(Parameter(Descriptor::kLength));
  USE(p_length);
  // ../third_party/v8/builtins/array-sort.tq:1688:69
  {
    // ../third_party/v8/builtins/array-sort.tq:1689:5
    {
      Label label_try_done_892_1155_impl(this);
      Label* label_try_done_892_1155 = &label_try_done_892_1155_impl;
      USE(label_try_done_892_1155);
      Label label_Slow_710_impl(this);
      Label* label_Slow_710 = &label_Slow_710_impl;
      USE(label_Slow_710);
      Label label_try_begin_893_1156_impl(this);
      Label* label_try_begin_893_1156 = &label_try_begin_893_1156_impl;
      USE(label_try_begin_893_1156);
      Goto(label_try_begin_893_1156);
      if (label_try_begin_893_1156->is_used())
      {
        BIND(label_try_begin_893_1156);
        // ../third_party/v8/builtins/array-sort.tq:1689:9
        {
          // ../third_party/v8/builtins/array-sort.tq:1690:7
          ArrayTimSortImpl(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>(p_length), label_Slow_710);
        }
        Goto(label_try_done_892_1155);
      }
      if (label_Slow_710->is_used())
      {
        BIND(label_Slow_710);
        // ../third_party/v8/builtins/array-sort.tq:1693:16
        {
          // ../third_party/v8/builtins/array-sort.tq:1694:7
          {
            Label label__True_711_impl(this);
            Label* label__True_711 = &label__True_711_impl;
            USE(label__True_711);
            Label label__False_712_impl(this, {});
            Label* label__False_712 = &label__False_712_impl;
            USE(label__False_712);
            TNode<Object> t2730 = UncheckedCast<Object>(LoadFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kAccessorIdx())));
            TNode<BoolT> t2731 = UncheckedCast<BoolT>(WordEqual(implicit_cast<TNode<Object>>(t2730), implicit_cast<TNode<Object>>(kGenericElementsAccessorId())));
            USE(implicit_cast<TNode<BoolT>>(t2731));
            Branch(implicit_cast<TNode<BoolT>>(t2731), label__True_711, label__False_712);
            if (label__True_711->is_used())
            {
              BIND(label__True_711);
              // ../third_party/v8/builtins/array-sort.tq:1694:66
              {
                // ../third_party/v8/builtins/array-sort.tq:1696:9
                Unreachable();
              }
            }
            BIND(label__False_712);
          }
          // ../third_party/v8/builtins/array-sort.tq:1698:7
          StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kBailoutStatusIdx()), implicit_cast<TNode<Object>>(kSuccess()));
          // ../third_party/v8/builtins/array-sort.tq:1700:7
          InitializeSortStateAccessor25ATGenericElementsAccessor(implicit_cast<TNode<FixedArray>>(p_sortState));
          // ../third_party/v8/builtins/array-sort.tq:1701:7
          TNode<Object> t2732 = UncheckedCast<Object>(CallBuiltin(Builtins::kArrayTimSort, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<TNode<Smi>>(p_length)));
          USE(implicit_cast<TNode<Object>>(t2732));
        }
        Goto(label_try_done_892_1155);
      }
      BIND(label_try_done_892_1155);
    }
    // ../third_party/v8/builtins/array-sort.tq:1703:5
    Return(implicit_cast<TNode<Object>>(kSuccess()));
  }
}

TF_BUILTIN(ArrayPrototypeSort, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  CodeStubArguments arguments_impl(this, ChangeInt32ToIntPtr(argc));
  TNode<Object> p_receiver = arguments_impl.GetReceiver();
  auto arguments = &arguments_impl;
  USE(arguments);
  USE(p_receiver);
  // ../third_party/v8/builtins/array-sort.tq:1723:65
  {
    // ../third_party/v8/builtins/array-sort.tq:1726:5
    int31_t t2733 = 0;
    TNode<IntPtrT> t2734 = UncheckedCast<IntPtrT>(from_constexpr8ATintptr(implicit_cast<int31_t>(t2733)));
    TNode<Object> t2735 = UncheckedCast<Object>(GetArgumentValue(implicit_cast<CodeStubArguments*>(arguments), implicit_cast<TNode<IntPtrT>>(t2734)));
    TNode<Object> comparefnObj_894_impl;
    auto comparefnObj_894 = &comparefnObj_894_impl;
    USE(comparefnObj_894);
    *comparefnObj_894 = implicit_cast<TNode<Object>>(t2735);
    // ../third_party/v8/builtins/array-sort.tq:1727:5
    {
      Label label__True_713_impl(this);
      Label* label__True_713 = &label__True_713_impl;
      USE(label__True_713);
      Label label__False_714_impl(this, {});
      Label* label__False_714 = &label__False_714_impl;
      USE(label__False_714);
      Label label__True_715_impl(this);
      Label* label__True_715 = &label__True_715_impl;
      USE(label__True_715);
      TNode<BoolT> t2736 = UncheckedCast<BoolT>(WordNotEqual(implicit_cast<TNode<Object>>((*comparefnObj_894)), implicit_cast<TNode<Object>>(Undefined())));
      USE(implicit_cast<TNode<BoolT>>(t2736));
      GotoIfNot(implicit_cast<TNode<BoolT>>(t2736), label__False_714);
      TNode<BoolT> t2737 = UncheckedCast<BoolT>(TaggedIsCallable(implicit_cast<TNode<Object>>((*comparefnObj_894))));
      USE(implicit_cast<TNode<BoolT>>(t2737));
      TNode<BoolT> t2738 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t2737)));
      USE(implicit_cast<TNode<BoolT>>(t2738));
      Branch(implicit_cast<TNode<BoolT>>(t2738), label__True_713, label__False_714);
      if (label__True_713->is_used())
      {
        BIND(label__True_713);
        // ../third_party/v8/builtins/array-sort.tq:1727:71
        {
          // ../third_party/v8/builtins/array-sort.tq:1728:7
          ThrowTypeError(implicit_cast<TNode<Context>>(p_context), implicit_cast<MessageTemplate::Template>(MessageTemplate::kBadSortComparisonFunction), implicit_cast<TNode<Object>>((*comparefnObj_894)));
        }
      }
      BIND(label__False_714);
    }
    // ../third_party/v8/builtins/array-sort.tq:1732:5
    TNode<JSReceiver> t2739 = UncheckedCast<JSReceiver>(CallBuiltin(Builtins::kToObject, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_receiver)));
    USE(implicit_cast<TNode<JSReceiver>>(t2739));
    TNode<JSReceiver> obj_895_impl;
    auto obj_895 = &obj_895_impl;
    USE(obj_895);
    *obj_895 = implicit_cast<TNode<JSReceiver>>(t2739);
    // ../third_party/v8/builtins/array-sort.tq:1734:5
    TNode<FixedArray> t2740 = UncheckedCast<FixedArray>(AllocateZeroedFixedArray(implicit_cast<TNode<IntPtrT>>(kSortStateSize())));
    USE(implicit_cast<TNode<FixedArray>>(t2740));
    TNode<FixedArray> sort_state_896_impl;
    auto sort_state_896 = &sort_state_896_impl;
    USE(sort_state_896);
    *sort_state_896 = implicit_cast<TNode<FixedArray>>(t2740);
    // ../third_party/v8/builtins/array-sort.tq:1735:5
    TNode<Smi> t2741 = UncheckedCast<Smi>(SmiTag(implicit_cast<TNode<IntPtrT>>(kSortStateSize())));
    USE(implicit_cast<TNode<Smi>>(t2741));
    FillFixedArrayWithSmiZero(implicit_cast<TNode<FixedArray>>((*sort_state_896)), implicit_cast<TNode<Smi>>(t2741));
    // ../third_party/v8/builtins/array-sort.tq:1737:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>((*sort_state_896)), implicit_cast<int31_t>(kReceiverIdx()), implicit_cast<TNode<Object>>((*obj_895)));
    // ../third_party/v8/builtins/array-sort.tq:1738:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>((*sort_state_896)), implicit_cast<int31_t>(kUserCmpFnIdx()), implicit_cast<TNode<Object>>((*comparefnObj_894)));
    // ../third_party/v8/builtins/array-sort.tq:1739:5
    auto t2742 = [=]() {
      return implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kSortCompareUserFn).code()));
    };
    auto t2743 = [=]() {
      return implicit_cast<TNode<Code>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kSortCompareDefault).code()));
    };
    TVARIABLE(Code, t2744_897_impl);
    auto t2744_897 = &t2744_897_impl;
    USE(t2744_897);
    {
      Label label__True_716_impl(this);
      Label* label__True_716 = &label__True_716_impl;
      USE(label__True_716);
      Label label__False_717_impl(this);
      Label* label__False_717 = &label__False_717_impl;
      USE(label__False_717);
      Label label__done_898_1157_impl(this, {t2744_897});
      Label* label__done_898_1157 = &label__done_898_1157_impl;
      USE(label__done_898_1157);
      TNode<BoolT> t2745 = UncheckedCast<BoolT>(WordNotEqual(implicit_cast<TNode<Object>>((*comparefnObj_894)), implicit_cast<TNode<Object>>(Undefined())));
      USE(implicit_cast<TNode<BoolT>>(t2745));
      Branch(implicit_cast<TNode<BoolT>>(t2745), label__True_716, label__False_717);
      BIND(label__True_716);
            *t2744_897 = implicit_cast<TNode<Code>>(t2742());
      Goto(label__done_898_1157);
      BIND(label__False_717);
            *t2744_897 = implicit_cast<TNode<Code>>(t2743());
      Goto(label__done_898_1157);
      BIND(label__done_898_1157);
    }
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>((*sort_state_896)), implicit_cast<int31_t>(kSortComparePtrIdx()), implicit_cast<TNode<Object>>((*t2744_897).value()));
    // ../third_party/v8/builtins/array-sort.tq:1741:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>((*sort_state_896)), implicit_cast<int31_t>(kBailoutStatusIdx()), implicit_cast<TNode<Object>>(kSuccess()));
    // ../third_party/v8/builtins/array-sort.tq:1744:5
    const char* t2746 = "length";
    TNode<Object> t2747 = UncheckedCast<Object>(from_constexpr22UT12ATHeapObject5ATSmi(implicit_cast<const char*>(t2746)));
    TNode<Object> t2748 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*obj_895)), implicit_cast<TNode<Object>>(t2747)));
    USE(implicit_cast<TNode<Object>>(t2748));
    TNode<Number> t2749 = UncheckedCast<Number>(ToLength_Inline(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(t2748)));
    USE(implicit_cast<TNode<Number>>(t2749));
    TNode<Number> len_899_impl;
    auto len_899 = &len_899_impl;
    USE(len_899);
    *len_899 = implicit_cast<TNode<Number>>(t2749);
    // ../third_party/v8/builtins/array-sort.tq:1746:5
    {
      Label label__True_718_impl(this);
      Label* label__True_718 = &label__True_718_impl;
      USE(label__True_718);
      Label label__False_719_impl(this, {});
      Label* label__False_719 = &label__False_719_impl;
      USE(label__False_719);
      int31_t t2750 = 2;
      TNode<Number> t2751 = UncheckedCast<Number>(from_constexpr22UT12ATHeapNumber5ATSmi(implicit_cast<int31_t>(t2750)));
      BranchIfNumberLessThan(implicit_cast<TNode<Number>>((*len_899)), implicit_cast<TNode<Number>>(t2751), label__True_718, label__False_719);
      if (label__True_718->is_used())
      {
        BIND(label__True_718);
        // ../third_party/v8/builtins/array-sort.tq:1746:18
        arguments->PopAndReturn(implicit_cast<TNode<Object>>(p_receiver));
      }
      BIND(label__False_719);
    }
    // ../third_party/v8/builtins/array-sort.tq:1750:5
    TNode<Smi> t2752 = UncheckedCast<Smi>(CallRuntime(Runtime::kPrepareElementsForSort, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>((*obj_895)), implicit_cast<TNode<Number>>((*len_899))));
    USE(implicit_cast<TNode<Smi>>(t2752));
    TNode<Smi> nofNonUndefined_900_impl;
    auto nofNonUndefined_900 = &nofNonUndefined_900_impl;
    USE(nofNonUndefined_900);
    *nofNonUndefined_900 = implicit_cast<TNode<Smi>>(t2752);
    // ../third_party/v8/builtins/array-sort.tq:1751:5
    // ../third_party/v8/builtins/array-sort.tq:1753:5
    TNode<Map> t2753 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>((*obj_895))));
    TVARIABLE(Map, map_438_impl);
    auto map_438 = &map_438_impl;
    USE(map_438);
    *map_438 = implicit_cast<TNode<Map>>(t2753);
    // ../third_party/v8/builtins/array-sort.tq:1754:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>((*sort_state_896)), implicit_cast<int31_t>(kInitialReceiverMapIdx()), implicit_cast<TNode<Object>>((*map_438).value()));
    // ../third_party/v8/builtins/array-sort.tq:1755:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>((*sort_state_896)), implicit_cast<int31_t>(kInitialReceiverLengthIdx()), implicit_cast<TNode<Object>>((*len_899)));
    // ../third_party/v8/builtins/array-sort.tq:1757:5
    {
      Label label_try_done_901_1158_impl(this);
      Label* label_try_done_901_1158 = &label_try_done_901_1158_impl;
      USE(label_try_done_901_1158);
      Label label_slow_720_impl(this);
      Label* label_slow_720 = &label_slow_720_impl;
      USE(label_slow_720);
      Label label_try_begin_902_1159_impl(this);
      Label* label_try_begin_902_1159 = &label_try_begin_902_1159_impl;
      USE(label_try_begin_902_1159);
      Goto(label_try_begin_902_1159);
      if (label_try_begin_902_1159->is_used())
      {
        BIND(label_try_begin_902_1159);
        // ../third_party/v8/builtins/array-sort.tq:1757:9
        {
          // ../third_party/v8/builtins/array-sort.tq:1758:7
          TNode<JSArray> t2754 = UncheckedCast<JSArray>(cast9ATJSArray(implicit_cast<TNode<HeapObject>>((*obj_895)), label_slow_720));
          USE(implicit_cast<TNode<JSArray>>(t2754));
          TNode<JSArray> a_903_impl;
          auto a_903 = &a_903_impl;
          USE(a_903);
          *a_903 = implicit_cast<TNode<JSArray>>(t2754);
          // ../third_party/v8/builtins/array-sort.tq:1759:7
          TNode<Int32T> t2755 = UncheckedCast<Int32T>(LoadMapElementsKind(implicit_cast<TNode<Map>>((*map_438).value())));
          TNode<Int32T> elementsKind_904_impl;
          auto elementsKind_904 = &elementsKind_904_impl;
          USE(elementsKind_904);
          *elementsKind_904 = implicit_cast<TNode<Int32T>>(t2755);
          // ../third_party/v8/builtins/array-sort.tq:1760:7
          {
            Label label__True_721_impl(this);
            Label* label__True_721 = &label__True_721_impl;
            USE(label__True_721);
            Label label__False_722_impl(this, {});
            Label* label__False_722 = &label__False_722_impl;
            USE(label__False_722);
            TNode<BoolT> t2756 = UncheckedCast<BoolT>(IsFastElementsKind(implicit_cast<TNode<Int32T>>((*elementsKind_904))));
            USE(implicit_cast<TNode<BoolT>>(t2756));
            TNode<BoolT> t2757 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t2756)));
            USE(implicit_cast<TNode<BoolT>>(t2757));
            Branch(implicit_cast<TNode<BoolT>>(t2757), label__True_721, label__False_722);
            if (label__True_721->is_used())
            {
              BIND(label__True_721);
              // ../third_party/v8/builtins/array-sort.tq:1760:46
              Goto(label_slow_720);
            }
            BIND(label__False_722);
          }
          // ../third_party/v8/builtins/array-sort.tq:1762:7
          {
            Label label__True_723_impl(this);
            Label* label__True_723 = &label__True_723_impl;
            USE(label__True_723);
            Label label__False_724_impl(this);
            Label* label__False_724 = &label__False_724_impl;
            USE(label__False_724);
            Label label_if_done_label_905_1160_impl(this, {});
            Label* label_if_done_label_905_1160 = &label_if_done_label_905_1160_impl;
            USE(label_if_done_label_905_1160);
            TNode<BoolT> t2758 = UncheckedCast<BoolT>(IsDoubleElementsKind(implicit_cast<TNode<Int32T>>((*elementsKind_904))));
            USE(implicit_cast<TNode<BoolT>>(t2758));
            Branch(implicit_cast<TNode<BoolT>>(t2758), label__True_723, label__False_724);
            if (label__True_723->is_used())
            {
              BIND(label__True_723);
              // ../third_party/v8/builtins/array-sort.tq:1762:47
              {
                // ../third_party/v8/builtins/array-sort.tq:1763:9
                InitializeSortStateAccessor20ATFastDoubleElements(implicit_cast<TNode<FixedArray>>((*sort_state_896)));
              }
              Goto(label_if_done_label_905_1160);
            }
            if (label__False_724->is_used())
            {
              BIND(label__False_724);
              // ../third_party/v8/builtins/array-sort.tq:1764:14
              {
                Label label__True_725_impl(this);
                Label* label__True_725 = &label__True_725_impl;
                USE(label__True_725);
                Label label__False_726_impl(this);
                Label* label__False_726 = &label__False_726_impl;
                USE(label__False_726);
                Label label_if_done_label_906_1161_impl(this, {});
                Label* label_if_done_label_906_1161 = &label_if_done_label_906_1161_impl;
                USE(label_if_done_label_906_1161);
                TNode<Int32T> t2759 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(PACKED_SMI_ELEMENTS)));
                TNode<BoolT> t2760 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>((*elementsKind_904)), implicit_cast<TNode<Int32T>>(t2759)));
                USE(implicit_cast<TNode<BoolT>>(t2760));
                Branch(implicit_cast<TNode<BoolT>>(t2760), label__True_725, label__False_726);
                if (label__True_725->is_used())
                {
                  BIND(label__True_725);
                  // ../third_party/v8/builtins/array-sort.tq:1764:55
                  {
                    // ../third_party/v8/builtins/array-sort.tq:1765:9
                    InitializeSortStateAccessor23ATFastPackedSmiElements(implicit_cast<TNode<FixedArray>>((*sort_state_896)));
                  }
                  Goto(label_if_done_label_906_1161);
                }
                if (label__False_726->is_used())
                {
                  BIND(label__False_726);
                  // ../third_party/v8/builtins/array-sort.tq:1766:14
                  {
                    // ../third_party/v8/builtins/array-sort.tq:1767:9
                    InitializeSortStateAccessor25ATFastSmiOrObjectElements(implicit_cast<TNode<FixedArray>>((*sort_state_896)));
                  }
                  Goto(label_if_done_label_906_1161);
                }
                BIND(label_if_done_label_906_1161);
              }
              Goto(label_if_done_label_905_1160);
            }
            BIND(label_if_done_label_905_1160);
          }
          // ../third_party/v8/builtins/array-sort.tq:1769:7
          TNode<Object> t2761 = UncheckedCast<Object>(CallBuiltin(Builtins::kArrayTimSort, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>((*sort_state_896)), implicit_cast<TNode<Smi>>((*nofNonUndefined_900))));
          USE(implicit_cast<TNode<Object>>(t2761));
        }
        Goto(label_try_done_901_1158);
      }
      if (label_slow_720->is_used())
      {
        BIND(label_slow_720);
        // ../third_party/v8/builtins/array-sort.tq:1771:16
        {
          // ../third_party/v8/builtins/array-sort.tq:1772:7
          {
            Label label__True_727_impl(this);
            Label* label__True_727 = &label__True_727_impl;
            USE(label__True_727);
            Label label__False_728_impl(this);
            Label* label__False_728 = &label__False_728_impl;
            USE(label__False_728);
            Label label_if_done_label_907_1162_impl(this, {});
            Label* label_if_done_label_907_1162 = &label_if_done_label_907_1162_impl;
            USE(label_if_done_label_907_1162);
            Label label__True_729_impl(this);
            Label* label__True_729 = &label__True_729_impl;
            USE(label__True_729);
            Label label__True_730_impl(this);
            Label* label__True_730 = &label__True_730_impl;
            USE(label__True_730);
            TNode<Int32T> t2762 = UncheckedCast<Int32T>(LoadMapElementsKind(implicit_cast<TNode<Map>>((*map_438).value())));
            TNode<Int32T> t2763 = UncheckedCast<Int32T>(from_constexpr14ATElementsKind(implicit_cast<ElementsKind>(DICTIONARY_ELEMENTS)));
            TNode<BoolT> t2764 = UncheckedCast<BoolT>(ElementsKindEqual(implicit_cast<TNode<Int32T>>(t2762), implicit_cast<TNode<Int32T>>(t2763)));
            USE(implicit_cast<TNode<BoolT>>(t2764));
            GotoIfNot(implicit_cast<TNode<BoolT>>(t2764), label__False_728);
            TNode<BoolT> t2765 = UncheckedCast<BoolT>(IsExtensibleMap(implicit_cast<TNode<Map>>((*map_438).value())));
            USE(implicit_cast<TNode<BoolT>>(t2765));
            GotoIfNot(implicit_cast<TNode<BoolT>>(t2765), label__False_728);
            TNode<Int32T> t2766 = UncheckedCast<Int32T>(LoadMapInstanceType(implicit_cast<TNode<Map>>((*map_438).value())));
            TNode<BoolT> t2767 = UncheckedCast<BoolT>(IsCustomElementsReceiverInstanceType(implicit_cast<TNode<Int32T>>(t2766)));
            USE(implicit_cast<TNode<BoolT>>(t2767));
            TNode<BoolT> t2768 = UncheckedCast<BoolT>(Word32BinaryNot(implicit_cast<TNode<BoolT>>(t2767)));
            USE(implicit_cast<TNode<BoolT>>(t2768));
            Branch(implicit_cast<TNode<BoolT>>(t2768), label__True_727, label__False_728);
            if (label__True_727->is_used())
            {
              BIND(label__True_727);
              // ../third_party/v8/builtins/array-sort.tq:1773:69
              {
                // ../third_party/v8/builtins/array-sort.tq:1774:9
                InitializeSortStateAccessor20ATDictionaryElements(implicit_cast<TNode<FixedArray>>((*sort_state_896)));
              }
              Goto(label_if_done_label_907_1162);
            }
            if (label__False_728->is_used())
            {
              BIND(label__False_728);
              // ../third_party/v8/builtins/array-sort.tq:1775:14
              {
                // ../third_party/v8/builtins/array-sort.tq:1776:9
                InitializeSortStateAccessor25ATGenericElementsAccessor(implicit_cast<TNode<FixedArray>>((*sort_state_896)));
              }
              Goto(label_if_done_label_907_1162);
            }
            BIND(label_if_done_label_907_1162);
          }
          // ../third_party/v8/builtins/array-sort.tq:1778:7
          TNode<Object> t2769 = UncheckedCast<Object>(CallBuiltin(Builtins::kArrayTimSort, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<FixedArray>>((*sort_state_896)), implicit_cast<TNode<Smi>>((*nofNonUndefined_900))));
          USE(implicit_cast<TNode<Object>>(t2769));
        }
        Goto(label_try_done_901_1158);
      }
      BIND(label_try_done_901_1158);
    }
    // ../third_party/v8/builtins/array-sort.tq:1781:5
    arguments->PopAndReturn(implicit_cast<TNode<Object>>(p_receiver));
  }
}

void ArrayBuiltinsFromDSLAssembler::VisitAllElements18ATFixedDoubleArray(TNode<Context> p_context, TNode<JSArray> p_a, TNode<Smi> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, Label* label_Bailout_741, TVariable<Smi>* Bailout0_451) {
  Label label_macro_end_1168_impl(this, {});
  Label* label_macro_end_1168 = &label_macro_end_1168_impl;
  USE(label_macro_end_1168);
  // ../src/builtins/array-foreach.tq:77:16
  {
    // ../src/builtins/array-foreach.tq:78:5
    int31_t t2777 = 0;
    TVARIABLE(Smi, k_452_impl);
    auto k_452 = &k_452_impl;
    USE(k_452);
    TNode<Smi> t2778 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2777)));
    *k_452 = implicit_cast<TNode<Smi>>(t2778);
    // ../src/builtins/array-foreach.tq:79:5
    TNode<Map> t2779 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>(p_a)));
    TNode<Map> map_908_impl;
    auto map_908 = &map_908_impl;
    USE(map_908);
    *map_908 = implicit_cast<TNode<Map>>(t2779);
    // ../src/builtins/array-foreach.tq:81:5
    {
      Label label_try_done_909_1169_impl(this);
      Label* label_try_done_909_1169 = &label_try_done_909_1169_impl;
      USE(label_try_done_909_1169);
      Label label_Slow_742_impl(this);
      Label* label_Slow_742 = &label_Slow_742_impl;
      USE(label_Slow_742);
      Label label_try_begin_910_1170_impl(this);
      Label* label_try_begin_910_1170 = &label_try_begin_910_1170_impl;
      USE(label_try_begin_910_1170);
      Goto(label_try_begin_910_1170);
      if (label_try_begin_910_1170->is_used())
      {
        BIND(label_try_begin_910_1170);
        // ../src/builtins/array-foreach.tq:81:9
        {
          // ../src/builtins/array-foreach.tq:83:7
          Label label__True_743_impl(this);
          Label* label__True_743 = &label__True_743_impl;
          USE(label__True_743);
          Label label__False_744_impl(this);
          Label* label__False_744 = &label__False_744_impl;
          USE(label__False_744);
          Label label_header_911_1171_impl(this, {k_452});
          Label* label_header_911_1171 = &label_header_911_1171_impl;
          USE(label_header_911_1171);
          Goto(label_header_911_1171);
          BIND(label_header_911_1171);
          Label label_action_912_1172_impl(this);
          Label* label_action_912_1172 = &label_action_912_1172_impl;
          USE(label_action_912_1172);
          TNode<BoolT> t2780 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*k_452).value()), implicit_cast<TNode<Smi>>(p_len)));
          USE(implicit_cast<TNode<BoolT>>(t2780));
          Branch(implicit_cast<TNode<BoolT>>(t2780), label__True_743, label__False_744);
          if (label__True_743->is_used())
          {
            BIND(label__True_743);
            // ../src/builtins/array-foreach.tq:83:34
            {
              // ../src/builtins/array-foreach.tq:85:9
              {
                Label label__True_745_impl(this);
                Label* label__True_745 = &label__True_745_impl;
                USE(label__True_745);
                Label label__False_746_impl(this, {});
                Label* label__False_746 = &label__False_746_impl;
                USE(label__False_746);
                TNode<Map> t2781 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>(p_a)));
                TNode<BoolT> t2782 = UncheckedCast<BoolT>(WordNotEqual(implicit_cast<TNode<Object>>((*map_908)), implicit_cast<TNode<Object>>(t2781)));
                USE(implicit_cast<TNode<BoolT>>(t2782));
                Branch(implicit_cast<TNode<BoolT>>(t2782), label__True_745, label__False_746);
                if (label__True_745->is_used())
                {
                  BIND(label__True_745);
                  // ../src/builtins/array-foreach.tq:85:27
                  Goto(label_Slow_742);
                }
                BIND(label__False_746);
              }
              // ../src/builtins/array-foreach.tq:87:9
              {
                Label label__True_747_impl(this);
                Label* label__True_747 = &label__True_747_impl;
                USE(label__True_747);
                Label label__False_748_impl(this, {});
                Label* label__False_748 = &label__False_748_impl;
                USE(label__False_748);
                TNode<Number> t2783 = UncheckedCast<Number>(LoadJSArrayLength(implicit_cast<TNode<JSArray>>(p_a)));
                BranchIfNumberGreaterThanOrEqual(implicit_cast<TNode<Number>>((*k_452).value()), implicit_cast<TNode<Number>>(t2783), label__True_747, label__False_748);
                if (label__True_747->is_used())
                {
                  BIND(label__True_747);
                  // ../src/builtins/array-foreach.tq:87:28
                  Goto(label_Slow_742);
                }
                BIND(label__False_748);
              }
              // ../src/builtins/array-foreach.tq:89:9
              {
                Label label_try_done_913_1173_impl(this);
                Label* label_try_done_913_1173 = &label_try_done_913_1173_impl;
                USE(label_try_done_913_1173);
                Label label_FoundHole_749_impl(this);
                Label* label_FoundHole_749 = &label_FoundHole_749_impl;
                USE(label_FoundHole_749);
                Label label_try_begin_914_1174_impl(this);
                Label* label_try_begin_914_1174 = &label_try_begin_914_1174_impl;
                USE(label_try_begin_914_1174);
                Goto(label_try_begin_914_1174);
                if (label_try_begin_914_1174->is_used())
                {
                  BIND(label_try_begin_914_1174);
                  // ../src/builtins/array-foreach.tq:89:13
                  {
                    // ../src/builtins/array-foreach.tq:90:11
                    TNode<Object> t2784 = UncheckedCast<Object>(LoadElementNoHole18ATFixedDoubleArray(implicit_cast<TNode<JSArray>>(p_a), implicit_cast<TNode<Smi>>((*k_452).value()), label_FoundHole_749));
                    USE(implicit_cast<TNode<Object>>(t2784));
                    TNode<Object> value_915_impl;
                    auto value_915 = &value_915_impl;
                    USE(value_915);
                    *value_915 = implicit_cast<TNode<Object>>(t2784);
                    // ../src/builtins/array-foreach.tq:92:11
                    TNode<Object> t2785 = UncheckedCast<Object>(Call(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>(p_callbackfn), implicit_cast<TNode<Object>>(p_thisArg), implicit_cast<TNode<Object>>((*value_915)), implicit_cast<TNode<Object>>((*k_452).value()), implicit_cast<TNode<Object>>(p_a)));
                    USE(implicit_cast<TNode<Object>>(t2785));
                  }
                  Goto(label_try_done_913_1173);
                }
                if (label_FoundHole_749->is_used())
                {
                  BIND(label_FoundHole_749);
                  // ../src/builtins/array-foreach.tq:94:25
                  {
                    // ../src/builtins/array-foreach.tq:99:11
                    {
                      Label label__True_750_impl(this);
                      Label* label__True_750 = &label__True_750_impl;
                      USE(label__True_750);
                      Label label__False_751_impl(this, {});
                      Label* label__False_751 = &label__False_751_impl;
                      USE(label__False_751);
                      TNode<BoolT> t2786 = UncheckedCast<BoolT>(IsNoElementsProtectorCellInvalid());
                      USE(implicit_cast<TNode<BoolT>>(t2786));
                      Branch(implicit_cast<TNode<BoolT>>(t2786), label__True_750, label__False_751);
                      if (label__True_750->is_used())
                      {
                        BIND(label__True_750);
                        // ../src/builtins/array-foreach.tq:99:51
                        *Bailout0_451 = implicit_cast<TNode<Smi>>((*k_452).value());
                        Goto(label_Bailout_741);
                      }
                      BIND(label__False_751);
                    }
                  }
                  Goto(label_try_done_913_1173);
                }
                BIND(label_try_done_913_1173);
              }
            }
            Goto(label_action_912_1172);
          }
          {
            BIND(label_action_912_1172);
            int31_t t2787 = 1;
            TNode<Smi> t2788 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2787)));
            TNode<Smi> t2789 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*k_452).value()), implicit_cast<TNode<Smi>>(t2788)));
            USE(implicit_cast<TNode<Smi>>(t2789));
            *k_452 = implicit_cast<TNode<Smi>>(t2789);
            Goto(label_header_911_1171);
          }
          BIND(label__False_744);
        }
        Goto(label_try_done_909_1169);
      }
      if (label_Slow_742->is_used())
      {
        BIND(label_Slow_742);
        // ../src/builtins/array-foreach.tq:103:16
        {
          // ../src/builtins/array-foreach.tq:104:7
          *Bailout0_451 = implicit_cast<TNode<Smi>>((*k_452).value());
          Goto(label_Bailout_741);
        }
      }
      BIND(label_try_done_909_1169);
    }
  }
}

void ArrayBuiltinsFromDSLAssembler::VisitAllElements12ATFixedArray(TNode<Context> p_context, TNode<JSArray> p_a, TNode<Smi> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, Label* label_Bailout_752, TVariable<Smi>* Bailout0_453) {
  Label label_macro_end_1175_impl(this, {});
  Label* label_macro_end_1175 = &label_macro_end_1175_impl;
  USE(label_macro_end_1175);
  // ../src/builtins/array-foreach.tq:77:16
  {
    // ../src/builtins/array-foreach.tq:78:5
    int31_t t2790 = 0;
    TVARIABLE(Smi, k_454_impl);
    auto k_454 = &k_454_impl;
    USE(k_454);
    TNode<Smi> t2791 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2790)));
    *k_454 = implicit_cast<TNode<Smi>>(t2791);
    // ../src/builtins/array-foreach.tq:79:5
    TNode<Map> t2792 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>(p_a)));
    TNode<Map> map_916_impl;
    auto map_916 = &map_916_impl;
    USE(map_916);
    *map_916 = implicit_cast<TNode<Map>>(t2792);
    // ../src/builtins/array-foreach.tq:81:5
    {
      Label label_try_done_917_1176_impl(this);
      Label* label_try_done_917_1176 = &label_try_done_917_1176_impl;
      USE(label_try_done_917_1176);
      Label label_Slow_753_impl(this);
      Label* label_Slow_753 = &label_Slow_753_impl;
      USE(label_Slow_753);
      Label label_try_begin_918_1177_impl(this);
      Label* label_try_begin_918_1177 = &label_try_begin_918_1177_impl;
      USE(label_try_begin_918_1177);
      Goto(label_try_begin_918_1177);
      if (label_try_begin_918_1177->is_used())
      {
        BIND(label_try_begin_918_1177);
        // ../src/builtins/array-foreach.tq:81:9
        {
          // ../src/builtins/array-foreach.tq:83:7
          Label label__True_754_impl(this);
          Label* label__True_754 = &label__True_754_impl;
          USE(label__True_754);
          Label label__False_755_impl(this);
          Label* label__False_755 = &label__False_755_impl;
          USE(label__False_755);
          Label label_header_919_1178_impl(this, {k_454});
          Label* label_header_919_1178 = &label_header_919_1178_impl;
          USE(label_header_919_1178);
          Goto(label_header_919_1178);
          BIND(label_header_919_1178);
          Label label_action_920_1179_impl(this);
          Label* label_action_920_1179 = &label_action_920_1179_impl;
          USE(label_action_920_1179);
          TNode<BoolT> t2793 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*k_454).value()), implicit_cast<TNode<Smi>>(p_len)));
          USE(implicit_cast<TNode<BoolT>>(t2793));
          Branch(implicit_cast<TNode<BoolT>>(t2793), label__True_754, label__False_755);
          if (label__True_754->is_used())
          {
            BIND(label__True_754);
            // ../src/builtins/array-foreach.tq:83:34
            {
              // ../src/builtins/array-foreach.tq:85:9
              {
                Label label__True_756_impl(this);
                Label* label__True_756 = &label__True_756_impl;
                USE(label__True_756);
                Label label__False_757_impl(this, {});
                Label* label__False_757 = &label__False_757_impl;
                USE(label__False_757);
                TNode<Map> t2794 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>(p_a)));
                TNode<BoolT> t2795 = UncheckedCast<BoolT>(WordNotEqual(implicit_cast<TNode<Object>>((*map_916)), implicit_cast<TNode<Object>>(t2794)));
                USE(implicit_cast<TNode<BoolT>>(t2795));
                Branch(implicit_cast<TNode<BoolT>>(t2795), label__True_756, label__False_757);
                if (label__True_756->is_used())
                {
                  BIND(label__True_756);
                  // ../src/builtins/array-foreach.tq:85:27
                  Goto(label_Slow_753);
                }
                BIND(label__False_757);
              }
              // ../src/builtins/array-foreach.tq:87:9
              {
                Label label__True_758_impl(this);
                Label* label__True_758 = &label__True_758_impl;
                USE(label__True_758);
                Label label__False_759_impl(this, {});
                Label* label__False_759 = &label__False_759_impl;
                USE(label__False_759);
                TNode<Number> t2796 = UncheckedCast<Number>(LoadJSArrayLength(implicit_cast<TNode<JSArray>>(p_a)));
                BranchIfNumberGreaterThanOrEqual(implicit_cast<TNode<Number>>((*k_454).value()), implicit_cast<TNode<Number>>(t2796), label__True_758, label__False_759);
                if (label__True_758->is_used())
                {
                  BIND(label__True_758);
                  // ../src/builtins/array-foreach.tq:87:28
                  Goto(label_Slow_753);
                }
                BIND(label__False_759);
              }
              // ../src/builtins/array-foreach.tq:89:9
              {
                Label label_try_done_921_1180_impl(this);
                Label* label_try_done_921_1180 = &label_try_done_921_1180_impl;
                USE(label_try_done_921_1180);
                Label label_FoundHole_760_impl(this);
                Label* label_FoundHole_760 = &label_FoundHole_760_impl;
                USE(label_FoundHole_760);
                Label label_try_begin_922_1181_impl(this);
                Label* label_try_begin_922_1181 = &label_try_begin_922_1181_impl;
                USE(label_try_begin_922_1181);
                Goto(label_try_begin_922_1181);
                if (label_try_begin_922_1181->is_used())
                {
                  BIND(label_try_begin_922_1181);
                  // ../src/builtins/array-foreach.tq:89:13
                  {
                    // ../src/builtins/array-foreach.tq:90:11
                    TNode<Object> t2797 = UncheckedCast<Object>(LoadElementNoHole12ATFixedArray(implicit_cast<TNode<JSArray>>(p_a), implicit_cast<TNode<Smi>>((*k_454).value()), label_FoundHole_760));
                    USE(implicit_cast<TNode<Object>>(t2797));
                    TNode<Object> value_923_impl;
                    auto value_923 = &value_923_impl;
                    USE(value_923);
                    *value_923 = implicit_cast<TNode<Object>>(t2797);
                    // ../src/builtins/array-foreach.tq:92:11
                    TNode<Object> t2798 = UncheckedCast<Object>(Call(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<JSReceiver>>(p_callbackfn), implicit_cast<TNode<Object>>(p_thisArg), implicit_cast<TNode<Object>>((*value_923)), implicit_cast<TNode<Object>>((*k_454).value()), implicit_cast<TNode<Object>>(p_a)));
                    USE(implicit_cast<TNode<Object>>(t2798));
                  }
                  Goto(label_try_done_921_1180);
                }
                if (label_FoundHole_760->is_used())
                {
                  BIND(label_FoundHole_760);
                  // ../src/builtins/array-foreach.tq:94:25
                  {
                    // ../src/builtins/array-foreach.tq:99:11
                    {
                      Label label__True_761_impl(this);
                      Label* label__True_761 = &label__True_761_impl;
                      USE(label__True_761);
                      Label label__False_762_impl(this, {});
                      Label* label__False_762 = &label__False_762_impl;
                      USE(label__False_762);
                      TNode<BoolT> t2799 = UncheckedCast<BoolT>(IsNoElementsProtectorCellInvalid());
                      USE(implicit_cast<TNode<BoolT>>(t2799));
                      Branch(implicit_cast<TNode<BoolT>>(t2799), label__True_761, label__False_762);
                      if (label__True_761->is_used())
                      {
                        BIND(label__True_761);
                        // ../src/builtins/array-foreach.tq:99:51
                        *Bailout0_453 = implicit_cast<TNode<Smi>>((*k_454).value());
                        Goto(label_Bailout_752);
                      }
                      BIND(label__False_762);
                    }
                  }
                  Goto(label_try_done_921_1180);
                }
                BIND(label_try_done_921_1180);
              }
            }
            Goto(label_action_920_1179);
          }
          {
            BIND(label_action_920_1179);
            int31_t t2800 = 1;
            TNode<Smi> t2801 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2800)));
            TNode<Smi> t2802 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*k_454).value()), implicit_cast<TNode<Smi>>(t2801)));
            USE(implicit_cast<TNode<Smi>>(t2802));
            *k_454 = implicit_cast<TNode<Smi>>(t2802);
            Goto(label_header_919_1178);
          }
          BIND(label__False_755);
        }
        Goto(label_try_done_917_1176);
      }
      if (label_Slow_753->is_used())
      {
        BIND(label_Slow_753);
        // ../src/builtins/array-foreach.tq:103:16
        {
          // ../src/builtins/array-foreach.tq:104:7
          *Bailout0_453 = implicit_cast<TNode<Smi>>((*k_454).value());
          Goto(label_Bailout_752);
        }
      }
      BIND(label_try_done_917_1176);
    }
  }
}

void ArrayBuiltinsFromDSLAssembler::FastPackedArrayReverse23ATFastPackedSmiElements5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_length) {
  Label label_macro_end_1182_impl(this, {});
  Label* label_macro_end_1182 = &label_macro_end_1182_impl;
  USE(label_macro_end_1182);
  // ../src/builtins/array-reverse.tq:61:46
  {
    // ../src/builtins/array-reverse.tq:62:5
    int31_t t2803 = 0;
    TVARIABLE(Smi, lower_455_impl);
    auto lower_455 = &lower_455_impl;
    USE(lower_455);
    TNode<Smi> t2804 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2803)));
    *lower_455 = implicit_cast<TNode<Smi>>(t2804);
    // ../src/builtins/array-reverse.tq:63:5
    int31_t t2805 = 1;
    TNode<Smi> t2806 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2805)));
    TNode<Smi> t2807 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_length), implicit_cast<TNode<Smi>>(t2806)));
    USE(implicit_cast<TNode<Smi>>(t2807));
    TVARIABLE(Smi, upper_456_impl);
    auto upper_456 = &upper_456_impl;
    USE(upper_456);
    *upper_456 = implicit_cast<TNode<Smi>>(t2807);
    // ../src/builtins/array-reverse.tq:65:5
    {
      Label label__True_763_impl(this);
      Label* label__True_763 = &label__True_763_impl;
      USE(label__True_763);
      Label label__False_764_impl(this);
      Label* label__False_764 = &label__False_764_impl;
      USE(label__False_764);
      Label label_header_924_1183_impl(this, {lower_455, upper_456});
      Label* label_header_924_1183 = &label_header_924_1183_impl;
      USE(label_header_924_1183);
      Goto(label_header_924_1183);
      BIND(label_header_924_1183);
      TNode<BoolT> t2808 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*lower_455).value()), implicit_cast<TNode<Smi>>((*upper_456).value())));
      USE(implicit_cast<TNode<BoolT>>(t2808));
      Branch(implicit_cast<TNode<BoolT>>(t2808), label__True_763, label__False_764);
      if (label__True_763->is_used())
      {
        BIND(label__True_763);
        // ../src/builtins/array-reverse.tq:65:27
        {
          // ../src/builtins/array-reverse.tq:66:7
          TNode<Smi> t2809 = UncheckedCast<Smi>(LoadElement23ATFastPackedSmiElements5ATSmi(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*lower_455).value())));
          USE(implicit_cast<TNode<Smi>>(t2809));
          TNode<Smi> lower_value_925_impl;
          auto lower_value_925 = &lower_value_925_impl;
          USE(lower_value_925);
          *lower_value_925 = implicit_cast<TNode<Smi>>(t2809);
          // ../src/builtins/array-reverse.tq:67:7
          TNode<Smi> t2810 = UncheckedCast<Smi>(LoadElement23ATFastPackedSmiElements5ATSmi(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*upper_456).value())));
          USE(implicit_cast<TNode<Smi>>(t2810));
          TNode<Smi> upper_value_926_impl;
          auto upper_value_926 = &upper_value_926_impl;
          USE(upper_value_926);
          *upper_value_926 = implicit_cast<TNode<Smi>>(t2810);
          // ../src/builtins/array-reverse.tq:68:7
          StoreElement23ATFastPackedSmiElements5ATSmi(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*lower_455).value()), implicit_cast<TNode<Smi>>((*upper_value_926)));
          // ../src/builtins/array-reverse.tq:69:7
          StoreElement23ATFastPackedSmiElements5ATSmi(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*upper_456).value()), implicit_cast<TNode<Smi>>((*lower_value_925)));
          // ../src/builtins/array-reverse.tq:70:7
          TNode<Smi> t2811 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t2812 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*lower_455).value()), implicit_cast<TNode<Smi>>(t2811)));
          *lower_455 = implicit_cast<TNode<Smi>>(t2812);
          // ../src/builtins/array-reverse.tq:71:7
          TNode<Smi> t2813 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t2814 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*upper_456).value()), implicit_cast<TNode<Smi>>(t2813)));
          *upper_456 = implicit_cast<TNode<Smi>>(t2814);
        }
        Goto(label_header_924_1183);
      }
      BIND(label__False_764);
    }
  }
}

void ArrayBuiltinsFromDSLAssembler::FastPackedArrayReverse26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_length) {
  Label label_macro_end_1184_impl(this, {});
  Label* label_macro_end_1184 = &label_macro_end_1184_impl;
  USE(label_macro_end_1184);
  // ../src/builtins/array-reverse.tq:61:46
  {
    // ../src/builtins/array-reverse.tq:62:5
    int31_t t2815 = 0;
    TVARIABLE(Smi, lower_457_impl);
    auto lower_457 = &lower_457_impl;
    USE(lower_457);
    TNode<Smi> t2816 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2815)));
    *lower_457 = implicit_cast<TNode<Smi>>(t2816);
    // ../src/builtins/array-reverse.tq:63:5
    int31_t t2817 = 1;
    TNode<Smi> t2818 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2817)));
    TNode<Smi> t2819 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_length), implicit_cast<TNode<Smi>>(t2818)));
    USE(implicit_cast<TNode<Smi>>(t2819));
    TVARIABLE(Smi, upper_458_impl);
    auto upper_458 = &upper_458_impl;
    USE(upper_458);
    *upper_458 = implicit_cast<TNode<Smi>>(t2819);
    // ../src/builtins/array-reverse.tq:65:5
    {
      Label label__True_765_impl(this);
      Label* label__True_765 = &label__True_765_impl;
      USE(label__True_765);
      Label label__False_766_impl(this);
      Label* label__False_766 = &label__False_766_impl;
      USE(label__False_766);
      Label label_header_927_1185_impl(this, {lower_457, upper_458});
      Label* label_header_927_1185 = &label_header_927_1185_impl;
      USE(label_header_927_1185);
      Goto(label_header_927_1185);
      BIND(label_header_927_1185);
      TNode<BoolT> t2820 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*lower_457).value()), implicit_cast<TNode<Smi>>((*upper_458).value())));
      USE(implicit_cast<TNode<BoolT>>(t2820));
      Branch(implicit_cast<TNode<BoolT>>(t2820), label__True_765, label__False_766);
      if (label__True_765->is_used())
      {
        BIND(label__True_765);
        // ../src/builtins/array-reverse.tq:65:27
        {
          // ../src/builtins/array-reverse.tq:66:7
          TNode<Object> t2821 = UncheckedCast<Object>(LoadElement26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*lower_457).value())));
          USE(implicit_cast<TNode<Object>>(t2821));
          TNode<Object> lower_value_928_impl;
          auto lower_value_928 = &lower_value_928_impl;
          USE(lower_value_928);
          *lower_value_928 = implicit_cast<TNode<Object>>(t2821);
          // ../src/builtins/array-reverse.tq:67:7
          TNode<Object> t2822 = UncheckedCast<Object>(LoadElement26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*upper_458).value())));
          USE(implicit_cast<TNode<Object>>(t2822));
          TNode<Object> upper_value_929_impl;
          auto upper_value_929 = &upper_value_929_impl;
          USE(upper_value_929);
          *upper_value_929 = implicit_cast<TNode<Object>>(t2822);
          // ../src/builtins/array-reverse.tq:68:7
          StoreElement26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*lower_457).value()), implicit_cast<TNode<Object>>((*upper_value_929)));
          // ../src/builtins/array-reverse.tq:69:7
          StoreElement26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*upper_458).value()), implicit_cast<TNode<Object>>((*lower_value_928)));
          // ../src/builtins/array-reverse.tq:70:7
          TNode<Smi> t2823 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t2824 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*lower_457).value()), implicit_cast<TNode<Smi>>(t2823)));
          *lower_457 = implicit_cast<TNode<Smi>>(t2824);
          // ../src/builtins/array-reverse.tq:71:7
          TNode<Smi> t2825 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t2826 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*upper_458).value()), implicit_cast<TNode<Smi>>(t2825)));
          *upper_458 = implicit_cast<TNode<Smi>>(t2826);
        }
        Goto(label_header_927_1185);
      }
      BIND(label__False_766);
    }
  }
}

void ArrayBuiltinsFromDSLAssembler::FastPackedArrayReverse26ATFastPackedDoubleElements9ATfloat64(TNode<FixedArrayBase> p_elements, TNode<Smi> p_length) {
  Label label_macro_end_1186_impl(this, {});
  Label* label_macro_end_1186 = &label_macro_end_1186_impl;
  USE(label_macro_end_1186);
  // ../src/builtins/array-reverse.tq:61:46
  {
    // ../src/builtins/array-reverse.tq:62:5
    int31_t t2827 = 0;
    TVARIABLE(Smi, lower_459_impl);
    auto lower_459 = &lower_459_impl;
    USE(lower_459);
    TNode<Smi> t2828 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2827)));
    *lower_459 = implicit_cast<TNode<Smi>>(t2828);
    // ../src/builtins/array-reverse.tq:63:5
    int31_t t2829 = 1;
    TNode<Smi> t2830 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(t2829)));
    TNode<Smi> t2831 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>(p_length), implicit_cast<TNode<Smi>>(t2830)));
    USE(implicit_cast<TNode<Smi>>(t2831));
    TVARIABLE(Smi, upper_460_impl);
    auto upper_460 = &upper_460_impl;
    USE(upper_460);
    *upper_460 = implicit_cast<TNode<Smi>>(t2831);
    // ../src/builtins/array-reverse.tq:65:5
    {
      Label label__True_767_impl(this);
      Label* label__True_767 = &label__True_767_impl;
      USE(label__True_767);
      Label label__False_768_impl(this);
      Label* label__False_768 = &label__False_768_impl;
      USE(label__False_768);
      Label label_header_930_1187_impl(this, {lower_459, upper_460});
      Label* label_header_930_1187 = &label_header_930_1187_impl;
      USE(label_header_930_1187);
      Goto(label_header_930_1187);
      BIND(label_header_930_1187);
      TNode<BoolT> t2832 = UncheckedCast<BoolT>(SmiLessThan(implicit_cast<TNode<Smi>>((*lower_459).value()), implicit_cast<TNode<Smi>>((*upper_460).value())));
      USE(implicit_cast<TNode<BoolT>>(t2832));
      Branch(implicit_cast<TNode<BoolT>>(t2832), label__True_767, label__False_768);
      if (label__True_767->is_used())
      {
        BIND(label__True_767);
        // ../src/builtins/array-reverse.tq:65:27
        {
          // ../src/builtins/array-reverse.tq:66:7
          TNode<Float64T> t2833 = UncheckedCast<Float64T>(LoadElement26ATFastPackedDoubleElements9ATfloat64(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*lower_459).value())));
          USE(implicit_cast<TNode<Float64T>>(t2833));
          TNode<Float64T> lower_value_931_impl;
          auto lower_value_931 = &lower_value_931_impl;
          USE(lower_value_931);
          *lower_value_931 = implicit_cast<TNode<Float64T>>(t2833);
          // ../src/builtins/array-reverse.tq:67:7
          TNode<Float64T> t2834 = UncheckedCast<Float64T>(LoadElement26ATFastPackedDoubleElements9ATfloat64(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*upper_460).value())));
          USE(implicit_cast<TNode<Float64T>>(t2834));
          TNode<Float64T> upper_value_932_impl;
          auto upper_value_932 = &upper_value_932_impl;
          USE(upper_value_932);
          *upper_value_932 = implicit_cast<TNode<Float64T>>(t2834);
          // ../src/builtins/array-reverse.tq:68:7
          StoreElement26ATFastPackedDoubleElements9ATfloat64(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*lower_459).value()), implicit_cast<TNode<Float64T>>((*upper_value_932)));
          // ../src/builtins/array-reverse.tq:69:7
          StoreElement26ATFastPackedDoubleElements9ATfloat64(implicit_cast<TNode<FixedArrayBase>>(p_elements), implicit_cast<TNode<Smi>>((*upper_460).value()), implicit_cast<TNode<Float64T>>((*lower_value_931)));
          // ../src/builtins/array-reverse.tq:70:7
          TNode<Smi> t2835 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t2836 = UncheckedCast<Smi>(SmiAdd(implicit_cast<TNode<Smi>>((*lower_459).value()), implicit_cast<TNode<Smi>>(t2835)));
          *lower_459 = implicit_cast<TNode<Smi>>(t2836);
          // ../src/builtins/array-reverse.tq:71:7
          TNode<Smi> t2837 = UncheckedCast<Smi>(from_constexpr5ATSmi(implicit_cast<int31_t>(1)));
          TNode<Smi> t2838 = UncheckedCast<Smi>(SmiSub(implicit_cast<TNode<Smi>>((*upper_460).value()), implicit_cast<TNode<Smi>>(t2837)));
          *upper_460 = implicit_cast<TNode<Smi>>(t2838);
        }
        Goto(label_header_930_1187);
      }
      BIND(label__False_768);
    }
  }
}

TF_BUILTIN(Load25ATGenericElementsAccessor, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  // ../third_party/v8/builtins/array-sort.tq:129:27
  {
    // ../third_party/v8/builtins/array-sort.tq:130:5
    TNode<Object> t2908 = UncheckedCast<Object>(GetProperty(implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_elements), implicit_cast<TNode<Object>>(p_index)));
    USE(implicit_cast<TNode<Object>>(t2908));
    Return(implicit_cast<TNode<Object>>(t2908));
  }
}

TF_BUILTIN(Store25ATGenericElementsAccessor, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<FixedArray> p_sortState = UncheckedCast<FixedArray>(Parameter(Descriptor::kSortState));
  USE(p_sortState);
  TNode<HeapObject> p_elements = UncheckedCast<HeapObject>(Parameter(Descriptor::kElements));
  USE(p_elements);
  TNode<Smi> p_index = UncheckedCast<Smi>(Parameter(Descriptor::kIndex));
  USE(p_index);
  TNode<Object> p_value = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(p_value);
  // ../third_party/v8/builtins/array-sort.tq:198:27
  {
    // ../third_party/v8/builtins/array-sort.tq:199:5
    CallBuiltin(Builtins::kSetProperty, implicit_cast<TNode<Context>>(p_context), implicit_cast<TNode<Object>>(p_elements), implicit_cast<TNode<Object>>(p_index), implicit_cast<TNode<Object>>(p_value));
    // ../third_party/v8/builtins/array-sort.tq:200:5
    Return(implicit_cast<TNode<Smi>>(kSuccess()));
  }
}

void ArrayBuiltinsFromDSLAssembler::InitializeSortStateAccessor20ATFastDoubleElements(TNode<FixedArray> p_sortState) {
  Label label_macro_end_1190_impl(this, {});
  Label* label_macro_end_1190 = &label_macro_end_1190_impl;
  USE(label_macro_end_1190);
  // ../third_party/v8/builtins/array-sort.tq:1629:77
  {
    // ../third_party/v8/builtins/array-sort.tq:1630:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kAccessorIdx()), implicit_cast<TNode<Object>>(kFastElementsAccessorId()));
    // ../third_party/v8/builtins/array-sort.tq:1631:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kLoadFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoad20ATFastDoubleElements).code())));
    // ../third_party/v8/builtins/array-sort.tq:1632:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kStoreFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStore20ATFastDoubleElements).code())));
    // ../third_party/v8/builtins/array-sort.tq:1633:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kCanUseSameAccessorFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kCanUseSameAccessor20ATFastDoubleElements).code())));
  }
}

void ArrayBuiltinsFromDSLAssembler::InitializeSortStateAccessor23ATFastPackedSmiElements(TNode<FixedArray> p_sortState) {
  Label label_macro_end_1191_impl(this, {});
  Label* label_macro_end_1191 = &label_macro_end_1191_impl;
  USE(label_macro_end_1191);
  // ../third_party/v8/builtins/array-sort.tq:1629:77
  {
    // ../third_party/v8/builtins/array-sort.tq:1630:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kAccessorIdx()), implicit_cast<TNode<Object>>(kFastElementsAccessorId()));
    // ../third_party/v8/builtins/array-sort.tq:1631:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kLoadFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoad23ATFastPackedSmiElements).code())));
    // ../third_party/v8/builtins/array-sort.tq:1632:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kStoreFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStore23ATFastPackedSmiElements).code())));
    // ../third_party/v8/builtins/array-sort.tq:1633:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kCanUseSameAccessorFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kCanUseSameAccessor23ATFastPackedSmiElements).code())));
  }
}

void ArrayBuiltinsFromDSLAssembler::InitializeSortStateAccessor25ATFastSmiOrObjectElements(TNode<FixedArray> p_sortState) {
  Label label_macro_end_1192_impl(this, {});
  Label* label_macro_end_1192 = &label_macro_end_1192_impl;
  USE(label_macro_end_1192);
  // ../third_party/v8/builtins/array-sort.tq:1629:77
  {
    // ../third_party/v8/builtins/array-sort.tq:1630:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kAccessorIdx()), implicit_cast<TNode<Object>>(kFastElementsAccessorId()));
    // ../third_party/v8/builtins/array-sort.tq:1631:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kLoadFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoad25ATFastSmiOrObjectElements).code())));
    // ../third_party/v8/builtins/array-sort.tq:1632:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kStoreFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStore25ATFastSmiOrObjectElements).code())));
    // ../third_party/v8/builtins/array-sort.tq:1633:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kCanUseSameAccessorFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kCanUseSameAccessor25ATFastSmiOrObjectElements).code())));
  }
}

void ArrayBuiltinsFromDSLAssembler::InitializeSortStateAccessor20ATDictionaryElements(TNode<FixedArray> p_sortState) {
  Label label_macro_end_1193_impl(this, {});
  Label* label_macro_end_1193 = &label_macro_end_1193_impl;
  USE(label_macro_end_1193);
  // ../third_party/v8/builtins/array-sort.tq:1629:77
  {
    // ../third_party/v8/builtins/array-sort.tq:1630:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kAccessorIdx()), implicit_cast<TNode<Object>>(kFastElementsAccessorId()));
    // ../third_party/v8/builtins/array-sort.tq:1631:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kLoadFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kLoad20ATDictionaryElements).code())));
    // ../third_party/v8/builtins/array-sort.tq:1632:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kStoreFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kStore20ATDictionaryElements).code())));
    // ../third_party/v8/builtins/array-sort.tq:1633:5
    StoreFixedArrayElement(implicit_cast<TNode<FixedArray>>(p_sortState), implicit_cast<int31_t>(kCanUseSameAccessorFnIdx()), implicit_cast<TNode<Object>>(HeapConstant(Builtins::CallableFor(isolate(), Builtins::kCanUseSameAccessor20ATDictionaryElements).code())));
  }
}

TF_BUILTIN(CanUseSameAccessor20ATFastDoubleElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSReceiver> p_receiver = UncheckedCast<JSReceiver>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_initialReceiverMap = UncheckedCast<Object>(Parameter(Descriptor::kInitialReceiverMap));
  USE(p_initialReceiverMap);
  TNode<Number> p_initialReceiverLength = UncheckedCast<Number>(Parameter(Descriptor::kInitialReceiverLength));
  USE(p_initialReceiverLength);
  // ../third_party/v8/builtins/array-sort.tq:329:47
  {
    // ../third_party/v8/builtins/array-sort.tq:330:5
    // ../third_party/v8/builtins/array-sort.tq:332:5
    TNode<JSArray> t2909 = UncheckedCast<JSArray>(unsafe_cast9ATJSArray(implicit_cast<TNode<Object>>(p_receiver)));
    USE(implicit_cast<TNode<JSArray>>(t2909));
    TVARIABLE(JSArray, a_467_impl);
    auto a_467 = &a_467_impl;
    USE(a_467);
    *a_467 = implicit_cast<TNode<JSArray>>(t2909);
    // ../third_party/v8/builtins/array-sort.tq:333:5
    {
      Label label__True_771_impl(this);
      Label* label__True_771 = &label__True_771_impl;
      USE(label__True_771);
      Label label__False_772_impl(this, {});
      Label* label__False_772 = &label__False_772_impl;
      USE(label__False_772);
      TNode<Map> t2910 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>((*a_467).value())));
      TNode<BoolT> t2911 = UncheckedCast<BoolT>(WordNotEqual(implicit_cast<TNode<Object>>(t2910), implicit_cast<TNode<Object>>(p_initialReceiverMap)));
      USE(implicit_cast<TNode<BoolT>>(t2911));
      Branch(implicit_cast<TNode<BoolT>>(t2911), label__True_771, label__False_772);
      if (label__True_771->is_used())
      {
        BIND(label__True_771);
        // ../third_party/v8/builtins/array-sort.tq:333:38
        Return(implicit_cast<TNode<Oddball>>(False()));
      }
      BIND(label__False_772);
    }
    // ../third_party/v8/builtins/array-sort.tq:335:5
    // ../third_party/v8/builtins/array-sort.tq:336:5
    TNode<Smi> t2912 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(p_initialReceiverLength)));
    USE(implicit_cast<TNode<Smi>>(t2912));
    TVARIABLE(Smi, originalLength_468_impl);
    auto originalLength_468 = &originalLength_468_impl;
    USE(originalLength_468);
    *originalLength_468 = implicit_cast<TNode<Smi>>(t2912);
    // ../third_party/v8/builtins/array-sort.tq:337:5
    {
      Label label__True_773_impl(this);
      Label* label__True_773 = &label__True_773_impl;
      USE(label__True_773);
      Label label__False_774_impl(this, {});
      Label* label__False_774 = &label__False_774_impl;
      USE(label__False_774);
      TNode<Smi> t2913 = UncheckedCast<Smi>(LoadFastJSArrayLength(implicit_cast<TNode<JSArray>>((*a_467).value())));
      TNode<BoolT> t2914 = UncheckedCast<BoolT>(SmiNotEqual(implicit_cast<TNode<Smi>>(t2913), implicit_cast<TNode<Smi>>((*originalLength_468).value())));
      USE(implicit_cast<TNode<BoolT>>(t2914));
      Branch(implicit_cast<TNode<BoolT>>(t2914), label__True_773, label__False_774);
      if (label__True_773->is_used())
      {
        BIND(label__True_773);
        // ../third_party/v8/builtins/array-sort.tq:337:42
        Return(implicit_cast<TNode<Oddball>>(False()));
      }
      BIND(label__False_774);
    }
    // ../third_party/v8/builtins/array-sort.tq:339:5
    Return(implicit_cast<TNode<Oddball>>(True()));
  }
}

TF_BUILTIN(CanUseSameAccessor23ATFastPackedSmiElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSReceiver> p_receiver = UncheckedCast<JSReceiver>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_initialReceiverMap = UncheckedCast<Object>(Parameter(Descriptor::kInitialReceiverMap));
  USE(p_initialReceiverMap);
  TNode<Number> p_initialReceiverLength = UncheckedCast<Number>(Parameter(Descriptor::kInitialReceiverLength));
  USE(p_initialReceiverLength);
  // ../third_party/v8/builtins/array-sort.tq:329:47
  {
    // ../third_party/v8/builtins/array-sort.tq:330:5
    // ../third_party/v8/builtins/array-sort.tq:332:5
    TNode<JSArray> t2915 = UncheckedCast<JSArray>(unsafe_cast9ATJSArray(implicit_cast<TNode<Object>>(p_receiver)));
    USE(implicit_cast<TNode<JSArray>>(t2915));
    TVARIABLE(JSArray, a_469_impl);
    auto a_469 = &a_469_impl;
    USE(a_469);
    *a_469 = implicit_cast<TNode<JSArray>>(t2915);
    // ../third_party/v8/builtins/array-sort.tq:333:5
    {
      Label label__True_775_impl(this);
      Label* label__True_775 = &label__True_775_impl;
      USE(label__True_775);
      Label label__False_776_impl(this, {});
      Label* label__False_776 = &label__False_776_impl;
      USE(label__False_776);
      TNode<Map> t2916 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>((*a_469).value())));
      TNode<BoolT> t2917 = UncheckedCast<BoolT>(WordNotEqual(implicit_cast<TNode<Object>>(t2916), implicit_cast<TNode<Object>>(p_initialReceiverMap)));
      USE(implicit_cast<TNode<BoolT>>(t2917));
      Branch(implicit_cast<TNode<BoolT>>(t2917), label__True_775, label__False_776);
      if (label__True_775->is_used())
      {
        BIND(label__True_775);
        // ../third_party/v8/builtins/array-sort.tq:333:38
        Return(implicit_cast<TNode<Oddball>>(False()));
      }
      BIND(label__False_776);
    }
    // ../third_party/v8/builtins/array-sort.tq:335:5
    // ../third_party/v8/builtins/array-sort.tq:336:5
    TNode<Smi> t2918 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(p_initialReceiverLength)));
    USE(implicit_cast<TNode<Smi>>(t2918));
    TVARIABLE(Smi, originalLength_470_impl);
    auto originalLength_470 = &originalLength_470_impl;
    USE(originalLength_470);
    *originalLength_470 = implicit_cast<TNode<Smi>>(t2918);
    // ../third_party/v8/builtins/array-sort.tq:337:5
    {
      Label label__True_777_impl(this);
      Label* label__True_777 = &label__True_777_impl;
      USE(label__True_777);
      Label label__False_778_impl(this, {});
      Label* label__False_778 = &label__False_778_impl;
      USE(label__False_778);
      TNode<Smi> t2919 = UncheckedCast<Smi>(LoadFastJSArrayLength(implicit_cast<TNode<JSArray>>((*a_469).value())));
      TNode<BoolT> t2920 = UncheckedCast<BoolT>(SmiNotEqual(implicit_cast<TNode<Smi>>(t2919), implicit_cast<TNode<Smi>>((*originalLength_470).value())));
      USE(implicit_cast<TNode<BoolT>>(t2920));
      Branch(implicit_cast<TNode<BoolT>>(t2920), label__True_777, label__False_778);
      if (label__True_777->is_used())
      {
        BIND(label__True_777);
        // ../third_party/v8/builtins/array-sort.tq:337:42
        Return(implicit_cast<TNode<Oddball>>(False()));
      }
      BIND(label__False_778);
    }
    // ../third_party/v8/builtins/array-sort.tq:339:5
    Return(implicit_cast<TNode<Oddball>>(True()));
  }
}

TF_BUILTIN(CanUseSameAccessor25ATFastSmiOrObjectElements, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSReceiver> p_receiver = UncheckedCast<JSReceiver>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_initialReceiverMap = UncheckedCast<Object>(Parameter(Descriptor::kInitialReceiverMap));
  USE(p_initialReceiverMap);
  TNode<Number> p_initialReceiverLength = UncheckedCast<Number>(Parameter(Descriptor::kInitialReceiverLength));
  USE(p_initialReceiverLength);
  // ../third_party/v8/builtins/array-sort.tq:329:47
  {
    // ../third_party/v8/builtins/array-sort.tq:330:5
    // ../third_party/v8/builtins/array-sort.tq:332:5
    TNode<JSArray> t2921 = UncheckedCast<JSArray>(unsafe_cast9ATJSArray(implicit_cast<TNode<Object>>(p_receiver)));
    USE(implicit_cast<TNode<JSArray>>(t2921));
    TVARIABLE(JSArray, a_471_impl);
    auto a_471 = &a_471_impl;
    USE(a_471);
    *a_471 = implicit_cast<TNode<JSArray>>(t2921);
    // ../third_party/v8/builtins/array-sort.tq:333:5
    {
      Label label__True_779_impl(this);
      Label* label__True_779 = &label__True_779_impl;
      USE(label__True_779);
      Label label__False_780_impl(this, {});
      Label* label__False_780 = &label__False_780_impl;
      USE(label__False_780);
      TNode<Map> t2922 = UncheckedCast<Map>(LoadMap(implicit_cast<TNode<HeapObject>>((*a_471).value())));
      TNode<BoolT> t2923 = UncheckedCast<BoolT>(WordNotEqual(implicit_cast<TNode<Object>>(t2922), implicit_cast<TNode<Object>>(p_initialReceiverMap)));
      USE(implicit_cast<TNode<BoolT>>(t2923));
      Branch(implicit_cast<TNode<BoolT>>(t2923), label__True_779, label__False_780);
      if (label__True_779->is_used())
      {
        BIND(label__True_779);
        // ../third_party/v8/builtins/array-sort.tq:333:38
        Return(implicit_cast<TNode<Oddball>>(False()));
      }
      BIND(label__False_780);
    }
    // ../third_party/v8/builtins/array-sort.tq:335:5
    // ../third_party/v8/builtins/array-sort.tq:336:5
    TNode<Smi> t2924 = UncheckedCast<Smi>(unsafe_cast5ATSmi(implicit_cast<TNode<Object>>(p_initialReceiverLength)));
    USE(implicit_cast<TNode<Smi>>(t2924));
    TVARIABLE(Smi, originalLength_472_impl);
    auto originalLength_472 = &originalLength_472_impl;
    USE(originalLength_472);
    *originalLength_472 = implicit_cast<TNode<Smi>>(t2924);
    // ../third_party/v8/builtins/array-sort.tq:337:5
    {
      Label label__True_781_impl(this);
      Label* label__True_781 = &label__True_781_impl;
      USE(label__True_781);
      Label label__False_782_impl(this, {});
      Label* label__False_782 = &label__False_782_impl;
      USE(label__False_782);
      TNode<Smi> t2925 = UncheckedCast<Smi>(LoadFastJSArrayLength(implicit_cast<TNode<JSArray>>((*a_471).value())));
      TNode<BoolT> t2926 = UncheckedCast<BoolT>(SmiNotEqual(implicit_cast<TNode<Smi>>(t2925), implicit_cast<TNode<Smi>>((*originalLength_472).value())));
      USE(implicit_cast<TNode<BoolT>>(t2926));
      Branch(implicit_cast<TNode<BoolT>>(t2926), label__True_781, label__False_782);
      if (label__True_781->is_used())
      {
        BIND(label__True_781);
        // ../third_party/v8/builtins/array-sort.tq:337:42
        Return(implicit_cast<TNode<Oddball>>(False()));
      }
      BIND(label__False_782);
    }
    // ../third_party/v8/builtins/array-sort.tq:339:5
    Return(implicit_cast<TNode<Oddball>>(True()));
  }
}

}  // namespace internal
}  // namespace v8

