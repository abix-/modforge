// Address: 0x140026520
// Ghidra name: FUN_140026520
// ============ 0x140026520 FUN_140026520 (size=119) ============


void FUN_140026520(longlong param_1,longlong param_2,undefined4 param_3)



{

  longlong *plVar1;

  

  if (param_2 == 0) {

    FID_conflict__assert(L"cfile",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x44e);

  }

  for (plVar1 = *(longlong **)(param_1 + 0x28); plVar1 != (longlong *)0x0;

      plVar1 = (longlong *)plVar1[0xc]) {

    (**(code **)(*plVar1 + 8))(plVar1,param_2,param_3);

    FUN_140023ee0(param_2,&DAT_14039bd10);

  }

  return;

}




