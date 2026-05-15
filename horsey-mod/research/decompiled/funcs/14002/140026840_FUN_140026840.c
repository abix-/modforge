// Address: 0x140026840
// Ghidra name: FUN_140026840
// ============ 0x140026840 FUN_140026840 (size=129) ============


void FUN_140026840(longlong param_1,longlong param_2,uint param_3)



{

  ulonglong uVar1;

  longlong *plVar2;

  

  uVar1 = (ulonglong)param_3;

  if (param_2 == 0) {

    FID_conflict__assert(L"cfile",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x4e5);

  }

  if (0 < (int)param_3) {

    do {

      FUN_140023ee0(param_2,&DAT_14039bd08);

      uVar1 = uVar1 - 1;

    } while (uVar1 != 0);

  }

  plVar2 = (longlong *)(param_1 + 0x38);

  if (0xf < *(ulonglong *)(param_1 + 0x50)) {

    plVar2 = (longlong *)*plVar2;

  }

  FUN_140023ee0(param_2,"<!--%s-->",plVar2);

  return;

}




